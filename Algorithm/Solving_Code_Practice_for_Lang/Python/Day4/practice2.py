for i in range(1, 10):
    for j in range(2, 10):
        print('%-10s' % '{} x {} = {}'.format(j, i, i*j), end=' ')
    print()