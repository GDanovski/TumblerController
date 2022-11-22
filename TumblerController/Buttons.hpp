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

#ifndef Buttons_HPP
#define Buttons_HPP

#include "FlashDrv.hpp"
#include "TimeCalculator.hpp"

class Buttons {
  public:
    /**
       @brief Construct a new Buttons object

    */
    Buttons(TimeCalculator& timeCalculator, FlashDrv& flashDrv);
    /**
       @brief Delete default copy constructor

    */
    Buttons(Buttons&) = delete;
    /**
       @brief Delete default move constructor

    */
    Buttons(Buttons&&) = delete;
    /**
       @brief Destroy the Buttons object

    */
    ~Buttons() = default;

    //Operators
    /**
       @brief Delete default copy assignment operator

       @return Buttons&
    */
    Buttons& operator=(Buttons&) = delete;
    /**
       @brief Delete default move assignment operator

       @return Buttons&
    */
    Buttons& operator=(Buttons&&) = delete;

    void checkButtons(int days);

    bool isTumblerStarted() const;

  private:
    static const int startCounterMax = 6;
    static const int buttonsCounterMax = 20;

    TimeCalculator& _timeCalculator;
    FlashDrv& _flashDrv;
    
    int buttonsCounter = 0;
    int startCounter = 0;
    bool _tumblerStarted = false;

    bool isIncrementPressed() const;
    bool isDecrementPressed() const;
    bool isStartPressed();
    bool isStartLongPressed() const;
};

#endif // !Buttons_HPP
