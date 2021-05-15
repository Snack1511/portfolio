from datetime import datetime
idnum = input("주민번호 입력 : ")
if int(idnum[8:9]) == 1 or int(idnum[8:9]) == 2:
     birth = 19000000 + int(idnum[:6])
else :
     birth = 20000000 + int(idnum[:6])

print(idnum[8:9])

c_year = datetime.today().year
c_month = datetime.today().month
c_day = datetime.today().day


today = c_year * 10000 + c_month * 100 + c_day

age = (today - birth)//10000
print(age)