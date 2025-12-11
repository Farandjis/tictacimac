//
// Created by Matthieu on 10/12/2025.
//


#include "jeu.h"

void tests_verif_action_possible() {
    cout << "tests_verif_action_possible =======" << endl;
    int numeroTests = 1;
    char plateau[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 1; i < 10; i++) {
        if (!verif_action_possible(std::to_string(i), plateau)) {
            // est ce que pour cet valeur de i (1 à 9) on peut placer le jeton sur le plateau ?
            // ---> Réponse attendu : true, car le plateau n'a aucun jeton peu importe la case.
            // si false, alors erreur
            cout << "ECHEC TEST " << numeroTests << endl;
        }
        numeroTests++;
    }

    // test 10
    numeroTests++;
    plateau[0] = 'x';
    if (!verif_action_possible("1", plateau)) {
        cout << "ECHEC TEST " << numeroTests << endl; // réponse attendu : false, car il y a un jeton case 1
    }

    //test 11
    numeroTests++;
    plateau[5] = 't';
    if (!verif_action_possible("6", plateau)) {
        cout << "ECHEC TEST " << numeroTests << endl; // réponse attendu : false, car il y a un jeton case 6
    }

    // test 12
    numeroTests++;
    if (!verif_action_possible("5", plateau)) {
        cout << "ECHEC TEST " << numeroTests << endl; // réponse attendu : true, car il y n'a pas de jeton case 5
    }

    cout << "fin des tests" << endl;
}
