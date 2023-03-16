void printPlayArea() {
  // Serial.println("--------------");
  // for (int y = AREAHEIGHT - 1; y >= 0; y--) {
  //   for (int x = 0; x < AREAWIDTH; x++) {
  //     Serial.print(playArea[x][y]);
  //   }
  //   Serial.println();
  // }
  // Serial.println("--------------");
}

void clearPlayArea() {
  for (int y = AREAHEIGHT - 1; y >= 0; y--) {
    for (int x = 0; x < AREAWIDTH; x++) {
      if (playArea[x][y] == 1) {
        playArea[x][y] = 0;
      }
    }
  }
}

void lockShape(int oldX[3], int oldY[3], int oldCX, int oldCY) {
  for (int k = 0; k < 3; k++) {  // Lock Shape
    playArea[oldX[k]][oldY[k]] = 1;
    drawBlock(oldX[k], oldY[k], TFT_MAGENTA);  // draw Locked shape
  }
  // Lock Center
  playArea[oldCX][oldCY] = 1;
  drawBlock(oldCX, oldCY, TFT_ORANGE);  // draw Locked Center

  alreadyStoredThisTurn = false;  // unlock Store function

  checkClears();

  createBlock(getNextBlock(), startX, startY);
  genNextBlock();
}

void dropShape() {

  // arrays of xy coordinates
  int oldX[3];
  int oldY[3];
  int oldCX;
  int oldCY;

  // the coordinate pair we are saving
  int i = 0;

  // get x,y pairs that are 2's or 3's
  for (int x = 0; x < AREAWIDTH; x++) {
    for (int y = 0; y < AREAHEIGHT; y++)
      if (playArea[x][y] == 2) {
        oldX[i] = x;
        oldY[i] = y;
        i++;
      } else if (playArea[x][y] == 3) {
        oldCX = x;
        oldCY = y;
      }
  }

  // check next non center positions
  for (int j = 0; j < 3; j++) {
    if (playArea[oldX[j]][oldY[j] - 1] == 1 || oldY[j] - 1 < 0) {
      lockShape(oldX, oldY, oldCX, oldCY);
      return;
    }
  }

  // Check next center position
  if (playArea[oldCX][oldCY - 1] == 1 || oldCY - 1 < 0) {
    lockShape(oldX, oldY, oldCX, oldCY);
    return;
  }

  // after checking, move down
  // clear non centers
  for (int m = 0; m < 3; m++) {
    playArea[oldX[m]][oldY[m]] = 0;
    clearBlock(oldX[m], oldY[m]);  // Clear old position
  }
  // clear center
  playArea[oldCX][oldCY] = 0;
  clearBlock(oldCX, oldCY);  // Clear old position

  // draw non center
  for (int n = 0; n < 3; n++) {
    playArea[oldX[n]][oldY[n] - 1] = 2;
    drawBlock(oldX[n], oldY[n] - 1, TFT_WHITE);  // Draw new position
  }

  // draw center
  playArea[oldCX][oldCY - 1] = 3;
  drawBlock(oldCX, oldCY - 1, TFT_WHITE);  // Draw new position
}

void rotateShape() {                  // (x,y) -> (-y,x) CCW rotation
  if (currentBlock == 0) { return; }  // dont rotate if its square
  int xList[3];
  int yList[3];

  int newX[3];
  int newY[3];

  int centerX;
  int centerY;

  int i = 0;
  for (int x = 0; x < AREAWIDTH; x++) {
    for (int y = 0; y < AREAHEIGHT; y++) {
      if (playArea[x][y] == 3) {  // get rotation point
        centerX = x;
        centerY = y;
      } else if (playArea[x][y] == 2) {  // get other points
        xList[i] = x;
        yList[i] = y;
        i++;
      }
    }
  }
  // get new positions
  for (int j = 0; j < 3; j++) {
    newX[j] = (yList[j] - centerY) + centerX;
    newY[j] = -1 * (xList[j] - centerX) + centerY;
  }

  // check valid rotation
  for (int k = 0; k < 3; k++) {
    if (newX[k] < 0) {  // will rotate outside left boundary
      return;
    } else if (newX[k] > (AREAWIDTH - 1)) {  // will rotate outside right boundary
      return;
    } else if (playArea[newX[k]][newY[k]] == 1) {  // will rotate into another block
      return;
    }
  }

  for (int t = 0; t < 3; t++) {
    playArea[xList[t]][yList[t]] = 0;
    clearBlock(xList[t], yList[t]);  // Clear old positions
  }

  // perform rotation
  for (int l = 0; l < 3; l++) {
    playArea[newX[l]][newY[l]] = 2;
    drawBlock(newX[l], newY[l], TFT_GREEN);
  }
}

