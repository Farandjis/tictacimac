#include <iostream>
#include "Player.h"
#include "jeu.h"
#include "tests.h"

int main()
{
    /*
    std::cout << "Hello, World!" << std::endl;
    // createPlayer("x"); // ça marche pas on peut lui dire x il s'en moque AAAAH


    char tab[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    draw_game_board(tab);
    */

    mode_deux_joueurs();
    // tests_verif_action_possible();
    // tests_verif_joueur_gagnant();
    // test_verif_cases_encore_disponible();
    return 0;
}