def calculateC(f):
	return 5*(f-32)/9

cases = int(input())
cont = 1

while cases:
	c,f = map(int, input().split())

	print("Case %d: %.2f"%(cont, calculateC(f + 9/5 * (c) + 32)))
	cases -= 1
	cont += 1