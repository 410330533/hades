#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MEM_D_SIZE 1024*1024					//1M磁盘空间		
#define DISKSIZE 256							//磁盘块大小
#define MSD 5									//最大子目录数
#define DISK_NUM    4*1024						//磁盘块数目
#define	FATSIZE		4*1024*8					//FAT表大小8   DISK_NUM*sizeof(struct fatitem)
#define	MOFN 5									//最大文件打开数目
#define ROOT_DISK_NO 1+FATSIZE/DISKSIZE			//根目录起始盘块号
#define	ROOT_DISK_SIZE sizeof(struct direct)	//根目录大小(MSD+2)*28=196

/** FAT表项结构 */
struct fatitem	 
{
	int item;									//存放文件下一个磁盘的指针
	char em_disk;								//磁盘块空闲标志位 0空闲
};

/** 目录项结构 */
struct direct
{
	struct FCB									//文件控制块信息
	{
		char name[9];							//文件/目录 名8位
		char property;							//属性  1为目录  2为普通文件
		int size;								//文件/目录的大小
		int	firstdisk;							//文件/目录对应起始盘块号
		int next;								//子目录起始盘块号
		int sign;								//1是根目录 0不是根目录
	}directitem[MSD+2];							//第0，1表项用来存放当前目录和上一级目录
};

/** 文件打开表项结构 */
struct opentable 
{
	struct opentableitem 
	{
		char name[9];							//文件名
		int firstdisk;							//起始盘块号
		int size;								//文件的大小
	}openitem[MOFN];							//允许打开文件的最大数目
	int	cur_size;								//当前打开的用户表的数目
};

/** 定义全局变量 */
struct fatitem *fat;							//FAT表
struct direct *root;							//根目录
struct direct *cur_dir;							//当前目录
struct opentable u_opentable;					//文件打开表
int fd=-1;										//文件打开表的初始序号为－1
char *bufferdir;								//记录当前路径名称
char *fdisk;									//虚拟磁盘起始地址

/** 函数声明 */
void initfile();								//初始化文件系统
void format();									//格式化
void enter();									//进入文件系统
void halt();									//退出文件系统
int create(char *name);							//创建文件
int open(char *name);							//打开文件
int close(char *name);							//关闭文件
int write(int fd,char *buf,int len);			//写文件
int read(int fd,char *buf,int len);				//读文件
int del(char *name);							//删除文件
int mkdir(char* name);							//创建子目录
int rmdir(char* name);							//删除子目录
void dir();										//显示当前目录的子目录
int cd(char *name);								//更改当前目录

void show();									//显示命令提示符
void print();									//输出提示信息

void initfile()
{
	fdisk=(char *)malloc(MEM_D_SIZE); 
	format();
	free(fdisk);
}

void format()
{
	int i;
	FILE *fp;									//文件结构体指针变量名

	fat=(struct fatitem *)(fdisk+DISKSIZE);		//计算出FAT表的地址
	/*初始化FAT表*/
	fat[0].item=-1;								//引导块
	fat[0].em_disk='1';

	for(i=1;i<ROOT_DISK_NO-1;i++)				//FAT表存放磁盘块号
	{
		fat[i].item=i+1;	
		fat[i].em_disk='1';
	}
	fat[ROOT_DISK_NO-1].item=-1;
	fat[ROOT_DISK_NO-1].em_disk='1';

	fat[ROOT_DISK_NO].item=-1;					//根目录存放磁盘块号
	fat[ROOT_DISK_NO].em_disk='1';

	for(i=ROOT_DISK_NO+1;i<DISK_NUM;i++)
	{
		fat[i].item=-1;
		fat[i].em_disk='0';
	}

	root=(struct direct *)(fdisk+DISKSIZE+FATSIZE);//计算出根目录区的地址
	/*初始化根目录*/
	/*指向当前目录的目录项*/
	root->directitem[0].sign=1;		
	root->directitem[0].firstdisk=ROOT_DISK_NO;
	strcpy(root->directitem[0].name,".");
	root->directitem[0].next=root->directitem[0].firstdisk;
	root->directitem[0].property='1';
	root->directitem[0].size=ROOT_DISK_SIZE;
	/*指向上一级目录的目录项*/
	root->directitem[1].sign=1;
	root->directitem[1].firstdisk=ROOT_DISK_NO;
	strcpy(root->directitem[1].name,"..");
	root->directitem[1].next=root->directitem[1].firstdisk;
	root->directitem[1].property='1';
	root->directitem[1].size=ROOT_DISK_SIZE;
	/*最大子目录都初始化为空*/
	for(i=2;i<MSD+2;i++)
	{
		root->directitem[i].sign=0;
		root->directitem[i].firstdisk=-1;
		strcpy(root->directitem[i].name,"");
		root->directitem[i].next=-1;
		root->directitem[i].property='0';
		root->directitem[i].size=0;
	}
	//把虚拟磁盘空间内容保存到磁盘文件中
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("Error:\nCannot open file\n");
		return;
	}
	if(fwrite(fdisk,MEM_D_SIZE,1,fp)!=1)				
		printf("Error:\nFile write error!\n");
	fclose(fp);
}

