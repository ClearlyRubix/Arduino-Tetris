void initDisplay() {
  // draw grid and first shape
  for (int x = 0; x < AREAWIDTH; x++) {
    for (int y = 0; y < AREAHEIGHT; y++) {
      if (playArea[x][y] == 2 || playArea[x][y] == 3) {
        drawBlock(x, y, TFT_WHITE);
      } else if (playArea[x][y] == 0) {
        tft.drawRect(320 - x * BLOCKWIDTH - BLOCKWIDTH, y * BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, TFT_LIGHTGREY);
      }
    }
  }

  tft.drawPixel(0, 0, TFT_GREEN);

  // initialize stored area
  tft.setRotation(2);  // needed to rotate text
  tft.drawRect(320 - 120, 0, 120, 120, TFT_DARKGREY);
  tft.setTextColor(TFT_WHITE);
  tft.drawCentreString("STORED", 320 - 60, 10, 1);
  tft.setRotation(4);

  // update next area
  tft.setRotation(2);  // needed to rotate text
  tft.drawRect(320 - 120, 120, 120, 120, TFT_DARKGREY);
  tft.setTextColor(TFT_WHITE);
  tft.drawCentreString("NEXT", 320 - 60, 130, 1);
  tft.setRotation(4);
}

void drawBlock(int x, int y, uint32_t color) {
  tft.fillRect(320 - x * BLOCKWIDTH - BLOCKWIDTH, y * BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
}

void clearBlock(int x, int y) {
  tft.fillRect(320 - x * BLOCKWIDTH - BLOCKWIDTH, y * BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, TFT_BLACK);
  tft.drawRect(320 - x * BLOCKWIDTH - BLOCKWIDTH, y * BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, TFT_LIGHTGREY);
}

void generalDrawShape(int oX, int oY, int shape, uint32_t color) {
  switch (shape) {
    case 0:  // Square
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
    case 1:  // I
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + 2 * BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
    case 2:  // S
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
    case 3:  // Z
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY  + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
    case 4:  // L
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
    case 5:  // J
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
    case 6:  // T
      tft.fillRect(oX, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX, oY + BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX + BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      tft.fillRect(oX - BLOCKWIDTH, oY, BLOCKWIDTH, BLOCKHEIGHT, color);
      break;
  }
}

void updateStoredBlockArea() {
  int oX = 40;
  int oY = 480 - 80;
  generalDrawShape(oX, oY, storedBlock,TFT_YELLOW);
}

void updateNextBlockArea() {
  int oX = 40;
  int oY = 480 - 80 - 120;
  generalDrawShape(oX, oY, nextBlock,TFT_YELLOW);
}

void update7Segment() {

}