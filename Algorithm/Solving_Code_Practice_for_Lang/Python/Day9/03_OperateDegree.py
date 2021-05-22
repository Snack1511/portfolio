def score_list(*data):
    total = 0
    count = len(data)
    for i in data:
        total += i
        print("성적은 {}값입니다.".format(i))

    print("총점은 {}, 평균은 {:0.2f}입니다.".format(total, total/count))

def score_dic(**data):
    total = 0
    count = len(data)
    for k,v in data.items():
        total += v
        print("{} : {}점".format(k, v))
    print("총점은 {}, 평균은 {:0.2f}입니다.".format(total, total/count))

score_list(90,89,67,99)

score_dic(국어=90,영어=88,수학=86,과학=78)