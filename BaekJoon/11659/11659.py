# 문제 출처 : https://www.acmicpc.net/problem/11659
import sys
input = sys.stdin.readline

sums = [0 for _ in range(100001)]

[n, m] = map(int, input().split())

inputList = list(map(int, input().split()))
sums[0] = inputList[0]

for i in range(n):
    if(i>0):
        sums[i] = sums[i-1] + inputList[i]

for k in range(m):
    [st, ed] = map(int, input().split())
    print(sums[ed-1]-sums[st-2])
