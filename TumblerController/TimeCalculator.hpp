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

#ifndef TIMECALCULATOR_HPP
#define TIMECALCULATOR_HPP

#include "FlashDrv.hpp"

class TimeCalculator {
  public:
    /**
       @brief Construct a new TimeCalculator object

    */
    explicit TimeCalculator(FlashDrv& flashDrv);
    /**
       @brief Delete default copy constructor

    */
    TimeCalculator(TimeCalculator&) = delete;
    /**
       @brief Delete default move constructor

    */
    TimeCalculator(TimeCalculator&&) = delete;
    /**
       @brief Destroy the TimeCalculator object

    */
    ~TimeCalculator() = default;

    //Operators
    /**
       @brief Delete default copy assignment operator

       @return TimeCalculator&
    */
    TimeCalculator& operator=(TimeCalculator&) = delete;
    /**
       @brief Delete default move assignment operator

       @return TimeCalculator&
    */
    TimeCalculator& operator=(TimeCalculator&&) = delete;

    /**
       @brief Set how many days the tumbler should be active

       @param days how many days the tumbler should be active
    */
    void setDays(int days);

    /**
       @brief Get how many days the tumbler should be active

       @return how many days the tumbler should be active
    */
    int getDays() const;

    /**
       @brief Recalculate hours and

       @return true if the time is larger then 0
    */
    bool calculate();

    void storeToFlash();

  private:
    static const int kMaxDays = 99;
    static const unsigned long kMsInHour = 1000u * 60u * 60u;
    static const unsigned long kHourInDay = 24u;

    FlashDrv& _flashDrv;
    
    int _days{0};
    int _hours{0};
    unsigned long _lastTime_ms{0u};

    void reset() { asm volatile ("jmp 0"); }

};

#endif // !TIMECALCULATOR_HPP
