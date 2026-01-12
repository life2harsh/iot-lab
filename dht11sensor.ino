// without dht11 library
#define DHT_PIN 2
void setup() {
  Serial.begin(9600);
}

void loop() {
  byte data[5] = {0,0,0,0,0}; 
  pinMode(DHT_PIN, OUTPUT);
  digitalWrite(DHT_PIN, LOW);
  delay(18);
  digitalWrite(DHT_PIN, HIGH);
  delayMicroseconds(40);
  pinMode(DHT_PIN, INPUT);
  while(digitalRead(DHT_PIN) == HIGH);
  while(digitalRead(DHT_PIN) == LOW);
  while(digitalRead(DHT_PIN) == HIGH);
  for (int i = 0; i < 40; i++) {
    while(digitalRead(DHT_PIN) == LOW);
    unsigned long start = micros();
    while(digitalRead(DHT_PIN) == HIGH);
    if ((micros() - start) > 40) {
      data[i/8] |= (1 << (7 - (i % 8)));
    }
  }
  Serial.print("Humidity: "); Serial.print(data[0]); Serial.print("% ");
  Serial.print("Temp: "); Serial.print(data[2]); Serial.println("C"); 
  delay(2000);
}
