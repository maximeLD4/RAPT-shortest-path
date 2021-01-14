#ifndef ROUTES_H
#define ROUTES_H

#include"struct.h"

/**
 * @brief Ce qu'on appel séparateur est le "<->" qu'on retrouve dans la synthaxe de routes.txt.
 *        On cherche donc ici "<" dans un str.
 */
int rechercheSeparteur(char * str);

/**
 * @brief Renvoi 1 si il y a un Slash et 0 sinon, dans le str d'argument.
 */
int rechercheSlash(char * str);


/**
 * @brief Renvoi 1 si il y a une parenthese et 0 sinon, dans le str d'argument.
 */
int rechercheParentheses(char * str);

/**
 * @brief Permet de remplir ((list)->routes[p]).Rshortname a partir de str5.
 */
void fillShortName(int p,char * str5,listes * list);

/**
 * @brief Remplis str avec "NONE\0"
 */
void fillNoneStr(char * str);  

/**
 *  @brief  Si COef = 0; cad si la ligne a la synthaxe suivant : " station 1 <-> station 2"
 *          Remplis list->routes a partir de routes.txt, en lisant le fichier ligne par ligne.
 *          les infos de la ligne i sont stockées dans la structure list->routes[i], a savoir :
 *          Le DepartExtremite, l'ArriveExtremite la route_id et le shortname.
 */
void fillCoef0(int routeidint,char * str5,char * str1, int p,listes * list);



/**
 *  @brief  Si la ligne a la synthaxe suivant : " station 1/station 1 prime <-> station 2"
 *          Remplis list->routes a partir de routes.txt, en lisant le fichier ligne par ligne.
 *          les infos de la ligne i sont stockées dans la structure list->routes[i], a savoir :
 *          Le DepartExtremite, l'ArriveExtremite la route_id et le shortname.
 */
void fillSlashAGauche(char * str1, int p, listes * list); 


/**
 *  @brief Si la ligne a la synthaxe suivant : " station 1 <-> station 2/station 2 prime"
 *         Remplis list->routes a partir de routes.txt, en lisant le fichier ligne par ligne.
 *         les infos de la ligne i sont stockées dans la structure list->routes[i], a savoir :
 *         Le DepartExtremite, l'ArriveExtremite la route_id et le shortname.
 */
void fillSlashADroite(char * str1, int p, listes * list);


/**
 * @brief Si la ligne a la synthaxe suivant : " station 1" 
 *        /!\ on met un aller ou retour et l'autre en "NONE"
 *        Remplis list->routes a partir de routes.txt, en lisant le fichier ligne par ligne.
 *        les infos de la ligne i sont stockées dans la structure list->routes[i], a savoir :
 *        Le DepartExtremite, l'ArriveExtremite la route_id et le shortname.
 */
void fillSansSeparateur(int routeidint,char * str5,char * str1, int p, listes * list);


/**
 * @brief Enleve les parentheses de (list->routes[p]).ArriveExtremite pour des raison estetiques d'affichage.
 */
void enleverParenthesesArrive(int p, listes * list); 

/**
 * @brief Enleve les parentheses de (list->routes[p]).DepartExtremite pour des raison estetiques d'affichage.
 */
void enleverParenthesesDepart(int p, listes * list);


/**
 * @brief  Remplis list->routes a partir de routes.txt, en lisant le fichier ligne par ligne.
 *         A l'aide des fonction : fillSansSeparateur, fillSlashADroite, fillSlashAGauche et fillCoef0 .
 * 
 *         Les infos de la ligne i sont stockées dans la structure list->routes[i], 
 *         a savoir : Le short_name, route_id, départ_extremité et arrivée_extremité.
 */
int fill_struct_route(FILE ** name, listes * list);


/**
 * @brief fonction qui fprint element par element les list->routes[i]->... infos stockée par "fill_Struc_Routes"
 *        dans le fichier routestest.txt du dossier Saves.
 *        Si BOOL=1 !
 */
int write_Routes(int nombredeligne,char * fonctionExtractrice, int * BOOL, listes * list);


/**
 * @brief Ouvre le fichier routes.txt et applique les fonctions :
 *        "fill_Struc_Routes" et "print_test_Routes".
 *        creer un fichier "routetest.txt" dans save contenant les données extraites
 */
int froutes(int BOOL, listes * list); 


#endif
