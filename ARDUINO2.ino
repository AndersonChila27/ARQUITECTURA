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
  pinMode(Trig; OUTPUT); 
  pinMode(Echo, INPUT);  
  digitalWrite(Trigger, LOW);
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
 
  if(distancia > 0 && distancia < 50)
  {
    contador = contador + 1;
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(zumbador, HIGH);
    tone(zumbador, tono);
    delay(500);
    noTone(zumbador);
    digitalWrite(led, LOW);
    digitalWrite(zumbador, LOW);
    Serial.println();
    Serial.print("Registrado ");
    
  }
  else{
    Serial.println();
    Serial.print("Espere un momento....... ");

  }
  Serial.println();
  Serial.print(cont);
  
  
}
