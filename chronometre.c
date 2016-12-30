#include <time.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
clock_t debut, fin ;
long clk_tck = CLOCKS_PER_SEC ;
double difference ;
int touche, escape ;



char text[] = "Appuyez sur espace pour stopper le chronomètre"; 
printf("%s",text) ;
debut=clock();
do
{
do
{
touche=getchar() ;
} while(touche!=' ') ;

system("cls") ;

fin=clock() ;
difference = (double)(fin-debut)/(double)clk_tck ;

printf("\n\nIl s'est ecoule %lf secondes\n\n", difference*10000) ;
escape=getchar() ;
} while(escape!=27) ;





return 0;
}

