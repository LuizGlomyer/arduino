const byte GREEN PROGMEM = 2;
const byte RED PROGMEM = 3;
const byte YELLOW PROGMEM = 4;
const byte BUZZER PROGMEM = 5;

const byte UNCONNECTED_PIN PROGMEM = 6;

const byte BUTTON1 PROGMEM = 8;
const byte BUTTON2 PROGMEM = 9;
const byte BUTTON3 PROGMEM = 10;

const short TONE1 PROGMEM = 600;
const short TONE2 PROGMEM = 650;
const short TONE3 PROGMEM = 700;

class Simon
{
public:
  Simon(int quantity);
  void start();
  void memory_game();
  int button_press();
  void correct_answer();
  void wrong_answer();
  void reset();
  void game_won();
  void light_up(int input);
  void increment(int value);
  int *leds;
  int get_position();
  int get_size();

private:
  int position;
  int size;
};

void megalovania();