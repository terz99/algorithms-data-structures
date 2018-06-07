def maxActivities(arr):
    arr.sort()
    used = []
    used.append(arr[-1])
    j = len(arr)-1
    for i in range(len(arr)-2, -1, -1):
        sj = arr[j][0]
        fi = arr[i][1]
        if fi <= sj:
            used.append(arr[i])
            j = i
    used.reverse()
    return used


if __name__ == "__main__":
    n = int(input("Enter the number of activities: "))
    arr = []
    for i in range(n):
        line = input().split()
        arr.append((int(line[0]), int(line[1])))
    print(maxActivities(arr))