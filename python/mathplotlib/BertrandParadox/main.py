import numpy as np
from matplotlib import pyplot as plt
import functions

CHORDS = 1000
POINTS = 3000
circle = np.array(functions.get_circle(1))

# метод "случайных концов"
plt.figure(figsize=(20, 20))
plt.subplot(4, 3, 1)
plt.plot(circle[0], circle[1], color="slategrey")
plt.title("random endpoints", color="black")
for i in range(CHORDS):
    points = functions.method1()
    x = np.linspace(points[0], points[2], 100)
    y = np.linspace(points[1], points[3], 100)
    plt.plot(x, y, linewidth=0.2, color="slategrey")

plt.subplot(4, 3, 4)
plt.plot(circle[0], circle[1], color="slategrey")
for i in range(POINTS):
    x, y = functions.get_center(1)
    plt.scatter(x, y, s=0.2, color="slategrey")

# метод "случайного радиуса"
plt.subplot(4, 3, 2)
plt.plot(circle[0], circle[1], color="slategrey")
plt.title("random radial point", color="black")
for i in range(CHORDS):
    points = functions.method2()
    x = np.linspace(points[0], points[2], 100)
    y = np.linspace(points[1], points[3], 100)
    plt.plot(x, y, linewidth=0.2, color="slategrey")

plt.subplot(4, 3, 5)
plt.plot(circle[0], circle[1], color="slategrey")
for i in range(POINTS):
    x, y = functions.get_center(2)
    plt.scatter(x, y, s=0.2, color="slategrey")

# метод "случайного центра"
plt.subplot(4, 3, 3)
plt.plot(circle[0], circle[1], color="slategrey")
plt.title("random midpoint", color="black")
for i in range(CHORDS):
    points = functions.method3()
    x = np.linspace(points[0], points[2], 100)
    y = np.linspace(points[1], points[3], 100)
    plt.plot(x, y, linewidth=0.2, color="slategrey")

plt.subplot(4, 3, 6)
plt.plot(circle[0], circle[1], color="slategrey")
for i in range(POINTS):
    x, y = functions.get_center(3)
    plt.scatter(x, y, s=0.2, color="slategrey")

# метод двух точек внутри круга"
plt.subplot(4, 3, 7)
plt.plot(circle[0], circle[1], color="slategrey")
plt.title("random points inside the circle", color="black")
for i in range(CHORDS):
    points = functions.method4()
    x = np.linspace(points[0], points[2], 100)
    y = np.linspace(points[1], points[3], 100)
    plt.plot(x, y, linewidth=0.2, color="slategrey")

plt.subplot(4, 3, 10)
plt.plot(circle[0], circle[1], color="slategrey")
for i in range(POINTS):
    x, y = functions.get_center(4)
    plt.scatter(x, y, s=0.2, color="slategrey")


# метод точки на окружности и внутри кргуа
plt.subplot(4, 3, 8)
plt.plot(circle[0], circle[1], color="slategrey")
plt.title("random points on the circle\nand inside the circle", color="black")
for i in range(CHORDS):
    points = functions.method5()
    x = np.linspace(points[0], points[2], 100)
    y = np.linspace(points[1], points[3], 100)
    plt.plot(x, y, linewidth=0.2, color="slategrey")

plt.subplot(4, 3, 11)
plt.plot(circle[0], circle[1], color="slategrey")
for i in range(POINTS):
    x, y = functions.get_center(5)
    plt.scatter(x, y, s=0.2, color="slategrey")

# метод различной веротности
plt.subplot(4, 3, 9)
plt.plot(circle[0], circle[1], color="slategrey")
plt.title("random probability", color="black")
for i in range(CHORDS):
    points = functions.method6()
    x = np.linspace(points[0], points[2], 100)
    y = np.linspace(points[1], points[3], 100)
    plt.plot(x, y, linewidth=0.2, color="slategrey")

plt.subplot(4, 3, 12)
plt.plot(circle[0], circle[1], color="slategrey")
for i in range(POINTS):
    x, y = functions.get_center(6)
    plt.scatter(x, y, s=0.2, color="slategrey")
plt.show()
