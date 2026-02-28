#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LED 9
#define BUT 10
#define BUZ 6
#define STATE 2

#define DOT  300
#define DASH 900

int a , p ;
unsigned long starttime , pressduration , notpressed ;
int i=0;
int i2;
int j=0;
int j2=0;
bool end=false , first_iteration=true ;
String x ="";
String y ;
int state;

void translate()
{
  if      (x == ".-")     { 
      Serial.println("A"); 
      display.print("A"); 
  }
  else if (x == "-...")   { 
      Serial.println("B"); 
      display.print("B"); 
  }
  else if (x == "-.-.")   { 
      Serial.println("C"); 
      display.print("C"); 
  }
  else if (x == "-..")    { 
      Serial.println("D"); 
      display.print("D"); 
  }
  else if (x == ".")      { 
      Serial.println("E"); 
      display.print("E"); 
  }
  else if (x == "..-.")   { 
      Serial.println("F"); 
      display.print("F"); 
  }
  else if (x == "--.")    { 
      Serial.println("G"); 
      display.print("G"); 
  }
  else if (x == "....")   { 
      Serial.println("H"); 
      display.print("H"); 
  }
  else if (x == "..")     { 
      Serial.println("I"); 
      display.print("I"); 
  }
  else if (x == ".---")   { 
      Serial.println("J"); 
      display.print("J"); 
  }
  else if (x == "-.-")    { 
      Serial.println("K"); 
      display.print("K"); 
  }
  else if (x == ".-..")   { 
      Serial.println("L"); 
      display.print("L"); 
  }
  else if (x == "--")     { 
      Serial.println("M"); 
      display.print("M"); 
  }
  else if (x == "-.")     { 
      Serial.println("N"); 
      display.print("N"); 
  }
  else if (x == "---")    { 
      Serial.println("O"); 
      display.print("O"); 
  }
  else if (x == ".--.")   { 
      Serial.println("P"); 
      display.print("P"); 
  }
  else if (x == "--.-")   { 
      Serial.println("Q"); 
      display.print("Q"); 
  }
  else if (x == ".-.")    { 
      Serial.println("R"); 
      display.print("R"); 
  }
  else if (x == "...")    { 
      Serial.println("S"); 
      display.print("S"); 
  }
  else if (x == "-")      { 
      Serial.println("T"); 
      display.print("T"); 
  }
  else if (x == "..-")    { 
      Serial.println("U"); 
      display.print("U"); 
  }
  else if (x == "...-")   { 
      Serial.println("V"); 
      display.print("V"); 
  }
  else if (x == ".--")    { 
      Serial.println("W"); 
      display.print("W"); 
  }
  else if (x == "-..-")   { 
      Serial.println("X"); 
      display.print("X"); 
  }
  else if (x == "-.--")   { 
      Serial.println("Y"); 
      display.print("Y"); 
  }
  else if (x == "--..")   { 
      Serial.println("Z"); 
      display.print("Z"); 
  }
  else                    { 
      Serial.print("?"); 
      display.print("?"); 
  }
}
void translate2()
{
    if      (x[j] == 'A')  y = ".-";
    else if (x[j] == 'B')  y = "-...";
    else if (x[j] == 'C')  y = "-.-.";
    else if (x[j] == 'D')  y = "-..";
    else if (x[j] == 'E')  y = ".";
    else if (x[j] == 'F')  y = "..-.";
    else if (x[j] == 'G')  y = "--.";
    else if (x[j] == 'H')  y = "....";
    else if (x[j] == 'I')  y = "..";
    else if (x[j] == 'J')  y = ".---";
    else if (x[j] == 'K')  y = "-.-";
    else if (x[j] == 'L')  y = ".-..";
    else if (x[j] == 'M')  y = "--";
    else if (x[j] == 'N')  y = "-.";
    else if (x[j] == 'O')  y = "---";
    else if (x[j] == 'P')  y = ".--.";
    else if (x[j] == 'Q')  y = "--.-";
    else if (x[j] == 'R')  y = ".-.";
    else if (x[j] == 'S')  y = "...";
    else if (x[j] == 'T')  y = "-";
    else if (x[j] == 'U')  y = "..-";
    else if (x[j] == 'V')  y = "...-";
    else if (x[j] == 'W')  y = ".--";
    else if (x[j] == 'X')  y = "-..-";
    else if (x[j] == 'Y')  y = "-.--";
    else if (x[j] == 'Z')  y = "--..";
    else {y="ERRORE";}
}




void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BUT, INPUT_PULLUP);
  pinMode(STATE , INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Errore: SSD1306 non trovato"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); 
  //display.setCursor(10, 20); 
  Serial.begin(9600);
  Serial.println("INIZIALIZZATO CORRETTAMENTE");
  delay(2000);
  a=digitalRead(BUT);
  display.clearDisplay();
}

void loop() 
{
  display.clearDisplay();
  if(first_iteration)
  {
    display.setTextSize(3);
    display.setCursor(0, 20);
    display.clearDisplay();
    display.print("PRONTO");
    display.display();
    first_iteration=false;
    delay(200);
  }
  state=digitalRead(STATE);
  //Serial.println(state);
  if(state==1)
  {
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("MORSE");
    display.println("TO");
    display.println("TEXT");
    display.display();
    p=a;
    a=digitalRead(BUT);
    display.setTextSize(5);
    display.setCursor(49, 12);
    if(p==1&&a==0)
    {
        starttime=millis();
        notpressed=0;
        digitalWrite(LED,1);
        tone(BUZ,1000);
    }
    if(p==0&&a==1)
    {
        pressduration=millis()-starttime;
        notpressed=millis();
        digitalWrite(LED,0);
        noTone(BUZ);
    }
    if(pressduration>50)
    {
        if(pressduration<500)
        {
        Serial.print(".");
        x+='.';
        }
        else
        {
        Serial.print("-");
        x+='-';
        }
        pressduration=0;
        i++;
    }
    if(a==1 && notpressed>0)
    {
        if(millis()-notpressed>2000)
        {
        Serial.println();
        end=true;
        notpressed=0;
        }
    }
    if(end)
    {
        if(first_iteration){first_iteration=false;}
        end=false;
        i=0;
        display.clearDisplay();
        translate();
        display.display();
        delay(800);
        x="";
    }
  }
    if (state == 0)
  {
    while (Serial.available() > 0) 
    {
        Serial.read();         
    }
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("TEXT");
    display.println("TO");
    display.println("MORSE");
    display.display();
    if (Serial.available()> 0)
    {
      x = Serial.readString();
      i = x.length();
    }

    while (i > 0)
    {
      if (x[j] > 'A' || x[j] < 'Z') 
      {
        translate2();
      }

      Serial.println(y);
      i2 = y.length();
      j++;
      i--;
    while(i2>0)
    {   
        display.clearDisplay();
        if(y[j2]=='.')
        {
            display.setTextSize(5);
            display.setCursor(49, 12);
            display.print(".");
            tone(BUZ,1000);
            delay(DOT);
            noTone(BUZ);
            delay(DOT);
            Serial.println("PUNTO");
        }
        else if (y[j2]=='-')
        {
            display.setTextSize(5);
            display.setCursor(49, 12);
            display.print("-");
            tone(BUZ,1000);
            delay(DASH);
            noTone(BUZ);
            delay(DOT);
            Serial.println("LINEA");
        }
        else{}
        display.display();
        delay(DASH);
        j2++;
        i2=i2-1;
    }
    j2=0;
  }
  j=0;
    }
} 

