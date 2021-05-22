import re
member = dict()

def namecheck():
    name_p = re.compile('^[ㄱ-ㅣ가-힣]+$')
    name_c = 0
    while not name_c:
        name = input('이름 >>> ')
        name_c = name_p.match(name)
        print(name_c)
    return name

def idcheck():
    id_p = re.compile('^[a-z][a-z0-9]{4,11}$')
    id_c = 0
    while not id_c:
        id=input('아이디(영어,숫자) >>> ')
        id_c = id_p.match(id)
        print(id_c)
    return id

def telcheck():
    tel_p = re.compile('^[0-9]{2,3}-[0-9]{3,4}-[0-9]{4}$')
    tel_c = 0
    while not tel_c:
        tel=input('전화번호 >>> ')
        tel_c = tel_p.match(tel)
        print(tel_c)
    return tel

def idnumcheck():
    idnum_p = re.compile('^[0-9]{6}-[1-8][0-9]{6}$')#{숫자} -> 숫자만큼 들어감
    idnum_c = 0
    while not idnum_c:
        idnum=input('주민등록번호 >>> ')
        idnum_c = idnum_p.match(idnum)
        print(idnum_c)
    return idnum

def emailcheck():
    email_p = re.compile('^[a-z][a-z0-9_-]+@[a-z]+.[a-z]+$') #+ -> 한번이상
    email_c = 0
    while not email_c:
        email=input('이메일 >>> ')
        email_c = email_p.match(email)
        print(email_c)
    return email

def signup(member):
    name = namecheck()
    id = idcheck()
    tel = telcheck()
    idnum = idnumcheck()
    email = emailcheck()
    member[id] = [name,tel,idnum,email]
    return member

member = signup(member)
print(member)