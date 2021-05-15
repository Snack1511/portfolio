from datetime import datetime

name = input("이름은 : ")
birth = input("생년월일(예:yyyymmdd)")

b_year = int(birth)//10000
b_month = int(birth)%10000 // 100
b_day = int(birth)%100

c_year = datetime.today().year
c_month = datetime.today().month
c_day = datetime.today().day


today = c_year * 10000 + c_month * 100 + c_day
birth = b_year*10000 + b_month * 100 + b_day

age = (today - birth)//10000
print('{}님의 만나이는 {}입니다.'.format(name, age))