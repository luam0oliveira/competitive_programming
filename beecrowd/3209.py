# -*- coding: utf-8 -*-

n = int(input())

for cases in range(n):
	aparelhos = 1
	reguas = [int(i) for i in input().split()]
	reguas.pop(0)

	numreguas = len(reguas)
	
	for i in range(numreguas):
		if i != numreguas - 1:
			aparelhos += reguas[i] - 1
		else:
			aparelhos += reguas[i]
	
	if numreguas > 0:
		aparelhos -= 1

	print(aparelhos)
