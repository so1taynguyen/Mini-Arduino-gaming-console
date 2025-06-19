/*
  ******************************* BIG NOTE *******************************
    - The commanded code is use for playing the music on buzzer but the 
    buzzer has too much noise so we shouldn't use those lines of code

    - 
  ************************************************************************
*/

//== Define screen's pins ==
#define TFT_CS          10
#define TFT_DC          9
#define TFT_RST         8
//==========================

//======= Declare libraries ======= 
#include "../../Library/Fast_ILI9341_Library/ILI9341_Fast.h"
#include "../../Library/AT24C/src/at24c256.h"
//=================================

//======= Define colors =======
#define CYAN            0x7639
#define FLOOR_COLOR     0xded2
#define DARK_ORANGE     0xd549  
#define SHIT            0xb508
#define DARK_GREEN      0x5404
#define GREEN           0x7605
#define LIGHT_GREEN     0x9f4b
#define GREEN_YEL       0xe7f1
#define BROWN           0x51a9
#define WHITE           0xffff
#define ORANGE          0xc302
#define RED             0xe1a9
#define EMERALD         0x0ef3
#define BLACK           0x0000
//=============================

//==== Define parameters ====
#define TFTW            240     
#define TFTH            320     
#define TFTW2           120     
#define TFTH2           160     
#define GAMEH           304
#define GAPH            36
//===========================

//== Define highest score address in EEPROM ==
#define FLAPPY_HS_ADDRESS   100
#define PING_HS_ADDRESS     200
#define SNAKE_HS_ADDRESS    300
// #define TETRIS_HS_ADDRESS   400
//============================================

ILI9341 monitor = ILI9341(TFT_DC, TFT_RST, TFT_CS);
AT24C256 eprom(AT24C_ADDRESS_0);

//====== Define pins ======
#define buttonMid     7
#define buttonUp      5
#define buttonDown    4
#define buttonLeft    3
#define buttonRight   2
#define speakerPin    6
//=========================

int menu_select;
int menu_pointer = 1;
int menu_start = 1;

int flappy_score;

int flappy_flag = 1;
int flappy_wing;
int flappy_fx, flappy_fy, flappy_fallRate;
int flappy_pillarPos, flappy_gapPos;
int flappy_highScore = 0;
bool flappy_running = false;
bool flappy_crashed = false;

void(* resetFunc) (void) = 0;

//== Include header files ==
#include "./Flappy_bird/f_Floor.h"
#include "./Flappy_bird/f_Pipe.h"
#include "./Flappy_bird/f_Birdy.h"

#include "./Snake_game/s_Header.h"
#include "./Snake_game/s_Graphic.h"
#include "./Snake_game/s_Snake.h"
#include "./Snake_game/s_Music.h"

#include "./Ping_pong/p_Header.h"
#include "./Ping_pong/p_Graphic.h"
#include "./Ping_pong/p_PingPong.h"
#include "./Ping_pong/p_Music.h"

// #include "./Tetris/t_Graphic.h"
// #include "./Tetris/t_Tetris.h"
//==========================

// int snake_melody[] = {
//   REST, 250, REST, 500, REST, 125, NOTE_DS4, 125,
//   NOTE_E4, 500, REST, 125, NOTE_FS4, 125, NOTE_G4, 500, REST, 125, NOTE_DS4, 125,
//   NOTE_E4, 250, NOTE_FS4, 125, NOTE_G4, 250, NOTE_C5, 125, NOTE_B4, 250, NOTE_E4, 125, NOTE_G4, 250, NOTE_B4, 125,
//   NOTE_AS4, 1000, NOTE_A4, 62, NOTE_G4, 62, NOTE_E4, 62, NOTE_D4, 62,
//   NOTE_E4, 1000, REST, 500, REST, 125, NOTE_DS4, 500,

