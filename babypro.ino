#include "SoftwareSerial.h"

#define motor11 4 
#define motor12 7

#define motor21 8 
#define motor22 12

/// Ultrasonic

const int trigPin = 11;

const int echoPin = 13;



String ssid ="Redmi";

String password="SUNCYGININ";

SoftwareSerial esp(2, 3);// RX, TX



void setup() {

  pinMode(motor11, OUTPUT);
  pinMode(motor12, OUTPUT);
  
  pinMode(motor21, OUTPUT);
  pinMode(motor22, OUTPUT);  

//pinMode (DHpin, OUTPUT);

esp.begin(115200);

Serial.begin(115200);

reset();

connectWifi();

}




//reset the esp8266 module

void reset() {

esp.println("AT+RST");

delay(1000);

if(esp.find("OK") ) Serial.println("Module Reset");

}



//connect to your wifi network

void connectWifi() {
  Serial.print("Connecting...");

String cmd = "AT+CWJAP=\"" +ssid+"\",\"" + password + "\"";

esp.println(cmd);

delay(4000);

if(esp.find("OK")) {

Serial.println("Connected!");

}

else {

connectWifi();

Serial.println("Cannot connect to wifi"); }

}





void loop () {



long duration, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);


  cm = duration / 29 / 2;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);

if(cm<25)
{
 Serial.println("OBSTACLE AHEAD..");

  digitalWrite(motor11, LOW); //Motor stops//

  digitalWrite(motor21, LOW); //Motor stops// 
     digitalWrite(motor12, LOW);
     digitalWrite(motor22, LOW); 
  
    callurl();
}
  else
  {
      Serial.println("SAFE MOVEMENT..");

       digitalWrite(motor11,HIGH); 
   digitalWrite(motor22, HIGH);


     digitalWrite(motor12, LOW);
     digitalWrite(motor21, LOW); 
          
  }
  

delay(1000);

}







// Call a URL

void callurl()
{

//connectWifi();
  
  String cmd;
   Serial.println("URL Called");

String ncmd = "AT+CIPSTART=\"TCP\",\"";
 ncmd += "192.168.43.146";  // 184.106.153.149 thingspeak IP address
 ncmd += "\",80";
 esp.println(ncmd);
//delay(10000);
 if(esp.find("Error"))
 {
   Serial.println("AT+CIPSTART error");
   return;
}
String hostt = "GET /babycare/api.php";
hostt += "\r\n";
hostt += "Host:192.168.43.146";
hostt += "\r\n\r\n\r\n\r\n\r\n\r\n";
esp.println(hostt);

cmd = "AT+CIPSEND=";
cmd += String(hostt.length());

Serial.println("Length");
Serial.println(cmd);

esp.println(cmd);

if(esp.find(">")){
  
esp.print(hostt);

delay(2000);

}


else{
  
esp.println("AT+CIPCLOSE");
// alert user
Serial.println("AT+CIPCLOSE");
}
delay(5000);




  }
