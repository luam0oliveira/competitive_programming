# -*- coding: utf-8 -*-

while True:
	d = int(input())

	if d == 0:
		break

	digits = 0

	higher = 2 ** (d * 2 - 2)
	resto = 2

	while resto >= 1:
		resto = higher // (10 ** digits)
		digits += 1

	digits -= 1

	for i in range(d):
		for j in range(d):
			resto = 2
			actual = 0
			valor = 2 ** (i + j)

			while resto >= 1:
				resto = valor // (10 ** actual)
				actual += 1

			actual -= 1
			for k in range(digits - actual):
				print(" ", end="")

			if j != d - 1:
				print("%d " % (valor), end="")
			else:
				print("%d" % (valor), end="")
				
		print()
	print()
