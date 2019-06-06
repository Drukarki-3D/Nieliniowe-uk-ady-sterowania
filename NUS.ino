/* Paweł Jędrzejak, Bartosz Jaworek, Kacper Bednarczyk 2019*/
//
// Steppers
//
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif

//
// Limit Switches
//
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

int stepsX = 0;
int stepsY = 0;
int stepsZ = 0;

bool done = true;

bool dirX = 0;
bool dirY = 0;
bool dirZ = 0;

//silniki 

  int s1=0, s2=0, s3=0;
  bool kier1=0, kier2=0, kier3=0; 

void setup() {
  Serial.begin(115200);
  //ustawienie wejsc i wyjsc dla ENABLE
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);

  //ustawienie wejsc i wyjsc dla DIR
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);

  //wlaczenie silnikow
  digitalWrite(X_ENABLE_PIN, !HIGH);
  digitalWrite(Y_ENABLE_PIN, !HIGH);
  digitalWrite(Z_ENABLE_PIN, !HIGH);

  //ustawienie wejsc i wyjsc dla STEP
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Z_STEP_PIN, OUTPUT);

  //krancowki z pullupem
  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);

}

void loop() {
  
  //podanie sygnalu wysokiego na silniki
  if(((digitalRead(X_MAX_PIN) == 0 && kier1 == 0) || kier1 == 1) && s1 > 0 )
  {
    digitalWrite(X_STEP_PIN, HIGH);
    s1--;
  }
  if(((digitalRead(Y_MAX_PIN) == 0 && kier2 == 0) || kier2 == 1) && s2 > 0 )
  {
    digitalWrite(Y_STEP_PIN, HIGH);
    s2--;
  }
  if(((digitalRead(Z_MAX_PIN) == 0 && kier3 == 0) || kier3 == 1) && s3 > 0 )
  {
    digitalWrite(Z_STEP_PIN, HIGH);
    s3--;
  }
  delay(1);
  
  //podanie sygnalu niskiego na silniki
    digitalWrite(X_STEP_PIN, LOW);
    digitalWrite(Y_STEP_PIN, LOW);
    digitalWrite(Z_STEP_PIN, LOW);
  delay(1);
/*
  if(dirX == 1)
  {
    digitalWrite(X_STEP_PIN, LOW);
  }
  if(dirY == 1)
  {
    digitalWrite(Y_STEP_PIN, LOW);
  }
  if(dirZ == 1)
  {
    digitalWrite(Z_STEP_PIN, LOW);
  }
  delay(1);
  
  if(dirX == 1)
  {
    digitalWrite(X_STEP_PIN, HIGH);
  }
  if(dirY == 1)
  {
    digitalWrite(Y_STEP_PIN, HIGH);
  }
  if(dirZ == 1)
  {
    digitalWrite(Z_STEP_PIN, HIGH);
  }
  delay(1);
  
  if(stepsX >= 100)
    dirX = !dirX;
  if(stepsY >= 100)
    dirY = !dirY;
  if(stepsZ >= 100)
    dirZ = !dirZ;
      
  {
    digitalWrite(X_STEP_PIN, LOW);
    digitalWrite(Y_STEP_PIN, LOW);
    digitalWrite(Z_STEP_PIN, LOW);
  }

  //drukowanie danych z krancowek
  Serial.println(digitalRead(X_MAX_PIN));
  Serial.println(digitalRead(Y_MAX_PIN));
  Serial.println(digitalRead(Z_MAX_PIN));
*/

  //lab2 sterowanie silnikami zadanymi wartosciami


  while(Serial.available()>0)
  {
    done = false;
    //wysylanie wiadomosci z PC do Arduino
    String msg;
    msg = Serial.readStringUntil('\n');
    sscanf(msg.c_str(),"a %d b %d c %d", &s1,&s2,&s3);

    // ustawienie kierunku ruchu
    kier1 = s1 < 0; // silnik X
    kier2 = s2 < 0; // silnik Y
    kier3 = s3 < 0; // silnik Z

    // podanie kierunku na pin
    digitalWrite(X_DIR_PIN, kier1);
    digitalWrite(Y_DIR_PIN, kier2);
    digitalWrite(Z_DIR_PIN, kier3);

    // ilosc krokow (bez kierunku) 
    s1 = abs(s1);
    s2 = abs(s2);
    s3 = abs(s3);
    
    Serial.println(s1);
    Serial.println(s2);
    Serial.println(s3);
  }

  
  //Komunikat o sukcesie
  if(s1 == 0 && s2 == 0 && s3 == 0 && done == false)
  {
    done = true;
    Serial.println("OK!");
  }
  
}
