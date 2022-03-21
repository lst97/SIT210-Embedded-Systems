void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

const int TIME_UNIT = 200;
class Morse {
  private:
    String words;
    int data[26][4] = {
        {TIME_UNIT, TIME_UNIT * 3, 0, 0}, {TIME_UNIT * 3, TIME_UNIT, TIME_UNIT, TIME_UNIT}, {TIME_UNIT * 3, TIME_UNIT, TIME_UNIT * 3, TIME_UNIT}, {TIME_UNIT * 3, TIME_UNIT, TIME_UNIT, 0},
        {TIME_UNIT, 0, 0, 0}, {TIME_UNIT, TIME_UNIT, TIME_UNIT * 3, TIME_UNIT}, {TIME_UNIT * 3, TIME_UNIT * 3, TIME_UNIT, 0}, {TIME_UNIT, TIME_UNIT, TIME_UNIT, TIME_UNIT},
        {TIME_UNIT, TIME_UNIT, 0, 0}, {TIME_UNIT, TIME_UNIT * 3, TIME_UNIT * 3, TIME_UNIT * 3}, {TIME_UNIT * 3, TIME_UNIT, TIME_UNIT * 3, 0}, {TIME_UNIT, TIME_UNIT * 3, TIME_UNIT, TIME_UNIT},
        {TIME_UNIT * 3, TIME_UNIT * 3, 0, 0}, {TIME_UNIT * 3, TIME_UNIT, 0, 0}, {TIME_UNIT * 3, TIME_UNIT * 3, TIME_UNIT * 3, 0}, {TIME_UNIT, TIME_UNIT * 3, TIME_UNIT * 3, TIME_UNIT},
        {TIME_UNIT * 3, TIME_UNIT * 3, TIME_UNIT, TIME_UNIT * 3}, {TIME_UNIT, TIME_UNIT * 3, TIME_UNIT, 0}, {TIME_UNIT, TIME_UNIT, TIME_UNIT, 0}, {TIME_UNIT * 3},
        {TIME_UNIT, TIME_UNIT, TIME_UNIT * 3, 0}, {TIME_UNIT, TIME_UNIT, TIME_UNIT, TIME_UNIT * 3}, {TIME_UNIT, TIME_UNIT * 3, TIME_UNIT * 3, 0}, {TIME_UNIT * 3, TIME_UNIT, TIME_UNIT, TIME_UNIT * 3},
        {TIME_UNIT * 3, TIME_UNIT, TIME_UNIT * 3, TIME_UNIT * 3}, {TIME_UNIT * 3, TIME_UNIT * 3, TIME_UNIT, TIME_UNIT}
      };

  public:
    Morse() {
      this->words = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    void blink(String input) {
      int len = input.length();
      int word_index;
      int delay_time;
      
      for (int i = 0; i < len; i++) {
        word_index = words.indexOf(input[i]);
        Serial.print(words[word_index]);
        for (int j = 0; j < 4; j++) {
          delay_time = data[word_index][j];
          if (delay_time == 0) 
            continue;
          
          digitalWrite(13, HIGH);
          delay(delay_time);
          digitalWrite(13, LOW);
          delay(TIME_UNIT);
        }
      }
      delay(TIME_UNIT);
    }
};

void loop() {
  // put your main code here, to run repeatedly:

  Morse* morse = new Morse();
  morse->blink("SOS");
}
