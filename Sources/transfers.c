#include"struct.h"

#include"transfers.h"


int fill_struc_transfers(FILE ** name, listes * list)
{
    char txt='o';                       
    int p=0;
    while (txt !=EOF)                                   // on boucle la lecture d'un ligne
    {                                                   // tant qu'on a pas ateint la fin du fichier
        char str2[200];
        fgets(str2, 200, *name);
        char * stopavantid=strtok(str2,","); 
        char * stopapresid=strtok(NULL,",");        
        char * type=strtok(NULL,",");            // chaque ligne a son format particulier    
        char * temps=strtok(NULL,",");

        int stopavantiddouble;                              // on convertis nos données en int et long int
        sscanf(stopavantid,"%i",&stopavantiddouble);
        (list->transfers[p]).stop_id_prec=stopavantiddouble;
        int stoppapresiddouble;                              // on convertis nos données en int et long int
        sscanf(stopapresid,"%i",&stoppapresiddouble);
        (list->transfers[p]).stop_id_prox=stoppapresiddouble;

        int m1int=atoi(temps);                     // ainsi on pourra bien comparer les horaires

        (list->transfers[p]).temps_trans=m1int;


        p++;

        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    }
    return 1;
}


int write_transfers(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/transferstest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*****************\n****%s[%i]**** \nstop_id_dep : %i\nstop_id_arr : %i\ntemps: %i\n",fonctionExtractrice,j,list->transfers[j].stop_id_prec,list->transfers[j].stop_id_prox,list->transfers[j].temps_trans);
    }
    return 1;
}


int ftransfers(int BOOL,listes * list)
{
    FILE * stoptext;
    open_File("../Gtfstxt/transfers.txt",&stoptext);
    
    char str[200];
    read_1_line_in_file(str,200, &stoptext);

    fill_struc_transfers(&stoptext,list);
    
    write_transfers(NBR_TRANSFERS,"transfers",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}
