/*Use pins 2-10
You can get the TTBOUNCE library here: https://github.com/TOLDOTECHNIK/TTBOUNCE
*/
#include <TTBOUNCE.h>

int delay_time = 0;
const uint8_t led_array[9] = {4,3,5,6,7,8,9,10,11};
const uint8_t button = 2;
uint8_t difficulty = 0;
uint8_t current_led = 0;
bool dir_flag = true; //true goes right, false goes left
bool game_ended = false;
bool is_win = false;
bool is_finished_selecting = false;

TTBOUNCE b = TTBOUNCE(button);

void doubleClick(){
  Serial.println("double click");
  is_finished_selecting = true;
  delay_time = floor(500/(difficulty+1)); //Formula: delay (in ms) = 500 / (difficulty + 1)
  Serial.println("difficulty: " + String(delay_time));
  sweep();
}

void click(){
  Serial.print("Click | ");
  digitalWrite(led_array[difficulty], LOW);
  difficulty++;
  if(difficulty>8){
    difficulty = 0;
  }
  digitalWrite(led_array[difficulty], HIGH);
  Serial.println("Difficulty is: "+String(difficulty));
  delay(100);
}

void setup()
{
  Serial.begin(9600);
  b.attachDoubleClick(doubleClick);
  b.attachClick(click);
  b.setActiveLow();
  b.enablePullup();
  
  for(int i=0;i<9;i++){
    pinMode(led_array[i], OUTPUT);
  }
 
  sweep();
  pulse();

  difficulty = 0;
  digitalWrite(led_array[difficulty], HIGH);
  while(!is_finished_selecting){
    b.update();
  }
  b.update();
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), button_pressed, FALLING);
  delay(1000);
}

void loop()
{
  if(game_ended==false){
    move_led();
    delay(delay_time);
  }
  else if(game_ended){
    Serial.println(game_ended);
    Serial.println("Game over");
    if(is_win){
    Serial.println("you won");
      for(int i=0; i<5;i++){
        pulse();
        delay(100);
      }
    }
   sweep();
    game_ended = false;
    is_win = false;
   delay(2000);
  }
}

void move_led()
{
  digitalWrite(led_array[current_led], LOW);
  if(current_led == 8){
    dir_flag = false;
    current_led -= 1;
  }
  
  else if(current_led == 0){
    dir_flag = true;
    current_led += 1;
  }
  
  else if(dir_flag){
    current_led += 1;
  }
  
  else if(!dir_flag){
    current_led -= 1;
  }
  digitalWrite(led_array[current_led], HIGH);
}

void pulse(){
  for(int i=0; i<9;i++){
    digitalWrite(led_array[i], HIGH);
  }
  
  delay(100);
  
  for(int i=0; i<9;i++){
    digitalWrite(led_array[i], LOW);
  }
}

void sweep(){
  for(int i=0; i<9;i++){
    digitalWrite(led_array[i], HIGH);
    delay(50);
    digitalWrite(led_array[i], LOW);
  }
  
  for(int i=8; i>=0;i--){
    digitalWrite(led_array[i], HIGH);
    delay(50);
    digitalWrite(led_array[i], LOW);
  }
}

void button_pressed(){
  Serial.println("Button pressed on LED: "+String(current_led));
  game_ended = true;
  if(current_led==4){
    is_win = true;
  }
  else if(current_led != 4){
    is_win = false;
  }
 current_led = 0;
 delay(500);
}
