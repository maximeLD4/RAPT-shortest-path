#ifndef TRIPS_H
#define TRIPS_H

#include"struct.h"


/**
 *  @brief Remplis list->trips a partir de trips.txt, en lisant le fichier ligne par ligne.
 *         Les infos de la ligne i sont stockées dans la structure list->trips[i], 
 *         a savoir : Le route_id, le trip_id, la direction_id et le service_id.
 */
int fill_struc_trips(FILE ** name,listes * list);

/**
 * @brief fonction qui fprint element par element les list->trips[i]->... infos stockée par "fill_struc_trips"
 *        dans le fichier tripstest.txt du dossier Saves.
 *        Si BOOL=1 !
 */
int write_trips(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list);

/**
 * @brief Ouvre le fichier trips.txt et applique les fonctions :
 *        "fill_struc_trips" et "write_trips".
 *        creer un fichier "tripstest.txt" dans le dossier Save contenant les données extraites
 */
int ftrips(int BOOL,listes * list);

#endif
