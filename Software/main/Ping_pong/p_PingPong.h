#ifndef PingPong_h
#define PingPong_h

// Constants
const int PADDING_X = 2;
const int PADDING_Y = 2;
const int BRICK_COLS = 4;
const int BRICK_ROWS = 4;

// Declare the brick arrays
extern bool bricks[BRICK_ROWS][BRICK_COLS];
extern uint16_t brickColors[BRICK_ROWS][BRICK_COLS];

//Set up vi tri hien tai cua PONG
int ping_x = 0;
int ping_y = 0;

int ping_xDir = 1;
int ping_yDir = 1;

int pongW = monitor.width() / 25;
int pongH = monitor.height() / 25;

int ping_lastX = ping_x;
int ping_lastY = ping_y;

//Toa do thanh chan
int paddleH;
int paddleX;
int paddleY;
int paddleW;

bool ping_gameOn = false;
bool ping_gameOver = false;

int ping_score = 0;
int ping_highest_score;

//Kich thuoc ngang cua vien gach
const int BRICK_WIDTH = ((monitor.width() - (PADDING_X * (BRICK_COLS + 1))) / BRICK_COLS) / 4;
//Kich thuoc doc cua vien gach
const int BRICK_HEIGHT = ((monitor.height() - (PADDING_Y * (BRICK_ROWS + 1))) / BRICK_ROWS);
bool bricks[BRICK_ROWS][BRICK_COLS];
uint16_t brickColors[BRICK_ROWS][BRICK_COLS];
//Thiet ke mot thu vien mau de random
const uint16_t colorLibrary[] = 
{
  ILI9341_RED,
  ILI9341_GREEN,
  ILI9341_BLUE,
  ILI9341_YELLOW,
  ILI9341_CYAN,
  ILI9341_MAGENTA,
  ILI9341_ORANGE,
  ILI9341_PURPLE,
  ILI9341_PINK
};

const int colorLibrarySize = sizeof(colorLibrary) / sizeof(colorLibrary[0]);
//Ham de lay mau ngau nhien tu thu vien tao san

uint16_t getRandomColor()
{
  return colorLibrary[random(0, colorLibrarySize)];
}

bool isin(int pX, int pY, int padX, int padY, int padW, int padH)
{
  //Kiem tra toa do pX va pY co hop le khong
  return pX > padX && pX <= padX + padW && pY >= padY && pY <= padY + padH;
}

void resetPong()
{
  //Tinh toan vi tri ban dau cua vien bi o khoang giua man hinh
  ping_x = (monitor.width() - pongW) / 2;
  ping_y = (monitor.height() - pongH) / 2;
  //Cai dat huong di chuyen cua vien bi, va so luong pixel ma vien bi di chuyen qua
  ping_xDir = 4;
  ping_yDir = 4;
  //Cap nhat kich thuoc vien bi
  pongW = monitor.width() / 25;
  pongH = monitor.height() / 25;
  //Luu lai vi tri ban dau duoc tinh toan cua vien bi
  ping_lastX = ping_x;
  ping_lastY = ping_y;
}

void resetPadle()
{
  //Thiet lap lai chieu cao cua thanh chan bang 4 lan chieu cao cua vien bi PONG
  paddleH = pongH * 4;
  //Thiet lap vi tri cua thanh chan sao cho nam o ben phai man hinh, cach le phai
  //1 khoang bang 3 lan chieu rong cua vien PONG
  paddleX = monitor.width() - pongW * 3;
  //Thiet lap vi tri ping_y cua thanh chan sao cho nam o giua chieu cao cua man hinh
  //lui vao 1 nua chieu cao cua thanh chan
  paddleY = monitor.height() / 2 - pongH / 2;
  //Thiet lap chieu rong cua thanh chan bang chieu rong cua vien PONG
  paddleW = pongW;
}

void resetBricks()
{
  //Duyet qua tung hang va cot cua ma tran gach
  for(int row = 0; row < BRICK_ROWS; row++)
  {
    for(int col = 0; col < BRICK_COLS; col++)
    {
      //Thiet lap gia tri cua o trong ma tran gach la true, tuc la gach dang ton tai
      bricks[row][col] = true;
      //Gan ngau nhien mau tu thu vien duoc tao san o tren
      brickColors[row][col] = getRandomColor();
    }
  }
}

