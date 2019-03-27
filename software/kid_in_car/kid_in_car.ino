#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX
int switchstate = 0;

void setup() { 
  BTserial.begin(9600);    
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // declare the LED pins as outputs
  pinMode(3, OUTPUT);
  // declare the switch pin as an input
  pinMode(2, INPUT);

/*
  String setName = String("AT+NAME=KID_IN_CAR\r\n");
  BTserial.begin(9600);
  BTserial.print("AT\r\n"); //Check Status
  delay(500);
  while (BTserial.available()) {
      BTserial.read();
  }
  BTserial.print(setName); //Send Command to change the name
  delay(500);
  while (BTserial.available()) {
      BTserial.read();
  }
  digitalWrite(3, HIGH);
*/
}

void blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void bt_send_data(int data) {
  //IMPORTANT: The complete String has to be of the Form: 1234,1234,1234,1234;
  //(every Value has to be seperated through a comma (',') and the message has to
  //end with a semikolon (';')) 
  //BTserial.print("FORGETMENOT:KIDINCAR");  
  //BTserial.print(",");  
  if (data == 1) {
    BTserial.print("FORGETMENOT:KIDINCAR:TRUE");  
  } else {
    BTserial.print("FORGETMENOT:KIDINCAR:FALSE");
  }
  BTserial.print(";");
}

void loop() {
/*
  char c = "";
  while (BTserial.available()) {
    c = BTserial.read();
    if (c == 'T') {
      BTserial.print("FORGETMENOT:KIDINCAR:PING:RESP");
      c = "";
    }
  }
*/
  
  //blink();
  // read the value of the switch
  switchstate = digitalRead(2);
  
  if (switchstate == HIGH) {
    //car seat has kid
    digitalWrite(3, HIGH); // turn the green LED on pin 3 on
    bt_send_data(1);
  } else {
    digitalWrite(3, LOW);  // turn the green LED on pin 3 off
    bt_send_data(0);
  }

  delay(50);

}
