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

#ifndef DIGITALDISPLAY_HPP
#define DIGITALDISPLAY_HPP

class DigitalDisplay {
  public:
    /**
       @brief Construct a new DigitalDisplay object

    */
    DigitalDisplay();
    /**
       @brief Delete default copy constructor

    */
    DigitalDisplay(DigitalDisplay&) = delete;
    /**
       @brief Delete default move constructor

    */
    DigitalDisplay(DigitalDisplay&&) = delete;
    /**
       @brief Destroy the DigitalDisplay object

    */
    ~DigitalDisplay() = default;

    //Operators
    /**
       @brief Delete default copy assignment operator

       @return DigitalDisplay&
    */
    DigitalDisplay& operator=(DigitalDisplay&) = delete;
    /**
       @brief Delete default move assignment operator

       @return DigitalDisplay&
    */
    DigitalDisplay& operator=(DigitalDisplay&&) = delete;

    /**
       @brief Construct a new DigitalDisplay object

       @param value int value to be shown (max = 99, min = 00)
       @param time_ms how much time one of the displays will be active before swithcing to the other
    */
    void showValue(int value, int time_ms);

  private:
  /**
       @brief Construct a new DigitalDisplay object

       @param value int state of all pins
    */
    void setAllPins(bool value);

    /**
       @brief Construct a new DigitalDisplay object

       @param value int value to be shown (max = 9, min = 0)
    */
    void setDigit(int value);
};

#endif // !DIGITALDISPLAY_HPP
