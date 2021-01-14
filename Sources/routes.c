#include "routes.h"


int rechercheSeparteur(char * str)
{
    int j=0;                   //on pourrait commencer a 16 dans certain cas.. dommage
    int coef2=0;                
    while(str[j]!='\0')
    {
        if (str[j]=='<')
        {
            coef2=2;
            break;
        }
        j++;
    }
    return coef2;
}



int rechercheSlash(char * str)
{
    int j=0;                   //on pourrait commencer a 16 dans certain cas.. dommage
    int coef1=0;                
    while(str[j]!='\0')
    {
        if (str[j]=='/')
        {
            coef1=1;
            break;
        }
        j++;
    }
    return coef1;
}




int rechercheParentheses(char * str)
{
    //int j=0;                   //on pourrait commencer a 16 dans certain cas.. dommage
    int coef=0;  
    int len=strlen(str);
    for (int j=0; j<len;j++)              
    //while(str[j]!='\0')
    {
        if (str[j]=='(')
        {
            coef=1;
            break;
        }
        //j++;
    }
    return coef;
}



void fillShortName(int p,char * str5,listes * list)
{
    int k=0;
    while(str5[k]!='\0')
    {
        ((list)->routes[p]).Rshortname[k]=str5[k];
        k++;
    }
    ((list)->routes[p]).Rshortname[k]='\0';
}



void fillNoneStr(char * str)
{
    char * str_none="NONE";
    for (int i=0; i<4; i++)
    {
        str[i]=str_none[i];
    }
    str[4]='\0';
}


void fillCoef0(int routeidint,char * str5,char * str1, int p,listes * list)
{    
    list->routes[p].route_id=routeidint;
    fillShortName(p,str5,list);
    int n=strlen(str1);
    int k1=0;
    int k6=0;
    int k2=0;
    int k3=0;
    int k5=0;

    if (str1[n-5]=='A')                                         // on regarde si c'est un aller ou un retour
    {
        while(str1[k1]!='(' || str1[k1]==' ')
        {
            k1++;
        }
        while(str1[k1+1]!='<')
        {
            (list->routes[p]).DepartExtremite[k6]=str1[k1+1];
            k1++;
            k6++;
        }
        list->routes[p].DepartExtremite[k6]='\0';
        while(str1[k1+5]!=')')
        {
            list->routes[p].ArriveExtremite[k2]=str1[k1+5];
            k1++;
            k2++;
        }
        list->routes[p].ArriveExtremite[k2]='\0';
    }
    else if (str1[n-6]=='R')                                         // on regarde si c'est ou aller ou un retour
    {   
        while(str1[k1]!='(' || str1[k1]==' ')
        {
            k1++;
        }
        while(str1[k1+1]!='<')                                      //et on parcours la ligne, avec les separateurs <-> et -,)
        {
            list->routes[p].ArriveExtremite[k5]=str1[k1+1];
            k1++;
            k5++;
        }
        list->routes[p].ArriveExtremite[k5]='\0';
        while(str1[k1+5]!=')')
        {
            list->routes[p].DepartExtremite[k3]=str1[k1+5];
            k1++;
            k3++;
        }
        list->routes[p].DepartExtremite[k3]='\0';
    }
}





void fillSlashAGauche(char * str1, int p, listes * list)
{
    int n=strlen(str1);
    int k1=0;
    if (str1[n-5]=='A')          // on regarde si c'est ou aller ou un retour
    {
        while(str1[k1+1]!='<')
        {
            (list->routes[p]).DepartExtremite[k1]=str1[k1+1];
            (list->routes[p+1]).DepartExtremite[k1]=str1[k1+1];
            k1++;
        }
        (list->routes[p]).DepartExtremite[k1]='\0';
        (list->routes[p+1]).DepartExtremite[k1]='\0';
        int k2=0;
        while(str1[k1+4]!='/')
        {
            (list->routes[p+1]).ArriveExtremite[k2]=str1[k1+4];
            k1++;
            k2++;
        }
        (list->routes[p+1]).ArriveExtremite[k2]='\0';
        int k3=0;
        while(str1[k1+5]!=')')
        {
            (list->routes[p]).ArriveExtremite[k3]=str1[k1+5];
            k1++;
            k3++;
        }
        (list->routes[p]).ArriveExtremite[k3]='\0';
    }
    else if (str1[n-6]=='R')                                         // on regarde si c'est ou aller ou un retour
    {
        while(str1[k1+1]!='<')
        {
            (list->routes[p]).ArriveExtremite[k1]=str1[k1+1];
            (list->routes[p+1]).ArriveExtremite[k1]=str1[k1+1];
            k1++;
        }
        (list->routes[p]).ArriveExtremite[k1]='\0';
        (list->routes[p+1]).ArriveExtremite[k1]='\0';
        int k2=0;
        while(str1[k1+4]!='/')
        {
            (list->routes[p+1]).DepartExtremite[k2]=str1[k1+4];
            k1++;
            k2++;
        }
        (list->routes[p+1]).DepartExtremite[k2]='\0';
        int k3=0;
        while(str1[k1+5]!=')')
        {
            (list->routes[p]).DepartExtremite[k3]=str1[k1+5];
            k1++;
            k3++;
        }
        (list->routes[p]).DepartExtremite[k3]='\0';
    }
}




