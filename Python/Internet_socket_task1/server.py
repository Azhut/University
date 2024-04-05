# Сервер
import socket
import threading

def handle_client(client_socket):
    request = client_socket.recv(1024)
    print("[*] Received: {}".format(request.decode()))
    client_socket.send("ACK!".encode())
    client_socket.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('127.0.0.1', 9999))
    server.listen(5)
    print("[*] Listening on 127.0.0.1:9999")

    while True:
        client, addr = server.accept()
        print("[*] Accepted connection from: {}:{}".format(addr[0], addr[1]))
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

start_server()
