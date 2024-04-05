
import socket
import time

def main():
    sock = socket.socket()
    sock.settimeout(10)  # Устанавливаем таймаут в 10 секунд

    server_address = ('127.0.0.1', 9999)
    sock.connect(server_address)
    print(f"Подключение к серверу {server_address}")

    message = b"Hello, server!"
    total_sent = 0

    while total_sent < len(message):
        sent = sock.send(message[total_sent:])
        total_sent += sent

    print(f"Сообщение отправлено")

    try:
        received = sock.recv(2048)
        print(f"Ответ получен: {received.decode()}")
    except socket.timeout as e:
        print("[*] Превышено время ожидания ответа: {}".format(e))
    finally:
        sock.close()

if __name__ == "__main__":
    main()