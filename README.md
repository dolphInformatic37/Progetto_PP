# Programma per l'Unione e la Differenza di Linguaggi Finiti

## Specifica del Problema
Un alfabeto è un insieme finito di simboli. Un linguaggio finito su un alfabeto è un insieme finito
di sequenze di lunghezza finita di simboli dell’alfabeto. Dato un alfabeto {a, e, i, o, u}, viene scritto un
programma ANSI C che acquisisce da tastiera due linguaggi finiti su quell’alfabeto e poi stampa
sullo schermo l’unione dei due linguaggi e la differenza tra il primo linguaggio e il secondo.
Almeno una delle due operazioni verrà essere calcolata ricorsivamente.

## Analisi del Problema
### Dati di Ingresso del Problema
I dati di ingresso del problema sono rappresentati da due linguaggi finiti sull’alfabeto dato.
### Dati di Uscita del Problema
I dati di uscita del problema sono rappresentati dall’unione dei due linguaggi e dalla differenza
tra il primo linguaggio ed il secondo.
### Relazioni Intercorrenti tra i Dati del Problema
L’unione di due insiemi, indicata con il simbolo “∪”, è un'operazione binaria insiemistica che
restituisce l'insieme contenente tutti gli elementi del primo insieme e tutti gli elementi del
secondo insieme. In tale caso si afferma che "A è unito a B" e si scrive A ∪ B.

A ∪ B := { x | x ∈ A ∨ x ∈ B }

La differenza fra due insiemi, indicata con il simbolo - oppure \, è un'operazione binaria
insiemistica che, dati due insiemi A e B, restituisce l'insieme degli elementi di A che non
appartengono anche a B. L'operazione di differenza si legge "A meno B" e può essere scritta nel
seguente modo:

A - B := { x | x ∈ A e x ∉ B }

## Progettazione dell’Algoritmo
### Scelte di Progetto
I linguaggi da trattare si prestano in modo naturale a essere rappresentati mediante array di
caratteri. Al fine di non imporre limitazioni rispetto alla specifica del problema, gli array
verranno allocati dinamicamente in memoria chiedendo all’utente la quantità di elementi presenti
all'interno dei due linguaggi.
Nel caso in cui l’utente decida che il primo dei due linguaggi sia privo di elementi, verrà
stampato a schermo il secondo linguaggio come unione, mentre per la differenza risulterà esserci
un insieme vuoto (privo di elementi).
Nel caso in cui l’utente decida che il secondo dei due linguaggi sia privo di elementi, verrà
stampato a schermo solo il primo linguaggio per entrambi i risultati.
Nel caso in cui l’utente decida che entrambi i linguaggi siano privi di elementi, verrà stampato a
schermo che sia l’unione sia la differenza tra il primo linguaggio ed il secondo risulteranno essere
un insieme vuoto (privo di elementi).
Nel caso in cui l’utente decida di inserire all’interno di un linguaggio solo un elemento
rappresentante il vuoto, dovrà porre in input il carattere “v” all’inizio della stringa.
Nel caso in cui l’utente decida di separare mediante barra spaziatrice vari caratteri, verrà
considerato solo ciò che ne precede l’inserimento.
### Passi dell’Algoritmo
I passi dell’algoritmo per risolvere il seguente problema sono i seguenti:
1. Acquisire la dimensione del primo linguaggio e allocare la memoria necessaria.
2. Acquisire la dimensione del secondo linguaggio e allocare la memoria necessaria.
3. Acquisire le parole del primo linguaggio.
4. Acquisire le parole del secondo linguaggio.
5. Calcolare l’unione (ricorsivamente) e la differenza tra i due linguaggi.
6. Stampare a schermo i risultati.
Per evitare ridondanze di codice nei primi due passi dell’algoritmo, è necessario sviluppare un
sottoprogramma che si occupi di acquisire la quantità di stringhe contenute all’interno di un
linguaggio, da utilizzare due volte.
Per evitare ridondanze di codice nel terzo e nel quarto passo dell’algoritmo, è necessario
sviluppare un sottoprogramma che si occupi di acquisire le stringhe contenute all’interno di un
linguaggio, da utilizzare due volte.

## Implementazione dell’Algoritmo
Il programma è stato implementato nel file `linguaggi.c`. Per compilare il programma, esegui il seguente comando nel terminale:

```bash
make
```
Se non hai make installato, puoi compilare manualmente il programma usando il tuo compilatore C preferito. Ad esempio, con GCC, puoi utilizzare il comando:
```
gcc -ansi -Wall -O linguaggi.c -o linguaggi
```
Una volta compilato il programma, eseguilo digitando il seguente comando nel terminale:
```
./linguaggi
```

Segui poi le istruzioni a schermo per inserire i linguaggi.
