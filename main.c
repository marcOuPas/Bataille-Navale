//ABOUD MARC
//BATAILLE NAVALE
//MA-20



#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>


int compteurBat = 0;


int tableau[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};



//Afficher le fichier

void afficheFichier(char score[]) {
    //Cette fonction affiche le fichier texte
    //dont le nom est passé par la variable "nomFichier"
    char chaine[50] = "";//pour lire une ligne, longueur max 50
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(score, "r");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        //lecture de la ligne suivante
        while (fgets(chaine, 50, fichier)) {
            printf("%s", chaine);//affichage ligne (y compris fin de ligne)
        }
        fclose(fichier); // fermeture du fichier
    }
}


int lectureFichierVersTableau(char nomFichier[]) {
    //Cette procédure lit le fichier nomFichier (ex: ../BN1.txt dans le répertoire du main.c)
    //on s'attend à un fichier du genre:
    // 0011111000
    // 0000033000... etc
    //et le transforme en fichier BN[10][10]
    char chaine[20];
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "r");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        int ligne = 0;
        //lecture de la ligne suivante (de 0 à 9 max)
        while (fgets(chaine, 20, fichier) && ligne < 10) {
            int co = 0;
            //la boucle s'arrête soit quand on est à 9, soit quand ce n'est pas un chiffre
            while (co < 10 && chaine[co] >= 48 && chaine[co] <= 57) {
                tableau[ligne][co] = chaine[co] - 48;
                co++;
            }
            ligne++;
        }
        fclose(fichier); // fermeture du fichier
    }
}

void dateHeure(char chaine[]) {
    //Cette fonction va chercher la date et l'heure et l'écrit dans la variable qu'on lui donne
    time_t now;
    int h, min, s, day, month, year;//pour récupérer chaque détail

    time(&now);// Renvoie l'heure actuelle
    struct tm *local = localtime(&now);//structure qui contient chaque détail de l'heure
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    // Ecrire dans la chaine les détails du genre 28/03/2022 11:52:05
    sprintf(chaine, "%02d/%02d/%04d %02d:%02d:%02d", day, month, year, h, min, s);

}


void ajouteFichier(char nomFichier[], char ligne[]) {
    //Cette fonction ouvre le fichier nomFichier
    // et ajoute une ligne avec la chaine ligne[]
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "a");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        //Ecrire un saut de ligne puis la ligne
        fputs("\n", fichier);
        fputs(ligne, fichier);
        fclose(fichier); // fermeture du fichier
    }
}


void ajouteFichierAvecHeure(char nomFichier[], char ligne[]) {
    char dateheure[20] = "";//chaine pour écrire l'heure
    char saisie2[50] = "";

    //récupération de l'heure
    dateHeure(dateheure);
    //Concaténation heure + saisie
    sprintf(saisie2, "%s la partie à ete demarrer par\n la partie a ete terminer par  %s", dateheure, ligne);
    //Ecriture dans le fichier
    ajouteFichier(nomFichier, saisie2);

}

//couleurs du texte

void Color(int t, int f) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, f * 16 + t);
}
//logo

void logo() {
    Color(11, 0);

    printf(" ____        _        _ _ _                               _      \n");
    printf("| __ )  __ _| |_ __ _(_) | | ___   _ __   __ ___   ____ _| | ___ \n");
    printf("|  _ \\ / _` | __/ _` | | | |/ _ \\ | '_ \\ / _` \\ \\ / / _` | |/ _ \\\n");
    printf("| |_) | (_| | || (_| | | | |  __/ | | | | (_| |\\ V / (_| | |  __/\n");
    printf("|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| |_|\\__,_| \\_/ \\__,_|_|\\___|\n\n");
    Color(8, 0);
    printf("        _     _     _ "  "__-=-//__  __\\\\-=-__"  " _     _     _        \n");
    printf(".-.,.-'`(,.-'`(,.-'`(,"  "\\_______/"  ".."  "\\_______/"  ",)`'-.,)`'-.,)`'-.,¸.-.\n\n");
    Color(15, 0);
}


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

                printf(" ");
                Color(1, 0);
                printf("O");
                Color(15, 0);
                printf("|");

            }
            if (tableau[ligne][col] == 80) {
                printf(" ");
                Color(4, 0);
                printf("X");
                Color(15, 0);
                printf("|");
            }


            if (tableau[ligne][col] == 60) {
                Color(14, 0);
                printf(" ");
                printf("~");
                printf("|");

            }
            Color(15, 0);


        }
    }
}


