#include <Servo.h>
//abbiamo utilizzato la libreria Servo.h, per semplificare l'utilizzo del servomotore

Servo motServo;
//abbiamo dichiarato un oggetto della class Servo

int movServo[] = {100, 80, 90, 100, 40, 60, 80, 50, 180, 20};
int delServo[] = {500, 300, 700, 400, 500, 230, 430, 340, 320, 430};
//dichiariamo i vettori contenenti movimento e tempo in cui il servo motore deve mentenere la posizione

int j = 0; 
//dichiariamo l'indice che utilizzeremo poi per scorrere il vettore contenente i movimenti, ed i delay del servo motore

int motorPin1 = 8;          
int motorPin2 = 9;      
int motorPin3 = 10;     
int motorPin4 = 11;   
//abbiamo dichiarato i piedini a cui è collegato il motore passo passo

int motor_Speed = 2;
int motor_Step;
int movStepper[] = {100, -200, 150, 130, 210, 400, 100, 120, 140, 900};
//dichiariamo i parametri necessari per l'utilizzo del motore passo passo ed il vettore contenente i suoi movimenti

void setup() {

  motServo.attach(3);
  //sfruttiamo la funzione attach, della classe Servo per indicare a che piedino è collegato il motore
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  //indichiamo i piedini di collegamento del motore passo passo

  pinMode(2, OUTPUT);
  //indico il piedino a cui è collegato il motore principale, in questo caso il 2
  
  Serial.begin(9600);
  //accendiamo la seriale con un valore di passaggio dati di 9600
}



void loop() {
  if (Serial.available()) {
  //controllo l'arrivo di un messaggio sulla porta seriale
  
    char c = Serial.read();
    //leggo il messaggio in arrivo sulla seriale, che per essere comandato riceverà un carattere, 'H' per partire, 'L' per stopparsi
    
    if(c == 'H'){
      //controllo che il carattere sia 'H' e do il via ai motori
      
      while(c == 'H'){
      //finche il messaggio è 'H' il codice verrà eseguito
      
      
        if (Serial.read() == 'L'){
        //controllo se il carattere, in caso sia 'L' lo fermo
        
          digitalWrite(2, LOW);
          //spengo il motore principale
          
          exit(0);
          //fermo l'esecuzione del codice
        }
        
        //se arrivo qui il codice non è stato arrestato
        
        digitalWrite(2, HIGH);
        //accendo il motore principale
        
        if (movStepper[j] >= 0){
        //controllo che l'elemento j dell'array contenga un valore positivo
        //avendo valore positivo, girerà avanti
        
          for (int i = 0; i < movStepper[j]; i++ ){
          //questo for fa si che si muova il motore passo passo, muovendo un passo alla volta, e si ripete il numero di volte indicato nella posizione j dell'array
          
            digitalWrite(motorPin1, HIGH);
            digitalWrite(motorPin2, LOW);
            digitalWrite(motorPin3, LOW);
            digitalWrite(motorPin4, LOW);
            delay(motor_Speed);
            digitalWrite(motorPin1, LOW);
            digitalWrite(motorPin2, HIGH);
            digitalWrite(motorPin3, LOW);
            digitalWrite(motorPin4, LOW);
            delay(motor_Speed);
            digitalWrite(motorPin1, LOW);
            digitalWrite(motorPin2, LOW);
            digitalWrite(motorPin3, HIGH);
            digitalWrite(motorPin4, LOW);
            delay(motor_Speed);
            digitalWrite(motorPin1, LOW);
            digitalWrite(motorPin2, LOW);
            digitalWrite(motorPin3, LOW);
            digitalWrite(motorPin4, HIGH);
            delay(motor_Speed); 
      
          }
        }
      else{
      //se il valore è negativo il motore girerà indietro
        for (int i = 0; i > movStepper[j]; i-- ){
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          delay(motor_Speed);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          delay(motor_Speed);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          delay(motor_Speed);
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          delay(motor_Speed); 
        }
      }
      j++; 
      //incremento il valore dell'indicatore alla posizione dell'array
      delay(500);
  
      motServo.write(movServo[j]);
      //assegno al servo motore la posizione che deve raggiungere
      
      delay(delServo[j]);
      //faccio fermare il codice per il tempo scelto, ed indicato nell'array
      
      if (j == ((sizeof(movStepper)/2)-1)){
      //controllo se sono arrivato alla fine delle posizione richieste al motore
        
        digitalWrite(2, LOW);
        //spengo il motore principale
        
        exit(0);
        //fermo l'esecuzione
      } 
     }
      digitalWrite(2, LOW);
      //fermo il motore, in caso sia qui il codice si è fermato in maniera d'emmerganza
   }
 }    
}
