#include <stdio.h>
#include <stdlib.h>

////////////////TABUADA//////////////////////////////////////////////////////////////////////
/*
int main()
{

    int i, j, nmax, nmin, mmax, mmin, nm, ns;

    printf("Type in the starting number \n");
        scanf("%d", &nmin);
    printf("Type in until witch number you want \n");
        scanf("%d", &nmax);
    printf("Type in the starting multiplication \n");
        scanf("%d", &mmin);
    printf("Type in until witch multiplication \n");
        scanf("%d", &mmax);

    for (i = nmin; i <= nmax; i++){
        for (j = mmin; j <= mmax; j++){
            nm = j;
            ns = i * j;
            printf("%d X %d = %d \n", i, j, ns);
        }
        j = j + 1;
        printf("\n");
    }

}
*/
////////////////FIBONACI NUMBERS////////////////////////////////////////////////////////////
/*
int main(){

    double j;
    double n, c, d;
    d=0;
    c=1;

    for(n=1; n; n=c+d){
        d=c;
        c=n;
        j=(d+c)/c;
        printf("%.0lf \n", n);
    if(j<=1.6180339887498948482 && j>=1.618033988749894848){
                break;
        }
    }
    return 0;


}
*/
////////////////INVERT NUMBERS////////////////////////////////////////////////////////////
/*
int main(){

    int n, r = 0;
    printf("Type a number to invert \n");
        scanf("%d", &n);

    while(n!=0){
        r = r * 10;
        r = r + n%10;
        n = n/10;
    }

    printf("%d", r);

    return 0;
}
*/

int main(){

    printf("BLANK");
}