int main() {
    SetConsoleOutputCP(65001);
    system("cls");


    int choix = 0, choisirligne, score, nbcoups, variablealea;
    char choisircolonne, nomdujoueur[20];

    int bateau1_coord_x_1;
    int bateau1_coord_x_2;
    int bateau1_coord_x_3;
    int bateau1_coord_y_1;
    int bateau1_coord_y_2;
    int bateau1_coord_y_3;

    int bateau2_coord_x_1;
    int bateau2_coord_x_2;
    int bateau2_coord_x_3;
    int bateau2_coord_x_4;
    int bateau2_coord_y_1;
    int bateau2_coord_y_2;
    int bateau2_coord_y_3;
    int bateau2_coord_y_4;

    int bateau3_coord_x_1;
    int bateau3_coord_x_2;
    int bateau3_coord_y_1;
    int bateau3_coord_y_2;


    logo();


    //AFFICHAGE TABLEAU RANDOM


    srand(time(NULL));
    variablealea = rand() % 5 + 1;
    char nomfichier[15];
    sprintf(nomfichier, "../bateau%d.txt", variablealea);
    lectureFichierVersTableau(nomfichier);


    //MENU DU JEU


    while (choix != '4') {
        do {
            printf("\n1:Jouer a la bataille navale\n2:Afficher l aide\n3:Afficher le score                                    %s\")\n4:Arreter\nReponse:",
                   nomfichier);
            scanf(" %s", &choix);

        } while (choix != '1' && choix != '2' && choix != '3');


        if (choix == '2') {
            system("cls");
            printf("\n\nPour jouer, tapez d'abord le numero de ligne et ensuite la lettre de la colonne\n\n  ");
            printf("\n-Les cases ayant touche un bateau s'affiche avec un X\n-Les cases n'ayant pas touche de bateau s'afficher avec un O\n-Les cases ayant coule un bateau s'affiche avec un ~\n\n");
            printf("\nLes regles du jeu sont les suivantes:\nLe but du jeu est de couler tous les bateaux de l'adversaire. Pour cela, chacun votre tour, vous devez essayer de tirer sur ses navires en devinant leurs positions. Pour tirer, il faut citer les coordonnees d'un emplacement comprenant \nun chiffre et une lettre\n\n");
            system("PAUSE");
        }
//score
        if (choix == '3') {
            system("cls");
            Color(14, 0);
            printf("\t\t-------------------------------------------------\n");
            printf("\t\t|\t\t\t\t\t\t|\n");

            printf("\t\t|\t\t\t\t\t\t|\n");

            printf("\t\t|                      SCORE                    |\n");

            printf("\t\t|\t\t\t\t\t\t|\n");
            printf("\t\t|\t\t\t\t\t\t|\n");
            printf("\t\t-------------------------------------------------\n");
            Color(15, 0);

            afficheFichier("../score.txt");
            printf("\n");
            system("PAUSE");


        }

        //Debut du jeu

        if (choix == '1') {
            printf("ENTREZ UN NOM:");
            fflush(stdin);
            fgets(nomdujoueur, 50, stdin);
            system("cls");

            ajouteFichierAvecHeure("../logg.txt", nomdujoueur);

            //dire ou se situe la position des bateaux pour tous les tableaux


            if (variablealea == 1) {
                bateau1_coord_y_1 = 0;
                bateau1_coord_y_2 = 0;
                bateau1_coord_y_3 = 0;
                bateau1_coord_x_1 = 1;
                bateau1_coord_x_2 = 2;
                bateau1_coord_x_3 = 3;

                bateau2_coord_y_1 = 2;
                bateau2_coord_y_2 = 3;
                bateau2_coord_y_3 = 4;
                bateau2_coord_y_4 = 5;
                bateau2_coord_x_1 = 2;
                bateau2_coord_x_2 = 2;
                bateau2_coord_x_3 = 2;
                bateau2_coord_x_4 = 2;

                bateau3_coord_y_1 = 8;
                bateau3_coord_y_2 = 8;
                bateau3_coord_x_1 = 4;
                bateau3_coord_x_2 = 5;
            }

            if (variablealea == 2) {
                bateau1_coord_x_1 = 6;
                bateau1_coord_x_2 = 6;
                bateau1_coord_x_3 = 6;
                bateau1_coord_y_1 = 0;
                bateau1_coord_y_2 = 1;
                bateau1_coord_y_3 = 2;

                bateau2_coord_x_1 = 1;
                bateau2_coord_x_2 = 2;
                bateau2_coord_x_3 = 3;
                bateau2_coord_x_4 = 4;
                bateau2_coord_y_1 = 2;
                bateau2_coord_y_2 = 2;
                bateau2_coord_y_3 = 2;
                bateau2_coord_y_4 = 2;

                bateau3_coord_x_1 = 7;
                bateau3_coord_x_2 = 8;
                bateau3_coord_y_1 = 9;
                bateau3_coord_y_2 = 9;
            }

            if (variablealea == 3) {
                bateau1_coord_x_1 = 6;
                bateau1_coord_x_2 = 6;
                bateau1_coord_x_3 = 6;
                bateau1_coord_y_1 = 2;
                bateau1_coord_y_2 = 3;
                bateau1_coord_y_3 = 4;

                bateau2_coord_x_1 = 1;
                bateau2_coord_x_2 = 2;
                bateau2_coord_x_3 = 3;
                bateau2_coord_x_4 = 4;
                bateau2_coord_y_1 = 9;
                bateau2_coord_y_2 = 9;
                bateau2_coord_y_3 = 9;
                bateau2_coord_y_4 = 9;

                bateau3_coord_x_1 = 0;
                bateau3_coord_x_2 = 1;
                bateau3_coord_y_1 = 0;
                bateau3_coord_y_2 = 0;
            }

            if (variablealea == 4) {
                bateau1_coord_x_1 = 4;
                bateau1_coord_x_2 = 4;
                bateau1_coord_x_3 = 4;
                bateau1_coord_y_1 = 3;
                bateau1_coord_y_2 = 4;
                bateau1_coord_y_3 = 5;

                bateau2_coord_x_1 = 7;
                bateau2_coord_x_2 = 7;
                bateau2_coord_x_3 = 7;
                bateau2_coord_x_4 = 7;
                bateau2_coord_y_1 = 0;
                bateau2_coord_y_2 = 1;
                bateau2_coord_y_3 = 2;
                bateau2_coord_y_4 = 3;

                bateau3_coord_x_1 = 0;
                bateau3_coord_x_2 = 0;
                bateau3_coord_y_1 = 0;
                bateau3_coord_y_2 = 1;
            }

            if (variablealea == 5) {
                bateau1_coord_x_1 = 0;
                bateau1_coord_x_2 = 1;
                bateau1_coord_x_3 = 2;
                bateau1_coord_y_1 = 9;
                bateau1_coord_y_2 = 9;
                bateau1_coord_y_3 = 9;

                bateau2_coord_x_1 = 3;
                bateau2_coord_x_2 = 4;
                bateau2_coord_x_3 = 5;
                bateau2_coord_x_4 = 6;
                bateau2_coord_y_1 = 9;
                bateau2_coord_y_2 = 9;
                bateau2_coord_y_3 = 9;
                bateau2_coord_y_4 = 9;

                bateau3_coord_x_1 = 7;
                bateau3_coord_x_2 = 8;
                bateau3_coord_y_1 = 9;
                bateau3_coord_y_2 = 9;
            }




            while (tableau[bateau1_coord_x_1][bateau1_coord_y_1] +
                   tableau[bateau1_coord_x_2][bateau1_coord_y_2]
                   + tableau[bateau1_coord_x_3][bateau1_coord_y_3] +
                   tableau[bateau2_coord_x_1][bateau2_coord_y_1] +
                   tableau[bateau2_coord_x_2][bateau2_coord_y_2] +
                   tableau[bateau2_coord_x_3][bateau2_coord_y_3] +
                   tableau[bateau2_coord_x_4][bateau2_coord_y_4] +
                   tableau[bateau3_coord_x_1][bateau3_coord_y_1] +
                   tableau[bateau3_coord_x_2][bateau3_coord_y_2] != 540) {

                //NOMBRE DE BATEAUX RESTANTS
                score = 3;

                if (tableau[bateau1_coord_x_1][bateau1_coord_y_1] +
                    tableau[bateau1_coord_x_2][bateau1_coord_y_2] +
                    tableau[bateau1_coord_x_3][bateau1_coord_y_3] == 180) {
                    score = score - 1;
                }

                if (tableau[bateau2_coord_x_1][bateau2_coord_y_1] +
                    tableau[bateau2_coord_x_2][bateau2_coord_y_2] +
                    tableau[bateau2_coord_x_3][bateau2_coord_y_3] +
                    tableau[bateau2_coord_x_4][bateau2_coord_y_4] ==
                    240) {
                    score = score - 1;
                }

                if (tableau[bateau3_coord_x_1][bateau3_coord_y_1] +
                    tableau[bateau3_coord_x_2][bateau3_coord_y_2] ==
                    120) {
                    score = score - 1;
                }


                nbcoups += 0;
                logo();

                printf("\nil reste %d bateau\n",score);
                printf("\nvous avez tire %d fois \n", nbcoups);
                nbcoups++;

                //POSER LA QUESTION AU JOUEUR

                imprimertab(tableau);
                printf("\n  Sur quel ligne voulez vous tirer ? ex:[1-10]:");
                scanf(" %d", &choisirligne);
                printf("\n  Sur quel colonne voulez vous tirer? ex:[A-J]");
                scanf(" %c", &choisircolonne);



                //transformation des nombres en lettres
                if ((choisircolonne >= 65) && (choisircolonne < 75)) {
                    if (tableau[choisirligne - 1][choisircolonne - 65] == 0) {

                        tableau[choisirligne - 1][choisircolonne - 65] = 40;

                    }

                }

                if ((choisircolonne >= 97) && (choisircolonne < 107)) {
                    if (tableau[choisirligne - 1][choisircolonne - 97] == 0) {

                        tableau[choisirligne - 1][choisircolonne - 97] = 40;

                    }
                }

                if ((choisircolonne >= 65) && (choisircolonne < 75)) {
                    if (tableau[choisirligne - 1][choisircolonne - 65] == 1) {

                        tableau[choisirligne - 1][choisircolonne - 65] = 80;

                    }

                }

                if ((choisircolonne >= 97) && (choisircolonne < 107)) {
                    if (tableau[choisirligne - 1][choisircolonne - 97] == 1) {

                        tableau[choisirligne - 1][choisircolonne - 97] = 80;

                    }
                }

                //transformation des croix en bateaux coulés

                if (tableau[bateau1_coord_x_1][bateau1_coord_y_1] + tableau[bateau1_coord_x_2][bateau1_coord_y_2] +
                    tableau[bateau1_coord_x_3][bateau1_coord_y_3] == 240) {
                    tableau[bateau1_coord_x_1][bateau1_coord_y_1] = 60;
                    tableau[bateau1_coord_x_2][bateau1_coord_y_2] = 60;
                    tableau[bateau1_coord_x_3][bateau1_coord_y_3] = 60;
                }

                if (tableau[bateau2_coord_x_1][bateau2_coord_y_1] + tableau[bateau2_coord_x_2][bateau2_coord_y_2] +
                    tableau[bateau2_coord_x_3][bateau2_coord_y_3] + tableau[bateau2_coord_x_4][bateau2_coord_y_4] ==
                    320) {
                    tableau[bateau2_coord_x_1][bateau2_coord_y_1] = 60;
                    tableau[bateau2_coord_x_2][bateau2_coord_y_2] = 60;
                    tableau[bateau2_coord_x_3][bateau2_coord_y_3] = 60;
                    tableau[bateau2_coord_x_4][bateau2_coord_y_4] = 60;
                }


                if (tableau[bateau3_coord_x_1][bateau3_coord_y_1] + tableau[bateau3_coord_x_2][bateau3_coord_y_2] ==
                    160) {
                    tableau[bateau3_coord_x_1][bateau3_coord_y_1] = 60;
                    tableau[bateau3_coord_x_2][bateau3_coord_y_2] = 60;
                }


                system("cls");
                logo();
                imprimertab(tableau);
                system("cls");
            }

            //fin du jeu


            system("cls");
            printf("\n\n\n\n********************\n!!!BRAVO %s TU AS GAGNE!!!\n********************\n", nomdujoueur);

            ajouteFichierAvecHeure("../score.txt", nomdujoueur);

            ajouteFichierAvecHeure("../logg.txt", nomdujoueur);
            system("PAUSE");

            return 0;


        }
    }
}



