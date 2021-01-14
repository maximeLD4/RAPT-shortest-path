#include"create_graph.h"



listes * callocLesTableaux(void)
{
    listes * list =calloc(1,sizeof(listes));

    list->routes=(station_t *)calloc(NBR_ROUTES,sizeof(station_t));
    for (int i=0;i<NBR_ROUTES;i++)
    {
        ((list)->routes[i]).DepartExtremite=(char *)calloc(100,sizeof(char));
        ((list)->routes[i]).ArriveExtremite=(char *)calloc(100,sizeof(char));
        ((list)->routes[i]).Rshortname=(char *)calloc(100,sizeof(char));
    }
    list->calendar_date=(station_t *)calloc(NBR_CALENDAR_DATE,sizeof(station_t));
    

    list->calendar=(station_t *)calloc(NBR_CALENDAR,sizeof(station_t));
    

    list->stop_time=(station_t *)calloc(NBR_STOP_TIMES,sizeof(station_t));

    list->stop=(station_t *)calloc(NBR_STOPS,sizeof(station_t));
    for (int i=0;i<NBR_STOPS;i++)
    {
        list->stop[i].sname=(char *)calloc(100,sizeof(char));
    }

    list->transfers=(station_t *)calloc(NBR_TRANSFERS,sizeof(station_t));

    list->trips=(station_t *)calloc(NBR_TRIPS,sizeof(station_t));

    return list;
}


int cherche_route_id(int nbr_routes, char * Station_Depart, listes * list)
{    
    int indice1=0;
    for (int j=0;j<nbr_routes;j++)
    {
        if (!strcmp(list->routes[j].DepartExtremite,Station_Depart))
        {
            indice1=j;
            break;              
        }
    }                          
    int route_id1=((list)->routes[indice1]).route_id;
    return route_id1;
}


long int cherche_trip_id(int nbr_trips, int route_id1, listes * list)
{
    int indice2=0;
    for (int i=0;i<nbr_trips;i++)
    {
        if (list->trips[i].route_id==route_id1)
        {
            indice2=i;
            break;              
        }
    }
    long int trip_id1=list->trips[indice2].trip_id;
    return trip_id1;
}


int cherche_indice_stop_times(int nbr_stop_times, long int trip_id, listes * list,int heure_depart_debut)
{
    int indice3=0;
    for (int k=0;k<nbr_stop_times;k++)
    {
        if (list->stop_time[k].trip_id==trip_id )//&& list->stop_time[k].heure_depart > heure_depart_debut)
        {
            indice3=k;
            break;
        }
    }
    return indice3;
}

void fill_graph(node * first_node,int nbr_stop,int indice, listes * list)
{ 
    node * cur_node=first_node;
    int p=0;
    int stpseqprec=0;
    while (stpseqprec < ((list)->stop_time[indice+p]).stop_sequence)    
    {
        int t2=list->stop_time[indice+p-1].heure_arrive;
        int t1=list->stop_time[indice+p].heure_arrive;
        int T=t1-t2;
        stpseqprec=((list)->stop_time[indice+p]).stop_sequence;
        int indice4=0;
        for (int m=0;m<nbr_stop;m++)
        {
            if (list->stop_time[indice+p].stop_id==list->stop[m].stop_id)
            {
                indice4=m;
                break;
            }
        }
        node * nouveau_node=insert_node(T,cur_node);
        fill_node(list->stop[indice4].sname,list->stop[indice4].stop_id,nouveau_node);
        cur_node=nouveau_node;
        p++;
    }
    node * nouveau_node=insert_node(0,cur_node);
    fill_node("**FIN**",-1,nouveau_node);
}



void print_graph(node * first_node, int BOOL)
{
    if (BOOL)
    {
        printf("Station(id)\n");
        node * cur1_node=first_node;
        while((cur1_node->BOOL)==1)
        {
            printf("%s(%i)\n",cur1_node->stop_name,cur1_node->stop_id);
            printf("        ||\n        \\/\n");
            node * last_node=cur1_node;
            cur1_node=cur1_node->nextnode[cur1_node->NbrDeVoisins-1];
            del_node(last_node);
        }
        printf("%s(%i)\n",cur1_node->stop_name,cur1_node->stop_id);
        del_node(cur1_node);
    }
}

