from datetime import datetime, timedelta
import random

from DB import get_users, get_timestamps
import plotly.express as px
import pandas as pd
import plotly.graph_objects as go
import json

from statistics.location import Location
from statistics.statistics import Statistics
from geopy.geocoders import Nominatim
from requests.exceptions import ConnectTimeout
from geopy.exc import GeocoderUnavailable

STANDARD_WIDTH = 90
STANDARD_HEIGHT = 50


def read_json(filename):
   f = open(filename)
   data = json.load(f)
   return data


def get_daily_visits():
    timestamps = get_timestamps()
    # start_date = datetime(2023, 1, 1)
    # for _ in range(100):
    #     timestamps.append({
    #         'id': random.randint(1, 100),
    #         'username': f"user_{random.randint(1, 10)}",
    #         'timestamp': start_date + timedelta(days=random.randint(1, 365)),
    #     })

    df = pd.DataFrame(timestamps)

    df['timestamp'] = pd.to_datetime(df['timestamp'])

    daily_visits = df.groupby(df['timestamp'].dt.date).size().reset_index(name='count')

    return daily_visits

def get_locations(users=get_users()):
    geolocator = Nominatim(user_agent="GeoLoc")

    locations = []

    for user in users:
        latitude = user['latitude']
        longitude = user['longitude']

        full_location = geolocator.reverse(f"{latitude}, {longitude}")

        country = full_location.raw['address']['country']
        city = full_location.raw['address'].get('city', 'Неопознаный город')

        loc = Location(latitude, longitude, country, city)
        locations.append(loc.__dict__)

    return locations


def get_clicks():
    clicks = read_json("./clicks.json")

    screen_matrix = [[0] * STANDARD_WIDTH for _ in range(STANDARD_HEIGHT)]

    for click in clicks:
        width_coefficient =  STANDARD_WIDTH / click["screenWidth"]
        height_coefficient = STANDARD_HEIGHT / click["screenHeight"]

        x, y = int(click["x"] * width_coefficient), STANDARD_HEIGHT - int(click["y"] * height_coefficient)

        screen_matrix[y][x] += 1

    return screen_matrix

def get_statistics():
    users = get_users()

    daily_visits = get_daily_visits()
    locations = []
    try:
        locations = get_locations(users)
    except ConnectTimeout:
        locations = []
    except GeocoderUnavailable:
        locations = []

    screen_matrix = get_clicks()
    fig_daily_visits = px.line(daily_visits, x='timestamp', y='count', title='Уникальные посещения за день')

    fig_heatmap = go.Figure(go.Heatmap(z=screen_matrix, zsmooth="best"))


    if locations:
        fig_counties = px.pie(locations, names='country', title='Страны')
        fig_cities = px.pie(locations, names='city', title="Города")
        fig_map = px.scatter_mapbox(locations, lat="latitude", lon="longitude", hover_data=['country', 'city'],
                                    color_discrete_sequence=["fuchsia"], zoom=3, height=500, )

        fig_map.update_layout(mapbox_style="open-street-map")

        fig_map.update_layout(margin={"r": 0, "t": 0, "l": 0, "b": 0})

    else:
        fig_counties = px.pie()
        fig_cities = px.pie()
        fig_map = px.pie()
    stat = Statistics(fig_counties=fig_counties, fig_cities=fig_cities, fig_daily_visits=fig_daily_visits,
                      fig_heatmap=fig_heatmap, fig_map=fig_map)

    return stat
