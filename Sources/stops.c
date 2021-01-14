#include"stops.h"


int write_stops(int nombredeligne,char * fonctionExtractrice, int * BOOL,listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/stopstest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*****************\n****%s[%i]**** \nid : %i\nname: %s \n",fonctionExtractrice,j,list->stop[j].stop_id,list->stop[j].sname);
    }
    return 1;
}


int fill_struc_stops(FILE ** name,listes * list)
{
    char txt='o';
    int p=0;
    while (txt !=EOF)
    {
        int a;
        char str2[200];
        fgets(str2, 200, *name);
        sscanf(str2,"%i",&a);
        (list->stop[p]).stop_id=a;

        int i=0;
        while (str2[i]!=',')
        {
            i++;
        }
        i+=2;
        int k=0;
        while (str2[i]!=',')
        {
            if(str2[i]!='\"')
            {
                (list->stop[p]).sname[k]=str2[i];
                k++;
            }
            i++;
        }
        (list->stop[p]).sname[k]='\0';
        
        p++;
        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    }
    return 1;
}


int fstops(int BOOL,listes * list)
{
    FILE * stoptext;    
    open_File("../Gtfstxt/stops.txt",&stoptext);

    char str[200];
    read_1_line_in_file(str,200,&stoptext);

    fill_struc_stops(&stoptext,list);
    
    write_stops(NBR_STOPS,"stops",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}
