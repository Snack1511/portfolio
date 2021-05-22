def check(password):
    p1 = int(password[0])
    p2 = int(password[1])
    p3 = int(password[2])
    p4 = int(password[3])
    duplicate = increment = decrement = False
    if p1 == p2 or p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4 or p3 == p4:
        duplicate = True
    if p1 + 1 == p2 and p2+1 == p3 and p3 + 1 == p4:
        increment = True
    if p1-1 == p2 and p2 -1 == p2 and p3 - 1 == p4:
        decrement = True
    if duplicate or increment or decrement:
        return False
    else:
        return True


while True:
    password = input("사용하고자 하는 암호를 입력하세요 : ")
    if password == '':
        print("프로그램 종료!")
    result = check(password)
    if result:
        print("사용 할 수 있는 암호")
    else:
        print("사용할 수 없는 암호")