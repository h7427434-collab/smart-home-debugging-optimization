// Smart Home Environment Monitoring
// Week 3 - Corrected and Optimized Version

#define TEMP_SENSOR_PIN A0
#define HUMIDITY_SENSOR_PIN A1
#define LED_PIN 13
#define BUZZER_PIN 8

const float TEMP_THRESHOLD = 30.0;
const float HUMIDITY_THRESHOLD = 70.0;

unsigned long previousMillis = 0;
const unsigned long SENSOR_INTERVAL = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking timing improves responsiveness.
  if (currentMillis - previousMillis >= SENSOR_INTERVAL) {
    previousMillis = currentMillis;

    int tempRaw = analogRead(TEMP_SENSOR_PIN);
    int humidityRaw = analogRead(HUMIDITY_SENSOR_PIN);

    // Floating-point conversion avoids integer-division errors.
    float voltage = (tempRaw * 5.0) / 1023.0;
    float temperature = voltage * 100.0;

    float humidity = (humidityRaw * 100.0) / 1023.0;

    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity, 2);
    Serial.println(" %");

    // Alert only when either environmental value exceeds
    // its defined safety threshold.
    bool alert = (temperature > TEMP_THRESHOLD) ||
                 (humidity > HUMIDITY_THRESHOLD);

    digitalWrite(LED_PIN, alert ? HIGH : LOW);
    digitalWrite(BUZZER_PIN, alert ? HIGH : LOW);
  }
}
