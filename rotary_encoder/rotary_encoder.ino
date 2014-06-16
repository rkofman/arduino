/*
(Copy and paste)

Rotary encoder decoding using two interrupt lines.
Most Arduino boards have two external interrupts,
inputNumbers 0 (on digital pin 2) and 1 (on digital pin 3).

Program sketch is for SparkFun Rotary Encoder sku: COM-09117
Connect the middle pin of the three to ground.
The outside two pins of the three are connected to
digital pins 2 and 3
*/


volatile int inputNumber = 0;                // TestinputNumber, print it when it changes value,
                                        // used in loop and both interrupt routines
int oldinputNumber = inputNumber;

volatile boolean halfleft = false;      // Used in both interrupt routines
volatile boolean halfright = false;


void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);                // Turn on internal pullup resistor
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);                // Turn on internal pullup resistor
  attachInterrupt(0, isr_2, FALLING);   // Call isr_2 when digital pin 2 goes LOW
  attachInterrupt(1, isr_3, FALLING);   // Call isr_3 when digital pin 3 goes LOW
}

void loop(){
  if(inputNumber != oldinputNumber){              // Change in value ?
    Serial.println(inputNumber);             // Yes, print it (or whatever)
    oldinputNumber = inputNumber;
  }
}

void isr_2(){                                              // Pin2 went LOW
  delay(1);                                                // Debounce time
  if(digitalRead(2) == LOW){                               // Pin2 still LOW ?
    if(digitalRead(3) == HIGH && halfright == false){      // -->
      halfright = true;                                    // One half click clockwise
    }  
    if(digitalRead(3) == LOW && halfleft == true){         // <--
      halfleft = false;                                    // One whole click counter-
      inputNumber--;                                            // clockwise
    }
  }
}
void isr_3(){                                             // Pin3 went LOW
  delay(1);                                               // Debounce time
  if(digitalRead(3) == LOW){                              // Pin3 still LOW ?
    if(digitalRead(2) == HIGH && halfleft == false){      // <--
      halfleft = true;                                    // One half  click counter-
    }                                                     // clockwise
    if(digitalRead(2) == LOW && halfright == true){       // -->
      halfright = false;                                  // One whole click clockwise
      inputNumber++;
    }
  }
}
