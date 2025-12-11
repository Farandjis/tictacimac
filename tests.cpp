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
    if (verif_action_possible("1", plateau)) {
        cout << "ECHEC TEST " << numeroTests << endl; // réponse attendu : false, car il y a un jeton case 1
    }

    //test 11
    numeroTests++;
    plateau[5] = 't';
    if (verif_action_possible("6", plateau)) {
        cout << "ECHEC TEST " << numeroTests << endl; // réponse attendu : false, car il y a un jeton case 6
    }

    // test 12
    numeroTests++;
    if (!verif_action_possible("5", plateau)) {
        cout << "ECHEC TEST " << numeroTests << endl; // réponse attendu : true, car il y n'a pas de jeton case 5
    }

    cout << "fin des tests ====================" << endl;
}



void tests_verif_joueur_gagnant()
{

    char parDefaut[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char plateau[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int numeroTests = 1;

    cout << "tests_verif_joueur_gagnant =======" << endl;
    // TEST PLATEAU VIDE
    if (verif_joueur_gagnant(plateau)) {
        cout << "ECHEC TEST 1 " << endl; // réponse attendu : false, car il n'y a aucun jeton
    }

    // TEST VERIF PLATEAU EN VERTICAL
    cout << "- test verif plateau en vertical" << endl;
    // 1°) cases 1 4 7
    int nbTour = 0;
    for (int i = 0; i < 9; i = i + 3)
    {
        plateau[i] = 'x';

        if (nbTour < 2 && verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 2-1-a " << endl; // réponse attendu : false, car il n'y a pas 3 jeton

        }
        else if (nbTour == 2 && !verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 2-1-b " << endl; // réponse attendu : true, car il y a pas 3 même jeton

        }
        nbTour++;
    }

    // on réinitialise le plateau par les valeurs par défaut.
    std::copy(parDefaut, parDefaut + 9, plateau);

    // 2°) cases 2 5 8
    nbTour = 0;
    for (int i = 1; i < 9; i = i + 3)
    {
        plateau[i] = 'x';

        if (nbTour < 2 && verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 2-2-a " << endl; // réponse attendu : false, car il n'y a pas 3 jeton

        }
        else if (nbTour == 2 && !verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 2-2-b " << endl; // réponse attendu : true, car il y a pas 3 même jeton

        }
        nbTour++;
    }

    // on réinitialise le plateau par les valeurs par défaut.
    std::copy(parDefaut, parDefaut + 9, plateau);

    // 2°) cases 3 6 9
    nbTour = 0;
    for (int i = 2; i < 9; i = i + 3)
    {
        plateau[i] = 'x';

        if (nbTour < 2 && verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 2-3-a " << endl; // réponse attendu : false, car il n'y a pas 3 jeton

        }
        else if (nbTour == 2 && !verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 2-3-b " << endl; // réponse attendu : true, car il y a pas 3 même jeton

        }
        nbTour++;
    }


    // on réinitialise le plateau par les valeurs par défaut.
    std::copy(parDefaut, parDefaut + 9, plateau);

    // TEST VERIF PLATEAU EN HORIZONTAL
    cout << "- test verif plateau en horizontal" << endl;
    // 1°) cases 1 2 3
    nbTour = 0;
    for (int i = 0; i < 3; i++)
    {
        plateau[i] = 'x';

        if (nbTour < 2 && verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 3-1-a " << endl; // réponse attendu : false, car il n'y a pas 3 jeton

        }
        else if (nbTour == 2 && !verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 3-1-b " << endl; // réponse attendu : true, car il y a pas 3 même jeton

        }
        nbTour++;
    }

    // on réinitialise le plateau par les valeurs par défaut.
    std::copy(parDefaut, parDefaut + 9, plateau);

    // 2°) cases suite
    nbTour = 0;
    for (int i = 3; i < 6; i++)
    {
        plateau[i] = 'x';

        if (nbTour < 2 && verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 3-2-a " << endl; // réponse attendu : false, car il n'y a pas 3 jeton

        }
        else if (nbTour == 2 && !verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 3-2-b " << endl; // réponse attendu : true, car il y a pas 3 même jeton

        }
        nbTour++;
    }


    // on réinitialise le plateau par les valeurs par défaut.
    std::copy(parDefaut, parDefaut + 9, plateau);

    // 2°) cases suite
    nbTour = 0;
    for (int i = 6; i < 9; i++)
    {
        plateau[i] = 'x';

        if (nbTour < 2 && verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 3-3-a " << endl; // réponse attendu : false, car il n'y a pas 3 jeton

        }
        else if (nbTour == 2 && !verif_joueur_gagnant(plateau))
        {
            cout << "ECHEC TEST 3-3-b " << endl; // réponse attendu : true, car il y a pas 3 même jeton

        }
        nbTour++;
    }



    cout << "fin des tests ====================" << endl;

}