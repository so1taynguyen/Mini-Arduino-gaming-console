#ifndef FLOOR_Header
#define FLOOR_Header

#define FLOOR_H   30

void draw_detail(int x, int y) {
  for (int i = 0; i < 7; i++) {
    monitor.drawLine(x + i, y, x + i + 4, y + 6, GREEN);
  }
}

void draw_floor() {
  monitor.fillScreen(CYAN);
  monitor.fillRect(0, 0, TFTW, FLOOR_H, FLOOR_COLOR);
  monitor.fillRect(0, FLOOR_H, TFTW, 2, DARK_ORANGE);
  monitor.fillRect(0, FLOOR_H + 2, TFTW, 1, SHIT);
  monitor.fillRect(0, FLOOR_H + 3, TFTW, 3, DARK_GREEN);
  monitor.fillRect(0, FLOOR_H + 6, TFTW, 6, LIGHT_GREEN);
  for (int i = 0; i < TFTW; i += 15) {
    draw_detail(i, FLOOR_H + 6);
  }
  monitor.fillRect(0, FLOOR_H + 12, TFTW, 2, GREEN_YEL);
  monitor.fillRect(0, FLOOR_H + 14, TFTW, 2, BROWN);
}

#endif