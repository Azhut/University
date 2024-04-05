import json
import sqlite3


# Читаем содержимое из JSON в словарь и чистим JSON, потом метод переедет в getter_service
def read_erase_json(json_name):
    with open(json_name) as json_file:
        data = json.load(json_file)
    # __erase_from_json__(json_name)
    return data


# Затираем JSON
def __erase_from_json__(json_name):
    open(json_name, 'w').close()


# Устанавливаем соединение с базой данных
def __get_connection__(db_name):
    connection = sqlite3.connect(db_name)
    return connection


# Сохраняем изменения и закрываем соединение
def __commit_and_close__(connection):
    connection.commit()
    connection.close()


# Создаем таблицу sessions, если она еще не существует
def __db_create_sessions__(cursor):
    cursor.execute('''
   CREATE TABLE IF NOT EXISTS Sessions (
   session_id INTEGER PRIMARY KEY,
   date DATE,
   deviceType TEXT, 
   latitude DOUBLE,
   longitude DOUBLE,
   screenWidth INTEGER,
   screenHeight INTEGER                
   )'''
                   )


# методы для создания таблицы
def __init_sessions__():
    connection = __get_connection__('Sessions.db')
    cursor = connection.cursor()

    __db_create_sessions__(cursor)

    __commit_and_close__(connection)


# Внешний метод для app
def db_init():
    __init_sessions__()


# Запись содержимого parse_data из словаря в таблицу
def insert_data(Session):
    date = Session['date']
    deviceType = Session['deviceType']
    latitude = Session['location']['latitude']
    longitude = Session['location']['longitude']
    screenWidth = Session['screenWidth']
    screenHeight = Session['screenHeight']

    connection = __get_connection__('Sessions.db')
    cursor = connection.cursor()

    # SQL-запрос выделил отдельной переменной
    request = '''INSERT INTO Sessions 
              (date, deviceType, latitude, longitude, screenWidth, screenHeight) 
              VALUES (?, ?, ?, ?, ?, ?)'''

    cursor.execute(request, (date, deviceType, latitude, longitude, screenWidth, screenHeight))

    __commit_and_close__(connection)


def get_users():
    connection = __get_connection__('Sessions.db')
    cursor = connection.cursor()

    cursor.execute('SELECT * FROM SESSIONS')
    sessions = cursor.fetchall()

    session_list = []
    for session in sessions:
        session_dict = {
            'id': session[0],
            'date': session[1],
            'deviceType': session[2],
            'latitude': session[3],
            'longitude': session[4],
            'screenWidth': session[5],
            'screenHeight': session[6],
        }
        session_list.append(session_dict)

    connection.close()
    return session_list


def get_timestamps():
    connection = __get_connection__('Timestamps.db')
    cursor = connection.cursor()

    cursor.execute('SELECT * FROM TIMESTAMPS')
    timestamps = cursor.fetchall()

    timestamp_list = []
    for timestamp in timestamps:
        timestamp_dict = {
            'id': timestamp[0],
            'username': timestamp[1],
            'timestamp': timestamp[2]
        }
    timestamp_list.append(timestamp_dict)

    connection.close()
    return timestamp_list
