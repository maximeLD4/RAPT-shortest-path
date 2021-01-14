#include"struct.h"

#include"trips.h"

int fill_struc_trips(FILE ** name,listes * list)
{
    char txt='o';                       
    //int i=0;
    int p=0;
    while (txt !=EOF)                                   // on boucle la lecture d'un ligne
    {                                                   // tant qu'on a pas ateint la fin du fichier
        char str2[200];
        fgets(str2, 200, *name);
        char * routeid=strtok(str2,",");                     // chaque ligne a son format particulier    
        char * serviceid=strtok(NULL,",");                         // on vient récuperer ce qui nous interresse
        char * tripid=strtok(NULL,",");
        char * a=strtok(NULL,",");
        char * b=strtok(NULL,",");
        char * directionid=strtok(NULL,",");

        int routeidint;                              // on convertis nos données en int et long int
        sscanf(routeid,"%i",&routeidint);
        (list->trips[p]).route_id=routeidint;
        long int tripidint;
        sscanf(tripid,"%ld",&tripidint);
        (list->trips[p]).trip_id=tripidint;
        int directionidint;
        sscanf(directionid,"%i",&directionidint);
        (list->trips[p]).direction_id=directionidint;
        int serviceidint;
        sscanf(serviceid,"%i",&serviceidint);
        (list->trips[p]).service_id=serviceidint;    

        p++;

        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    }
    return 1;
}


int write_trips(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/tripstest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*****************\n****%s[%i]**** \nroute_id : %i\ntrip_id : %ld\ndirection_id : %i\nservice_id: %i\n",fonctionExtractrice,j,list->trips[j].route_id,(list->trips[j]).trip_id,list->trips[j].direction_id, list->trips[j].service_id);
    }
    return 1;
}


int ftrips(int BOOL,listes * list)
{ 
    FILE * stoptext;
    open_File("../Gtfstxt/trips.txt",&stoptext);

    char str[100];                                      // on lit la premeire ligne (qui ne sert a rien ici)
    read_1_line_in_file(str,100,&stoptext);

    fill_struc_trips(&stoptext,list);

    write_trips(NBR_TRIPS,"trips",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}
