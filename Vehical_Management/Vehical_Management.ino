
// Define pins for ultrasonic and LED
int const trigPin = 10;
int const echoPin = 9;
int const led = 2;
int const counter_led = 4;
long count=0;
long tk=0;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  pinMode(led, OUTPUT); // led pin is output to control LED lights
  
}

void loop()
{
  
  // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration, distance;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);

  if(tk>10)
    digitalWrite(counter_led, HIGH);
  
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 74;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance < 5) {
      // LED on
      count++;
      
      digitalWrite(led, HIGH);
    } else {

      if(count!=0)
      { 
        tk++;
        Serial.print("\n---------------------");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("---------------------");
        
      }
        

      
      count=0;
      
      // LED off
      digitalWrite(led, LOW);
    }
    delay(60);
    
}
