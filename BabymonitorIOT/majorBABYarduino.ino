

#define buzzer 7
#define led    6
#define fan    5
#define music  4



#define moist  8
#define pir   9
#define temperature  A2
#define sound  A1


int mval=1;
int pval=0;
int sval=0;
int tval=0;


int temp=0, i=0;
int flag=1;

char str[15];
void keycheck();
void compare();

void setup()
 {
   
   Serial.begin(9600);
      
   pinMode(sound,INPUT);  
   pinMode(pir,INPUT);
   pinMode(moist,INPUT);
   pinMode(temperature,INPUT);  
  
          
   pinMode(buzzer, OUTPUT);
    pinMode(fan, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(music, OUTPUT);
   
    digitalWrite(buzzer,HIGH); 
    digitalWrite(fan,HIGH); 
    digitalWrite(led,HIGH); 
     digitalWrite(music,HIGH); 
     
      digitalWrite(moist,HIGH);
      digitalWrite(pir,LOW); 
     

    delay(2000);
   
Serial.println("AT+CMGF=1");
delay(1000);
}

void gsmSend(const char *ptr)
{ 
 int i;
  Serial.print("AT+CMGS=");
  delay(1000);
  Serial.print('"');
  delay(1000);
  Serial.print("+919958852065");
    delay(3000); 
}

void loop()
{ 
keycheck();
}




void keycheck()
{
     int pval=digitalRead(pir);
     int mval=digitalRead(moist);      
     int tval=analogRead(temperature);
     int sval=analogRead(sound); 
     Serial.print("sound:");
     Serial.println(sval);
     Serial.print("temp:");
     Serial.println(tval);  
     delay(500);  
     
   if(tval > 210 )
   {     
   Serial.println("Baby is Feverish");
   delay(1000);
   Serial.print('\n'); 
   delay(500);
   gsmSend("Attention Please,The baby is feeling Feverish,please take an appropriate action");   
   delay(2000);  
   }
  else if(mval==LOW)
   {
    digitalWrite(led,LOW);
    delay(1000);
   
   Serial.println("Over Moisture....");
   delay(500);
   Serial.print('\n'); 
   delay(500);
   gsmSend("Attention Please,the baby's diaper is wet now,please take an appropriate action");   
   delay(2000); 
   }
   else if(sval>560)
   {
   digitalWrite(led,LOW);
   digitalWrite(buzzer,LOW);
   delay(1000);
   digitalWrite(led,LOW);
   digitalWrite(buzzer,LOW);
   delay(1000);
   Serial.println("Baby is crying....");
   delay(500);
   Serial.print('\n'); 
   delay(500);
   gsmSend("Attention Please,The baby is crying $ now lullaby is playing ,please take an appropriate action");   
   delay(2000);
   digitalWrite(buzzer,HIGH); 
   digitalWrite(led,HIGH); 
   }
   else if(pval==HIGH)
   {
   digitalWrite(fan,LOW);
   Serial.println("Baby is moving....");
   delay(500);
   Serial.print('\n'); 
   delay(500);
   gsmSend("Attention Please,The baby is moving ,please take an appropriate action");   
   delay(2000); 
   digitalWrite(fan,HIGH);
   }
   else
   {
     digitalWrite(buzzer,HIGH); 
     digitalWrite(led,HIGH); 
     digitalWrite(fan,HIGH); 
   }
}
