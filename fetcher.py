import urllib
from lxml import html
from lxml import etree

link = 'https://en.wikipedia.org/wiki/List_of_Nobel_laureates_by_country'
page = html.fromstring(urllib.urlopen(link).read())
#tree = page.xpath('/')

country_filter = "//div[@id='mw-content-text']/h2/span[@class='mw-headline']"

for i in page.iterfind(country_filter):
    print i.text()
    

