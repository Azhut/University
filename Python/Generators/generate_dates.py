import datetime


def generate_dates(month, day, year):
    current_date = datetime.datetime(year, month, day)

    while True:
        yield current_date

        current_date += datetime.timedelta(days=1)


if __name__ == "__main__":
    generator = generate_dates(10, 20, 2023)

    for i in range(31):
        print(next(generator))
