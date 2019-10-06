const int Trig = PA10;  
const int Echo = PA8;  
const int led = PB11;  
const int zumbador = PA7; 
  long tiempo; 
  long distancia; 
   int contador = 0;
   int acumulador = 0;
   int tono = 540;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT); 
  pinMode(Echo, INPUT);  
  digitalWrite(Trig, LOW);
  pinMode(led, OUTPUT);  
  pinMode(zumbador, OUTPUT);
}
void loop()
{
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(10);          
  digitalWrite(Trig, LOW);     
  
  tiempo = pulseIn(Echo, HIGH); 
  distancia = tiempo / 59;            
  
  an(); 
}

void an(){
 
  if(distancia > 0 && distacia < 30)
  {
    Serial.print("Persona dentro de la habitación");
    digitalWrite(led, HIGH);
    digitalWrite(zumbador, HIGH);
    tone(zumabador, tono);
    delay(500);
    noTone(zumbador);
    digitalWrite(zumbador, LOW);
    delay(3000);
    Serial.println();
    
  }
  else{
    Serial.print("Habitación vacía");
    digitalWrite(led, LOW);
    Serial.println();
  }
  
  }
