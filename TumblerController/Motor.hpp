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

#ifndef Motor_HPP
#define Motor_HPP

#include "FlashDrv.hpp"
#include "TimeCalculator.hpp"

class Motor {
  public:
    /**
       @brief Construct a new Motor object

    */
    Motor();
    /**
       @brief Delete default copy constructor

    */
    Motor(Motor&) = delete;
    /**
       @brief Delete default move constructor

    */
    Motor(Motor&&) = delete;
    /**
       @brief Destroy the Motor object

    */
    ~Motor() = default;

    //Operators
    /**
       @brief Delete default copy assignment operator

       @return Motor&
    */
    Motor& operator=(Motor&) = delete;
    /**
       @brief Delete default move assignment operator

       @return Motor&
    */
    Motor& operator=(Motor&&) = delete;

    void setSpeed(unsigned int motorSpeed);

  private:
    static const int kSpeedMax = 255;
    int _speed = 0;
};

#endif // !Motor_HPP
