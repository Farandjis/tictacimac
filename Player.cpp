//
// Created by matthieu on 12/4/25.
//

#include "Player.h"

#include <algorithm>
#include <iostream>
#include <bits/ostream.tcc>

/**
 * Créer un objet joueur en demandant à l'utilisateur des informations.
 * @param symbolBanni : (optionnel) permet d'empêcher l'utilisateur d'utiliser le symbol partagé
 * @return le joueur qui vient d'être créé
 */
Player createPlayer(string symbolBanni)
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
        if (symbolSansEspace == symbolBanni && symbolBanni != "")
        {
            cout << "Vous ne pouvez pas utiliser le caractère " << symbolBanni << endl;
        }
        cout << "==== VOTRE SYMBOLE (1 caractère max) : ";
        getline(cin, symbol);
        symbolSansEspace = symbol;

        // on efface les espaces et autres caractères invisible
        symbolSansEspace.erase(
            remove_if(symbolSansEspace.begin(), symbolSansEspace.end(),
                      [](unsigned char c) { return isspace(c); }),
            symbolSansEspace.end());


    } while (symbolSansEspace.length() != 1 || symbolSansEspace == symbolBanni); // tant que le nom indiqué est vide ou n'est composé que d'espaces (donc tant qu'il n'est pas valide)

    cout << "==========================================================" << std::endl;

    Player player;
    player.name = nameSansEspace;
    player.symbol = symbolSansEspace;
    return player;
}

/**
 * Créer un joueur directement à l'aide des paramètres reçus
 * @param nom : nom du joueur
 * @param symbol : symbol du joueur
 * @return le joueur créé
 */
Player creerDirectementUnJoueur(string nom, string symbol) {
    Player player;
    player.name = nom;
    player.symbol = symbol;
    return player;
}