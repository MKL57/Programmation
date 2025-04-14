#include<stdio.h>
#include<math.h>

int main()
{

   //programme code PUK
    int i=0;  //variable pour le compteur de tentatives
    int j=0;
    int PUK=123456;  //code PUK correcte en memoire
    int code;   //code PUK entre par l'utilisateur

          printf("\nPremiere phase de deverouillage \n");

          printf("Vous avez trois tentatives");

    while (i<3) //les trois tentatives pour le code PUK
     {
      printf("\nSaisissez votre code PUK [6 chiffres]:");
       scanf("%d",&code);
        i++;




             if (PUK==code)
             {
               printf("\nFelicitation! Votre code PUK est correcte \n");
               break ;
             }

          if (i==3)
          {
           printf("\n \nDesole, vos tentatives sont epuisees\n votre sim a ete bloque\n");
           return 0;
          }

                if (i==2)
                 {
                  printf("\nIl vous reste 1 tentatives\n");
                  }


                     if (i==1)
                     {
                     printf("\nIl vous reste 2 tentatives\n ");
                     }
      }


     int pin=1234; //variable du vrai code
   int pin_utilisateur; //variable qui reçoit ce que l'utilisateur saisi


    printf("\nDeuxieme partie du deverouillage\n \n");

    printf("Vous avez trois tentatives\n");

    while (j<3) //les trois tentatives pour le code PIN
     {
      printf("Saisissez votre code PIN [4 chiffres]:");
       scanf("%d",&pin_utilisateur);
        j++;




             if (pin==pin_utilisateur)
             {
               printf("\nFelicitation! Votre code PIN est correcte\n");
               printf("Votre SIM est deverouillee\n");
               break ;
             }

          if (j==3)
          {
           printf("\n \nDesole, vos tentatives sont epuises\n votre SIM a ete bloquee\n");
           return 0;
          }

                if (j==2)
                 {
                  printf("\nIl vous reste 1 tentatives\n");
                  }


                     if (j==1)
                     {
                     printf("\nIl vous reste 2 tentatives\n ");
                     }
      }










}
