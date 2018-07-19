import os
import shutil
from email.mime.text import MIMEText
import smtplib
import socket
from email.header import Header

# python 3 required

def monitor_disk():
    # hd = {}
    # st = os.statvfs('/')
    # hd['avail'] = st.f_bsize * st.f_bavail
    # hd['total'] = st.f_bsize * st.f_blocks
    # hd['used']  = st.f_bsize * (st.f_blocks - st.f_bfree)
    # return hd

    hd = shutil.disk_usage('/')
    if (hd.used / hd.total > 0.8):
        hostname = socket.gethostname()
        ip       = socket.gethostbyname(hostname)
        body     = "hostname = %s, ip = %s, total = %s, used = %s, free = %s" % (hostname, ip, bytes2human(hd.total), bytes2human(hd.used), bytes2human(hd.free))
        sendmail('[monitor] 磁盘空间不足', body)

def sendmail(subject, body):
    host     = ''
    port     = 587
    user     = ''
    password = ''

    from_addr = ''
    to_addr   = ['']
    msg = MIMEText(body, 'plain', 'utf-8')
    msg['From']    = Header(from_addr, 'utf-8')
    msg['To']      = Header(','.join(to_addr), 'utf-8')
    msg['Subject'] = Header(subject, 'utf-8')

    server = smtplib.SMTP(host, port)
    server.starttls()
    # server.set_debuglevel(1)
    server.login(user, password)
    server.sendmail(from_addr, [to_addr], msg.as_string())
    server.quit()

def bytes2human(n):
    symbols = ('K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y')
    prefix = {}
    for i, s in enumerate(symbols):
        prefix[s] = 1 << (i+1)*10
    for s in reversed(symbols):
        if n >= prefix[s]:
            value = float(n) / prefix[s]
            return '%.1f%s' % (value, s)
    return "%sB" % n

if __name__ == '__main__':
    monitor_disk()
