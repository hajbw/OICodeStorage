#P1008 三连击

def yes(i):
	bit = [0,0,0,0,0,0,0,0,0,0]
	ans = True
	for j in [i,i*2,i*3]:
		bit[j%10] += 1
		bit[j//10%10] += 1
		bit[j//100] += 1
	for k in bit:
		if k != 1:
			ans = False
	return ans


for i in range(100,333):
	if yes(i):
		print(i,i*2,i*3)