import sys

def main():
    print('Nth prime finder')
    print('(0) to exit')
    while True:
        nth = int(input('Nth prime: '))
        if nth is 0:
            print('quit')
            break
        print(primeFinder(nth))


def primeFinder(n):
    count = 0
    if n is 1:
        return 2
    elif n is 2:
        return 3
    n -= 1
    for i in range(1, sys.maxsize**10, 2):
        cnd = 0
        for j in range(1, int(i**(1/2))+1):
            if i % j is 0 and j is not 1:
                cnd = 1
                break
        if cnd is 0 and n is not 1 and i is not 1:
            count += 1
        if count >= n:
            return i


if __name__ == '__main__':
    main()
