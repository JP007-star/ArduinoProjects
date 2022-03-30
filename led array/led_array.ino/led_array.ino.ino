int rows [] = {2, 3, 4, 5, 6, 7, 8, 9};
int cols [] = {10, 11, 12, 13, A0, A1, A2, A3};
boolean cells[8][8] = {
  {1, 1, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1  0, 0, 0, 0, 0, 0, 0, 0},
};

void setup()
{
  for (int x = 0; x < 8; x++) {
    pinMode(rows[x], OUTPUT);
    pinMode(cols[x], OUTPUT);
  }

}


void loop()
{

  display();

}


void off () {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      cells [y][x] = 0;
    }
  }
}
int py = 0;
void display() {
  for (int px = 0; px < 8; px++) {
    digitalWrite(rows[px], LOW);
  }
  digitalWrite(cols[py], HIGH);
  py++;
  if (py == 8) {
    py = 0;
  }
  digitalWrite(cols[py], LOW);
  for (int px = 0; px < 8; px++) {
    if (cells[py][px] == 1) {
      digitalWrite(rows[px], HIGH);
    }
    else {
      digitalWrite (rows[px], LOW);
    }
  }
}
