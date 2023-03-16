void drawSquare(int x, int y) {
  playArea[x][y] = 3;
  playArea[x][y + 1] = 2;
  playArea[x + 1][y] = 2;
  playArea[x + 1][y + 1] = 2;
}

void drawI(int x, int y) {
  playArea[x][y] = 3;
  playArea[x-1][y] = 2;
  playArea[x+1][y] = 2;
  playArea[x+2][y] = 2;
}

void drawS(int x, int y) {
  playArea[x][y] = 3;
  playArea[x - 1][y] = 2;
  playArea[x][y + 1] = 2;
  playArea[x + 1][y + 1] = 2;
}

void drawZ(int x, int y) {
  playArea[x][y + 1] = 2;
  playArea[x + 1][y] = 2;
  playArea[x][y] = 3;
  playArea[x - 1][y + 1] = 2;
}

void drawL(int x, int y) {
  playArea[x-1][y] = 2;
  playArea[x][y] = 3;
  playArea[x + 1][y] = 2;
  playArea[x + 1][y + 1] = 2;
}

void drawJ(int x, int y) {
  playArea[x + 1][y] = 2;
  playArea[x - 1][y + 1] = 2;
  playArea[x][y] = 3;
  playArea[x - 1][y] = 2;
}

void drawT(int x, int y) {
  playArea[x][y] = 3;
  playArea[x][y + 1] = 2;
  playArea[x + 1][y] = 2;
  playArea[x - 1][y] = 2;
}