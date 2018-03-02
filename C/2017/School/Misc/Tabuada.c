#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int i, j, n, m, nm, ns;

    printf("Type in until witch number you want \n");
        scanf("%d", &n);
    printf("Type in until witch multiplication \n");
        scanf("%d", &m);

    for (i = 1; i <= n; i++){
        for (j = 0; j <= m; j++){
            nm = j;
            ns = i * j;
            printf("%d X %d = %d \n", i, j, ns);
        }
        j = j + 1;
        printf("\n");
    }
*/

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
