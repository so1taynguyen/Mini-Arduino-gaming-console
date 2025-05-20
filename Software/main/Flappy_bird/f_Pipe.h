#ifndef PIPE_H
#define PIPE_H

#define PIPEW    52

void draw_pillar(int x, int gap) {
  monitor.drawRect(x - 4, gap - 25, 60, 25, BROWN);
  monitor.drawRect(x - 3, gap - 24, 58, 23, BROWN);
  monitor.drawFastVLine(x, FLOOR_H + 14, gap - 67, BROWN);
  monitor.drawFastVLine(x + 1, FLOOR_H + 14, gap - 67, BROWN);
  monitor.drawFastVLine(x + PIPEW - 1, FLOOR_H + 14, gap - 67, BROWN);
  monitor.drawFastVLine(x + PIPEW - 2, FLOOR_H + 14, gap - 67, BROWN);

  monitor.fillRect(x + 2, FLOOR_H + 16, 4, gap - 71, DARK_GREEN);
  monitor.fillRect(x + 6, FLOOR_H + 16, 2, gap - 71, GREEN);
  monitor.fillRect(x + 8, FLOOR_H + 16, 2, gap - 71, DARK_GREEN);
  monitor.fillRect(x + 10, FLOOR_H + 16, 27, gap - 71, GREEN);
  monitor.fillRect(x + 37, FLOOR_H + 16, 2, gap - 71, LIGHT_GREEN);
  monitor.fillRect(x + 39, FLOOR_H + 16, 2, gap - 71, GREEN);
  monitor.fillRect(x + 41, FLOOR_H + 16, 5, gap - 71, LIGHT_GREEN);
  monitor.fillRect(x + 46, FLOOR_H + 16, 2, gap - 71, GREEN_YEL);
  monitor.fillRect(x + 48, FLOOR_H + 16, 2, gap - 71, LIGHT_GREEN);

  monitor.fillRect(x - 2, (FLOOR_H + 16) + (gap - 71) + 2, 4, 21, DARK_GREEN);
  monitor.fillRect(x + 2, (FLOOR_H + 16) + (gap - 71) + 2, 2, 21, GREEN);
  monitor.fillRect(x + 4, (FLOOR_H + 16) + (gap - 71) + 2, 2, 21, DARK_GREEN);
  monitor.fillRect(x + 6, (FLOOR_H + 16) + (gap - 71) + 2, 35, 21, GREEN);
  monitor.fillRect(x + 41, (FLOOR_H + 16) + (gap - 71) + 2, 2, 21, LIGHT_GREEN);
  monitor.fillRect(x + 43, (FLOOR_H + 16) + (gap - 71) + 2, 2, 21, GREEN);
  monitor.fillRect(x + 45, (FLOOR_H + 16) + (gap - 71) + 2, 5, 21, LIGHT_GREEN);
  monitor.fillRect(x + 50, (FLOOR_H + 16) + (gap - 71) + 2, 2, 21, GREEN_YEL);
  monitor.fillRect(x + 52, (FLOOR_H + 16) + (gap - 71) + 2, 2, 21, LIGHT_GREEN);
  monitor.drawFastHLine(x - 2, (FLOOR_H + 16) + (gap - 71) + 2, 56, DARK_GREEN);

  monitor.drawRect(x - 4, 100 + gap, 60, 25, BROWN);
  monitor.drawRect(x - 3, 101 + gap, 58, 23, BROWN);
  monitor.drawFastVLine(x, 125 + gap, TFTH, BROWN);
  monitor.drawFastVLine(x + 1, 125 + gap, TFTH, BROWN);
  monitor.drawFastVLine(x + PIPEW - 1, 125 + gap, TFTH, BROWN);
  monitor.drawFastVLine(x + PIPEW - 2, 125 + gap, TFTH, BROWN);

  monitor.fillRect(x + 2, 125 + gap, 4, TFTH - gap - 100, DARK_GREEN);
  monitor.fillRect(x + 6, 125 + gap, 2, TFTH - gap - 100, GREEN);
  monitor.fillRect(x + 8, 125 + gap, 2, TFTH - gap - 100, DARK_GREEN);
  monitor.fillRect(x + 10, 125 + gap, 27, TFTH - gap - 100, GREEN);
  monitor.fillRect(x + 37, 125 + gap, 2, TFTH - gap - 100, LIGHT_GREEN);
  monitor.fillRect(x + 39, 125 + gap, 2, TFTH - gap - 100, GREEN);
  monitor.fillRect(x + 41, 125 + gap, 5, TFTH - gap - 100, LIGHT_GREEN);
  monitor.fillRect(x + 46, 125 + gap, 2, TFTH - gap - 100, GREEN_YEL);
  monitor.fillRect(x + 48, 125 + gap, 2, TFTH - gap - 100, LIGHT_GREEN);

  monitor.fillRect(x - 2, 102 + gap, 4, 21, DARK_GREEN);
  monitor.fillRect(x + 2, 102 + gap, 2, 21, GREEN);
  monitor.fillRect(x + 4, 102 + gap, 2, 21, DARK_GREEN);
  monitor.fillRect(x + 6, 102 + gap, 35, 21, GREEN);
  monitor.fillRect(x + 41, 102 + gap, 2, 21, LIGHT_GREEN);
  monitor.fillRect(x + 43, 102 + gap, 2, 21, GREEN);
  monitor.fillRect(x + 45, 102 + gap, 5, 21, LIGHT_GREEN);
  monitor.fillRect(x + 50, 102 + gap, 2, 21, GREEN_YEL);
  monitor.fillRect(x + 52, 102 + gap, 2, 21, LIGHT_GREEN);
  monitor.drawFastHLine(x - 2, 122 + gap, 56, DARK_GREEN);
}

void clear_pillar(int x, int gap) {
  monitor.fillRect(x - 4, FLOOR_H + 16, 9, gap, CYAN);
  monitor.fillRect(x - 4, gap + 100, 9, TFTH - gap - 100, CYAN);
}
#endif