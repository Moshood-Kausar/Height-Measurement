//#include <UltrasonicSensor.h>

//#include <Adafruit_MLX90614.h>

#include <Wire.h>

#include <LiquidCrystal.h>

#include <Keypad.h>

LiquidCrystal lcd(8,9,10,11,12,13);
const int trigPin = A5;
const int echoPin = A4;
int enterkey_status=0;
int duration;
int HeightCM;
int HeightCM1;
int HeightCM2;
int HeightCM3;
int Heightfoot;
int Heightinch;
int count = 0;
int age = 0;
int no_pressed=0;
const byte ROWS = 4;
const byte COLS = 4;
byte colPins[COLS] = {3, 2, A6, A8};
byte rowPins[ROWS] = {7, 6, 5, 4};

char key[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

int NULL_HEIGHT;   
int calibration_status=0;
int error1;
int error2;
int error3;

Keypad keypad = Keypad( makeKeymap(key) , rowPins, colPins, ROWS, COLS);
void setup() {
  // put your setup code here, to run once:
 lcd.begin(16,4);
  lcd.setCursor(3,0);
  //lcd.print("You Pressed");
  Serial.begin(9600);
  lcd.begin(16,4); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  lcd.setCursor(0,0);
  lcd.print("RAIN - KAUSAR");
  lcd.setCursor(0,1);
  lcd.print("RAIN - DIEKOLA");
  delay(5000);
  lcd.setCursor(0,0);
  lcd.print("                                  ");
  lcd.setCursor(0,1);
  lcd.print("                                  ");

// calibration process

while (calibration_status==0){
calibration_status=calibrationprocess();
}

  lcd.setCursor(0,0);
  lcd.print("                                  ");
  lcd.setCursor(0,1);
  lcd.print("                                  ");


}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("AGE:");
  delay(200);
  char key = keypad.getKey();
  if (key!=NO_KEY) {
       if (key=='C'){
        Serial.println("C has been pressed");
        lcd.setCursor(3+count,0);
        lcd.print(" ");
        age = (age - no_pressed)/10; 
        count--;
        
       }

       else if(key== 'D'){
        enterkey_status=1;
      
       }


       
       else if(count<2){
        if (key == '1')   {
          no_pressed = 1;
        }
                else if (key == '2')   {
          no_pressed = 2;
        }
        else if (key == '3')   {
          no_pressed = 3;
        }
         else if (key == '4')   {
          no_pressed = 4;
        }
        else if (key == '5')   {
          no_pressed = 5;
        }
         else if (key == '6')   {
          no_pressed = 6;
        }
        else if (key == '7')   {
          no_pressed = 7;
        }
         else if (key == '8')   {
          no_pressed = 8;
        }
        else if (key == '9')   {
          no_pressed = 9;
        }
         else if (key == '0')   {
          no_pressed = 0;
        }
        
        
        
          count++;
   // lcd.setCursor(4,0);
    lcd.setCursor(3+count,0);
    lcd.print(key);
 
   
    age = age*10+no_pressed;
 // delay(5000);
   //delay(2000);
   // Serial.println(key);

        
       }

   //Serial.print("your age is therefore...");
   //Serial.println(age); 
   

  }
  
  if(enterkey_status ==1){
    delay(1000);
    
    lcd.setCursor(0,1);
  lcd.print("PLS STAND RIGHT");
  delay(5000);






HeightCM1=CalculateHeight();
delay(1000);
HeightCM2=CalculateHeight();
delay(1000);
HeightCM3=CalculateHeight();
HeightCM = (HeightCM1+HeightCM2+HeightCM3)/3;


Serial.println(HeightCM);

HeightCM=NULL_HEIGHT-HeightCM;
Heightfoot = HeightCM*0.033;
Heightinch = 12*((HeightCM*0.033)-Heightfoot);


lcd.setCursor(0,1); 
lcd.print("                          "); 
lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("HEIGHT:"); // Prints string "Distance" on the LCD


lcd.setCursor(7,1);
lcd.print("                                  ");
lcd.setCursor(7,1);
lcd.print(HeightCM); // Prints the distance value from the sensor
lcd.print("cm");

lcd.setCursor(7,2);
lcd.print("or");

lcd.setCursor(7,3);
lcd.print(Heightfoot); // Prints the distance value from the sensor
lcd.print("'");
lcd.print(Heightinch);



delay(5000);
enterkey_status=0;
lcd.clear();
count=0;
}


    }




int CalculateHeight(){

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    Serial.println(duration*0.034/2);
    return duration*0.034/2;

}


int calibrationprocess(){
  lcd.setCursor(0,0);
  lcd.print("CALIBRATING...");
  lcd.setCursor(0,1);
  lcd.print("PLEASE WAIT");
  delay(2000);

  
  
NULL_HEIGHT=CalculateHeight();
delay(3000);
error1=abs(CalculateHeight()-NULL_HEIGHT);
delay(3000);
error2=abs(CalculateHeight()-NULL_HEIGHT);
delay(3000);
error3=abs(CalculateHeight()-NULL_HEIGHT);
  
  lcd.setCursor(0,0);
  lcd.print("                 ");
  lcd.setCursor(0,1);
  lcd.print("                 ");

if(error1>2 || error2>2 || error3>2){
    lcd.setCursor(0,0);
  lcd.print("CALIBRATION");
  lcd.setCursor(0,1);
  lcd.print("FAILED");
   delay(5000);
   calibration_status=0; // failed
}
else {
  calibration_status=1; // successful
  lcd.setCursor(0,0);
  lcd.print("CALIBRATION");
  lcd.setCursor(0,1);
  lcd.print("SUCCESSFUL");
  delay(5000);
}
  return calibration_status;
}
