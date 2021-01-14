#include"struct.h"

#include"struct_nodes.h"


node * createfirstnode(void)
{
    node * firstnode=malloc(sizeof(node));
    if (firstnode==NULL)
    {
        printf("Error malloc");
        return NULL;
    }
    return firstnode;
}


int fill_node(char * nom,int id, node * cur_node)
{
    cur_node->NbrDeVoisins=1;
    cur_node->stop_id=id;
    cur_node->BOOL=0;
    int k=0;
    cur_node->stop_name =calloc(sizeof(char),(strlen(nom)+1));
    if(cur_node->stop_name == NULL)
    {
        printf("Error malloc");
        return 0;
    }
    while (nom[k]!='\0')
    {
        cur_node->stop_name[k]=nom[k];
        k++;
    }
    cur_node->stop_name[k]='\0';
    return 1;
}


int fill_first_node(char * nom,int id, node * cur_node)
{
    cur_node->BOOL=0;
    cur_node->NbrDeVoisins=0;
    cur_node->stop_id=id;
    int k=0;
    cur_node->stop_name =calloc(sizeof(char),(strlen(nom)+1));
    if(cur_node->stop_name == NULL)
    {
        printf("Error malloc");
        return 0;
    }
    while (nom[k]!='\0')
    {
        cur_node->stop_name[k]=nom[k];
        k++;
    }
    cur_node->stop_name[k]='\0';
    return 1;
}


node * insert_node(int T,node * derniernode)
{
    int nbrvoisin= derniernode->NbrDeVoisins;
    if(nbrvoisin <=50)
    {
        derniernode->nextnode[nbrvoisin]=malloc(sizeof(node));
        derniernode->Poid[nbrvoisin]=T;
        if (derniernode->nextnode[nbrvoisin]==NULL)
        {
            printf("Error malloc");
            return NULL;
        }
        derniernode->BOOL=1;
        derniernode->NbrDeVoisins=(nbrvoisin)+1;
        derniernode->nextnode[nbrvoisin]->nextnode[0]=malloc(sizeof(node));
        derniernode->nextnode[nbrvoisin]->nextnode[0]=derniernode;
        return derniernode->nextnode[nbrvoisin];
    }
    printf("deja trop de voisins");
    return NULL;
}


void insert_existing_node(int Te,node * derniernode, node * inserernode)
{
    derniernode->nextnode[derniernode->NbrDeVoisins]=inserernode;
    derniernode->Poid[derniernode->NbrDeVoisins]=Te;
    derniernode->NbrDeVoisins++;
    derniernode->BOOL=1;
    inserernode->nextnode[inserernode->NbrDeVoisins]=derniernode;
    inserernode->Poid[inserernode->NbrDeVoisins]=Te;
    inserernode->NbrDeVoisins++;
    inserernode->BOOL=1;
}


int not_already_voisins(node * derniernode, node * inserernode)
{
    for(int i=0;i<(derniernode->NbrDeVoisins);i++)
    {
        if(derniernode->nextnode[i]->stop_id==inserernode->stop_id)
        {
            return 0;
        }
    }
    return 1;
}


void del_node(node * cur_node)
{
    free(cur_node->stop_name);
    free(cur_node);
}


node * recherche_node_id(int stop_id1,node * * Liste)
{
    for (int i=0;i<NBR_ROUTES;i++)
    {
        node * cur1_node=Liste[i];
        cur1_node=cur1_node->nextnode[0];
        while((cur1_node->BOOL)==1)
        {
            if (cur1_node->stop_id==stop_id1)
            {
                return cur1_node;
            }
            cur1_node=cur1_node->nextnode[1];
        }
        if (cur1_node->stop_id==stop_id1)
        {
            return cur1_node;
        }
    }
    return NULL;
}

int recherche_stop_id_name(char * name,node * * Liste)
{
    for (int i=0;i<NBR_ROUTES;i++)
    {
        node * cur1_node=Liste[i];
        cur1_node=cur1_node->nextnode[0];
        while((cur1_node->BOOL)==1)
        {
            if (strcmp(cur1_node->stop_name,name)==0)
            {
                return cur1_node->stop_id;
            }
            cur1_node=cur1_node->nextnode[1];
        }
        if (strcmp(cur1_node->stop_name,name)==0)
        {
            return cur1_node->stop_id;
        }
    }
    return 0;
}