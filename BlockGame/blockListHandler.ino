void createBlock(int i, int x, int y) {
  currentBlock = i;
  switch (i) {
    case 0:
      drawSquare(x, y);
      break;
    case 1:
      drawI(x, y);
      break;

    case 2:
      drawS(x, y);
      break;

    case 3:
      drawZ(x, y);
      break;

    case 4:
      drawL(x, y);
      break;

    case 5:
      drawJ(x, y);
      break;

    case 6:
      drawT(x, y);
      break;
  }
}

int genNextBlock() {
  nextBlock = random(0, 7);
  return nextBlock;
}

int getNextBlock() {
  return nextBlock;
}

void storeBlock() {
  if (alreadyStoredThisTurn) {  // Don't do anything if you already swapped
    return;
  }
  if (storedBlock < 7 && storedBlock >= 0) {

    // if there is already a stored block
    alreadyStoredThisTurn = true;  // don't allow swap again
    // swap block variables
    storedBlock = currentBlock;
    currentBlock = tempStore;
    tempStore = storedBlock;

  } else {  // if stored block is empty

    alreadyStoredThisTurn = true;  // don't allow swap again
    // store current block and use nextBlock instead
    storedBlock = currentBlock;
    currentBlock = nextBlock;
    tempStore = storedBlock;
    genNextBlock();
  }
  // Get current shape
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
  // clear current block
  for (int m = 0; m < 3; m++) {
    playArea[oldX[m]][oldY[m]] = 0;
    clearBlock(oldX[m], oldY[m]);  // Clear old position
  }
  // clear center
  playArea[oldCX][oldCY] = 0;
  clearBlock(oldCX, oldCY);  // Clear old position
  // create new block
  createBlock(currentBlock, startX, startY);\
  
  // update stored image
  updateStoredBlockArea();
}