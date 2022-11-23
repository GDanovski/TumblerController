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

#ifndef PINMAP_HPP
#define PINMAP_HPP

/**
   @brief DigitalDisplay configuration

  pins:
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

LED:
DS1 -- B
 C -- A
 E -- F
DP -- G
 D -- DS1
*/
struct DigitalDisplayConfig {
  static const int pinDS1 = 2;  ///< pin select first digit display (minor)
  static const int pinDS2 = 3;  ///< pin select secound digit display (major)
  static const int pinA = 4;    ///< pin A
  static const int pinB = 5;    ///< pin B
  static const int pinC = 6;    ///< pin C
  static const int pinD = 7;    ///< pin D
  static const int pinE = 8;    ///< pin E
  static const int pinF = 9;    ///< pin F
  static const int pinG = 10;   ///< pin G
  static const int pinDP = 0;   ///< pin dot postatic const int - not used
};

static const int pinStart = A0;       ///< pin dot postatic const int - not used
static const int pinIncrement = A1;   ///< pin dot postatic const int - not used
static const int pinDecrement = A2;   ///< pin dot postatic const int - not used
static const int pinSpeed = A3;       ///< pin dot postatic const int - not used
static const int pinMotor = 11;       ///< pin dot postatic const int - not used

#endif // !PINMAP_HPP
