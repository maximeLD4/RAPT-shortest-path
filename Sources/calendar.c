#include"struct.h"

#include "calendar.h"



int write_calendar(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/calendartest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*****************\n****%s[%i]**** \nservice_id : %i\nstart_date : %i\nend_date: %i\n",fonctionExtractrice,j,list->calendar[j].service_id,list->calendar[j].start_date,list->calendar[j].end_date);
    }
    return 1;
}


int fill_struc_calendar(FILE ** name,listes * list)
{
    char txt='o';                       
    int p=0;
    while (txt !=EOF)                                   // on boucle la lecture d'un ligne
    {                                                   // tant qu'on a pas ateint la fin du fichier
        char str2[200];
        fgets(str2, 200, *name);
        char * serviceid=strtok(str2,","); 
        
        char * lundi=strtok(NULL,",");        
        char * mardi=strtok(NULL,",");            // chaque ligne a son format particulier    
        char * mercredi=strtok(NULL,",");
        char * jeudi=strtok(NULL,",");
        char * vendredi=strtok(NULL,",");
        char * samedi=strtok(NULL,",");
        char * dimanche=strtok(NULL,",");

        char * start_date=strtok(NULL,",");
        char * end_date=strtok(NULL,",");




        int serviceidint;                              // on convertis nos données en int et long int
        sscanf(serviceid,"%i",&serviceidint);
        (list->calendar[p]).service_id=serviceidint;
        int startd;                              // on convertis nos données en int et long int
        sscanf(start_date,"%i",&startd);
        (list->calendar[p]).start_date=startd;
        int endd;                              // on convertis nos données en int et long int
        sscanf(end_date,"%i",&endd);
        (list->calendar[p]).end_date=endd;
        p++;

        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    } 
    return 1;
}


int fcalendar(int BOOL, listes * list)
{ 
    FILE * stoptext;
    open_File("../Gtfstxt/calendar.txt",&stoptext);
    
    char str[200];                                      // on lit la premeire ligne (qui ne sert a rien ici)
    read_1_line_in_file(str,200,&stoptext);

    fill_struc_calendar(&stoptext,list);
    
    write_calendar(NBR_CALENDAR,"calendar",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}
