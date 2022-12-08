#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

const char* ssid = "sor";
const char* password = "Cen";

Servo servo1;
int servo1Pin = D1;
int servo1Pos = 0;

Servo servo2;
int servo2Pin = D2;
int servo2Pos = 0;

Servo servo3;
int servo3Pin = D3;
int servo3Pos = 0;

ESP8266WebServer server(80);

void handleRoot() {
  String message = "Hello from ESP8266!\n";
  message += "Servo 1 position: ";
  message += servo1Pos;
  message += "\n";
  message += "Servo 2 position: ";
  message += servo2Pos;
  message += "\n";
  message += "Servo 3 position: ";
  message += servo3Pos;
  server.send(200, "text/plain", message);
}

void handleServo1() {
  if (server.hasArg("pos")) {
    servo1Pos = server.arg("pos").toInt();
    servo1.write(servo1Pos);
  }
  String message = "Servo 1 position set to: ";
  message += servo1Pos;
  server.send(200, "text/plain", message);
}

void handleServo2() {
  if (server.hasArg("pos")) {
    servo2Pos = server.arg("pos").toInt();
    servo2.write(servo2Pos);
  }
  String message = "Servo 2 position set to: ";
  message += servo2Pos;
  server.send(200, "text/plain", message);
}

void handleServo3() {
  if (server.hasArg("pos")) {
    servo3Pos = server.arg("pos").toInt();
    servo3.write(servo3Pos);
  }
  String message = "Servo 3 position set to: ";
  message += servo3Pos;
  server.send(200, "text/plain", message);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/servo1", handleServo1);
  server.on("/servo2", handleServo2);
  server.on("/servo3", handleServo3);
  server.begin();// Start Webpage
Serial.println("HTTP server started");
}
void loop()
{
server.handleClient(); //Listen for data requests from weebpage
}
