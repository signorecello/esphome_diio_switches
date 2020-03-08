#include "esphome.h"
#include "NewRemoteTransmitter.h"

class MyCustomSwitch : public Component, public Switch {
 private:
    int _unit;
    int _address = 25015010;
    int _pin = 13;
    int _period = 263;
 
 public:
    MyCustomSwitch(int unit) {
        _unit = unit;
    }

    void setup() override {

    }

    void write_state(bool state) override {
        NewRemoteTransmitter transmitter(_address, _pin, _period);
        transmitter.sendUnit(_unit, state);
        publish_state(state);
    }
};