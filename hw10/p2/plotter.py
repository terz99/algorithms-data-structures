import matplotlib.pyplot as plt

x_axis = []
y_axis = []

try:
    file = open("data_dp.txt", "r")
    while True:
        line = file.readline()
        if line == None or line == "" or len(line) == 0:
            file.close()
            break
        x_axis.append(int(line))
        line = file.readline()
        y_axis.append(float(line))

except FileNotFoundError:
    pass

plt.title("Task 2: Dynamic Programming Algorithm")
plt.xlabel("N")
plt.ylabel("Time (seconds)")
plt.plot(x_axis, y_axis)
plt.show()