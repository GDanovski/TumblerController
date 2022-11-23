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

#ifndef SpeedController_HPP
#define SpeedController_HPP

#include "FlashDrv.hpp"
#include "TimeCalculator.hpp"

class SpeedController {
  public:
    /**
       @brief Construct a new SpeedController object

    */
    SpeedController();
    /**
       @brief Delete default copy constructor

    */
    SpeedController(SpeedController&) = delete;
    /**
       @brief Delete default move constructor

    */
    SpeedController(SpeedController&&) = delete;
    /**
       @brief Destroy the SpeedController object

    */
    ~SpeedController() = default;

    //Operators
    /**
       @brief Delete default copy assignment operator

       @return SpeedController&
    */
    SpeedController& operator=(SpeedController&) = delete;
    /**
       @brief Delete default move assignment operator

       @return SpeedController&
    */
    SpeedController& operator=(SpeedController&&) = delete;

    int getValue();

  private:
    static const unsigned int kWeight = 5;
    static const unsigned int kMaxSpeed = 255;
    static const unsigned int kMinSpeed = 124;

    unsigned long _lastValue = 0;
    
};

#endif // !SpeedController_HPP
