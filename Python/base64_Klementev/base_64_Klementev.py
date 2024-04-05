# base64_encoder и base64_decoder, Клементьев Егор, МО-202
def base64_encode(text):
    base64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

    bytes_text = text.encode('utf-8')

    encoded_text = ""

    padding = 3 - len(bytes_text) % 3
    bytes_text += b'\x00' * padding

    for i in range(0, len(bytes_text), 3):
        chunk = int.from_bytes(bytes_text[i:i + 3], 'big')

        for j in range(4):
            index = (chunk >> (18 - j * 6)) & 0x3F
            encoded_text += base64_table[index]

    encoded_text = encoded_text[:-padding] + "=" * padding

    return encoded_text


BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"


def base64_decode(encoded_string):
    decoded_string = ""
    encoded_string = encoded_string.replace("=", "")

    binary_string = ""
    for char in encoded_string:
        binary_string += format(BASE64_CHARS.index(char), '06b')

    if len(binary_string) % 8 != 0:
        binary_string += ('0' * (8 - len(binary_string) % 8))

    for i in range(0, len(binary_string), 8):
        block = binary_string[i:i + 8]
        decoded_string += chr(int(block, 2))

    return decoded_string


if __name__ == "__main__":
    original_text = "Hello, my little world!?"
    encoded_text = base64_encode(original_text)
    decoded_text = base64_decode(encoded_text)

    print("Original Text:", original_text)
    print("Encoded Text:", encoded_text)
    print("Decoded Text:", decoded_text)
