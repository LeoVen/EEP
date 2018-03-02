import random
def main():
    print("""
        Welcome to Math's Game this is the tutorial. Please read through.
        In this game your objective is to reach a certain number with few operations as possible
        Operations Table:
                                Type:
            1 - to SUM table
            2 - to SUBTRACTION table
            3 - to MULTIPLICATION table
            4 - to DIVISION table
            5 - to EXPONENT table
            6 - to ROOT table
            7 - to MOD table
            8 - REMOVE decimals
            0 - EXIT
        """)
    print("""
        Select Game Mode:
        0- Exit.
        1- Reach the number as quick as possible. No tries limit.
        2- Limited amount of tries given randomly between 4 and 8.
        3- No sums or subtractions allowed. Hard. Error Margin depending on difficulty chosen
        4- Sandbox. Choose all the parameters
    """)
    game = -1
    while game != 0:
        game = int(input('Select game mode'))
        if game == 0:
            break
        elif game == 1:
            game1()
        elif game == 2:
            game2()
        elif game == 3:
            game3()
        elif game == 4:
            game4()
        elif game == 5:
            game5()
        else:
            print('Bad input. try Again')

def game1():
    print('Game 1: Reach the goal number as quick as possible with no operations limit')
    n = random.randint(-10000, 10000)
    goal = random.randint(-100000, 100000)
    print('Your number is {} with {} as your goal'.format(n, goal))
    itr = 0
    cond = 0
    while n != goal:
        op = int(input('Select Operation'))
        if op == 0:
            cond = 1
            break
        elif op == 1:
            n = add(n)
        elif op == 2:
            n = sub(n)
        elif op == 3:
            n = mul(n)
        elif op == 4:
            n = div(n)
        elif op == 5:
            n = exp(n)
        elif op == 6:
            n = rot(n)
        elif op == 7:
            n = mod(n)
        elif op == 8:
            n = dec(n)
        print('Your new number is {}.Your goal is {}'.format(n, goal))
        itr += 1
    if cond != 1:
        print('////////////////////////////////////')
        print('You reached your goal in {} tries'.format(itr))
        print('////////////////////////////////////')

def game2():
    print('Game 2: Reach the goal number with a limited amount of tries')
    n = random.randint(-1000, 1000)
    goal = random.randint(-1000, 1000)
    tries = random.randint(4, 8)
    print('Your number is {} with {} as your goal and {} tries'.format(n, goal, tries))
    itr = 0
    while n != goal and itr < tries:
        op = int(input('Select Operation'))
        if op == 0:
            break
        elif op == 1:
            n = add(n)
        elif op == 2:
            n = sub(n)
        elif op == 3:
            n = mul(n)
        elif op == 4:
            n = div(n)
        elif op == 5:
            n = pow(n)
        elif op == 6:
            n = rot(n)
        elif op == 7:
            n = mod(n)
        elif op == 8:
            n = int(n)
        itr += 1
        print('Your new number is {}.Your goal is {}. You have {} tries left'.format(n, goal, (tries - itr)))
    if n != goal:
        print('You have not reached your goal')
    else:
        print('You have reached your goal')

