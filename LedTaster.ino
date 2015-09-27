
int inPin = 12;        
int ledRingPin = 5;

int redPin = 3;
int greenPin = 9;
int bluePin = 10;

int ledRingState = HIGH;   
int reading;          
int previous = LOW;   
int mode = 0;
boolean pressed = false;
boolean longPressed = false;

long time = 0;
long lastLoop = 0;

long debounce = 200;

int color0[3] = {0, 0, 0};
int color1[3] = {125, 0, 0};
int color2[3] = {255, 0, 0};
int color3[3] = {255, 125, 0};
int color4[3] = {255, 255, 0};
int color5[3] = {125, 255, 0};
int color6[3] = {0, 255, 0};
int color7[3] = {0, 255, 125};
int color8[3] = {0, 255, 255};
int color9[3] = {0, 125, 255};
int color10[3] = {0, 0, 255};
int color11[3] = {125, 0, 255};
int color12[3] = {255, 0, 255};
int color13[3] = {255, 125, 255};
int color14[3] = {255, 255, 255};
int color15[3] = {125, 125, 125};
int color16[3] = {80, 80, 80};
int color17[3] = {40, 40, 40};


int* colors[20];

void setup()
{
  pinMode(inPin, INPUT);
  pinMode(ledRingPin, OUTPUT);
  pinMode(redPin, INPUT);
  pinMode(greenPin, INPUT);
  pinMode(bluePin, INPUT); 
  
colors[0] = color0;
colors[1] = color1;
colors[2] = color2;
colors[3] = color3;
colors[4] = color4;
colors[5] = color5;
colors[6] = color6;
colors[7] = color7;
colors[8] = color8;
colors[9] = color9;
colors[10] = color10;
colors[11] = color11;
colors[12] = color12;
colors[13] = color13;
colors[14] = color14;
colors[15] = color15;
colors[16] = color16;
colors[17] = color17;

 
 
 
 
 
 
 
 
   Serial.begin(9600);
   
   
   
 
}

void loop()
{
  lastLoop = millis();
  pressed = false;
  reading = digitalRead(inPin);


    while (digitalRead(inPin) == HIGH && !longPressed && millis() - time > debounce) {
      pressed = true;
      longPressed = false;
      debounce = 200;
      
      if (millis() - lastLoop > 1000) {    
        longPressed = true;
        debounce = 1000;
      }
    }

  

  if (pressed && millis() - time > debounce) {
    if (longPressed) {
      mode = 0;
      ledRingState = HIGH;
      longPressed = false;
    } else {
      ledRingState = LOW;
        mode++;
        if (mode == 18) mode = 1;
        Serial.println(mode);

    }
      
      time = millis();
    }

  
  
  setLedIntensity(redPin, colors[mode][0]);
  setLedIntensity(greenPin, colors[mode][1]);
  setLedIntensity(bluePin, colors[mode][2]);  
 
  digitalWrite(ledRingPin, ledRingState);
  
  
  previous = reading;
}

void setLedIntensity(int ledPin, int value) {
  analogWrite(ledPin, 255-value);
}
