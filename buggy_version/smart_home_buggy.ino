// Smart Home Environment Monitoring
// Week 3 - Buggy Version
// Purpose: Demonstrate common embedded-system bugs for debugging practice.

#define TEMP_SENSOR_PIN A0
#define HUMIDITY_SENSOR_PIN A1
#define LED_PIN 13
#define BUZZER_PIN 8

float temperature = 0;
float humidity = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, INPUT);      // BUG 1
  pinMode(BUZZER_PIN, INPUT);   // BUG 2
}

void loop() {

  int tempRaw = analogRead(TEMP_SENSOR_PIN);
  int humidityRaw = analogRead(HUMIDITY_SENSOR_PIN);

  // BUG 3: Integer division causes inaccurate conversion.
  temperature = tempRaw * 5 / 1023 * 100;

  // BUG 4: Incorrect conversion and unrealistic range.
  humidity = humidityRaw / 1023 * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // BUG 5: Alert condition is too broad.
  if (temperature > 25 || humidity > 40) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // BUG 6: Long blocking delay reduces system responsiveness.
  delay(5000);
}
