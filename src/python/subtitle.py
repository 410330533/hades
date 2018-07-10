from os.path import splitext
import re

def adjst_subtitle(filename, seconds):
    (root, ext) = splitext(filename)
    if ext == '.ass':
        process_ass(filename, seconds)
    elif ext == '.srt':
        process_srt(filename, seconds)
    else:
        print('I cannot process the ext.')

def process_ass(filename, seconds):
    f = open(filename, 'r')
    for l in f.readlines():
        if not re.match('^Dialogue', l):
            print(l, end='')
            continue

        r = l.split(',')
        /////////////
        print('r1 = %s, r2 = %s' % (r[1], r[2]))
    f.close()

if __name__ == '__main__':
    filename = '[tvN] Signal.E01.160122.HDTV.H264.720p-WITH.chs.ass'
    seconds = 10

    adjst_subtitle(filename, seconds)