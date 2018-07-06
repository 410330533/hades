from os.path import splitext

def adjst_subtitle(filename, seconds):
    (root, ext) = splitext(filename)
    

if __name__ == '__main__':
    filename = '[tvN] Signal.E01.160122.HDTV.H264.720p-WITH.chs.ass'
    seconds = 10

    adjst_subtitle(filename, seconds)