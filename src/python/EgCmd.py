from cmd import Cmd
# import cmd, sys

class MyPrompt(Cmd):
    def do_hello(self, args):
        """Says hello. If you provide a name, it will greet you with it."""
        if len(args) == 0:
            name = 'stranger'
        else:
            name = args
        print('hello %s' % (name))

    def do_quit(self, args):
        """Quits the program."""
        print('quit...')
        raise SystemExit

if __name__ == '__main__':
    p = MyPrompt()
    # p.prompt = '>'
    # p.cmdloop('Starting prompt...')
    p.cmdloop()