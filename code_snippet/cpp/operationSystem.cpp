#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MEM_D_SIZE 1024*1024					//1M���̿ռ�		
#define DISKSIZE 256							//���̿��С
#define MSD 5									//�����Ŀ¼��
#define DISK_NUM    4*1024						//���̿���Ŀ
#define	FATSIZE		4*1024*8					//FAT���С8   DISK_NUM*sizeof(struct fatitem)
#define	MOFN 5									//����ļ�����Ŀ
#define ROOT_DISK_NO 1+FATSIZE/DISKSIZE			//��Ŀ¼��ʼ�̿��
#define	ROOT_DISK_SIZE sizeof(struct direct)	//��Ŀ¼��С(MSD+2)*28=196

/** FAT����ṹ */
struct fatitem	 
{
	int item;									//����ļ���һ�����̵�ָ��
	char em_disk;								//���̿���б�־λ 0����
};

/** Ŀ¼��ṹ */
struct direct
{
	struct FCB									//�ļ����ƿ���Ϣ
	{
		char name[9];							//�ļ�/Ŀ¼ ��8λ
		char property;							//����  1ΪĿ¼  2Ϊ��ͨ�ļ�
		int size;								//�ļ�/Ŀ¼�Ĵ�С
		int	firstdisk;							//�ļ�/Ŀ¼��Ӧ��ʼ�̿��
		int next;								//��Ŀ¼��ʼ�̿��
		int sign;								//1�Ǹ�Ŀ¼ 0���Ǹ�Ŀ¼
	}directitem[MSD+2];							//��0��1����������ŵ�ǰĿ¼����һ��Ŀ¼
};

/** �ļ��򿪱���ṹ */
struct opentable 
{
	struct opentableitem 
	{
		char name[9];							//�ļ���
		int firstdisk;							//��ʼ�̿��
		int size;								//�ļ��Ĵ�С
	}openitem[MOFN];							//������ļ��������Ŀ
	int	cur_size;								//��ǰ�򿪵��û������Ŀ
};

/** ����ȫ�ֱ��� */
struct fatitem *fat;							//FAT��
struct direct *root;							//��Ŀ¼
struct direct *cur_dir;							//��ǰĿ¼
struct opentable u_opentable;					//�ļ��򿪱�
int fd=-1;										//�ļ��򿪱�ĳ�ʼ���Ϊ��1
char *bufferdir;								//��¼��ǰ·������
char *fdisk;									//���������ʼ��ַ

/** �������� */
void initfile();								//��ʼ���ļ�ϵͳ
void format();									//��ʽ��
void enter();									//�����ļ�ϵͳ
void halt();									//�˳��ļ�ϵͳ
int create(char *name);							//�����ļ�
int open(char *name);							//���ļ�
int close(char *name);							//�ر��ļ�
int write(int fd,char *buf,int len);			//д�ļ�
int read(int fd,char *buf,int len);				//���ļ�
int del(char *name);							//ɾ���ļ�
int mkdir(char* name);							//������Ŀ¼
int rmdir(char* name);							//ɾ����Ŀ¼
void dir();										//��ʾ��ǰĿ¼����Ŀ¼
int cd(char *name);								//���ĵ�ǰĿ¼

void show();									//��ʾ������ʾ��
void print();									//�����ʾ��Ϣ

void initfile()
{
	fdisk=(char *)malloc(MEM_D_SIZE); 
	format();
	free(fdisk);
}

