from cmd2 import Cmd

class App(Cmd):
    def do_hello(self, line):
        """Says hello. If you provide a name, it will greet you with it."""
        print('hello %s' % (line))

if __name__ == '__main__':
    app = App()
    app.cmdloop()