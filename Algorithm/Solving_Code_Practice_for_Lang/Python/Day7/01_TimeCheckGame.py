import time

time_diff = []
cnt = 0
while True : 
    cnt += 1
    menu = input(str(cnt) + '번째 시도 : 시작하려면 ENTER(종료시 Q)')
    if menu.upper() == 'Q':
        break
    start = time.time()
    input("5초 후에 ENTER")
    end = time.time()
    diff = end - start
    time_diff.append(diff)

if not len(time_diff) == 0:
    print("엔터키를 누른 시간 간격 : ", time_diff)
    time_diff1 = [data - 5 for data in time_diff]
    result = list( map(abs, time_diff1))
    print('시간차이 : ',result)
    index = result.index(min(result))
    print('최종선택한 실제 시간 : ', time_diff[index], '초')
    print('최종선택한 실제 시간차이 : ', result[index], '초')
else:
    print('저장된 정보가 없습니다.')
print("프로그램을 종료합니다.")
