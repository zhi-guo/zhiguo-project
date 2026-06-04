#include <Arduino.h>
//6路LED引脚
uint8_t led_pin[6] = {2,4,5,18,19,21};
uint16_t t = 350;  //数字越大亮得越慢

void setup()
{
  for(int i=0;i<6;i++){
    pinMode(led_pin[i],OUTPUT);
    digitalWrite(led_pin[i],LOW);
  }
}

void loop()
{
  //从第1个到第6个：亮→延时→灭掉，每次只亮单颗
  for(int i=0;i<6;i++)
  {
    digitalWrite(led_pin[i],HIGH);
    delay(t);
    digitalWrite(led_pin[i],LOW);
  }
}