void enter()			
{
	FILE *fp;
	int i;
	fdisk=(char *)malloc(MEM_D_SIZE);					//申请1M空间
	if((fp=fopen("data.txt","rb"))==NULL)				//把data文件的内容保存到虚拟磁盘空间
	{
		printf("Error:\nCannot open file\n");
		return;
	}
	fread(fdisk,MEM_D_SIZE,1,fp);						//将磁盘中的内容读入虚拟磁盘空间
	fat=(struct fatitem *)(fdisk+DISKSIZE);				//找到FAT表的地址
	root=(struct direct *)(fdisk+DISKSIZE+FATSIZE);		//找到root的地址
	fclose(fp);
	/*初始化用户打开表*/
	for(i=0;i<MOFN;i++)
	{
		strcpy(u_opentable.openitem[i].name,"");
		u_opentable.openitem[i].firstdisk=-1;
		u_opentable.openitem[i].size=0;
	}
	u_opentable.cur_size=0;

	cur_dir=root;										//当前目录为根目录
	bufferdir=(char *)malloc(sizeof(char));
	strcpy(bufferdir,"E:");								//当前目录为根目录
}

void halt()                
{
	FILE *fp;
	int i;
	if((fp=fopen("data.txt","wb"))==NULL)
	{
		printf("Error:\nCannot open file\n");
		return;
	}
	if(fwrite(fdisk,MEM_D_SIZE,1,fp)!=1)				//把虚拟磁盘空间内容保存到磁盘文件中
		printf("Error:\nFile write error!\n");
	fclose(fp);

	free(fdisk);										//释放虚拟磁盘空间

	for(i=0;i<MOFN;i++)									//撤销用户打开用户表
	{
		strcpy(u_opentable.openitem[i].name,"");
		u_opentable.openitem[i].firstdisk=0;
		u_opentable.openitem[i].size=0;
	}
	u_opentable.cur_size=0;

	return;
}

int create(char *name)		
{
	int i,j;

	if(strlen(name)>8)									//如果文件名长度大于8位
		return(-1);

	for(i=2;i<MSD+2;i++)								//如果有空闲目录项退出
	{
		if(cur_dir->directitem[i].firstdisk==-1)
			break;
	}

	for(j=2;j<MSD+2;j++)								//如果如果创建的文件的文件名已经存在目录项中则退出
	{
		if(!strcmp(cur_dir->directitem[j].name,name))
			break;
	}

	if(i>=MSD+2)										//如果无空目录项
		return (-2);
	if(u_opentable.cur_size>=MOFN)						//打开文件太多
		return (-3);
	if(j<MSD+2)											//如果文件名已经存在目录项中
		return(-4);

	for(j=ROOT_DISK_NO+1;j<DISK_NUM;j++)				//查找到空闲磁盘块后退出,j 就是对应的空闲磁盘块号
		if(fat[j].em_disk=='0')
			break;
	fat[j].em_disk='1';									//将该空闲块置成已经分配
	//填写目录项
	strcpy(cur_dir->directitem[i].name,name);
	cur_dir->directitem[i].firstdisk=j;
	cur_dir->directitem[i].size=0;
	cur_dir->directitem[i].next=j;
	cur_dir->directitem[i].property='0';
	//打开该文件
	fd=open(name);										//FD即为打开文件表项的序号J
	return 0;
}

