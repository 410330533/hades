#!/bin/sh

# eg:
	# sh db_operation.sh backup ungzip
	# sh db_operation.sh restore ungzip commentset commentset_2010_02_05.sql
	
	# sh db_operation.sh backup gzip
	# sh db_operation.sh restore gzip commentset commentset_2010_02_05.sql.gz

host='localhost'
user='root'
passwd='taobao'

if [ $# -lt 1 ]; then
	echo 'parameter error...'
	exit
fi

# gzip
gzip=$2

# backup
if [ 'backup' = $1 ]; then
	date_str=`date +"%Y_%m_%d"`
	dbs_str='commentset m8backup'

	for db_str in $dbs_str
	do
		if [ 'gzip' = $gzip ]; then
			mysqldump -h${host} -u${user} -p${passwd} $db_str | gzip > $db_str'_'$date_str'.sql.gz'
		else
			mysqldump -h${host} -u${user} -p${passwd} $db_str > $db_str'_'$date_str".sql"
		fi
		echo "database ${db_str} backup done."
	done

	echo "backup done."
# restore
elif [ 'restore' = $1 ]; then
	echo 'i am restoring...'
	dbname=$3
	dbfile=$4
	if [ 'gzip' = $gzip ]; then
		gunzip < $dbfile | mysql -h${host} -u${user} -p${passwd} $dbname
	else
		mysql -h${host} -u${user} -p${passwd} $dbname < $dbfile
	fi
	echo 'restore done.'
else
	echo 'unrecognize opertator...'
fi
