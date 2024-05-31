/* programma per ottenere unione e differenza di due linguaggi */

/* inclusione delle librerie */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* dichiarazione delle funzioni */
void allocazione_memoria(char ***,
						             int *);

void acquisizione_linguaggio(char **,
							               int);
void unione(char **,
	          char **,
			      int,
			      int,
			      int,
		    	  int,
			      int,
			      int);
void differenza(char **,											
		 	          char **,
        				int,
				        int);

/* definizione delle funzioni */

/* definizione della funzione main */
int main(void)
{
	/* dichiarazione delle variabili locali della funzione */
	char **ling1, 	/* input: parole contenute nel primo linguaggio */
	     **ling2; 	/* input: parole contenute secondo linguaggio */
	int dim1,	  	  /* input: numero di parole nel primo linguaggio */
		  dim2,	      /* input: numero di parole nel secondo linguaggio */
		  diverse,    /* lavoro: numero di parole diverse fre loro */
		  s,			    /* lavoro: indice per la stampa dei linguaggi */
		  m,			    /* lavoro: indice per il confronto dei linguaggi */
		  n;	  	   	/* lavoro: indice per il confronto dei linguaggi */

	/* allocare la memoria necessaria per i linguaggi */
	printf("-Primo linguaggio-\n\n");
	allocazione_memoria(&ling1,
						          &dim1);
	printf("\n-Secondo linguaggio-\n\n");
	allocazione_memoria(&ling2,
						          &dim2);

	/* acquisire il primo linguaggio */
	if (dim1 > 0)
	{
		printf("\nDigita le parole del primo linguaggio\n");
		printf("una alla volta seguite da invio\n");
		acquisizione_linguaggio(ling1,
								            dim1);
	}
	
	/* acquisire il secondo linguaggio*/
	if (dim2 > 0)
	{	
    printf("\nDigita le parole del secondo linguaggio\n");
		printf("una alla volta seguite da invio\n");
		acquisizione_linguaggio(ling2,
								            dim2);
	}
	
	/* inzializzo le variabili a 0 */
	diverse = 0;
	s = 0; 
	m = 0;
	n = 0;

	/* stampa dell'unione dei due linguaggi */
	printf("\nL'unione dei due linguaggi è\n");

	unione(ling1,
		     ling2,
		     dim1,
		     dim2,
		     diverse,
		     s,
		     m,
		     n);

	/* stampa della differenza dei due linguaggi */
	printf("\nLa differenza dei due linguaggi è\n");

	differenza(ling1,
  			     ling2,
  			     dim1,
			       dim2);
	
	return(0);
}

/* definizione della funzione per allocare la memoria necessaria */
void allocazione_memoria(char ***ling,  /* output: conterrà le parole del linguaggio */
						 int *dim)		/* input: numero di parole nel linguaggio */
{
	/* dichiarazione delle variabili locali della funzione */
	int esito_lettura, 			/* lavoro: esito della scanf */
		acquisizione_errata;	/* lavoro: controllo validità */
	
	do
	{
		printf("Da quante parole sarà formato il linguaggio? (>= 0): ");
		esito_lettura = scanf("%d",
						  	  dim);
		acquisizione_errata = esito_lettura != 1 || *dim < 0;
		if (acquisizione_errata)
			printf("Valore non accettabile!\n");
		while (getchar() != '\n');
	}
	while (acquisizione_errata);
	
	/* allocazione memoria */
	(*ling) = (char**)calloc((*dim), sizeof(char*));
	if ((*ling) == NULL)
		printf("Errore nell'allocazione della memoria");
}

/* definizione della funzione per acquisire un linguaggio */
void acquisizione_linguaggio(char **ling, /* output: conterrà le parole del linguaggio */
						     int dim)	  /* input: numero di parole nel linguaggio */
						     
