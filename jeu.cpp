//
// Created by matthieu on 12/9/25.
//

#include "jeu.h"

#include <algorithm>
#include <vector>

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

vector<char> getCasesDisponibles(char plateau[9]) {
    vector<char> casesDisponibles;
    for (int i = 0; i < 9; i++)
    {
        if (plateau[i] >= '1' && plateau[i] <= '9')
        {
            casesDisponibles.push_back(plateau[i]);
        }
    }

    return casesDisponibles;
}


/**
 * Tire un nombre aléatoire entre 0 et le nombre de case dispo, puis renvoi la chiffre associé à la case choisit.
 * @param plateau : plateau de jeu actualisé
 * @return un string qui, si c'était un humain, équivaut à la réponse à la fonction C++ cin.
 */
string choixIAAuxHasard(char plateau[9]) {
    srand((unsigned int)time(0)); // initialisation de la série aléatoire
    vector<char> casesDisponibles = getCasesDisponibles(plateau);

    int idCaseChoisit = rand() % (casesDisponibles.size()); // tirage d'un nombre entre 0 et la taille du tableau casesDisponibles

    return to_string(casesDisponibles[idCaseChoisit]  - '0'); // le -'0' permet de convertir en entier (qu'on renvoi comme string car on manipule des string dans la suite du prog)
}



