- Android 内部短信数据库结构

```conf
threads 表
列名                      类型                  说明
_id                       integer               唯一标识，自增，从 1 开始
date                      integer               会话最新更新时间
message_count             integer               当前会话所包含的消息数量
recipient_ids             text                  接收者（ canonical_addresses 表的 id ）列表，所有接收者以空格隔开
snippet                   text                  最新更新的消息的内容（彩信为主题，短信为正文）
snippet_cs                integer               snippet 的编码方式，彩信： UTF-8 为 106 ，短信为 0
read                      integer               是否有未读信息： 0- 未读， 1- 已读  
type                      integer               会话类型， 0- 普通会话（只有一个接收者）， 1- 广播会话（多个接收者）
error                     integer               发送失败的消息（ type=5 ）的数量
has_attachment            integer               是否有附件： 0- 无， 1- 有
	
sms 表
列名                      类型                  说明
_id                       integer               唯一标识，自增，从 1 开始
thread_id                 integer               threads 表的 id
address                   text                  接收者手机号码，对于一个会话，有可能含有多个接收者，每个人都将收到一条短信
person                    integer               联系人（模块）列表里的序号，陌生人为 null
date                      integer               时间，以豪秒来表示
protocol                  integer               协议，分为： 0-SMS_RPOTO ， 1-MMS_PROTO 。成功发送后设置。
read                      integer               是否阅读： 0- 未读， 1- 已读  
status                    integer               状态： -1 默认值， 0-complete ， 64-pending ， 128-failed
type                      integer               ALL=0;INBOX=1;SENT=2;DRAFT=3;OUTBOX=4;FAILED=5;QUEUED=6;
reply_path_present        integer               TP-Reply-Path 位的值 0/1
subject                   text                  短信的主题，默认为空
body                      text                  短信内容
service_center            text                  短信服务中心号码编号
locked                    integer               此条短信是否已由用户锁定， 0- 未锁定， 1- 已锁定
error_code                integer               错误代码，有哪些值暂时未知
seen                      integer               用于指明该消息是否已被用户看到（非阅读，点开会话列表即可，不用打开会话），仅对收到的消息有用
```

- url

```conf
联系人 ContactsContract.Contacts.CONTENT_URI
       ContactsContract.Contacts.DISPLAY_NAME
联系人电话 ContactsContract.CommonDataKinds.Phone.CONTENT_URI
           ContactsContract.CommonDataKinds.Phone.NUMBER
           ContactsContract.CommonDataKinds.Phone.TYPE
联系人邮箱 ContactsContract.CommonDataKinds.Email.CONTENT_URI
           ContactsContract.CommonDataKinds.Email.TYPE
           ContactsContract.CommonDataKinds.Email.DATA
地址 ContactsContract.CommonDataKinds.StructuredPostal.CONTENT_URI
     ContactsContract.CommonDataKinds.StructuredPostal.STREET
     ContactsContract.CommonDataKinds.StructuredPostal.CITY
     ContactsContract.CommonDataKinds.StructuredPostal.REGION
     ContactsContract.CommonDataKinds.StructuredPostal.POSTCODE
     ContactsContract.CommonDataKinds.StructuredPostal.FORMATTED_ADDRESS
IM ContactsContract.CommonDataKinds.Im
昵称 ContactsContract.CommonDataKinds.Nickname
备注 ContactsContract.CommonDataKinds.Note
组织 ContactsContract.CommonDataKinds.Organization
```