void format()
{
	int i;
	FILE *fp;									//�ļ��ṹ��ָ�������

	fat=(struct fatitem *)(fdisk+DISKSIZE);		//�����FAT��ĵ�ַ
	/*��ʼ��FAT��*/
	fat[0].item=-1;								//������
	fat[0].em_disk='1';

	for(i=1;i<ROOT_DISK_NO-1;i++)				//FAT���Ŵ��̿��
	{
		fat[i].item=i+1;	
		fat[i].em_disk='1';
	}
	fat[ROOT_DISK_NO-1].item=-1;
	fat[ROOT_DISK_NO-1].em_disk='1';

	fat[ROOT_DISK_NO].item=-1;					//��Ŀ¼��Ŵ��̿��
	fat[ROOT_DISK_NO].em_disk='1';

	for(i=ROOT_DISK_NO+1;i<DISK_NUM;i++)
	{
		fat[i].item=-1;
		fat[i].em_disk='0';
	}

	root=(struct direct *)(fdisk+DISKSIZE+FATSIZE);//�������Ŀ¼���ĵ�ַ
	/*��ʼ����Ŀ¼*/
	/*ָ��ǰĿ¼��Ŀ¼��*/
	root->directitem[0].sign=1;		
	root->directitem[0].firstdisk=ROOT_DISK_NO;
	strcpy(root->directitem[0].name,".");
	root->directitem[0].next=root->directitem[0].firstdisk;
	root->directitem[0].property='1';
	root->directitem[0].size=ROOT_DISK_SIZE;
	/*ָ����һ��Ŀ¼��Ŀ¼��*/
	root->directitem[1].sign=1;
	root->directitem[1].firstdisk=ROOT_DISK_NO;
	strcpy(root->directitem[1].name,"..");
	root->directitem[1].next=root->directitem[1].firstdisk;
	root->directitem[1].property='1';
	root->directitem[1].size=ROOT_DISK_SIZE;
	/*�����Ŀ¼����ʼ��Ϊ��*/
	for(i=2;i<MSD+2;i++)
	{
		root->directitem[i].sign=0;
		root->directitem[i].firstdisk=-1;
		strcpy(root->directitem[i].name,"");
		root->directitem[i].next=-1;
		root->directitem[i].property='0';
		root->directitem[i].size=0;
	}
	//��������̿ռ����ݱ��浽�����ļ���
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
	fdisk=(char *)malloc(MEM_D_SIZE);					//����1M�ռ�
	if((fp=fopen("data.txt","rb"))==NULL)				//��data�ļ������ݱ��浽������̿ռ�
	{
		printf("Error:\nCannot open file\n");
		return;
	}
	fread(fdisk,MEM_D_SIZE,1,fp);						//�������е����ݶ���������̿ռ�
	fat=(struct fatitem *)(fdisk+DISKSIZE);				//�ҵ�FAT��ĵ�ַ
	root=(struct direct *)(fdisk+DISKSIZE+FATSIZE);		//�ҵ�root�ĵ�ַ
	fclose(fp);
	/*��ʼ���û��򿪱�*/
	for(i=0;i<MOFN;i++)
	{
		strcpy(u_opentable.openitem[i].name,"");
		u_opentable.openitem[i].firstdisk=-1;
		u_opentable.openitem[i].size=0;
	}
	u_opentable.cur_size=0;

	cur_dir=root;										//��ǰĿ¼Ϊ��Ŀ¼
	bufferdir=(char *)malloc(sizeof(char));
	strcpy(bufferdir,"E:");								//��ǰĿ¼Ϊ��Ŀ¼
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
	if(fwrite(fdisk,MEM_D_SIZE,1,fp)!=1)				//��������̿ռ����ݱ��浽�����ļ���
		printf("Error:\nFile write error!\n");
	fclose(fp);

	free(fdisk);										//�ͷ�������̿ռ�

	for(i=0;i<MOFN;i++)									//�����û����û���
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

	if(strlen(name)>8)									//����ļ������ȴ���8λ
		return(-1);

	for(i=2;i<MSD+2;i++)								//����п���Ŀ¼���˳�
	{
		if(cur_dir->directitem[i].firstdisk==-1)
			break;
	}

	for(j=2;j<MSD+2;j++)								//�������������ļ����ļ����Ѿ�����Ŀ¼�������˳�
	{
		if(!strcmp(cur_dir->directitem[j].name,name))
			break;
	}

	if(i>=MSD+2)										//����޿�Ŀ¼��
		return (-2);
	if(u_opentable.cur_size>=MOFN)						//���ļ�̫��
		return (-3);
	if(j<MSD+2)											//����ļ����Ѿ�����Ŀ¼����
		return(-4);

	for(j=ROOT_DISK_NO+1;j<DISK_NUM;j++)				//���ҵ����д��̿���˳�,j ���Ƕ�Ӧ�Ŀ��д��̿��
		if(fat[j].em_disk=='0')
			break;
	fat[j].em_disk='1';									//���ÿ��п��ó��Ѿ�����
	//��дĿ¼��
	strcpy(cur_dir->directitem[i].name,name);
	cur_dir->directitem[i].firstdisk=j;
	cur_dir->directitem[i].size=0;
	cur_dir->directitem[i].next=j;
	cur_dir->directitem[i].property='0';
	//�򿪸��ļ�
	fd=open(name);										//FD��Ϊ���ļ���������J
	return 0;
}

