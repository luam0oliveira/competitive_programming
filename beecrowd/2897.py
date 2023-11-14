# -*- coding: utf-8 -*-

while True:
	num = int(input())
	
	if num == 0:
		break
	
	cont = 0
	
	comnds = [int(i) for i in input().split()]

	historico = []
	for i in range(num):
		cmd = comnds[i]
		
		if cmd in historico:
			pos = historico.index(cmd)
			cont += 1 + pos
		else:
			cont += len(historico) + cmd
		historico.insert(0, cmd)

	print(cont)
