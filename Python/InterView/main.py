import socket
from tqdm import tqdm as track
import asyncio

async def onServerActivate():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('127.0.0.1', 2000))
    server.listen(4)
    client_socket, address = server.accept()
    data = client_socket.recv(1024).decode('utf-8')
    print(data)
    HDRS = 'HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=utf-8\r\n\r\n'
    content = 'Successfully'.encode('utf-8')
    client_socket.send(HDRS.encode('utf-8') + content)

async def working():
    for i in track(range(20)):
        print(" Working...", end='\t')
        await asyncio.sleep(0.05)


async def main():
    server = asyncio.create_task(onServerActivate())
    await server
    print("THIS IS THE END")

if __name__ == '__main__':
    asyncio.run(main())