void fillSlashADroite(char * str1, int p, listes * list)
{
    int n=strlen(str1);
    int k1=0;
    if (str1[n-5]=='A')          // on regarde si c'est ou aller ou un retour
    {
        while(str1[k1+1]!='/')
        {
            (list->routes[p+1]).DepartExtremite[k1]=str1[k1+1];
            k1++;
        }
        (list->routes[p+1]).DepartExtremite[k1]='\0';
        int k2=0;
        while(str1[k1+2]!='<')
        {
            (list->routes[p]).DepartExtremite[k2]=str1[k1+2];
            k1++;
            k2++;
        }
        (list->routes[p]).DepartExtremite[k2]='\0';
        int k3=0;
        while(str1[k1+5]!=')')
        {
            (list->routes[p]).ArriveExtremite[k3]=str1[k1+5];
            (list->routes[p+1]).ArriveExtremite[k3]=str1[k1+5];
            k1++;
            k3++;
        }
        (list->routes[p]).ArriveExtremite[k3]='\0';
        (list->routes[p+1]).ArriveExtremite[k3]='\0';
    }
    else if (str1[n-6]=='R')                                         // on regarde si c'est ou aller ou un retour
    {
        while(str1[k1+1]!='/')
        {
            (list->routes[p+1]).ArriveExtremite[k1]=str1[k1+1];
            k1++;
        }
        (list->routes[p+1]).ArriveExtremite[k1]='\0';
        int k2=0;
        while(str1[k1+2]!='<')
        {
            (list->routes[p]).ArriveExtremite[k2]=str1[k1+2];
            k1++;
            k2++;
        }
        (list->routes[p]).ArriveExtremite[k2]='\0';
        int k3=0;
        while(str1[k1+5]!=')')
        {
            (list->routes[p]).DepartExtremite[k3]=str1[k1+5];
            (list->routes[p+1]).DepartExtremite[k3]=str1[k1+5];
            k1++;
            k3++;
        }
        (list->routes[p]).DepartExtremite[k3]='\0';
        (list->routes[p+1]).DepartExtremite[k3]='\0';
    }
}




void fillSansSeparateur(int routeidint,char * str5,char * str1, int p, listes * list)
{
    (list->routes[p]).route_id=routeidint;
    fillShortName(p,str5,list);
    int n=strlen(str1);
    int k1=0;
    if (str1[n-5]=='A')                                         // on regarde si c'est ou aller ou un retour
    {
        int k=0;
        while(str1[k]!='(')
        {
            k++;
        }
        while(str1[k+1]!=')')
        {
            (list->routes[p]).DepartExtremite[k1]=str1[k+1];
            k1++;
            k++;
        }
        (list->routes[p]).DepartExtremite[k]='\0';
        fillNoneStr((list->routes[p]).ArriveExtremite);
    }
    else if (str1[n-6]=='R')                                         // on regarde si c'est ou aller ou un retour
    {
        int k=0;
        while(str1[k]!='(')
        {
            k++;
        }
        while(str1[k+1]!=')')
        {
            (list->routes[p]).ArriveExtremite[k1]=str1[k+1];
            k1++;
            k++;
        }
        (list->routes[p]).ArriveExtremite[k]='\0';
        fillNoneStr((list->routes[p]).DepartExtremite);
    }
}




void enleverParenthesesArrive(int p, listes * list)
{
    int k=0;
    int q=0;
    while((list->routes[p]).ArriveExtremite[k]!='\0')
    {
        if ((list->routes[p]).ArriveExtremite[k]==')' || (list->routes[p]).ArriveExtremite[k]=='(' )
        {
            k++;
        }
        else
        {
            (list->routes[p]).ArriveExtremite[q]=(list->routes[p]).ArriveExtremite[k];
            q++;
            k++;
        }
    }
    (list->routes[p]).ArriveExtremite[q]='\0';
}



