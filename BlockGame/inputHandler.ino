bool rotatePressed = false;
int rotateButtonState;

void checkRotateButton() {
  // get button state
  rotateButtonState = digitalRead(rotateButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (rotateButtonState == HIGH && rotatePressed == false) {
    rotatePressed = true;
    rotateShape();
    Serial.println("ROTATE");
  }
  if (rotateButtonState == LOW) {
    rotatePressed = false;
  }
}

bool leftPressed = false;
int leftButtonState;

bool rightPressed = false;
int rightButtonState;

void checkLeftButton() {
  // don't move left if right is already pressed
  if (rightPressed) return;
  // get button state
  leftButtonState = digitalRead(leftButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (leftButtonState == HIGH && leftPressed == false) {
    leftPressed = true;
    translateShape(-1);
    Serial.println("LEFT");
  }
  if (leftButtonState == LOW) {
    leftPressed = false;
  }
}


void checkRightButton() {
  // don't move if left already pressed
  if (leftPressed) return;
  // get button state
  rightButtonState = digitalRead(rightButtonState);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (rightButtonState == HIGH && rightPressed == false) {
    rightPressed = true;
    translateShape(1);
    Serial.println("RIGHT");
  }
  if (rightButtonState == LOW) {
    rightPressed = false;
  }
}

bool storePressed = false;
int storeButtonState;

void checkStoreButton() {
  // get button state
  storeButtonState = digitalRead(storeButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (storeButtonState == HIGH && storePressed == false) {
    storePressed = true;
    rotateShape();
    Serial.println("ROTATE");
  }
  if (storeButtonState == LOW) {
    storePressed = false;
  }
}

// bool rotatePressed = false;
// int rotateButtonState;

// void checkRotateButton() {
//   // get button state
//   rotateButtonState = digitalRead(rotateButton);

//   // make sure it only does 1 rotation, not as long as it's pressed
//   if (rotateButtonState == HIGH && rotatePressed == false) {
//     rotatePressed = true;
//     rotateShape();
//     Serial.println("ROTATE");
//   }
//   if (rotateButtonState == LOW) {
//     rotatePressed = false;
//   }
// }

bool instaLockPressed = false;
int instaLockButtonState;

void checkInstaLockButton() {
  // get button state
  instaLockButtonState = digitalRead(rotateButton);

  // make sure it only does 1 rotation, not as long as it's pressed
  if (instaLockButtonState == HIGH && instaLockPressed == false) {
    instaLockPressed = true;
    rotateShape();
    Serial.println("ROTATE");
  }
  if (instaLockButtonState == LOW) {
    instaLockPressed = false;
  }
}