def str2int(slist):
    nlist = slist.split()
    nlist = list(map(int, nlist))
    return nlist

def countvotes(votes):
    n = max(set(votes))#set() -> 데이터 입력시 중복값 허용X
    result = [0 for i in range(n)]
    print(result)
    for vote in votes:
        result[vote - 1] += 1
    return result

def printresult(result):
    for i in range(len(result)):
        print("기호 : {:2}, 득표수 : {}".format(i+1, result[i]))

votes = input("투표내용 : ")
votes = str2int(votes)
#print(votes)

result = countvotes(votes)
printresult(result)