//   NOTE_E4, 500, REST, 125, NOTE_FS4, 125, NOTE_G4, 500, REST, 125, NOTE_DS4, 125,
//   NOTE_E4, 250, NOTE_FS4, 125, NOTE_G4, 250, NOTE_C5, 125, NOTE_B4, 250, NOTE_G4, 125, NOTE_B4, 250, NOTE_E5, 125,
//   NOTE_DS5, 2000,
//   NOTE_D5, 1000, REST, 500, REST, 125, NOTE_DS4, 125,
//   NOTE_E4, 500, REST, 125, NOTE_FS4, 125, NOTE_G4, 500, REST, 125, NOTE_DS4, 125,
//   NOTE_E4, 250, NOTE_FS4, 125, NOTE_G4, 250, NOTE_C5, 125, NOTE_B4, 250, NOTE_E4, 125, NOTE_G4, 250, NOTE_B4, 125,

//   NOTE_AS4, 1000, NOTE_A4, 62, NOTE_G4, 62, NOTE_E4, 62, NOTE_D4, 62,
//   NOTE_E4, 500, REST, 500,
//   REST, 500, NOTE_E5, 250, NOTE_D5, 125, NOTE_B4, 250, NOTE_A4, 125, NOTE_G4, 250, NOTE_E4, 125,
//   NOTE_AS4, 62, NOTE_A4, 250, NOTE_AS4, 62, NOTE_A4, 250, NOTE_AS4, 62, NOTE_A4, 250, NOTE_AS4, 62, NOTE_A4, 250,
//   NOTE_G4, 62, NOTE_E4, 62, NOTE_D4, 62, NOTE_E4, 62, NOTE_E4, 62, NOTE_E4, 1000
// };
// const int snake_melodyLength = sizeof(snake_melody) / sizeof(snake_melody[0]);
// unsigned long snake_previousMillis = 0;
// unsigned long snake_noteDuration = 0;
// int snake_noteIndex = 0;
// bool snake_isPlaying = false;

// int ping_tempo = 144;
// int ping_melody[] = {
//   NOTE_E5, 4,  NOTE_B4, 8,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_C5, 8,  NOTE_B4, 8,
//   NOTE_A4, 4,  NOTE_A4, 8,  NOTE_C5, 8,  NOTE_E5, 4,  NOTE_D5, 8,  NOTE_C5, 8,
//   NOTE_B4, -4,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_E5, 4,
//   NOTE_C5, 4,  NOTE_A4, 4,  NOTE_A4, 8,  NOTE_A4, 4,  NOTE_B4, 8,  NOTE_C5, 8,
//   NOTE_D5, -4,  NOTE_F5, 8,  NOTE_A5, 4,  NOTE_G5, 8,  NOTE_F5, 8,
//   NOTE_E5, -4,  NOTE_C5, 8,  NOTE_E5, 4,  NOTE_D5, 8,  NOTE_C5, 8,
//   NOTE_B4, 4,  NOTE_B4, 8,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_E5, 4,
//   NOTE_C5, 4,  NOTE_A4, 4,  NOTE_A4, 4,  REST, 4,
//   NOTE_E5, 4,  NOTE_B4, 8,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_C5, 8,  NOTE_B4, 8,
//   NOTE_A4, 4,  NOTE_A4, 8,  NOTE_C5, 8,  NOTE_E5, 4,  NOTE_D5, 8,  NOTE_C5, 8,
//   NOTE_B4, -4,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_E5, 4,
//   NOTE_C5, 4,  NOTE_A4, 4,  NOTE_A4, 8,  NOTE_A4, 4,  NOTE_B4, 8,  NOTE_C5, 8,
//   NOTE_D5, -4,  NOTE_F5, 8,  NOTE_A5, 4,  NOTE_G5, 8,  NOTE_F5, 8,
//   NOTE_E5, -4,  NOTE_C5, 8,  NOTE_E5, 4,  NOTE_D5, 8,  NOTE_C5, 8,
//   NOTE_B4, 4,  NOTE_B4, 8,  NOTE_C5, 8,  NOTE_D5, 4,  NOTE_E5, 4,
//   NOTE_C5, 4,  NOTE_A4, 4,  NOTE_A4, 4,  REST, 4,
//   NOTE_E5, 2,  NOTE_C5, 2,
//   NOTE_D5, 2,  NOTE_B4, 2,
//   NOTE_C5, 2,  NOTE_A4, 2,
//   NOTE_GS4, 2,  NOTE_B4, 4,  REST, 8, 
//   NOTE_E5, 2,  NOTE_C5, 2,
//   NOTE_D5, 2,  NOTE_B4, 2,
//   NOTE_C5, 4,  NOTE_E5, 4,  NOTE_A5, 2,
//   NOTE_GS5, 2,
// };
// int ping_notes = sizeof(ping_melody) / sizeof(ping_melody[0]) / 2; 
// int ping_wholenote = (60000 * 4) / ping_tempo;
// int ping_divider = 0, ping_noteDuration = 0;
// int ping_thisNote = 0;
// unsigned long ping_noteStartTime = 0;

