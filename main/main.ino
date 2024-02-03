//Enviroment Assumptions:
//3DS on brightness is on level 3
//The L and R buttons are always pressed
//Comments ending with (*) indicate the values need to be adjusted based on you enviroment and target

#include <Servo.h>

//Defines the pins for the A and Select button servo motors
const byte A_BTN_SERVO_PIN = 6;
const byte SELECT_BTN_SERVO_PIN = 7;

//Defines the analog pin for the LDR
const int LDR_PIN = A0; 

//Defines the pin for the piezo buzzer
const int BUZZER_PIN = 2;

//Stores the threshold before (*)
const int SHINY_LIGHT_THRESHOLD = 26;

//Stores the duration of a single encounter (*)
const int ENCOUNTER_DURATION = 10000;

//Stores the frequencies used by the piezo buzzer for different notes
const short MIDDLE_C_FREQU = 261;
const short C_S_FREQU = 277;
const short D_FREQU = 294;
const short D_S_FREQU = 311;
const short E_FREQU = 330;
const short F_FREQU = 349;
const short F_S_FREQU = 370;
const short G_FREQU = 392;
const short G_S_FREQU = 415;
const short A_FREQU = 440;

//Stores the A and Select button servo motors
Servo aBtnServo;
Servo selectBtnServo;

//Stores the current number of encounters that have passed
int currentEncounters = 0;

//Store the LDR value
int ldrValue = 0;

//The entry point of the program
void setup() {
  
  //Initializes the A and Select button servo motors
  aBtnServo.attach(A_BTN_SERVO_PIN);
  selectBtnServo.attach(SELECT_BTN_SERVO_PIN);

  //Resets the position of the A and Select button servo motors
  aBtnServo.write(0);
  selectBtnServo.write(0);

  //Sets the buzzer pin as an output pin
  pinMode(BUZZER_PIN, OUTPUT);

  //Enable the serial console
  Serial.begin(9600);

  //Do a soft reset
  softReset();
}

//Repeates until the program ends
void loop() {

  //Wait for the previous encounter to finish
  delay(ENCOUNTER_DURATION);

  //Start another encounter
  doEncounter();
}

//Does a new encounter
void doEncounter(){
  
  //Opening cutscene 1 (*)
  pressA();
  delay(3500);

  //Opening cutscene 2 (*)
  pressA();
  delay(4500);

  //Continue (*)
  pressA();
  delay(3750);

  //Talk to portal 1 (*)
  pressA();
  delay(1000);

  //Talk to portal 2 (*)
  pressA();
  delay(750);

  //Talk to portal 3 (*)
  pressA();
  delay(500);

  //Talk to portal 4 (*)
  pressA();
  //delay(500);

  //These commented out lines and should be uncommented if you are shiny hunting Latios/Latias
  /*//Talk to Latios 1 (*)
  pressA();
  delay(2500);

  //Talk to Latios 2 (*)
  pressA();*/

  //Wait for encounter cutscene (*)
  //This value must be finetuned based on your lead pokemon and the target pokemon
  delay(13125);

  //Gets the current value of the LDR
  ldrValue = getLightData();
  Serial.print("Encounter Number: ");
  Serial.print(currentEncounters);
  Serial.print(" | LDR Value: ");
  Serial.println(ldrValue);
  
  //Checks if after the expected time the bottom screen shows the menu options
  //If the menu options are visible, no shiny was found since it took the same amount of time to encounter as a normal pokemon
  //If the menu options are still not visible, this encounter is taking longer and is therfore a shiny pokemon
  if(ldrValue >= SHINY_LIGHT_THRESHOLD){

    //Prints to the console that no shiny was found
    Serial.println("No shiny, resetting game...");

    //Soft reset the 3DS
    softReset();
  }
  else{

      //Prints to the console that a shiny was found
      Serial.print("Shiny found in ");
      Serial.print(currentEncounters);
      Serial.println(" encounters!");

      //Loops until the user ends the program since the shiny was found
      shinyFound();
  }
}

//Does a soft reset
void softReset(){

  //Presses the select button
  pressSelect();

  //Increment the number of encounters
  currentEncounters++;
}

//Gets the value from the LDR
int getLightData(){
  return analogRead(LDR_PIN);
}

//Presses the A button using the servo motor (*)
void pressA(){
  aBtnServo.write(63)
  delay(300);
  aBtnServo.write(0);
}

//Presses the Select button using the servo motor (*)
void pressSelect(){
  selectBtnServo.write(47);//47
  delay(300);
  selectBtnServo.write(0);
}

//Actions to take since a shiny pokemon was found
void shinyFound(){

  //Keeps playing the pokemon catch success music to notify the user a shiny pokemon has been found
  while(true){
    tone(BUZZER_PIN, E_FREQU);
    delay(125);
    tone(BUZZER_PIN, D_FREQU);
    delay(125);
    tone(BUZZER_PIN, MIDDLE_C_FREQU);
    delay(125);
    tone(BUZZER_PIN, D_FREQU);
    delay(125);
    
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(200);

    tone(BUZZER_PIN, F_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, F_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, F_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(200);

    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(200);

    tone(BUZZER_PIN, E_FREQU);
    delay(125);
    tone(BUZZER_PIN, D_FREQU);
    delay(125);
    tone(BUZZER_PIN, MIDDLE_C_FREQU);
    delay(125);
    tone(BUZZER_PIN, D_FREQU);
    delay(125);

    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(100);

    tone(BUZZER_PIN, MIDDLE_C_FREQU);
    delay(50);
    noTone(BUZZER_PIN);
    delay(50);
    
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, E_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(75);

    noTone(BUZZER_PIN);
    delay(75);
    tone(BUZZER_PIN, F_FREQU);
    delay(75);
    noTone(BUZZER_PIN);
    delay(125);

    noTone(BUZZER_PIN);
    delay(400);
  }
}
