
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Variables globales pour permettre à afficher_bilan()
   d'accéder aux scores sans recevoir de paramètres */
int scoreJoueur = 0;
int scoreOrdi = 0;

// Déclarations
void afficher_bilan(void);
void afficher_choix(int choix);
bool partie_en_cours(int manche, int scoreJ, int scoreO);
int saisie_joueur(void);
bool joueur1_gagne(int choix1, int choix2);


// Étape 2 - Procédure sans paramètre
void afficher_bilan(void)
{
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n",
           scoreJoueur, scoreOrdi);

    if (scoreJoueur > scoreOrdi)
    {
        printf("Bravo, vous avez gagné la partie !\n");
    }
    else if (scoreOrdi > scoreJoueur)
    {
        printf("L'ordinateur remporte la partie...\n");
    }
    else
    {
        printf("Match nul parfait !\n");
    }
}


// Étape 3 - Procédure avec paramètre
void afficher_choix(int choix)
{
    if (choix == 1)
    {
        printf("Pierre");
    }
    else if (choix == 2)
    {
        printf("Feuille");
    }
    else if (choix == 3)
    {
        printf("Ciseaux");
    }
    else if (choix == 4)
    {
        printf("Lézard");
    }
    else if (choix == 5)
    {
        printf("Spock");
    }
}


// Étape 4 - Fonction qui détermine si la partie continue
bool partie_en_cours(int manche, int scoreJ, int scoreO)
{
    return manche <= 7
        && scoreJ - scoreO < 2
        && scoreO - scoreJ < 2;
}


// Étape 4 - Fonction de saisie du joueur
int saisie_joueur(void)
{
    int choixJoueur;
    bool incorrect;

    // Saisie du joueur
    do
    {
        printf("Choix :\n");

        for (int i = 1; i <= 5; i++)
        {
            printf("%d = ", i);
            afficher_choix(i);
            printf("\n");
        }

        printf("Votre choix : ");
        scanf("%d", &choixJoueur);

        incorrect = choixJoueur < 1 || 5 < choixJoueur;

        if (incorrect)
        {
            printf("Non valide, valeurs de 1 à 5 acceptées\n");
        }

    } while (incorrect);

    return choixJoueur;
}


// Étape 4 - Fonction qui détermine si le joueur 1 gagne
bool joueur1_gagne(int choix1, int choix2)
{
    return (choix1 == 1 && (choix2 == 3 || choix2 == 4))
        || (choix1 == 2 && (choix2 == 1 || choix2 == 5))
        || (choix1 == 3 && (choix2 == 2 || choix2 == 4))
        || (choix1 == 4 && (choix2 == 2 || choix2 == 5))
        || (choix1 == 5 && (choix2 == 1 || choix2 == 3));
}


int main()
{
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (7 Manches / avantage décisif de 2) ===\n");

    while (partie_en_cours(manche, scoreJoueur, scoreOrdi))
    {
        printf("--- Manche %d/7 ---\n", manche);

        choixJoueur = saisie_joueur();

        // Choix aléatoire de l'ordinateur (1, 2, 3, 4 ou 5)
        choixOrdi = (rand() % 5) + 1;

        printf("L'ordinateur a choisi : ");
        afficher_choix(choixOrdi);
        printf("\n");

        // Détermination du gagnant de la manche
        if (choixJoueur == choixOrdi)
        {
            printf("Égalité !\n");
        }
        else if (joueur1_gagne(choixJoueur, choixOrdi))
        {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur = scoreJoueur + 1;
        }
        else
        {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi = scoreOrdi + 1;
        }

        printf("Score actuel -> Vous : %d | Ordi : %d\n\n",
               scoreJoueur, scoreOrdi);

        manche = manche + 1;
    }

    // Bilan de la partie
    afficher_bilan();

    return 0;
}
