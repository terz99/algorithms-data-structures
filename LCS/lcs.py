def lcs(x, xIdx, y, yIdx):
    global dp
    if dp[xIdx][yIdx] == None:
        if xIdx == 0 or yIdx == 0:
            dp[xIdx][yIdx] = 0
        elif x[xIdx-1] == y[yIdx-1]:
            dp[xIdx][yIdx] = 1 + lcs(x, xIdx-1, y, yIdx-1)
        else:
            dp[xIdx][yIdx] = max(lcs(x, xIdx-1, y, yIdx), lcs(x, xIdx, y, yIdx-1))
    return dp[xIdx][yIdx]

x = input()
y = input()
dp = [[None]*(len(x)+2)]*(len(y)+2)
# for i in range(len(x)):
#     for j in range(len(y)):
#         print(dp[i][j], end=" ")
#     print()
longest = lcs(x, len(x), y, len(y))
print(longest)