int open(char *name)
{
	int i,j;
	/*���ļ��Ƿ����*/
	for(i=2;i<MSD+2;i++)
		if(!strcmp(cur_dir->directitem[i].name,name))
			break;
	if(i>=MSD+2)/*���ļ�������*/
		return(-1);
	/*�ļ��Ƿ��Ѿ���*/
	for(j=0;j<MOFN;j++)
		if(!strcmp(u_opentable.openitem[j].name,name))
			break;
	if(j<MOFN)/*�ļ��Ѿ���*/
		return(-2);

	if(u_opentable.cur_size>=MOFN)/*�ļ���̫��*/
		return(-3);
	/*����һ�������û����ļ������*/
	for(j=0;j<MOFN;j++)
		if(u_opentable.openitem[j].firstdisk==-1)
			break;
	/*��д���������Ϣ*/
	u_opentable.openitem[j].firstdisk=cur_dir->directitem[i].firstdisk;
	strcpy(u_opentable.openitem[j].name,name);
	u_opentable.openitem[j].size=cur_dir->directitem[i].size;
	u_opentable.cur_size++;
	/*�����û��򿪱�������*/
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
	if(i>=MOFN)/*�رյ��ļ�û�д�*/
		return(-1);
	/*��ո��ļ����û��򿪱���������*/
	strcpy(u_opentable.openitem[i].name,"");
	u_opentable.openitem[i].firstdisk=-1;
	u_opentable.openitem[i].size=0;
	u_opentable.cur_size--;

	fd=-1;/*�ر��ļ����fd��ʼ��Ϊԭ����*/
	return 0;
}

int write(int fd,char *buf,int len)
{
	char * first;
	int item,i,j,k;
	int ilen1,ilen2,modlen,temp;
	/*��ȡ�û��򿪱��Ӧ�����һ���̿��*/
	item=u_opentable.openitem[fd].firstdisk;
	/*�ҵ���ǰĿ¼����Ӧ��������*/
	for(i=2;i<MSD+2;i++)
		if(cur_dir->directitem[i].firstdisk==item)
			break;
	temp=i;/*������ŵ�ǰĿ¼����±�*/
	/*�ҵ�item�Ǹ��ļ������һ����̿�*/
	while(fat[item].item!=-1)
		item=fat[item].item;
	first=fdisk+item*DISKSIZE+u_opentable.openitem[fd].size%DISKSIZE;/*��������ļ�����ĩ�ĵ�ַ*/

	if((DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE)>len)/*��������̿�ʣ��Ĵ�С����Ҫд����ļ��Ĵ�С*/
	{
		strcpy(first,buf);/*д���ݵ��������*/
		u_opentable.openitem[fd].size=u_opentable.openitem[fd].size+len;/*�޸��û����ļ�������ļ��ĳ���*/
		cur_dir->directitem[temp].size=cur_dir->directitem[temp].size+len;/*�޸�Ŀ¼����ļ�����*/
	}
	else
	{
		for(i=0;i<(DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE);i++)/*дһ�������ݵ����һ����̿��ʣ���ֽ�*/
			first[i]=buf[i];
		ilen1=len-(DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE);/*���������һ����̿��ʣ���ֽڻ�ʣ�����ֽ�δ�洢*/
		ilen2=ilen1/DISKSIZE;
		modlen=ilen1%DISKSIZE;
		if(modlen>0)
			ilen2=ilen2+1;/*��Ҫ�Ĵ��̿��1*/
		for(j=0;j<ilen2;j++)
		{
			for(i=ROOT_DISK_NO+1;i<DISK_NUM;i++)/*Ѱ�ҿ����̿�*/
				if(fat[i].em_disk=='0')
					break;
			if(i>=DISK_NUM)/*������̿��Ѿ���������*/
				return(-1);
			first=fdisk+i*DISKSIZE;/*�ҵ����ǿ���д��̿����ʼ��ַ*/
			if(j==ilen2-1)/*��������Ҫ�����һ��*/
				for(k=0;k<len-(DISKSIZE-u_opentable.openitem[fd].size%DISKSIZE)-j*DISKSIZE;k++)
					first[k]=buf[k];
			else/*����������Ҫ�����һ��*/
				for(k=0;k<DISKSIZE;k++)
					first[k]=buf[k];
			fat[item].item=i;	/*�ҵ�һ���������Ŵ������һ���ָ����*/
			fat[i].em_disk='1';	/*���ҵ��Ĵ��̿�Ŀ��б�־λΪ�ѷ���*/
			fat[i].item=-1;		/*���ҵ��Ĵ��̿��ָ��Ϊ��1*/
		}	
		u_opentable.openitem[fd].size=u_opentable.openitem[fd].size+len;/*�޸��û����ļ�������ļ��ĳ���*/
		cur_dir->directitem[temp].size=cur_dir->directitem[temp].size+len;/*�޸�Ŀ¼����ļ�����*/
	}	
	return 0;
}

