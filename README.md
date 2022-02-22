# HOW TO MEASURE HEIGHT USING AN ULTRASONIC SENSOR CONTROLLED BY A KEYPAD
## INTRODUCTION
This project is based on the development of a height measuring machine that could be useful in schools, hospitals etc. It is essential to know ones height because the data can be used by medical personnel to collate data for  medical reports.  
 
## PROBLEM STATEMENT 
 In the world today medical personnel in hospitals in most countries developed or developing, go through stress attending to the basic hospital checks of the patients. Not only does this stress them but it also leaves them vulnerable to communicable diseases during contact with the patients such as catarrh, cough etc. Using a calibrated meter rule to measure height, one has to get someone who is much taller to check the meter rule. Using a digital height measurement device saves all that stress.

## PROPOSED SOLUTION
Well the solution to the aforementioned problem is to introduce a system that measures height digitally.  All these are to be done without contact with any patient to reduce transfer of communicable diseases. This system runs on a program which will in turn store the data it has gotten from each patient. 

## COMPONENTS USED
	• Ultrasonic sensor
 	• Arduino Uno
	• Jumper wires
	• 220Ω Resistor 
	• 1604A LCD
	• 4*4 matrix keypad
	• Breadboard
	
  ## SCHEMATIC DIAGRAM 
  
  
  ## METHODOLOGY
•	VSS on the LCD goes to GND

•	VDD on the LCD goes to 5v on the arduino  

•	VO on the LCD goes to the ground.

•	RS on the LCD goes to pin 8 on the arduino. 

•	RW on the LCD goes to ground. 

•	E on the LCD goes to pin 9 on the arduino. 

•	Digital pin( 4 -7) to pin (10-13) on the arduino respectively.

•	LEDA pin on the LCD to 5v. 

•	LEDK pin on the LCD to a 2KΩ to the ground.


### KEYPAD 

•	Pin R1 to pin 7 on the arduino board. 

•	Pin R2 to pin 6 on the arduino board. 

•	Pin R3 to pin 5 on the arduino board. 

•	Pin R4 to pin 4 on the arduino board. 

•	Pin C1 to pin 3 on the arduino board.

•	Pin C2 to pin 2 on the arduino board. 

•	Pin C3 to pin A6 on the arduino board.  

•	Pin C4 to pin A8 on the arduino board. 


### ULTRASONIC SENSOR.
•	VCC to 5v. 

•	Trig pin to pin A5 on the arduino board. 

•	Echo pin to pin A6 on the arduino board. 

•	Ground pin to ground. 




  
