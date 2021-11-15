boolean shift = false;

void setup() {
  pinMode(14, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Keyboard.begin();
  Serial.begin(9600);
  delay(3000);
  if (digitalRead(15) == LOW) {
    Serial.println("killed");
    delay(10000000000000);
  }
}

void loop() {
  if (digitalRead(16) == LOW) {
    shift = true;
  } else {
    shift = false;
  }
  if (digitalRead(15) == LOW) {
    Keyboard.press(219);
    delay(50);
    Keyboard.releaseAll();
  }
  if(digitalRead(9) == LOW) {
    if (!shift) {
      sendAltCode(225);
    } else {
      sendAltCode(193);
    }
  }
  if(digitalRead(8) == LOW) {
    if (!shift) {
      sendAltCode(233);
    } else {
      sendAltCode(200);
    }
  }
  if(digitalRead(6) == LOW) {
      if (!shift) {
      sendAltCode(237);
    } else {
      sendAltCode(205);
    }
  }
  if(digitalRead(4) == LOW) {
    if (!shift) {
      sendAltCode(243);
    } else {
      sendAltCode(211);
    }
  }
  if(digitalRead(2) == LOW) {
    if (!shift) {
      sendAltCode(250);
    } else {
      sendAltCode(218);
    }
  }
  if(digitalRead(10) == LOW) {
    if (!shift) {
      sendAltCode(241);
    } else {
      sendAltCode(209);
    }
  }
  if(digitalRead(14) == LOW) {
    sendAltCode(191);
  }
}

void sendAltCode(int code) {
  Keyboard.press(130);
  delay(10);
  sendSingleCode(234);
  sendSingleCode(genCode((int)(code/100)));
  sendSingleCode(genCode((int)(code%100)/10));
  sendSingleCode(genCode(code%10));
  Keyboard.releaseAll();
  delay(250);
}

int genCode(int prevCode) {
  if (prevCode == 0) {
    return 234;
  } else {
    return prevCode + 224;
  }
}
    
void sendSingleCode(int singleCode) {
  Keyboard.press(singleCode);
  delay(10);
  Keyboard.release(singleCode);
  delay(10);
}

