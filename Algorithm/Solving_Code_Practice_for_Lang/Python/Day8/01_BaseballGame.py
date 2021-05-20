import random
com  = random.sample(range(1, 10), 3)
strike = 0
cnt = 0
print("시작")
while strike != 3:
    strike = 0
    ball = 0
    guess = list(input('3자리 숫자를 입력하세요 : '))
    for i in guess:
        for j in com:
            if int(i) == j:
                if guess.index(i) == com.index(j):
                    strike += 1
                else:
                    ball += 1
    
    cnt += 1
    print("Strike : {} | Ball : {} | Try : {}".format(strike, ball, cnt))

print("정답")