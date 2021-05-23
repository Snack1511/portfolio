import random, time, pickle, os, sys
dir = os.path.dirname(__file__)

def rankload():
        with open(dir+'/rank.pk1','rb') as f:
            return pickle.load(f)

def wordAppend(word):
        quiz = 1
        while quiz:
            quiz = input("추가할 단어 입력(종료 : 0) >>> ")
            if quiz == '0':
                print("입력을 종료합니다.")
                break
            word.append(quiz)
        print(word)
        return word

def wordSavePik(word):
    with open(dir+'/word.pk1', 'wb') as f:
        pickle.dump(word,f)
    

def wordLoadPik():
     with open(dir+'/word.pk1', 'rb') as f:
        word = pickle.load(f)
     return word

def game(word, rank):
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
    return rank

def ranklinst(rank):
    ranklist = sorted(rank.items(),key=(lambda x:x[1]))
    print(ranklist)
    cnt = 1
    for k,v in ranklist:
        print("{}등 {}시간 : {:.0f}".foramt(cnt,k,v))
        cnt+=1

def endgame(rank):
    with open(dir+'/word.pk1', 'wb') as f:
        pickle.dump(rank, f)
