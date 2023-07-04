/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/vinso/Documents/CTDIoT2023/Lab11/src/Lab11.ino"
#include "LIS3DH.h"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 4 "c:/Users/vinso/Documents/CTDIoT2023/Lab11/src/Lab11.ino"
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

#define CSPIN D3

OledWingAdafruit display;
LIS3DHSPI accel(SPI, CSPIN, WKP);

void setup() {
    Serial.begin(9600);
    while (!Serial.isConnected()) {}

    display.setup();
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.display();

    LIS3DHConfig config;
	config.setAccelMode(LIS3DH::RATE_100_HZ);
	bool setupSuccess = accel.setup(config);
    Serial.printlnf("setupSuccess=%d", setupSuccess);
}

void loop() {
    display.loop();
    LIS3DHSample sample;
    if (accel.getSample(sample)) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.print("X: ");
        display.println(sample.x);
        display.print("Y: ");
        display.println(sample.y);
        display.print("Z: ");
        display.println(sample.z);
        display.display();
	}
}
