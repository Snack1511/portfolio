items = {'사과' : 12, '배':9, '귤':20}#딕셔너리 사용   키값 : 출력값

item = input("과일명을 입력하세요 : ")
Count = int(input("과일의 갯수를 입력하세요."))

#if items[item]    # 가지고 온 내용이 있으면 True 아니면 KeyError
if items.get(item): # 가지고 온 내용이 있으면 True 아니면 False
    box = Count // items.get(item) # 몫만 구하는 경우 : //
    remain = Count % items.get(item) # 나머지 출력 : %
    print('{}박스 {}개 입니다'.format(box, remain)) # .format(box, remain) : str에서 제공하는 포맷함수, {} 값이 들어갈 공간
else : 
    print("해당 품목이 없습니다. ")