#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Functions declared
void primeCheck();
void primeFinder();
void primeInterval();
void primeNumber();


int main()
{

    //Variables
    int x;

    //Code
    printf("Type in:\n");
    printf("\n  1 for prime check");
    printf("\n  2 to print all prime numbers up to N");
    printf("\n  3 to print all the prime numbers between two numbers");
    printf("\n  4 to calculate the number of prime numbers up to N\n\n");

        scanf("%d", &x);
    switch(x) {

    case 1 :
        primeCheck();
        break;
    case 2 :
        primeFinder();
        break;
    case 3 :
        primeInterval();
        break;
    case 4 :
        primeNumber();
        break;
    default:
        printf("Error, bad input. Try again");
        break;
    }
}

void primeCheck(){

    //Variables
    int i, cond=0;
    unsigned long long int z;

    //Code
    printf("Type in number...");
        scanf("%llu", &z);
    //Loop
        for(i=2; i<=sqrt(z); i++){

            if (z%i == 0){
                printf("Number %llu is not prime", z);
                cond = 1;
                break;
            }

            else if (z%i != 0){
                continue;
            }
        }//End Loop
        if(cond == 0){
            printf("%llu is prime", z);
        }


}

void primeFinder(){

    //Variables
    int i, cond, num=0;
    unsigned long long int z, n;

    //Code
    printf("Prime numbers up to...");
        scanf("%llu", &n);
    //Loop
    for(z=2; z<=n; z++){

        cond = 0;
        for(i=2; i<=sqrt(z); i++){

            if(z%i == 0){
                cond = 1;
                break;
            }
        }
        if (cond == 0 && n != 1){
            printf("\n%llu", z);
            num++;
        }
    }//End Loop
    printf("\n");
    system("PAUSE");
    system("cls");
    printf("\n\n    Total primes: %d", num);
}

void primeInterval(){

    //Variables
    int i, cond, num=0;
    unsigned long long int n1, n2;

    //Code
    printf("Type in first number...");
        scanf("%llu", &n1);
    printf("Type in second number...");
        scanf("%llu", &n2);
    //Loop
    while(n1<n2){

        cond = 0;
        for(i=2; i<=sqrt(n1); i++){

            if(n1%i == 0){
                cond = 1;
                break;
            }
        }
        if(cond == 0 && n2 != 1){
            printf("\n%llu", n1);
            num++;
        }

        n1++;
    }//End Loop
    printf("\n");
    system("PAUSE");
    system("cls");
    printf("\n\n    Total primes: %d", num);
}

void primeNumber(){

    //Variables
    int i, cond, num=0;
    unsigned long long int z, n;

    //Code
    printf("Prime numbers up to...");
        scanf("%llu", &n);
    //Loop
    for(z=2; z<=n; z++){

        cond = 0;
        for(i=2; i<=sqrt(z); i++){

            if(z%i == 0){
                cond = 1;
                break;
            }
        }
        if (cond == 0 && n != 1){
            num++;
        }
    }//End Loop
    printf("\n\n    Total primes: %d", num);
}
