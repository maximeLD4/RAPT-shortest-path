#include "hashmap.h"

/* 
typedef struct graph_station
{
    void * id; // La clé de la table graph : id de la station
    void * nom; // La valeur de la table graph: le nom de la station
    int * nb_voisins; // Le nombre de voisins de la station , ie: la taille du tableau voisins
    int * voisins; //La liste des stations voisines (au sens du réseau)
    struct graph_station * next; // La liste des noeuds suivants (pour créer la table de hachage)

} graph_station;


typedef struct hashmap_graph
{
    unsigned long long size; //La taille de la table 
    size_t id_memsize; // Taille mémoire de la clé id
    size_t nom_memsize; // Taille mémoire de la valeur nom
    unsigned long long (*hash_function)(struct hashmap_graph *, void *); // Fonction de hachage
    int (*comp_function)(void *, void *); // Fonction de comparaison : retourne 1 si les 2 arguments sont égaux
    graph_station **list; // POinteur vers la table

} hashmap_graph;
 */

unsigned long long __hash_code(hashmap_graph *h_map, void *key)
{
    return (*(unsigned long long *)key) % h_map->size;
}

int __comp (void *a, void *b)
{
	return *(char *)a == *(char *)b;
}

hashmap_graph * create_table(unsigned long long size,
	         size_t key_memsize,
	         size_t val_memsize,
	         unsigned long long (*hash_function)(hashmap_graph *, void *),
			 int (*comp_function)(void *, void *))
{
    hashmap_graph *graph = (hashmap_graph *)malloc(sizeof(hashmap_graph));

    if (!graph) return NULL;

    graph->size = size;
	graph->id_memsize = key_memsize;
    graph->nom_memsize = val_memsize;
    graph->list = (graph_station **)calloc(size, sizeof(graph_station *));

    if(graph->list == NULL)
    {
        free(graph);
        return NULL;
    }

    graph->hash_function = hash_function ? hash_function : __hash_code;
	graph->comp_function = comp_function ? comp_function : __comp;

}

int insert(hashmap_graph *graph, void*key, void*val)
{
    graph_station *list, *temp, *new_node;

    unsigned long long pos = graph->hash_function(graph,key);
    if (pos > graph->size)
        return -1;

    list = graph->list[pos];
    temp = list;

    while(temp)
	{
        if(graph->comp_function(temp->id, key))
		{
            memcpy(temp->nom, val, graph->nom_memsize);
            return 0;
        }
        temp = temp->next;
    }

    new_node = malloc(sizeof(graph_station));
	if(new_node == NULL)
		return -1;

    new_node->nom = malloc(sizeof(graph->nom_memsize));
	if(new_node->nom == NULL)
	{
		free(new_node);
		return -1;
	}

    new_node->id = malloc(sizeof(graph->id_memsize));
	if(new_node->id == NULL)
	{
		free(new_node->nom);
		free(new_node);
		return -1;
	}

    new_node->nb_voisins = malloc(sizeof(int));
    if(new_node->nb_voisins == NULL)
	{
        free(new_node->id);
		free(new_node->nom);
		free(new_node);
		return -1;
	}

    *(new_node->nb_voisins)=0;
	memcpy(new_node->nom, val, graph->nom_memsize);
	memcpy(new_node->id, key, graph->id_memsize);
    new_node->next = list;
    graph->list[pos] = new_node;
	return 0;

}

int lookup(hashmap_graph *graph, void *key, void *value)
{
    unsigned long long pos   = graph->hash_function(graph, key);
    graph_station        *list = graph->list[pos];
    graph_station        *temp = list;
    while(temp)
	{
        if(graph->comp_function(temp->id, key))
        {
            memcpy(value, temp->nom, graph->nom_memsize);
            return 0;
        }
        temp = temp->next;
    }
    return -1;
}

void  delete_hash_map(hashmap_graph *graph)
{
    for (unsigned long long i = 0; i < graph->size; i++)
        if (graph->list[i] != NULL)
        {
            graph_station *temp = graph->list[i];
            while (temp)
            {
                graph_station *next = temp->next;
                free(temp->nom);
                free(temp->id);
                free(temp);
                temp = next;
            }
        }
    free(graph->list);
    free(graph);
}


void delete_node(hashmap_graph *graph, void *key)
{
	unsigned long long pos   = graph->hash_function(graph, key);
    graph_station *temp = graph->list[pos];
    graph_station        *prec = NULL;

    while(temp)
	{
        if(graph->comp_function(temp->id, key))
        {
			if(prec != NULL)
				prec->next = temp->next;
			else
                graph->list[pos] = NULL;

            free(temp->nom);
            free(temp->id);
            free(temp->voisins);
            free(temp);
			return;
		}
		prec = temp;
        temp = temp->next;
    }
}

// On met (id2,nom2) dans la liste des voisins de (id1,nom1)
int  insert_neighbor(hashmap_graph *graph, int id1, int id2)
{
    graph_station *neighborhood, *station, *temp;

    unsigned long long pos = graph->hash_function(graph,id1);
    if (pos > graph->size)
        return -1;



    temp = graph->list[pos];

    while(temp)
    {
        if (graph->comp_function(temp->id,id1))
        {
            station = temp;
            neighborhood = temp->voisins;
            break;
        }
        temp = temp->next;
    }

    if(station->nb_voisins==0)
        station->voisins = malloc(sizeof(int));

    else
    {
        realloc(station->voisins,*(station->nb_voisins) + 1);
    }

    memcpy(station->voisins[*(station->nb_voisins)],id2,sizeof(int));
    *(station->nb_voisins)++;
    return 0;
}
