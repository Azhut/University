from translate import Translator

translator = Translator(to_lang='ru')

while True:
    word = input("Enter a word in English (to exit enter 'exit'): ")

    if word.lower() == 'exit':
        break

    # Translate the word
    translation = translator.translate(word)

    # Write the word and its translation to the file
    with open('Output.txt', 'a') as file:
        file.write(f'{word} - {translation}\n')
