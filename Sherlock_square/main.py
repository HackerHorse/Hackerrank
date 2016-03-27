import sys
from math import ceil, floor, sqrt

# Enter your code here. Read input from STDIN. Print output to STDOUT
T=int(raw_input())

for i in range(0,T):
	A,B = map(int,sys.stdin.readline().split())
	lower = sqrt(A)//1
	higher = sqrt(B)//1

	if lower != sqrt(A):
		lower = lower + 1

	higher = higher + 1

	print int(higher - lower)
