#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Wire.h>
#include "BMP.h"

#define xlen 80
#define ylen 60

const char* STASSID = "My ASUS_1619";
const char* STAPSK = "3fcb600ecb07";
const char* APSSID = "ESP01";
const char* APPSK = "12345678";
IPAddress ip(192,168,43,21); 
IPAddress gateway(192,168,43,1); 
IPAddress subnet(255,255,255,0); 

AsyncWebServer server(80);
bool push = 0;
unsigned char bmp[xlen*ylen*2+66];
unsigned char out[5] = "    ";
const char success[] = "Success!";

TwoWire I2C_0 = TwoWire();
void setup(void) {
  Serial.begin(115200);
  I2C_0.begin(4, 5, 100000);
  BMP::construct16BitHeader(bmp, xlen, ylen);
//  BMP::construct16BitHeader(bmp[1], xlen, ylen);
 // BMP::construct16BitHeader(last, xlen, ylen);

  WiFi.config(ip, gateway, subnet);
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP(APSSID, APPSK, 1);
  WiFi.begin(STASSID, STAPSK);

  server.on("/", HTTP_GET, [] (AsyncWebServerRequest *request) {
    request->send(200,"text/plain-text", "esp8266 is here!");
  });

  server.on("/bmp", HTTP_GET, [] (AsyncWebServerRequest *request) {
    request->send_P(200, "image/bmp", bmp, xlen*ylen*2+66);
  });
  
  server.on("/servo", HTTP_GET, [] (AsyncWebServerRequest *request) {
    if (request->hasParam("s1")) {
      out[1] = '1';
      out[2] = request->getParam("s1")->value()[0];
    }else if (request->hasParam("s2")) {
      out[1] = '2';
      out[2] = request->getParam("s2")->value()[0];
    }else {
      out[1] = ' ';
      out[2] = ' ';
    }
    push = 1;
    request->send(200, "text/plain-text", "Success");
  });

  server.begin();
}

int i;
char d1, d2;
bool rec, wr, wait;
void loop(void) {
  while (Serial.available()) {
      d2 = Serial.read();
      if (wr) {
        if (wait) {
          if (d2 == 0x01) {
            wr = 0;
          }else {
            bmp[66+i] = d1;
            bmp[67+i] = d2;
            i += 2;
          }
          wait = 0;
        }else if (d2 == 0xfe) {
          wait = 1;
        }else if (i>xlen*ylen*2) {
          wr = 0;
        }else {
          bmp[66+i] = d2;
          i++;
        }
      }
      if (d2 == 0xfe && d1 == 0x01) {
        wr = 1;
        i = 0;
      }
      d1 = d2;
  }
  if (push) {
    I2C_0.beginTransmission(0x28);
    I2C_0.write(out, 4);
    int err = I2C_0.endTransmission(1);
    Serial.printf("%sstatus: %d\n", out, err);
    push = 0;
  }
}
