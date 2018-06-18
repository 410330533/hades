import os
from cmd import Cmd

class MyPrompt(Cmd):
    # prompt = '>'
    # intro = 'intro is here...'

    # doc_header = 'doc_header'
    # misc_header = 'misc_header'
    # undoc_header = 'undoc_header'

    # ruler = '-'

    def do_hello(self, line):
        """Says hello. If you provide a name, it will greet you with it."""
        print('hello %s' % (line))

    def do_go(self, line):
        """do go..."""
        print('go go go... version = %s' % (int(line)))

    def do_quit(self, line):
        """Quits the program."""
        print('quit...')
        raise SystemExit

    # def do_EOF(self, line):
        # return True

    def do_shell(self, line):
        """Run a shell command"""
        print("running shell command:", line)
        output = os.popen(line).read()
        print(output)

if __name__ == '__main__':
    MyPrompt().cmdloop()