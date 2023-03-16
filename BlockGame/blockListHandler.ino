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

// void storeBlock() {
//   if (alreadyStoredThisTurn) {  // Don't do anything if you already swapped
//     return;
//   }

//   if (storedBlock < 7 || storedBlock >= 0) {  // if there is already a stored block
//     storedBlock =
//   }
// }