void translateShape(int t) {
  int xList[3];
  int yList[3];

  int newX[3];
  int newY[3];

  int centerX;
  int centerY;

  int i = 0;
  for (int x = 0; x < AREAWIDTH; x++) {
    for (int y = 0; y < AREAHEIGHT; y++) {
      if (playArea[x][y] == 3) {  // get center point
        centerX = x;
        centerY = y;
      } else if (playArea[x][y] == 2) {  // get other points
        xList[i] = x;
        yList[i] = y;
        i++;
      }
    }
  }

  // get new positions
  for (int j = 0; j < 3; j++) {
    newX[j] = xList[j] + t;
    newY[j] = yList[j];
  }

  // check valid translation
  for (int k = 0; k < 3; k++) {
    if (newX[k] < 0) {  // will translate outside left boundary
      return;
    } else if (newX[k] > (AREAWIDTH - 1)) {  // will translate outside right boundary
      return;
    } else if (playArea[newX[k]][newY[k]] == 1) {  // will translate into another block
      return;
    }
  }
  if ((centerX + t) < 0) {  // center will translate outside left
    return;
  } else if ((centerX + t) > (AREAWIDTH - 1)) {  // center will translate outside right
    return;
  } else if (playArea[(centerX + t)][centerY] == 1) {  // center wil ltranslate into another block
    return;
  }


  for (int p = 0; p < 3; p++) {
    playArea[xList[p]][yList[p]] = 0;
    clearBlock(xList[p], yList[p]);  // Clear old positions
  }

  playArea[centerX][centerY] = 0;
  clearBlock(centerX, centerY);  // Clear old center position



  // perform translation
  for (int l = 0; l < 3; l++) {
    playArea[newX[l]][newY[l]] = 2;
    drawBlock(newX[l], newY[l], TFT_WHITE);
  }
  // Center translation
  playArea[centerX + t][centerY] = 3;
  drawBlock(centerX + t, centerY, TFT_ORANGE);
}

void checkClears() {

  bool needMove = false;
  int rowsCleared = 0;
  // go through by row
  for (int y = 0; y < AREAHEIGHT; y++) { // each row
    int rowOnes = 0;
    for (int x = 0; x < AREAWIDTH; x++) { // check each block in row
      if (playArea[x][y] == 1) {  // if 1 is found add to total rowOnes
        rowOnes++;
      }
    }

    // if row is full, set to 0 and clear
    if (rowOnes == AREAWIDTH) {
      for (int i = 0; i < AREAWIDTH; i++) {
        playArea[i][y] = 0;
        clearBlock(i, y);
      }
      needMove = true;
      rowsCleared++; // update rows cleared
    }
    rowOnes = 0;
  }

  if (needMove) {
    // move all blocks down
    for (int x = 0; x < AREAWIDTH; x++) {
      for (int y = 0; y < AREAHEIGHT; y++) {
        if (playArea[x][y] == 1) {
          // clear old position
          clearBlock(x, y);
          playArea[x][y] = 0;
          drawBlock(x, (y - rowsCleared), TFT_MAGENTA);
          playArea[x][y - rowsCleared] = 1;
        }
      }
    }

    switch (rowsCleared) {
      case 1:
        score += 40;
        break;
      case 2:
        score += 100;
        break;
      case 3:
        score += 300;
        break;
      case 4:
        score += 1200;
        break;
    }

    rowsCleared = 0;
    needMove = false;
  }
}
