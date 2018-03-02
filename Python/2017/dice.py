import random

def main():
    print("""
Hello, chose the following options:
1- Dice Roll
2- Multiple Dice Rolls
3- Modifier Calculator (D&D)
""")
    n = int(input())
    if n == 1:
        diceRoll()
    elif n == 2:
        characterDiceRoll()
    elif n == 3:
        modCalc()
    else:
        print("Invalid Input")

def diceRoll():
    print('''
Hello Welcome to dice Roll
Please write down a formula for a desired dice roll
Ex: 1x 1d4+1
Note: no spaces, no capital 'd' and a space after 'x' is required.
The first number is how many attacks you wish to perform
''')

    while True:
        newLi = ['', '', '', '']
        tot, sum, i = 0, 0, 0
        inp = input()
        li = list(inp)
        while li[i] is not 'x':
            newLi[0] += li[i]
            i += 1
        i += 2 #skipping x and a space
        while li[i] is not 'd':
            newLi[1] += li[i]
            i += 1
        i += 1 #Skipping d
        while li[i] is not '+':
            newLi[2] += li[i]
            i += 1
        i += 1 #Skipping +
        while i < len(li):
            newLi[3] += li[i]
            i += 1
        for k in range(int(newLi[0])):
            tot = roll(int(newLi[1]), int(newLi[2]), int(newLi[3]))
            print(tot)
            sum += tot
        print("Total: {}".format(int(sum)))



def roll(trans, interval, plus):
    total = 0
    for j in range(trans):
        total += random.randint(1, interval)
    total += plus
    return total


def characterDiceRoll():
    print('''
Hello, welcome to Character Dice Roll
Here you can get pseud-random rolls for your character's stats
Firstly enter how many rolls you'd like to do and then how many dices are to be removed
(+ or - for removing highest and lowest respectively)
Ex: 5r 6d4+1 -2 #6 dices of 4 sides are rolled 5 times adding 1 to each roll and the lowest 2 are removed
Or: 4r 8d2+3 +1 #8 dices of 2 sides are rolled 4 times adding 3 to each roll and the highest 1 is removed
''')
    while True:
        newLi = ['', '', '', '', '']
        i = 0

        inp = input()
        li = list(inp)
        while li[i] is not 'r':
            newLi[0] += li[i]
            i += 1
        i += 2          #skipping r and a space
        while li[i] is not 'd':
            newLi[1] += li[i]
            i += 1
        i += 1          #skipping d
        while li[i] is not '+':
            newLi[2] += li[i]
            i += 1
        i += 1          #skipping the +
        while li[i] is not ' ':
            newLi[3] += li[i]
            i += 1
        i += 1          #skipping the space
        sign = li[i]    #sign receiving + or -
        i += 1          #skipping the + or -
        while i < len(li):
            newLi[4] += li[i]
            i += 1
        if int(newLi[0]) <= int(newLi[4]):
            print("Error. Bad input. Number of rolls is smaller or equals the number of removed dice")
            break
        doRoll(int(newLi[0]), int(newLi[1]), int(newLi[2]), int(newLi[3]), int(newLi[4]), sign)


def doRoll(times, ndice, diesize, plus, nremoved, sign):
    roll, total = 0, 0
    tsum = 0
    sum = [0 for z in range(times)]
    pool = [[0 for x in range(ndice)] for y in range(times)]
    for t in range(times):
        for m in range(ndice):
            roll = random.randint(1, diesize)
            pool[t][m] = roll
    for t in range(times):
        pool[t].sort(reverse=True)
    print("You've gotten the following rolls:")
    for t in range(times):
        print(pool[t])
    print("And the following rolls were considered:")
    #checking sign
    if sign is '+':
        for t in range(times):
            for r in range(nremoved):
                del pool[t][r]
    elif sign is '-':
        for t in range(times):
            for r in range(nremoved):
                del pool[t][ndice-nremoved]
    for t in range(times):
        print(pool[t])
    print("For a total of:")
    for t in range(times):
        for m in range(ndice-nremoved):
            sum[t] += pool[t][m]
    for t in range(times):
        tsum += sum[t] + plus
    for t in range(times):
        print("Roll {} yields {} + {} = {}".format(t+1, pool[t], plus, sum[t]+plus))
    print("Total Sum: {}    Average: {}".format(tsum, tsum/times))


def modCalc():
    print("What is the attribute value of your character?")
    while True:
        val = int(input())
        if val <= 0:
            print("Invalid Input. Attribute value must be 1 or higher")
            break
        if val%2 is 0:
            print("Your Modifier is: {}".format(int((val/2)-5)))
        elif val%2 is not 0:
            val -= 1
            print("Your Modifier is: {}".format(int((val/2)-5)))










if __name__ == '__main__':
    main()