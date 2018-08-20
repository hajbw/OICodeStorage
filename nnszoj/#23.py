n = int(input())
ans = [0,1]

for i in range(2,n):
	res = i
	for j in range(1,i):
		res = max(res,ans[j] * ans[i - j])
	ans.append(res)

print(ans[-1])