//Ham kiem tra neu nhu tat ca vien gach bien mat het
bool allBricksCleared()
{
  for(int row = 0; row < BRICK_ROWS; row++)
  {
    for(int col = 0; col < BRICK_COLS; col++)
    {
      if(bricks[row][col])
      {
        return false;
      }
    }
  }
  return true;
}

void ping_resetGame()
{
  //Dat lai diem so ve 0
  ping_score = 0;
  //Dat lai PONG ve vi tri ban dau
  resetPong();
  //Dat lai thanh chan o vi tri ban dau
  resetPadle();
  //Set up lai hang gach
  resetBricks();
  monitor.fillScreen(ILI9341_BLACK);
}

void ping_drawText(char *text, int posX, int posY, unsigned color)
{
  // Đặt vị trí bắt đầu vẽ văn bản
  monitor.setCursor(posX, posY);
  // Đặt màu cho văn bản
  monitor.setTextColor(color);
  // Đặt kích thước cho văn bản
  monitor.setTextSize(2);
  // Vẽ văn bản lên màn hình
  monitor.println(text);
}

void ping_drawScore()
{
  // Khai báo mảng char để lưu điểm số dưới dạng chuỗi
  char buff[7];
  // Tính độ rộng của văn bản dựa trên số lượng ký tự của chuỗi điểm số
  int textWidth = 6 * 2 * strlen(buff);
  // Kiểm tra điểm số đã được cập nhật chưa
  if (ping_score > 0)
  {
    // Nếu điểm số > 0, chuyển điểm số trước đó thành chuỗi và vẽ nó trên màn hình
    itoa(ping_score - 1, buff, 10);
    int posXPrev = monitor.width() - (6 * 2 * strlen(buff));
    ping_drawText(buff, posXPrev, 0, ILI9341_BLACK);
  }
  // Chuyển điểm số hiện tại thành chuỗi và vẽ trên màn hình
  itoa(ping_score, buff, 10);
  int posX = monitor.width() - (6 * 2 * strlen(buff));
  ping_drawText(buff, posX, 0, ILI9341_BLUE);
}

void drawBricks()
{
  // Duyệt qua từng hàng của ma trận gạch
  for (int row = 0; row < BRICK_ROWS; row++)
  {
    // Duyệt qua từng cột của ma trận gạch
    for (int col = 0; col < BRICK_COLS; col++)
    {
      // Kiểm tra xem ô gạch có tồn tại không
      if (bricks[row][col])
      {
        // Tính toán tọa độ ping_x và ping_y của ô gạch trên màn hình
        int brickX = col * (BRICK_WIDTH + PADDING_X) + PADDING_X;
        int brickY = row * (BRICK_HEIGHT + PADDING_Y) + PADDING_Y;
        // Vẽ ô gạch lên màn hình
        monitor.fillRect(brickX, brickY, BRICK_WIDTH, BRICK_HEIGHT, brickColors[row][col]);
      }
    }
  }
}

void drawPaddle()
{
  monitor.fillRect(paddleX, paddleY, paddleW, paddleH, ILI9341_MAGENTA);
}

