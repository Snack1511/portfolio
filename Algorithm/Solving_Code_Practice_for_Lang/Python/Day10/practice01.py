def check(password):
    if len(password) == 4:
        return True
    else:
        return False


while True:
    password = input("사용하고자 하는 암호를 입력하세요 : ")
    if password == '':
        print("프로그램 종료!")
    result = check(password)
    if result:
        print("사용 할 수 있는 암호")
    else:
        print("사용할 수 없는 암호")