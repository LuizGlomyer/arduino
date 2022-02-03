#include "functions.h"

Simon simon(3);

void setup()
{
  randomSeed(analogRead(UNCONNECTED_PIN));
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);  // led 1
  pinMode(RED, OUTPUT);    // led 2
  pinMode(YELLOW, OUTPUT); // led 3
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  simon.start();
}

void loop()
{
  while (simon.get_position() <= simon.get_size())
  {
    simon.leds[simon.get_position()] = random(GREEN, YELLOW + 1); // selects a random pin from 2 to 4
    simon.light_up(simon.leds[simon.get_position()]);             // shows the new led in the sequence
    simon.memory_game();                                          // the player iterates the sequence until its end

    simon.increment(1);
  }

  simon.game_won();
}
