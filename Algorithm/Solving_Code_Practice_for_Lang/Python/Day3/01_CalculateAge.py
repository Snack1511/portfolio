from datetime import datetime

# print(datetime.now().year)

current_year = datetime.today().year
print('현재연도는 {}년 입니다.'.format(current_year))
name = input('당신의 이름은?')
birth = int(input('당신이 태어난 해는?'))

age = current_year - birth
print(name + '님의 나이는 '+ str(age) +'세 입니다.')
