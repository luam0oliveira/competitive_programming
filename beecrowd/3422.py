# -*- coding: utf-8 -*-

n = int(input())

for i in range(n):
	minn, tmp = input().split()
	minn = int(minn)

	if tmp == "1T":
		if minn > 45:
			print("%d+%d" %(minn - minn % 45, minn % 45))
		else:
			print("%d" %(minn))
	else:
		if minn > 45:
			print("%d+%d" %((minn - minn % 45 )+ 45, minn % 45))
		else:
			print("%d" %(minn + 45))
