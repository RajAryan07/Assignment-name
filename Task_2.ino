int ontime;
int offtime;
float period;
float frequency;

void setup()
{
    pinMode(2,INPUT);            //pin 8 as signal input
    Serial.begin(9600);
}

void loop()
{
    noInterrupts();
    ontime = pulseIn(2,HIGH);
    offtime = pulseIn(2,LOW);
    interrupts();
    period = ontime+offtime;
    frequency = 1000000.0/period;
    delay(2000);                //Delete it.
    Serial.println(frequency);
    
}
