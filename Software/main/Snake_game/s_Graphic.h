#ifndef s_Graphic_h
#define s_Graphic_h

void SnakedrawGrass() {
   int16_t s_width = 240; 
   int16_t s_height = 320;

   monitor.drawBitmap(0, 0, Grass, s_width, s_height, monitor.color565(0, 92, 10));
}


void SnakeStartTitle()
{
    monitor.setCursor(0, 0);
    monitor.setTextColor(ILI9341_WHITE);
    monitor.setTextSize(4);
    monitor.println("SNAKE");
    monitor.setCursor(144, 0);
    monitor.println("GAME");
}

void SnakedrawSnake()
{
    // body
    monitor.fillRoundRect(80, 30, 130, 10, 5, ILI9341_ORANGE);
    monitor.fillRoundRect(200, 30, 10, 70, 5, ILI9341_ORANGE);
    monitor.fillRoundRect(30, 90, 175, 10, 5, ILI9341_ORANGE);
    monitor.fillRoundRect(30, 90, 10, 85, 5, ILI9341_ORANGE);
    monitor.fillRoundRect(30, 170, 90, 10, 5, ILI9341_ORANGE);
    // face
    monitor.fillRect(110, 176, 2, 2, ILI9341_BLACK);
    monitor.fillRect(110, 172, 2, 2, ILI9341_BLACK);
    monitor.fillRect(118, 174, 6, 2, ILI9341_RED);
}

void SnakedrawApple()
{
    monitor.fillCircle(140, 175, 5, ILI9341_RED);
    monitor.drawCircle(140, 175, 6, ILI9341_BLACK);
    monitor.fillCircle(143, 165, 1, ILI9341_GREEN);
    monitor.fillCircle(144, 165, 1, ILI9341_GREEN);
    monitor.fillCircle(144, 166, 1, ILI9341_GREEN);
    monitor.drawLine(140, 170, 143, 164, ILI9341_MAROON);
}

void SnakedrawStartText()
{
    monitor.setCursor(20, 240);
    monitor.setTextColor(ILI9341_LIGHTGREY);
    monitor.setTextSize(2);
    monitor.println("> PRESS TO PLAY <");
    monitor.setCursor(50, 270);
    monitor.setTextSize(1);
    monitor.println("Highest Score:");
    monitor.setCursor(150, 270);
    monitor.println(eprom.read(SNAKE_HS_ADDRESS));

    // print credits
    monitor.setCursor(40, 300);
    monitor.setTextColor(ILI9341_WHITE);
    monitor.setTextSize(1);
    monitor.println("- created by Vinh Khang -");
}

void SnakestartScreen()
{
    monitor.fillScreen(ILI9341_DARKGREEN);
    SnakedrawGrass();
    SnakeStartTitle();
    SnakedrawSnake();
    SnakedrawApple();
    SnakedrawStartText();

    while(digitalRead(7)==HIGH);
}

#endif 
