// TODO:
// Multiple Shapes going
// Block Stroing
// Row Clearing
// Score
// Lose (Shape generation checking)
// Music
// Start Menu


#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite block = TFT_eSprite(&tft);

// Area Width and Height in "Blocks"
#define AREAWIDTH 10
#define AREAHEIGHT 25

// block types Square, I = 0, I = 1, S = 2, Z = 3, L = 4, J = 5, T = 6 
int storedBlock = -1;
int nextBlock = -1;
int randSeed;

int playArea[AREAWIDTH][AREAHEIGHT] = {0};
bool activeIsSquare = false;

#define BLOCKWIDTH 16
#define BLOCKHEIGHT 16

unsigned long time = millis();
unsigned long oldTime = 0;

const int leftButton = 0;
const int rightButton = 0;
const int dropButton = 0;
const int rotateButton = 34;
const int saveButton = 0;


void setup() {
  Serial.begin(250000);
  randSeed = analogRead(A0) * analogRead(A1) * analogRead(A2);
  Serial.print("Random Seed: ");
  Serial.println(randSeed);
  randomSeed(randSeed);
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(dropButton, INPUT);
  pinMode(rotateButton, INPUT);
  pinMode(saveButton, INPUT);

  nextBlock = random(0,7);
  createBlock(random(0,7), AREAWIDTH/2-1, AREAHEIGHT-3);
  initDisplay();

}

bool rotatePressed = false;
int rotateButtonState;


void loop() {
    time = millis();
    randSeed = analogRead(A0) * analogRead(A1) * analogRead(A2);
    Serial.print("Random Seed: ");
    Serial.println(randSeed);
    randomSeed(randSeed);

    rotateButtonState = digitalRead(rotateButton);
    

    // update Rotate
    if (rotateButtonState == HIGH && rotatePressed == false) {
      rotatePressed = true;
      rotateShape();
      Serial.println("ROTATE");
    }
    if (rotateButtonState == LOW) {
      rotatePressed = false;
    }

    // 

    if ((time - oldTime) >= 1000) {
      printPlayArea();
      oldTime=time;
      //rotateShape();
      //dropShape();

      //translateShape(-1);
      
    }
}

