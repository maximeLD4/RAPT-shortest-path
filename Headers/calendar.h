#ifndef CALENDAR_H
#define CALENDAR_H


#include"struct.h"



/**
 * @brief fonction qui fprint element par element les list->calendar[i]->... infos stockée par "fill_struc_calendar"
 *        dans le fichier calendartest.txt dans le dossier Saves.
 *        Si BOOL=1 !
 */
int write_calendar(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list);

/**
 * @brief Remplis list->calendar a partir de calendar.txt, en lisant le fichier ligne par ligne.
 *        les infos de la ligne i sont stockées dans la structure list->calendar[i], a savoir :
 *        Le service_id et les start_date et end_date.
 */
int fill_struc_calendar(FILE ** name,listes * list);

/**
 * @brief Ouvre le fichier calendar.txt et applique les fonctions :
 *        "fill_struc_calendar" et "write_calendar".
 *        creer un fichier "calendartest.txt" dans le dossier Save contenant les données extraites
 */
int fcalendar(int BOOL, listes * list);

#endif
