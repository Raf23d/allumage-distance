int digit1 = 2; //Afficheur le plus à gauche - chiffre 1000
int digit2 = 3; //Afficheur centre gauche - chiffre 100
int digit3 = 4; //Afficheur centre droit - chiffre 10
int digit4 = 5; //Afficheur le plus à droite - chiffre 1

int segA = 6; //Led A
int segB = 7; //Led B
int segC = 8; //Led C
int segD = 9; //Led D
int segE = 10; //Led E
int segF = 11; //Led F
int segG = 12; //Led G
int dp = 13; //Led dp (= digital point)

int aff = 0; //chiffre à afficher
int tpsAllume = 0; //tps pendant lequel ce sera allumé
int ecartAll = 0; //tps d'ecart entre llumage du 1,2,3

int switchPin = 42; //pin du boutton
boolean switchState = LOW; //etat du bouton

int buttonPin = 40; //pin du boutton
boolean buttonState = LOW; //etat du bouton
int resultButton = 0; //nb appuis boutton
int resultButton2 = 0; //nb appuis boutton (2)


void setup() {
pinMode(digit1, OUTPUT);
pinMode(digit2, OUTPUT);
pinMode(digit3, OUTPUT);
pinMode(digit4, OUTPUT);

pinMode(segA, OUTPUT);
pinMode(segB, OUTPUT);
pinMode(segC, OUTPUT);
pinMode(segD, OUTPUT);
pinMode(segE, OUTPUT);
pinMode(segF, OUTPUT);
pinMode(segG, OUTPUT);
pinMode(dp, OUTPUT);

pinMode(buttonPin, INPUT);

//On commence par tout éteindre
digitalWrite(digit1, LOW);
digitalWrite(digit2, LOW);
digitalWrite(digit3, LOW);
digitalWrite(digit4, LOW);
}

void afficheDigit(int num){
//initialisation des chiffres (0,1,2,3,4,5,6,7,8,9)
 if (num==0)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, LOW);
   digitalWrite(segG, HIGH);
   digitalWrite(dp, HIGH);
   }
 if (num==1)
   {
   digitalWrite(segA, HIGH);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, HIGH);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, HIGH);
   digitalWrite(dp, HIGH);
   }
 if (num==2)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, HIGH);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
 if (num==3)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
 if (num==4)
   {
   digitalWrite(segA, HIGH);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, HIGH);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
 if (num==5)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, HIGH);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
 if (num==6)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, HIGH);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
 if (num==7)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, HIGH);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, HIGH);
   digitalWrite(segG, HIGH);
   digitalWrite(dp, HIGH);
   }
 if (num==8)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, LOW);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
 if (num==9)
   {
   digitalWrite(segA, LOW);
   digitalWrite(segB, LOW);
   digitalWrite(segC, LOW);
   digitalWrite(segD, LOW);
   digitalWrite(segE, HIGH);
   digitalWrite(segF, LOW);
   digitalWrite(segG, LOW);
   digitalWrite(dp, HIGH);
   }
} //fin de l'initialization


void affiche4digits(int num){
//Affiche un nb à 2 chiffres
int nb; //calcul d'un nb entier

//affiche le chiffre des 10
num=num-nb*100;
nb=num/10;
digitalWrite(digit2, LOW);
digitalWrite(digit3, HIGH);
afficheDigit(nb);
delay(0002);  

//affiche le chiffre des 1
num=num-nb*10;
nb=num;
digitalWrite(digit3, LOW);
digitalWrite(digit4, HIGH);
afficheDigit(nb);
delay(0002);  
}


void loop(){
switchState = digitalRead(switchPin);

if (switchState == LOW) {
  buttonState = digitalRead(buttonPin);
  //surveil appuis boutton
  if (buttonState == HIGH) {
    resultButton += 1 ;
    delay(0500);
  }
  //designe le tps allumé
  if (resultButton == 0) {
    tpsAllume = 1 ;
  }
  if (resultButton == 1) {
    tpsAllume = 5 ;
  }
  if (resultButton == 2) {
    tpsAllume = 10 ;
  }
  if (resultButton == 3) {
    tpsAllume = 30 ;
  }
  if (resultButton == 4) {
    tpsAllume = 60 ;
  }
  if (resultButton > 4) {
    resultButton = 0 ;
  }

  aff = tpsAllume ;
  affiche4digits(aff);
}


if (switchState == HIGH) {
  buttonState = digitalRead(buttonPin);
  //surveil appuis boutton
  if (buttonState == HIGH) {
    resultButton2 += 1 ;
    delay(0500);
  }
  //designe le tps allumé
  if (resultButton2 == 0) {
    ecartAll = 0 ;
  }
  if (resultButton2 == 1) {
    ecartAll = 1 ;
  }
  if (resultButton2 == 2) {
    ecartAll = 2 ;
  }
  if (resultButton2 == 3) {
    ecartAll = 5 ;
  }
  if (resultButton2 == 4) {
    ecartAll = 10 ;
  }
  if (resultButton2 > 4) {
    ecartAll = 0 ;
  }

  aff = ecartAll ;
  affiche4digits(aff);
}

}