void setup() {
  pinMode(buttonUp, INPUT);
  pinMode(buttonMid, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(speakerPin, OUTPUT);

  Wire.begin();

  monitor.begin();
  monitor.fillScreen(0x0000);
  menu_select = 0;
}

void menu() {
  monitor.setRotation(0);
  monitor.setCursor(55, 35);
  monitor.setTextSize(4); 
  monitor.setTextColor(WHITE);
  monitor.print("NHOM 9");

  if (digitalRead(buttonUp) == 0) {
    delay(100);

    if (digitalRead(buttonUp) == 1) {
      menu_pointer -= 1;

      if (menu_pointer < 1) {
        menu_pointer = 4;
      }
    }
  }

  if (digitalRead(buttonDown) == 0) {
    delay(100);

    if (digitalRead(buttonDown) == 1) {
      if (menu_pointer < 4) {
        menu_pointer += 1;
      }
      else {
        menu_pointer = 1;
      }
    }
  }

  if (menu_pointer == 1) {
    monitor.setTextSize(2);
    monitor.setCursor(57, 200);
    monitor.setTextColor(GREEN);
    monitor.print("Flappy Bird");

    if (digitalRead(buttonMid) == 0) {
      menu_select = 1;
    }
  }
  else {
    monitor.setTextColor(WHITE);
    monitor.setTextSize(2);
    monitor.setCursor(57, 200);
    monitor.print("Flappy Bird");
  }

  if (menu_pointer == 2) {
    monitor.setTextSize(2);
    monitor.setCursor(70, 225);
    monitor.setTextColor(GREEN);
    monitor.print("Ping Pong");

    if (digitalRead(buttonMid) == 0) {
      menu_select = 2;
    }
  }
  else {
    monitor.setTextColor(WHITE);
    monitor.setTextSize(2);
    monitor.setCursor(70, 225);
    monitor.print("Ping Pong");
  }

  if (menu_pointer == 3) {
    monitor.setTextSize(2);
    monitor.setCursor(52, 250);
    monitor.setTextColor(GREEN);
    monitor.print("Hungry Snake");

    if (digitalRead(buttonMid) == 0) {
      menu_select = 3;
    }
  }
  else {
    monitor.setTextColor(WHITE);
    monitor.setTextSize(2);
    monitor.setCursor(52, 250);
    monitor.print("Hungry Snake");
  }

  /*
  if (menu_pointer == 4) {
    monitor.setTextSize(2);
    monitor.setCursor(57, 275);
    monitor.setTextColor(GREEN);
    monitor.print("Tetris Game");

    if (digitalRead(buttonMid) == 0) {
      menu_select = 4;
    }
  }
  else {
    monitor.setTextColor(WHITE);
    monitor.setTextSize(2);
    monitor.setCursor(57, 275);
    monitor.print("Tetris Game");
  }
  */
}

//============ Flappy Bird ============
void flappy_start_game() {
  draw_floor();
  monitor.drawRect(TFTW2 - 40, TFTH2 - 80, 80, 30, BROWN);
  monitor.drawRect(TFTW2 - 41, TFTH2 - 81, 82, 32, BROWN);
  monitor.drawRect(TFTW2 - 42, TFTH2 - 82, 84, 34, BROWN);
  monitor.drawRect(TFTW2 - 39, TFTH2 - 79, 78, 28, WHITE);
  monitor.drawRect(TFTW2 - 38, TFTH2 - 78, 76, 26, WHITE);
  monitor.fillRect(TFTW2 - 37, TFTH2 - 77, 74, 24, ORANGE);
  monitor.setCursor(TFTW2 - 28, TFTH2 + 58);
  monitor.setTextColor(WHITE);
  monitor.setTextSize(2, 2);
  monitor.setRotation(4);
  monitor.print(F("START"));
  monitor.setTextColor(ORANGE);
  monitor.setTextSize(2);
  monitor.setCursor(70, 135);
  monitor.print(F("FLAPPY BIRD"));
  monitor.setRotation(2);
  monitor.drawImageF(TFTW2 + BIRD_W  + 30,  TFTH2 - BIRD_H + 30, BIRD_W, BIRD_H, floating_bird);

  monitor.setRotation(4);
  monitor.setTextColor(WHITE);
  monitor.setTextSize(1, 1);
  monitor.setCursor(TFTW2 - 55, TFTH2 - 100);
  monitor.print(F("Highest Score: "));
  monitor.print(eprom.read(FLAPPY_HS_ADDRESS));
  monitor.setRotation(2);

  while (flappy_flag) {
    if (digitalRead(buttonMid) == 0) {
      flappy_flag = 0;
      monitor.fillRect(0, FLOOR_H + 16, TFTW, GAMEH, CYAN);
    }

    if (digitalRead(buttonDown) == 0) {
      menu_start = 1;
      resetFunc();
    }
  }

  flappy_fx = TFTW - 80;
  flappy_fy = ((TFTH - (FLOOR_H + 16)) / 2) + FLOOR_H;
  flappy_fallRate = 1;
  flappy_pillarPos = -60;
  flappy_gapPos = random(70, TFTH - 135);
  flappy_crashed = false;
  flappy_score = 0;
  flappy_highScore = eprom.read(FLAPPY_HS_ADDRESS);
}

void draw_loop() {
  clear_pillar(flappy_pillarPos, flappy_gapPos);
  clear_flappy(flappy_fx, flappy_fy);

  if (flappy_running) {
    flappy_fy += flappy_fallRate;
    flappy_fallRate--;

    flappy_pillarPos += 5;
    if (flappy_pillarPos == (flappy_fx + 5)) {
      flappy_score++;
    }
    else if (flappy_pillarPos > TFTW) {
      flappy_pillarPos = -PIPEW + 2;
      flappy_gapPos = random(65, TFTH - 135);
    }
  }

  draw_pillar(flappy_pillarPos, flappy_gapPos);
  draw_flappy(flappy_fx, flappy_fy);
  flappy_wing++;
  if (flappy_wing == 80) {
    flappy_wing = 0;
  }
}

void checkCollision() {
  if (flappy_fy > (TFTH - BIRD_H) + 29) {
    flappy_crashed = true;
  }
  
  if (flappy_fx + BIRD_W > flappy_pillarPos - 4 && flappy_fx < flappy_pillarPos + PIPEW + 4) {
    if (flappy_fy < flappy_gapPos || flappy_fy + BIRD_H > flappy_gapPos + 100) {
      flappy_crashed = true;
    }
  }

  if (flappy_fx == (flappy_pillarPos + PIPEW + 4)) {
    if (flappy_fy < (flappy_gapPos + 29) || flappy_fy + BIRD_H > flappy_gapPos + 129) {
      flappy_crashed = true;
    }
  }

  if (flappy_fy <= FLOOR_H + 29) {
    flappy_crashed = true;
  }
  
  if (flappy_crashed) {
    monitor.fillRect(50, 127, 150, 63, FLOOR_COLOR);
    monitor.drawRect(48, 125, 154, 67, DARK_ORANGE);
    monitor.drawRect(49, 126, 152, 65, DARK_ORANGE);
    monitor.setRotation(4);
    monitor.setTextColor(RED);
    monitor.setTextSize(2);
    monitor.setCursor(60, 135);
    monitor.println(F("GAME OVER!"));
    monitor.setTextSize(1);
    monitor.setCursor(90, 155);
    monitor.println(F("Score:"));
    monitor.setCursor(130, 155);
    monitor.println(flappy_score);
    monitor.setTextColor(WHITE);
    monitor.setCursor(48, 295);          
    monitor.println("<press enter to continue>");
    monitor.setCursor(63, 308);          
    monitor.println("<press down to exit>");
    
    if (flappy_score > flappy_highScore) {
      flappy_highScore = flappy_score;
      eprom.write(FLAPPY_HS_ADDRESS, flappy_highScore);
      monitor.setCursor(62, 175);
      monitor.setTextColor(RED);
      monitor.setTextSize(2, 2);
      monitor.println("NEW HIGH!");
    }

    monitor.setRotation(2);

    flappy_running = false;
    
    delay(2200);
    while (digitalRead(buttonMid)) {
      if (digitalRead(buttonDown) == 0) {
        menu_start = 1;
        resetFunc();
      }
    }
  }
}

void flappy_setup() {
  monitor.setRotation(2); 

  flappy_start_game();
}

void flappy_loop() {
  if (!flappy_crashed) {
    draw_loop();
    checkCollision();
  }

  if (flappy_crashed) {
    flappy_flag = 1;
    flappy_start_game();
  }
  else if (digitalRead(buttonMid) == 0) {
    if (!flappy_running) {
      flappy_running = true;
    }
    else {
      flappy_fallRate = 6;
    } 
  }
}

//============ Ping Pong ============
void ping_setup()
{
  //Khoi dong man hinh
  monitor.fillScreen(monitor.color565(3, 1, 28));
  monitor.setRotation(4);

  ping_highest_score = eprom.read(PING_HS_ADDRESS);

  ping_drawStartScreen();
  delay(100);
}

void ping_loop() {

  unsigned long currentTime = millis();
  //Neu tro choi dang chay 
  if(ping_gameOn)
  {
    ping_drawScore(); // Ve diem so
    drawPaddle(); // Ve thanh chan
    drawPong(); // Ve bong
    drawBricks(); // Ve cac vien gach
  }

  //Kiem tra cac nut nhan 
  bool upPressed = digitalRead(buttonUp) == LOW; // Kiem tra nut UP co duoc nhan khong
  bool downPressed = digitalRead(buttonDown) == LOW; // Kiem tra nut down co duoc nhan khong
  bool enterPressed = digitalRead(buttonMid) == LOW; //Kiem tra nut enter co duoc nhan khong
  
  if(upPressed)
  {
    movePaddle(-1); //Di chuyen thanh chan len
  }

  else if(downPressed)
  {
    movePaddle(1); //Di chuyen thanh chan xuong
  }

  if (enterPressed && !ping_gameOn)
  {
    ping_resetGame();   // Dat lai tro choi
    ping_gameOn = true; // Bat dau tro choi
  }

  if (ping_gameOver && downPressed) {
    menu_start = 1;
    resetFunc();
  }

  if (ping_gameOver && enterPressed)
  {
    //Xoa man hinh va chuyen ve man hinh StartGame
    monitor.fillScreen(monitor.color565(3, 1, 28));
    ping_drawStartScreen();
    delay(100);

    // Cho nguoi choi bat dau lai bang cach bam enter
    while (digitalRead(buttonMid) == HIGH)
    {
      delay(100);
    }

    //Dat lai tro choi va bat dau lai
    ping_resetGame();
    ping_gameOn = true;
    ping_gameOver = false;
  }

  //Phat nhac
  // if(currentTime - ping_noteStartTime >= ping_noteDuration)
  // {
  //   //Dung phat not cu
  //   noTone(speakerPin);
  //   //Tinh toan not tiep theo
  //   ping_divider = ping_melody[ping_thisNote +1];
  //   if(ping_divider > 0)
  //   {
  //     ping_noteDuration = (ping_wholenote) / ping_divider;
  //   }
  //   else if (ping_divider < 0)
  //   {
  //     ping_noteDuration = (ping_wholenote) / abs(ping_divider);
  //     ping_noteDuration *= 1.5; //Tang do dai len 1.5 lan cho note co dau cham
  //   }
  //   //Phat note moi
  //   tone(speakerPin, ping_melody[ping_thisNote], ping_noteDuration * 0.9);

  //   //Cap nhat thoi gian bat dau note tiep theo 
  //   ping_noteStartTime = currentTime + ping_noteDuration;
  //   //Chuyen sang note tiep theo 
  //   ping_thisNote += 2;
  //   if(ping_thisNote >= ping_notes * 2)
  //   {
  //     ping_thisNote = 0; //Quay lai note dau tien neu nhu het bai
  //   }
  // }
  delay(2);
}

//============ Hungry Snake ============
void snake_setup()
{
  monitor.setRotation(4);

  snake_highscore = eprom.read(SNAKE_HS_ADDRESS);

  // noInterrupts();         // Tắt các ngắt toàn cục
  // TCCR1A = 0;               // Xóa thanh ghi điều khiển A của Timer1
  // TCCR1B = 0;               // Xóa thanh ghi điều khiển B của Timer1
  // TCNT1 = 0;                // Đặt bộ đếm của Timer1 về 0

  // // Đặt ngắt Timer1 để kích hoạt mỗi 1ms (1000Hz)
  // OCR1A = 15999;            // Giá trị so sánh cho 1ms: 16MHz / (1000 * 1) - 1
  // TCCR1B |= (1 << WGM12);   // CTC mode
  // TCCR1B |= (1 << CS10);    // Không có bộ chia tần số (prescaler)
  // TIMSK1 |= (1 << OCIE1A);  // Bật ngắt so sánh A của Timer1

  // interrupts();             // Bật các ngắt toàn cục
}

void snake_loop()
{ 
    SnakestartScreen();
    SnakegamePlay();
}

// ISR(TIMER1_COMPA_vect) {
//   // Hàm ngắt để phát nốt nhạc
//   unsigned long currentMillis = millis();

//   // Kiểm tra nếu đang không phát nhạc và đến lúc phát nốt tiếp theo
//   if (!snake_isPlaying && snake_noteIndex < snake_melodyLength) {
//     snake_previousMillis = currentMillis;
//     int note = snake_melody[snake_noteIndex];
//     snake_noteDuration = snake_melody[snake_noteIndex + 1];

//     if (note == REST) {
//       noTone(speakerPin);  // Nốt nghỉ, không phát âm
//     } else {
//       tone(speakerPin, note, snake_noteDuration);
//     }

//     snake_isPlaying = true;
//   }

//   // Kiểm tra nếu đã phát hết thời gian của nốt hiện tại
//   if (snake_isPlaying && (currentMillis - snake_previousMillis >= snake_noteDuration)) {
//     noTone(speakerPin);
//     snake_isPlaying = false;
//     snake_noteIndex += 2;

//     // Nếu đã phát hết các nốt, bắt đầu lại từ đầu hoặc dừng lại
//     if (snake_noteIndex >= snake_melodyLength) {
//       snake_noteIndex = 0; // Để bắt đầu lại từ đầu
//     }
//   }
// }

//============ Tetris Game ============
/*
void tetris_setup() {
  monitor.setRotation(0);
  eprom.write(TETRIS_HS_ADDRESS, 0);///////////////////////////////////////////////////////////////////

  tetris_highscore = eprom.read(TETRIS_HS_ADDRESS);

  tetris_grid[190] = 1; tetris_grid[191] = 1; tetris_grid[192] = 1; tetris_grid[193] = 1;
  tetris_grid[194] = 1; tetris_grid[195] = 1; tetris_grid[196] = 1; tetris_grid[197] = 1;
  tetris_grid[198] = 1; tetris_grid[199] = 1;
  tetris_pos = 4;

  tetris_start_screen();
}

void tetris_loop() {
  tetris_gameplay();
}
*/

//============ Main loop ============
void loop() {
  if (menu_select == 0) {
    menu();
  }

  if (menu_select == 1) {
    if (menu_start == 1) {
      flappy_setup();
      menu_start = 0;
    }
    
    if (menu_start == 0) {
      flappy_loop();
    }
  }

  if (menu_select == 2) {
    if (menu_start == 1) {
      ping_setup();
      menu_start = 0;
    }
    
    if (menu_start == 0) {
      ping_loop();
    }
  }
  
  if (menu_select == 3) {
    if (menu_start == 1) {
      snake_setup();
      menu_start = 0;
    }
    
    if (menu_start == 0) {
      snake_loop();
    }
  }
  /*
  if (menu_select == 4) {
    if (menu_start == 1) {
      tetris_setup();
      menu_start = 0;
    }
    
    if (menu_start == 0) {
      tetris_loop();
    }
  }
  */
}