void drawPong()
{
  //Xoa PONG o vi tri truoc do bang cach ve mot hinh chu nhat mau den de thay vao
  monitor.fillRect(ping_lastX, ping_lastY, pongW, pongH, ILI9341_BLACK);
  //Ve PONG o vi tri moi bang cach ve lai no 
  monitor.fillRect(ping_x, ping_y, pongW, pongH, ILI9341_MAGENTA);
  //Cap nhat vi tri truoc do cua PONG
  ping_lastX = ping_x;
  ping_lastY = ping_y;
  //Tinh toan vi tri moi cua PONG dua tren huong di chuyen
  int xTry = ping_x + ping_xDir;
  int yTry = ping_y + ping_yDir;
  //Kiem tra va cham voi thanh chan (paddle) hoac bien trai hoac bien phai
  if(xTry + pongW < paddleX && xTry > 0)
  {
    ping_x = xTry;
  }
  else
  {
    if(xTry <= 0)
    {
      //Neu PONG cham bien trai dao huong di chuyen theo truc ping_x va di chuyen PONG
      ping_xDir *= -1;
      ping_x += ping_xDir;
    }
    else if (yTry + pongH >= paddleY - 2 && yTry <= paddleY + paddleH + 2)
    {
      //Neu PONG cham thanh chan, dao huong di chuyen theo truc ping_x va di chuyen PONG
      ping_xDir *= -1;
      ping_x += ping_xDir;
    }
    else 
    {
      //Neu PONG khong cham bien phai hoac khong cham thanh chan, ket thuc tro choi
      ping_gameOn = false;
      ping_gameOver = true;

      if (ping_score > ping_highest_score) {
        eprom.write(PING_HS_ADDRESS, ping_score);
      }
      //Ve chu "Game Over" o trung tam man hinh
      ping_drawText("Game Over", monitor.width() / 2 - 43, monitor.height() / 2 - 10, ILI9341_DARKGREY);
      monitor.setCursor(monitor.width() / 2 - 43, 285);
      monitor.setTextSize(1);
      monitor.print("<press enter to continue>");
      monitor.setCursor(monitor.width() / 2 - 35, 300);
      monitor.print("<press down to exit>");
    }
  }
  //Kiem tra va cham voi bien tren va duoi cua man hinh
  if(yTry + pongH < monitor.height() && yTry > 0)
  {
    ping_y = yTry;
  }
  else
  {
    //Neu PONG cham bien tren hoac duoi, dao huong di chuyen theo truc ping_y va di chuyen PONG
    ping_yDir *= -1;
    ping_y += ping_yDir;
  }
  //Kiem tra va cham voi cac vien gach va cap nhat diem so
  for(int row = 0; row < BRICK_ROWS; row++)
  {
    for(int col = 0; col < BRICK_COLS; col++)
    {
      if(bricks[row][col])
      {
        int brickX = col * (BRICK_WIDTH + PADDING_X) + PADDING_X;
        int brickY = row * (BRICK_HEIGHT + PADDING_Y) + PADDING_Y;
        if(isin(ping_x, ping_y, brickX, brickY, BRICK_WIDTH, BRICK_HEIGHT))
        {
          //Neu PONG va cham voi vien gach, ve lai vien gach mau den de bien mat
          monitor.fillRect(brickX, brickY, BRICK_WIDTH, BRICK_HEIGHT, ILI9341_BLACK);
          //Danh dau vien gach da bi pha huy
          bricks[row][col] = false;
          //Dao huong di chuyen theo truc ping_y cua PONG va cap nhat diem so
          ping_yDir *= 1;
          ping_xDir *= -1;
          ++ping_score;
          //Ve diem so moi
          ping_drawScore();
          break;
        }
      }
    }
  }
  //Kiem tra neu nhu tat ca BRICK deu bien mat
  if (allBricksCleared())
  {
    resetPong();
    resetBricks();
    drawBricks();
  }
}

void drawPongOld()
{
  // Lấy chiều rộng và chiều cao của màn hình
  int w = monitor.width();
  int h = monitor.height();
  // Tính toán tọa độ ping_x và ping_y của điểm giữa màn hình
  int cx = w / 2 - 1;
  int cy = h / 2 - 1;
  // Vẽ một hình chữ nhật có màu ILI9341_MAGENTA tại điểm giữa màn hình
  // với chiều rộng và chiều cao được tính dựa trên kích thước màn hình
  monitor.fillRect(cx, cy, w / 25, w / 25, ILI9341_MAGENTA);
}

void movePaddle(int direction)
{
  //Di chuyen thanh chan len hoac xuong trong pham vi man hinh, dieu chinh toc do
  int newPaddleY = paddleY + direction * 10;
  //Kiem tra xem thanh chan co nam trong pham vi man hinh khong?
  if (newPaddleY >= newPaddleY + paddleH <= monitor.height())
  {
    //Xoa vi tri hien tai cua thanh chan 
    monitor.fillRect(paddleX, paddleY, paddleW, paddleH, ILI9341_BLACK);
    //Cap nhat vi tri moi cua thanh chan
    paddleY = newPaddleY;
    //Ve lai thanh chan o vi tri moi
    drawPaddle();
  }
}

#endif