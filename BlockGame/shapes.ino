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

// void drawIHorizontal(int x, int y)  {
//   playArea[x][y] = 2;
//   playArea[x+1][y] = 2;
//   playArea[x+2][y] = 2;
//   playArea[x+3][y] = 2;
// }

void drawS(int x, int y) {
  playArea[x][y] = 3;
  playArea[x - 1][y] = 2;
  playArea[x][y + 1] = 2;
  playArea[x + 1][y + 1] = 2;
}

// void drawSInvert(int x, int y)  {
//   playArea[x][y] = 2;
//   playArea[x][y+1] = 2;
//   playArea[x-1][y+1] = 2;
//   playArea[x-1][y+2] = 2;
// }

void drawZ(int x, int y) {
  playArea[x][y + 1] = 2;
  playArea[x + 1][y] = 2;
  playArea[x][y] = 3;
  playArea[x - 1][y + 1] = 2;
}

// void drawZInvert(int x, int y) {
//   playArea[x][y] = 2;
//   playArea[x][y+1] = 2;
//   playArea[x+1][y+1] = 2;
//   playArea[x+1][y+2] = 2;
// }

void drawL(int x, int y) {
  playArea[x-1][y] = 2;
  playArea[x][y] = 3;
  playArea[x + 1][y] = 2;
  playArea[x + 1][y + 1] = 2;
}

// void drawL90(int x, int y) {
//   playArea[x][y] = 2;
//   playArea[x+1][y] = 2;
//   playArea[x+1][y-1] = 2;
//   playArea[x+1][y-2] = 2;
// }

// void drawL180(int x, int y) {
//   playArea[x][y] = 2;
//   playArea[x][y-1] = 2;
//   playArea[x+1][y] = 2;
//   playArea[x+2][y] = 2;
// }

// void drawL270(int x, int y) {
//   playArea[x][y] = 2;
//   playArea[x+1][y] = 2;
//   playArea[x][y+1] = 2;
//   playArea[x][y+2] = 2;
// }


void drawJ(int x, int y) {
  playArea[x + 1][y] = 2;
  playArea[x - 1][y + 1] = 2;
  playArea[x][y] = 3;
  playArea[x - 1][y] = 2;
}

// void drawJ90(int x, int y) {
//     playArea[x][y] = 2;
//     playArea[x+1][y] = 2;
//     playArea[x+1][y+1] = 2;
//     playArea[x+1][y+2] = 2;
// }

// void drawJ180(int x, int y) {
//     playArea[x][y] = 2;
//     playArea[x+1][y] = 2;
//     playArea[x+2][y] = 2;
//     playArea[x+2][y-1] = 2;
// }

// void drawJ270(int x, int y) {
//     playArea[x][y] = 2;
//     playArea[x][y+1] = 2;
//     playArea[x][y+2] = 2;
//     playArea[x+1][y+2] = 2;
// }

void drawT(int x, int y) {
  playArea[x][y] = 3;
  playArea[x][y + 1] = 2;
  playArea[x + 1][y] = 2;
  playArea[x - 1][y] = 2;
}

// void drawT90(int x, int y) {
//     playArea[x][y] = 2;
//     playArea[x+1][y] = 2;
//     playArea[x][y+1] = 2;
//     playArea[x][y-1] = 2;
// }

// void drawT180(int x, int y) {
//     playArea[x][y] = 2;
//     playArea[x+1][y] = 2;
//     playArea[x-1][y] = 2;
//     playArea[x][y-1] = 2;
// }

// void drawT270(int x, int y) {
//     playArea[x][y] = 2;
//     playArea[x][y+1] = 2;
//     playArea[x][y-1] = 2;
//     playArea[x-1][y] = 2;
// }