void enleverParenthesesDepart(int p, listes * list)
{
    int k=0;
    int q=0;
    while((list->routes[p]).DepartExtremite[k]!='\0')
    {
        if ((list->routes[p]).DepartExtremite[k]==')' || (list->routes[p]).DepartExtremite[k]=='(' )
        {
            k++;
        }
        else
        {
            (list->routes[p]).DepartExtremite[q]=(list->routes[p]).DepartExtremite[k];
            q++;
            k++;
        }
    }
    (list->routes[p]).DepartExtremite[q]='\0';
}


int fill_struct_route(FILE ** name, listes * list)
{
    char txt='o';                       
    int p=0;
    while (txt !=EOF)                                   // on boucle la lecture d'une ligne
    {
        char str2[200];
        fgets(str2,200, *name);

        char * routeid=strtok(str2,",");
        char * a=strtok(NULL,",");                         // on vient récuperer ce qui nous interresse
        char * routeshortname=strtok(NULL,",");                          // a et b ne nous servent pas
        char * routelongname=strtok(NULL,",");

        int routeidint;
        sscanf(routeid,"%i",&routeidint);

        char * str5=strtok(routeshortname,"\"");
  

        char * str1=strtok(routelongname,"\"");                  // on va travailler sur le ligne ARRET1 <-> ARRET 2 - SENS
        int coef=rechercheSlash(str1);
        char * str4= malloc(sizeof(char)*(strlen(str1)+1)); 
        strcpy(str4,str1);
        if(rechercheSeparteur(str1)!=2)   // si il n'y a pas de "<->"
        {
            coef=2;
            fillSansSeparateur(routeidint,str5,str1,p,list);
        }
        else
        {
            if (coef==1)
            {
                char * a1=strtok(str4,">");              // on vient récuperer ce qui nous interresse
                char * b1=strtok(NULL,">");   
                
                (list->routes[p]).route_id=routeidint;
                (list->routes[p+1]).route_id=routeidint+1;
                fillShortName(p,str5,list);
                fillShortName(p+1,str5,list);

                if (rechercheSlash(a1))
                {
                    fillSlashADroite(str1,p,list);
                }
                else if (rechercheSlash(b1))
                {
                    fillSlashAGauche(str1,p,list);
                }
                char str3[300];                                      // on lit la premeire ligne (qui ne sert a rien ici)
                fgets(str3,300,*name); 
            }
            else if (coef==0)
            {
                fillCoef0(routeidint,str5,str1,p,list);
            }
        }
        if (rechercheParentheses(((list)->routes[p]).DepartExtremite)!=0)
        {
            enleverParenthesesDepart(p,list);
        }
        if (rechercheParentheses(((list)->routes[p]).ArriveExtremite)!=0)
        {
            enleverParenthesesArrive(p,list);
        }

        if (coef==1)
        {
            p=p+2; // on saute 1 ligne si on avait 2 station avec un '/' car on les enregistres les deux d'un coup
        }
        else
        {
            p=p+1;
        }
        coef=0;
        txt=fgetc(*name);
        if (txt!=EOF)
        {
            fseek(*name,-1,SEEK_CUR);
        }
    }   
    return 1;
}




int write_Routes(int nombredeligne,char * fonctionExtractrice, int * BOOL, listes * list)
{
    if (*BOOL!=1) {return 0;}
    FILE * file=fopen("../Saves/routestest.txt","w+");
    for (int j=0;j<nombredeligne;j++)
    {
        fprintf(file,"*******************\n****%s[%i]*****\n***METRO*N°[%s]****\n*******************\nroute_id : %i\nExtremite depart:%s\nExtremite arrivee:%s\n",fonctionExtractrice,j,((list)->routes[j]).Rshortname,list->routes[j].route_id,(list->routes[j]).DepartExtremite,list->routes[j].ArriveExtremite);
    }
    return 1;
}


int froutes(int BOOL, listes * list)
{
    FILE * stoptext;
    open_File("../Gtfstxt/routes.txt",&stoptext);
    
    char str[200];                                      // on lit la premeire ligne (qui ne sert a rien ici)
    read_1_line_in_file(str,200,&stoptext);

    fill_struct_route(&stoptext,list);
    write_Routes(NBR_ROUTES,"routes",&BOOL,list); //le BOOL (dernier arg) permet de faire ou non le test print
    return 1;
}

