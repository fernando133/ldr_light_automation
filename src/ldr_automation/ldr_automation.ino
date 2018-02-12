int led_indicator = 13;
int relay = 6;
int ldr_pin = 0;   
int ldr_value = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(led_indicator, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(ldr_pin, INPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(led_indicator, LOW);
}

void loop() {
  ldr_value = analogRead(ldr_pin);
  delay(2000);
  Serial.print("Valor lido do LDR : ");
  Serial.print(ldr_value);  
  Serial.print("\n");
  
  if (ldr_value > 900) {
    digitalWrite(led_indicator, HIGH);
    digitalWrite(relay, LOW);
    delay(14400000);
    while(ldr_value > 900) {
      digitalWrite(relay, HIGH);
      digitalWrite(led_indicator, LOW);
      ldr_value = analogRead(ldr_pin);
    }
  }
}
