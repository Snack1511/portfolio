import random

cnt = 0
oper = ['+', '-', '*', '/']

for x in range(5):
    a = random.randint(1, 50)
    b = random.randint(1, 50)
    op = random.choice(oper) # oper리스트 안의 값중 하나 출력
    quiz = str(a)+op+str(b)
    print(quiz, '=')
    result = int(input('정답 = '))
    if int(eval(quiz)) == result:
        print('정답입니다.')
        cnt += 1
    else:
        print('오답입니다.')

print("{}개 맞춤".format(cnt))
