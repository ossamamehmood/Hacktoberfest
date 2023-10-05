import asyncio
import json
import time
import wifi
from Comm.secrets import secrets
from socketpool import SocketPool

from pico import initiate_console, blink_pico_w_led


def start_wifi():
    try:
        print("Starting Wi-Fi")
        wifi.radio.start_ap(secrets['ssid'], secrets['password'])
    except:
        pass


def bind_socket():
    socketpool = SocketPool(wifi.radio)
    socket = SocketPool.socket(socketpool, SocketPool.AF_INET, SocketPool.SOCK_DGRAM)
    socket.setblocking(False)
    socket.bind(("", 5001))
    print(wifi.radio.ipv4_address_ap)
    return socket


async def receive_packets(socket):
    while True:
        buffer = bytearray(1024)
        try:
            num_bytes = socket.recv_into(buffer)
            data = json.loads(buffer[:num_bytes].decode())
            print(time.time())
            print(data)
        except:
            pass
        await asyncio.sleep(0)


async def main_loop():
    start_wifi()
    socket = bind_socket()
    pico_led_task = asyncio.create_task(blink_pico_w_led(0.05))
    console_task = asyncio.create_task(initiate_console())
    packets_task = asyncio.create_task(receive_packets(socket))
    await asyncio.gather(pico_led_task, console_task, packets_task)
