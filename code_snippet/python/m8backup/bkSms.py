import time
import xml.etree.ElementTree
import MySQLdb

import bkConfig
import mysqlExecutor

# get smsTable
def get_smsTable(xml_path):
    tree = xml.etree.ElementTree.parse(xml_path)
    root = tree.getroot()
    
    sms_table = []
    for sms in root:
        tmp = {}
        mobileNumber = sms.find('MobileNumber').text
        if mobileNumber.startswith('+86'):
            tmp['mobileNumber'] = mobileNumber[3:]
        else:
            tmp['mobileNumber'] = mobileNumber
        tmp['body'] = sms.find('Body').text
        tmp['type'] = sms.find('Type').text
        tmp['messageType'] = sms.find('MessageType').text
        tmp['read'] = sms.find('Read').text
        tmp['status'] = sms.find('Status').text
        tmp['reportDate'] = sms.find('ReportDate').text
        tmp['reportDate_d'] = time.strftime('%Y-%m-%d %H:%I:%S', time.localtime(float(tmp['reportDate'])))
        tmp['sendDate'] = sms.find('SendDate').text
        tmp['sendDate_d'] = time.strftime('%Y-%m-%d %H:%I:%S', time.localtime(float(tmp['sendDate'])))
        tmp['partNumber'] = sms.find('PartNumber').text
        tmp['smsId'] = sms.find('ID').text        
        sms_table.append(tmp)
    
    return sms_table

# insert into mysql(sms)
def insert2db_contact(sms_table):
    for line in sms_table:
        sql = "insert into sms(mobileNumber, body, type, messageType, `read`, status, reportDate, reportDate_d, sendDate, sendDate_d, partNumber, smsId) \
                values ('%s', '%s', %s, %s, %s, %s, %s, '%s', %s, '%s', '%s', %s)" % \
                (line['mobileNumber'], line['body'], line['type'], line['messageType'], line['read'], line['status'], 
                 line['reportDate'], line['reportDate_d'], line['sendDate'], line['sendDate_d'], 
                 line['partNumber'], line['smsId'])
        mysqlExecutor.execSql(sql)

if __name__ == '__main__':
    # parser xml
    xml_path = 'backup/%s/Sms/sms.xml' % bkConfig.bk_folder
    sms_table = get_smsTable(xml_path)
    
    # insert into mysql
    insert2db_contact(sms_table)
    
    print('end...')