#ifndef TRANSFERS_H
#define TRANSFERS_H

#include"struct.h"


/**
 *  @brief Remplis list->transfers a partir de transfers.txt, en lisant le fichier ligne par ligne.
 *         Les infos de la ligne i sont stockées dans la structure list->transfers[i], 
 *         a savoir : Le stop_id_prec , le stop_id_prox et le temps_trans.
 */
int fill_struc_transfers(FILE ** name, listes * list);

/**
 * @brief fonction qui fprint element par element les list->transfers[i]->... infos stockée par "fill_struc_transfers"
 *        dans le fichier transferstest.txt du dossier Saves.
 *        Si BOOL=1 !
 */
int write_transfers(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list);

/**
 * @brief Ouvre le fichier transfers.txt et applique les fonctions :
 *        "fill_struc_transfers" et "write_transfers".
 *        creer un fichier "transferstest.txt" dans le dossier Save contenant les données extraites
 */
int ftransfers(int BOOL,listes * list);

#endif