def game3():
    print('Game 3: Reach the goal number with a limited amount of tries (no sums or subtractions allowed). Error Margin Enabled')
    n = random.randint(-1000, 1000)
    goal = random.randint(-1000, 1000)
    tries = random.randint(4, 8)
    print("""
        Choose Game Difficulty
        //Difficulty// KEY //MarginError//
        // Very Easy//  1  //    100    //
        //   Easy   //  2  //     50    //
        //  Medium  //  3  //     30    //
        //   Hard   //  4  //     15    //
        // Very Hard//  5  //      5    //
        //Impossible//  6  //      1    //
    """)
    while True:
        mar = int(input('Choose game difficulty'))
        if mar == 1:
            err = 100
            break
        elif mar == 2:
            err = 50
            break
        elif mar == 3:
            err = 30
            break
        elif mar == 4:
            err = 15
            break
        elif mar == 5:
            err = 5
            break
        elif mar == 6:
            err = 1
            break
        else:
            print('Bad Input. Try again')
    print('Your number is {} with {} as your goal and {} tries. Error Margin: {}'.format(n, goal, tries, err))
    itr = 0
    while (not ((n + err) >= goal and (n - err) <= goal)) and itr < tries:
        op = int(input('Select Operation'))
        if op == 0:
            break
        elif op == 1:
            print('Sum Table not allowed. Please try again')
            itr -= 1
        elif op == 2:
            print('Substraction Table not allowed. Please try again')
            itr -= 1
        elif op == 3:
            n = mul(n)
        elif op == 4:
            n = div(n)
        elif op == 5:
            n = pow(n)
        elif op == 6:
            n = rot(n)
        elif op == 7:
            n = mod(n)
        elif op == 8:
            n = int(n)
        itr += 1
        print('Your new number is {}.Your goal is {}. You have {} tries left'.format(n, goal, (tries - itr)))
    if (n + err) >= goal and (n - err) <= goal:
        if n == goal:
            print('You have reached your goal')
        else:
            print('You have reached your goal by the margin error')
    else:
        print('You have not reached your goal')

def game4():
    print('Coming soon')




def add(n):
    print("""
    SUM TABLE
    Operation: n + X
    // KEY //   X  //
    --------------
    //  0  // EXIT //
    //  1  //    1 //
    //  2  //    2 //
    //  3  //    3 //
    //  4  //    5 //
    //  5  //   10 //
    //  6  //   20 //
    //  7  //   50 //
    //  8  //  100 //
    //  9  //  500 //
    """)
    while True:
        sum = int(input('Select KEY'))
        if sum == 1:
            return n + 1
        elif sum == 2:
            return n + 2
        elif sum == 3:
            return n + 3
        elif sum == 4:
            return n + 5
        elif sum == 5:
            return n + 10
        elif sum == 6:
            return n + 20
        elif sum == 7:
            return n + 50
        elif sum == 8:
            return n + 100
        elif sum == 9:
            return n + 500
        elif sum == 0:
            return n

def sub(n):
    print("""
    SUBTRACTION TABLE
    Operation: n - X
    // KEY //  X  //
    --------------
    //  0  // EXIT //
    //  1  //    1 //
    //  2  //    2 //
    //  3  //    3 //
    //  4  //    5 //
    //  5  //   10 //
    //  6  //   20 //
    //  7  //   50 //
    //  8  //  100 //
    //  9  //  500 //
    """)
    while True:
        sub = int(input('Select KEY'))
        if sub == 1:
            return n - 1
        elif sub == 2:
            return n - 2
        elif sub == 3:
            return n - 3
        elif sub == 4:
            return n - 5
        elif sub == 5:
            return n - 10
        elif sub == 6:
            return n - 20
        elif sub == 7:
            return n - 50
        elif sub == 8:
            return n - 100
        elif sub == 9:
            return n - 500
        elif sub == 0:
            return n
        else:
            print('Bad input. Try again.')

def mul(n):
    print("""
    MULTIPLICATION TABLE
    Operation: n * X
    // KEY //  X  //
    --------------
    //  0  // EXIT//
    //  1  //  -1 //
    //  2  //   2 //
    //  3  //   3 //
    //  4  //   5 //
    //  5  //   6 //
    //  6  //  10 //
    //  7  //  20 //
    //  8  //  50 //
    //  9  //   0 //
    """)
    while True:
        mul = int(input('Select KEY'))
        if mul == 1:
            return n * -1
        elif mul == 2:
            return n * 2
        elif mul == 3:
            return n * 3
        elif mul == 4:
            return n * 5
        elif mul == 5:
            return n * 6
        elif mul == 6:
            return n * 10
        elif mul == 7:
            return n * 20
        elif mul == 8:
            return n * 50
        elif mul == 9:
            return n * 0
        elif mul == 0:
            return n
        else:
            print('Bad input. Try again.')

