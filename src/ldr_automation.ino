int led_indicador = 13;
int rele = 6;
int ldr_pin = 0;   
int ldr_value = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(led_indicador, OUTPUT);
  pinMode(rele, OUTPUT);
  pinMode(ldr_pin, INPUT);
  digitalWrite(rele, HIGH);
  digitalWrite(led_indicador, LOW);
}

void loop() {
  ldr_value = analogRead(ldr_pin);
  delay(2000);
  Serial.print("Valor lido do LDR : ");
  Serial.print(ldr_value);  
  Serial.print("\n");
  
  if (ldr_value > 900) {
    digitalWrite(led_indicador, HIGH);
    digitalWrite(rele, LOW);
    delay(1440000);
    while(ldr_value > 900) {
      digitalWrite(rele, HIGH);
      digitalWrite(led_indicador, LOW);
      ldr_value = analogRead(ldr_pin);
    }
  }
}
