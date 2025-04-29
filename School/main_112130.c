#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int Q;
    printf("Saisir la valeur de a :");
    scanf("%d",&a);
    printf("Saisir la valeur de b :");
    scanf("%d",&b);
    if(a>b)
    {
        printf("Le plus grand nombre est :%d\n", a);
        Q=a%3;
        printf("Le resultat est :%d", Q);
    }
    else
    {
        printf("Le plus grand nombre est :%d\n", b);
        Q=b%3;
        printf("Le resultat est :%d", Q);
    }

    return 0;
}
