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
#include "TimeCalculator.hpp"

TimeCalculator::TimeCalculator(FlashDrv& flashDrv) : _flashDrv(flashDrv) {
  _days = _flashDrv.read(FlashEntries::days);
  _hours = _flashDrv.read(FlashEntries::hours);
  _lastTime_ms = millis();
}

void TimeCalculator::setDays(int days) {
  if (days > kMaxDays) days = kMaxDays;
  if (days < 0) days = 0;

  _days = days;
  _hours = 0;
  _lastTime_ms = millis();
}

int TimeCalculator::getDays() const {
  return _days;
}

bool TimeCalculator::calculate() {
  if ((_hours > 0) || (_days > 0)) {
    const unsigned long time_ms = millis();
    const unsigned long elapsed_time_ms = _lastTime_ms + kMsInHour;

    if (_lastTime_ms > time_ms) {
      storeToFlash();
      _flashDrv.entryUpdate();
      delay(1000);
      reset();  // Reset if overflow is detected
    }

    if (time_ms > elapsed_time_ms) {
      _lastTime_ms = time_ms;

      _hours++;
      if (_hours >= kHourInDay) {
        _hours = 0;
        if (_days > 0) {
          _days--;
          _flashDrv.store(FlashEntries::days, _days);
        }
      }
      _flashDrv.store(FlashEntries::hours, _hours);
      _flashDrv.entryUpdate();
    }
  }

  return (_hours > 0) || (_days > 0);
}

void TimeCalculator::storeToFlash() {
  _flashDrv.store(FlashEntries::days, _days);
  _flashDrv.store(FlashEntries::hours, _hours);
}
