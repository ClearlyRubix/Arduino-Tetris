void initStartMenu() {
  if (!startMenu) { return; }  // just in case this runs while menu not active
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);

  ////////
  //LOGO//
  ////////

  // BG
  tft.fillRect(29, 15, 255, 59, TFT_DARKGREY);

  // Black & White Rim
  tft.drawRect(2, 12, 2, 8, TFT_BLACK);
  tft.drawRect(26, 13, 8, 8, TFT_BLACK);
  tft.drawRect(26, 12, 261, 65, TFT_WHITE);
  tft.drawRect(25, 11, 263, 67, TFT_WHITE);

  // Top Left Square
  tft.drawRect(35, 13, 2, 8, TFT_BLACK);
  tft.drawRect(27, 21, 8, 2, TFT_BLACK);

  tft.fillRect(25, 11, 10, 10, TFT_WHITE);

  // Top Right
  tft.drawRect(276, 13, 2, 8, TFT_BLACK);
  tft.drawRect(276, 21, 8, 2, TFT_BLACK);

  tft.fillRect(278, 11, 10, 10, TFT_WHITE);

  // Bottom Left
  tft.drawRect(35, 66, 2, 8, TFT_BLACK);
  tft.drawRect(27, 66, 8, 2, TFT_BLACK);

  tft.fillRect(25, 68, 10, 10, TFT_WHITE);

  // Bottom Right
  tft.drawRect(276, 66, 2, 8, TFT_BLACK);
  tft.drawRect(276, 66, 8, 2, TFT_BLACK);

  tft.fillRect(278, 68, 10, 10, TFT_WHITE);

  // logo text
  tft.setTextSize(32);
  tft.setTextColor(TFT_BLACK);
  tft.drawCentreString("TETRIS", 162, 22, 1);
  tft.setTextColor(TFT_WHITE);
  tft.drawCentreString("TETRIS", 160, 20, 1);

  //////////////
  //HIGH SCORE//
  //////////////

  // BG (79, 120, 159, 54)
  tft.fillRect(71, 112, 175, 70, 0x4a49);
  tft.drawRect(70, 111, 177, 72, TFT_BLUE);
  tft.drawRect(69, 110, 179, 74, TFT_BLUE);
  tft.drawRect(68, 109, 181, 76, TFT_WHITE);
  tft.drawRect(67, 108, 183, 78, TFT_WHITE);

  // Text
  tft.setTextSize(3);
  tft.drawCentreString("HIGHSCORE", 160, 120, 1);
  tft.setTextSize(2);
  tft.drawCentreString("2500", 160, 160, 1);

  /////////
  //START//
  /////////

  tft.drawCentreString("PRESS CENTRE", 160, 270, 1);
  tft.drawCentreString("TO START", 160, 300, 1);
}


bool blinkyStart = true;
void updateStartMenu() {
  if (!startMenu) { return; }  // just in case this runs while menu not active
  // Blink Start Text
  time = millis();
  if ((time - oldTime) >= 500) {
    if (blinkyStart) {
      tft.setTextColor(0x0497);
      blinkyStart = false;
    } else {
      tft.setTextColor(TFT_WHITE);
      blinkyStart = true;
    }
    tft.drawCentreString("PRESS CENTRE", 160, 270, 1);
    tft.drawCentreString("TO START", 160, 300, 1);
    oldTime = time;
  }

  // Centre Button
  if (digitalRead(rotateButton) == LOW) {
    startMenu = false;
    startMenuFirstLoop = true;
    game = true;
    gameFirstLoop = true;
    loseMenu = false;
    loseMenuFirstLoop = false;
  }
}

void initLossMenu() {
}

void updateLossMenu() {
}