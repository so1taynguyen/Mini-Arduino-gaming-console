#ifndef TETRIS_h
#define TETRIS_h

int tetris_grid[200];
int tetris_pos;
int tetris_pcambio = 0;
int tetris_pieza;
int tetris_rot = 0;
int fila; 
int fila2; 
int fila3;
int antfila;
int nx = 45;
int ny = 41;

int tetris_highscore;
int tetris_score = 0;

void tetris_gameplay() {
  int tetris_x = tetris_pos % 10;
  int tetris_y = (tetris_pos - tetris_x) / 10;

  if (tetris_pcambio) {
    tetris_pieza = random(0, 4);
    tetris_pcambio = 0;
    tetris_rot = 0; 

    do {
      if (tetris_grid[fila]==1 && tetris_grid[fila+2]==1 && tetris_grid[fila+3]==1 && tetris_grid[fila+4]==1 && tetris_grid[fila+5]==1 && tetris_grid[fila+6]==1 && tetris_grid[fila+7]==1 && tetris_grid[fila+8]==1 && tetris_grid[fila+9]==1) {
        fila2 = ((fila / 10) * 15) - 15;
        antfila = fila;
        monitor.fillRect(nx, ny + fila2, 150, 15, BLACK);

        do {
          tetris_grid[fila] = 0;
          fila++;

        } while (fila < (antfila + 10));

        while (fila > 20) {
          fila = antfila - 10;
          antfila = fila;
          fila2 = ((fila / 10) * 15) - 15;
          monitor.fillRect(nx, ny + fila2, 150, 15, BLACK);

          do {
            if (tetris_grid[fila]) {
              tetris_grid[fila] = 0;
              tetris_grid[fila + 10] = 1;
              fila3 = ((fila % 10) * 15);
              monitor.fillRect(nx + fila3, ny + fila2 + 15, 15, 15, WHITE);
              monitor.drawRect(nx + fila3, ny + fila2 + 15, 15, 15, RED);  
            }
            fila++;
          } while (fila < (antfila + 10));
        }
      }
      else {
        fila +=10;
      }
    } while (fila < 190);

    if (fila >= 190) {
      fila = 0;
    }
  }
  
  if (tetris_pieza == 4) {
    tetris_pieza = random(0, 3);
  }

  // if (tetris_pieza == 0) {
  //   monitor.fillRect(nx + tetris_x * 15, tetris_y * 15 + ny, 30, 30, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 30, 30, RED);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  // }
  
  // if (tetris_pieza == 1 && tetris_rot == 0) {
  //   monitor.fillRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 60, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 60, RED);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 30, 15, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 45, 15, 15, RED);
  // }

  // if (tetris_pieza == 1 && tetris_rot == 1) {
  //   monitor.fillRect(nx + tetris_x * 15, tetris_y * 15 + ny, 60, 15, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 60, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 30, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 45, (tetris_y * 15 + ny), 15, 15, RED);
  // }
  // if (tetris_pieza == 2 && tetris_rot == 0) {
  //   monitor.fillRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 45, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 45, RED);
  //   monitor.fillRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 30, 15, 15, WHITE);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 30, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15), (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15), (tetris_y * 15 + ny) + 15, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15), (tetris_y * 15 + ny) + 30, 15, 15, RED);
  // }
  // if (tetris_pieza == 2 && tetris_rot == 1) {
  //   monitor.fillRect(nx + tetris_x * 15, tetris_y * 15 + ny, 45, 15, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 45, 15, RED);
  //   monitor.fillRect((nx + tetris_x * 15) + 30, (tetris_y * 15 + ny) - 15, 15, 15, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 30, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 30, (tetris_y * 15 + ny) - 15, 15, 15, RED);
  // }
  // if (tetris_pieza == 2 && tetris_rot == 2) {
  //   monitor.fillRect((nx + tetris_x * 15), tetris_y * 15 + ny, 15, 15, WHITE);
  //   monitor.drawRect((nx + tetris_x * 15), tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.fillRect((nx + tetris_x * 15) + 15, tetris_y * 15 + ny, 15, 45, WHITE);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, tetris_y * 15 + ny, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 30, 15, 15, RED);
  // }
  // if (tetris_pieza == 2 && tetris_rot == 3) {
  //   monitor.fillRect(nx + tetris_x * 15, tetris_y * 15 + ny, 45, 15, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, tetris_y * 15 + ny, 45, 15, RED);
  //   monitor.fillRect((nx + tetris_x * 15), (tetris_y * 15 + ny) + 15, 15, 15, WHITE);
  //   monitor.drawRect((nx + tetris_x * 15), (tetris_y * 15 + ny) + 15, 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15), (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 30, (tetris_y * 15 + ny), 15, 15, RED);
  // }
  // if (tetris_pieza == 3 && tetris_rot == 0) {
  //   monitor.fillRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 15, 15, 30, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 15, 15, 30, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny) + 30, 15, 15, RED);
  //   monitor.fillRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny), 15, 30, WHITE);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny), 15, 30, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  // }
  // if (tetris_pieza == 3 && tetris_rot == 1) {
  //   monitor.fillRect(nx + tetris_x * 15, (tetris_y * 15 + ny), 30, 15, WHITE);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny), 30, 15, RED);
  //   monitor.drawRect(nx + tetris_x * 15, (tetris_y * 15 + ny), 15, 15, RED);
  //   monitor.fillRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 15, 30, 15, WHITE);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 15, 30, 15, RED);
  //   monitor.drawRect((nx + tetris_x * 15) + 15, (tetris_y * 15 + ny) + 15, 15, 15, RED);
  // }
}

#endif