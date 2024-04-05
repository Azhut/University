class Statistics:
    def __init__(self, fig_heatmap, fig_daily_visits, fig_counties, fig_cities, fig_map):
        self.fig_counties = fig_counties
        self.fig_cities = fig_cities
        self.fig_heatmap = fig_heatmap
        self.fig_daily_visits = fig_daily_visits
        self.fig_map = fig_map

    def get_plot_counties_html(self):
        return self.fig_counties.to_html(full_html=False)

    def get_plot_cities_html(self):
        return self.fig_cities.to_html(full_html=False)

    def get_plot_heatmap_html(self):
        return self.fig_heatmap.to_html(full_html=False)

    def get_plot_daily_visits_html(self):
        return self.fig_daily_visits.to_html(full_html=False)

    def get_plot_map_html(self):
        return self.fig_map.to_html(full_html=False)
