'''
    This function sums each algarism of a year and subtracts that number.
    This function goes on until the year reaches a number lower than 0
'''
def yearSubtractor(year):
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

def main():
    print(yearSubtractor(2017))
    input()



if __name__ == '__main__':
    main()
