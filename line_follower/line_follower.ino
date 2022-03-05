int motorL_F = 10;
int motorL_B = 11;

int motorR_F = 6;
int motorR_B = 5;

int motorSpeed = 120;

int irR = 2;
int irL = 4;
int ir3 = 8;
int button = 3;

int counter = 0;
int maximum_1st_count = 3;
int maximum_count = 6; // 2 rounds
bool isBlack = false;
bool firstStage = true;
bool firstOn = true;

void setup() {
  pinMode(motorR_F, OUTPUT);
  pinMode(motorR_B, OUTPUT);
  pinMode(motorL_F, OUTPUT);
  pinMode(motorL_B, OUTPUT);

  pinMode(irR, INPUT);
  pinMode(irL, INPUT);
  pinMode(ir3, INPUT);
  pinMode(button, INPUT);
  /*
    for(;;)
    {
    forward();
    delay(2000);

    backward();
    delay(2000);

    right();
    delay(2000);

    left();
    delay(2000);
    }
  */
}

void loop() {
  if(firstOn == true)
  {
    for (;;)
    {
      Stop();
      if (digitalRead(button))
      {
        counter = 0;
        isBlack = false;
        firstStage = true;
        firstOn = false;
        Stop();
        delay(2000);
        break;
      }
    }
  }

  if (digitalRead(button))
  {
    counter = 0;
    isBlack = false;
    firstStage = true;
    firstOn = true;
    Stop();
    delay(2000);
  }


  if (firstStage)
  {
    motorSpeed = 80;
  }
  else
  {
    motorSpeed = 100;
  }

  if (both_black())
  {
    if (!isBlack)
    {
      counter++;
      isBlack = true;
    }

    if (counter == 1)
    {
      forward();
      delay(200);
    }
    else if (counter == 2)
    {
      sharpRight();
      delay(400); // 1st conjuction
    }
    else if (counter == 3)
    {
      sharpRight();
      delay(300); // 2nd conjuction
      firstStage = false;
    }
    else if (counter == 4) // 1st round
    {
      left();
      delay(100);
      forward();
      delay(200);
    }
    else if (counter == 5) // 2nd round
    {
      left();
      delay(100);
      forward();
      delay(200);
    }
    else if (counter == maximum_count)
    {
      counter++;
      sharpRight();
     right();
     delay(300); // final conjuction
    }
    else
    {
      for (;;)
      {
        Stop();
        if (digitalRead(button))
        {
          counter = 0;
          isBlack = false;
          firstStage = true;
          Stop();
          delay(2000);
          break;
        }
      }
    }
  }
  else if (!digitalRead(ir3))
  {
    Stop();
  }
  else if (right_black())
  {
    isBlack = false;
    sharpRight();
  }
  else if (left_black())
  {
    isBlack = false;
    sharpLeft();
  }
  else if (both_white())
  {
    isBlack = false;
    forward();
  }
}

void forward()
{
  // right forward
  analogWrite(motorR_F, motorSpeed);
  analogWrite(motorR_B, 0);

  // left forward
  analogWrite(motorL_F, motorSpeed);
  analogWrite(motorL_B, 0);
}

void backward()
{
  // right backward
  analogWrite(motorR_F, 0);
  analogWrite(motorR_B, motorSpeed);

  // left backward
  analogWrite(motorL_F, 0);
  analogWrite(motorL_B, motorSpeed);
}

void Stop()
{
  // right stop
  analogWrite(motorR_F, 0);
  analogWrite(motorR_B, 0);

  // left stop
  analogWrite(motorL_F, 0);
  analogWrite(motorL_B, 0);
}

void right()
{
  // right stop
  analogWrite(motorR_F, 0);
  analogWrite(motorR_B, 0);

  // left forward
  analogWrite(motorL_F, motorSpeed);
  analogWrite(motorL_B, 0);
}

void sharpRight()
{
  // right backward
  analogWrite(motorR_F, 0);
  analogWrite(motorR_B, motorSpeed);

  // left forward
  analogWrite(motorL_F, motorSpeed);
  analogWrite(motorL_B, 0);
}

void left()
{
  // right forward
  analogWrite(motorR_F, motorSpeed);
  analogWrite(motorR_B, 0);

  // left stop
  analogWrite(motorL_F, 0);
  analogWrite(motorL_B, 0);
}

void sharpLeft()
{
  // right forward
  analogWrite(motorR_F, motorSpeed);
  analogWrite(motorR_B, 0);

  // left backward
  analogWrite(motorL_F, 0);
  analogWrite(motorL_B, motorSpeed);
}

bool both_black()
{
  if (digitalRead(irL) && digitalRead(irR))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool right_black()
{
  if (!digitalRead(irL) && digitalRead(irR))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool left_black()
{
  if (digitalRead(irL) && !digitalRead(irR))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool both_white()
{
  if (!digitalRead(irL) && !digitalRead(irR))
  {
    return true;
  }
  else
  {
    return false;
  }
}
