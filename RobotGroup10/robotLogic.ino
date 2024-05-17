void robotLogic() {

  motorLogic(); // Process motor logic based on IR values

}

void motorLogic() {
  int* IRvalues;
  IRvalues = readInfrared();

  if (IRvalues[1] == 1 && IRvalues[2] == 1) {
    motorControl(200, 200);
    currentState = "Forward";

  } else if (IRvalues[1] == 0 && IRvalues[2] == 1) {
    motorControl(150, 200);
    currentState = "Slight left";

  } else if (IRvalues[1] == 1 && IRvalues[2] == 0) {
    motorControl(200, 150);
    currentState = "Slight right";

  } else if (IRvalues[0] == 1 && IRvalues[1] == 1 && IRvalues[2] == 1 && IRvalues[3] == 1) {
    if (currentState == "Forward") {
      motorControl(200, 200);
    } else if (currentState == "Slight left") {
      motorControl(150, 200);
    } else if (currentState == "Slight right") {
      motorControl(200, 150);
    }
  }
}