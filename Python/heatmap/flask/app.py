import json

from flask import Flask
from flask import render_template, request
from flask_cors import CORS

from DB import db_init, insert_data, get_users
from statistics import get_statistics

app = Flask(__name__)
CORS(app)   

def write(session):
    with open('parse_data_save.txt', 'a') as file:
        file.write(json.dumps(session) + '\n')

@app.route('/')
def index():
    return ('Сейчас мы будем парсить данные пользователей без их разрешения на это))) <br>'
            'Для этого добавить в адресной строке "/parse"<br>'
            '<br>'
            '/parse<br>'
            '<br>'
            'В новой строке просто чтоб удобно было копировать <br>')


@app.route('/parse', methods=['POST'])
def parse_data():
    # parse()
    #
    # db_init()
    # Session = read_erase_json('parse_data.json')
    # insert_data(Session)
    # with open('parse_data.json', 'w') as file:
    #     pass

    db_init()
    data = request.get_json()
    insert_data(data)
    write(data)

    return "Данные сохранены в бд и записаны на устройстве"


@app.route('/click', methods=['POST'])
def handle_click():
    data = request.get_json()
    x = data.get('x')
    y = data.get('y')
    screen_width = data.get('screenWidth')
    screen_height = data.get('screenHeight')

    try:
        with open('clicks.json', 'r') as file:
            existing_data = file.read()
            if existing_data:
                click_list = eval(existing_data)
            else:
                click_list = []
    except FileNotFoundError:
        click_list = []

    # Добавляем новые координаты в список
    click_list.append({"x": x, "y": y, "screenWidth": screen_width, "screenHeight": screen_height})

    # Записываем список с новыми координатами в файл
    with open('clicks.json', 'w') as file:
        file.write(json.dumps(click_list))

    return "Записано "


@app.route('/stat')
def stat():
    statistics = get_statistics()
    return render_template('stat.html', plot_counties_html=statistics.get_plot_counties_html(),
                           plot_cities_html=statistics.get_plot_cities_html(),
                           plot_heatmap_html=statistics.get_plot_heatmap_html(),
                           plot_daily_visits_html=statistics.get_plot_daily_visits_html(),
                           plot_map_html = statistics.get_plot_map_html())


# db_init()
# Session = read_erase_json('parse_data.json')
# insert_data(Session)

#
# users_data = get_users()
# print(users_data)
# timestamps_data = get_timestamps()

if __name__ == '__main__':

    app.run()
