#ifndef STRUCT_NODE_H
#define STRUCT_NODE_H


/**
 * Structure de Noeud qui permet de construire de graph.
 */
typedef struct node{
    struct node * nextnode[50]; // chaque voisin est un noeud qu'on stock dans la liste nextnode.
    int Poid[50];               // le poid de l'arrete qui mène a nextnode[i] est Poid[i]
    int stop_id;                //stop_id du noeud
    char * stop_name;           //nom de la station du noeud
    int NbrDeVoisins;           // nombre de voisin (transparent)
    int BOOL;                   // BOOL=1: noeud du graph et BOOL=0 : noeud qui permet de contruire le graph (DEBUT et FIN)
}node;


/**
 * @brief alloue et renvois un premier noeud pour une ligne donnée.
 */
node * createfirstnode(void);

/**
 * @brief remplis les données associées a un noeud. 
 *        Important: déja 1 voisins(celui auquel on le rattache, sur lequel on l'insert) et BOOL=0.
 */
int fill_node(char * nom,int id, node * cur_node);

/**
 * @brief remplis les données associées au premier noeud/sommet 
 *        Important: pas encore de voisins et BOOL=0
 */
int fill_first_node(char * nom,int id, node * cur_node);

/**
 * @brief créer un sommet et une arrete qu'on ajoute aux sommets adjacent du noeud "derniernode"
 *        et le renvois.
 */
node * insert_node(int T,node * derniernode);

/**
 * @brief insert le noeud déja existant "inserernode" sur le noeud déja existant "derniernode" 
 *        cad créer l'arrete entre ces deux sommets.
 */
void insert_existing_node(int Te,node * derniernode, node * inserernode);

/**
 * @brief Vérifie si deux noeuds ne sont pas déja voisins.
 *        Si oui --> renvoie 0, Si non --> renvoie 1.
 */
int not_already_voisins(node * derniernode, node * inserernode);

/**
 * @brief supprésion d'un "noeud" du graph. (free)
 */
void del_node(node * cur_node);

/**
 * @brief Recherche et renvois un node du graph créé, a partir de la liste "Liste" des 
 *        premieres stations de chaques lignes. En fonction de son stop_id.
 */
node * recherche_node_id(int stop_id1,node * * Liste);

/**
 * @brief Recherche et renvois le stop_id d'un node du graph créé, a partir de la liste "Liste" des 
 *        premieres stations de chaques lignes. En fonction de son stop_name.
 */
int recherche_stop_id_name(char * name,node * * Liste);


#endif
