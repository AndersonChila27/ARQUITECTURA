const int Trig = PA10;   
const int Echo = PA8;   
const int led = PB11; 
const int zumbador = PA7;
  long tiempo; 
  long distancia;
   int contador = 0;
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
 
  if(distancia > 0 && distancia < 300)
  {
    contador = contador + 1;
    digitalWrite(led, HIGH);
    delay(750);
    digitalWrite(zumbador, HIGH);
    tone(zumbador, tono);
    delay(750);
    noTone(zumbador);
    digitalWrite(led, LOW);
    delay(350);
    digitalWrite(zumbador, LOW);
    delay(350);
    Serial.println();
    Serial.print("Intrusoooo !!!!");
  }
  else{
    Serial.println();
    Serial.print("Escaneando............... ");

  }
  Serial.println();
  
}
