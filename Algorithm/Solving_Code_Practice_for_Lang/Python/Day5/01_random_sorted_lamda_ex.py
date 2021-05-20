import random
#Random
#for i in range(5):
    #print(random.randint(1, 6))
#    print(random.sample(range(1, 7), 2))#[6, 5][6, 2][2, 4][4, 5][6, 2]

# lista = [5, 2, 3, 4, 1]
# result = sorted(lista, reverse=True)
# print(result)
# print(lista)

# listb = [5,2,3,4,1]
# listb.sort(reverse=True)
# print(listb)

# def addnum(x, y):
#     return x + y

# print(addnum(2, 4))
# print((lambda x,y:x+y)(2,4))

# target = ['  Cat ', '    tiger ', '   dog', 'snake   ']
# print(sorted(target))

# def My_key(string):
#     return len(string)

# print(sorted(target, key=My_key))
# print(sorted(target, key=lambda string : len(string.strip())))

dic1 = {1:'D', 2:'B', 3:'B', 4:'E', 5:'A'}
print(sorted(dic1))
print(sorted(dic1.items(), key=lambda data :data[1]))