{
	/* dichiarazione delle variabili locali della funzione */
	int verifica,	/* lavoro: verifica validità */
	    a,			/* lavoro: indica la posizione all'interno del linguaggio */
		p;			/* lavoro: indica la posizione delle lettere */
	
	if (dim > 0)
	{
		printf("composte dall'alfabeto {a,e,i,o,u}\n");
		printf("(per porre termini vuoti inserire 'v'\n");
		printf("come primo carattere)\n\n");
	}
	
	for (a = 0; a < dim ; a++)
	{
		do 
		{
			verifica = 0;
			scanf("%ms",
			      &ling[a]);
			while (getchar() != '\n');

			/* controllo validazione caratteri */
			for (p = 0; p < strlen(ling[a]) && verifica != 1; p++) 
				if (ling[a][p] != 'a' && ling[a][p] != 'e' && 
					ling[a][p] != 'i' && ling[a][p] != 'o' &&
					ling[a][p] != 'u' && ling[a][0] != 'v')
					verifica = 1;
			/* controllo ripetizioni e termini vuoti */
			for (p = 0; p < a && verifica != 1; p++)
				if (strcmp(ling[a], ling[p]) == 0 || (ling[a][0] == 'v' && ling[p][0] == 'v'))
					verifica = 1;
			
			if (verifica == 1)
				printf("Inserimento non valido, riprova\n");

			if (ling[a][0] == 'v')
				ling[a] = "v";
				
		}while(verifica == 1);
	}
}

void unione(char **ling1, 	/* input: parole contenute nel primo linguaggio */
	        char **ling2, 	/* input: parole contenute secondo linguaggio */
	        int dim1,	  	/* input: numero di parole nel primo linguaggio */
			int dim2,		/* input: numero di parole nel secondo linguaggio */
			int diverse, 	/* lavoro: numero di parole diverse fre loro */
			int s,			/* lavoro: indice per la stampa dei linguaggi */
			int m,			/* lavoro: indice per il confronto dei linguaggi */
			int n) 		    /* lavoro: indice per il confronto dei linguaggi */
{
	
	/* caso base dell'unione ricorsiva */
	if (dim1 == 0 && dim2 == 0)
	{
		printf("un insieme vuoto");
	}
	/* caso generale dell'unione ricorsiva */
	else
	{
		if (dim2 == 0 && s < dim1)
		{
			printf("%s\n",
				   ling1[s]);

			unione(ling1,
				   ling2,
				   dim1,
				   dim2,
				   diverse,
				   s + 1,
				   m,
				   n);		
		}

		else if (dim1 == 0 && s < dim2)
		{
			printf("%s\n",
				   ling2[s]);

			unione(ling1,
				   ling2,
				   dim1,
				   dim2,
				   diverse,
				   s + 1,
				   m,
				   n);
		}

		else if (dim1 > 0 && dim2 > 0)
		{
			if (s < dim1)
			{
				printf("%s\n",
				       ling1[s]);

				unione(ling1,
					   ling2,
					   dim1,
					   dim2,
					   diverse,
					   s + 1,
					   m,
					   n);
			}
			else
			{
				if (strcmp(ling2[m], ling1[n]) != 0)
				{
					diverse++;
					if (diverse == dim1)
					    printf("%s\n",
					           ling2[m]);
				}
				if (n < (dim1 - 1))
					unione(ling1,
						   ling2,
						   dim1,
						   dim2,
						   diverse,
						   s,
						   m,
						   n + 1);		   
				else if (m < (dim2 - 1))
					unione(ling1,
						   ling2,
						   dim1,
						   dim2,
						   diverse = 0,
						   s,
						   m + 1,
						   n = 0);
			}
		}
	}
}

void differenza(char **ling1,
				char **ling2,
				int dim1,
				int dim2)
{
	/* dichiarazione delle variabili locali della funzione */
	int d,			/* lavoro: permette la stampa del risultato della differenza*/
		x,			/* lavoro: permette la stampa del risultato della differenza*/
		y,			/* lavoro: permette la ripetizione del confronto fra parole */
		diff = 0;	/* lavoro: numero di parole differenti */
	
	/* caso in cui il primo linguaggio o entrambi siano vuoti */
	if (dim1 == 0 || (dim1 == 0 && dim2 == 0))
	{
		printf("un insieme vuoto");
	}

	/*caso in cui il secondo linguaggio sia vuoto*/
	else if (dim2 == 0)
	{
		for (d = 0; d < dim1; d++)
			printf("%s\n",
				   ling1[d]);
	}
	/* caso in cui in entrambi i linguaggi non siano vuoti */
	else if (dim1 > 0 && dim2 > 0)
	{
		for (d = 0; d < dim1; d++)
		{

			x = 0;

			for (y = 0; y < dim2; y++)
			{
				if (strcmp(ling1[d], ling2[y]) == 0)
					x++;
			}
			if (x == 0)
			{
				printf("%s\n",
					   ling1[d]);
			}
			else
				diff = diff + x;
		}
		if (diff == dim1)
			printf("nessuna\n");
	}
}
