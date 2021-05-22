import os, pickle
dir =os.path.dirname(__file__)

def address_load():
    f = open(dir+'/Address_list.pickle', 'rb')
    Address_list = pickle.load(f)
    f.close()
    return Address_list

def address_save(Address_list):
    f = open(dir+'/Address_list.pickle', 'wb')
    pickle.dump(Address_list,f)
    f.close()

def address_input(Address_list):
    name = input("이름 : >>> ")
    tel = input("전화번호 >>> ")
    address = input("주소 >>> ")
    data = [name,tel,address]
    Address_list.append(data)
    return Address_list

    
def address_print(Address_list):
    for data in Address_list:
        print("이름 : {}, 전화번호 : {}, 주소 : {}".format(data[0], data[1], data[2]))
    

Address_list = []
Address_list = address_load()

while True:
    menu_txt = '1. 입력   2. 출력   3. 종료   \n>>> '
    menu = input(menu_txt)
    if menu == '1':
        Address_list = address_input(Address_list)
        address_save(Address_list)
    elif menu == '2':
        address_print(Address_list)
    elif menu == '3':
        print("프로그램 종료!\n")
        break
    else:
        print("메뉴선택을 잘못 하셨습니다.")