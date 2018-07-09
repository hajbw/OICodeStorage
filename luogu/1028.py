#P1028 数的计算
#AC

ans = [1,1,2,2]

n = int(input())

for i in range(4,n+1,2):
	ans[i:i+1] = [ans[i-1]+ans[i>>1]]*2

print(ans[n])