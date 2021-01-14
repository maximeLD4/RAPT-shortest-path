#include"struct.h"

#include "stop_times.h"


int write_stop_time(int nombredeligne,char * fonctionExtractrice, int * BOOL, listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/stoptimetest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*****************\n****%s[%i]**** \nstop_id : %i\ntrip_id : %ld\nheure depart : %i\nheure arrive: %i\nStop sequence %i\n",fonctionExtractrice,j,list->stop_time[j].stop_id,(list->stop_time[j]).trip_id,list->stop_time[j].heure_depart, list->stop_time[j].heure_arrive,(list->stop_time[j]).stop_sequence);
    }
    return 1;
}

int heure_en_seconde(char * heure)
{
    char * h2 =strtok(heure,":");
    char * m2 =strtok(NULL,":");
    char * s2 =strtok(NULL,":");
    int h2int= atoi(h2);
    int m2int= atoi(m2); 
    int s2int= atoi(s2);
    int heure_depart2=((h2int)*3600)+((m2int)*60 + s2int);
    return heure_depart2;
}


int fill_struc_stop_time(FILE ** name,listes * list)
{
    char txt='o';                       
    //int i=0;
    int p=0;
    while (txt !=EOF)                                   // on boucle la lecture d'un ligne
    {                                                   // tant qu'on a pas ateint la fin du fichier
        char str2[200];
        fgets(str2, 200, *name);
        char * tripid=strtok(str2,",");                     // chaque ligne a son format particulier    
        char * HA=strtok(NULL,",");                         // on vient récuperer ce qui nous interresse
        char * HD=strtok(NULL,",");
        char * stopid=strtok(NULL,",");
        char * stopsequence=strtok(NULL,",");

        long int tripiddouble;                              // on convertis nos données en int et long int
        sscanf(tripid,"%ld",&tripiddouble);
        (list->stop_time[p]).trip_id=tripiddouble;
        int stopidint;
        sscanf(stopid,"%i",&stopidint);
        (list->stop_time[p]).stop_id=stopidint;
        int stop_sequenceint;
        sscanf(stopsequence,"%i",&stop_sequenceint);
        (list->stop_time[p]).stop_sequence=stop_sequenceint;


        
        /* char * h1 =strtok(HA,":");                       // on choisit de noter l'heure en secondes
        char * m1 =strtok(NULL,":");                    //c'est a dire par exemple:
        int h1int= atoi(h1);
        int m1int= atoi(m1);                                 // 13h45 est noté en seconde 13*3600 + 45*60 
        int heure_arrive2=((h1int)*3600)+((m1int)*60); */

        (list->stop_time[p]).heure_arrive=heure_en_seconde(HA);


        /* heure_en_seconde(HD);
        char * h2 =strtok(HD,":");
        char * m2 =strtok(NULL,":");
        int h2int= atoi(h2);
        int m2int= atoi(m2); 
        int heure_depart2=((h2int)*3600)+((m2int)*60); */

        (list->stop_time[p]).heure_depart=heure_en_seconde(HD);

        p++;    

        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    }
    return 1;
}



int fstop_times(int BOOL, listes * list)
{ 
    FILE * stoptext;
    open_File("../Gtfstxt/stop_times.txt",&stoptext);
    
    char str[200];                                      // on lit la premeire ligne (qui ne sert a rien ici)
    read_1_line_in_file(str,200,&stoptext);

    fill_struc_stop_time(&stoptext, list);
    
    write_stop_time(NBR_STOP_TIMES,"stop_times",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}