int open(char *name)
{
	int i,j;
	/*打开文件是否存在*/
	for(i=2;i<MSD+2;i++)
		if(!strcmp(cur_dir->directitem[i].name,name))
			break;
	if(i>=MSD+2)/*打开文件不存在*/
		return(-1);
	/*文件是否已经打开*/
	for(j=0;j<MOFN;j++)
		if(!strcmp(u_opentable.openitem[j].name,name))
			break;
	if(j<MOFN)/*文件已经打开*/
		return(-2);

	if(u_opentable.cur_size>=MOFN)/*文件打开太多*/
		return(-3);
	/*查找一个空闲用户打开文件表表项*/
	for(j=0;j<MOFN;j++)
		if(u_opentable.openitem[j].firstdisk==-1)
			break;
	/*填写表项相关信息*/
	u_opentable.openitem[j].firstdisk=cur_dir->directitem[i].firstdisk;
	strcpy(u_opentable.openitem[j].name,name);
	u_opentable.openitem[j].size=cur_dir->directitem[i].size;
	u_opentable.cur_size++;
	/*返回用户打开表表项序号*/
	return (j);
}

int close(char *name)
{
	int i;
	for(i=0;i<MOFN;i++)
	{
		if(!strcmp(u_opentable.openitem[i].name,name))
			break;
	}
	if(i>=MOFN)/*关闭的文件没有打开*/
		return(-1);
	/*清空该文件的用户打开表表项的内容*/
	strcpy(u_opentable.openitem[i].name,"");
	u_opentable.openitem[i].firstdisk=-1;
	u_opentable.openitem[i].size=0;
	u_opentable.cur_size--;

	fd=-1;/*关闭文件后把fd初始化为原来的*/
	return 0;
}

int write(int fd,char *buf,int len)
{
	char * first;
	int item,i,j,k;
	int ilen1,ilen2,modlen,temp;
	/*读取用户打开表对应表项第一个盘块号*/
	item=u_opentable.openitem[fd].firstdisk;
	/*找到当前目录所对应表项的序号*/
	for(i=2;i<MSD+2;i++)
		if(cur_dir->directitem[i].firstdisk==item)
			break;
	temp=i;/*用来存放当前目录项的下标*/
	/*找到item是该文件的最后一块磁盘块*/
	while(fat[item].item!=-1)
		item=fat[item].item;
	first=fdisk+item*DISKSIZE+u_opentable.openitem[fd].size%DISKSIZE;/*计算出该文件的最末的地址*/

	if((DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE)>len)/*如果最后磁盘块剩余的大小大于要写入的文件的大小*/
	{
		strcpy(first,buf);/*写内容到虚拟磁盘*/
		u_opentable.openitem[fd].size=u_opentable.openitem[fd].size+len;/*修改用户打开文件表表项文件的长度*/
		cur_dir->directitem[temp].size=cur_dir->directitem[temp].size+len;/*修改目录项的文件长度*/
	}
	else
	{
		for(i=0;i<(DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE);i++)/*写一部分内容到最后一块磁盘块的剩余字节*/
			first[i]=buf[i];
		ilen1=len-(DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE);/*分配完最后一块磁盘块的剩余字节还剩对少字节未存储*/
		ilen2=ilen1/DISKSIZE;
		modlen=ilen1%DISKSIZE;
		if(modlen>0)
			ilen2=ilen2+1;/*需要的磁盘块加1*/
		for(j=0;j<ilen2;j++)
		{
			for(i=ROOT_DISK_NO+1;i<DISK_NUM;i++)/*寻找空闲盘块*/
				if(fat[i].em_disk=='0')
					break;
			if(i>=DISK_NUM)/*如果磁盘块已经分配完了*/
				return(-1);
			first=fdisk+i*DISKSIZE;/*找到的那块空闲磁盘块的起始地址*/
			if(j==ilen2-1)/*如果是最后要分配的一块*/
				for(k=0;k<len-(DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE)-j*DISKSIZE;k++)
					first[k]=buf[k];
			else/*如果不是最后要分配的一块*/
				for(k=0;k<DISKSIZE;k++)
					first[k]=buf[k];
			fat[item].item=i;	/*找到一块后将它的序号存放在上一块的指针中*/
			fat[i].em_disk='1';	/*置找到的磁盘块的空闲标志位为已分配*/
			fat[i].item=-1;		/*置找到的磁盘块的指针为－1*/
		}	
		u_opentable.openitem[fd].size=u_opentable.openitem[fd].size+len;/*修改用户打开文件表表项文件的长度*/
		cur_dir->directitem[temp].size=cur_dir->directitem[temp].size+len;/*修改目录项的文件长度*/
	}	
	return 0;
}

