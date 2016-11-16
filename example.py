from lxml import etree
import urllib
import sys

link = "https://en.wikipedia.org/wiki/List_of_Nobel_laureates_by_country"
page_str = urllib.urlopen(link).read()
root = etree.XML(page_str)

# print etree.tostring(root, pretty_print=True)

country_filter = "//div[@id='mw-content-text']/h2/span[@class='mw-headline']"
countries = root.xpath(country_filter)

# print countries

sys.stdout = open("data.csv", "w")

print "name, country, field, year"

for country in countries:
    country_name = country.text
    person_filter = "./parent::h2/following-sibling::ol[1]//li/a"
    persons = country.xpath(person_filter)
    for person in persons:
        other_info = person.xpath('./following-sibling::text()')
        outstr = "".join(other_info)
        output = (person.text + ", " + country.text + ", " + outstr).encode('utf-8').strip()
        print output 
