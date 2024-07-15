#define TEMP_PIN A1         // Temperature sensor connected to analog pin A1
#define SOIL_PIN A0         // Soil moisture sensor connected to analog pin A0
#define TEMP_LED_PIN 3      // LED for temperature indication connected to digital pin 3
#define MOIST_LED_PIN 5     // LED for soil moisture indication connected to digital pin 5
#define PUMP_PIN 6          // Pin to control the NPN transistor for the water pump (DC motor)

void setup() {
  Serial.begin(9600);      // Initialize serial communication
  
  pinMode(TEMP_LED_PIN, OUTPUT);
  pinMode(MOIST_LED_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  // Reading temperature from TMP36
  int tempValue = analogRead(TEMP_PIN);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;  // Convert voltage to Celsius

  // Reading soil moisture
  int soilMoisture = analogRead(SOIL_PIN);

  // Print values to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" *C\t");
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);

  // LED Indicators
  if (temperatureC > 25) {  // Example temperature threshold (adjust as needed)
    digitalWrite(TEMP_LED_PIN, HIGH);  // Turn on temperature LED
  } else {
    digitalWrite(TEMP_LED_PIN, LOW);   // Turn off temperature LED
  }

  if (soilMoisture < 300) {  // Example soil moisture threshold (adjust as needed)
    digitalWrite(MOIST_LED_PIN, LOW); // Turn on moisture LED
    digitalWrite(PUMP_PIN, HIGH);     // Turn on water pump
  } else {
    digitalWrite(MOIST_LED_PIN, HIGH); // Turn off moisture LED
    digitalWrite(PUMP_PIN, LOW);        // Turn off water pump
  }

  // Display soil moisture level in the Serial Monitor
  if (soilMoisture < 300) {  // Example soil moisture threshold (adjust as needed)
    Serial.println("Soil moisture level: Dry"); // Print dry soil moisture level
  } else {
    Serial.println("Soil moisture level: Moist"); // Print moist soil moisture level
  }

  delay(2000);  // Delay between sensor readings
}