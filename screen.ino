void initDisplay() {
  // draw grid and first shape
  for (int x = 0; x < AREAWIDTH; x++) {
    for (int y = 0; y < AREAHEIGHT; y++) {
      if (playArea[x][y] == 2 || playArea[x][y] == 3) {
        drawBlock(x, y, TFT_WHITE);
      } else if (playArea[x][y] == 0) {
        tft.drawRect(320-x*BLOCKWIDTH-BLOCKWIDTH,y*BLOCKHEIGHT,BLOCKWIDTH,BLOCKHEIGHT, TFT_LIGHTGREY);
      }
    }
  }

  // initialize stored area
  tft.drawRect(0,480-120, 120, 120, TFT_DARKGREY);
  tft.setTextColor(TFT_WHITE);
  tft.drawCentreString("STORED", 60, 480-60, 1);
  

  // update next area
}

void drawBlock(int x,int y, uint32_t color) {
    tft.fillRect(320-x*BLOCKWIDTH-BLOCKWIDTH,y*BLOCKHEIGHT,BLOCKWIDTH,BLOCKHEIGHT, color);

}

void clearBlock(int x, int y) {
  tft.fillRect(320-x*BLOCKWIDTH-BLOCKWIDTH,y*BLOCKHEIGHT,BLOCKWIDTH,BLOCKHEIGHT, TFT_BLACK);
  tft.drawRect(320-x*BLOCKWIDTH-BLOCKWIDTH,y*BLOCKHEIGHT,BLOCKWIDTH,BLOCKHEIGHT, TFT_LIGHTGREY);
}

void updateStoredBlockArea() {
  
}

void update7Segment() {

}