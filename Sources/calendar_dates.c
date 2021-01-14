#include"struct.h"

#include "calendar_dates.h"


int fill_struc_calendar_date(FILE ** name,listes * list)
{
    char txt='o';                       
    int p=0;
    while (txt !=EOF)                                   // on boucle la lecture d'un ligne
    {                                                   // tant qu'on a pas ateint la fin du fichier
        char str2[200];
        fgets(str2, 200, *name);
        char * serviceid=strtok(str2,",");            // chaque ligne a son format particulier    
        char * date=strtok(NULL,",");


        int serviceidint;                              // on convertis nos données en int et long int
        sscanf(serviceid,"%i",&serviceidint);
        ((list)->calendar_date[p]).service_id=serviceidint;
        int dateint;                              // on convertis nos données en int et long int
        sscanf(date,"%i",&dateint);
        ((list)->calendar_date[p]).date=dateint;                             // on convertis nos données en int et long int
        
        p++;
        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    }
    return 1;
}


int write_calendar_date(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/calendardatestest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*****************\n****%s[%i]**** \nservice_id : %i\ndate : %i\n",fonctionExtractrice,j,list->calendar_date[j].service_id,list->calendar_date[j].date);
    }
    return 1;
}


int fcalendar_dates(int BOOL,listes * list)
{ 
    FILE * stoptext;    
    open_File("../Gtfstxt/calendar_dates.txt",&stoptext);

    char str[200];
    read_1_line_in_file(str,200,&stoptext);

    fill_struc_calendar_date(&stoptext,list);
    
    write_calendar_date(NBR_CALENDAR_DATE,"calendar_dates",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}
