#include <Arduino.h>
#include "main.h"
#include "coms.h"

Remote remote_data;
PID pid_data;

#include "DShotRMT.h"
const auto MOTOR01_PIN = 17;
const auto MOTOR02_PIN = 5;
const auto MOTOR03_PIN = 18;
const auto MOTOR04_PIN = 19;

const auto DSHOT_MODE = DSHOT300;

DShotRMT motor01(MOTOR01_PIN, RMT_CHANNEL_0);
DShotRMT motor02(MOTOR02_PIN, RMT_CHANNEL_1);
DShotRMT motor03(MOTOR03_PIN, RMT_CHANNEL_2);
DShotRMT motor04(MOTOR04_PIN, RMT_CHANNEL_3);

void setup()
{
  Serial.begin(115200);
  setup_wifi();

  motor01.begin(DSHOT_MODE);
  motor02.begin(DSHOT_MODE);
  motor03.begin(DSHOT_MODE);
  motor04.begin(DSHOT_MODE);
}

const auto FAILSAFE_THROTTLE = 999;
const auto INITIAL_THROTTLE = 48;

float throttle_value = INITIAL_THROTTLE;
void loop()
{
  throttle_value = throttle_value + remote_data.left.y / 100;

  auto throttle_val = (throttle_value > INITIAL_THROTTLE) ? throttle_value : INITIAL_THROTTLE;

  motor01.sendThrottleValue(throttle_val);
  motor02.sendThrottleValue(throttle_val);
  motor03.sendThrottleValue(throttle_val);
  motor04.sendThrottleValue(throttle_val);

  Serial.println(throttle_val);
}