int read(int fd,char *buf,int len)
{
	char *first;
	int i,j,item;
	int ilen1,modlen;
	item=u_opentable.openitem[fd].firstdisk;
	if(len>u_opentable.openitem[fd].size)/*欲读出的文件长度比实际文件长度长*/
		return(-1);
	ilen1=len/DISKSIZE;
	modlen=len%DISKSIZE;
	if(modlen!=0)
		ilen1=ilen1+1;/*计算文件所占磁盘块的块数*/
	first=fdisk+item*DISKSIZE;/*计算文件的起始位置*/
	for(i=0;i<ilen1;i++)
	{
		if(i==ilen1-1)/*如果在最后一个磁盘块*/
			for(j=0;j<len-i*DISKSIZE;j++)
				buf[i*DISKSIZE+j]=first[j];
		else/*不在最后一块磁盘块*/
		{
			for(j=0;j<len-i*DISKSIZE;j++)
				buf[i*DISKSIZE+j]=first[j];
			item=fat[item].item;
			first=fdisk+item*DISKSIZE;
		}

	}
	return 0;
}

int del(char *name)
{
	int i,cur_item,item,temp;
	for(i=2;i<MSD+2;i++)/*查找要删除的文件是否在当前目录中*/
		if(!strcmp(cur_dir->directitem[i].name,name))
			break;
	cur_item=i;/*用来保存目录项的序号，供释放目录项用*/

	if(i>=MSD+2)/*如果不在当前目录中*/
		return(-1);

	if(cur_dir->directitem[cur_item].property!='0')/*如果删除的不是目录*/
		return(-3);

	for(i=0;i<MOFN;i++)/*如果文件打开，则不能删除，退出*/
		if(!strcmp(u_opentable.openitem[i].name,name))
			return(-2);

	item=cur_dir->directitem[cur_item].firstdisk;/*该文件的起始盘块号*/
	while(item!=-1)/*释放磁盘空间，将FAT表的对应项进行修改*/
	{
		temp=fat[item].item;
		fat[item].item=-1;
		fat[item].em_disk='0';
		item=temp;
	}
	/*释放目录项*/
	cur_dir->directitem[cur_item].sign=0;
	cur_dir->directitem[cur_item].firstdisk=-1;
	strcpy(cur_dir->directitem[cur_item].name,"");
	cur_dir->directitem[cur_item].next=-1;
	cur_dir->directitem[cur_item].property='0';
	cur_dir->directitem[cur_item].size=0;

	return 0;
}

