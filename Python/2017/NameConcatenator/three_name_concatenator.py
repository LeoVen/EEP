import random


def concatName(nome1, nome2, nome3):
    min_des = 2
    min_cut = 0
    random_order = random.randint(0, 5)
    #These are to help cut the middle word
    rnd = random.randint(min_cut, len(nome2) - min_des + 1) # +1 to make middle word longer and more visible
    left = random.randint(min_cut, rnd)
    right = rnd - left
    nome1 = nome1[ : random.randint(min_cut, len(nome1) - min_des) ]
    nome2 = nome2[ left : right ]
    nome3 = nome3[ random.randint(min_cut, len(nome3) - min_des) : ]
    if random_order is 0:
        #nome1 + nome2 + nome3
        fullName = nome1 + nome2 + nome3
    elif random_order is 1:
        #nome1 + nome3 + nome2
        fullName = nome1 + nome3 + nome2
    elif random_order is 2:
        #nome2 + nome1 + nome3
        fullName = nome2 + nome1 + nome3
    elif random_order is 3:
        #nome2 + nome3 + nome1
        fullName = nome2 + nome3 + nome1
    elif random_order is 4:
        #nome3 + nome1 + nome2
        fullName = nome3 + nome1 + nome2
    elif random_order is 5:
        #nome 3 + nome2 + nome1
        fullName = nome3 + nome2 + nome1
    return fullName


def main():
    vetor_nomes = []
    nome1 = input()
    nome2 = input()
    nome3 = input()
    for i in range(1000):
        nome_completo = concatName(nome1, nome2, nome3)
        vetor_nomes.append(nome_completo)
    print(vetor_nomes)



if __name__ == '__main__':
    main()
