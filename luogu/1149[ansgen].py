#P1149 火柴棒等式
#answer generator
#AC

stick = [6,2,5,5,4,5,6,3,7,6]
ans = [0,0,0,0,0,0,0,0,0,0]
ts = [6]

for i in range(1,2002):
	j = i
	k = 0
	while j > 0 :
		k += stick[j % 10]
		j //= 10
	ts.append(k)

print(ts[:20])

#numbers of stick
for n in range(10,25):
	curr = 0
	for i in range(0,1000):
		for j in range(0,1000):
			k = i + j
			if (ts[i] + ts[j] + ts[k]) == (n - 4) :
				curr += 1
	ans.append(curr)

print(ans)
print(ans[14],ans[18])