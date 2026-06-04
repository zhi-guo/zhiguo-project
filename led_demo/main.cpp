#include <Arduino.h>

//LED引脚：1~6号灯对应
uint8_t led_pin[6] = {2,4,5,18,19,21};
//存储LED状态：0灭 1亮
uint8_t led_state[6] = {0,0,0,0,0,0};

void setup()
{
  //初始化引脚
  for(int i=0;i<6;i++){
    pinMode(led_pin[i],OUTPUT);
    digitalWrite(led_pin[i],LOW);
  }
  //开启串口
  Serial.begin(115200);
  Serial.println("系统就绪:发送1~6控制对应LED翻转");
}

void loop()
{
  //判断串口收到数据
  if(Serial.available()>0)
  {
    char cmd = Serial.read(); //读取单个字符
    int num = cmd - '1';     //字符'1'→数字0、'2'→1……

    //指令在1~6范围内
    if(num>=0 && num<=5)
    {
      //翻转电平
      led_state[num] = !led_state[num];
      digitalWrite(led_pin[num], led_state[num]);

      //串口反馈信息
      if(led_state[num]==1){
        Serial.print("LED");
        Serial.print(num+1);
        Serial.println(" 点亮");
      }else{
        Serial.print("LED");
        Serial.print(num+1);
        Serial.println(" 熄灭");
      }
    }
    else{
      //无效指令
      Serial.println("无效指令,仅支持1~6");
    }
  }
}