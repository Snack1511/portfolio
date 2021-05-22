import os
dir = os.path.dirname(__file__)
def Address_input():
    name = input("이름 : >>> ")
    tel = input("전화번호 >>> ")
    address = input("주소 >>> ")
    f = open(dir+'/adress.txt', 'a', encoding='utf-8')
    f.write(name+', '+tel+', '+ address+'\n')
    f.close()

def Address_output():
    f = open(dir+'/adress.txt', 'r', encoding='utf-8')
    for line in f.readlines():
        line = line.replace('\n', '')
        data = line.split(', ')
        print("이름 : {}, 전화번호 : {}, 주소 : {}".format(data[0], data[1], data[2]))
    f.close()
Address_input()
Address_output()