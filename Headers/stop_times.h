#ifndef STOP_TIMES_H
#define STOP_TIMES_H


#include"struct.h"


/**
 * @brief fonction qui fprint element par element les list->stop_times[i]->... infos stockée par "fill_struc_stop_time"
 *        dans le fichier stoptimestest.txt dans le dossier Saves.
 *        Si BOOL=1 !
 */
int write_stop_time(int nombredeligne,char * fonctionExtractrice, int * BOOL, listes * list);

/**
 * @brief convertis une heure en str au formet "hh:mm:ss", en secondes int.
 */
int heure_en_seconde(char * heure);

/**
 *  @brief Remplis list->stop_times a partir de stop_times.txt, en lisant le fichier ligne par ligne.
 *         Les infos de la ligne i sont stockées dans la structure list->stop_times[i], 
 *         a savoir : Le stop_id, la stop_sequence, l'heure_arrive et heure_depart.
 */
int fill_struc_stop_time(FILE ** name,listes * list);

/**
 * @brief Ouvre le fichier stop_times.txt et applique les fonctions :
 *        "fill_struc_stop_time" et "print_test_stop_time".
 *        creer un fichier "stop_timestests.txt" dans le dossier Save contenant les données extraites
 */
int fstop_times(int BOOL, listes * list);

#endif
