void initDisplay() {
  for (int x = 0; x < AREAWIDTH; x++) {
    for (int y = 0; y < AREAHEIGHT; y++) {
      if (playArea[x][y] == 2 || playArea[x][y] == 3) {
        drawBlock(x, y, TFT_WHITE);
      }
    }
  }
}

void drawBlock(int x,int y, uint32_t color) {
    tft.fillRect(320-x*BLOCKWIDTH-16,y*BLOCKHEIGHT,BLOCKWIDTH,BLOCKHEIGHT, color);

}

void clearBlock(int x, int y) {
  tft.fillRect(320-x*BLOCKWIDTH-16,y*BLOCKHEIGHT,BLOCKWIDTH,BLOCKHEIGHT, TFT_BLACK);
}