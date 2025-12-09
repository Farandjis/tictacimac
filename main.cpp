#include <iostream>
#include "Player.h"
#include "jeu.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    // createPlayer();


    char tab[9] = {'x', ' ', ' ', 'o', 'x', ' ', ' ', ' ', 'x'};
    draw_game_board(tab);

    return 0;
}