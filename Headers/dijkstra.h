#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<math.h>

#include"create_graph.h"


#define VISITED 2

typedef struct dist_list_node{
    int* id;
    int* dist;
    struct dist_list_node* next;
}dist_node;

typedef struct dist_list{
    dist_node * list;
    int* unvisited;
}dist_list;


/**
 * @brief Une fonction qui met à jour la liste des distances 
 *        avec le nouveau sommet passé en argument
 * 
 * @param distances : la liste des sommets triée par distance croissante
 * @param id: l'id de la station a actualiser
 * @param dist: la distance de la station renvoyée par l'algo
 * 
 * @return Un entier indiquant si la fonction a réussi (-1 si erreur, 0 sinon)
 */
int update_dist(dist_list* distances,int id,int dist);

/**
 * @brief Renvoie la distance actuelle d'un sommet au point de départ de DIjkstra
 * 
 * @param distances : le pointeur sur la liste des distances
 * @param id : un entier representant l'id de la station à chercher
 * 
 * @return Un entier valant : -1 si erreur, sinon la distance recherchée
 */
int find_dist(dist_list* distances,int id);

/**
 * @brief Renvoie le noeud non visité par DIjkstra ayant la distance minimale.
 * @param distances : le pointeur sur la liste des distances
 * @param list_first_node : Pointeur sur une liste représentant le graphe
 * @return un pointeur sur le noeud de distance minimale
 */
node* get_min_dist(dist_list* distances,node ** list_first_node);

/**
 * @brief  LIbère toute la mémoire allouée pour stocker la liste des distances
 * @param distances : le pointeur sur la liste des distances
 * @return void
 */
void free_dist(dist_list * distances);

/**
 * @brief
 * @param list_first_node Pointeur sur une liste représentant le graphe
 * @param depart_id L'id du sommet de départ
 * @param arrive_id L'id du sommet d'arrivée
 * @return un entier indiquant si la fonction s'est correctement effectuée (0 si succès, -1 si erreur)
 */
int dijkstra(node ** list_first_node, int depart_id, int arrive_id );


#endif