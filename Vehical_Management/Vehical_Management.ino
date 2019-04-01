
// Define pins for ultrasonic and LED
int const trigPin = 4;  //exit
int const echoPin = 5;

int const trigPin2 = 11;  // entery
int const echoPin2 = 10;

int const trigPin3 = 13;  //entery
int const echoPin3 = 12;

int const trigPin4 = 2;  //exit
int const echoPin4 = 3;

int const led = 6;
int const led2 = 7;
int const led3 = 8;

int const led5 = 0;

int const counter_led = 9;
long count=0;
long count2=0;
long count3=0;
long count4=0;
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

  
  pinMode(trigPin4, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin4, INPUT); // echo pin should be input to get pulse width
  
  pinMode(led, OUTPUT); // led pin is output to control LED lights
  pinMode(led2, OUTPUT); // led pin is output to control LED lights
  pinMode(led3, OUTPUT); // led pin is output to control LED lights
//  pinMode(led4, OUTPUT); // led pin is output to control LED lights
  pinMode(led5, OUTPUT); // led pin is output to control LED lights
  
  pinMode(counter_led, OUTPUT);
}

void loop()
{
  
  if(tk>10)
    digitalWrite(counter_led, HIGH);
  else
    digitalWrite(counter_led, LOW);

  entry1();

  entry2();

  exit1();

//  exit2();

  
}

void entry1()
{

 
  int duration2, distance2;

  
  digitalWrite(trigPin2, HIGH); 
  delay(1);
  digitalWrite(trigPin2, LOW);

  
  duration2 = pulseIn(echoPin2, HIGH);

 
  distance2 = (duration2/2) / 74;
   
   if (distance2 < 5) {
      
      count2++;
      digitalWrite(led2, HIGH);
  
    } else {

       if(count2!=0)
      { 

        //increment tk value and display the count
        
        tk++;
        Serial.print("\n+++++++++++++++++++");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("+++++++++++++++++++++");
        
      }
        
      count2=0;
      
      // LED off
      digitalWrite(led2, LOW);
    }
    delay(60);
    
  

  }

void entry2()
{

 
  int duration3, distance3;

  
  digitalWrite(trigPin3, HIGH); 
  delay(1);
  digitalWrite(trigPin3, LOW);
  
  duration3 = pulseIn(echoPin3, HIGH);

 
  distance3 = (duration3/2) / 74;
   
   if (distance3 < 5) {
      
      count3++;
      digitalWrite(led, HIGH);
  
    } else {

       if(count3!=0)
      { 

        //increment tk value and display the count
        
        tk++;
        Serial.print("\n+++++++++++++++++++");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("+++++++++++++++++++++");
        
      }
        
      count3=0;
      
      // LED off
      digitalWrite(led, LOW);
    }
    delay(60);
    
  

  }


  void exit1()
{

 
  int duration, distance;

  
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);

 
  distance = (duration/2) / 74;
   
   if (distance < 5) {
      
      count++;
      digitalWrite(led3, HIGH);
  
    } else {

       if(count!=0)
      { 

        //increment tk value and display the count
        
        tk--;
        Serial.print("\n------------------");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("--------------------");
        
      }
        
      count=0;
      
      // LED off
      digitalWrite(led3, LOW);
    }
    delay(60);
    
  

  }
  void exit2()
{

 
  int duration4, distance4;

  
  digitalWrite(trigPin4, HIGH); 
  delay(1);
  digitalWrite(trigPin4, LOW);

  
  duration4 = pulseIn(echoPin3, HIGH);

 
  distance4 = (duration4/2) / 74;
   
   if (distance4 < 5) {
      
      count4++;
//      digitalWrite(led4, HIGH);
  
    } else {

       if(count4!=0)
      { 

        //increment tk value and display the count
        
        tk--;
        Serial.print("\n------------------");
        Serial.print('\n');
        Serial.print(tk);
        Serial.print('\n');
        Serial.print("--------------------");
        
      }
        
      count4=0;
      
      // LED off
//      digitalWrite(led4, LOW);
    }
    delay(60);
    
  

  }
