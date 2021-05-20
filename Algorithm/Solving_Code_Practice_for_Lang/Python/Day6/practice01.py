import random
cnt = 0
Goal = random.randint(1, 101)
while True:
    n = input("1-100사이의 숫자를 입력하세요.\n")
    cnt += 1
    if Goal ==int(n):
        print("정답입니다 {}번만에 맞추셨습니다.".format(cnt))
        break
    elif Goal > int(n):
        print("{}번째 시도 : 더 큰수를 입력하세요.".format(cnt))
    else:
        print("{}번째 시도 : 더 작은수를 입력하세요.".format(cnt))