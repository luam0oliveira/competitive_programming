degreeForOneMinuteHour = 0.5
degreeForOneMinuteMinute = 6

while True:
	hour, minute = map(int, input().split(":"))
	hour= (hour * 60 + minute) * degreeForOneMinuteHour
	minute = minute * degreeForOneMinuteMinute
	if hour == 0 == minute:
		break
	degree = max(hour,minute) - min(hour, minute)

	if degree > 180:
		degree -= 360

	if degree < 0:
		degree *= -1

	print("%.3f" %(degree))