int mkdir(char* name)     
{
	int i,j;
	struct direct *cur_mkdir;

	if(strlen(name)>8)		/*如果目录名长度大于8位*/
		return(-1);

	for(i=2;i<MSD+2;i++)	/*查找空闲目录项*/
	{
		if(cur_dir->directitem[i].firstdisk==-1)
			break;
	}
	if(i>=MSD+2)
		return(-2);

	for(j=2;j<MSD+2;j++)	
	{
		if(!strcmp(cur_dir->directitem[j].name,name))
			break;
	}
	if(j<MSD+2)/*如果创建的目录的目录名已经存在目录项中*/
		return(-3);

	for(j=ROOT_DISK_NO+1;j<DISK_NUM;j++)/*查找到空闲磁盘块后退出,j 就是对应的空闲磁盘块号*/
		if(fat[j].em_disk=='0')
			break;
	fat[j].em_disk='1';	/*将该空闲块置成已经分配*/
	/*填写目录项*/
	strcpy(cur_dir->directitem[i].name,name);
	cur_dir->directitem[i].firstdisk=j;
	cur_dir->directitem[i].size=ROOT_DISK_SIZE;
	cur_dir->directitem[i].next=j;/*指向子目录的起始盘块号*/
	cur_dir->directitem[i].property='1';

	cur_mkdir=(struct direct *)(fdisk+cur_dir->directitem[i].firstdisk*DISKSIZE);

	/*初始化根目录*/
	/*指向当前目录的目录项*/
	cur_mkdir->directitem[0].sign=0;		
	cur_mkdir->directitem[0].firstdisk=cur_dir->directitem[i].firstdisk;
	strcpy(cur_mkdir->directitem[0].name,".");
	cur_mkdir->directitem[0].next=cur_mkdir->directitem[0].firstdisk;
	cur_mkdir->directitem[0].property='1';
	cur_mkdir->directitem[0].size=ROOT_DISK_SIZE;
	/*指向上一级目录的目录项*/
	cur_mkdir->directitem[1].sign=0;
	cur_mkdir->directitem[1].firstdisk=cur_dir->directitem[0].firstdisk;
	strcpy(cur_mkdir->directitem[1].name,"..");
	cur_mkdir->directitem[1].next=cur_mkdir->directitem[1].firstdisk;
	cur_mkdir->directitem[1].property='1';
	cur_mkdir->directitem[1].size=ROOT_DISK_SIZE;

	for(i=2;i<MSD+2;i++)/*子目录都初始化为空*/
	{
		cur_mkdir->directitem[i].sign=0;
		cur_mkdir->directitem[i].firstdisk=-1;
		strcpy(cur_mkdir->directitem[i].name,"");
		cur_mkdir->directitem[i].next=-1;
		cur_mkdir->directitem[i].property='0';
		cur_mkdir->directitem[i].size=0;
	}
	return 0;
}

int rmdir(char* name)	
{
	int i,j,item;
	struct direct *temp_dir;
	/*检查当前目录项中有无该目录*/
	for(i=2;i<MSD+2;i++)
	{
		if(!strcmp(cur_dir->directitem[i].name,name))
			break;
	}

	if(cur_dir->directitem[i].property!='1')/*如果删除的不是目录*/
		return(-3);

	if(i>=MSD+2)/*如果没有退出*/
		return(-1);
	/*判断其有无子目录*/
	temp_dir=(struct direct *)(fdisk+cur_dir->directitem[i].next*DISKSIZE);/*计算子目录的起始地址*/
	for(j=2;j<MSD+2;j++)
	{
		if(temp_dir->directitem[j].next!=-1)
			break;
	}
	if(j<MSD+2)		/*如果有子目录或文件退出*/
		return(-2);

	/*找到起始盘块号，并将其释放*/
	item=cur_dir->directitem[i].firstdisk;
	fat[item].em_disk='0';

	/*修改目录项*/
	cur_dir->directitem[i].sign=0;
	cur_dir->directitem[i].firstdisk=-1;
	strcpy(cur_dir->directitem[i].name,"");
	cur_dir->directitem[i].next=-1;
	cur_dir->directitem[i].property='0';
	cur_dir->directitem[i].size=0;

	return 0;
}

void dir()
{
	int i;
	for(i=0;i<MSD+2;i++)
	{
		if(cur_dir->directitem[i].firstdisk!=-1)/*如果存在子目录*/
		{
			printf("%s\t",cur_dir->directitem[i].name);
			if(cur_dir->directitem[i].property=='0')
				printf("%d\t\t\n",cur_dir->directitem[i].size);
			else
				printf("\t<DIR>\t\n");
		}
	}
}

