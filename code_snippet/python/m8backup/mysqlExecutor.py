import MySQLdb

import bkConfig

# exec sql
def execSql(sql, host=bkConfig.db_host, user=bkConfig.db_user, passwd=bkConfig.db_passwd, db=bkConfig.db_dbname):
    conn = MySQLdb.connect(host=host, user=user, passwd=passwd, db=db, use_unicode=True)
    # important! here! fuck you!
    conn.set_character_set('utf8')
    cur = conn.cursor()
    cur.execute(sql)

# select sql
def selectSql(sql, host=bkConfig.db_host, user=bkConfig.db_user, passwd=bkConfig.db_passwd, db=bkConfig.db_dbname):
    conn = MySQLdb.connect(host=host, user=user, passwd=passwd, db=db, use_unicode=True)
    # important! here! fuck you!
    conn.set_character_set('utf8')
    cur = conn.cursor()
    cur.execute(sql)
    return cur.fetchall()

def exec_sql(sql, is_write):
    config = g_config['db']
    
    conn = MySQLdb.connect(host=config['host'], user=config['user'], passwd=config['passwd'], db=config['db']
        , connect_timeout=config['connect_timeout'], use_unicode=True, charset=config['charset'])
    cur = conn.cursor(MySQLdb.cursors.DictCursor)
    cur.execute(sql)
    conn.close()
    
    if is_write == False:
        result = cur.fetchall()
        cur.close()
        return result