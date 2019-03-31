
// Define pins for ultrasonic and LED
int const trigPin = 9;
int const echoPin = 8;

int const trigPin2 = 11;
int const echoPin2 = 10;

int const trigPin3 = 13;
int const echoPin3 = 12;

int const led = 2;
int const led2 = 5;
int const led3 = 6;
int const counter_led = 4;
long count=0;
long count2=0;
long count3=0;
long tk=0;

void setup()
{
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  
  pinMode(trigPin2, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin2, INPUT); // echo pin should be input to get pulse width
    
  pinMode(trigPin3, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin3, INPUT); // echo pin should be input to get pulse width
  
  pinMode(led, OUTPUT); // led pin is output to control LED lights
  pinMode(led2, OUTPUT); // led pin is output to control LED lights
  pinMode(led3, OUTPUT); // led pin is output to control LED lights
  pinMode(counter_led, OUTPUT);
}

void loop()
{
  
  if(tk>10)
    digitalWrite(counter_led, HIGH);
  else
    digitalWrite(counter_led, LOW);

  entry();

  exit1();

  exit2();
  
}

void entry()
{

 
  int duration, distance;

  
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);

 
  distance = (duration/2) / 74;
   
   if (distance < 5) {
      
      count++;
      digitalWrite(led, HIGH);
  
    } else {

       if(count!=0)
      { 

        //increment tk value and display the count
        
        tk++;
        Serial.print("\n+++++++++++++++++++");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("+++++++++++++++++++++");
        
      }
        
      count=0;
      
      // LED off
      digitalWrite(led, LOW);
    }
    delay(60);
    
  

  }

  void exit1()
{

 
  int duration, distance;

  
  digitalWrite(trigPin2, HIGH); 
  delay(1);
  digitalWrite(trigPin2, LOW);

  
  duration = pulseIn(echoPin2, HIGH);

 
  distance = (duration/2) / 74;
   
   if (distance < 5) {
      
      count2++;
      digitalWrite(led2, HIGH);
  
    } else {

       if(count2!=0)
      { 

        //increment tk value and display the count
        
        tk--;
        Serial.print("\n------------------");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("--------------------");
        
      }
        
      count2=0;
      
      // LED off
      digitalWrite(led2, LOW);
    }
    delay(60);
    
  

  }
  void exit2()
{

 
  int duration, distance;

  
  digitalWrite(trigPin3, HIGH); 
  delay(1);
  digitalWrite(trigPin3, LOW);

  
  duration = pulseIn(echoPin3, HIGH);

 
  distance = (duration/2) / 74;
   
   if (distance < 5) {
      
      count3++;
      digitalWrite(led3, HIGH);
  
    } else {

       if(count3!=0)
      { 

        //increment tk value and display the count
        
        tk--;
        Serial.print("\n------------------");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("--------------------");
        
      }
        
      count3=0;
      
      // LED off
      digitalWrite(led3, LOW);
    }
    delay(60);
    
  

  }