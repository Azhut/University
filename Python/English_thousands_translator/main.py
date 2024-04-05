import requests

def translate_word(word):
    url = f"https://translate.googleapis.com/translate_a/single?client=gtx&sl=en&tl=ru&dt=t&q={word}"
    response = requests.get(url)
    translation = response.json()[0][0][0]
    return translation

def main():
    file_path = "Text.txt"
    with open(file_path, "r") as file:
        text = file.read()

    word_count = len(text.split())
    char_count = len(text)

    print(f"Количество слов в тексте: {word_count}")
    print(f"Количество символов в тексте (включая пробелы): {char_count}")

    words = text.split()

    translated_words = []
    translated_set = set()
    for word in words:
        if word in translated_set:
            continue
        translation = translate_word(word)
        print(f"{word} - {translation}")
        choice = input("Нажмите Enter, чтобы записать слово в файл, или 'n', чтобы перейти к следующему слову: ")
        if choice == "":
            translated_words.append((word, translation))
            translated_set.add(word)

    output_file_path = "Output.txt"
    with open(output_file_path, "w") as output_file:
        output_file.write(f"Количество слов в тексте: {word_count}\n")
        output_file.write(f"Количество символов в тексте (включая пробелы): {char_count}\n")
        for i, (word, translation) in enumerate(translated_words):
            output_file.write(f"{i+1}. {word} - {translation}\n")

if __name__ == "__main__":
    main()
