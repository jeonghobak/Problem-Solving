n = int(input())

curList = list(map(int, input().split()))

sn = sum(curList)

maxVal = max(curList)

finalResult = sn * 100.0 / maxVal / n
print(finalResult)
