coffee ={'아메리카노':2500, '카푸치노':3500, '카페라떼':3000,'레몬에이드':2000}
print(sorted(coffee.keys(), key=lambda data: coffee[data], reverse=True))
menus = input("선택 : ")
print(coffee[menus])