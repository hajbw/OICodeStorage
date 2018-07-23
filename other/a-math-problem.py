#put n letters into n envelopes
#how many posibilities to put ALL disordered?
#or:place 1...n in a[1...n],let EVERY a[i] != i

#example:for p(3)
#1 2 3 :ordered
#1 3 2 :not all disoedered
#2 3 1 :all disordered

def p(n):
	if n < 2:
		return 0
	return (n - 1) * p1(n - 1)

def p1(n):
	if n < 1:
		return 0
	if n < 3:
		return 1
	return p(n - 1) + p1(n - 1)

for n in range(1,10):
	print(p(n))