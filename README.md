Matthieu FARANDJIS\
E3 IMAC

<div align="center">
<img height="95"  src="readme_src/esiee-scaled.jpg" title="logo esiee paris"/>

# SAÉ INF3-FI - Cluster Installation

---

<br>
Rapport du projet de TicTacToe "TicTacIMAC"
<br>

</div>

<br><br><br><br><br><br><br>

---

<a id="summary"></a>

## Plan

- ## [I – Indications pour exécuter TicTacImac](#p1)
- ## [II – Explication sur l'organisation du code et choix d'implémentation](#p2)
- ## [III - Fonctionnalités supplémentaires](#p3)
- ## [IV - Bilan rapide sur les problèmes rencontrés et solutions trouvées](#p4)

---

### <a id="p1"></a> I - Indications pour exécuter TicTacImac
Ce programme a été développé à la fois sur Windows 11 et Ubuntu 22.04 LTS à l'aide du logiciel CLion de JetBrains.\
J'utilise uniquement les librairies de base.\
\
Pour lancer le jeu, il suffit d'exécuter **Projet_Morpion.exe** qui se trouve dans le dossier `cmake-build-debug-windows`.\
Il y a également un raccourci Windows dans le répertoire principal du projet.\
\
L'utilisateur est accueilli par un menu ; il lui suffit d'indiquer le mode de jeu souhaité (1, 2 ou 3) à l'aide de son clavier pour que la partie commence.\
Le programme permet à l'utilisateur de saisir son nom ainsi que de choisir un symbole. Le joueur 2 (ou le joueur affrontant l'IA) ne peut pas choisir le même symbole que le joueur 1 (ou celui de l'IA).`\
À la fin de la partie, le jeu indique le vainqueur ou signale s'il y a une égalité. Pour recommencer une partie, il est nécessaire de réexécuter le programme.
## <a id="p2"></a> II - Explication sur l'organisation du code et choix d'implémentation
- **main.cpp** : fichier C++ principal à exécuter.
- **jeu.cpp/.h** : contient TOUTES les fonctions liées au déroulement du jeu : modes de jeu, vérifications, choix de l'IA...
- **Player.cpp/.h** : contient la structure `Player` ainsi que les fonctions permettant la création d'un joueur.
- **tests.cpp/.h** : contient quelques fonctions qui testent le bon fonctionnement des fonctions vérifiant la victoire, l'égalité et la disponibilité des cases.

## <a id="p3"></a> III - Fonctionnalités supplémentaires

J'ai implémenté un mode **IA Avancé** où l'IA va suivre un algorithme déterminant les meilleures actions à effectuer selon moi.\
Il ne remplace pas le mode IA aléatoire ! Ce nouveau mode est disponible via l'option 3 du menu.

## <a id="p4"></a> IV - Bilan rapide sur les problèmes rencontrés et solutions trouvées

### Exécuter Projet_Morpion.exe en dehors de CLion
Un mini-problème que j'ai rencontré : je n'arrivais pas à lancer **Projet_Morpion.exe** directement en cliquant dessus (sans passer par CLion).\
Explication : il lui manquait une librairie.

<div align="center">
<img height="400" src="readme_src\Screenshot 2025-12-21 174304.png"/>
</div>

La résolution a été assez simple, j'ai sollicité Gemini pour gagner du temps.\
Je tiens à souligner que l'utilisation de l'IA générative dans ce projet, en dehors de ce point, s'est résumée à un rappel de certaines fonctions en C++ (comme transformer un `char` en `string` sans que ce soit l'ID ASCII qui soit utilisé).
\
Il m'a proposé d'ajouter dans le fichier `CMakeLists.txt` : `set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")`


### Représenter le plateau de jeu avec une simple liste
L'énoncé suggérait de représenter un plateau de jeu avec une simple liste, et non pas 3 listes de 3 cases dans 1 grande liste.\
J'ai donc représenté le plateau avec une seule liste, ce qui n'a pas été simple pour les fonctions de vérification : je devais calculer manuellement la position de la prochaine case à analyser.\
\
Avec une liste de listes (tableau 2D), les vérifications auraient été beaucoup plus simples !\
Vérifier une colonne ? Aucun souci : il suffit d'analyser la case en position X des trois listes ; si le symbole est identique : c'est gagné.\
Dans mon cas, je devais effectuer des bonds de +3 (0+3 = 3, case juste en dessous de 0) et parfois des +2... Cela ne m'avait pas paru aussi complexe au départ !\
Comme je n'étais pas certain de mes fonctions, j'ai créé des fonctions de test de manière peu rigoureuse, mais qui remplissent néanmoins leur rôle.