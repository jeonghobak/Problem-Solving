# 문제 출처 : https://www.acmicpc.net/problem/1546

n = int(input())

curList = list(map(int, input().split()))

sn = sum(curList)

maxVal = max(curList)

finalResult = sn * 100.0 / maxVal / n
print(finalResult)
