#ifndef LED_H
#define LED_H

#include "Arduino.h"

class LedToggle {
      public:
             LedToggle(int pin);
             LedToggle(int pin, unsigned long delayTime);
             void toggle();
             
      private:
              int _pin;
              bool _state;
              unsigned long _delayTime;
};

#endif
