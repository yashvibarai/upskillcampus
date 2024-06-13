#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "iron-dome-4705d-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "4Am2EPGZ1nes63co9uUXVzHZE3yStBcUffzfRoGO"
#define WIFI_SSID "G"
#define WIFI_PASSWORD "miloni07"

int switchReed=D1;

void setup() {
 
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(switchReed, INPUT_PULLUP);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop(){
  
  if (digitalRead(switchReed)==HIGH){
    digitalWrite(LED_BUILTIN, LOW);
    Firebase.setString("message","Your Door is open");
    Serial.println("Your Door is open");
  }
  else {
    Firebase.setString("message", "Your Door is close");
    Serial.println("Your Door is close");
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
