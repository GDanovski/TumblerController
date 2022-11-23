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

#ifndef FlashDrv_HPP
#define FlashDrv_HPP

enum FlashEntries : int {
  hours = 0,
  days,
  isRunning,
  header,
  totalLength
};

class FlashDrv {
  public:
    /**
       @brief Construct a new FlashDrv object

    */
    FlashDrv();
    /**
       @brief Delete default copy constructor

    */
    FlashDrv(FlashDrv&) = delete;
    /**
       @brief Delete default move constructor

    */
    FlashDrv(FlashDrv&&) = delete;
    /**
       @brief Destroy the FlashDrv object

    */
    ~FlashDrv() = default;

    //Operators
    /**
       @brief Delete default copy assignment operator

       @return FlashDrv&
    */
    FlashDrv& operator=(FlashDrv&) = delete;
    /**
       @brief Delete default move assignment operator

       @return FlashDrv&
    */
    FlashDrv& operator=(FlashDrv&&) = delete;

    /**
       @brief Set value to flash

       @param value value to be stored
       @param addr address in flash
    */
    void store(int addr, int value);

    /**
       @brief Get value from flash

       @param addr address in flash
    */
    int read(int addr);

    void entryUpdate();
private:
    int _index = 0;
    int _values[FlashEntries::totalLength] = {0};
    
    void clearIndex();
    void findIndex();
};

#endif // !FlashDrv_HPP
