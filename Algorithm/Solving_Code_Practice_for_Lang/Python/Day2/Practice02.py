Money = int(input("물건 값 : "))

Green = Money//10000
Money -= 10000*Green

Brown = Money//5000
Money -= 5000*Brown

Blue = Money//1000
Money -= 1000*Blue

BigCoin = Money//500
Money -= 500*BigCoin

MiddleCoin = Money//100
Money -= 100*MiddleCoin

SmallCoin = Money//50
Money -= 50*SmallCoin

SmallestCoin = Money//50
Money -= 10*SmallestCoin

print('만원권 {}장, 오천원권 {}장, 천원권 {}장, 오백원 {}개, 백원 {}개, 오십원 {}개, 십원 {}개'.format(Green, Brown, Blue, BigCoin, MiddleCoin, SmallCoin, SmallestCoin))