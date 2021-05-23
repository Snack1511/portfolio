import random, time, pickle, os, sys


dir = os.path.dirname(__file__)

class TypingGame:
    word =['cat', 'dock', 'monkey','mouse','panda','frog','snake','wolf']
    rank={}

    def rankload(self):
        with open(dir+'/rank.pk1','rb') as f:
            TypingGame.rank = pickle.load(f)

    def wordAppend(self):
        quiz = 1
        while quiz:
            quiz = input("추가할 단어 입력(종료 : 0) >>> ")
            if quiz == '0':
                print("입력을 종료합니다.")
                break
            TypingGame.word.append(quiz)
        print(TypingGame.word)

    def wordSavePik(self):
        with open(dir+'/word.pk1', 'wb') as f:
            pickle.dump(TypingGame.word,f)
        print(TypingGame.word)

    def wordLoadPik(self):
         with open(dir+'/word.pk1', 'rb') as f:
            TypingGame.word = pickle.load(f)
         print(TypingGame.word)

    def game(self):
        n=1
        q=random.choice(TypingGame.word)
        input('시작')
        start = time.time()
        while n <= 5:
            print("--{}번--".format(n))
            print(q)
            x = input()
            if q == x:
                print("통과")
                n += 1
                q=random.choice(TypingGame.word)
            else:
                print("오타\n다시도전")
        end = time.time()
        print("걸린시간 : {:.0f}초".format(end-start))
        name = input("이름을 입력하세요 >>> ")
        TypingGame.rank[name] = end-start
        print(TypingGame.rank)

    def ranklinst(self):
        ranklist = sorted(TypingGame.rank.items(),key=(lambda x:x[1]))
        print(ranklist)
        cnt = 1
        for k,v in ranklist:
            print("{}등 {}시간 : {:.0f}".foramt(cnt,k,v))
            cnt+=1
    
    def endgame(self):
        with open(dir+'/word.pk1', 'wb') as f:
            pickle.dump(TypingGame.rank, f)
        print("프로그램 종료")
        sys.exit()

    def menuDisplay(self):
        print('''
        1. 문제추가
        2. 문제저장
        3. 문제읽기
        4. 타자게임
        5. 등수리스트
        6. 종료
        ''')
        menu = input("메뉴를 선택하세요 >>> ")
        return menu
    
    def exe(self, menu):
        if menu == '1':
            self.wordAppend()
        elif menu == '2':
            self.wordSavePik()
        elif menu == '3':
            self.wordLoadPik()
        elif menu == '4':
            self.game()
        elif menu == '5':
            self.rankload()
        elif menu == '6':
            self.endgame()
        else:
            print("메뉴선택이 잘못되었습니다.")

    def __init__(self):
        self.rankload()
        while True:
            self.exe(self.menuDisplay())

TypingGame()