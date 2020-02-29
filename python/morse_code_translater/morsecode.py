#import pandas as pd

d = {
	'a' : '.-',
	'b' : '-...',
	'c' : '-.-.',
	'd'	: '-..',
	'e' : '.',
	'f' : '..-.',
	'g' : '--.',
	'h' : '..',
	'i' : '..',
	'j' : '.---',
	'k' : '-.-',
	'l' : '.-..',
	'm' : '--',
	'n' : '-.',
	'o' : '---',
	'p' : ' .--.',
	'q' : '--.-',
	'r' : '.-.',
	's' : '...',
	't' : '-',
	'u' : '..-',
	'v' : '...-',
	'w' : '.--',
	'x' : '-..-',
	'y' : '-.--',
	'z' : '--..',
}

#file_object = open("wordlist.txt", "r")
#def smorase() 
dash = 0
dot = 0


file_contents = open('wordlist.txt')
	
for line in file_contents:
	for letter in line:
		convertedLetter = d.get(letter)

		dash += str(convertedLetter).count("-")
		dot += str(convertedLetter).count(".")

print('the amount of dashes are {}'.format(dash))
print('the amount of dots are {}'.format(dot))







