while True:
    a = input("숫자를 입력하세요 : ")
    if a == '':
        print("프로그램 종료")
        break
    a = int(a)
    b = 0
    for i in range(2, a):
        if a % i == 0:
            b = 1
    if b == 0:
        print("소수")
    else :
        print("소수아님")