#ifndef STRUCT_H
#define STRUCT_H

#include"Define_Nbr.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<math.h>
#include<unistd.h>


/**
 * Structure qui englobe l'essemble des extaction faites par les différents fichier.h
 * dans les differents fichiers gtfs.
 */
typedef struct station_t{  
    char * Rshortname;                              //creation de la structure 
    int service_id;
    int date;
    int start_date;
    int end_date;
    int route_id;
    char * DepartExtremite;
    char * ArriveExtremite;
    int stop_id;
    long int trip_id;
    int heure_arrive;
    int heure_depart;
    char * sname;
    int stop_id_prec;
    int stop_id_prox;
    int temps_trans;
    int direction_id;
    int stop_sequence;
}station_t;

/**
 * Différentes listes de structures "stations" qui permettent d'ordonner les données extraites
 * des fichier.h, dans lesquelles on va aller piochers les infos utiles par la suite
 */
typedef struct listes{
    station_t * routes;
    station_t * calendar_date;
    station_t * calendar;
    station_t * stop_time;
    station_t * stop;
    station_t * transfers;
    station_t * trips;
}listes;

/**
 *  structure stockant les arguments du main de main.c
 */
typedef struct main_args{
    int Bool_calendar_dates;
    int Bool_calendar;
    int Bool_routes;
    int Bool_stop_times;
    int Bool_stops;
    int Bool_transfers;
    int Bool_trips;
    int DATASET; // pas un int a mon avis...dailleur DATASET n'est pas a utiliser a priori ici
    char * Station_Depart;
    char * Station_Arrive;
    char * Heure_Depart;
    char * fichier_requetes;

}main_args;



/**
 * @brief Lire 1ere ligne d'un fichier (il est aussi rapide de ne pas utiliser cette fonction)
 */
int read_1_line_in_file(char * string,int taille, FILE ** name);



/**
 * @brief Permet d'ouvrir un fichier et tester sa bonne ouverture, et son allocation
 *        On creer un fonction spécifique car cela revient plusieurs fois.
 */
int open_File(char * path, FILE ** name);

/**
 * @brief alloue et remplis la structure des arguments
 */
main_args * get_args(int argc, char ** argv);

/**
 * @brief initialise la structure des arguments
 */
void init_args(main_args * structure_args);

/**
 * @brief définit l'utilisation de option du main de main.c 
 */
void print_usage(void);

#endif
