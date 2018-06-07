def maxActivities(arr):
    used = []
    used.append(arr[0])
    j = 0
    for i in range(1, len(arr)):
        si = arr[i][0]
        fj = arr[j][1]
        if si >= fj:
            used.append(arr[i])
            j = i
    return len(used)

if __name__ == "__main__":
    f = open("input.in", "r")
    arr = []
    for line in f:
        items = line.split()
        arr.append((int(items[0]), int(items[1])))
    f.close()
    arr = sorted(arr, key=lambda x: x[1])
    print(maxActivities(arr))