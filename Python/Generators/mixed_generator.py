from generate_dates import generate_dates
from generate_dow import generate_dow


def generate_mixed_date(month, day, year):
    dates_generator = generate_dates(month, day, year)
    dow_generator = generate_dow(month, day, year)

    while True:
        date = next(dates_generator)
        dow = next(dow_generator)

        yield date.day, date.month, date.year, dow


generator = generate_mixed_date(10, 20, 2023)

for _ in range(7):
    print(next(generator))
