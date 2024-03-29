// TODO:
// Music


#include <TFT_eSPI.h>
#include <EEPROM.h>

TFT_eSPI tft = TFT_eSPI();

TFT_eSprite block = TFT_eSprite(&tft);

// Constants

// Area Width and Height in "Blocks"
#define AREAWIDTH 10
#define AREAHEIGHT 24
#define BLOCKWIDTH 20
#define BLOCKHEIGHT 20

const int leftButton = 41;
const int rightButton = 39;
const int instaLockButton = 47;
const int rotateButton = 45;
const int storeButton = 43;

// 7 segment
int pinA = 10;
int pinB = 9;
int pinC = 8;
int pinD = 7;
int pinE = 6;
int pinF = 11;
int pinG = 13;
int pinDP = 12;
int D1 = 5;
int D2 = 4;
int D3 = 3;
int D4 = 2;

const int startX = AREAWIDTH / 2 - 1;
const int startY = AREAHEIGHT - 2;

// block statuses
// block types Square, square = 0, I = 1, S = 2, Z = 3, L = 4, J = 5, T = 6
int storedBlock = -1;
int tempStore = -1;
bool alreadyStoredThisTurn = false;
int nextBlock = -1;
int currentBlock = -1;


// game function variables
int randSeed;
int playArea[AREAWIDTH][AREAHEIGHT] = { 0 };
int currentNote = 0; // for music first note

unsigned long time = millis();
unsigned long oldTime = 0;
int score = 0;

bool game = false;
bool gameFirstLoop = true;

bool startMenu = false;
bool startMenuFirstLoop = true;

bool loseMenu = false;
bool loseMenuFirstLoop = true;

uint32_t highscore = 0;

void initGame() {
  tft.setRotation(4);
  tft.setOrigin(0, 0);
  tft.fillScreen(TFT_BLACK);
  tft.drawPixel(0, 480, TFT_GREEN);

  // initialize game logic
  genNextBlock();
  createBlock(random(0, 7), startX, startY);
  initDisplay();
}

void setup() {
  Serial.begin(250000);
  
  // set pins
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(instaLockButton, INPUT_PULLUP);
  pinMode(rotateButton, INPUT_PULLUP);
  pinMode(storeButton, INPUT_PULLUP);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  // reset music
  currentNote = 0;

  // get highscore from eeprom
  EEPROM.get(0, highscore);
  
  // startup with startMenu
  startMenu = true;
  // setup randomness
  randSeed = analogRead(A0) * analogRead(A1) * analogRead(A2);
  randomSeed(randSeed);

  // initialize tft Screen
  tft.init();
}


void loop() {
  if (startMenu) {
    // running start menu
    if (startMenuFirstLoop) {
      startMenuFirstLoop = false;
      initStartMenu();
    }
    updateStartMenu();

  } else if (game) {
    // running game
    if (gameFirstLoop) {
      gameFirstLoop = false;
      initGame();
    }
    time = millis();  // time for regular block dropping

    // updatae random Seed
    randSeed = analogRead(A0) * analogRead(A1) * analogRead(A2);
    
    // Check Buttons
    checkRotateButton();
    checkLeftButton();
    checkRightButton();
    checkInstaLockButton();
    checkStoreButton();

    // continue music
    updateSong();

    // every second
    if ((time - oldTime) >= 1000) {
      //printPlayArea();
      oldTime = time;
      dropShape();
    }
  } else if (loseMenu) {
    // running loss menu
    if (loseMenuFirstLoop) {
      loseMenuFirstLoop = false;
      initLossMenu();
    }
    updateLossMenu();
  }
  update7Segment();
}
