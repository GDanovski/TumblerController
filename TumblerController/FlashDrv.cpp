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
#include <EEPROM.h>
#include "FlashDrv.hpp"

FlashDrv::FlashDrv() {
  findIndex();
  // read old record
  for (int i = 0; i < FlashEntries::totalLength; i++) {
    _values[i] = static_cast<int>(EEPROM.read(_index + i));
  }
}

void FlashDrv::store(int addr, int value) {
  // read old record
  _values[addr] = value;
}

int FlashDrv::read(int addr) {
  return _values[addr];
}

void FlashDrv::clearIndex() {
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.update(i, 0);
  }
  _index = 0;
  EEPROM.update(FlashEntries::header, true);
}

void FlashDrv::findIndex() {
  _index = 0;
  for (int i = 0 ; i < EEPROM.length() ; i += FlashEntries::totalLength) {
    int val = static_cast<int>(EEPROM.read(i + FlashEntries::header));

    if (val != 0) {
      _index = i;
    } else {
      return;
    }
  }
}

void FlashDrv::entryUpdate() {
  _values[FlashEntries::header] = true;
  // recalculate index in flash
  _index += FlashEntries::totalLength;
  if (_index + FlashEntries::totalLength > EEPROM.length()) {
    clearIndex();
  }

  // update new record
  for (int i = 0; i < FlashEntries::totalLength; i++) {
    EEPROM.update(_index + i, _values[i]);
  }

  Serial.print("Successful entry update at address: ");
  Serial.print(_index);
  Serial.print("\n");
}
