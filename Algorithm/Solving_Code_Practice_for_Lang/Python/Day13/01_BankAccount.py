class Account:
    account_count = 0

    @classmethod
    def get_account_num(cls):
        print("계좌수 : ", cls.account_count)

    def __init__(self,name,balance):
        Account.account_count +=1
        self.deposit_Count = 0
        self.total_log = []
        self.name = name
        self.balance = balance
        self.get_account_number = str(Account.account_count)

    def deposit(self, amount):
        if amount >= 1:
            self.total_log.append(('입금', amount))
            self.balance += amount
            self.deposit_Count += 1
            if self.deposit_Count %5 == 0:
                interest = int(self.balance * 0.01)
                self.balance += interest
                self.total_log.append(('이자지급', interest))
                print(interest, "원의 이자가 지급되었습니다.")

    def withdraw(self, amount):
        if self.balance > amount:
            self.total_log.append(('출금', amount))
            self.balance += amount
        else:
            print("잔액이 부족합니다.")

    def display_info(self):
        print("예금주 : ", self.name)
        print("계좌번호 : ", self.get_account_number)
        print("잔고 : ", self.balance)
    def __str__(self):
        return "예금주 : "+self.name+", 계좌번호 : "+self.get_account_number+", 잔고 : "+str(self.balance)

a = Account('hong', 200000)
b = Account('kim', 500000)
a.display_info()
print(b)

a.deposit(2000)
a.deposit(100)
a.deposit(787)
a.withdraw(300000)
b.deposit(2000)
a.deposit(353)
b.deposit(25680)
b.deposit(552)
a.deposit(85593)
b.withdraw(200000)

print(a.total_log)
print(b.total_log)

Account.get_account_num()