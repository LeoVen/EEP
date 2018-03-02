import random

def randomWord():
    ascii_1 = [i for i in range(65, 91)]
    ascii_2 = [i for i in range(97, 123)]
    space = 0
    iteration = 0
    word = ''
    upper_lower = 0.3
    while True:
        chance = random.random();
        if chance < 0.1 and iteration > 4 and space > 4:
            break
        elif space > 8:
            word += chr(32)
            space = 0
            iteration += 1
        elif chance >= 0.1 and chance < upper_lower and space is 0:
            word += chr(ascii_1[random.randint(0, 25)])
            iteration += 1
            space += 1
        elif chance >= upper_lower and chance < 0.9 and space is not 0:
            word += chr(ascii_2[random.randint(0, 25)])
            iteration += 1
            space += 1
        elif space > 4 and chance >= 0.9:
            word += chr(32)
            space = 0
            iteration += 1
    return word


def randomNormalizedWord():
    ascii_vowel = [65, 69, 73, 79, 85]
    ascii_consonant = [i for i in range(65, 91)]
    for i in range(len(ascii_consonant)-1):
        if ascii_consonant[i] is (65 or 69 or 73 or 79 or 85):
            del ascii_consonant[i]
    punctuation = [33, 44, 59, 46, 63]
    space = 0
    iteration = 0
    word = ''
    upper_lower = 0.3
    chance_loup = 0 #fixed
    chance_difference = 0.3
    repetition_limit = 1
    #normalizing functions (consonant and vowel
    vowel = 0
    consonant = 0
    while True:
        chance = random.random();
        if chance < 0.1 and iteration > 4 and space > 4:
            break
        elif (chance > 0.97) and iteration > 4 and space > 4:
            word += chr(punctuation[random.randint(0, 4)]) + chr(32)
            break
        elif space > 8:
            word += chr(32)
            space = 0
            iteration += 1
            vowel = 0
        elif chance >= upper_lower and chance < 0.9:
            #lower case
            chance_loup = random.random();
            if chance_loup < chance_difference and vowel < repetition_limit:
                #vowel
                word += chr(32 + ascii_vowel[random.randint(0, 4)])
                iteration += 1
                space += 1
                vowel += 1
                consonant = 0
            elif chance_loup >= chance_difference and consonant < repetition_limit:
                #consonant
                word += chr(32 + ascii_consonant[random.randint(0, 20)])
                iteration += 1
                space += 1
                vowel = 0
                consonant += 1
        elif chance < upper_lower and space is 0:
            #upper case
            chance_loup = random.random();
            if chance_loup > chance_difference and vowel < repetition_limit:
                #vowel
                word += chr(ascii_vowel[random.randint(0, 4)])
                iteration += 1
                space += 1
                vowel += 1
                consonant = 0
            elif chance_loup <= chance_difference and consonant < repetition_limit:
                #consonant
                word += chr(ascii_consonant[random.randint(0, 20)])
                iteration += 1
                space += 1
                vowel = 0
                consonant += 1
        elif space > 4 and chance >= 0.9:
            word += chr(32)
            space = 0
            iteration += 1
    return word


def main():
    n = int(input("Quantos parágrafos você deseja printar?"))
    starting_letter = [i for i in range(65, 91)]
    paragraph_chance = 0.05
    for i in range(n):
        phrase = '- ' #+ chr(starting_letter[random.randint(0, 4)])
        while True:
            chance = random.random();
            if chance > paragraph_chance:
                phrase += randomNormalizedWord() + ' '
            elif len(phrase) > 200 and chance <= paragraph_chance:
                break
        print(phrase + '.')
        print('')
        


if __name__ == '__main__':
    main()
        
