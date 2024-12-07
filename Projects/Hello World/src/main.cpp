#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#define SDA_PIN 5  // là où passent les données
#define SCL_PIN 6  // clock pour gérér la synchro ?

// constructor pour l'écran
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(
    U8G2_R0,
    /* reset=*/U8X8_PIN_NONE);  // EastRising 0.42" OLED

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN);  // permet la communication avec l'écran
    u8g2.begin();                  // on initialise la bibliothèque graphique
    u8g2.setFont(u8g2_font_ncenB08_tr);
}

void loop() {
    // put your main code here, to run repeatedly:

    Serial.println("test\n");
    // affichage de plusieurs strings sur l'écran
    u8g2.clearBuffer();  // on nettoie le buffer avant de l'utiliser
    u8g2.drawStr(0, 10, "Hello world");     // on y écrit Hello world
    u8g2.drawStr(10, 30, "\\ (o u o ) /");  // on écrit autre chose
    u8g2.sendBuffer();                      // on envoi le buffer via Wire

    delay(1000);  // on attend 1 seconde à la fin de chaque tour
}