int read(int fd,char *buf,int len)
{
	char *first;
	int i,j,item;
	int ilen1,modlen;
	item=u_opentable.openitem[fd].firstdisk;
	if(len>u_opentable.openitem[fd].size)/*���������ļ����ȱ�ʵ���ļ����ȳ�*/
		return(-1);
	ilen1=len/DISKSIZE;
	modlen=len%DISKSIZE;
	if(modlen!=0)
		ilen1=ilen1+1;/*�����ļ���ռ���̿�Ŀ���*/
	first=fdisk+item*DISKSIZE;/*�����ļ�����ʼλ��*/
	for(i=0;i<ilen1;i++)
	{
		if(i==ilen1-1)/*��������һ�����̿�*/
			for(j=0;j<len-i*DISKSIZE;j++)
				buf[i*DISKSIZE+j]=first[j];
		else/*�������һ����̿�*/
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
	for(i=2;i<MSD+2;i++)/*����Ҫɾ�����ļ��Ƿ��ڵ�ǰĿ¼��*/
		if(!strcmp(cur_dir->directitem[i].name,name))
			break;
	cur_item=i;/*��������Ŀ¼�����ţ����ͷ�Ŀ¼����*/

	if(i>=MSD+2)/*������ڵ�ǰĿ¼��*/
		return(-1);

	if(cur_dir->directitem[cur_item].property!='0')/*���ɾ���Ĳ���Ŀ¼*/
		return(-3);

	for(i=0;i<MOFN;i++)/*����ļ��򿪣�����ɾ�����˳�*/
		if(!strcmp(u_opentable.openitem[i].name,name))
			return(-2);

	item=cur_dir->directitem[cur_item].firstdisk;/*���ļ�����ʼ�̿��*/
	while(item!=-1)/*�ͷŴ��̿ռ䣬��FAT��Ķ�Ӧ������޸�*/
	{
		temp=fat[item].item;
		fat[item].item=-1;
		fat[item].em_disk='0';
		item=temp;
	}
	/*�ͷ�Ŀ¼��*/
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

	if(strlen(name)>8)		/*���Ŀ¼�����ȴ���8λ*/
		return(-1);

	for(i=2;i<MSD+2;i++)	/*���ҿ���Ŀ¼��*/
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
	if(j<MSD+2)/*���������Ŀ¼��Ŀ¼���Ѿ�����Ŀ¼����*/
		return(-3);

	for(j=ROOT_DISK_NO+1;j<DISK_NUM;j++)/*���ҵ����д��̿���˳�,j ���Ƕ�Ӧ�Ŀ��д��̿��*/
		if(fat[j].em_disk=='0')
			break;
	fat[j].em_disk='1';	/*���ÿ��п��ó��Ѿ�����*/
	/*��дĿ¼��*/
	strcpy(cur_dir->directitem[i].name,name);
	cur_dir->directitem[i].firstdisk=j;
	cur_dir->directitem[i].size=ROOT_DISK_SIZE;
	cur_dir->directitem[i].next=j;/*ָ����Ŀ¼����ʼ�̿��*/
	cur_dir->directitem[i].property='1';

	cur_mkdir=(struct direct *)(fdisk+cur_dir->directitem[i].firstdisk*DISKSIZE);

	/*��ʼ����Ŀ¼*/
	/*ָ��ǰĿ¼��Ŀ¼��*/
	cur_mkdir->directitem[0].sign=0;		
	cur_mkdir->directitem[0].firstdisk=cur_dir->directitem[i].firstdisk;
	strcpy(cur_mkdir->directitem[0].name,".");
	cur_mkdir->directitem[0].next=cur_mkdir->directitem[0].firstdisk;
	cur_mkdir->directitem[0].property='1';
	cur_mkdir->directitem[0].size=ROOT_DISK_SIZE;
	/*ָ����һ��Ŀ¼��Ŀ¼��*/
	cur_mkdir->directitem[1].sign=0;
	cur_mkdir->directitem[1].firstdisk=cur_dir->directitem[0].firstdisk;
	strcpy(cur_mkdir->directitem[1].name,"..");
	cur_mkdir->directitem[1].next=cur_mkdir->directitem[1].firstdisk;
	cur_mkdir->directitem[1].property='1';
	cur_mkdir->directitem[1].size=ROOT_DISK_SIZE;

	for(i=2;i<MSD+2;i++)/*��Ŀ¼����ʼ��Ϊ��*/
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
	/*��鵱ǰĿ¼�������޸�Ŀ¼*/
	for(i=2;i<MSD+2;i++)
	{
		if(!strcmp(cur_dir->directitem[i].name,name))
			break;
	}

	if(cur_dir->directitem[i].property!='1')/*���ɾ���Ĳ���Ŀ¼*/
		return(-3);

	if(i>=MSD+2)/*���û���˳�*/
		return(-1);
	/*�ж���������Ŀ¼*/
	temp_dir=(struct direct *)(fdisk+cur_dir->directitem[i].next*DISKSIZE);/*������Ŀ¼����ʼ��ַ*/
	for(j=2;j<MSD+2;j++)
	{
		if(temp_dir->directitem[j].next!=-1)
			break;
	}
	if(j<MSD+2)		/*�������Ŀ¼���ļ��˳�*/
		return(-2);

	/*�ҵ���ʼ�̿�ţ��������ͷ�*/
	item=cur_dir->directitem[i].firstdisk;
	fat[item].em_disk='0';

	/*�޸�Ŀ¼��*/
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
		if(cur_dir->directitem[i].firstdisk!=-1)/*���������Ŀ¼*/
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
	temp_dir=cur_dir;  /*������ʱĿ¼���浱ǰĿ¼*/
	str=name;			/*str������¼�´β��ҵ���ʼ��ַ*/
	str1=strchr(str,'\\');/*�ҵ�"\"�ַ���λ��*/
	while(str1!=NULL)/*����ҵ�*/
	{
		temp=(char *)malloc(sizeof(char));/*Ϊһ����Ŀ¼�����ַ���ռ�*/
		for(i=0;i<str1-str;i++)
			temp[i]=str[i];
		temp[i]='\0';

		for(j=2;j<MSD+2;j++)/*���Ҹ���Ŀ¼�Ƿ��ڵ�ǰĿ¼��*/
		{
			if(!strcmp(temp_dir->directitem[j].name,temp))
				break;
		}
		if(j>=MSD+2)/*������ڵ�ǰĿ¼���˳�*/
			return(-1);

		item=temp_dir->directitem[j].firstdisk; 
		temp_dir=(struct direct *)(fdisk+item*DISKSIZE); /*���㵱ǰĿ¼��������̿ռ��λ��*/

		str=str1+1;/*��ȥ"/"��ռ��һλ�ռ䣬��¼�´β��ҵ���ʼ��ַ*/
		str1=strchr(str,'\\');
	}
	str1=str1+strlen(str);
	temp=(char *)malloc(sizeof(char));
	for(i=0;i<(int)strlen(str);i++)
		temp[i]=str[i];
	temp[i]='\0';
	for(j=0;j<MSD+2;j++)/*���Ҹ���Ŀ¼�Ƿ��ڵ�ǰĿ¼��*/
	{
		if(!strcmp(temp_dir->directitem[j].name,temp))
			break;
	}

	if(temp_dir->directitem[j].property!='1')/*����򿪵Ĳ���Ŀ¼*/
		return(-2);

	if(j>=MSD+2)/*������ڵ�ǰĿ¼���˳�*/
		return(-1);

	item=temp_dir->directitem[j].firstdisk;
	temp_dir=(struct direct *)(fdisk+item*DISKSIZE);/*���㵱ǰĿ¼��������̿ռ��λ��*/

	if(!strcmp("..",name))
	{
		if(cur_dir->directitem[j].sign!=1)/*�����Ŀ¼���Ǹ�Ŀ¼*/
		{
			point=strchr(bufferdir,'\\');
			while(point!=NULL)
			{
				point1=point+1;/*��ȥ"/"��ռ��һλ�ռ䣬��¼�´β��ҵ���ʼ��ַ*/
				point=strchr(point1,'\\');
			}
			*(point1-1)='\0';/*����һ��Ŀ¼ɾ��*/
		}

	}
	else if(!strcmp(".",name))
	{
		bufferdir=bufferdir;/*����ǵ�ǰĿ¼�򲻱�*/
	}
	else
	{
		bufferdir=strcat(bufferdir,"\\");/*�޸ĵ�ǰĿ¼*/
		bufferdir=strcat(bufferdir,name);
	}
	cur_dir=temp_dir;/*����ǰĿ¼ȷ������*/
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
	printf("\t\t�˳��ļ�ϵͳ         halt\n");
	printf("\t\t�����ļ�             create �ļ���\n");
	printf("\t\t���ļ�             open �ļ���\n");
	printf("\t\t�ر��ļ�             close �ļ���\n");
	printf("\t\t���ļ�             open �ļ���\n");
	printf("\t\tд�ļ�               write\n");
	printf("\t\t���ļ�               read\n");
	printf("\t\tɾ���ļ�             del �ļ���\n");
	printf("\t\t������Ŀ¼           mkdir Ŀ¼��\n");
	printf("\t\tɾ����Ŀ¼           rmdir Ŀ¼��\n");
	printf("\t\t��ʾ��ǰĿ¼����Ŀ¼ dir\n");
	printf("\t\t���ĵ�ǰĿ¼         cd Ŀ¼��\n");
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

	if((fp=fopen("data.txt","rb"))==NULL)/*�����û�н��и�ʽ������Ҫ��ʽ��*/
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

	enter();/*�����ļ�ϵͳ*/
	print();
	show();

	strcpy(code[0],"halt"); /*������ȫ�������CODE������*/
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
		case 0:			/*�˳��ļ�ϵͳ*/
			halt();
			return;
		case 1:			/*�����ļ�*/
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
		case 2:		/*���ļ�*/

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
		case 3:		/*�ر��ļ�*/
			scanf("%s",name);
			flag=close(name);
			if(flag==-1)
				printf("Error:\nThe file is not opened!\n");
			else
				printf("Successfully closed!\n");
			show();
			break;
		case 4:		/*д�ļ�*/
			if(fd==-1)/*����ļ�δ��*/
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
		case 5:		/*���ļ�*/
			if(fd==-1)/*����ļ�δ��*/
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
		case 6:		/*ɾ���ļ�*/
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
		case 7:		 /*������Ŀ¼*/
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
		case 8:		/*ɾ����Ŀ¼*/
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
		case 9:		/*��ʾ��ǰĿ¼����Ŀ¼*/
			dir();
			show();
			break;
		case 10:	/*���ĵ�ǰĿ¼*/
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