//Dice Thrower v3
//in this version I want to work out how to interrupt the void loop
//and have it wait until I press a button
// in this version it will show the correct form of the pips on the dice

// give dNum the max number of pips you want on your dice
const int dNum = 6; //as in d8 or d6 or d4 CAN'T BE HIGHER THAN 9!

const int ROW_COUNT = 3;
const int COL_COUNT = 3;
int ledMatrix[ROW_COUNT][COL_COUNT] =
{
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10}
};

/*  show & tell of array addresses
      {[0][0], [0][1], [0][2]},

      {[1][0], [1][1], [1][2]},

      {[2][0], [2][1], [2][2]}
*/


void setup()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      pinMode(ledMatrix[i][j], OUTPUT);
    }
  }
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  Serial.println(); //for random() checking reasons
}


void loop()
{
  int num;
  int mapChange;
  int thouNum = dNum * 1000;
  num = random(thouNum + thouNum * 0.66);
  mapChange = map(num, 1, thouNum + thouNum * 0.66, 1, dNum + 1);

  if (mapChange == 1)
    one();

  if (mapChange == 2)
    two();

  if (mapChange == 3)
    three();

  if (mapChange == 4)
    four();

  if (mapChange == 5)
    five();

  if (mapChange == 6)
    six();

  if (mapChange == 7)
    seven();

  if (mapChange == 8)
    eight();

  if (mapChange == 9)
    nine();

  Serial.print(mapChange);
  Serial.print("\t mapped from: ");
  Serial.println(num);
  delay(1000);
  allOff();
}

void ledOn(int x, int y) //x == rows, y == cols
{
  digitalWrite(ledMatrix[x][y], HIGH);
}

void one()
{
  ledOn(1, 1);
}

void two()
{
  ledOn(2, 0);
  ledOn(0, 2);
}

void three()
{
  ledOn(1, 1);
  ledOn(2, 0);
  ledOn(0, 2);
}

/*void four() //one of two ways to write four()
  {
  digitalWrite(ledMatrix[0][0], HIGH);
  digitalWrite(ledMatrix[2][0], HIGH);
  digitalWrite(ledMatrix[0][2], HIGH);
  digitalWrite(ledMatrix[2][2], HIGH);
  }*/

//different way of writing four()
void four()
{
  for (int row = 0; row < 3; row++)
  {
    if (row == 1) continue;

    ledOn(row, 0);
    //digitalWrite(ledMatrix[row][0], HIGH); //original code
    ledOn(row, 2);
    //digitalWrite(ledMatrix[row][2], HIGH); //original code
  }
}


void five()
{
  ledOn(0, 0);
  ledOn(2, 0);
  ledOn(0, 2);
  ledOn(2, 2);
  ledOn(1, 1);
}

void six()
{
  for (int row = 0; row < 3; row++)
  {
    ledOn(row, 0);
    ledOn(row, 2);
  }
}

void seven()
{
  for (int row = 0; row < 3; row++)
  {
    ledOn(row, 0);
    ledOn(row, 2);
  }
  ledOn(1, 1);
}

void eight()
{
  for (int row = 0; row < 3; row++)
  {
    ledOn(row, 0);
    ledOn(row, 2);
  }
  ledOn(0, 1);
  ledOn(2, 1);
}

/*void eight() //different way of writing eight()
  {
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      if (col == 1 && row == 1) continue;

      digitalWrite(ledMatrix[row][col], HIGH);
    }
  }
  }*/

void nine()
{
  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      ledOn(row, col);
    }
  }
}

void allOff() //All LEDs off for 1 second
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      digitalWrite(ledMatrix[i][j], LOW);
    }
  }
  delay(1000);
}

void allOn() //All LEDs on for 1 second
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      digitalWrite(ledMatrix[i][j], HIGH);
    }
  }
  delay(1000);
}
