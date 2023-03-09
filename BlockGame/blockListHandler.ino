void createBlock(int i, int x, int y) {
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