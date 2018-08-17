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
	return (n - 1) * ( p(n - 1) + p(n - 2) )

for n in range(1,10):
	print(p(n))