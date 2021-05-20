import random

words = ['가위', '바위', '보']
cnt = 0
while True:
    computer = random.choice(words)
    Player = input("가위바위보를 하세요 :")
    print("computer : ", computer)
    if Player == '':
        print("프로그램을 종료합니다.")
        break
    elif words.index(Player) - words.index(computer) == 0 :
        print("무승부")
    elif words.index(Player) - words.index(computer) == 1 or words.index(Player) - words.index(computer) == -2 :
        print("승리")
    else:
        print("패배")