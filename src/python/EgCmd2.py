from cmd2 import Cmd
import cmd2

class App(cmd2.Cmd):
    def preloop(self):
        self.poutput("pre loop here...")

    def precmd(self, line):
        self.poutput('pre cmd here...')
        return line

    def do_hello(self, line):
        """Says hello. If you provide a name, it will greet you with it."""
        print('hello %s' % (line))

if __name__ == '__main__':
    app = App()
    app.cmdloop()