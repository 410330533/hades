import urllib.request
from gevent import monkey; monkey.patch_socket()
import gevent
from os.path import exists

def download(i):
    path = 'https://ipn.c.zgslb.net/kernelpanic/'
    file = 'kernelpanic-ep%d.mp3' % (i)
    url = path + file

    if exists(file):
        print('exists %s' % (file))
        return

    print('download %s' % (url))
    try:
        data = urllib.request.urlopen(url).read()
    except urllib.error.URLError as e:
        print('error %s %s' % (file, e))
        return

    with open(file, 'wb') as lf:
        lf.write(data)
    print('downloaded %s' % (file))

if __name__ == '__main__':
    # co-routine
    # gs = []
    # for i in range(1, 53):
    #     g = gevent.spawn(download, i)
    #     gs.append(g)

    # for g in gs:
    #     g.join()

    # sequence
    for i in range(1, 53):
        download(i)