struct
{
  float volt;
  float amp;
} response;

int utlimoatt = 0;
volatile boolean zera = false;
volatile boolean haveData = false;

float tensaoEntrada = 0.0; 
float tensaoMedida = 0.0; 
 
float valorR1 = 30000.0; 
float valorR2 = 7500.0; 
int leituraSensor = 0; 

const int pinoSensor = A2; 
float ruido = 0.08; 
 
const int analogIn = A1;
int mVperAmp = 66; 
int RawValue = 0;
int ACSoffset = 2500;
double Voltage = 0;
double Amps = 0;
String ptz;

void setup(){
   pinMode(pinoSensor, INPUT); 
   Serial.begin(9600); 
}
void loop(){
     leituraSensor = analogRead(pinoSensor); 
     tensaoEntrada = (leituraSensor * 5.0) / 1024.0; 
     tensaoMedida = tensaoEntrada / (valorR2/(valorR1+valorR2));   
     Calcula_corrente();     
     ptz = String(tensaoMedida)+ "," + String(Amps);
     Serial.write(ptz.c_str(), ptz.length());  
     delay(5000);
}
void Calcula_corrente(){
  unsigned int x=0;
	float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;
		for (int x = 0; x < 150; x++){ 
		  AcsValue = analogRead(A1);    
		  Samples = Samples + AcsValue; 
		  delay (3);
		}
	AvgAcs=Samples/150.0;
	AcsValueF = (2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.066;
	Amps = AcsValueF;
}
