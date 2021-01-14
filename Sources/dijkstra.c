/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<math.h> */

//#include"create_graph.h"
#include"dijkstra.h"


int update_dist(dist_list* distances,int id,int dist)
{
    dist_node * pointer = distances->list;
    dist_node * previous_node=pointer;
    //On parcourt la liste des distances
    while ((pointer != NULL) && (*(pointer->dist) <= dist))
    {
        //Si le sommet est déjà présent la liste des distances
        if (*(pointer->id)==id)
        {
            //MAJ de la distance à l'origine
            int new_dist=fmin(dist,*(pointer->dist));
            memcpy(pointer->dist,&new_dist,sizeof(int));
            return 0;

        }
        previous_node = pointer;
        pointer = previous_node->next;
        
    }
    //Sinon on ajoute le nouveau sommet trié par dist croissant

    dist_node * new_node = malloc(sizeof(dist_node));
    if (new_node==NULL)
    {
        printf(" //!\\ //!\\ Echec de l'allocation mémoire\n");
        return -1;
    }

    new_node->dist = malloc(sizeof(int));

    if (new_node->dist == NULL)
    {
        free(new_node);
        printf(" //!\\ //!\\ Echec de l'allocation mémoire\n");
        return -1;
    }

    new_node->id = malloc(sizeof(int));

    if (new_node->id == NULL)
    {
        free(new_node);
        free(new_node->dist);
        printf(" //!\\ //!\\ Echec de l'allocation mémoire\n");
        return -1;
    }
    *(new_node->dist)=dist;
    *(new_node->id)=id;

    if (previous_node == NULL)
    {
        distances->list = new_node;
    }
    else
    {
        previous_node->next = new_node;
    }

    if (pointer != NULL)
    {
        new_node->next = pointer;
        (*distances->unvisited)++;
        return 0;
    }
    else 
    {
        new_node->next = NULL;
        (*distances->unvisited)++;
        return 0;

    }
}

int find_dist(dist_list* distances,int id)
{
    dist_node * pointer = distances->list;
    dist_node * prev_node;
    while(*(pointer->id) != id)
    {
        if (pointer==NULL)
            return -1;
        prev_node=pointer;
        pointer = prev_node->next;
    }
    return *(pointer->dist);
}

node* get_min_dist(dist_list* distances,node ** list_first_node)
{
    dist_node * pointer = distances->list;
    if (pointer == NULL)
    {
        return NULL;
    }
    dist_node * prev_node;
    node * node=recherche_node_id(*(pointer->id),list_first_node);
    while(((node->BOOL)==VISITED) && (pointer != NULL))
    {
        prev_node=pointer;
        pointer=prev_node->next;
        node=recherche_node_id(*(pointer->id),list_first_node);
    }
    return node;
}

void free_dist(dist_list * distances)
{
    dist_node * pointer = distances->list;
    dist_node * next_node = pointer; 
    while (next_node != NULL)
    {
        next_node= pointer->next;
        free(pointer->dist);
        free(pointer->id);
        free(pointer);
        pointer = next_node;
    
    }
    free(distances->unvisited);
    free(distances);
}
 
int dijkstra(node ** list_first_node, int depart_id, int arrive_id )
{
    int n=NBR_STOPS;
    int k=1;
    node * node_dep=recherche_node_id(depart_id,list_first_node);
    node * node_arr=recherche_node_id(arrive_id,list_first_node);

    node * current_node = node_dep;

    //Création de la liste des distances
    dist_list * distances = malloc(sizeof(dist_list));
    if (distances == NULL)
    {
        printf(" //!\\ //!\\ Echec de l'allocation mémoire\n");
        return -1;
    }
    distances->unvisited = calloc(1,sizeof(*(distances->unvisited)));
    if (distances->unvisited == NULL)
    {
        free(distances);
        printf(" //!\\ //!\\ Echec de l'allocation mémoire\n");
        return -1;
    }
    distances->list = NULL;

    *(distances->unvisited) = 0;

    update_dist(distances,current_node->stop_id,0);

    //Tant qu'on ne tombe pas sur la station de fin du trajet
    while(current_node->stop_name!=node_arr->stop_name)
    {
        current_node->BOOL=VISITED;

        if ((k>n) || ((*distances->unvisited)==0))
        {
            //Tout le sous-ensemble connexe du graphe a été
            //parcouru : la station d'arrivée n'est pas atteignable
            printf("Condition d'arrêt du while : Graphe entièrement parcouru\n");
            return -1;
        }
        //On parcourt les voisins du noeud actuel
        
        for(int i=0;i++;i<(current_node->NbrDeVoisins))
        { 
            node * voisin= (current_node->nextnode)[i];
            //On met à jour la distance de tous les voisins pas encore visités
            if (voisin->BOOL != VISITED)
            {
                int dist = (current_node->Poid)[i] + find_dist(distances,voisin->stop_id);
                update_dist(distances,voisin->stop_id,dist);
            }
        }

    //On séléctionne le prochain sommet non visité
    current_node = get_min_dist(distances,list_first_node);
    k++;
    }

    int result = find_dist(distances,node_arr->stop_id);
    printf("Succès de l'algo!\n\t____\t\nLe temps de : %s\nA : %s\nEst de : %i sec\n",node_dep->stop_name,node_arr->stop_name,result);
    return 0;

}
