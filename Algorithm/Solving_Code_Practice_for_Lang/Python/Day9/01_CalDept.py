def installment(price, months):
    result = price/months
    return result

price = int(input('상품대금 : '))
months = int(input('할부개월수(3~12) : '))

if 3 <= months <= 12:
    amt = installment(price, months)
    amt = int(round(amt, -1))
    print("월 할부금은 {}원 입니다.".format(amt))
else:
    print("3~12개월 할부만 가능합니다.")