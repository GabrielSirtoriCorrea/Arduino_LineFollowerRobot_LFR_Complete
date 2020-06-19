//Using #define to separate system variables, and port numbers

#define speedMotorA 11 //speed motor a
#define motorAPositive 2 //motor a = +
#define motorANegative 3 //motor a = -
#define motorBNegative 4 //motor b = -
#define motorBPositive 5 //motor b = +
#define speedMotorB 10  //speed motor b

#define rightSensor A0 //sensor R
#define centralSensor A1 //sensor S
#define leftSensor A2 //sensor L

void setup() 
{
pinMode(motorAPositive, OUTPUT); 
pinMode(motorANegative, OUTPUT);
pinMode(motorBPositive, OUTPUT);
pinMode(motorBNegative, OUTPUT);
pinMode(speedMotorA, OUTPUT);
pinMode(speedMotorB, OUTPUT);

pinMode(leftSensor, INPUT);
pinMode(centralSensor, INPUT);
pinMode(rightSensor, INPUT);

analogWrite(speedMotorA, 150); 
analogWrite(speedMotorB, 150); 
delay(200);
}
void loop()
{  
if ((digitalRead(leftSensor) == 0)&&(digitalRead(centralSensor) == 1)&&(digitalRead(rightSensor) == 0)){
  forword();
 }

else if ((digitalRead(leftSensor) == 1)&&(digitalRead(centralSensor) == 1)&&(digitalRead(rightSensor) == 0)){
  turnLeft();
 }
  
else if ((digitalRead(leftSensor) == 1)&&(digitalRead(centralSensor) ==0)&&(digitalRead(rightSensor) == 0)) {
  turnLeft();
 }

else if ((digitalRead(leftSensor) == 0)&&(digitalRead(centralSensor) == 1)&&(digitalRead(rightSensor) == 1)){
  turnRight();
 }
  
else if ((digitalRead(leftSensor) == 0)&&(digitalRead(centralSensor) == 0)&&(digitalRead(rightSensor) == 1)){
  turnRight();
 }

else if((digitalRead(leftSensor) == 1)&&(digitalRead(centralSensor) == 1)&&(digitalRead(rightSensor) == 1)){
  Stop();
  }
}

void forword(){
digitalWrite(motorAPositive, LOW);
digitalWrite(motorANegative, HIGH);
digitalWrite(motorBNegative, HIGH);
digitalWrite(motorBPositive, LOW);  
}


void turnRight(){
digitalWrite(motorAPositive, LOW);
digitalWrite(motorBNegative, LOW);
digitalWrite(motorBNegative, HIGH);
digitalWrite(motorBPositive, LOW);  
}

void turnLeft(){
digitalWrite(motorAPositive, LOW);
digitalWrite(motorANegative, HIGH);
digitalWrite(motorBNegative, LOW);
digitalWrite(motorBPositive, LOW);
}

void Stop(){
digitalWrite(motorAPositive, LOW);
digitalWrite(motorANegative, LOW);
digitalWrite(motorBNegative, LOW);
digitalWrite(motorBPositive, LOW);
}
