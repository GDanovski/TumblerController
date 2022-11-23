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
#include "DigitalDisplay.hpp"

DigitalDisplay::DigitalDisplay() {
  pinMode(DigitalDisplayConfig::pinA, OUTPUT);
  pinMode(DigitalDisplayConfig::pinB, OUTPUT);
  pinMode(DigitalDisplayConfig::pinC, OUTPUT);
  pinMode(DigitalDisplayConfig::pinD, OUTPUT);
  pinMode(DigitalDisplayConfig::pinE, OUTPUT);
  pinMode(DigitalDisplayConfig::pinF, OUTPUT);
  pinMode(DigitalDisplayConfig::pinG, OUTPUT);
  pinMode(DigitalDisplayConfig::pinDS1, OUTPUT);
  pinMode(DigitalDisplayConfig::pinDS2, OUTPUT);

  setAllPins(HIGH);
  digitalWrite(DigitalDisplayConfig::pinDS1, LOW);
  digitalWrite(DigitalDisplayConfig::pinDS2, LOW);
}

void DigitalDisplay::setAllPins(bool value) {
  digitalWrite(DigitalDisplayConfig::pinA, value);
  digitalWrite(DigitalDisplayConfig::pinB, value);
  digitalWrite(DigitalDisplayConfig::pinC, value);
  digitalWrite(DigitalDisplayConfig::pinD, value);
  digitalWrite(DigitalDisplayConfig::pinE, value);
  digitalWrite(DigitalDisplayConfig::pinF, value);
  digitalWrite(DigitalDisplayConfig::pinG, value);
}

void DigitalDisplay::showValue(int value) {
  int minor = value % 10;
  int major = (value - minor) / 10;

  setDigit(minor);
  digitalWrite(DigitalDisplayConfig::pinDS1, LOW);
  digitalWrite(DigitalDisplayConfig::pinDS2, HIGH);
  delay(timeToShowDigit_ms);

  setDigit(major);
  digitalWrite(DigitalDisplayConfig::pinDS1, HIGH);
  digitalWrite(DigitalDisplayConfig::pinDS2, LOW);
  delay(timeToShowDigit_ms);

  digitalWrite(DigitalDisplayConfig::pinDS1, HIGH);
  digitalWrite(DigitalDisplayConfig::pinDS2, HIGH);
}

void DigitalDisplay::setDigit(int value) {
  switch (value) {
    case 0:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, HIGH);
      digitalWrite(DigitalDisplayConfig::pinF, HIGH);
      digitalWrite(DigitalDisplayConfig::pinG, LOW);
      break;
    case 1:
      digitalWrite(DigitalDisplayConfig::pinA, LOW);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, LOW);
      digitalWrite(DigitalDisplayConfig::pinE, LOW);
      digitalWrite(DigitalDisplayConfig::pinF, LOW);
      digitalWrite(DigitalDisplayConfig::pinG, LOW);
      break;
    case 2:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, LOW);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, HIGH);
      digitalWrite(DigitalDisplayConfig::pinF, LOW);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    case 3:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, LOW);
      digitalWrite(DigitalDisplayConfig::pinF, LOW);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    case 4:
      digitalWrite(DigitalDisplayConfig::pinA, LOW);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, LOW);
      digitalWrite(DigitalDisplayConfig::pinE, LOW);
      digitalWrite(DigitalDisplayConfig::pinF, HIGH);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    case 5:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, LOW);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, LOW);
      digitalWrite(DigitalDisplayConfig::pinF, HIGH);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    case 6:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, LOW);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, HIGH);
      digitalWrite(DigitalDisplayConfig::pinF, HIGH);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    case 7:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, LOW);
      digitalWrite(DigitalDisplayConfig::pinE, LOW);
      digitalWrite(DigitalDisplayConfig::pinF, LOW);
      digitalWrite(DigitalDisplayConfig::pinG, LOW);
      break;
    case 8:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, HIGH);
      digitalWrite(DigitalDisplayConfig::pinF, HIGH);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    case 9:
      digitalWrite(DigitalDisplayConfig::pinA, HIGH);
      digitalWrite(DigitalDisplayConfig::pinB, HIGH);
      digitalWrite(DigitalDisplayConfig::pinC, HIGH);
      digitalWrite(DigitalDisplayConfig::pinD, HIGH);
      digitalWrite(DigitalDisplayConfig::pinE, LOW);
      digitalWrite(DigitalDisplayConfig::pinF, HIGH);
      digitalWrite(DigitalDisplayConfig::pinG, HIGH);
      break;
    default:
      setAllPins(HIGH);
      break;
  }
}
