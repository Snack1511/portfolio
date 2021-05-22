import os, pickle
dir =os.path.dirname(__file__)

def Book_load():
    if os.path.exists(dir+'/Book_list.pickle'):
        f = open(dir+'/Book_list.pickle', 'rb')
        Book_list = pickle.load(f)
        f.close()
        
    else:
        print("현재 저장된 정보가 없습니다.")
        Book_list = []
    return Book_list


def Book_save(Book_list):
    f = open(dir+'/Book_list.pickle', 'wb')
    pickle.dump(Book_list,f)
    f.close()

def Book_input(Book_list):
    name = input("도서명 >>> ")
    author = input("저자 >>> ")
    publisher = input("출판사명 >>> ")
    data = [name,author,publisher]
    Book_list.append(data)
    return Book_list

    
def Book_print(Book_list):
    for data in Book_list:
        print("도서명 : {}, 저자 : {}, 출판사명 : {}".format(data[0], data[1], data[2]))
    

Book_list = []
Book_list = Book_load()

while True:
    menu_txt = '1. 입력   2. 출력   3. 종료   \n>>> '
    menu = input(menu_txt)
    if menu == '1':
        Book_list = Book_input(Book_list)
        Book_save(Book_list)
    elif menu == '2':
        Book_print(Book_list)
    elif menu == '3':
        print("프로그램 종료!\n")
        break
    else:
        print("메뉴선택을 잘못 하셨습니다.")