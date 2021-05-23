import random, time, pickle, os, sys
dir = os.path.dirname(__file__)

word =['cat', 'dock', 'monkey','mouse','panda','frog','snake','wolf']
rank={}
while True:
    prompt = "1. 문제추가  2. 문제저장  3. 문제읽기  4. 타자게임  5. 등수리스트  6. 종료\n>>> "
    
    menu = input(prompt)

    if menu == '1':
        quiz = 1
        while quiz:
            quiz = input("추가할 단어 입력(종료 : 0) >>> ")
            if quiz == '0':
                print("입력을 종료합니다.")
                break
            word.append(quiz)
        print(word)
    elif menu == '2':
        with open(dir+'/word.pk1', 'wb') as f:
            pickle.dump(word,f)
        print(word)
    elif menu == '3':
        with open(dir+'/word.pk1', 'rb') as f:
            word = pickle.load(f)
        print(word)
    elif menu == '4':
        n=1
        q=random.choice(word)
        input('시작')
        start = time.time()
        while n <= 5:
            print("--{}번--".format(n))
            print(q)
            x = input()
            if q == x:
                print("통과")
                n += 1
                q=random.choice(word)
            else:
                print("오타\n다시도전")
        end = time.time()
        print("걸린시간 : {:.0f}초".format(end-start))
        name = input("이름을 입력하세요 >>> ")
        rank[name] = end-start
        print(rank)
    elif menu == '5':
        ranklist = sorted(rank.items(),key=(lambda x:x[1]))
        print(ranklist)
        cnt = 1
        for k,v in ranklist:
            print("{}등 {}시간 : {:.0f}".foramt(cnt,k,v))
            cnt+=1
    elif menu == '6':
        with open(dir+'/word.pk1', 'wb') as f:
            pickle.dump(rank, f)
        print("프로그램 종료")
        break
    else:
        print("메뉴선택이 잘못되었습니다.")
    