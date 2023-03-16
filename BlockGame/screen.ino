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

void updateStoredBlockArea() {
  Serial.println(storedBlock);
  int oX = 60;
  int oY = 320;
  switch (storedBlock) {
    case 0:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
    case 1:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
    case 2:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
    case 3:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
    case 4:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
    case 5:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
    case 6:
      drawBlock(oX, oY, TFT_YELLOW);
      break;
  }
}

void update7Segment() {
}