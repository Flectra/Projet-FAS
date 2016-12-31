#include "grovepi.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


//Compilation : gcc instrument.c grovepi.c -Wall -o instrument
//Execution : sudo ./instrument

#define us_cmd 7

char * saisir_chaine(char * lpBuffer, int buf_size)
{
    char * ret = fgets(lpBuffer, buf_size, stdin);

    if (ret != NULL)
    {
        char * p = strchr(lpBuffer, '\n');
        if (p != NULL)
            *p = '\0';
        else
        {
            int c;

            do
                c = getchar();
            while (c != EOF && c != '\n');
        }
    }

    return ret;
}
 
int main(void)
{

char touche=' ';
printf("faisons un peu de musique\n");


//touche= getchar();	
	if(init()==-1)
                exit(1);
        int LED = 3; // LED branchée sur le port D3 (digital 3)
        //Set pin mode to input
        pinMode(LED,0);  // indique que ce port est utilisé en Entrée
        
 //Exit on failure to start communications with the GrovePi
        if(init()==-1)
                exit(1);
	int PIN = 4; // Capteur branché sur le port D4 (digital 4)
        int data;
	char *note;
	int valeur=digitalRead (LED);// prend la valeur 1 que si on appuye sur le bouton
	do{        
	if(valeur==0) // boucle condition d'arrêt : on a appuyé sur le bouton
        {
          write_block(us_cmd, PIN, 0, 0);
          pi_sleep(50);
          read_byte();
          read_block();
          data=r_buf[1]* 256 + r_buf[2];
	  if (data<5)
	  {note="60";}
	  else if ( data <10)
	  {note="62";}
	  else if  (data<15){
	  note="64";}
	  else if (data<20){
	  note="65";}
	  else if (data<25){
	  note="67";}
	  else if(data<30){
	  note="69";}
	  else if(data<35){
	  note="71";}
	  else {
	  note ="81";}
          pi_sleep(100); // attend 100ms
	  FILE *f = fopen("musique_live.txt","w");
	  fprintf(f, "%s.\n", note);
	  fclose(f);
	  FILE *f2 = fopen("musique.txt","a");
	  fprintf(f2,"%s.\n",note);
	  fclose(f2);  
        }
	else{
	char *message ="arrêt";
	FILE *f = fopen("musique_live.txt","a");
	fprintf(f,"%s.\n",message);
	fclose(f);
	touche= 'a';}
	}while (touche ==' ');
	pi_sleep(100);
	printf(" Joli Morceau ! Voulez vous le réécouter ? Si oui, rappuyez donc sur le bouton!");
	int i = 10;
	do{
	printf("%i",i);
	i=i-1;
	pi_sleep(1000);}
	while(valeur==0 &&i>0);

	if ((valeur ==1) && (i<10)) /*si on appuye sur le bouton avant la fin du compte à rebours*/
	{printf("Là faut coder pour changer musique.txt en musique_live.txt");
	//http://melem.developpez.com/tutoriels/langage-c/fichiers/?page=cours#LI-E
	char * saisir_chaine(char * lpBuffer, int buf_size);
	saisir_chaine("musique.txt", sizeof("musique.txt"));

    	FILE *fsrc  = fopen("musique.txt", "rb");
        saisir_chaine("musique_live.txt", sizeof("musique_lve.txt"));
        FILE *fdest = fopen("musique_live.txt", "wb");
        int compt;
        while ((compt = getc(fdest)) != EOF)
        	putc(compt, fsrc);

        fclose(fsrc);
        // printf("Copie terminee.\n");
	}
	return 1;
	}

