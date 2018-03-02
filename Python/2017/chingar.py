import random

def main():
    while True:
        print("Próximo")
        input()
        parentes = ['sua irmã',
                    'sua mãe',
                    'sua avó',
                    'sua tia',
                    'sua cachorra',
                    'sua patroa',
                    'sua mina',
                    'seu irmão',
                    'seu pai',
                    'seu avô',
                    'seu tio',
                    'seu cachorro',
                    'o gostoso do yanzão',
                    'o vitão',
                    'o boneco de posto',
                    ]
        modo = [' de quatro',
                ' na cama',
                ' num puteiro',
                ' na pia da cozinha',
                ' no box do banheiro',
                ' na casa da sua tia',
                ' num swing',
                ' com o professor Odahyr junto',
                ' na esquina do McDonalds',
                ' no circo',
                ' na Shirley Terezinha',
                ' com o Juarez fumando Marijuana']
        extra = [' e depois lambi ele(a) todinho(a)',
                 ' e depois chupei uma ppk',
                 ' e depois fudi a mãe',
                 ' e depois jantei a cadela da sua irmã',
                 ' e depois trepei no pau',
                 ' e depois meti o pau na cara dele(a)']
        print('Ontem comi ' +
              parentes[random.randint(0, len(parentes)-1)] +
              modo[random.randint(0, len(modo)-1)] +
              extra[random.randint(0, len(extra)-1)])
    

if __name__ == '__main__':
    main()