string choixIAAvancé(char plateau[9], Player ia, Player humain) {


    if (plateau[4] == '5') {
        return "5"; // en tant que joueur, la première case je tente de prendre coûte que coûte c'est la 5, donc mon IA doit faire ça.
    }


    vector<char> casesDisponibles = getCasesDisponibles(plateau); // les cases disponibles
    char plateauCopie[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // note : les ' ' seront écrasé juste après)
    std::copy(plateau, plateau + 9, plateauCopie); // on réinitialise plateauCopie par les valeurs du vrai plateau

    // On va regarder si on peut gagner ce tour ci (si oui, on prend la case nous garantissant la victoire)
    for (int i = 0; i < casesDisponibles.size(); i++) {
        int idCaseARegarder = casesDisponibles[i] - '0' - 1; // -'0' pour convertir en entier, et -1 car l'index de la liste commence à 0
        plateauCopie[idCaseARegarder] = ia.symbol[0]; // on place le symbol de l'IA

        bool peutGagner = verif_joueur_gagnant(plateauCopie); // on regarde si en plaçant le symbol à cet endroit, on gagne
        if (peutGagner) {
            return to_string(casesDisponibles[i] - '0'); // on renvoi la case si elle mène à la victoire
        }

        // on reset afin de préparer le prochain test
        std::copy(plateau, plateau + 9, plateauCopie); // on réinitialise plateauCopie par les valeurs du vrai plateau
    }



    // On va maintenant regarder si l'adversaire peut gagner (si oui, on va prendre la case qu'il espère)
    for (int i = 0; i < casesDisponibles.size(); i++) {
        int idCaseARegarder = casesDisponibles[i] - '0' - 1; // -'0' pour convertir en entier, et -1 car l'index de la liste commence à 0
        plateauCopie[idCaseARegarder] = humain.symbol[0]; // on place le symbol de l'adversaire

        bool peutGagner = verif_joueur_gagnant(plateauCopie); // on regarde si en plaçant le symbol à cet endroit, il gagne
        if (peutGagner) {
            return to_string(casesDisponibles[i] - '0'); // on renvoi la case si elle mène à sa victoire (on lui la prend)
        }

        // on reset afin de préparer le prochain test
        std::copy(plateau, plateau + 9, plateauCopie); // on réinitialise plateauCopie par les valeurs du vrai plateau
    }


    // si on est ici : c'est que personne ne peut gagner dans l'état présent.
    // dans ce cas, on va prendre une autre place stratégique que la case 5 : un angle.
    // on tire au hasard un angle.

    string idCoins[4] = {"1", "3", "7", "9"};
    srand((unsigned int)time(0)); // initialisation de la série aléatoire
    int idCaseChoisit = rand() % 4; // tirage d'un nombre entre 0 et 3 compris

    // on va tester tous les angles. On commencera par l'angle qui a été tiré au sort. Si disponible, on le prend, sinon, on prend le suivant.
    // C'est une boucle for qui itère 4 fois afin de tester les 4 angles. Si on a rien renvoyé à la fin de la quatrième itération, on considère que tous les angles sont pris.
    for (int i = 0; i < 4; i++) {


        if (verif_action_possible(idCoins[idCaseChoisit], plateau)) {
            return idCoins[idCaseChoisit]; // cet angle est libre, on le prend
        }

        idCaseChoisit = (idCaseChoisit+1) % 4; // l'angle privilégié n'est pas disponible, on prend l'angle suivant
    }

    return choixIAAuxHasard(plateau); // si on est ici, c'est qu'on a aucun choix évident à effectuer -> on tire au hasard
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
 *
 * Il est important de noter que les variables "nbDeFoisMemeValeurCase" compte la première case elle-même,
 * donc même si elle est initialisée à 0, elle passera toujours à 1. Elle passera à 2 si deux mêmes caractères sont côte à côte, et 3 si 3 caractères sont alignés.
 *
 * @param action : case où le jeton vient d'être placé
  * @param plateau : plateau de jeu précédemment actualisé
 * @return true s'il a gagné
 */
bool verif_joueur_gagnant(char plateau[9]){

    // VÉRIFICATION A LA VERTICALE =====================
    for (int i = 0; i < 3; i++)
    {
        char valeurCaseToutEnHaut = plateau[i];
        int nbDeFoisMemeValeurCase = 0;
        // (valeurCaseToutEnHaut - '0') pour récupérer le caractère  et non la valeur ASCII du caractère
        for (int j = i; j < 9; j += 3)
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
    for (int i = 0; i < 9; i += 3)
    {
        char valeurCaseTouteAGauche = plateau[i];
        int nbDeFoisMemeValeurCase = 0;
        // (valeurCaseToutEnHaut - '0') pour récupérer le caractère  et non la valeur ASCII du caractère
        for (int j = i ; j <= i+2; j++)
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



    // VERIFICATION A LA DIAGONALE (bas gauche - haut droite) =====================
    char valeurCaseTouteEnBasAGauche = plateau[6];
    int nbDeFoisMemeValeurCase = 0;
    for (int i = 6; i > 0; i -= 2)
    {
        // (valeurCaseToutEnHaut - '0') pour récupérer le caractère  et non la valeur ASCII du caractère
        if (valeurCaseTouteEnBasAGauche == plateau[i])
        {
            nbDeFoisMemeValeurCase++; // si c'est la même valeur que tout à gauche
        }
    }
    if (nbDeFoisMemeValeurCase == 3)
    {
        return true; // on a 3x la même valeur à la vertical -> donc 3x le même jeton -> donc le joueur a gagné
    }

    // VERIFICATION A LA DIAGONALE (haut gauche - bas droit) =====================
    char valeurCaseTouteEnHautAGauche = plateau[0];
    nbDeFoisMemeValeurCase = 0;
    for (int i = 0; i < 9; i += 4)
    {
        // (valeurCaseToutEnHaut - '0') pour récupérer le caractère  et non la valeur ASCII du caractère
        if (valeurCaseTouteEnHautAGauche == plateau[i])
        {
            nbDeFoisMemeValeurCase++; // si c'est la même valeur que tout à gauche
        }
    }
    if (nbDeFoisMemeValeurCase == 3)
    {
        return true; // on a 3x la même valeur à la vertical -> donc 3x le même jeton -> donc le joueur a gagné
    }

    return false;
}

/**
 * Vérifie si la partie peut se poursuivre, ou bien s'il n'y a plus de place disponible.
 * Pour savoir s'il reste une place de disponible, c'est sympa : si la valeur de la case est un chiffre : elle est vide !
 * Rappel : l'utilisateur ne peut pas choisir un chiffre comme symbol.
 * @param plateau : plateau de jeu précédemment actualisé
 * @return true si la partie peut se poursuivre (toutes les cases ne sont pas occupés)
 */
bool verif_cases_encore_disponible(char plateau[9]){
    for (int i = 0; i < 9; i++)
    {
        if (plateau[i] >= '1' && plateau[i] <= '9')
        {
            return true; // une case vide a été trouvé
        }
    }

    return false; // si on arrive là, c'est qu'aucune case vide n'a été trouvé
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
void mode_deux_joueurs(bool modeIA)
{

    // INITIALISATION ===========================================================
    Player joueur1;
    if (modeIA) {
        joueur1 = creerDirectementUnJoueur("IA", "A"); // création du joueur 1 IA
    }
    else {
        joueur1 = createPlayer(); // création du joueur 1 humain
    }
    Player joueur2 = createPlayer(joueur1.symbol); // création du joueur 2 humain dont on interdit le choix du caractère du joueur 1


    // Player joueur2 = creerDirectementUnJoueur("titi", "i"); // pour moi
    Player joueurs[2] = {joueur1, joueur2};

    cout << endl << "Bienvenue " << joueur1.name << " (" << joueur1.symbol << ")" << "  et  " << joueur2.name << " (" << joueur2.symbol << ") ! " << endl;
    cout << "Voici le plateau de jeu de morpion." << endl << "Chacun votre tour, vous sélectionnerez une case libre en indiquant son numéro. Aucun retour en arrière n'est possible." << endl << "Le numéro est remplacé par le symbole du joueur qui a sélectionné la case." << endl;

    char plateau[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // source : https://blog.alphorm.com/les-fonctions-aleatoires-en-c-11
    srand((unsigned int)time(0)); // initialisation de la série aléatoire
    int tirage = rand()%2; // tirage d'un nombre entre 0 et 1
    cout << endl << endl;
    cout << "Par tirage aléatoire, le joueur " << joueurs[tirage].name << " est invité à commencer la partie." << endl;



    int quiJoue = tirage;
    // PARTIE
    do {
        Player leJoueurQuiJoue = (quiJoue == 0) ? joueur1 : joueur2;

        cout << endl << endl << "============================= " << "TOUR " << leJoueurQuiJoue.name << " (" << leJoueurQuiJoue.symbol << ") =============================";
        cout << endl;

        string reponse = "";
        do
        {

            // ETAPE 1
            draw_game_board(plateau);
            cout << endl;

            // ETAPE 2
            if (reponse != "")
            {
                cout << "Réponse invalide. Choisissez une valeur parmis : ";
                for (int i = 0; i < 9; i++)
                {
                    if (plateau[i] >= '1' && plateau[i] <= '9')
                    {
                        cout << plateau[i] << " ";
                    }
                }
                cout << endl;
            }

            if (modeIA && quiJoue == 0) {
                // si le mode IA est actif et que c'est le tour du joueur 1 (note : l'IA est joeuur 1)
                // reponse = choixIAAuxHasard(plateau);
                reponse = choixIAAvancé(plateau, joueur1, joueur2);
                cout << ">> L'IA a choisit : " << reponse << endl;
            }
            else {
                cout << "Joueur " << leJoueurQuiJoue.name << " quel case choisissez vous ?" << endl << ">> ";
                getline(cin, reponse);
            }
        } while (!verif_action_possible(reponse, plateau)); // ETAPE 3

        // ETAPE 4
        plateau[reponse[0] - '0' - 1] = leJoueurQuiJoue.symbol[0];

        // ETAPE 5
        if (verif_joueur_gagnant(plateau))
        {
            // écrit de tête donc à revoir
            cout << "\n\n\n\n\n\n";
            cout << "FELICITATION " << leJoueurQuiJoue.name << " (" << leJoueurQuiJoue.symbol <<  ") A GAGNÉ(E) !!!!!!! " << endl;
            break;
        }

        // ETAPE 5
        if (!verif_cases_encore_disponible(plateau))
        {
            // écrit de tête donc à revoir
            cout << "\n\n\n\n\n\n";
            cout << "Il n'y a plus de place sur le plateau... Vous êtes tous les deux à égalité." << endl;
            break;
        }


        // ETAPE 7
        quiJoue = (quiJoue+1) % 2;
    } while (true);
}




void menu()
{
    cout << "==========================" << "BIENVENUE DANS TIC TAC IMAC" << "==========================" << endl;
    cout << "Choissez un mode de jeu en répondant par la valeur associée :" << endl;
    cout << "   1. Mode deux joueurs" << endl;
    cout << "   2. Mode contre IA" << endl;
    cout << "===============================================================================" << endl;

    string reponse = "";
    string reponseSansEspace;
    do {
        if (reponse != "") {
            cout << "Votre réponse n'est pas valide, veuillez indiquer le chiffre associé à l'option voulu" << endl;
        }
        cout << "Votre choix : >> ";
        getline(cin, reponse);

        reponseSansEspace = reponse;

        // on efface les espaces et autres caractères invisible
        reponseSansEspace.erase(
            remove_if(reponseSansEspace.begin(), reponseSansEspace.end(),
                      [](unsigned char c) { return isspace(c); }),
            reponseSansEspace.end()
            );

        cout << reponseSansEspace << endl;
    } while (reponseSansEspace.empty() || (reponseSansEspace[0] != '1' && reponseSansEspace[0] != '2'));


    // MODE DEUX JOUEURS
    if (reponseSansEspace[0] == '1') {
        mode_deux_joueurs();
    }

    // MODE IA
    else if (reponseSansEspace[0] == '2') {
        mode_deux_joueurs(true); // true car IA
    }
}
