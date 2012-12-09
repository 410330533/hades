import xml.etree.ElementTree
import MySQLdb

import bkConfig
import mysqlExecutor

# get contactTable
def get_contactTable(xml_path):
    tree = xml.etree.ElementTree.parse(xml_path)
    root = tree.getroot()
    
    contact_table = []
    for contact in root:
        tmp = {}
        tmp['fileAs'] = contact.find('FileAs').text
        if contact.find('FirstName') is None:
            tmp['firstName'] = ''
        else:
            tmp['firstName'] = contact.find('FirstName').text
        if contact.find('LastName') is None:
            tmp['lastName'] = ''
        else:
            tmp['lastName'] = contact.find('LastName').text
        tmp['smsLock'] = contact.find('SmsLock').text
        tmp['phoneNumber'] = ','.join([phone.attrib['Value'] for phone in contact.find('Phone')])
        
        contact_table.append(tmp)
    
    return contact_table

# insert into mysql(contact)
def insert2db_contact(contact_table):
    for line in contact_table:
        sql = "insert into contact(fileAs, firstName, lastName, smsLock, phoneNumber) \
                values ('%s', '%s', '%s', '%s', '%s')" % \
                (line['fileAs'], line['firstName'], line['lastName'], line['smsLock'], line['phoneNumber'])
        mysqlExecutor.execSql(sql)

if __name__ == '__main__':
    # parser xml
    xml_path = 'backup/%s/Contact/Contact.xml' % bkConfig.bk_folder
    contact_table = get_contactTable(xml_path)
    
    # insert into mysql
    insert2db_contact(contact_table)
    
    print('end...')