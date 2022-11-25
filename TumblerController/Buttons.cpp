// MIT License
//
// Copyright (c) 2022 Georgi Danovski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Arduino.h>
#include "PinMap.hpp"
#include "Buttons.hpp"

Buttons::Buttons(TimeCalculator& timeCalculator, FlashDrv& flashDrv) : _timeCalculator(timeCalculator), _flashDrv(flashDrv) {
  pinMode(pinStart, INPUT_PULLUP);
  pinMode(pinIncrement, INPUT_PULLUP);
  pinMode(pinDecrement, INPUT_PULLUP);

  _tumblerStarted = _flashDrv.read(FlashEntries::isRunning);
}

bool Buttons::isIncrementPressed() const {
  return (digitalRead(pinIncrement) == LOW);
}

bool Buttons::isDecrementPressed() const {
  return (digitalRead(pinDecrement) == LOW);
}

bool Buttons::isStartPressed() {
  bool stat = (digitalRead(pinStart) == LOW);

  if (stat && startCounter == 0) {
    startCounter = 1;
    stat = true;
  }
  else if (stat) {
    startCounter++;
    stat = false;
  }
  else {
    startCounter = 0;
    stat = false;
  }

  return stat;
}

bool Buttons::isStartLongPressed() const {
  return (startCounter > startCounterMax);
}

bool Buttons::isTumblerStarted() const {
  return _tumblerStarted;
}

void Buttons::checkButtons(int days) {
  buttonsCounter++;
  if (buttonsCounter > buttonsCounterMax) {
    buttonsCounter = 0;

    if (isIncrementPressed()) {
      _timeCalculator.setDays(days + 1);
    }

    if (isDecrementPressed()) {
      _timeCalculator.setDays(days - 1);
    }

    if (isStartPressed()) {
      _tumblerStarted = !_tumblerStarted;
      _timeCalculator.storeToFlash();
      _flashDrv.store(FlashEntries::isRunning, _tumblerStarted);
      _flashDrv.entryUpdate();

      Serial.print("Tumbler running: ");
      Serial.print(_tumblerStarted);
      Serial.print("\n");
    }

    while(isStartLongPressed()){
      if(_timeCalculator.getDays() > 0){
        _timeCalculator.setDays(0);
        _tumblerStarted = false;
        _flashDrv.store(FlashEntries::isRunning, _tumblerStarted);
        _timeCalculator.storeToFlash();
        _flashDrv.entryUpdate();

        Serial.print("Timer reset\n");
        return;
      }
      
      isStartPressed();
      Serial.print("Start button stucked\n");
      delay(1000);
    }
  }
}
