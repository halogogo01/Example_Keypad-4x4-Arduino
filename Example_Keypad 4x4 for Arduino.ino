#include <Keypad.h> //เรียกLiberyที่ชื่อKeypad.hมาใช้
const byte ROWS = 4; //เก็บค่า4ไว้ใช้กับแกนROW
const byte COLS = 4; //เก็บค่า4ไว้ใช้กับแกนCOL
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //หมายเลขPINบนบอร์ดArduinoที่ต่อกับแกนROWS
byte colPins[COLS] = {5, 4, 3, 2}; //หมายเลขPINบนบอร์ดArduinoที่ต่อกับแกนCOLS
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //เปิดการการทำงานLibery "Keypad.h" โดยใส่ค่าPINที่เชื่อมต่อกับArduinoที่เรากำหนดให้เป็นแกนROW ตามด้วยแกนCOLS ต่อด้วยจำนวนที่มีในแกนROW และต่อด้วยจำนวนที่มีในแกนCOL

void setup() {
  Serial.begin(9600);
  Serial.println("Please Enter Key : ");
}
void loop() {
  char key = keypad.getKey(); //สร้างตัวแปรประเภทcharชื่อkey โดยเก็บค่าที่รับจากการกดคีแพดมาเก็บไว้ในตัวแปลkey
  if (key != NO_KEY) { //เงือนไขถ้าตัวแปลkeyไม่มีค่าว่างเปล่าให้ทำงาน
    Serial.println(key); //แสดงค่าในตัวแปลkeyออกมา
  }
}
