# -*- coding: utf-8 -*-

teste = 1

while True:
	tmp, intervalo = [int(i) for i in input().split()]
	
	if tmp == intervalo == 0:
		break

	temps = []
	tempsmedia = []
	
	soma = 0
	for i in range(tmp):
		temps.append(int(input()))
		soma += temps[i]
		if i + 1 >= intervalo:
			medialocal = int(soma / intervalo)
			tempsmedia.append(medialocal)
			soma -= temps[i - intervalo + 1]


	print("Teste %d" % teste)
	print("%d %d" % (min(tempsmedia), max(tempsmedia)))
	print()
	teste += 1
