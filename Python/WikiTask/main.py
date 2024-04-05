import httpx
from lxml import html

def get_wikipedia_links(url):
    response = httpx.get(url)
    tree = html.fromstring(response.text)
    links = tree.xpath('//a[contains(@href, "wikipedia.org")]/@href')
    return links


url = "https://en.wikipedia.org/wiki/Virtual_private_network"
links = get_wikipedia_links(url)
print(links)
