#ifndef p_Graphic_h
#define p_Graphic_h

void ping_drawtitle() {
  monitor.setCursor(0, 0);
  monitor.setTextColor(ILI9341_WHITE);
  monitor.setTextSize(6);
  monitor.print("PING");
  monitor.setCursor(86, 65);
  monitor.setTextSize(6);
  monitor.print("PONG");
};

void ping_drawtext() {
  monitor.setCursor(50, 130);
  monitor.setTextColor(monitor.color565(155, 2, 237));
  monitor.setTextSize(2.8);
  monitor.println(F(">START GAME<"));
  monitor.setTextSize(1.5);
  monitor.setCursor(50, 160);
  monitor.println(F("Highest Score:"));
  monitor.setCursor(150, 160);
  monitor.println(eprom.read(PING_HS_ADDRESS));
};

void ping_drawblock() {
  // Hình vuông
  monitor.fillRect(13, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(0, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(13, 290, 11, 11, monitor.color565(237, 5, 5));
  // Hình chữ nhật
  monitor.fillRect(117, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(117, 290, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(117, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(117, 264, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(117, 251, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(117, 238, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(117, 225, 11, 11, monitor.color565(13, 240, 10));
  monitor.fillRect(117, 212, 11, 11, monitor.color565(13, 240, 10));
  // Chữ T
  monitor.fillRect(39, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(26, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(52, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(39, 290, 11, 11, monitor.color565(237, 5, 5));
  // Dẫu ngã
  monitor.fillRect(26, 290, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(26, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(39, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(39, 264, 11, 11, monitor.color565(222, 97, 2));
  // Hình chữ nhật
  monitor.fillRect(52, 290, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(52, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(52, 264, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(52, 251, 11, 11, monitor.color565(252, 248, 3));
  // Hình chữ L
  monitor.fillRect(65, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(78, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(91, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(65, 290, 11, 11, monitor.color565(237, 5, 5));
  // Hình chữ L ngược
  monitor.fillRect(104, 303, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(104, 290, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(91, 290, 11, 11, monitor.color565(237, 5, 5));
  monitor.fillRect(78, 290, 11, 11, monitor.color565(237, 5, 5));
  // Chữ T
  monitor.fillRect(65, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(65, 264, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(65, 251, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(65, 238, 11, 11, monitor.color565(252, 248, 3));
  // Khối vuông
  monitor.fillRect(78, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(91, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(78, 264, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(91, 264, 11, 11, monitor.color565(222, 97, 2));
  // Khối dọc
  monitor.fillRect(104, 277, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(104, 264, 11, 11, monitor.color565(222, 97, 2));
  monitor.fillRect(104, 251, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(104, 238, 11, 11, monitor.color565(252, 248, 3));
  // Chữ L
  monitor.fillRect(104, 225, 11, 11, monitor.color565(13, 240, 10));
  monitor.fillRect(91, 225, 11, 11, monitor.color565(13, 240, 10));
  monitor.fillRect(91, 238, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(91, 251, 11, 11, monitor.color565(252, 248, 3));
  // Khoi nho
  monitor.fillRect(117, 199, 11, 11, monitor.color565(10, 156, 240));
  monitor.fillRect(104, 212, 11, 11, monitor.color565(13, 240, 10));
  monitor.fillRect(78, 238, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(78, 251, 11, 11, monitor.color565(252, 248, 3));
  monitor.fillRect(78, 225, 11, 11, monitor.color565(13, 240, 10));
  monitor.fillRect(91, 212, 11, 11, monitor.color565(13, 240, 10));
  monitor.fillRect(104, 199, 11, 11, monitor.color565(10, 156, 240));
  monitor.fillRect(117, 186, 11, 11, monitor.color565(10, 156, 240));
};

// In ra cây
void drawtree()
{
  monitor.fillRect(150, 303, 11, 11, monitor.color565(56, 44, 8));
  monitor.fillRect(163, 303, 11, 11, monitor.color565(56, 44, 8));
  monitor.fillRect(176, 303, 11, 11, monitor.color565(56, 44, 8));
  monitor.fillRect(189, 303, 11, 11, monitor.color565(56, 44, 8));
  monitor.fillRect(202, 303, 11, 11, monitor.color565(56, 44, 8));

  monitor.fillRect(163, 290, 11, 11, monitor.color565(6, 56, 6));
  monitor.fillRect(176, 290, 11, 11, monitor.color565(6, 56, 6));
  monitor.fillRect(189, 290, 11, 11, monitor.color565(6, 56, 6));

  monitor.fillRect(176, 277, 11, 11, monitor.color565(92, 76, 27));
  monitor.fillRect(176, 264, 11, 11, monitor.color565(92, 76, 27));

  monitor.fillRect(150, 251, 11, 11, monitor.color565(26, 150, 9));
  monitor.fillRect(163, 251, 11, 11, monitor.color565(26, 150, 9));
  monitor.fillRect(176, 251, 11, 11, monitor.color565(26, 150, 9));
  monitor.fillRect(189, 251, 11, 11, monitor.color565(26, 150, 9));
  monitor.fillRect(202, 251, 11, 11, monitor.color565(26, 150, 9));

  monitor.fillRect(163, 238, 11, 11, monitor.color565(26, 150, 9));
  monitor.fillRect(176, 238, 11, 11, monitor.color565(26, 150, 9));
  monitor.fillRect(189, 238, 11, 11, monitor.color565(26, 150, 9));

  monitor.fillRect(176, 225, 11, 11, monitor.color565(26, 150, 9));
}

void ping_drawStartScreen() {
  monitor.fillScreen(monitor.color565(3, 1, 28));
  ping_drawtitle();
  ping_drawtext();
  ping_drawblock();
  drawtree();
  // drawBackRound();
};
#endif