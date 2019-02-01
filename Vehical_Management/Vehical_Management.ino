
// Define pins for ultrasonic and LED
int const trigPin = 10;
int const echoPin = 9;
int const led = 2;

void setup()
{
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
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance <= 50 && distance >= 0) {
      // LED on
      digitalWrite(led, HIGH);
    } else {
      // LED off
      digitalWrite(led, LOW);
    }
    delay(60);
}
