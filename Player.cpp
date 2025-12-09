//
// Created by matthieu on 12/4/25.
//

#include "Player.h"

#include <algorithm>
#include <iostream>
#include <bits/ostream.tcc>


Player createPlayer()
{
    string name = "";
    string nameSansEspace;
    cout << "============== CRÉATION D'UN NOUVEAU JOUEUR ==============" << std::endl;
    do
    {
        cout << "==== VOTRE NOM                       : ";
        getline(cin, name);
        nameSansEspace = name;

        // on efface les espaces et autres caractères invisible
        nameSansEspace.erase(
            remove_if(nameSansEspace.begin(), nameSansEspace.end(),
                      [](unsigned char c) { return isspace(c); }),
            nameSansEspace.end()
        );
    } while (name == "" || nameSansEspace == ""); // tant que le nom indiqué est vide ou n'est composé que d'espaces (donc tant qu'il n'est pas valide)



    string symbol = "";
    string symbolSansEspace;
    do
    {
        cout << "==== VOTRE SYMBOLE (1 caractère max) : ";
        getline(cin, symbol);
        symbolSansEspace = symbol;

        // on efface les espaces et autres caractères invisible
        symbolSansEspace.erase(
            remove_if(symbolSansEspace.begin(), symbolSansEspace.end(),
                      [](unsigned char c) { return isspace(c); }),
            symbolSansEspace.end()
        );
    } while (symbolSansEspace.length() != 1); // tant que le nom indiqué est vide ou n'est composé que d'espaces (donc tant qu'il n'est pas valide)


    Player player;
    player.name = nameSansEspace;
    player.symbol = symbolSansEspace;
    return player;
}
