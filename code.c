#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void afficher_bilan(int scoreJoueur, int scoreOrdi)
{
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous : %d | Ordi : %d\n", scoreJoueur, scoreOrdi);
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

void afficher_choix(int choix)
{
    switch (choix)
    {
        case 1: printf("Pierre"); break;
        case 2: printf("Feuille"); break;
        case 3: printf("Ciseaux"); break;
        case 4: printf("Lézard"); break;
        case 5: printf("Spock"); break;
        default: printf("Inconnu"); break;
    }
}

bool partie_en_cours(int manche, int scoreJoueur, int scoreOrdi)
{
    return (manche <= 7 && 
            (scoreJoueur - scoreOrdi < 2) && 
            (scoreOrdi - scoreJoueur < 2));
}

int saisie_joueur(void)
{
    int choixJoueur;
    bool incorrect;

    printf("Choix (");
    for (int i = 1; i <= 5; i++)
    {
        printf("%d = ", i);
        afficher_choix(i);
        if (i < 5)
        {
            printf(", ");
        }
    }
    printf(") :");

    do
    {
        scanf("%d", &choixJoueur);
        incorrect = (choixJoueur < 1 || 5 < choixJoueur);
        if (incorrect)
        {
            printf("Non valide, valeurs de 1 à 5 acceptées\n");
        }
    } while (incorrect);

    return choixJoueur;
}

bool joueur1_gagne(int c1, int c2)
{
    return ((c1 == 1 && (c2 == 3 || c2 == 4)) ||
            (c1 == 2 && (c2 == 1 || c2 == 5)) ||
            (c1 == 3 && (c2 == 2 || c2 == 4)) ||
            (c1 == 4 && (c2 == 2 || c2 == 5)) ||
            (c1 == 5 && (c2 == 1 || c2 == 3)));
}

int main(void)
{
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    printf("=== PIERRE, FEUILLE, CISEAUX, LEZARD, SPOCK (7 Manches / avantage décisif de 2) ===\n");

    while (partie_en_cours(manche, scoreJoueur, scoreOrdi))
    {
        printf("--- Manche %d/7 ---\n", manche);

        choixJoueur = saisie_joueur();
    }
}