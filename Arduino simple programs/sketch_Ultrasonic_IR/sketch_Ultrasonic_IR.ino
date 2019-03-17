#include <IRremote.h>
const int irReceiverPin = 7; //the SIG of receiver module attach to pin7
const int trigPin = 9;
const int echoPin = 10;
char dataString[50] = {0};
int a = 0;

long duration;
int distance;
int distanceInch;

IRrecv irrecv(irReceiverPin); //Creates a variable of type IRrecv
decode_results results;


enum commands {
  CHMinus,
  CH,
  CHPlus,
  Back,
  Forward,
  PlayPause,
  Minus,
  Plus,
  EQ,
  Zero,
  HunderdPlus,
  TwoHundredPlus,
  One,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine
};

enum commands command;
enum commands lastCommand;

void setup()
{
  Serial.begin(9600);//initialize serial
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  irrecv.enableIRIn(); //enable ir receiver module
}

void loop()
{
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    distanceInch = duration * 0.0133 / 2;
    delay(10);
    //Serial.print("Distance: ");
    //Serial.print(distance);
    //Serial.println("");
  }

  if (irrecv.decode(&results)) //if the ir receiver module receiver data
  {

    //    Serial.print("irCode: "); //print"irCode: "
    //    Serial.print(results.value, HEX); //print the value in hexdecimal
    //    Serial.print(", bits: "); //print" , bits: "
    //    Serial.println(results.bits); //print the bits
    //    Serial.println("");

    if (results.value == 0xFFA25D) {
      command = CHMinus;
    }

    if (results.value == 0xFF629D) {
      command = CH;
    }

    if (results.value == 0xFFE21D) {
      command = CHPlus;
    }

    if (results.value == 0xFF22DD) {
      command = Back;
    }

    if (results.value == 0xFF02FD) {
      command = Forward;
    }

    if (results.value == 0xFFC23D) {
      command = PlayPause;
    }

    if (results.value == 0xFFE01F) {
      command = Minus;
    }

    if (results.value == 0xFFA857) {
      command = Plus;
    }

    if (results.value == 0xFF906F) {
      command = EQ;
    }

    if (results.value == 0xFF6897) {
      command = Zero;
    }

    if (results.value == 0xFF9867) {
      command = HunderdPlus;
    }

    if (results.value == 0xFFB04F) {
      command = TwoHundredPlus;
    }

    if (results.value == 0xFF30CF) {
      command = One;
    }

    if (results.value == 0xFF18E7) {
      command = Two;
    }

    if (results.value == 0xFF7A85) {
      command = Three;
    }

    if (results.value == 0xFF10EF) {
      command = Four;
    }

    if (results.value == 0xFF38C7) {
      command = Five;
    }

    if (results.value == 0xFF5AA5) {
      command = Six;
    }

    if (results.value == 0xFF42BD) {
      command = Seven;
    }

    if (results.value == 0xFF4AB5) {
      command = Eight;
    }

    if (results.value == 0xFF52AD) {
      command = Nine;
    }

    if (results.value == 0xFFFFFFFF) {
      command = lastCommand;
    }

    lastCommand = command;

    if (distance < 100 && command == PlayPause) {
      //Serial.print("command: "); //print" , bits: "
      Serial.println(command); //print the bits
      //Serial.println("");
    }

    irrecv.resume(); // Receive the next value
  }

  if (distance < 100) {
    Serial.println(25);
  } else {
    Serial.println(30);
  }

  delay(1000); //delay 600ms
}


/*
  Hex code: button

  FFA25D  CH-
  FF629D  CH
  FFE21D  CH+
  FF22DD  <<
  FF02FD  >>
  FFC23D  >||
  FFE01F  -
  FFA857  +
  FF906F  EQ
  FF6897  0
  FF9867  100+
  FFB04F  200+
  FF30CF  1
  FF18E7  2
  FF7A85  3
  FF10EF  4
  FF38C7  5
  FF5AA5  6
  FF42BD  7
  FF4AB5  8
  FF52AD  9


  CHMinus,
  CH,
  CHPlus
  Back,
  Forward,
  PlayPause,
  Minus
  Plus,
  EQ,
  Zero,
  HunderdPlus,
  TwoHundredPlus,
  One,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine
*/

