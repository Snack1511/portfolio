# while True : 
#     user_input = input('계산식 입력. 숫자와 연산자 사이 공백(예 : 1 + 4) : ')
#     if not user_input == '':
#         quiz = user_input.split()
#         if len(quiz) == 3:
#             x = int(quiz[0])
#             y = int(quiz[2])
#             if quiz[1] == '+':
#                 print(x+y)
#             elif quiz[1] == '-':
#                 print(x-y)
#             elif quiz[1] == '*':
#                 print(x*y)
#             elif quiz[1] == '/':
#                 if y == 0:
#                     print("0으로 나눌 수 없습니다.")
#                 else:
#                     print(x/y)
#             else:
#                 print("사칙연산만 가능합니다.")
#         else:
#             print("입력값이 바르지 않습니다.")
#     else:
#         print("프로그램 종료")
#         break

user_input = input("계산식 입력(예:2*4)")
print("결과 : {}".format(eval(user_input)))

