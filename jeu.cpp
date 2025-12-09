//
// Created by matthieu on 12/9/25.
//

#include "jeu.h"

/**
 * Affiche le plateau de jeu à partir des données pris en paramètres.
 * @param tab : Tableau des données à afficher.
 */
void draw_game_board(char tab[9])
{

    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << endl << "| ";
        }

        cout << tab[i] << " | ";
    }

}
