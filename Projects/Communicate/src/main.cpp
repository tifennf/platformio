#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#define SDA_PIN 5  // là où passent les données
#define SCL_PIN 6  // clock pour gérér la synchro ?
#define MAX_X 72
#define MAX_Y 40

// constructor pour l'écran
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(
    U8G2_R0,
    /* reset=*/U8X8_PIN_NONE);  // EastRising 0.42" OLED

// parse and clean msg into buffer
int parse_msg(String msg, char** res) {
    msg.trim();
    msg.toCharArray(*res, 256, 0);

    return 0;
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN);  // permet la communication avec l'écran
    u8g2.begin();                  // on initialise la bibliothèque graphique
    u8g2.setFont(u8g2_font_ncenB08_tr);
}
void loop() {
    // put your main code here, to run repeatedly:

    u8g2.clearBuffer();  // on nettoie le buffer avant de l'utiliser

    if (Serial.available() > 0) {
        char msg[256];
        char* ptrMsg = msg;  // cpp things

        parse_msg(Serial.readStringUntil('\n'), &ptrMsg);

        Serial.print("Message envoyé : ");
        Serial.println(msg);

        u8g2.drawStr(10, 30, msg);  // on écrit le message dans le buffer
    }

    u8g2.drawStr(10, 40, "\\ (o u o ) /");
    u8g2.sendBuffer();  // on écrit le buffer via Wire pour l'afficher sur
                        // l'écran

    delay(1000);  // on attend 1 seconde à la fin de chaque tour
}