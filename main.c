#include "grovepi.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


//Compilation : gcc main.c grovepi.c -Wall -o main
//Execution : sudo ./main

#define us_cmd 7
 
int main(void)
{
	clock_t debut,fin;
	debut=clock();
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
          printf("%d %d\n", r_buf[1], r_buf[2]);
          printf("Distance : %d cm\n", data);
          pi_sleep(100); // attend 100ms
	  if(data<50)
	{	arret=1;
		fin=clock();
	}
        }
	long clk_tck = CLOCKS_PER_SEC ;
	double difference ; 	
	difference = (double)(fin-debut)/(double)clk_tck; 
	printf("Temps : %lf seconde\n\n",difference);
	printf("Arrêt\n");
	return 1;

}



