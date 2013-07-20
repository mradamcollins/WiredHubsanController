int FB_PIN_IN = A0;
int LR_PIN_IN = A1;
int YAW_PIN_IN = A2;
int THRUST_PIN_IN = A3;

int FB_PIN_OUT = A8;
int LR_PIN_OUT = A9;
int YAW_PIN_OUT = A10;
int THRUST_PIN_OUT = A11;

void setup() {
 pinMode(FB_PIN_IN, INPUT); 
 pinMode(LR_PIN_IN, INPUT);
 pinMode(YAW_PIN_IN, INPUT);
 pinMode(THRUST_PIN_IN, INPUT);
 
 pinMode(FB_PIN_OUT, OUTPUT); 
 pinMode(LR_PIN_OUT, OUTPUT);
 pinMode(YAW_PIN_OUT, OUTPUT);
 pinMode(THRUST_PIN_OUT, OUTPUT);
 
 Serial.begin(115200);
}

void loop() {
 int front_back =  analogRead(FB_PIN);
 int left_light =  analogRead(LR_PIN);
 int yaw =  analogRead(YAW_PIN);
 int thrust =  analogRead(THRUST_PIN);
 analogWrite(A8,  );
 analogWrite(A9, analogRead(A1) );
 analogWrite(A10, analogRead(A2) ); 
 analogWrite(A11, analogRead(A3) );
 delay(100);
}
