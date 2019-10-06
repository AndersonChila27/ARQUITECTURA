const int Trig = PA10;   
const int Echo = PA8;   
const int led = PB11;  
const int zumbador = PA7;
  long tiempo; 
  long distancia; 
   int contador=0;
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
  
  chila();
}

void chila(){
 
    if (distancia > 0 && distancia < 50)
    {
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
    Serial.print("Tienes un obstaculo al frente!!!");
    delay(1000);
    }
    else {
    Serial.println();
    Serial.print("wait..........");
    }
}

  
