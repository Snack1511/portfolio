def total(numbers):
    tot = 0
    for a in numbers:
        tot += a
    return tot

lst_nums = input("더할 숫자들을 입력하세요.(구분자 : ,) >>>").split(',')
lst_nums = list(map(int, lst_nums))
print("합계 : ", total(lst_nums))