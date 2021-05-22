def calcultate(string):
    return eval(string)

i = input("계산할 식(ex : 1+2) : ")
print("{} = {}".format(i, calcultate(i)))