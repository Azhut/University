import json

from flask import request


def parse():
    data = request.get_json()

    # Запись данных в json-файл
    try:
        with open('parse_data.json', 'a') as file:
            file.write(json.dumps(data))
            file.write('\n')
    except FileNotFoundError:
        return "File not found"

    return ('Данные успешно сохранены! <br>'
            'Проверяй файл parse_date.json<br>'
            '<br>'
            'не забудь, что лучше очищать этот файл, ведь json должен храниться только один')
