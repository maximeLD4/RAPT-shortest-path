#ifndef CALENDAR_DATES_H
#define CALENDAR_DATES_H

#include"struct.h"



/**
 * @brief   Remplis list->calendar_date a partir de calendar_date.txt, en lisant le fichier ligne par ligne.
 *          les infos de la ligne i sont stockées dans la structure list->calendar_date[i], a savoir :
 *          Le service_id et la date.
 * 
 */
int fill_struc_calendar_date(FILE ** name,listes * list);

/**
 * @brief  fonction qui fprint element par element les list->calendar_date[i]->... infos stockée par "fill_struc_calendar_date"
 *         dans le fichier calendardatestest.txt dans le dossier Saves.
 *         Si BOOL=1 !
 * 
 */
int write_calendar_date(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list);

/**
 * @brief Ouvre le fichier calendar_date.txt et applique les fonctions :
 *        "fill_struc_calendar_date" et "write_calendar_date".
 *        creer un fichier "calendar_datetest.txt" dans save contenant les données extraites
 */
int fcalendar_dates(int BOOL,listes * list);
#endif
