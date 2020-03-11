from bs4 import BeautifulSoup
import requests

#This code is taken from https://www.pythonforbeginners.com/python-on-the-web/web-scraping-with-beautifulsoup 
# I take no credit in it's creation

url = raw_input("Enter the webiste you wish to take URL's from")

r = requests.get("https://" + url)

data = r.text

soup = BeautifulSoup(data)

for link in soup.find_all('a'):
	print(link.get('href'))