int cd(char *name)
{
	int i,j,item;
	char *str,*str1;
	char *temp,*point,*point1;
	struct direct *temp_dir;
	temp_dir=cur_dir;  /*先用临时目录代替当前目录*/
	str=name;			/*str用来记录下次查找的起始地址*/
	str1=strchr(str,'\\');/*找到"\"字符的位置*/
	while(str1!=NULL)/*如果找到*/
	{
		temp=(char *)malloc(sizeof(char));/*为一个子目录的名字分配空间*/
		for(i=0;i<str1-str;i++)
			temp[i]=str[i];
		temp[i]='\0';

		for(j=2;j<MSD+2;j++)/*查找该子目录是否在当前目录中*/
		{
			if(!strcmp(temp_dir->directitem[j].name,temp))
				break;
		}
		if(j>=MSD+2)/*如果不在当前目录则退出*/
			return(-1);

		item=temp_dir->directitem[j].firstdisk; 
		temp_dir=(struct direct *)(fdisk+item*DISKSIZE); /*计算当前目录在虚拟磁盘空间的位置*/

		str=str1+1;/*减去"/"所占的一位空间，记录下次查找的起始地址*/
		str1=strchr(str,'\\');
	}
	str1=str1+strlen(str);
	temp=(char *)malloc(sizeof(char));
	for(i=0;i<(int)strlen(str);i++)
		temp[i]=str[i];
	temp[i]='\0';
	for(j=0;j<MSD+2;j++)/*查找该子目录是否在当前目录中*/
	{
		if(!strcmp(temp_dir->directitem[j].name,temp))
			break;
	}

	if(temp_dir->directitem[j].property!='1')/*如果打开的不是目录*/
		return(-2);

	if(j>=MSD+2)/*如果不在当前目录则退出*/
		return(-1);

	item=temp_dir->directitem[j].firstdisk;
	temp_dir=(struct direct *)(fdisk+item*DISKSIZE);/*计算当前目录在虚拟磁盘空间的位置*/

	if(!strcmp("..",name))
	{
		if(cur_dir->directitem[j].sign!=1)/*如果子目录不是根目录*/
		{
			point=strchr(bufferdir,'\\');
			while(point!=NULL)
			{
				point1=point+1;/*减去"/"所占的一位空间，记录下次查找的起始地址*/
				point=strchr(point1,'\\');
			}
			*(point1-1)='\0';/*将上一级目录删除*/
		}

	}
	else if(!strcmp(".",name))
	{
		bufferdir=bufferdir;/*如果是当前目录则不变*/
	}
	else
	{
		bufferdir=strcat(bufferdir,"\\");/*修改当前目录*/
		bufferdir=strcat(bufferdir,name);
	}
	cur_dir=temp_dir;/*将当前目录确定下来*/
	return 0;
}

void show()
{
	printf("\n%s>",bufferdir);
}

void print()
{
	printf("*******************************************************************************\n");
	printf("\t\t\tWelcome to DOS file system!\n");
	printf("*******************************************************************************\n");
	printf("\t\t退出文件系统         halt\n");
	printf("\t\t创建文件             create 文件名\n");
	printf("\t\t打开文件             open 文件名\n");
	printf("\t\t关闭文件             close 文件名\n");
	printf("\t\t打开文件             open 文件名\n");
	printf("\t\t写文件               write\n");
	printf("\t\t读文件               read\n");
	printf("\t\t删除文件             del 文件名\n");
	printf("\t\t创建子目录           mkdir 目录名\n");
	printf("\t\t删除子目录           rmdir 目录名\n");
	printf("\t\t显示当前目录的子目录 dir\n");
	printf("\t\t更改当前目录         cd 目录名\n");
	printf("*******************************************************************************\n");
}

