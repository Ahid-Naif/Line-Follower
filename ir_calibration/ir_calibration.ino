int irR = 2;
int irL = 4;
int ir3 = 8;
int button = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(irR, INPUT);
  pinMode(irL, INPUT);
  pinMode(ir3, INPUT);
  pinMode(button, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("left: ");
  Serial.print(digitalRead(irL));

  Serial.print("    right: ");
  Serial.print(digitalRead(irR));

  Serial.print("    ir3: ");
  Serial.print(digitalRead(ir3));

  Serial.print("    button: ");
  Serial.println(digitalRead(button));
}
