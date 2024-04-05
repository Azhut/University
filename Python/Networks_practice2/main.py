import socket
import struct
from datetime import datetime

NTP_EPOCH_OFFSET = 2208988800

def get_ntp_packet(server, port):
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.settimeout(5)
        s.sendto(b'\x1b' + 47 * b'\0', (server, port))
        data = s.recv(48)
        return data

def parse_ntp_packet(data):
    fields = struct.unpack("!B B B b 11I", data)
    print("Leap Indicator:", fields[0] >> 6)
    print("Version:", (fields[0] >> 3) & 0b111)
    print("Mode:", fields[0] & 0b111)
    print("Stratum:", fields[1])
    print("Poll Interval:", fields[2])
    print("Precision:", fields[3])
    print("Root Delay:", fields[4] / 2**16)
    print("Root Dispersion:", fields[5] / 2**16)
    print("Reference Identifier:", fields[6])
    print("Reference Timestamp:", datetime.utcfromtimestamp(fields[7] + fields[8] / 2**32 - NTP_EPOCH_OFFSET))
    print("Originate Timestamp:", datetime.utcfromtimestamp(fields[9] + fields[10] / 2**32 - NTP_EPOCH_OFFSET))
    print("Receive Timestamp:", datetime.utcfromtimestamp(fields[11] + fields[12] / 2**32 - NTP_EPOCH_OFFSET))
    print("Transmit Timestamp:", datetime.utcfromtimestamp(fields[13] + fields[14] / 2**32 - NTP_EPOCH_OFFSET))

if __name__ == "__main__":
    NTP_SERVER = "pool.ntp.org"
    NTP_PORT = 123

    try:
        packet = get_ntp_packet(NTP_SERVER, NTP_PORT)
        parse_ntp_packet(packet)
    except socket.timeout:
        print("Connection to NTP server timed out.")
    except Exception as e:
        print("An error occurred:", e)
