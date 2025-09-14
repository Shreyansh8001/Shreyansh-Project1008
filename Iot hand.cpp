#include <WiFi.h>  // Use WiFi library for ESP32
#include <BlynkSimpleEsp32.h>  // Blynk library for ESP32
#include <DFRobotDFPlayerMini.h>

// Blynk credentials (get from Blynk app)
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";  // Replace with your Blynk auth token
char ssid[] = "YOUR_WIFI_SSID";         // Replace with your WiFi SSID
char pass[] = "YOUR_WIFI_PASSWORD";     // Replace with your WiFi password

// SoftwareSerial for DFPlayer Mini (RX, TX pins on ESP32)
#include <HardwareSerial.h>
HardwareSerial mySerial(2);  // Use Serial2 on ESP32 (default pins: RX=16, TX=17)
DFRobotDFPlayerMini myDFPlayer;

// Flex sensor pin (use GPIO pin, analog capable)
const int flexPin = 34;  // GPIO34 (ADC1_CH6) for flex sensor

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, 16, 17);  // Serial2: RX=16, TX=17
  if (!myDFPlayer.begin(mySerial)) {
    Serial.println("DFPlayer init failed!");
    while (true);  // Halt if DFPlayer fails
  }
  myDFPlayer.volume(20);  // Volume 0-30
  Serial.println("DFPlayer initialized successfully");

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);
  Serial.println("Assistive Hand Glove Started - Real-time Monitoring");

  // Configure flex sensor pin
  pinMode(flexPin, INPUT);
}

void loop() {
  Blynk.run();  // Handle Blynk communication
  int flexValue = analogRead(flexPin);  // Read flex sensor (0-4095 on ESP32)
  Serial.print("Flex Value: "); Serial.println(flexValue);

  String gesture = detectGesture(flexValue);
  playAudio(gesture);  // Audio feedback

  if (gesture == "Help Needed!" || gesture == "Call Doctor") {
    sendBlynkAlert(gesture);  // Send notification via Blynk
  }

  delay(1000);  // 1s interval for real-time processing
}

String detectGesture(int value) {
  // Adjusted thresholds for ESP32's 12-bit ADC (0-4095)
  if (value > 3200) return "Help Needed!";      // Strong bend = Urgent
  else if (value > 2000) return "Call Doctor";  // Medium bend = Alert
  else if (value > 800) return "Comfort OK";    // Light bend = Status
  else return "No Gesture";                     // Straight = Idle
  // Note: analogRead on ESP32 clamps values to 0-4095
}

void playAudio(String msg) {
  if (msg == "Help Needed!") {
    myDFPlayer.play(1);  // Track 1: help.mp3
    Serial.println("Audio: Help Needed!");
  } else if (msg == "Call Doctor") {
    myDFPlayer.play(2);  // Track 2: doctor.mp3
    Serial.println("Audio: Call Doctor");
  } else if (msg == "Comfort OK") {
    myDFPlayer.play(3);  // Track 3: ok.mp3
    Serial.println("Audio: Comfort OK");
  } else {
    Serial.println("Audio: No Gesture");
  }
}

void sendBlynkAlert(String msg) {
  Blynk.notify(msg);  // Send push notification to Blynk app
  Serial.println("Blynk Alert Sent: " + msg + " (via WiFi)");
}