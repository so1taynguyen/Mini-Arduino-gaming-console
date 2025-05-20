#ifndef Snake_h
#define Snake_h

void SnakegamePlay();
void draw_design();
void spawn_apple();
void check_direction();
void step();
void check_apple();
void check_collision();
void append_square();
void check_and_delay(int ms);
void draw_score();
void draw_quadrat (int x_pos, int y_pos, int color);
void check_highscre();
void gameover();
void Snakereset_game();

int snake_score = 0;
int snake_highscore;
int snake_speed = 300;
int snake_position[100][2] = {{12, 16}, {12, 17}, {12, 18}};
int snake_element = 3;
int snake_direction = 1;
int apple_position[2];

void SnakegamePlay()
{
    draw_design();
    spawn_apple();

    for (int i=0;i<snake_element;i++) {
      draw_quadrat(snake_position[i][0],snake_position[i][1], ILI9341_BLACK);
    }

    check_direction();
}

void check_direction(){
  while (true) {
    check_and_delay(0);
    if (snake_direction == 1) {     //Up
      if (snake_position[0][1] == 3) {
        gameover();
      }
      step();
      snake_position[0][1] -= 1;
    }

    else if (snake_direction == 2) {    //Right
      if (snake_position[0][0] == 22) {
        gameover();
      }
      step();
      snake_position[0][0] += 1;
    }

    else if (snake_direction == 3) {    //Down
      if (snake_position[0][1] == 30) {
        gameover();
      }
      step();
      snake_position[0][1] += 1;
    }

    else if (snake_direction == 4) {  //Left
      if (snake_position[0][0] == 1) {
        gameover();
      }
      step();
      snake_position[0][0] -= 1;
    }

    draw_quadrat(snake_position[0][0], snake_position[0][1], ILI9341_BLACK);
    check_and_delay(snake_speed);
  }
}

void step() {
  int last = snake_element - 1;
  draw_quadrat(snake_position[last][0], snake_position[last][1], ILI9341_DARKGREEN);
  for (int i = last; i > 0; i--) {
    snake_position[i][0] = snake_position[i - 1][0];
    snake_position[i][1] = snake_position[i - 1][1];
  }
  check_apple();
  check_collision();
}

void check_apple() { 
  if (snake_position[0][0] == apple_position[0] && snake_position[1][1] == apple_position[1]) {
    snake_score += 1;
    draw_score();
    append_square();
    spawn_apple();

    if (300 - snake_score * 10 < 80) {
      snake_speed = 50;                             
    } else {
      snake_speed = 300 - snake_score * 10;  
    }
  }
}

void check_collision() { 
  for (int i = 2; i < snake_element; i++) {
    if (snake_position[0][0] == snake_position[i][0] and snake_position[0][1] == snake_position[i][1]) {
      gameover();
    }
  }
} 


void append_square() { 
  snake_position[snake_element][0] = snake_position[snake_element - 1][0];
  snake_position[snake_element][1] = snake_position[snake_element - 1][1];

  snake_element++;
}

void check_and_delay(int ms) {
  for (int i = 0; i < ms; i++) {
    delay(1);
    if (digitalRead(buttonUp) == LOW && snake_direction != 3) {
      snake_direction = 1;
    }
    else if (digitalRead(buttonDown) == LOW && snake_direction != 1) {
      snake_direction = 3;
    }
    else if (digitalRead(buttonLeft) == LOW && snake_direction != 2) {
      snake_direction = 4;
    }
    else if (digitalRead(buttonRight) == LOW && snake_direction != 4) {
      snake_direction = 2;
    }
  }
}

void draw_design() {
  monitor.fillScreen(ILI9341_DARKGREEN);
  monitor.drawRect(9, 31, 222, 278, ILI9341_BLACK);

  monitor.setCursor(50, 5);
  monitor.setTextColor(ILI9341_BLACK);
  monitor.setTextSize(3);
  monitor.println("SCORE: ");
  monitor.setCursor(175, 5);
  monitor.println(snake_score);
}

void draw_score () {
  monitor.setCursor(175, 5);
  monitor.setTextSize(3);
  monitor.setTextColor(ILI9341_DARKGREEN);
  monitor.println(snake_score - 1);

  monitor.setCursor(175, 5);
  monitor.setTextSize(3);
  monitor.setTextColor(ILI9341_BLACK);
  monitor.println(snake_score);
}

void spawn_apple() {  
  int random_x = random(1, 23);   
  int random_y = random(3, 31);  

  int numofelement = sizeof(snake_position) / sizeof (snake_position[0]);

  for (int i = 0; i < numofelement/ 4; i++) { 
    if (snake_position[i][0] == random_x && snake_position[i][1] == random_y) {
      spawn_apple();
      exit(0);
    }
  }

  apple_position[0] = random_x;
  apple_position[1] = random_y;
  draw_quadrat(random_x, random_y, ILI9341_RED); 
}

void draw_quadrat (int x_pos, int y_pos, int color) { 
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      monitor.drawPixel(x_pos * 10 + i, y_pos * 10 + j, color);
    }
  }
} 

void check_highscore() { 
  if (snake_score > snake_highscore) {  
    snake_highscore = snake_score;
    eprom.write(SNAKE_HS_ADDRESS, snake_highscore);

    monitor.setCursor(40, 230);          
    monitor.setTextColor(ILI9341_YELLOW);
    monitor.setTextSize(2);
    monitor.println("NEW HIGHSCORE!");
  }

  monitor.setCursor(40, 5);          
  monitor.setTextColor(ILI9341_YELLOW);
  monitor.setTextSize(2);
  monitor.println("HIGHSCORE:");
  monitor.setCursor(180, 5);
  monitor.println(snake_highscore);
}

void gameover() { //Gameover Bildschirm
  monitor.fillScreen(ILI9341_BLACK);    
  monitor.setCursor(15, 140);
  monitor.setTextColor(ILI9341_RED);
  monitor.setTextSize(4);
  monitor.println("GAME OVER");

  monitor.setCursor(70, 200);           
  monitor.setTextColor(ILI9341_WHITE);
  monitor.setTextSize(2);
  monitor.println("Score:");
  monitor.setCursor(155, 200);
  monitor.println(snake_score);

  check_highscore();

  monitor.setCursor(47, 285);          
  monitor.setTextSize(1);
  monitor.setTextColor(ILI9341_DARKGREY);
  monitor.println("<press enter to continue>");
  monitor.setCursor(63, 300);          
  monitor.println("<press down to exit>");

  while (digitalRead(7) == HIGH) {
    if (digitalRead(buttonDown) == 0) {
      menu_start = 1;
      resetFunc();
    }
  }
  Snakereset_game();
}

void Snakereset_game() { 
  snake_direction = 1;
  snake_score = 0;
  snake_speed = 300;
  snake_element = 3;

  for (int i = 0; i < 3; i++) {
    snake_position[i][0] = 12;
    snake_position[i][1] = 16 + i;
  }
  SnakegamePlay();
}

#endif 