void main()
{
	FILE *fp;
	char ch;
	char a[100],code[11][10],name[10];
	int i,flag,r_size;
	char *contect;

	contect=(char *)malloc(sizeof(char));

	if((fp=fopen("data.txt","rb"))==NULL)/*如果还没有进行格式化，则要格式化*/
	{
		printf("You have not format!\nDo you want format?(y/n)");
		scanf("%c",&ch);
		if(ch=='y')
		{
			initfile();
			printf("Successfully format!\n");
		}	
		else
			return;
	}

	enter();/*进入文件系统*/
	print();
	show();

	strcpy(code[0],"halt"); /*将命令全部存放在CODE数组中*/
	strcpy(code[1],"create");
	strcpy(code[2],"open");
	strcpy(code[3],"close");
	strcpy(code[4],"write");	
	strcpy(code[5],"read");
	strcpy(code[6],"del");
	strcpy(code[7],"mkdir");
	strcpy(code[8],"rmdir");
	strcpy(code[9],"dir");
	strcpy(code[10],"cd");
	while(1)
	{
		scanf("%s",a);
		for(i=0;i<11;i++)
			if(!strcmp(code[i],a))
				break;

		switch(i)
		{
		case 0:			/*退出文件系统*/
			halt();
			return;
		case 1:			/*创建文件*/
			scanf("%s",name);
			flag=create(name);
			if(flag==-1)
				printf("Error:\nThe length of name is too long!\n");
			else if(flag==-2)
			{
				printf("Error:\nThe direct item is already full!\n");
			}
			else if(flag==-3)
			{
				printf("Error:\nThe number of open file is too much!\n");
			}
			else if(flag==-4)
				printf("Error:\nThe name is already in the direct!\n");
			else
				printf("Successfully create a file!\n");	
			show();
			break;
		case 2:		/*打开文件*/

			scanf("%s",name);
			fd=open(name);
			if(fd==-1)
				printf("Error:\nThe open file not exist!\n");	
			else if(fd==-2)
				printf("Error:\nThe file have already opened!\n");
			else if(fd==-3)
				printf("Error:\nThe number of open file is too much!\n");
			else
				printf("Successfully opened!\n");
			show();
			break;
		case 3:		/*关闭文件*/
			scanf("%s",name);
			flag=close(name);
			if(flag==-1)
				printf("Error:\nThe file is not opened!\n");
			else
				printf("Successfully closed!\n");
			show();
			break;
		case 4:		/*写文件*/
			if(fd==-1)/*如果文件未打开*/
				printf("Error:\nThe file is not opened!\n");
			else
			{
				printf("Please input the file contect:");
				scanf("%s",contect);
				flag=write(fd,contect,strlen(contect));
				if(flag==0)
					printf("Successfully write!\n");
				else
					printf("Error:\nThe disk size is not enough!\n");
			}
			show();
			break;
		case 5:		/*读文件*/
			if(fd==-1)/*如果文件未打开*/
				printf("Error:\nThe file is not opened!\n");
			else
			{	
				printf("Please input the size of read:");
				scanf("%d",&r_size);
				flag=read(fd,contect,r_size);
				if(flag==-1)
					printf("Error:\nThe size is over the length of the file!\n");
				else
				{
					printf("Successfully read!\nthe contect is:");
					for(i=0;i<r_size;i++)
						printf("%c",contect[i]);
				}

			}
			show();
			break;
		case 6:		/*删除文件*/
			scanf("%s",name);
			flag=del(name);
			if(flag==-1)
				printf("Error:\nThe file not exist!\n");
			else if(flag==-2)
				printf("Error:\nThe file is opened.please first close it!");
			else if(flag==-3)
				printf("Error:\nThe delete is not the file!\n");
			else
				printf("Successfully delete!\n");
			show();
			break;
		case 7:		 /*创建子目录*/
			scanf("%s",name);
			flag=mkdir(name);
			if(flag==-1)
				printf("Error:\nThe length of name is too long!\n");
			else if(flag==-2)
				printf("Error:\nThe direct item is already full!\n");
			else if(flag==-3)
				printf("Error:\nThe name is already in the direct!\n");
			else if(flag==0)
				printf("Successfully make direct!\n");	
			show();
			break;
		case 8:		/*删除子目录*/
			scanf("%s",name);
			flag=rmdir(name);
			if(flag==-1)
				printf("Error:\nThe direct not exist!\n");
			else if(flag==-2)
				printf("Error:\nThe direct have son direct,please first remove the son direct!\n");
			else if(flag==-3)
				printf("Error:\nThe remove is not direct!\n");
			else if(flag==0)
				printf("Successfully remove direct!\n");	
			show();
			break;
		case 9:		/*显示当前目录的子目录*/
			dir();
			show();
			break;
		case 10:	/*更改当前目录*/
			scanf("%s",name);
			flag=cd(name);
			if(flag==-1)
				printf("Error:\nThe path no correct!\n");
			else if(flag==-2)
				printf("Error:\nThe opened is not direct!\n");
			show();
			break;
		default:
			printf("\nError!The command is wrong!\n");
			show();
		};
	}
	return;
}