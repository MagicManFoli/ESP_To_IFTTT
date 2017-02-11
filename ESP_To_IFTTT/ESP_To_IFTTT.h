
#ifndef ESP__To_IFTTT_h
#define ESP__To_IFTTT_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

//IFTTT
#define IFTTT_URL "maker.ifttt.com"
const uint16_t httpsPort = 443;

class ESP_To_IFTTT{
  public:
    ESP_To_IFTTT(const String auth_key, const String event)
      : auth_key(auth_key), event(event){} // constructor
    bool connect();   //returns if connection was Successful
    bool post(const String, const String, const String);  //NOTE: return broken
  private:
    WiFiClientSecure client;
    String auth_key;
    String event;
};

#endif
