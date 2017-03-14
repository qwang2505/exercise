import urllib2
import time
import random
import pymongo
import urlparse
from lxml.html import fromstring

_START_URL = 'http://maoyan.com/films?sortId=2&yearId=11'
_NEXT_URL = None

_con = pymongo.Connection('10.12.6.6')
_db = _con['films']

def crawl(url):
    print 'crawl: %s' % url
    r = urllib2.urlopen(url).read()
    dom = fromstring(unicode(r, 'utf-8'))
    dom.make_links_absolute(url)
    divs = dom.xpath('.//dl[@class="movie-list"]//div[contains(@class, "movie-item-title")]')
    films = []
    for div in divs:
        title = div.xpath('a')
        if title:
            title = title[0].text
        href = div.xpath('a/@href')
        if href:
            href = href[0]
        if href and title:
            films.append({'title': title, 'link': href})
    for film in films:
        _db.films.update({'title': film['title']}, {'$set': film}, upsert=True)
    return len(films)

def construct_next_url(count):
    global _NEXT_URL
    u = urlparse.urlparse(_NEXT_URL)
    query = urlparse.parse_qs(u.query)
    if 'offset' not in query:
        query['offset'] = [count]
    else:
        query['offset'][0] = int(query['offset'][0]) + count
    q = ''
    for k, v in query.items():
        if len(q) != 0:
            q += '&'
        q += '%s=%s' % (k, v[0])
    _NEXT_URL = urlparse.urlunparse((u.scheme, u.netloc, u.path, u.params, q, u.fragment))

def run():
    global _NEXT_URL
    if not _NEXT_URL:
        _NEXT_URL = _START_URL
    # crawl
    count = crawl(_NEXT_URL)
    # construct next url
    construct_next_url(count)
    return count > 0

def main():
    while True:
        r = run()
        if not r:
            break
        time.sleep(random.randint(1, 40))

if __name__ == '__main__':
    main()
