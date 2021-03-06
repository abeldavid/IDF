#include "idf/DualShock3.hh"

namespace idf {

DualShock3::DualShock3() :
    selectButton(0, 1),
    startButton(0, 1) {

    directionalPadUp.configure(0, 255);
    directionalPadDown.configure(0, 255);
    directionalPadLeft.configure(0, 255);
    directionalPadRight.configure(0, 255);
    squareButton.configure(0, 255);
    triangleButton.configure(0, 255);
    xButton.configure(0, 255);
    circleButton.configure(0, 255);
    leftBumper.configure(0, 255);
    rightBumper.configure(0, 255);

    for (unsigned i = 1; i < sizeof(command); ++i) {
        command[i] = 0;
    }
    command[0] = 0x01;
    command[9] = 0x1E;
}

void DualShock3::rumble(Rumbler rumbler, unsigned char intensity) {
   rumble(rumbler, intensity, 0xFF);
}

void DualShock3::rumble(Rumbler rumbler, unsigned char intensity, unsigned char duration) {
    int index = rumbler == Weak ? 1 : 3;
    command[index] = duration;
    command[++index] = intensity;
    sendCommand();
}

void DualShock3::setLed(LED led, unsigned char commandDuration,
  unsigned char cyclePeriodInteger, unsigned char cyclePeriodFraction,
  unsigned char offFactor, unsigned char onFactor) {
    int index = 10 + 5 * led;
    command[index] = commandDuration;
    command[++index] = cyclePeriodInteger;
    command[++index] = cyclePeriodFraction;
    command[++index] = offFactor;
    command[++index] = onFactor;
    sendCommand();
}

const std::vector<InputLayout::Configurable>& DualShock3::getConfigurables() {
    static std::vector<Configurable> inputs;
    if (inputs.empty()) {
        append(DualShock::getConfigurables(), inputs);
        inputs.push_back(Configurable(directionalPadUp, "Directional Pad Up", "directionalPadUp"));
        inputs.push_back(Configurable(directionalPadDown, "Directional Pad Down", "directionalPadDown"));
        inputs.push_back(Configurable(directionalPadLeft, "Directional Pad Left", "directionalPadLeft"));
        inputs.push_back(Configurable(directionalPadRight, "Directional Pad Right", "directionalPadRight"));
        inputs.push_back(Configurable(squareButton, "Square Button", "squareButton"));
        inputs.push_back(Configurable(triangleButton, "Triangle Button", "triangleButton"));
        inputs.push_back(Configurable(xButton, "X Button", "xButton"));
        inputs.push_back(Configurable(circleButton, "Circle Button", "circleButton"));
        inputs.push_back(Configurable(leftBumper, "Left Bumper", "leftBumper"));
        inputs.push_back(Configurable(rightBumper, "Right Bumper", "rightBumper"));
    }
    return inputs;
}

}
