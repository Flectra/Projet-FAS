#include "grovepi.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


//Compilation : gcc main.c grovepi.c -Wall -o main
//Execution : sudo ./main

#define us_cmd 7
 
int main(void)
{
<<<<<<< HEAD
	
=======
>>>>>>> 486aa9ab0edc43f259272528aba1720c573abd69
	char id[100];
	char id2[100];
	printf("Comment t'appelles tu petit Zero ? \n");
	fgets(id2, 100, stdin);
	printf("prêt pour la course ? %s  Va sur la ligne de départ et attend le signal sonore\n",id2);
	if(init()==-1)
                exit(1);
        int LED = 3; // LED branchée sur le port D3 (digital 3)
        //Set pin mode to output
        pinMode(LED,1);  // indique que ce port est utilisé en SORTIE
        printf("3\n");
        digitalWrite(LED,1); // envoie "HIGH" sur le port LED (allume la LED)
        pi_sleep(100); // attend 100ms
        digitalWrite(LED,0); // envoie "LOW" : éteind la LED
        pi_sleep(900); // attend 900ms
	printf("2\n");
	digitalWrite(LED,1); // envoie "HIGH" sur le port LED (allume la LED)
        pi_sleep(100); // attend 100ms
        digitalWrite(LED,0); // envoie "LOW" : éteind la LED
        pi_sleep(900); // attend 900ms
	printf("1\n");
        digitalWrite(LED,1); // envoie "HIGH" sur le port LED (allume la LED)
        pi_sleep(100); // attend 100ms
        digitalWrite(LED,0); // envoie "LOW" : éteind la LED
        pi_sleep(900); // attend 900ms
	printf("GO !\n");
	int j =0;
	while(j<=6)
        {
	digitalWrite(LED,1); // envoie "HIGH" sur le port LED (allume la LED)
        pi_sleep(50); // attend 100ms
        digitalWrite(LED,0); // envoie "LOW" : éteind la LED
        pi_sleep(100); // attend 900ms
	j=j+1;
	}
	
<<<<<<< HEAD
	clock_t debut,fin;
	debut=clock();
=======
	time_t debut,fin;
	debut=time(NULL);
>>>>>>> 486aa9ab0edc43f259272528aba1720c573abd69
 //Exit on failure to start communications with the GrovePi
        if(init()==-1)
                exit(1);
	int PIN = 4; // Capteur branché sur le port D4 (digital 4)
        int data;
	int arret=0;
        while(arret==0) // boucle condition d'arrêt : distance < 50cm
        {
          write_block(us_cmd, PIN, 0, 0);
          pi_sleep(200);
          read_byte();
          read_block();
          data=r_buf[1]* 256 + r_buf[2];
          pi_sleep(100); // attend 100ms
	  if(data<50)
	{	arret=1;
<<<<<<< HEAD
		fin=clock();
=======
		fin=time(NULL);
>>>>>>> 486aa9ab0edc43f259272528aba1720c573abd69
	}
        }
	//long clk_tck = CLOCK_PER_SEC ;
	double difference ;
	double diff = difftime(fin,debut); 	
<<<<<<< HEAD
	difference = (double)(fin-debut)/CLOCKS_PER_SEC; 
	printf("Temps : %lf seconde\n\n",difference*10000);
=======
	difference = (double)(fin-debut); 
	printf("Temps : %lf seconde\n\n",difference);
>>>>>>> 486aa9ab0edc43f259272528aba1720c573abd69
	printf("2eTest Temps : %lf secondes \n",diff);
	printf("Arrêt\n");
	return 1;

}



<<<<<<< HEAD

=======
>>>>>>> 486aa9ab0edc43f259272528aba1720c573abd69
