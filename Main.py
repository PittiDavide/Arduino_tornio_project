#creaazione del bot telegram in python
import time
import telepot
import serial
from telepot.loop import MessageLoop
from pprint import pprint
#abbiamo inserito queste librerie: time, per sfruttare delle pause, serial che ci consente di comunicare sulla seriale, telepot per collegare python a telegram

arduino = serial.Serial('porta seriale', 9600)
#sfruttiamo la il metodo Serial(), della classe serial, per indicare a python su che porta comunicare e con quanti baud

time.sleep(1)
#sfruttiamo la classe time, con il metodo sleep(), per inserire un piccolo delay

def handle(msg):

    content_type, chat_type, chat_id = telepot.glance(msg)
    print(content_type, chat_type, chat_id)
    pprint(msg)
    #riceviamo il messaggio da telegram
  
    username = msg['from']['first_name']
    user_id = msg['from']['id']
    #indichiamo al bot di leggere  user name ed id della persona collegata al bot
    
    if msg['text'] == '/start':
        bot.sendMessage(chat_id, 'ciao %s, i comandi che puoi usare sono: /begin   /stop' %username)
      #leggiamo il messaggio, in questo caso start, e generiamo un messaggio che stampi nome utente e i comandi utilizzabili
    if msg['text'] == '/begin':
        arduino.write('H'.encode())
      #in questo caso il messaggio è /begin e comunica ad arduino il carattere "H", che farà capire ad arduino di di far partire l'algoritmo
    if msg['text'] == '/stop':
        arduino.write('L'.encode())
      #in questo caso il messaggio è /stop e comunica ad arduino il messaggio "L", che bloccherà il tornio per un caso d'emergenza

TOKEN = 'token generato dal bot'
#inseriamo il token generato dal bot, necessario per comunicare con esso

bot = telepot.Bot(TOKEN)
#passiamo il token alla classe telepot, tramite il metodo Bot()

MessageLoop(bot, handle).run_as_thread()
print('Listening ...')
#stampiamo il un messaggio a console per far capire che il bot è in ascolto
while 1:
    time.sleep(10)
    #blocchiamo il programma finche non riceviamo un nuovo messaggio stramite il bot
