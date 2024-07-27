#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

// Define the pulse sensor settings
const int pulsePin = 35; // the pulse sensor pin
const int ledPin = 2; // the LED pin
const int LED13 = 25;
int LED14 = 27;
int pulseValue; // the pulse sensor value
int bpm; // the heart rate in beats per minute
int maxHeartRate = 220; // Maximum heart rate for athletes (adjust as needed)

// Heart rate ranges for different workout types
const int maximum_workout = 195;
const int anerobic_training = 156;
const int cardio_training = 137;
const int fat_burn = 117;
const int warm_up = 98;

// Your WiFi credentials and ThingSpeak channel details
const char* ssid = "Galaxy M3155F8"; // Replace with your WiFi SSID
const char* password = "211088281072"; // Replace with your WiFi password
unsigned long channelID =  2515272; // Replace with your ThingSpeak Channel ID
const char* writeAPIKey = "75E13ER4V5R19WSA"; // Replace with your ThingSpeak Write API Key

WiFiClient client;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Set up the pulse sensor
  pinMode(pulsePin, INPUT);
  pinMode(LED13, OUTPUT);
  digitalWrite(LED13, LOW);
}

void loop() {
  // Read the pulse sensor value
  pulseValue = analogRead(pulsePin);

  // Detect the pulse
  if (pulseValue > 600) {
    digitalWrite(LED13, HIGH); // turn on the LED
    delay(100); // wait for a short time
    digitalWrite(LED13, LOW); // turn off the LED

    bpm = map(pulseValue, 0, 1024, 60, maxHeartRate); // calculate the heart rate in beats per minute

    Serial.print("Heart rate: ");
    Serial.print(bpm/3);
    Serial.println(" BPM");
    bpm = bpm/3;

    delay(5000);

    // Check if heart rate is within the recommended range for the workout type
    String workoutType;
    if (bpm >= maximum_workout ) {
      workoutType = "Maximum Workout";
      Serial.println("Maximum Workout");
    } else if (bpm >= anerobic_training) {
      workoutType = "Anerobic Training";
      Serial.println("Anerobic Training");
     
      
      
    } else if (bpm >= fat_burn ) {
      workoutType = "Fat Burn";
      Serial.println("Fat Burn");
    } else if (bpm >= warm_up ) {
      workoutType = "Warm Up";
      Serial.println("Warmup");
      digitalWrite(LED13,HIGH);
     
    } else {
      workoutType = "Outside recommended range";
      Serial.println("Outside recommended range");
    }

    // Send the heart rate and workout type to ThingSpeak
    ThingSpeak.setField(1, bpm);
    ThingSpeak.setField(2, workoutType);
    ThingSpeak.writeFields(channelID, writeAPIKey);
  }
}
