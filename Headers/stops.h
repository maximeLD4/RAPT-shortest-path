#ifndef STOPS_H
#define STOPS_H

#include"struct.h"

/**
 * @brief fonction qui print element par element les list->stops[i]->... infos stockée par "fill_struc_stops"
 *        dans le fichier stopstest.txt du dossier Saves.
 *        Si BOOL=1 !
 */
int write_stops(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list);

/**
 *  @brief Remplis list->stops a partir de stops.txt, en lisant le fichier ligne par ligne.
 *         Les infos de la ligne i sont stockées dans la structure list->stops[i], 
 *         a savoir : Le stop_id et le sname.
 */
int fill_struc_stops(FILE ** name,listes * list);

/**
 * @brief Ouvre le fichier stops.txt et applique les fonctions :
 *        "fill_struc_stops" et "write_stops".
 *        creer un fichier "stopstest.txt" dans le dossier Save contenant les données extraites
 */
int fstops(int BOOL,listes * list);

#endif