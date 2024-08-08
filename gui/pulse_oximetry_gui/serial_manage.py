# This Python file uses the following encoding: utf-8

from PySide6 import QtCore
import serial
import threading
from PySide6.QtCore import Signal

class serial_manage(QtCore.QObject):
    packet = Signal(bytes)

    def __init__(self, port, baudrate):
        super().__init__()

        # Array for store all data
        self.temp_data = bytearray()

        self.port = port
        self.baudrate = baudrate
        self.running = False
        self.thread = threading.Thread(target=self.run)
        self.serial_connection = None

    def start(self):
        if not self.running:
            self.running = True
            self.serial_connection = serial.Serial(self.port, self.baudrate, timeout=1)
            self.thread.start()

    def stop(self):
        self.running = False
        if self.serial_connection and self.serial_connection.is_open:
            self.serial_connection.close()

    def run(self):
        while self.running:
            if self.serial_connection.in_waiting > 8:
                data = self.serial_connection.read(8)
                self.temp_data.extend(data)
                if self.temp_data[0] == 0x01 and self.temp_data[7] == 0x04:
                    self.packet.emit(self.temp_data[:8])
                    self.temp_data = self.temp_data[8:]
                else:
                    self.temp_data = self.temp_data[1:]

    def send(self, command_bytes):
        if self.serial_connection and self.serial_connection.is_open:
            self.serial_connection.write(command_bytes)
