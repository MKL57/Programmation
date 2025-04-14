#include <stdio.h>
int main()
{
    int n;
    int f,i;

    do
    {
        printf("Entrez un entier positif: ");
        scanf("%d",&n);
        printf("Veuillez reessayez\n");
    }
    while(n<0);

    if(n==0)
        printf("La factorielle est: 1");
        else{
            f=1;
            for(i=1; i <= n; i++)
                f = f*i;
            printf("La factorielle de %d est : %d",n,f);
        }
    return 0;
}
