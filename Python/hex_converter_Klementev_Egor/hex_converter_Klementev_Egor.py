# hex_converter_Klementev_Egor
def hex_dump(data):
    offset = 0
    for i in range(0, len(data), 16):
        line = data[i:i+16]
        hex_data = ' '.join(["{:02x}".format(b) for b in line])
        ascii_data = ''.join([chr(b) if 32 <= b <= 126 else '.' for b in line])
        print("{:08x}: {:48} {}".format(offset, hex_data, ascii_data))
        offset += 16


# Пример использования
data = b'\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64\x48\x65\x6c\x6c\x6f\x20\x57\x6f\x72\x6c\x64'
hex_dump(data)




