#P1008 三连击

def yes(i):
	print(i)
	bit = [0,0,0,0,0,0,0,0,0,0]
	for j in [i,i*2,i*3]:
		bit[j%10] += 1
		bit[j//10%10] += 1
		bit[j//100] += 1
	return bit == [1,1,1,1,1,1,1,1,1,1]


for i in range(100,333):
	if yes(i):
		print(i,i*2,i*3)