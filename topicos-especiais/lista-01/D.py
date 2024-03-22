def format(string):
	newString = ""
	string = string.lower()
	for i in string:
		if i.isalpha():
			newString += i
	return newString

def verifyPalindrome(string):
	tam = len(string)
	tam_met = tam // 2
	for i in range(tam_met):
		if string[i] != string[tam-1-i]:
			return False
	return True


while True:
	palavra = input()

	if palavra == "DONE":
		break

	palavra = format(palavra)

	if verifyPalindrome(palavra):
		print("You won't be eaten!")
	else:
		print("Uh oh..")