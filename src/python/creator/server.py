import socket
import threading
import socketserver

encoding = 'utf-8'

class ThreadedTCPRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
        while True:
            data = str(self.request.recv(1024), 'utf-8')
            print('client {}, [{}]'.format(self.client_address, data))

            if data == 'exit':
                break;

            # cur_thread = threading.current_thread()
            # response = bytes("[Server] {}:{}".format(cur_thread.name, data), 'utf-8')
            self.request.sendall(bytes("[Server] {}".format(data), encoding))

if __name__ == '__main__':
    host, port = '0.0.0.0', 10080
    # print("host = {}, port = {}".format(host, port))

    # server = socketserver.ThreadingTCPServer((host, port), ThreadedTCPRequestHandler)
    server = socketserver.TCPServer((host, port), ThreadedTCPRequestHandler)
    
    # t = threading.Thread(target = server.serve_forever)
    # t.daemon = True
    # t.start()
    # print("Server loop running in thread:", t.name)
    # t.join()

    server.serve_forever()

    # server.shutdown()
    # server.server_close()