void write_graph(node * first_node, int BOOL,FILE * fichiertxt)
{
    if (BOOL)
    {
        node * cur1_node=first_node->nextnode[0];
        while((cur1_node->BOOL)==1)
        {
            fprintf(fichiertxt,"%s(%i)",cur1_node->stop_name,cur1_node->stop_id);
            if (cur1_node->NbrDeVoisins>2)
            {   
                fprintf(fichiertxt," <===> { ");
                for (int i=2;i<cur1_node->NbrDeVoisins;i++)
                {
                    fprintf(fichiertxt," [%i]%s(%i)  ",cur1_node->Poid[i],cur1_node->nextnode[i]->stop_name,cur1_node->nextnode[i]->stop_id);
                }
                fprintf(fichiertxt,"}");
                fprintf(fichiertxt,"\n");
            }
            else
            {
                fprintf(fichiertxt,"\n");
            }
            fprintf(fichiertxt,"        /\\\n        ||\n       [%i]\n        ||\n        \\/\n",cur1_node->Poid[1]);
            cur1_node=cur1_node->nextnode[1];
        }
        fprintf(fichiertxt,"%s(%i)\n",cur1_node->stop_name,cur1_node->stop_id);
    }
}

void freeLesTableaux(listes * list)
{
    free(list->calendar_date);
    free(list->calendar);
    for (int i=0; i<NBR_ROUTES;i++)
    {
        free(((list)->routes[i]).DepartExtremite);
        free(((list)->routes[i]).ArriveExtremite);
        free(((list)->routes[i]).Rshortname);
    } 
    free(list->routes);
    for (int i=0; i<NBR_STOPS;i++)
    {
        free((list->stop[i]).sname);
    } 
    free(list->stop);
    free(list->stop_time);
    free(list->transfers);
    free(list->trips);
    free(list);
} 

int graph_transfers(node * * Liste1, listes * list)
{
    for (int i=0; i<NBR_ROUTES;i++)
    {
        node * cur1_node =Liste1[i];
        cur1_node=cur1_node->nextnode[0];
        while(cur1_node->BOOL==1)
        {
            for (int j=0;j<NBR_TRANSFERS;j++)
            {
                if (cur1_node->stop_id==list->transfers[j].stop_id_prec)
                {
                    int Te=list->transfers[j].temps_trans;
                    node * proxnode=recherche_node_id(list->transfers[j].stop_id_prox,Liste1);
                    if (proxnode!=NULL)
                    {
                        if (not_already_voisins(cur1_node,proxnode))
                        {
                            insert_existing_node(Te,cur1_node,proxnode);
                        }
                    }
                }
            }
            cur1_node=cur1_node->nextnode[1];
        }
        for (int j=0;j<NBR_TRANSFERS;j++)
        {
            if (cur1_node->stop_id==list->transfers[j].stop_id_prec)
            {
                int Te=list->transfers[j].temps_trans;
                node * proxnode=recherche_node_id(list->transfers[j].stop_id_prox,Liste1);
                if (proxnode!=NULL)
                {
                    insert_existing_node(Te,cur1_node,proxnode);
                }
            }
        }
    }
    return 1;
}


node * * graph(int BOOL,main_args * struct_arguments, int heure_depart_debut)
{
    if (BOOL)
    {
        listes * list=callocLesTableaux();
        froutes(struct_arguments->Bool_routes,list);
        fstops(struct_arguments->Bool_stops,list);
        fstop_times(struct_arguments->Bool_stop_times,list);
        ftrips(struct_arguments->Bool_trips,list);
        ftransfers(struct_arguments->Bool_transfers,list);
        fcalendar(struct_arguments->Bool_calendar,list);
        fcalendar_dates(struct_arguments->Bool_calendar_dates,list);
        
        FILE * fichiertxt = fopen("../Saves/ResultatsGraph.txt", "w+");
        node * * List_first_node= calloc(NBR_ROUTES,sizeof(node *));
        for (int indice=0;indice<NBR_ROUTES ;indice++)
        {
            int route_id=list->routes[indice].route_id;

            long int trip_id =cherche_trip_id(NBR_TRIPS,route_id,list);
            
            int indice3=cherche_indice_stop_times(NBR_STOP_TIMES,trip_id,list,heure_depart_debut);
            List_first_node[indice]=createfirstnode();

            fill_first_node("BEBUT",-1,List_first_node[indice]);    

            fill_graph(List_first_node[indice],NBR_STOPS,indice3,list);         
        }
        graph_transfers(List_first_node,list);
        for (int indice=0;indice<NBR_ROUTES ;indice++) 
        {
            fprintf(fichiertxt,"*****************************************************************\n****************************METRO N°%s****************************\n*****************************************************************\n**********************[Poid]Station(id_station)******************\n************************Station(id_station)**********************\n*****************************************************************\n",list->routes[indice].Rshortname);
            write_graph(List_first_node[indice],1,fichiertxt);
        }
        freeLesTableaux(list);                                        
        return List_first_node;  //Pour dijkstra
    }
    //return 1;
}             


int test(int BOOL)
{
    if (BOOL)
    {
        listes * list=callocLesTableaux();
        froutes(0,list);
        fstops(0,list);
        fstop_times(0,list);
        ftrips(0,list);
        fcalendar(0,list);
        fcalendar_dates(0,list);
        //ftransfers(0,list);
        //freeLesTableaux(list); 
    }
    return 1;
}
