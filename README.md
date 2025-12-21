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
Ce programme a été développé à la fois sur Windows 11 et Ubuntu 22.04 LTS à l'aide du logiciel CLion de Jetbrains.\
J'utilise uniquement les librairies de base.\
\
Pour lancer le jeu, il suffit d'exécuter Projet_Morpion.exe qui se trouve dans le dossier cmake-build-debug-windows.
Il y a également un raccourci Windows dans le répertoire principal du projet.

## <a id="p2"></a> II - Explication sur l'organisation du code et choix d'implémentation
- **main.cpp** : fichier C++ principale à exécuter
- **jeu.cpp/.h** : contient TOUTES les fonctions liées au déroulement du jeu : modes de jeu, vérifications, choix de l'IA...
- **Player.cpp/.h** : contient la structure Player ainsi que les fonctions permettant la création d'un joueur.
- **tests.cpp/.h** : contient quelques fonctions qui test le bon fonctionnement des fonctions vérifiant la victoire,
  l'égalité et s'il reste des cases disponibles.

## <a id="p3"></a> III - Fonctionnalités supplémentaires

## <a id="p4"></a> IV - Bilan rapide sur les problèmes rencontrés et solutions trouvées

### Exécuter Projet_Morpion.exe en dehors de CLion
Un miniproblème que j'ai eu : je n'arrivais pas à lancer Projet_Morpion.exe directement en cliquant dessus (sans passer par CLion).\
Explication : il lui manquait une librairie.

<div align="center">
<img height="400" src="readme_src\Screenshot 2025-12-21 174304.png"/>
</div>

La résolution a été assez simple, j'ai demandé à Gemini pour gagner du temps.\
Je tiens à souligner que l'utilisation de l'IA générative dans ce projet, en dehors de ce point, se résume à un rappel de certaines fonctions en C++ (comme transformer un char en string sans que ce soit l'ID ASCII qui soit le string).
\
Il m'a proposé de rajouter dans CMakeLists.txt : `set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")` 