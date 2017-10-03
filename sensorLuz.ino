const int pinoSensor = A0;  // Analog input pin that the potentiometer is attached to

const int vermelho2 = 12;
const int vermelho1 = 11;
const int amarelo2 = 10;
const int amarelo1 = 9;
const int verde2 = 8;
const int verde1 = 7;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  pinMode(vermelho2, OUTPUT);
  pinMode(vermelho1, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(verde1, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(pinoSensor);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 40, 650, 0, 6);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  digitalWrite(vermelho2, LOW);
  digitalWrite(vermelho1, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(amarelo1, LOW);
  digitalWrite(verde2, LOW);
  digitalWrite(verde1, LOW);

  switch (outputValue) {
    case 6:
      digitalWrite(vermelho2, HIGH);
    case 5:
      digitalWrite(vermelho1, HIGH);
    case 4:
      digitalWrite(amarelo2, HIGH);
    case 3:
      digitalWrite(amarelo1, HIGH);
    case 2:
      digitalWrite(verde2, HIGH);
    case 1:
      digitalWrite(verde1, HIGH);
    case 0:
      break;
  }

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(500);
}
