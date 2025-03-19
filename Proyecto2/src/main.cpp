#include <Arduino.h>

#define pin_led1 13
#define pin_led2 12
#define pin_led3 11
#define pin_led4 10
#define pin_led5 9
#define pin_switch1 8
#define pin_switch2 7
#define pin_switch3 6
#define pin_switch4 5 

bool ledStates[5] = {false, false, false, false, false};
unsigned long tiempo_actual;
unsigned long tiempo_anterior = 0;  
void printStatus();

void setup() {

  pinMode(pin_switch1, INPUT);
  pinMode(pin_switch2, INPUT);
  pinMode(pin_switch3, INPUT);
  pinMode(pin_switch4, INPUT);
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_led5, OUTPUT);
  Serial.begin(9600);  
}

void loop() {

  tiempo_actual = millis();
  
  // Leer el estado de los interruptores
  bool switch1high = digitalRead(pin_switch1) == HIGH;
  bool switch2high = digitalRead(pin_switch2) == HIGH;
  bool switch3high = digitalRead(pin_switch3) == HIGH;
  bool switch4high = digitalRead(pin_switch4) == HIGH;
  bool switch1low = digitalRead(pin_switch1) == LOW;
  bool switch2low = digitalRead(pin_switch2) == LOW;
  bool switch3low = digitalRead(pin_switch3) == LOW;
  bool switch4low = digitalRead(pin_switch4) == LOW;


 // 0000, si todos los interruptores estan en LOW 
  if (switch1low && switch2low && switch3low && switch4low) {
      ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
      digitalWrite(pin_led1, LOW);
      digitalWrite(pin_led2, LOW);
      digitalWrite(pin_led3, LOW);
      digitalWrite(pin_led4, LOW);
      digitalWrite(pin_led5, LOW);
      printStatus();
    
    }
 ///////////////////////////////////////////////////////////////////////////////////
 //0001, El led 4 enciende cada 1.5 segundos
 if (switch1low && switch2low && switch3low&& switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 1500 && !ledStates[3]) {
      ledStates[0] = false;
      ledStates[1] = false;
      ledStates[2] = false;
      ledStates[3] = true;
      ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 1500 && ledStates[3]) {
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
////////////////////////////////////////////////////////////////////////////////////////
//0010, Los leds 1, 3 y 5 encienden cada 0.5 segundos y después los  2 y 4
if (switch1low && switch2low && switch3high && switch4low) {
    
  if ((tiempo_actual - tiempo_anterior) >= 500 && !ledStates[0] && !ledStates[2] && !ledStates[4]) {
    // Encender todos los LEDs
      ledStates[0] = true;
      ledStates[1] = false;
      ledStates[2] = true;
      ledStates[3] = false;
      ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 500 && ledStates[0] && ledStates[2] && ledStates[4]) {
    // Apagar todos los LEDs
      ledStates[0] = false;
      ledStates[1] = true;
      ledStates[2] = false;
      ledStates[3] = true;
      ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
//////////////////////////////////////////////////////////////////////////////////////
//0011, Los leds 2 y 4 encienden cada 2 segundos
if (switch1low && switch2low && switch3high && switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 2000 && !ledStates[1] && !ledStates[3]) {
    // Encender todos los LEDs
      ledStates[0] = false;
      ledStates[1] = true;
      ledStates[2] = false;
      ledStates[3] = true;
      ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 2000 && ledStates[1] && ledStates[3]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
/////////////////////////////////////////////////////////////////////////////////////
//0100, Todos los leds parpadean cada 3 segundos
if (switch1low && switch2high && switch3low && switch4low) {
    
  if ((tiempo_actual - tiempo_anterior) >= 3000 && !ledStates[0]) {
    // Encender todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 3000 && ledStates[0]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
/////////////////////////////////////////////////////////////////////////////////////
//0101, Primero se encienden 2 segundos los leds 1, 3 y 5 y después los 2 y 4
if (switch1low && switch2high && switch3low && switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 2000 && !ledStates[0] && !ledStates[2] && !ledStates[4]) {
    // Encender todos los LEDs
      ledStates[0] = true;
      ledStates[1] = false;
      ledStates[2] = true;
      ledStates[3] = false;
      ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 2000 && ledStates[0] && ledStates[2] && ledStates[4]) {
    // Apagar todos los LEDs
      ledStates[0] = false;
      ledStates[1] = true;
      ledStates[2] = false;
      ledStates[3] = true;
      ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
/////////////////////////////////////////////////////////////////////////////////////
//0110, Los leds 2 y 4 permanecen encendidos mientras los leds 1, 3 y 5 parpadean cada segundo 
if (switch1low && switch2high && switch3high && switch4low) {
    
  if ((tiempo_actual - tiempo_anterior) >= 1000 && !ledStates[0]) {
    // Encender todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 1000 && ledStates[0] && ledStates[2] && ledStates[4]) {
    // Apagar todos los LEDs
      ledStates[0] = false;
      ledStates[1] = true;
      ledStates[2] = false;
      ledStates[3] = true;
      ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
/////////////////////////////////////////////////////////////////////////////////////
//0111, Todos los leds parpadean cada 2.5 segundos
if (switch1low && switch2high && switch3high && switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 2500 && !ledStates[0]) {
    // Encender todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 2500 && ledStates[0]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
 /////////////////////////////////////////////////////////////////////////////////////
 // 1000, Los leds 1, 3 y 5 permanecen apagados mientras los leds 2 y 4 parpadean cada 0.5 segundos 
  if (switch1high && switch2low && switch3low && switch4low) {
    
    if ((tiempo_actual - tiempo_anterior) >= 500 && !ledStates[1] && !ledStates[3]) {
      // Encender todos los LEDs
      ledStates[0] = false;
      ledStates[1] = true;
      ledStates[2] = false;
      ledStates[3] = true;
      ledStates[4] = false;
      digitalWrite(pin_led1, LOW);
      digitalWrite(pin_led2, HIGH);
      digitalWrite(pin_led3, LOW);
      digitalWrite(pin_led4, HIGH);
      digitalWrite(pin_led5, LOW);
      tiempo_anterior = tiempo_actual;
      printStatus();
    }

    else if ((tiempo_actual - tiempo_anterior) >= 500 && ledStates[1] && ledStates[3]) {
      // Apagar todos los LEDs
      ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
      digitalWrite(pin_led1, LOW);
      digitalWrite(pin_led2, LOW);
      digitalWrite(pin_led3, LOW);
      digitalWrite(pin_led4, LOW);
      digitalWrite(pin_led5, LOW);
      tiempo_anterior = tiempo_actual; 
      printStatus();
    }
  }
  
//////////////////////////////////////////////////////////////////////////////////
// 1001, Los leds 1, 3 y 5 permanecen encendidos mientras los leds 2 y 4 parpadean cada segundo
if (switch1high && switch2low && switch3low&& switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 1000 && !ledStates[0]) {
    // Encender todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 1000 && ledStates[1] && ledStates[3]) {
    // Apagar todos los LEDs
    ledStates[0] = true;
    ledStates[1] = false;
    ledStates[2] = true;
    ledStates[3] = false;
    ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////
// 1010, todos los leds cada 0.3 segundos
if (switch1high && switch2low && switch3high && switch4low) {
    
  if ((tiempo_actual - tiempo_anterior) >= 300 && !ledStates[0]) {
    // Encender todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 300 && ledStates[0]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
///////////////////////////////////////////////////////////////////////////////////////
//1011,Los leds 2 y 4 permanecen apagados mientras los leds 1, 3 y 5 parpadean 0.5 segundos
if (switch1high && switch2low && switch3high && switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 500 && !ledStates[0] && !ledStates[2] && !ledStates[4]) {
    // Encender todos los LEDs
    ledStates[0] = true;
    ledStates[1] = false;
    ledStates[2] = true;
    ledStates[3] = false;
    ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 500 && ledStates[0]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
/////////////////////////////////////////////////////////////////////////////////////////
// 1100, Parpadean todos los leds cada 0.5 segundos
if (switch1high && switch2high && switch3low && switch4low) {
    
  if ((tiempo_actual - tiempo_anterior) >= 500 && !ledStates[0]) {
    // Encender todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 500 && ledStates[0]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual;
    printStatus(); 
  }
}
///////////////////////////////////////////////////////////////////////////////////////////
// 1101, Primero se encienden 1 segundos los leds 1, 2 y 3 y después los 4 y 5
if (switch1high && switch2high && switch3low && switch4high) {
    
  if ((tiempo_actual - tiempo_anterior) >= 1000 && !ledStates[0] && !ledStates[1] && !ledStates[2]) {
    // Encender todos los LEDs
    ledStates[0] = true;
    ledStates[1] = true;
    ledStates[2] = true;
    ledStates[3] = false;
    ledStates[4] = false;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 1000 && ledStates[0] && ledStates[1] && ledStates[2]) {
    // Apagar todos los LEDs
    ledStates[0] = false;
    ledStates[1] = false;
    ledStates[2] = false;
    ledStates[3] = true;
    ledStates[4] = true;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
////////////////////////////////////////////////////////////////////////////////////////
// 1110, Parpadean los leds 1 y 5 cada 1 segundo
if (switch1high && switch2high && switch3high && switch4low) {
    
  if ((tiempo_actual - tiempo_anterior) >= 1000 && !ledStates[0] && !ledStates[4]) {
    // Encender todos los LEDs
    ledStates[0] = true;
    ledStates[1] = false;
    ledStates[2] = false;
    ledStates[3] = false;
    ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, HIGH);
    tiempo_anterior = tiempo_actual;
    printStatus();
  }

  else if ((tiempo_actual - tiempo_anterior) >= 1000 && ledStates[0]) {
    // Apagar todos los LEDs
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = false;
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    digitalWrite(pin_led5, LOW);
    tiempo_anterior = tiempo_actual; 
    printStatus();
  }
}
////////////////////////////////////////////////////////////////////////////////////////
  //1111, todos los leds encendidos
  if (switch1high && switch2high && switch3high && switch4high) {
   
    ledStates[0] = ledStates[1] = ledStates[2] = ledStates[3] = ledStates[4] = true;
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    digitalWrite(pin_led5, HIGH);
    printStatus();
  }
  ////////////////////////////////////////////////////////////////////////////////////////
 
}

// Función para imprimir el estado de los LEDs
void printStatus() {
  Serial.print("LED1: ");
  Serial.println(ledStates[0] ? "ON" : "OFF");
  Serial.print("LED2: ");
  Serial.println(ledStates[1] ? "ON" : "OFF");
  Serial.print("LED3: ");
  Serial.println(ledStates[2] ? "ON" : "OFF");
  Serial.print("LED4: ");
  Serial.println(ledStates[3] ? "ON" : "OFF");
  Serial.print("LED5: ");
  Serial.println(ledStates[4] ? "ON" : "OFF");
}