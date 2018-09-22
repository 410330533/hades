import os
import cmd
import argparse
import socket

class Client(cmd.Cmd):
    prompt = '>>> '
    intro = 'welcome to the creator world...'

    # doc_header = 'doc_header'
    # misc_header = 'misc_header'
    # undoc_header = 'undoc_header'

    # ruler = '-'

    def __init__(self, host, port):
        super().__init__()
        self.encoding = 'utf-8'
        self.host     = host
        self.port     = port

        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((self.host, self.port))

    def emptyline(self):
        pass

    def do_hello(self, line):
        print("[cmd] hello {}".format(line))
        self.sock.send(bytes(line, self.encoding))
        response = str(self.sock.recv(1024), self.encoding)
        print("Received: {}".format(response))

    # def parse_subcmd(self, subcmd):
    #     parser = argparse.ArgumentParser()
    #     parser.add_argument('subcmd', nargs=1)
    #     parser.add_argument('params', nargs=2)
    #     args = parser.parse_args(subcmd.strip().split())
    #     return args

    def parse(self, cmd):
        return tuple(cmd.strip().split())

    def do_p(self, line):
        args = self.parse(line)
        if len(args) == 0:
            print('subcmd required.')
            return
        subcmd = args[0]

        if subcmd == 'water':
            return 1
        elif subcmd == 'wood':
            return 1
        else:
            print('unknown subcmd: %s' % (subcmd))
            return

    def do_exit(self, cmd):
        return True

if __name__ == '__main__':
    host = '0.0.0.0'
    port = 10080
    Client(host, port).cmdloop()