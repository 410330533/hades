import socket
import threading
import socketserver

class ThreadedTCPRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
        data = str(self.request.recv(1024), 'utf-8')
        cur_thread = threading.current_thread()
        response = bytes("[Server] {}:{}".format(cur_thread.name, data), 'utf-8')
        self.request.sendall(response)

if __name__ == '__main__':
    host, port = '0.0.0.0', 10080
    server = socketserver.ThreadingTCPServer((host, port), ThreadedTCPRequestHandler)
    # ip, port = server.server_address
    print("host = {}, port = {}".format(host, port))
    t = threading.Thread(target = server.serve_forever)
    t.daemon = True
    t.start()
    print("Server loop running in thread:", t.name)
    # t.join()

    server.serve_forever()

    # server.shutdown()
    # server.server_close()