def div(n):
    print("""
    DIVISION TABLE
    Operation: n / X
    // KEY //  X  //
    --------------
    //  0  // EXIT//
    //  1  //  -1 //
    //  2  //   2 //
    //  3  //   3 //
    //  4  //   5 //
    //  5  //   6 //
    //  6  //  10 //
    //  7  //  20 //
    //  8  //  50 //
    //  9  // 100 //
    """)
    while True:
        div = int(input('Select KEY'))
        if div == 1:
            return n / -1
        elif div == 2:
            return n / 2
        elif div == 3:
            return n / 3
        elif div == 4:
            return n / 5
        elif div == 5:
            return n / 6
        elif div == 6:
            return n / 10
        elif div == 7:
            return n / 20
        elif div == 8:
            return n / 50
        elif div == 9:
            return n / 100
        elif div == 0:
            return n
        else:
            print('Bad input. Try again.')

def exp(n):
    print("""
    EXPONENT TABLE
    Operation: n to the power of X ( n ** X)
    // KEY //  X  //
    --------------
    //  0  // EXIT//
    //  1  //  -1 //
    //  2  //   2 //
    //  3  //   3 //
    //  4  //   4 //
    //  5  //   5 //
    //  6  //   8 //
    //  7  //  10 //
    //  8  //  20 //
    //  9  //   0 //
    """)
    while True:
        exp = int(input('Select KEY'))
        if exp == 1:
            return n ** -1
        elif exp == 2:
            return n ** 2
        elif exp == 3:
            return n ** 3
        elif exp == 4:
            return n ** 4
        elif exp == 5:
            return n ** 5
        elif exp == 6:
            return n ** 8
        elif exp == 7:
            return n ** 10
        elif exp == 8:
            return n ** 20
        elif exp == 9:
            return n ** 0
        elif exp == 0:
            return n
        else:
            print('Bad input. Try again.')

def rot(n):
    print("""
    ROOT TABLE
    Operation: Xth root of n ( n ** (1 / X))
    // KEY //  X  //
    --------------
    //  0  // EXIT//
    //  1  //  10 //
    //  2  //   2 //
    //  3  //   3 //
    //  4  //   4 //
    //  5  //   5 //
    //  6  //   6 //
    //  7  //   7 //
    //  8  //   8 //
    //  9  //   9 //
    """)
    while True:
        exp = int(input('Select KEY'))
        if exp == 1:
            return n ** (1 / 10)
        elif exp == 2:
            return n ** (1 / 2)
        elif exp == 3:
            return n ** (1 / 3)
        elif exp == 4:
            return n ** (1 / 4)
        elif exp == 5:
            return n ** (1 / 5)
        elif exp == 6:
            return n ** (1 / 6)
        elif exp == 7:
            return n ** (1 / 7)
        elif exp == 8:
            return n ** (1 / 8)
        elif exp == 9:
            return n ** (1 / 9)
        elif exp == 0:
            return n
        else:
            print('Bad input. Try again.')

def mod(n):
    print("""
    MOD TABLE
    Operation: returns remainder of n divided by X ( n % X)
    // KEY //  X  //
    --------------
    //  0  // EXIT//
    //  1  //  10 //
    //  2  //   2 //
    //  3  //   3 //
    //  4  //   4 //
    //  5  //   5 //
    //  6  //   6 //
    //  7  //   7 //
    //  8  //   8 //
    //  9  //   9 //
    """)
    while True:
        exp = int(input('Select KEY'))
        if exp == 1:
            return n % 10
        elif exp == 2:
            return n % 2
        elif exp == 3:
            return n % 3
        elif exp == 4:
            return n % 4
        elif exp == 5:
            return n % 5
        elif exp == 6:
            return n % 6
        elif exp == 7:
            return n % 7
        elif exp == 8:
            return n % 8
        elif exp == 9:
            return n % 9
        elif exp == 0:
            return n
        else:
            print('Bad input. Try again.')

def dec(n):
    print('Decimal cases have been removed')
    return int(n)














main()