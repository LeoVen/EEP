#Some functions that I use a lot are packed in here

def prime(n):
    from sys import maxsize as maxint
    count = 0
    if n is 1:
        return 2
    elif n is 2:
        return 3
    n -= 1
    for i in range(1, maxint**10, 2):
        cnd = 0
        for j in range(1, int(i**(1/2))+1):
            if i % j is 0 and j is not 1:
                cnd = 1
                break
        if cnd is 0 and n is not 1 and i is not 1:
            count += 1
        if count >= n:
            return i



def collatz(n):
    number = n
    it = 0
    high = n
    while n > 1:
        if int(n) % 2 is 0:
            n /= 2
            it += 1
        elif int(n) % 2 is 1:
            n = 3 * n + 1
            it += 1
            if n > high:
                high = n
    return [number, it, int(high)]



def max_collatz(n):
    number = n
    it = 0
    high = n
    while n > 1:
        if int(n) % 2 is 0:
            n /= 2
            it += 1
        elif int(n) % 2 is 1:
            n = 3 * n + 1
            it += 1
            if n > high:
                high = n
    return int(high)



def it_collatz(n):
    number = n
    it = 0
    high = n
    while n > 1:
        if int(n) % 2 is 0:
            n /= 2
            it += 1
        elif int(n) % 2 is 1:
            n = 3 * n + 1
            it += 1
            if n > high:
                high = n
    return it



def numSubtractor(year):
    it = 0
    while year > 0:
        year = str(year)
        list(year)
        sub = 0
        for i in range(len(year)):
            sub += int(year[i])
        year = int(year) - sub
        it += 1
        sub = 0
    return it



def printNumSubtractor(year):
    it = 0
    while year > 0:
        year = str(year)
        list(year)
        sub = 0
        for i in range(len(year)):
            sub += int(year[i])
        print("Ano: {} subtraiu: {}".format(year, sub))
        year = int(year) - sub
        it += 1
        sub = 0
    return it



def nthFib(n):
    phi = (1 + 5 ** (1/2) ) / 2
    return int( ( (phi ** n) - (1 - phi) ** n) / (5 ** (1/2)) )



def nthLucas(n):
    if n is 1:
        return 2
    n -= 1
    return nthFib(n - 1) + nthFib(n + 1)



def sumTenBase(magnitude):
    soma = 0
    for i in range(1, 10 ** magnitude + 1):
        soma += i
    return soma



def sumXBase(x, magnitude):
    soma = 0
    for i in range(1, x ** magnitude + 1):
        soma += i
    return soma


def generate(n):
    from random import randint
    randArr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    tot = 0
    for i in range(n):
        rnd = randint(0, 9)
        randArr[rnd] += 1
    print(randArr)
    for i in range(len(randArr)):
        tot += randArr[i]
    for i in range(len(randArr)):
        randArr[i] = randArr[i] / tot * 100
    print(randArr)


