
const int Trig = PA10;   
const int Echo = PA8;   
const int led = PB11;  

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT); 
  pinMode(Echo, INPUT);  
  digitalWrite(Trig, LOW);
  pinMode(led, OUTPUT);  
}
void loop()
{

  long tiempo; 
  long distancia; 

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);          
  digitalWrite(Trig, LOW);
  
  tiempo = pulseIn(Echo, HIGH); 
  distancia = tiempo / 59;            
  
  Serial.print("Distancia: ");
  Serial.print(distancia);     
  Serial.print("cm");
  Serial.println();
  delay(100);          

  if(distancia > 40){
    
     digitalWrite(led, LOW);
     Serial.print("Retroceda ");  
     
  }else if(distancia >= 20 && distancia <= 40){
     digitalWrite(led, LOW);
     delay(300);
     digitalWrite(led, HIGH);
     delay(500);
     Serial.print("Precaucion.... ");    
}else if(distancia < 20){
     digitalWrite(led, HIGH);
     Serial.print("Pare!!! ");  
  
}
}
