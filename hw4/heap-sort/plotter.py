import matplotlib.pyplot as plt

x_axis = []
y_axis = []

try:
    file = open("heapsort.txt", "r")
    while True:
        line = file.readline()
        if line == None or line == "" or len(line) == 0:
            file.close()
            break
        x_axis.append(int(line))
        line = file.readline()
        y_axis.append(float(line))

        for i in range(4):
            file.readline()

except FileNotFoundError:
    pass

plt.title("Heap Sort Running Time")
plt.xlabel("N times 1e7")
plt.ylabel("Time (seconds)")
plt.plot(x_axis, y_axis)
x_axis = []
y_axis = []

try:
    file = open("bottom_up_heapsort.txt", "r")
    while True:
        line = file.readline()
        if line == None or line == "" or len(line) == 0:
            file.close()
            break
        x_axis.append(int(line))
        line = file.readline()
        y_axis.append(float(line))

        for i in range(4):
            file.readline()

except FileNotFoundError:
    pass

plt.plot(x_axis, y_axis)
plt.show()