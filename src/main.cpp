#include <Arduino.h>

int pins[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
};
int steps = 0;
unsigned long start_time = 0;

// steps per revolution: 2038
// 1 rev = 12 hours = 43200 seconds
// 43200/2038 = 21.197252208 seconds per step
// 21.197252208 seconds ~= 21197252 microseconds
unsigned long interval = 21197252;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(DD2, OUTPUT);
  pinMode(DD3, OUTPUT);
  pinMode(DD4, OUTPUT);
  pinMode(DD5, OUTPUT);
  start_time = micros();
}

void step()
{
  digitalWrite(DD2, pins[steps % 4][0]);
  digitalWrite(DD3, pins[steps % 4][1]);
  digitalWrite(DD4, pins[steps % 4][2]);
  digitalWrite(DD5, pins[steps % 4][3]);

  if (steps == 3)
  {
    steps = 0;
  }
  else
  {
    steps++;
  }
}

void loop()
{
  if (micros() - start_time >= interval)
  {
    step();
    start_time = micros();
  }
}