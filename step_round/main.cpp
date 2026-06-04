#include <Arduino.h>

const uint8_t IN1 = 18;
const uint8_t IN2 = 19;
const uint8_t IN3 = 21;
const uint8_t IN4 = 22;

const uint16_t STEP_PER_ROUND = 2048;  // 整圈步数
uint16_t step_delay = 2;               // 延时，改大小调速（题目2：改此数值观察转速）
uint8_t step_table[] = {0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09};

// 单圈运转函数：dir=1正转，dir=0反转
void runRound(uint8_t dir)
{
  uint16_t cnt = 0;
  uint8_t idx = 0;
  while(cnt < STEP_PER_ROUND)
  {
    digitalWrite(IN1, bitRead(step_table[idx],0));
    digitalWrite(IN2, bitRead(step_table[idx],1));
    digitalWrite(IN3, bitRead(step_table[idx],2));
    digitalWrite(IN4, bitRead(step_table[idx],3));

    if(dir) idx = (idx+1)%8;
    else    idx = (idx+7)%8;

    delay(step_delay);
    cnt++;
  }
}

void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop()
{
  runRound(1);    // 正转一圈
  delay(500);     // 停顿0.5s
  runRound(0);    // 反转一圈
  delay(500);
}