from bs4 import BeautifulSoup
import requests
import pandas as pd 

#get the data from the website
url = 'https://sandiego.eater.com/maps/new-coffee-shops-san-diego-essential'
data = requests.get(url)
soup = BeautifulSoup(data.text, 'html.parser')
coffee = soup.find("div")
coffee_shop_names = coffee.find_all("h1")

list(soup.children)
