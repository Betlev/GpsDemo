#include <SoftwareSerial.h> 
#include <TinyGPS++.h>
#define RXPin 2
#define TXPin 3
#define GPSBaud 4800
#define ConsoleBaud 115200

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

// The TinyGPS++ object
TinyGPSPlus gps;
unsigned long lastUpdateTime = 0;

#define WITRAC_LAT 39.462256
#define WITRAC_LNG -0.327821

double distanceToDestination = 0;

void setup() {
   Serial.begin(ConsoleBaud);
   ss.begin(GPSBaud);
}

void loop() {
  
    // If any characters have arrived from the GPS,
    // send them to the TinyGPS++ object
    while (ss.available() > 0) {
      gps.encode(ss.read());
    }
    // Every 5 seconds, do an update.
    if (millis() - lastUpdateTime >= 5000) {
      lastUpdateTime = millis();

      // Establish our current status
      double distanceToDestination = TinyGPSPlus::distanceBetween(
        gps.location.lat(), gps.location.lng(),WITRAC_LAT, WITRAC_LNG
      );
      
    }

    // Within 100 meters of destination?  We're here!
    if (distanceToDestination <= 100.0) {
      Serial.println("You're near WiTraC HQ!");
    }

}
