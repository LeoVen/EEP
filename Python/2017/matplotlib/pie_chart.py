import numpy as np
import matplotlib.pyplot as plt
def pieChart():
    labels = ('Hydrogen', 'Helium', 'Oxygen',
              'Carbon', 'Neon', 'Iron',
              'Nitrogen', 'Silicon', 'Magnesium', 'Sulfur')
    sizes = [739000, 240000, 10400, 4600, 1340, 1090, 960, 650, 580, 440]
    colors = ['gold', 'red', 'green', 'lightcoral', 'lightskyblue', 'blue',
              'black', 'purple', 'pink', 'royalblue']
    explode = (0, 0, 0, 0, 0, 0.1, 0, 0, 0, 0)
    plt.pie(sizes, explode=explode, labels=labels,
            colors=colors, autopct='%1.1f%%', shadow=True,
            startangle=230, rotatelabels=True)
    plt.show()

def main():
    pieChart()



if __name__ == '__main__':
    main()
