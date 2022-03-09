# Arduino_tornio_project
In seguito a una serie di lezioni in classe con l'obbiettivo di presentarci l'hardware Arduino, il profe ci ha richiesto di sviluppare un progetto a scelta, che comunicasse con Python, tramite porta seriale.

## idea e pianificazione
A quel punto abbiamo avuto l'idea di ricreare un tornio che eseguisse tramite dei nostri input una sequenza di spostamenti della testina in automatico.
Per dare questi input abbiamo deciso di sfruttare un bot telegram il quale avrebbe dobuto far partire e stoppare tutto l'algoritmo tramite appositi coimandi da remoto.

## ragionamenti tecnici e materiali
Abbiamo iniziato a pensare con quali materiali lavorare e la nostra scelta infine è ricaduta su 3 motori diversi:

- motore RC              (il motore principale del tornio)
- motore passo-passo     (motore che permetteva lo spostamento della testina)
- servo motore           (testina)
        
I 3 motori avrebbero dovuto funzionare in 3 modi e tempi diversi e sarebbero dovuti essere in grado di lavorare coordinati con la seguente logica:

il motore passo passo, ovvero un motore controllabile in qualsiasi suo movimento, tramite la quantità di 
passi che esso deve fare, e tramite il suo motimento spostiamo il servo motore,con montata la testina in parallelo al pezzo da incidere.

## sviluppo
L'ultimo passo prima della reale scrittura del codice era la composizione, era il momento di montare su breadbord le nostre idee e i nostri motori decidendo anche di aggiungerci un led, il quale ci avrebbe dovuto segnalare  lo stato del tornio (acceso/spento)  

il progetto in se, a livello fisico si compone di tre motori: il motore passo passo, ovvero un motore controllabile in qualsiasi suo movimento, tramite la quantità di 
passi che esso deve fare, e tramite il suo motimento spostiamo il servo motore,con montata la testina in parallelo al pezzo da incidere.
successivamente abbiamo sfruttato un servo motore, ovvero un motore che muove il l'albero di un certo tot di gradi.
questo motore è il motore che abbiamo sfruttato per l'offset della testina, ovvero quanto far entrare essa nel pezzo, così da inciderlo.
infine abbiamo sfruttato un semplice motore rc, questo motore ci è servito come motore principale del tornio, infatti è il motore che fa sì che il pezzo ruoti, e di con-
seguenza possa essere inciso dalla testina.
infine abbiamo aggiunto un semplice diodo led di colore rosso, che si accenda quando il macchinario sta funzionando, principalmente come misura di sicurezza nei confronti
di un eventuale operaio che lo debba aprire per estrarre il pezzo.


FASI DEL PROGETTO

il progetto si è diviso in: 

IDEA

    Pensare alla fattibilità del progetto
    
    Possibili sbocchi commerciali
    
    Funzionalità necessarie
    
SVILUPPO

    Scelta dei corretti componenti
    
    Scelta linguaggio e bot
    
    Montaggio arduino
    
    Sviluppo codice
    
        Arduino
        
        Bot telegram
        
CONCLUSIONI

    Aggiunta nuove feature
    
    Test di funzionamento
    
    
CODICE PYTHON:

    Fase di listening
            il bot si mette in attesa di ricevere un messaggio, e di conseguenza di far partire l'Arduino

    Fase di start
            il bot riceve il messaggio "/begin", e manda un messaggio ad Arduino che fa partire il codice

    Fase di stop
            il bot riceve il messaggio "/stop", e manda un messaggio ad Arduino che fa interrompe il codice.                                                                                 il messaggio serve in caso di un stop d'emergenza

PARTE FISICA CON ARDUINO:
        
    Motore Passo-Passo:
        Funziona tramite degli step, che gli consentono di andare avanti, indietro, e a velocità diverse.
        E' molto versatile e noi lo usiamo per muovere la il servo motore avanti e indietro   

    Servo motore:
        Funziona tramite una rotazione di x gradi, 0 <= x <= 180.
        E noi lo abbiamo sfruttato per muovere la testina avanti e indietro

    Motore RC:
        Funziona solo se alimentato, quindi senza programmazione , in base alla polarizzazione, e a velocità fissa.                                                                       Lo abbiamo sfruttato come motore principale, ovvero che muove il pezzo da incidere
