#include <stdio.h>
#include <string.h>

#define MAX_BILLETS 100
#define MAX_LIGNES 10
#define CODE_PUK_ADMIN "123456"
#define CODE_PUK_GUICHETIER "654321"
#define TVA 0.18  // TVA de 18%

typedef struct {
    int id;
    char nomClient[50];
    int estReserve;
    int estValide;
    float prixBase; // Prix du billet sans TVA
} Billet;

typedef struct {
    int id;
    char nom[50];
    char horaire[20];
    char date[20];  // Date du trajet
    float tarif;
    char conducteur[50];
    char vehicule[50];
} Ligne;

int main() {
    Billet billets[MAX_BILLETS];
    Ligne lignes[MAX_LIGNES];
    int compteurBillets = 0;
    int compteurLignes = 0;
    int typeCompte;
    int choix;

    while (1) {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("Choisissez votre type de compte :\n");
        printf("1. Client\n");
        printf("2. Guichetier\n");
        printf("3. Administrateur\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &typeCompte);

        if (typeCompte == 1) {
            // Menu Client
            while (1) {
                printf("\n--- MENU CLIENT ---\n");
                printf("1. Reserver un billet\n");
                printf("2. Acheter un billet\n");
                printf("3. Voir mes billets\n");
                printf("4. Retour au menu principal\n");
                printf("Votre choix : ");
                scanf("%d", &choix);

                if (choix == 1) {
                    if (compteurBillets >= MAX_BILLETS) {
                        printf("Aucune place disponible.\n");
                    } else {
                        billets[compteurBillets].id = compteurBillets + 1;
                        printf("Entrez votre nom : ");
                        scanf(" %[^\n]", billets[compteurBillets].nomClient);
                        printf("Entrez le prix de base du billet : ");
                        scanf("%f", &billets[compteurBillets].prixBase);
                        billets[compteurBillets].estReserve = 1;
                        billets[compteurBillets].estValide = 1;
                        printf("Billet reserve avec succes. ID: %d\n", billets[compteurBillets].id);
                        compteurBillets++;
                    }
                } else if (choix == 2) {
                    int id;
                    int trouve = 0;
                    printf("Entrez l'ID du billet µ acheter : ");
                    scanf("%d", &id);

                    for (int i = 0; i < compteurBillets; i++) {
                        if (billets[i].id == id && billets[i].estValide == 1 && billets[i].estReserve == 1) {
                            billets[i].estReserve = 0;
                            printf("Billet achete avec succes pour %s.\n", billets[i].nomClient);
                            trouve = 1;
                            break;
                        }
                    }

                    if (!trouve) {
                        printf("Billet introuvable ou deja achete.\n");
                    }
                } else if (choix == 3) {
                    printf("\nVos billets :\n");
                    for (int i = 0; i < compteurBillets; i++) {
                        printf("ID: %d | Client: %s | Statut: %s | Prix de base: %.2f\n",
                               billets[i].id,
                               billets[i].nomClient,
                               billets[i].estReserve ? "Reserve" : "Achete",
                               billets[i].prixBase);
                    }
                } else if (choix == 4) {
                    break; // Retour au menu principal
                } else {
                    printf("Choix invalide.\n");
                }
            }
        } else if (typeCompte == 2) {
            // Vérification du code PUK guichetier
            char saisie[20];
            int essais = 0;
            int accesAutorise = 0;

            while (essais < 3) {
                printf("Entrez le code PUK guichetier : ");
                scanf(" %[^\n]", saisie);

                if (strcmp(saisie, CODE_PUK_GUICHETIER) == 0) {
                    accesAutorise = 1;
                    break;
                } else {
                    printf("Code incorrect. Tentative %d/3\n", essais + 1);
                    essais++;
                }
            }

            if (!accesAutorise) {
                printf("Acces refuse. Trop de tentatives.\n");
            } else {
                // Menu Guichetier
                while (1) {
                    printf("\n--- MENU GUICHETIER ---\n");
                    printf("1. Enregistrer une vente\n");
                    printf("2. Voir tous les billets\n");
                    printf("3. Vérifier un billet client\n");
                    printf("4. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix);

                    if (choix == 1) {
                        if (compteurBillets >= MAX_BILLETS) {
                            printf("Plus de billets disponibles.\n");
                        } else {
                            billets[compteurBillets].id = compteurBillets + 1;
                            printf("Nom du client : ");
                            scanf(" %[^\n]", billets[compteurBillets].nomClient);
                            printf("Entrez le prix de base du billet : ");
                            scanf("%f", &billets[compteurBillets].prixBase);
                            billets[compteurBillets].estReserve = 0;
                            billets[compteurBillets].estValide = 1;
                            printf("Vente enregistrée. Billet ID : %d\n", billets[compteurBillets].id);
                            compteurBillets++;
                        }
                    } else if (choix == 2) {
                        printf("\nTous les billets :\n");
                        for (int i = 0; i < compteurBillets; i++) {
                            printf("ID: %d | Client: %s | Statut: %s\n",
                                   billets[i].id,
                                   billets[i].nomClient,
                                   billets[i].estReserve ? "Reserve" : "Achete");
                        }
                    } else if (choix == 3) {
                        int id;
                        int trouve = 0;
                        printf("Entrez l'ID du billet µ verifier : ");
                        scanf("%d", &id);

                        for (int i = 0; i < compteurBillets; i++) {
                            if (billets[i].id == id) {
                                trouve = 1;
                                float prixTotal = billets[i].prixBase * (1 + TVA);  // Calcul du prix avec TVA
                                printf("Billet ID: %d | Client: %s | Statut: %s | Prix de base: %.2f | Montant total avec TVA: %.2f\n",
                                       billets[i].id,
                                       billets[i].nomClient,
                                       billets[i].estReserve ? "Reserve (non paye)" : "Achete",
                                       billets[i].prixBase,
                                       prixTotal);
                                break;
                            }
                        }

                        if (!trouve) {
                            printf("Billet introuvable.\n");
                        }
                    } else if (choix == 4) {
                        break; // Retour au menu principal
                    } else {
                        printf("Choix invalide.\n");
                    }
                }
            }
        } else if (typeCompte == 3) {
            // Vérification du code PUK admin
            char saisie[20];
            int essais = 0;
            int accesAutorise = 0;

            while (essais < 3) {
                printf("Entrez le code PUK administrateur : ");
                scanf(" %[^\n]", saisie);

                if (strcmp(saisie, CODE_PUK_ADMIN) == 0) {
                    accesAutorise = 1;
                    break;
                } else {
                    printf("Code incorrect. Tentative %d/3\n", essais + 1);
                    essais++;
                }
            }

            if (!accesAutorise) {
                printf("Acces refuse. Trop de tentatives.\n");
            } else {
                // Menu Administrateur
                while (1) {
                    printf("\n--- MENU ADMINISTRATEUR ---\n");
                    printf("1. Ajouter une ligne\n");
                    printf("2. Modifier une ligne\n");
                    printf("3. Voir toutes les lignes\n");
                    printf("4. Quitter\n");
                    printf("5. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &choix);

                    if (choix == 1) {
                        if (compteurLignes >= MAX_LIGNES) {
                            printf("Nombre maximal de lignes atteint.\n");
                        } else {
                            lignes[compteurLignes].id = compteurLignes + 1;
                            printf("Nom de la ligne : ");
                            scanf(" %[^\n]", lignes[compteurLignes].nom);
                            printf("Horaire : ");
                            scanf(" %[^\n]", lignes[compteurLignes].horaire);
                            printf("Date du trajet (jj/mm/aaaa) : ");
                            scanf(" %[^\n]", lignes[compteurLignes].date);
                            printf("Tarif : ");
                            scanf("%f", &lignes[compteurLignes].tarif);
                            printf("Nom du conducteur : ");
                            scanf(" %[^\n]", lignes[compteurLignes].conducteur);
                            printf("Vehicule : ");
                            scanf(" %[^\n]", lignes[compteurLignes].vehicule);
                            printf("Ligne ajoutee avec succes. ID : %d\n", lignes[compteurLignes].id);
                            compteurLignes++;
                        }
                    } else if (choix == 2) {
                        int id;
                        printf("Entrez l'ID de la ligne µ modifier : ");
                        scanf("%d", &id);

                        int trouve = 0;
                        for (int i = 0; i < compteurLignes; i++) {
                            if (lignes[i].id == id) {
                                trouve = 1;
                                printf("Modifier la ligne %d :\n", id);
                                printf("Nom de la ligne (%s) : ", lignes[i].nom);
                                scanf(" %[^\n]", lignes[i].nom);
                                printf("Horaire (%s) : ", lignes[i].horaire);
                                scanf(" %[^\n]", lignes[i].horaire);
                                printf("Date du trajet (%s) : ", lignes[i].date);
                                scanf(" %[^\n]", lignes[i].date);
                                printf("Tarif (%.2f) : ", lignes[i].tarif);
                                scanf("%f", &lignes[i].tarif);
                                printf("Conducteur (%s) : ", lignes[i].conducteur);
                                scanf(" %[^\n]", lignes[i].conducteur);
                                printf("Véhicule (%s) : ", lignes[i].vehicule);
                                scanf(" %[^\n]", lignes[i].vehicule);
                                printf("Ligne modifiee avec succes.\n");
                                break;
                            }
                        }

                        if (!trouve) {
                            printf("Ligne introuvable.\n");
                        }
                    } else if (choix == 3) {
                        printf("\nLignes disponibles :\n");
                        for (int i = 0; i < compteurLignes; i++) {
                            printf("ID: %d | Ligne: %s | Horaire: %s | Date: %s | Tarif: %.2f | Conducteur: %s | Vehicule: %s\n",
                                   lignes[i].id,
                                   lignes[i].nom,
                                   lignes[i].horaire,
                                   lignes[i].date,
                                   lignes[i].tarif,
                                   lignes[i].conducteur,
                                   lignes[i].vehicule);
                        }
                    } else if (choix == 4) {
                        break; // Retour au menu principal
                    } else if (choix == 5) {
                        break; // Retour au menu principal
                    } else {
                        printf("Choix invalide.\n");
                    }
                }
            }
        } else if (typeCompte == 4) {
            printf("Fermeture du programme.\n");
            break;
        } else {
            printf("Choix invalide.\n");
        }
    }

    return 0;
}
