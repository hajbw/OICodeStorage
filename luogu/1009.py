#P1009 阶乘之和

n = int(input())
a = 1
s = 0

for i in range(1,n+1):
	a *= i
	s += a

print(s)