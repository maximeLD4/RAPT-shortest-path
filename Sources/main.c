#include"create_graph.h"
#include"dijkstra.h"

int main(int argc, char ** argv)
{ 

    printf("Début du main....\n");
    main_args * struct_arguments =get_args(argc,argv);
    int heure_depart_debut=heure_en_seconde(struct_arguments->Heure_Depart);
    printf("Création de la structure arguments\n");
    node ** list_first_node = graph(1,struct_arguments,heure_depart_debut);
    //int stop_id_depart=recherche_stop_id_name(struct_arguments->Station_Depart,list_first_node);
    //int stop_id_arrive=recherche_stop_id_name(struct_arguments->Station_Arrive,list_first_node);
    //dijkstra(list_first_node,2035,1892);
    return 1; 
}

/* int main()
{
    node ** list_first_node = graph(1);
    int result = dijkstra(list_first_node,2035,1887);
    printf ("0 : succès\n -1 : erreur\n------\n retour : %i\n",result);


}  */