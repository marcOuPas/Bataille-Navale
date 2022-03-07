//ABOUD MARC
//BATAILLE NAVALE
//MA-20




#include <stdio.h>
#include <time.h>
#include <windows.h>



//FONCTION TABLEAU


void imprimertab(int tableau[10][10]) {


    printf("\n   A  B  C  D  E  F  G  H  I  J \n");


    for (int ligne = 0; ligne < 10; ligne++) {
        printf("\n");
        printf("%2d", ligne + 1);
        for (int col = 0; col < 10; col++) {
            if (tableau[ligne][col] == 0 || tableau[ligne][col] == 1) {
                printf(" _|");
            }
            if (tableau[ligne][col] == 40) {
                printf(" O|");
            }
            if (tableau[ligne][col] == 80) {
                printf(" X|");
            }
            if (tableau[ligne][col] == 60) {
                printf(" ~|");
            }


        }
    }
}



//FONCTION CONVERSION ASCCI

int convert(char lettre) {
    int nombre;
    nombre = lettre - 65;
    return nombre;
}

int main() {
    SetConsoleOutputCP(65001);
    int dmdligne, dmdcol, question, choix, choisirligne, score;
    char choisircolonne;




    //MENU DU JEU
    while (choix != 3) {
        printf("\n1:Jouer a la bataille navale\n2:Afficher l aide\n3:Arreter\nReponse:");
        scanf("%d", &choix);

        if (choix == 2) {
            printf("\n\nPour jouer, tapez d'abord le numero de ligne et ensuite la lettre de la colonne\n\n  ");
            printf("\n-Les cases ayant touche un bateau s'affiche avec un X\n-Les cases n'ayant pas touche de bateau s'afficher avec un O\n-Les cases ayant coule un bateau s'affiche avec un ~\n\n");
            printf("\nLes regles du jeu sont les suivantes:\nLe but du jeu est de couler tous les bateaux de l'adversaire. Pour cela, chacun votre tour, vous devez essayer de tirer sur ses navires en devinant leurs positions. Pour tirer, il faut citer les coordonnées d'un emplacement comprenant \nun chiffre et une lettre\n\n");
        }

        //AFFICHAGE TABLEAU
        if (choix == 1) {
            int tableau[10][10] = {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

            };

            //POSER LA QUESTION AU JOUEUR
            while (tableau[1][0] + tableau[2][0] + tableau[3][0] + tableau[2][2] + tableau[2][3] + tableau[2][4] +
                   tableau[2][5] + tableau[4][8] + tableau[5][8] != 540) {
                imprimertab(tableau);
                printf("\nchoissez la ligne ou tirer:");
                scanf("%d", &choisirligne);

                printf("\nchoissez la colonne ou tirer:");
                scanf(" %c", &choisircolonne);

                //AFFICHAGE DES ACTIONS SOUHAITE
                if (tableau[choisirligne - 1][choisircolonne - 65] == 0) {
                    tableau[choisirligne - 1][choisircolonne - 65] = 40;

                }

                if (tableau[choisirligne - 1][choisircolonne - 65] == 1) {
                    tableau[choisirligne - 1][choisircolonne - 65] = 80;

                }

                if (tableau[1][0] + tableau[2][0] + tableau[3][0] == 240) {
                    tableau[1][0] = 60;
                    tableau[2][0] = 60;
                    tableau[3][0] = 60;

                }

                if (tableau[2][2] + tableau[2][3] + tableau[2][4] + tableau[2][5] == 320) {
                    tableau[2][2] = 60;
                    tableau[2][3] = 60;
                    tableau[2][4] = 60;
                    tableau[2][5] = 60;

                }

                if (tableau[4][8] + tableau[5][8] == 160) {
                    tableau[4][8] = 60;
                    tableau[5][8] = 60;

                }


                imprimertab(tableau);

                //NOMBRE DE BATEAUX RESTANTS
                score = 3;

                if (tableau[1][0] + tableau[2][0] + tableau[3][0] == 180) {
                    score=score-1;
                }
                if (tableau[2][2] + tableau[2][3] + tableau[2][4] + tableau[2][5] == 240) {
                    score=score-1;
                }
                if (tableau[4][8] + tableau[5][8] == 120) {
                    score=score-1;
                }

                printf("\n\nil reste %d bateau(x)\n", score);

                if(score==0){
                    printf("********************\n!!!VOUS AVEZ GAGNE!!!\n********************\n");
                }

            }


        }
    }


    return 0;
}