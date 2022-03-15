## Arduino_tornio_project
Dopo averci presentato Arduino in classe, il profe ci ha richiesto di sviluppare un progetto a scelta, che avrebbe dovuto comunicare con Python tramite porta seriale.
A quel punto abbiamo avuto l'idea di creare un tornio che in seguito alla ricezione di determinati comandi avrebbe dovuto spostare una testina in automatico.
Per inviare questi comandi abbiamo deciso di creare un bot tramite l'ausilio della nota piattaforma di messaggistica Telegram, la quale avrebbe dovuto comunicare con Python
Il bot ci avrebbe consentito quindi di avviare il tornio da remoto e di fermarlo per una qualsiasi emergenza.

Dopo aver montato il tutto su breadbord e aver scritto il codice siamo riusciti a collegarlo a Python, il quale manda un messaggio nella porta seriale che verrà letto da arduino il quale avvierà il circuito.

Il progetto a livello fisico è composto da tre motori:

        -il motore passo passo, ovvero un motore controllabile in qualsiasi suo movimento, tramite la quantità di passi che esso deve fare 
        
        -il servo motore, con montata la testina in parallelo al pezzo da incidere
        
        -il motore rc, motore principale che fa girare il pezzo
        
Infine abbiamo aggiunto un semplice diodo led di colore rosso, che si accenda quando il macchinario sta funzionando, principalmente come misura di sicurezza nei confronti
di un eventuale operaio che lo debba aprire per estrarre il pezzo.

## IL PROGETTO SI E' DIVISO IN: 

### IDEA

    Pensare alla fattibilità del progetto
    
    Possibili sbocchi commerciali
    
    Funzionalità necessarie
    
### SVILUPPO

    Scelta dei corretti componenti
    
    Scelta linguaggio e bot
    
    Montaggio arduino
    
    Sviluppo codice
    
        Arduino
        
        Bot telegram
        
### CONCLUSIONI

    Test di funzionamento
    
    
### CODICE PYTHON:

    Fase di listening
            il bot si mette in attesa di ricevere un messaggio, e di conseguenza di far partire l'Arduino

    Fase di start
            il bot riceve il messaggio "/begin", e manda un messaggio ad Arduino che fa partire il codice

    Fase di stop
            il bot riceve il messaggio "/stop", e manda un messaggio ad Arduino che fa interrompe il codice. 
            il messaggio serve in caso di un stop d'emergenza

### PARTE FISICA CON ARDUINO:
        
    Motore Passo-Passo:
        Funziona tramite degli step, che gli consentono di andare avanti, indietro, e a velocità diverse.
        E' molto versatile e noi lo usiamo per muovere la il servo motore avanti e indietro   

    Servo motore:
        Funziona tramite una rotazione di x gradi, 0 <= x <= 180.
        E noi lo abbiamo sfruttato per muovere la testina avanti e indietro

    Motore RC:
        Funziona solo se alimentato, quindi senza programmazione , in base alla polarizzazione, e a velocità fissa.
        Lo abbiamo sfruttato come motore principale, ovvero che muove il pezzo da incidere
