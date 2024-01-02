# RATP_PROJET_TPS-1A_HUGO_MAXIME

L’objectif de ce projet est d’implémenter un algorithme de calcul de plus court chemin pour un réseau de transport public. Pour cela on a un accès libre à des fichiers dit GTFS sur le site de la RATP. Nous allons implémenter nos algorithmes en langages C (et Bash).

## “make clean”
Permet de supprimer les fichier.o du répertoir “Obj”, la commande “make Define_Nbr” permet de creer le fichier “Define_Nbr.h” dans le répertoire “Headers”. Et enfin la commande “make” permet de compiler le projet. Ainsi la suite d’instructions suivant permet d’utiliser le projet :
- make clean
- make Define_Nbr
- make
- 
Puis il faut aller dans le fichier “Sources” et exécuter le main avec les options désirées . (Attention : des erreurs de types proviennent de la Hashmap lors de la compilation, mais cela ne gène pas l’avancé des choses)
