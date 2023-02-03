// dichiarazione delle variabili che contengono i dati



/* Spiegazione: in questo caso si può anche evitare di leggere il valore digitale.
 * Il sensore legge due tipi di valore, quello analogico che legge un range di valori
 * e quello digitale, che resitituisce solo LOW and HIGH
*/ 

int sensorValue;
int digitalValue;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  sensorValue = analogRead(0);
  digitalValue = digitalRead(2);
  Serial.println(sensorValue, DEC);
  Serial.println(digitalValue, DEC);

  //inserire in millisecondi quanto si vuole aspetttare per leggere il secondo valore
  delay(1000);
}
