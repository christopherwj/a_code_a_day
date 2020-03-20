from bs4 import BeautifulSoup
import requests
import pandas as pd

#get the data from the website
url = 'https://sandiego.eater.com/maps/new-coffee-shops-san-diego-essential'
data = requests.get(url)
soup = BeautifulSoup(data.text, 'html.parser')
coffee = soup.find("div")
coffee_shop_names = coffee.find_all("h1")
#print(bar_names)

#clean up the output
coffee_shop_list = []

for b in coffee_shop_names[1:]:
	result = b.text.strip()
	coffee_shop_list.append(result)

#print(len(coffee_shop_names))
#print(coffee_shop_names)
#print(coffee_shop_list)

#get rid of u' that is before each number'
#bar_list = [e[2:] for e in bar_list]
#turns out that is beautiful soup telling me the string is unicode 
#added '.encode('ascii)' to above loop to fix this

#removed unwanted last term
#bar_list = bar_list[:-1]


#print list of coffee shops
for item in coffee_shop_list:
	print(item)
