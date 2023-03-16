// TODO:
// insta lock
// Lose (Shape generation checking)
// Music
// Start Menu


#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite block = TFT_eSprite(&tft);

// Constants

// Area Width and Height in "Blocks"
#define AREAWIDTH 10
#define AREAHEIGHT 24
#define BLOCKWIDTH 20
#define BLOCKHEIGHT 20

const int leftButton = 22;
const int rightButton = 24;
const int instaLockButton = 28;
const int rotateButton = 26;
const int storeButton = 30;

const int startX = AREAWIDTH/2-1;
const int startY = AREAHEIGHT-2;

// block statuses
// block types Square, square = 0, I = 1, S = 2, Z = 3, L = 4, J = 5, T = 6 
int storedBlock = -1;
int tempStore = -1;
bool alreadyStoredThisTurn = false;
int nextBlock = -1;
int currentBlock = -1;


// game function variables
int randSeed;
int playArea[AREAWIDTH][AREAHEIGHT] = {0};

unsigned long time = millis();
unsigned long oldTime = 0;
int score = 0;



void setup() {
  Serial.begin(250000);
  
  // setup randomness
  randSeed = analogRead(A0) * analogRead(A1) * analogRead(A2);
  randomSeed(randSeed);

  // initialize tft Screen
  tft.init();
  tft.setRotation(4);
  tft.setOrigin(0,0);
  tft.fillScreen(TFT_BLACK);
  tft.drawPixel(0,480, TFT_GREEN);

  // initialize buttons
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(instaLockButton, INPUT_PULLUP);
  pinMode(rotateButton, INPUT_PULLUP);
  pinMode(storeButton, INPUT_PULLUP);

  // initialize game logic
  genNextBlock();
  createBlock(random(0,7), startX, startY);
  initDisplay();

}




void loop() {
    time = millis(); // time for regular block dropping

    // updatae random Seed
    randSeed = analogRead(A0) * analogRead(A1) * analogRead(A2);


    // Check Buttons
    checkRotateButton();
    checkLeftButton();
    checkRightButton();
    checkInstaLockButton();
    checkStoreButton();
    
    // every second
    if ((time - oldTime) >= 1000) {
      printPlayArea();
      oldTime=time;
      dropShape();
    }
}

