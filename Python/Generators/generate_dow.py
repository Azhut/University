import datetime


def generate_dow(month, day, year):
    current_date = datetime.datetime(year, month, day)

    Weekdays = ["Понедельник", "Вторник", "Среда", "Чертверг", "Пятница", "Суббота", "Воскресенье"]
    while True:
        yield Weekdays[current_date.weekday()]

        current_date += datetime.timedelta(days=1)


if __name__ == "__main__":
    generator = generate_dow(10, 20, 2023)

    for i in range(31):
        print(next(generator))
