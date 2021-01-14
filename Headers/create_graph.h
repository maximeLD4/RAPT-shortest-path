#ifndef CREAT_GRAPH_H
#define CREAT_GRAPH_H

#include"struct_nodes.h"
#include"routes.h"
#include"stops.h"
#include"stop_times.h"
#include"trips.h"
#include"transfers.h"
#include"calendar_dates.h"
#include"calendar.h"



/**
 * @brief Alloue de la mémoire pour la structure list et ses composants: les listes
 *        de structures station_t, et leurs str.
 */
listes * callocLesTableaux(void);

/**
 * @brief Cherche dans list->routes la premiere station du nom de la station de départ que l'on cherche
 *        et renvois son route_id.
 */
int cherche_route_id(int nbr_routes, char * Station_Depart, listes * list);

/**
 * @brief Cherche dans list->trip le premier trip_id de même route_id que le rout_id1 et
 *        le renvois .
 */
long int cherche_trip_id(int nbr_trips, int route_id1, listes * list);

/**
 * @brief Cherche l'indice du premier stop_time de list->stop_time dont le trip_id est celui en argument.
 *        et renvois cet indice.
 */
int cherche_indice_stop_times(int nbr_stop_times, long int trip_id, listes * list,int heure_depart_debut);

/**
 * @brief remplis une ligne de nodes, telle qu'elle apparait dans stop_time
 *        C'est a dire: creer un graphprime pour une ligne (de metro par exemple)
 */
void fill_graph(node * first_node,int nbr_stop,int indice, listes * list);

/**
 * @brief A partir d'un "first node", print le graph (obsolete par rapport a Write_graph).
 */
void print_graph(node * first_node, int BOOL);

/**
 * @brief A partir d'un "first node", print le graph dans un fichier txt (ResultatGraph.txt).
 *        Il n'apparait pas dans sa totalité mais on peut y voir chaque ligne et les stations "transfert"
 *        qui permettent de passer de lignes en lignes.
 */
void write_graph(node * first_node, int BOOL,FILE * fichiertxt);

/**
 * @brief free chacun des tableaux de station_t dans list-> ... et leurs chaines de caractere et free list.
 */
void freeLesTableaux(listes * list);

/**
 * @brief Permet a partir des differents graphprimes de chaques lignes, et de la liste de leurs first_node: "Liste1"
 *        de construire les noeuds de transfers entre chaques lignes. et ainsi de completer nos graphprimes et un GRAPH final.
 */
int graph_transfers(node * * Liste1, listes * list);

/**
 * @brief Fonction finale qui permet d'extraire les données des fichiers gtfs et de creer le graph associé.
 *        renvois la liste des first nodes (cad les premier nodes de chaques lignes)
 */
node * * graph(int BOOL,main_args * struct_arguments, int heure_depart_debut);

/**
 * @brief permet d'effectuer des tests sur les Listes de stations.. (purement experimental) 
 */
int test(int BOOL);
 
#endif
