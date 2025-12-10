//
// Created by matthieu on 12/9/25.
//

#ifndef JEU_H
#define JEU_H
#include <iostream>
#include <ostream>
using namespace std;


void draw_game_board(char plateau[9]);

void mode_deux_joueurs();

bool verif_action_possible(string action, char plateau[9]);
bool verif_joueur_gagnant(string action, char plateau[9]);
bool verif_cases_encore_disponible(char plateau[9]);



#endif //JEU_H
