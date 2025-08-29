n = input()
n = int(n)

result = 0

numStr = input()
for str in numStr:
    result += (ord(str) - ord("0"))

print(result)