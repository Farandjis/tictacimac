//
// Created by matthieu on 12/9/25.
//

#include "jeu.h"

#include "Player.h"

/**
 * Affiche le plateau de jeu à partir des données pris en paramètres.
 * @param plateau : Tableau des données à afficher.
 */
void draw_game_board(char plateau[9])
{

    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << endl << "| ";
        }

        cout << plateau[i] << " | ";
    }

}


/**
 * Vérifie si l'action demandée par le joueur (càd placer à tel endroit son jeton) est possible.
 * @param action : case demandé (en tout cas, ce qu'a écrit le joueur)
 * @param plateau : plateau de jeu précédemment actualisé
 * @return true si possible, false sinon
 */
bool verif_action_possible(string action, char plateau[9]) {
    if (action.length() != 1 || action[0] < '1' || action[0] > '9' ) {
        // si l'entrée fait plus d'1 caractère OU que la valeur n'est pas un chiffre compris entre 1 et 9
        return false;
    }

    int numeroCase = stoi(&action[0]) - 1;
    string valeurDansLaCase = string(1, plateau[numeroCase]); // on converti la valeur char (plateau[numeroCase]) en string
    bool estValide = valeurDansLaCase == action;
    return estValide; // true si la case associé au numéro de case, correspod
}

/**
 * Vérifie si le joueur dont c'est le tour vient de gagner
 *
 * 0  1  2
 * 3  4  5
 * 6  7  8
 *
 * Si on parcourt à la verticale, on part du numéro case en hayt et on fait +3 pour passer à celle juste en dessous
 * Si on parcourt à l'horizontal, on part du numéro case à droite et on fait +1 pour passer à celle juste à droite
 * Diagonale haut gauche -> bas droite : +4
 * Diagonale haut droite -> bas gauche : +2
 * @param action : case où le jeton vient d'être placé
  * @param plateau : plateau de jeu précédemment actualisé
 * @return true s'il a gagné
 */
bool verif_joueur_gagnant(char plateau[9]){

    // VÉRIFICATION A LA VERTICALE =====================
    for (int i = 0; i < 3; i++)
    {
        char valeurCaseToutEnHaut = plateau[i];
        int nbDeFoisMemeValeurCase = 1;
        // (valeurCaseToutEnHaut - '0') pour récupérer le caractère  et non la valeur ASCII du caractère
        for (int j = i + 3; j < 9; j += 3)
        {
            if (valeurCaseToutEnHaut == plateau[j])
            {
                nbDeFoisMemeValeurCase++; // si c'est la même valeur que tout en haut
            }
        }

        if (nbDeFoisMemeValeurCase == 3)
        {
            return true; // on a 3x la même valeur à la vertical -> donc 3x le même jeton -> donc le joueur a gagné
        }
    }


    // VERIFICATION A L'HORIZONTAL =====================
    for (int i = 1; i < 9; i += 3)
    {
        char valeurCaseTouteAGauche = plateau[i];
        int nbDeFoisMemeValeurCase = 1;
        // (valeurCaseToutEnHaut - '0') pour récupérer le caractère  et non la valeur ASCII du caractère
        for (int j = i ; j < i+2; j++)
        {
            if (valeurCaseTouteAGauche == plateau[j])
            {
                nbDeFoisMemeValeurCase++; // si c'est la même valeur que tout à gauche
            }
        }

        if (nbDeFoisMemeValeurCase == 3)
        {
            return true; // on a 3x la même valeur à la vertical -> donc 3x le même jeton -> donc le joueur a gagné
        }
    }

    return false;




    // vérification à la diagonale (bas gauche - haut droit)
    // vérification à la diagonale (bas droit - haut gauche)
}

/**
 * Vérifie si la partie peut se poursuivre, ou bien s'il n'y a plus de place disponible.
 * @param plateau : plateau de jeu précédemment actualisé
 * @return true si la partie peut se poursuivre (toutes les cases ne sont pas occupés)
 */
bool verif_cases_encore_disponible(char plateau[9]){

}


/*+
 * Principe :
 *  Exécution du mode 1vs1
 *  Le mode créé les joueurs, explique et montre un plateau.
 *  Le jeu commence.
 *  1. Il affiche le plateau
 *  2. il demande au joueur X de placer son jeton
 *  3. il vérifie que sa réponse est valable (valeur correspondant à une case libre)
 *  4. Il modifie la liste pour y indiquer le symbole du joueur
 *  5. Il exécute une fonction pour vérifier si le joueur ne vient pas de gagner.
 *  6. Il vérifie s'il reste une case libre
 *  7. Il passe au joueur suivant
 */
void mode_deux_joueurs()
{

    // INITIALISATION ===========================================================
    // Player joueur1 = createPlayer();
    // Player joueur2 = createPlayer(joueur1.symbol);

    Player joueur1 = asuppr("toto", "o");
    Player joueur2 = asuppr("titi", "i");
    Player joueurs[2] = {joueur1, joueur2};

    cout << endl << "Bienvenue " << joueur1.name << " (" << joueur1.symbol << ")" << "  et  " << joueur2.name << " (" << joueur2.symbol << ") ! " << endl;
    cout << "Voici le plateau de jeu de morpion." << endl << "Chacun votre tour, vous sélectionnerez une case libre en indiquant son numéro. Aucun retour en arrière n'est possible." << endl << "Le numéro est remplacé par le symbole du joueur qui a sélectionné la case." << endl;

    char plateau[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // source : https://blog.alphorm.com/les-fonctions-aleatoires-en-c-11
    srand((unsigned int)time(0)); // initialisation de la série aléatoire
    int tirage = rand()%2; // tirage d'un nombre entre 0 et 1
    cout << endl << endl;
    cout << "Par tirage aléatoire, le joueur " << tirage + 1 << " est invité à commencer la partie." << endl;

    int quiJoue = tirage;
    bool continuer = true;
    // PARTIE
    do {
        cout << endl << endl << "============================= " << "TOUR JOUEUR " << quiJoue + 1 << " =============================";
        draw_game_board(plateau);
        cout << endl;
        cout << "Joueur " << quiJoue + 1 << " quel case choisissez vous ?" << endl << ">>";

    } while (continuer);
}


