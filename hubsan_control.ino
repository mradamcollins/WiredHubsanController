int FB_PIN_IN = A2;
int LR_PIN_IN = A3;
int YAW_PIN_IN = A0;
int THRUST_PIN_IN = A1;

int FB_PIN_OUT = 8;
int LR_PIN_OUT = 9;
int YAW_PIN_OUT = 10;
int THRUST_PIN_OUT = 11;

void setup() {
 pinMode(FB_PIN_IN, INPUT); 
 pinMode(LR_PIN_IN, INPUT);
 pinMode(YAW_PIN_IN, INPUT);
 pinMode(THRUST_PIN_IN, INPUT);
 
 pinMode(FB_PIN_OUT, OUTPUT); 
 pinMode(LR_PIN_OUT, OUTPUT);
 pinMode(YAW_PIN_OUT, OUTPUT);
 pinMode(THRUST_PIN_OUT, OUTPUT);
 
 analogReference(INTERNAL2V56);
 Serial.begin(115200);
}
float MAX_ANALOG_V = 3.1;
int ANALOG_RANGE = MAX_ANALOG_V / 5.0 * 255;
void loop() {
 int front_back =  analogRead(FB_PIN_IN) / 1024.0 * ANALOG_RANGE;
 int left_right =  analogRead(LR_PIN_IN) / 1024.0 * ANALOG_RANGE;
 int yaw =  analogRead(YAW_PIN_IN) / 1024.0 * ANALOG_RANGE;
 int thrust =  analogRead(THRUST_PIN_IN) / 1024.0 * ANALOG_RANGE;
 
 Serial.print("Front_Back: "); Serial.print(front_back); 
 Serial.print(" Left_Right: "); Serial.print(left_right); 
 Serial.print(" Yaw: "); Serial.print(yaw); 
 Serial.print(" Thrust: "); Serial.println(thrust); 
 
 analogWrite(FB_PIN_OUT, front_back );
 analogWrite(LR_PIN_OUT, left_right );
 analogWrite(YAW_PIN_OUT, yaw ); 
 analogWrite(THRUST_PIN_OUT, thrust );
 delay(1000);
}
