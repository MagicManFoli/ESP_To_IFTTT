
#include "ESP_To_IFTTT.h"

bool ESP_To_IFTTT::connect()
{
  return (client.connect(IFTTT_URL, httpsPort));
}

bool ESP_To_IFTTT::post(const String new_value1, const String new_value2, const String new_value3)
{

  String postData = "{\"value1\":\"" + new_value1 + "\",\"value2\":\"" + new_value2 +
                    "\",\"value3\":\"" + new_value3 + "\"}";

  client.print("POST ");
  client.print("/trigger/" + event + "/with/key/" + auth_key);  //url
  client.println(" HTTP/1.1");

  client.println("Host: " + String(IFTTT_URL));
  client.println("User-Agent: ESP8266");
  client.println("Accept: */*");
  client.println("Content-Length: " + String(postData.length()));
  client.println("Content-Type: application/json");
  client.println("Connection: close");
  client.println();
  client.println(postData);
  client.println();
/*
  Serial.println("Request sent");
  Serial.println("Reply:");

  while (client.connected()) {    //NOTE: WTF, still not working, no idea
    Serial.print("A: ");
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line.indexOf("event") != -1 ){
      Serial.println("Post Successful");
      return true;
    }
  }*/
  //no success
  return false;

}

/*
bool ESP_To_IFTTT::setValues(const String new_value1, const String new_value2, const String new_value3)
{
  value[0] = new_value1;
  value[1] = new_value2;
  value[2] = new_value3;
  return true;
}
*/
