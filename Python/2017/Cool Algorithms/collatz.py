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

def main():
    print("(1) Simple Collatz Conjecture Calculation.")
    print("(2) Generate and Manipulate a List up to N.")
    print("(3) Generate and Manipulate a List from N up to M.")
    choice = int(input())
    if choice is 1:
        print("1 - Collatz Conjecture of a number N. Type 0 to exit.")
        while True:
            con = int(input())
            if con is 0:
                break
            result = collatz(con)
            print("Number {} took {} iterations to reach 1 and reached {} as its highest number.".format(result[0], int(result[1]), int(result[2])))
    elif choice is 2:
        while True:
            print("2 - Collatz Conjecture list. Type in a number to generate the list. 0 to exit")
            con = int(input())
            if con is 0:
                break
            elif con >= 1:
                pool = [collatz(r) for r in range(1, con + 1)]
                print("List Generated")
                while True:
                    print("Select index so see info. 0 to exit. -1 to print entire list. -2 to sort the list.")
                    select = int(input())
                    if select is 0:
                        break
                    elif select > con:
                        print("Error. Value higher than total list size")
                    elif select is -1:
                        for i in range(len(pool)):
                            print(pool[i])
                    elif select > 0:
                        print(pool[select - 1])
                    elif select is -2:
                        print("Sort by Number (1), Sort by Stopping Time (2), Sort by Highest Number Reached (3)")
                        sort = int(input())
                        if sort is 1:
                            pool.sort(key = lambda x: x[0])
                            print("List Sorted")
                        elif sort is 2:
                            pool.sort(key = lambda x: x[1])
                            print("List Sorted")
                        elif sort is 3:
                            pool.sort(key = lambda x: x[2])
                            print("List Sorted")
                        else:
                            print("Bad Input")
                    else:
                        print("Positive numbers only")
                break
            else:
                print("Negative numbers not allowed")
    elif choice is 3:
        print("3 - Collatz Conjecture list from N to M. Type in the numbers to generate the list. 0 to exit")
        minimum = int(input("Minimum value : "))
        maximum = int(input("Maximum value : "))
        if minimum >= maximum:
            print("Bad Input. Minimum is higher than Maximum")
            return
        elif minimum < 1:
            print("Bad Input. Minimum can not be less than 1")
            return
        else:
            pool = [collatz(r) for r in range(minimum, maximum + 1)]
            print("List Generated")
            while True:
                    print("Select index so see info. 0 to exit. -1 to print entire list. -2 to sort the list.")
                    select = int(input())
                    if select is 0:
                        break
                    elif select > maximum:
                        print("Error. Value higher than total list size")
                        break
                    elif select is -1:
                        for i in range(len(pool)):
                            print(pool[i])
                    elif select > 0:
                        print(pool[select - 1])
                    elif select is -2:
                        print("Sort by Number (1), Sort by Stopping Time (2), Sort by Highest Number Reached (3)")
                        sort = int(input())
                        if sort is 1:
                            pool.sort(key = lambda x: x[0])
                            print("List Sorted")
                        elif sort is 2:
                            pool.sort(key = lambda x: x[1])
                            print("List Sorted")
                        elif sort is 3:
                            pool.sort(key = lambda x: x[2])
                            print("List Sorted")
                        else:
                            print("Bad Input")
                    else:
                        print("Positive numbers only")
    else:
        print("Error. Exiting")
        return



if __name__ == '__main__':
    main()
