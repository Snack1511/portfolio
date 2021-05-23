import Day16.functionM as fm

word =['cat', 'dock', 'monkey','mouse','panda','frog','snake','wolf']
rank={}

rank = fm.rankload()
print(rank)

while True:
    prompt = "1. 문제추가  2. 문제저장  3. 문제읽기  4. 타자게임  5. 등수리스트  6. 종료\n>>> "
    
    menu = input(prompt)
    if menu == '1':
        word = fm.wordAppend(word)
    elif menu == '2':
        fm.wordSavePik(word)
    elif menu == '3':
        fm.wordLoadPik()
    elif menu == '4':
        fm.game(word, rank)
    elif menu == '5':
        fm.rankload(rank)
    elif menu == '6':
        fm.endgame(rank)
    else:
        print("메뉴선택이 잘못되었습니다.")
