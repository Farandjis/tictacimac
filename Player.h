//
// Created by matthieu on 12/4/25.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;


struct Player
{
    string name;
    string symbol;
};

Player createPlayer(string symbolBanni = "");
Player creerDirectementUnJoueur(string nom, string symbol);



#endif //PLAYER_H
