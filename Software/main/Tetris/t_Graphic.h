#ifndef t_GRAPHIC_h
#define t_GRAPHIC_h

void tetris_start_screen() {
  monitor.fillScreen(EMERALD);
  monitor.setCursor(63, 10);
  monitor.setTextSize(3);  
  monitor.setTextColor(RED);
  monitor.print("TETRIS");
  monitor.drawRect(44, 40, 152, 272, WHITE);
  monitor.drawRect(43, 39, 154, 274, WHITE);
  monitor.fillRect(45, 41, 150, 270, BLACK);
}

#endif