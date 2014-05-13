boolean DEBUG = false;

// pin outs					// INPUTS
int LR_PIN_IN = A0;			// Left - Right
int FB_PIN_IN = A1;			// Front - Back
int YAW_PIN_IN = A2;		// Yaw
int THRUST_PIN_IN = A3;		// Thrust

							// OUTPUTS
int LR_PIN_OUT = 8;			// Left - Right
int FB_PIN_OUT = 9;			// Front - Back
int YAW_PIN_OUT = 10;		// Yaw
int THRUST_PIN_OUT = 11;	// Thrust			

// Calibration parameters			
int LR_min = 0; // value to be subtracted from input to get 0
int LR_max = 0; // value to be added to the input to get 255

int FB_min = 0; // value to be subtracted from input to get 0
int FB_max = 0; // value to be added to the input to get 255

int YAW_min = 0; // value to be subtracted from input to get 0
int YAW_max = 0; // value to be added to the input to get 255

int THRUST_min = 0; // value to be subtracted from the input to get 0
int THRUST_max = 0; // value to be added to the input to get 255

// values to change analogue range output to cap the max output voltage
float MAX_ANALOG_V = 5.0;	// can be set to 3.3 for pro-mini versions that have 3.3v logic
int ANALOG_RANGE = MAX_ANALOG_V / 5.0 * 255;

long last_print_time = 0;

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
	last_print_time = millis();
}

// Scale the input to from 1024 to 255 output, where 255 represents 0-ANALOG_MAX_VOLTAGE
int scaled(int input)
{
	return input / 1024.0 * ANALOG_RANGE; 
}

void loop() {
	int front_back =  scaled(analogRead(FB_PIN_IN));
	int left_right =  scaled(analogRead(LR_PIN_IN));
	int yaw =  scaled(analogRead(YAW_PIN_IN));
	int thrust =  scaled(analogRead(THRUST_PIN_IN));
	
	analogWrite(FB_PIN_OUT, front_back );
	analogWrite(LR_PIN_OUT, left_right );
	analogWrite(YAW_PIN_OUT, yaw ); 
	analogWrite(THRUST_PIN_OUT, thrust );
	delay(10);
	
	if ( DEBUG && ((millis() - last_print_time) > 1000) ) 
	{
		Serial.print("Front_Back: "); Serial.print(front_back); 
		Serial.print(" Left_Right: "); Serial.print(left_right); 
		Serial.print(" Yaw: "); Serial.print(yaw); 
		Serial.print(" Thrust: "); Serial.println(thrust);   		
	}
}
