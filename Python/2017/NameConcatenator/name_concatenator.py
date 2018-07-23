import random

def concatName(name, surname):
    min_des = 1
    random_order = random.randint(0, 1)
    while True:
        if random_order is 0:
            #cortar no começo da primeira palavra e no final da segunda
            fullName = surname[ : random.randint(1, len(surname) - min_des) ] + name[ random.randint(1, len(name) - min_des) : ]
        elif random_order is 1:
            #cortar no começo da segunda palavra e no final da primeira
            fullName = name[ : random.randint(1, len(name) - min_des) ] + surname[ random.randint(1, len(surname) - min_des) : ]
        break
    return fullName


def main():
    vetor_nomes = set()
    nome1 = input()
    nome2 = input()
    for i in range(1000):
        nome_completo = concatName(nome1, nome2)
        vetor_nomes.add(nome_completo)
    print(sorted(vetor_nomes))


if __name__ == '__main__':
    main()
    
