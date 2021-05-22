import re
member = dict()


def urlcheck():
    url_p = re.compile('^[http]|[https]://[a-z._-]+.[a-z]+$') #+ -> 한번이상
    url_c = 0
    while not url_c:
        url=input('이메일 >>> ')
        url_c = url_p.match(url)
        print(url_c)
    return url



url = urlcheck()
print(url)