# import json
# import sys
# sys.path.append("/path/to/flask/DB")
#
# from flask.DB import __get_connection__


##ПОКА ЧТО НЕ РАБОТАЕТ, НЕ МОЖЕТ ДОТЯНУТЬСЯ ДО ПАКЕТА
# def read_erase_json(json_name):
#     with open(json_name, 'r', encoding='utf-8') as f:
#         Users = json.load(f)
#     open(json_name, 'w').close()
#
#     print(Users)
#
#     return Users
#
# def get_users():
#     connection = __get_connection__('Users.db')
#     cursor = connection.cursor()
#
#     cursor.execute('SELECT * FROM USERS')
#     users = cursor.fetchall()
#
#     user_list = []
#     for user in users:
#         user_dict = {
#             'id': user[0],
#             'username': user[1],
#             'location': user[2]
#         }
#     user_list.append(user_dict)
#
#     connection.close()
#     return user_list
#
#
# def get_timestamps():
#     connection = __get_connection__('Timestamps.db')
#     cursor = connection.cursor()
#
#     cursor.execute('SELECT * FROM TIMESTAMPS')
#     timestamps = cursor.fetchall()
#
#     timestamp_list = []
#     for timestamp in timestamps:
#         timestamp_dict = {
#             'id': timestamp[0],
#             'username': timestamp[1],
#             'timestamp': timestamp[2]
#         }
#     timestamp_list.append(timestamp_dict)
#
#     connection.close()
#     return timestamp_list