#ifndef HASHMAP_GRAPH
#define HASHMAP_GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Une structure représentant une station. C'est un noeud de la table de hachage.
 * 
 * Cette structure contient l'id (la clé), le nom(la valeur), 
 * le nombre de voisins et un tableau contenant l'id des stations voisines.
 * 
 * Le pointeur next pointe sur le prochain noeud de la table et n'a aucun rapport 
 * avec le graphe. Son interêt est du point de vue de la structure.
 */

typedef struct graph_station
{
    void * id; // La clé de la table graph : id de la station
    void * nom; // La valeur de la table graph: le nom de la station
    int * nb_voisins; // Le nombre de voisins de la station , ie: la taille du tableau voisins
    int * voisins; //La liste des stations voisines (au sens du réseau)
    struct graph_station * next; // La liste des noeuds suivants (pour créer la table de hachage)

} graph_station;

/**
 * @brief Une table de hachage qui représente le graphe.
 * 
 * Elle associe la clé (l'id d'une station) avec la valeur correspondante (le nom de la station).
 * 
 * Utiliser les fonctions suivantes pour se servir de la table de hachage.
 */

typedef struct hashmap_graph
{
    unsigned long long size; //La taille de la table 
    size_t id_memsize; // Taille mémoire de la clé id
    size_t nom_memsize; // Taille mémoire de la valeur nom
    unsigned long long (*hash_function)(struct hashmap_graph *, void *); // Fonction de hachage
    int (*comp_function)(void *, void *); // Fonction de comparaison : retourne 1 si les 2 arguments sont égaux
    graph_station **list; // POinteur vers la table

} hashmap_graph;



/**
 * @brief Macro to create a hash map
 *
 * To make this library easy to use, this macro can be used with 5 or 3
 * parameters.
 *
 * @param size: the size of the hash map.
 * @param key_memsize: the memsize of a key.
 * @param val_memsize: the memsize of a value.
 * @param hash_func: the hash function.
 * @param comp_func: the comparaison function.
 */

#define __ITS_GET_MACRO_CREATE_TABLE(_1, _2, _3, _4, _5, NAME, ...) NAME

#define create_table(...)                                                         \
	__ITS_GET_MACRO_CREATE_TABLE(__VA_ARGS__, __CREAT_T5, __CREAT_T4, __CREAT_T3) \
	(__VA_ARGS__)

#define __CREAT_T5(size, key_memsize, val_memsize, hash_func, comp_func) create_table(size, key_memsize, val_memsize, hash_func, comp_func)

#define __CREAT_T4(size, key_memsize, val_memsize, hash_func) create_table(size, key_memsize, val_memsize, hash_func, NULL)

#define __CREAT_T3(size, key_memsize, val_memsize) create_table(size, key_memsize, val_memsize, NULL, NULL)


/**
 * @brief Crée la table de hachage avec les tailles données (a modifier plus tard).
 * 
 * Alloue de la mémoire pour la table et la liste des stations(des noeuds).
 * Initialise les fonctions de comparaison et hachage.
 * Si elles sont NULL, des fonctions par défaut seront utilisées.
 *                                                         
 * @param size: la taille de la table (le nombre de sous listes), plus elle est grande, plus la recherche sera rapide.
 * @param key_memsize: La taille mémoire des id (normalement taille d'un entier).
 * @param val_memsize: La taille mémoire des noms (chaine de caractère de taille à définir).
 * @param hash_function: La fonction de hachage (si NULL, fonction par défaut).
 * @param comp_function: La fonction de comparaison (si NULL, fonction par défaut).
 * 
 * @return Le pointeur de la table de hachage.
 */

hashmap_graph *create_table(unsigned long long size,
	         size_t key_memsize,
	         size_t val_memsize,
	         unsigned long long (*hash_function)(hashmap_graph *, void *),
			 int (*comp_function)(void *, void *));


/**
 * @brief Crée la noeud du graphe correspondant à la station ayant les caractéristiques données en paramètre.
 * 
 * ALloue de la mémoire pour le noeud, la clé (id) et la valeur (nom)
 * 
 * @param graph: Le pointeur sur table ou insérer le noeud.
 * @param key: l'id de la station correspondante.
 * @param val: le nom de la station correspondante.
 * 
 * @return un nombre qui indique si la station a été correctement insérée (0 pour succès et -1 si erreur)
 */
int 
insert(hashmap_graph *graph, void *key, void *val);

/**
 * @brief: Cherche la clé (l'id) dans le graphe et retourne le nom correspondant.
 * 
 * Utilisation: allouer de la mémoire pour la valeur, ie
 * __NE__PAS__FAIRE
 * int* data;
 * lookup(graph,id,data);
 * __FAIRE__
 * int data;
 * lookup(graph,id,&data);
 * 
 * @param graph: Le pointeur sur la table de hachage.
 * @param key: L'id de la station à rechercher.
 * @param value: Le pointeur ou stocker la valeur.
 * 
 * @return un entier qui indique si la fonction a réussi (0 pour un succès, -1 pour une erreur)
 */
int
lookup(hashmap_graph *graph, void *key, void *value);

/**
 * @brief: Supprime la table de hachage en libérant toute la mémoire allouée
 * 
 * @param graph: Le pointeur sur la table de hachage.
 */
void 
delete_hash_map(hashmap_graph *graph);

/**
 * @brief: Supprime un noeud de la table et libère la mémoire allouée.
 * 
 * @param graph: Le pointeur vers la table.
 * @param key: La clé (id) associée au noeud (station) à supprimer.
 */
void
delete_node(hashmap_graph *graph, void *key);

/**
 * @brief: Actualise la liste des voisins de la station d'id id1 en y ajoutant la station d'id id2.
 * 
 * @param graph: Le pointeur vers la table.
 * @param id1: L'id de la station dont il faut actualiser les voisins.
 * @param id2: L'id de la station à insérer dans la liste des voisins.
 * 
 * @return un entier indiquant si la fonction s'est opérée avec succès (0 pour un succès et -1 sinon).
 */
int 
insert_neighbor(hashmap_graph *graph, int id1, int id2);

/**
 * @brief: indique l'indice de la table ou se trouve la station d'id correspondante.
 * Fonction par défaut de la table de hachage.
 * 
 * @param h_map: Le pointeur sur la table de hachage.
 * @param key: L'id de la station (ie la clé du noeud correspondant).
 * @return l'indice de la table ou se trouve la station correspondante.
 */
unsigned long long
__hash_code(hashmap_graph *h_map, void *key);

/**
 * @brief fonction de comparaison par défaut utilisée dans la table si aucune fonction n'est entrée.
 * 
 * @param a: L'adresse de la première valeur à comparer.
 * @param b: L'adresse de la seconde valeur a comparer.
 * 
 * @return un entier qui indique si les deux valeurs sont égales ou différentes
 * (0 si elles sont différentes et 1 si elles sont égales)
 */
int
__comp (void *a, void *b);

#endif