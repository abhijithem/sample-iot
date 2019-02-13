#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>


const char* ssid = "test";

const char* password = "1234567898";

byte LED = 2;                // device to control
char BT_input = ' ';
String WF_input = " ";
//IPAddress staticIP(192,168,1,22);

//IPAddress gateway(192,168,1,9);

//IPAddress subnet(255,255,255,0);


void setup(void)

{
  Serial.begin(9600);     // default baud rate of module
  pinMode(LED, OUTPUT);
  //Serial.begin(115200);

  Serial.println();

  Serial.printf("Connecting to %s\n", ssid);

  WiFi.begin(ssid, password);
  Serial.println();
  digitalWrite(LED, HIGH);

}
int cnt = 0;
void loop() {
  if (WiFi.status() == WL_CONNECTED && cnt >= 100)

  {
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    int value = analogRead(A0);
    String str = "http://api.thingspeak.com/update?api_key=W17KIL6ZCVQW2MUM&field1=" + String(value);
    HTTPClient http;  //Declare an object of class HTTPClient
    Serial.println(str);
    http.begin(str);
    int httpCode = http.GET();
    Serial.println(httpCode);
    delay(1000);
   
    http.end();  //Close connection

  }


  cnt++;
  delay(10);
}
