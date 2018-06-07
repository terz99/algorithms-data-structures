m = 5
vis = [False]*m

def h1(key, f):
    f.write("Calling hash function 1 on k=" + str(key) + "\n\t")
    return key%5

def h2(key, f):
    f.write("Calling hash function 2 on k=" + str(key) + "\n\t")
    return (7*key)%8


def hashit(key, f):
    f.write("Hashing k=" + str(key) + "\n\t")
    idx1 = h1(key, f)
    f.write("From hash function 1 we have idx1=" + str(idx1) + "\n\t")
    idx2 = h2(key, f)
    f.write("From hash function 2 we have idx2=" + str(idx2) + "\n\t")
    idx = idx1
    f.write("Current index idx=" + str(idx) + "\n\t")
    while vis[idx]:
        f.write("Collision at idx=" + str(idx))
        idx = (idx + idx2)%m
        f.write("Resolving: increasing idx by idx2 ==> idx=(idx+idx2)%m ==> idx=" + str(idx) + "\n\t")
    f.write("Position idx=" + str(idx) + " is available. Continuing.\n\n")
    vis[idx] = True
    return idx

if __name__ == "__main__":
    arr = [3, 10, 2, 4]
    f = open("solution_1a.txt", "w")
    for i in range(len(arr)):
        arr[i] = hashit(arr[i], f)
    f.write("Done.\n")
    f.write("Final sequence: arr=" + str(arr) + "\n")
    f.close()