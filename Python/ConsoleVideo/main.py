import cv2
import time

# Определение символов для отображения
symbols = '@%#*+=-:. '

# Загрузка видео
video = cv2.VideoCapture('BlackWhite.mp4')

# Определение размера ASCII-ART изображения
art_width = 80

# Чтение и обработка каждого кадра видео
while video.isOpened():
    ret, frame = video.read()
    if not ret:
        break

    # Масштабирование кадра до размера ASCII-ART изображения
    resized_frame = cv2.resize(frame, (art_width, int(art_width / frame.shape[1] * frame.shape[0])), interpolation=cv2.INTER_NEAREST)

    # Преобразование кадра в цветное ASCII-ART изображение
    ascii_image = ''
    for row in resized_frame:
        for pixel in row:
            # Получение значения яркости пикселя
            brightness = sum(pixel) / 3

            # Определение символа на основе яркости пикселя
            symbol_index = int(brightness / (256 / len(symbols)))
            symbol = symbols[symbol_index]

            # Добавление символа к ASCII-ART изображению
            ascii_image += symbol

        # Добавление символа новой строки к ASCII-ART изображению
        ascii_image += '\n'

    # Вывод ASCII-ART изображения
    print(ascii_image)

    # Задержка между кадрами
    time.sleep(0.024)

# Освобождение ресурсов
video.release()
cv2.destroyAllWindows()