void initStartMenu() {
  if (!startMenu) { return; }  // just in case this runs while menu not active
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);

  ////////
  //LOGO//
  ////////

  // BG
  tft.fillRect(29, 15, 255, 59, TFT_DARKGREY);

  // White Rim
  tft.drawRect(26, 12, 261, 65, TFT_WHITE);
  tft.drawRect(25, 11, 263, 67, TFT_WHITE);

  // Top Left Square
  tft.drawRect(35, 15, 2, 8, TFT_BLACK);
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

  // BG
  tft.fillRect(71, 112, 175, 70, 0x4a49);
  tft.drawRect(70, 111, 177, 72, TFT_BLUE);
  tft.drawRect(69, 110, 179, 74, TFT_BLUE);
  tft.drawRect(68, 109, 181, 76, TFT_WHITE);
  tft.drawRect(67, 108, 183, 78, TFT_WHITE);

  // Text
  tft.setTextSize(3);
  tft.drawCentreString("HIGHSCORE", 160, 120, 1);
  tft.setTextSize(2);
  tft.drawCentreString((String)highscore, 160, 160, 1);

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
    loseMenuFirstLoop = true;
  }
}

bool newHighscore = false;
void initLossMenu() {
  if (!loseMenu) { return; }  // just in case this runs while menu not active
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);

  /////////////
  //GAME OVER//
  /////////////

  // BG
  tft.fillRect(29, 15, 255, 117, TFT_DARKGREY);

  // White Rim
  tft.drawRect(26, 12, 261, 123, TFT_WHITE);
  tft.drawRect(25, 11, 263, 125, TFT_WHITE);

  // Top Left Square
  tft.drawRect(35, 15, 2, 8, TFT_BLACK);
  tft.drawRect(27, 21, 8, 2, TFT_BLACK);

  tft.fillRect(25, 11, 10, 10, TFT_WHITE);

  // Top Right
  tft.drawRect(276, 13, 2, 8, TFT_BLACK);
  tft.drawRect(276, 21, 8, 2, TFT_BLACK);

  tft.fillRect(278, 11, 10, 10, TFT_WHITE);

  // Bottom Left
  tft.drawRect(35, 124, 2, 8, TFT_BLACK);
  tft.drawRect(27, 124, 8, 2, TFT_BLACK);

  tft.fillRect(25, 126, 10, 10, TFT_WHITE);

  // Bottom Right
  tft.drawRect(276, 124, 2, 8, TFT_BLACK);
  tft.drawRect(276, 124, 8, 2, TFT_BLACK);

  tft.fillRect(278, 126, 10, 10, TFT_WHITE);

  // logo text
  tft.setTextSize(32);
  tft.setTextColor(TFT_BLACK);
  tft.drawCentreString("GAME", 162, 22, 1);
  tft.drawCentreString("OVER", 162, 78, 1);
  tft.setTextColor(0x8800);
  tft.drawCentreString("GAME", 160, 20, 1);
  tft.drawCentreString("OVER", 160, 78, 1);

  if (score > highscore) {
    EEPROM.put(0, score);
    highscore = score;
    newHighscore = true;
    //////////////
    //HIGH SCORE//
    //////////////

    // BG
    tft.fillRect(71, 146, 175, 82, 0x4a49);
    tft.drawRect(70, 145, 177, 84, TFT_BLUE);
    tft.drawRect(69, 144, 179, 86, TFT_BLUE);
    tft.drawRect(68, 143, 181, 88, TFT_WHITE);
    tft.drawRect(67, 142, 183, 90, TFT_WHITE);

    // Text
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(3);
    tft.drawCentreString("NEW", 160, 154, 1);
    tft.drawCentreString("HIGHSCORE", 160, 180, 1);
    tft.setTextSize(2);
    tft.drawCentreString((String)highscore, 160, 210, 1);

    //////////////
    //YOUR SCORE//
    //////////////
    tft.drawCentreString("YOUR SCORE: " + (String)score, 160, 250, 1);

  } else {
    //////////////
    //HIGH SCORE//
    //////////////

    // BG
    tft.fillRect(71, 146, 175, 70, 0x4a49);
    tft.drawRect(70, 145, 177, 72, TFT_BLUE);
    tft.drawRect(69, 144, 179, 74, TFT_BLUE);
    tft.drawRect(68, 143, 181, 76, TFT_WHITE);
    tft.drawRect(67, 142, 183, 78, TFT_WHITE);

    // Text
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(3);
    tft.drawCentreString("HIGHSCORE", 160, 154, 1);
    tft.setTextSize(2);
    tft.drawCentreString((String)highscore, 160, 194, 1);

    //////////////
    //YOUR SCORE//
    //////////////
    tft.drawCentreString("YOUR SCORE: " + (String)score, 160, 250, 1);
  }



  //////////
  //RETURN//
  //////////

  tft.drawCentreString("PRESS CENTRE TO", 160, 300, 1);
  tft.drawCentreString("RETURN TO MENU", 160, 330, 1);
  
  
  // reset game values
  score = 0;
  clearPlayArea();
}

bool blinkyLoss = true;
bool blinkyHighscore = true;
void updateLossMenu() {
  if (!loseMenu) { return; }  // just in case this runs while menu not active
  // Blink Start Text
  time = millis();
  if ((time - oldTime) >= 500) {
    if (blinkyLoss) {
      tft.setTextColor(0x0497);
      blinkyLoss = false;
    } else {
      tft.setTextColor(TFT_WHITE);
      blinkyLoss = true;
    }
    tft.setTextSize(2);
    tft.drawCentreString("PRESS CENTRE TO", 160, 300, 1);
    tft.drawCentreString("RETURN TO MENU", 160, 330, 1);
    if (newHighscore) {
      if (blinkyHighscore) {
        tft.setTextColor(0xffc0);
        blinkyHighscore = false;
      } else {
        tft.setTextColor(0xf800);
        blinkyHighscore = true;
      }
      tft.setTextSize(3);
      tft.drawCentreString("NEW", 160, 154, 1);
      tft.drawCentreString("HIGHSCORE", 160, 180, 1);
    }
    oldTime = time;
  }

  if (newHighscore) {
  }

  // Centre Button
  if (digitalRead(rotateButton) == LOW) {
    startMenu = true;
    startMenuFirstLoop = true;
    game = false;
    gameFirstLoop = true;
    loseMenu = false;
    loseMenuFirstLoop = true;
  }
}