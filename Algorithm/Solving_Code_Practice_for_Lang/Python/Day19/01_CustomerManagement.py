import re
custlist = [{'name':'홍길동','gender':'M','email':'hong12@gmail.com','birthyear':'2000'},
            {'name':'박철수','gender':'F','email':'park12@gmail.com','birthyear':'2001'},
            {'name':'김나리','gender':'M','email':'kim12@gmail.com','birthyear':'1998'}]
page = 2
while True:
    choice = input('''
    다음 중에서 하실 작업을 골라주세요 : 
    I - 고객정보입력
    C - 현재 고객 정보 조회
    P - 이전 고객 정보 조회
    N - 다음 고객 정보 조회
    U - 고객 정보 수정
    D - 고객 정보 삭제
    Q - 프로그램 종료
    ''').upper()

    if choice == "I":
        customer = {'name':'', 'gender':'','email':'','birthyear':''}
        customer['name'] = input("이름을 입력하세요 >>> ")
        while True :
            customer['gender'] = input('성별(M/F)을 입력하세요 >>> ')
            customer['gender'] = customer['gender'].upper()
            if customer['gender'] in ('M', 'F'):
                break
        while True:
            regex = re.compile('^[a-z][a-z0-9_-]{4,10}@[a-z]{2,6}[.][a-z]{2,3}$')
            while True:
                customer['email'] = input("이메일을 입력하세요 >>> ")
                email_c = regex.search(customer['email'])
                if email_c:
                    break
                else:
                    print('@를 포함한 정확한 이메일을 입력하세요')
            check = 0
            for i in custlist:
                if i['email'] == customer['email']:
                    check = 1
            if check == 0:
                break
            print('중복되는 이메일이 있습니다.')
        while True:
            customer['birthyear'] = input('출생년도 4자리를 입력하세요 >>> ')
            if len(customer['birthyear']) == 4 and customer['birthyear'].isdigit():
                break
        custlist.append(customer)
        page = len(customer)-1
        print(customer)
        print(custlist)
        print(page)

    elif choice == "C":
        if page >= 0:
            print("현재페이지는 {}쪽 입니다.".format(page+1))
            print(custlist[page])
        else:
            print("입력된 정보가 없습니다.")

    elif choice == "P":
        if page <= 0:
            print("첫 번째 페이지입니다. 이전 페이지로 이동이 불가능합니다.")
            print(page)
        else:
            page -= 1
            print("현재 페이는 {}쪽 입니다.".format(page+1))
            print(custlist[page])
            
    elif choice == "N":
        if page >= len(custlist)-1:
            print("마지막 페이지입니다. 다음페이지로 이동이 불가능합니다.")
            print(page)
        else:
            page += 1
            print("현재 페이는 {}쪽 입니다.".format(page+1))
            print(custlist[page])

    elif choice == "U":
        while True:
            choice1 = input('수정하려는 고객 정보의 이메일 주소를 입력하세요 : ')
            idx = -1
            for i in range(0, len(custlist)):
                if custlist[i]['email'] == choice1:
                    idx = i
                    break
            if idx == -1:
                print("등록되지 않은 이메일입니다.")
                break
            choice2 = input("수정하실 정보를 선택하세요.(name,gender,birthyear) 종료:exit")
            if choice2 in ('name','gender','birthyear'):
                custlist[idx][choice2] = input("수정할 {}를 입력하세요 >> ".format(choice2))
                break
            elif choice2 == 'exit':
                break
            else:
                print('존재하지 않는 정보입니다.')
                break
    elif choice == "D":
        choice == input("삭제하려는 고객정보의 이메일을 입력하세요")
        delok = 0
        for i in range(0,len(custlist)):
            if custlist[i]['email'] == choice:
                print('{} 고객님의 정보가 삭제되었습니다.'.format(custlist[i]['name']))
                del custlist[i]
                delok = 1
                break
        if delok == 0:
            print('등록되지 않은 고객 정보입니다.')
        print(custlist)
    elif choice == "Q":
        break
    else:
        print("메뉴 선택을 잘못하셨습니다.")
    
