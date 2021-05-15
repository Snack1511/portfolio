People = input("주민번호 입력 : ")
#print(type(People))
if People[7] == '1' or People[7] == '3':
    print("남자")
elif People[7] == '2' or People[7] == '4':
    print("여자")
else:
    print("입력이 잘못되었습니다.")