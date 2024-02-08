#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define ssid "UdithaL Y5p"
#define password "1994uditha"
#define FIREBASE_HOST ""  //Firebase Project URL Remove "https:" , "\" and "/"
#define FIREBASE_AUTH ""                           //Firebase Auth Token

FirebaseData firebaseData;

int Device_1 = D0;
int Device_2 = D1;
int Device_3 = D2;
int Device_4 = D4;

void setup() {

  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(Device_1, OUTPUT);
  pinMode(Device_2, OUTPUT);
  pinMode(Device_3, OUTPUT);
  pinMode(Device_4, OUTPUT);
}

void loop() {

  if (Firebase.get(firebaseData, "/D1")) {
    if (firebaseData.dataType() == "string") {
      String De1 = firebaseData.stringData();
      if (De1 == "1") {
        digitalWrite(Device_1, HIGH);
      } else if (De1 == "0") {
        digitalWrite(Device_1, LOW);
      }
    }
  }
  if (Firebase.get(firebaseData, "/D2")) {
    if (firebaseData.dataType() == "string") {
      String De2 = firebaseData.stringData();
      if (De2 == "1") {
        digitalWrite(Device_2, HIGH);
      } else if (De2 == "0") {
        digitalWrite(Device_2, LOW);
      }
    }
  }
  if (Firebase.get(firebaseData, "/D3")) {
    if (firebaseData.dataType() == "string") {
      String De3 = firebaseData.stringData();
      if (De3 == "1") {
        digitalWrite(Device_3, HIGH);
      } else if (De3 == "0") {
        digitalWrite(Device_3, LOW);
      }
    }
  }

  if (Firebase.get(firebaseData, "/D4")) {
    if (firebaseData.dataType() == "string") {
      String De4 = firebaseData.stringData();
      if (De4 == "1") {
        digitalWrite(Device_4, HIGH);
      } else if (De4 == "0") {
        digitalWrite(Device_4, LOW);
      }
    }
  }
}
