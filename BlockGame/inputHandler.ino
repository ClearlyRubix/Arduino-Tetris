bool rotatePressed = false;
int rotateButtonState;

bool leftPressed = false;
int leftButtonState;

bool rightPressed = false;
int rightButtonState;

bool storePressed = false;
int storeButtonState;

bool instaLockPressed = false;
int instaLockButtonState;

void checkRotateButton() {
  // get button state
  rotateButtonState = digitalRead(rotateButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (rotateButtonState == LOW && rotatePressed == false) {
    rotatePressed = true;
    rotateShape();
  }
  if (rotateButtonState == HIGH) {
    rotatePressed = false;
  }
}

void checkLeftButton() {
  // don't move left if right is already pressed
  if (rightPressed) return;
  // get button state
  leftButtonState = digitalRead(leftButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (leftButtonState == LOW && leftPressed == false) {
    leftPressed = true;
    translateShape(-1);
  }
  if (leftButtonState == HIGH) {
    leftPressed = false;
  }
}


void checkRightButton() {
  // don't move if left already pressed
  if (leftPressed) return;
  // get button state
  rightButtonState = digitalRead(rightButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (rightButtonState == LOW && rightPressed == false) {
    rightPressed = true;
    translateShape(1);
  }
  if (rightButtonState == HIGH) {
    rightPressed = false;
  }
}

void checkStoreButton() {
  // get button state
  storeButtonState = digitalRead(storeButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (storeButtonState == LOW && storePressed == false) {
    storePressed = true;
    storeBlock();
  }
  if (storeButtonState == HIGH) {
    storePressed = false;
  }
}


void checkInstaLockButton() {
  // get button state
  instaLockButtonState = digitalRead(instaLockButton);
  // make sure it only does 1 input, not as long as it's pressed
  if (instaLockButtonState == LOW && instaLockPressed == false) {
    instaLockPressed = true;
    instaLock();
  }
  if (instaLockButtonState == HIGH) {
    instaLockPressed = false;
  }
}