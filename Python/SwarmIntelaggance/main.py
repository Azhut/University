import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Создание случайных координат роя
num_particles = 50
dim = 2
positions = np.random.rand(num_particles, dim)
velocities = np.random.rand(num_particles, dim)

# Создание графика
fig, ax = plt.subplots()
ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
scatter = ax.scatter(positions[:, 0], positions[:, 1])


# Функция обновления графика
def update_plot(frame):
    global positions, velocities
    # Обновление координат роя
    positions += velocities

    # Ограничение координат в пределах графика
    positions = np.clip(positions, 0, 1)

    # Обновление графика
    scatter.set_offsets(positions)


# Рассчитываем количество кадров и интервал времени для анимации
num_frames = 100
duration = 10  # Длительность анимации в секундах
interval = duration * 1000 / num_frames

# Создание анимации
ani = animation.FuncAnimation(fig, update_plot, frames=num_frames, interval=interval)
plt.show()