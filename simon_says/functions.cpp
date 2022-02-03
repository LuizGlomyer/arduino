#include "Arduino.h"
#include "functions.h"

Simon::Simon(int quantity)
{
  position = 0;
  size = quantity - 1;
  leds = new int[size];
}

void Simon::correct_answer()
{
  for (int i = 0; i < 3; i++)
  {
    tone(BUZZER, 1000, 50);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    delay(100);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    delay(100);
  }
  delay(1000);
}

void Simon::wrong_answer()
{
  tone(BUZZER, 200, 1000);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  delay(1000);
}

void Simon::reset()
{
  position = -1;
}

int Simon::button_press()
{
  while (1)
  { // waiting for input
    if (digitalRead(BUTTON1) == LOW)
      return GREEN;

    if (digitalRead(BUTTON2) == LOW)
      return RED;

    if (digitalRead(BUTTON3) == LOW)
      return YELLOW;
  }
}

void Simon::light_up(int input)
{
  switch (input)
  {
  case GREEN:
    digitalWrite(GREEN, HIGH);
    tone(BUZZER, TONE1, 100);
    delay(100);
    digitalWrite(GREEN, LOW);
    return;

  case RED:
    digitalWrite(RED, HIGH);
    tone(BUZZER, TONE2, 100);
    delay(100);
    digitalWrite(RED, LOW);
    return;

  case YELLOW:
    digitalWrite(YELLOW, HIGH);
    tone(BUZZER, TONE2, 100);
    delay(100);
    digitalWrite(YELLOW, LOW);
    return;
  }
}

void Simon::memory_game()
{
  for (int i = 0; i <= position; i++)
  {
    short input = button_press();
    if (input == leds[i])
    {
      light_up(input);
      delay(80);
    }
    else
    {
      wrong_answer();
      reset();
      return;
    }
  }
  correct_answer();
}

void Simon::start()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    tone(BUZZER, 500, 100);
    delay(500);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    delay(500);
  }
  tone(BUZZER, 700, 200);
  delay(2000);
}

void Simon::increment(int value)
{
  position += value;
}

int Simon::get_position()
{
  return position;
}

int Simon::get_size()
{
  return size;
}

void Simon::game_won()
{
  megalovania();
}

void megalovania()
{
  short notes[88] PROGMEM = {294, 294, 587, 440, 415, 392, 349, 294, 349, 392, 261, 261, 261, 261, 587, 440, 415, 392, 349, 294, 349, 392, 247, 247, 587, 440, 415, 392, 349, 294, 349, 392, 233, 233, 233, 233, 587, 440, 415, 392, 349, 294, 349, 392, 294, 294, 587, 440, 415, 392, 349, 294, 349, 392, 261, 261, 261, 261, 587, 440, 415, 392, 349, 294, 349, 392, 247, 247, 587, 440, 415, 392, 349, 294, 349, 392, 233, 233, 233, 233, 588, 440, 415, 392, 349, 294, 349, 392};
  short duration[88] PROGMEM = {125, 125, 250, 250, 125, 250, 250, 125, 125, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375, 125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125, 125, 125, 125, 250, 375, 125, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375, 125, 250, 250, 125, 125, 125};
  short time_delay[88] PROGMEM = {125, 125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125, 125, 125, 125, 250, 375, 250, 250, 250, 125, 125, 125, 62, 62, 62, 62, 250, 375, 250, 250, 250, 125, 125, 125};
  for (int i = 0; i < 88; i++)
  {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);

    digitalWrite(random(GREEN, YELLOW + 1), HIGH);
    digitalWrite(random(GREEN, YELLOW + 1), HIGH);

    tone(BUZZER, notes[i], duration[i]);
    delay(time_delay[i]);
  }
}