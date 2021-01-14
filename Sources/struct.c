#include"struct.h"


int read_1_line_in_file(char * string,int taille, FILE ** name)
{
    fgets(string,taille, *name);   // on lit la premeire ligne (qui ne sert a rien ici)
    return 1;
}


int open_File(char * path, FILE ** name)
{
    *name=fopen(path,"r");  //importation du fichier
    if (*name==NULL)
    {
        printf("%s \n", strerror(errno));
        return 0;
    }
    return 1;
} 

main_args * get_args(int argc, char ** argv)
{
    main_args * struct_arguments =calloc(1, sizeof(main_args));
    init_args(struct_arguments);
    char c;
    while ((c = getopt (argc, argv, "hpcumoaids:e:t:r:")) != -1)
    {
        switch (c)
        {
            case 'h':
                print_usage();
                return 0;
            case 'p':
                struct_arguments->Bool_calendar_dates = 1;
                break;
            case 'c':
                struct_arguments->Bool_calendar = 1;
                break;
            case 'u':
                struct_arguments->Bool_routes = 1;
                break;
            case 'm':
                struct_arguments->Bool_stop_times = 1;
                break;
            case 'o':
                struct_arguments->Bool_stops = 1;
                break;
            case 'a':
                struct_arguments->Bool_transfers = 1;
                break;
            case 'i':
                struct_arguments->Bool_trips = 1;
                break;
            case 'd':
                struct_arguments->DATASET = 1;
                break;
            case 's':
                struct_arguments->Station_Depart = optarg;
                break;
            case 'e':
                struct_arguments->Station_Arrive = optarg;
                break;
            case 't':
                struct_arguments->Heure_Depart = optarg;
                break;
            case 'r':
                struct_arguments->fichier_requetes = optarg;
                break;
            case '?':
                printf ("Unknown option  OR Unknown character \n");
                print_usage();
                return NULL;
        }
    }
    return struct_arguments;
}

void init_args(main_args * structure_args)
{
    structure_args->Bool_calendar_dates = 0;
    structure_args->Bool_calendar = 0;
    structure_args->Bool_routes = 0;
    structure_args->Bool_stop_times = 0;
    structure_args->Bool_stops = 0;
    structure_args->Bool_transfers = 0;
    structure_args->Bool_trips = 0;
}


void print_usage(void)
{
    printf("usage: ./fichier OPTIONS\n"
    "options:\n"
    "\t-h       print usage\n"
    "\t-p       sauvegarde calendar_date_test dans Saves\n"
    "\t-c       sauvegarde calendar_test dans Saves\n"
    "\t-u       sauvegarde routes_test dans Saves\n"
    "\t-m       sauvegarde stop_times_test dans Saves\n"
    "\t-o       sauvegarde stops_test dans Saves\n"
    "\t-a       sauvegarde transfers_test dans Saves\n"
    "\t-i       sauvegarde trips_test dans Saves\n"
    "\t-d       DATASET\n"                  //inutile ici car on a deja notre graph
    "\t-s       Station de Depart \n"
    "\t-e       Station d'arrivée\n"
    "\t-r       FICHIER REQUETES\n"
    "\t-t       Heure de Depart au format \"hh:mm:ss\"\n\n"
    "Exemples:\n"
    "./main -s \"Château de Vincennes\" -e \"Hôtel de Ville\" -t \"12:00:00\"\n}");
}