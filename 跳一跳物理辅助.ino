/*
    author-BA_NANA 天津理工大学
*/
int servopin=7;//定义数字接口7 连接伺服舵机信号线 根据实际情况修改
int myangle;//定义角度变量
int pulsewidth;//定义脉宽变量
float dis,Time;

void servopulse(int servopin,int myangle)//定义一个脉冲函数
{
          pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
          digitalWrite(servopin,HIGH);//将舵机接口电平至高
          delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
          digitalWrite(servopin,LOW);//将舵机接口电平至低
          delay(1);
}

void up()     //定义抬起函数
{
            int val=50;
          val=val-'0'; 
          val=val*(180/9); 
          for(int i=0;i<=50;i++)  
          {
          servopulse(servopin,val); 
          }
}

void down()     //定义放下函数
{
          int val=51;
          val=val-'0'; 
          val=val*(180/9); 
          for(int i=0;i<=50;i++) 
              {
                servopulse(servopin,val); 
              }
}

void setup()//初始化
{
pinMode(servopin,OUTPUT);//设定舵机接口为输出接口
Serial.begin(9600);//连接到串行端口，波特率为9600
Serial.println("servo=o_seral_simple ready" ) ;

up();

}
void loop()   //主函数
{
    while(Serial.available()>0){
                dis = Serial.parseInt(); 
    }
    Serial.println(dis);

    up();

    while(dis!=-1&&dis!=0){
                Time =2.1729*dis - 0.1595;
                down();
                delay(Time);
                up();
                dis = -1;
      }

}

