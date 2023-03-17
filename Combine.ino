
#include <B31DGMonitor.h>
#include <Ticker.h>
#include <Arduino.h>

#define FRAME_DURATION_MS 4     // 4ms
//General Frame
unsigned long frameTime = 0;
unsigned long frameCounter = 0;
//-------------------------------------




// task 1
#define RED_LED 10   // check pin
// task 1



// task 2
int ontime_2;
int offtime_2;
float period_2;
float frequency_2;
#define Task2 4
// task 2


// task 3
int ontime_3;
int offtime_3;
float period_3;
float frequency_3;
#define Task3 5
// task 3


// task 4
#define potPin 0
#define ERROR_LED 18
float potval;
float cal_val =0;
float a1 = 0;
float a2 = 0;
float a3 = 0;
float a4 = 0;
float ana_avg;
float half_max;
//task 4

//task 5
int feqmin = 333;
int feqmin1 = 500;
int feqmax = 1000;
int fscale = 0;
int fscale1 = 0;
int a = 0;
int a_1 = 0;
//task 5


//FRAME
//Name mointor and ticker
B31DGCyclicExecutiveMonitor monitor;
Ticker FrameTick;
//FRAME



void setup() {    ////
  
  Serial.begin(9600);

  //task 1
  pinMode(RED_LED, OUTPUT);
  //task 1


  //task 2
  pinMode(Task2,INPUT);         // check pin  
  //task 2

  //task 3
  pinMode(Task3,INPUT);         // check pin
  //task 3


  //task 4
  pinMode(potPin, INPUT);
  pinMode(ERROR_LED, OUTPUT); 
  //task 4 

  FrameTick.attach_ms(4, frame);  //Define ticker size as 4ms for the "Frame" function
  task_1();                        //Run task 1 followed by fixed delay in
  delayMicroseconds(2000);        //order to fix associated with startMonitoring
  monitor.startMonitoring();      //Start monitoring scheme

  

}



void frame() 
{
  unsigned int slot = frameCounter % 50;
  switch (slot){
    case 0 :   task_1();           task_3(); task_4(); task_5();          break;
    case 1 :   task_1(); task_2();                                      break;
    case 2 :   task_1();           task_3();                            break;
    case 3 :   task_1();                                                break;
    case 4 :   task_1();           task_3();                            break;
    case 5 :   task_1();                     task_4();                  break;
    case 6 :   task_1();           task_3();                            break;
    case 7 :   task_1(); task_2();                                      break;
    case 8 :   task_1();           task_3();                            break;
    case 9 :   task_1();                                                break;
    case 10 :  task_1();           task_3(); task_4();                  break;
    case 11 :  task_1(); task_2();                                      break;
    case 12 :  task_1();           task_3();                            break;
    case 13 :  task_1();                                                break;
    case 14 :  task_1();           task_3();                            break;
    case 15 :  task_1();                     task_4();                  break;
    case 16 :  task_1();           task_3();                            break;
    case 17 :  task_1(); task_2();                                      break;
    case 18 :  task_1();           task_3();                            break;
    case 19 :  task_1();                                                break;
    case 20 :  task_1();           task_3(); task_4();                  break;
    case 21 :  task_1(); task_2();                                      break;
    case 22 :  task_1();           task_3();                            break;
    case 23 :  task_1();                                                break;
    case 24 :  task_1();           task_3();                            break;
    case 25 :  task_1();                     task_4();                  break;
    case 26 :  task_1();           task_3();                            break;
    case 27 :  task_1(); task_2();                                      break;
    case 28 :  task_1();           task_3();                            break;
    case 29 :  task_1();                                                break;
    case 30 :  task_1();           task_3(); task_4();                  break;
    case 31 :  task_1(); task_2();                                      break;
    case 32 :  task_1();           task_3();                            break;
    case 33 :  task_1();                                                break;
    case 34 :  task_1();           task_3();                            break;
    case 35 :  task_1();                     task_4();                  break;
    case 36 :  task_1();           task_3();                            break;
    case 37 :  task_1(); task_2();                                      break;
    case 38 :  task_1();           task_3();                            break;
    case 39 :  task_1();                                                break;
    case 40 :  task_1();           task_3(); task_4();                  break;
    case 41 :  task_1(); task_2();                                      break;
    case 42 :  task_1();           task_3();                            break;
    case 43 :  task_1();                                                break;
    case 44 :  task_1();           task_3();                            break;
    case 45 :  task_1();                     task_4();                  break;
    case 46 :  task_1();           task_3();                            break;
    case 47 :  task_1(); task_2();                                      break;
    case 48 :  task_1();           task_3();                            break;
    case 49 :  task_1();                                                break;
  }
  frameCounter = frameCounter + 1;  
}
//-------------------------------------


void loop(void)
{
    ////
}



void task_1(void)
{
  monitor.jobStarted(1);
  digitalWrite(RED_LED, HIGH);
  delayMicroseconds(200);
  digitalWrite(RED_LED, LOW);
  delayMicroseconds(50);
  digitalWrite(RED_LED, HIGH);
  delayMicroseconds(30);
  monitor.jobEnded(1);

}

void task_2(void)
{
    monitor.jobStarted(2);
    noInterrupts();
    ontime_2 = pulseIn(Task2,HIGH);    // check pin
    offtime_2 = pulseIn(Task2,LOW);    // check pin
    interrupts();
    period_2 = ontime_2+offtime_2;
    frequency_2 = 1000000.0/period_2;
    //delay(2000);                         //Delete it.
    
    monitor.jobEnded(2);

}

void task_3(void)
{
    monitor.jobStarted(3);
    noInterrupts();
    ontime_3 = pulseIn(Task3,HIGH);    // check pin
    offtime_3 = pulseIn(Task3,LOW);    // check pin
    interrupts();
    period_3 = ontime_3+offtime_3;
    frequency_3 = 1000000.0/period_3;
    //delay(2000);                         //Delete it.
    
    monitor.jobEnded(3);

}

void task_4(void)
{
  monitor.jobStarted(4);
  potval = analogRead(potPin);       // check pin
  cal_val = (3.3*potval)/4095;
  a1 = a2;
  a2 = a3;
  a3 = a4;
  a4 = cal_val;
  ana_avg = (a1 + a2 + a3 + a4)/4;
  half_max = 3.3/2;
  if (ana_avg > half_max)  
  {
    digitalWrite(ERROR_LED, HIGH);
  }
  else 
  {
    digitalWrite(ERROR_LED, LOW);
  }
  
  monitor.jobEnded(4);
}



void task_5(void)
{ 
  monitor.jobStarted(5);
  fscale = (99*(frequency_2 - feqmin))/(feqmax - feqmin);
  if (fscale <= 0){
    a = 0;
  }

  else {
    a=99;
  }

  fscale1 = (99*(frequency_3-feqmin1))/(feqmax -feqmin1);
  if (fscale1 <= 0){
    a_1 = 0;
  }
  else{
    a_1=99;   
  }

  Serial.print(a);
  Serial.print(',');
  Serial.println(a_1);
  monitor.jobEnded(5);

}


