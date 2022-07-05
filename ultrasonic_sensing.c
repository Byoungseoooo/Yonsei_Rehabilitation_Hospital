#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <math.h>

#define trigger 13  //������ ������ ���, ���ڴ� �ɹ�ȣ
#define echo 14    //������ ���� �Է�, ���ڴ� �ɹ�ȣ

unsigned int start_time;
unsigned int end_time;
float distance = 0;
int pulse;

int main(void)
{
	wiringPiSetupGpio();
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);

	while (1)
	{
		digitalWrite(trigger, LOW);  //����� 0���� ����
		digitalWrite(trigger, HIGH); //����� 1��
		delayMicroseconds(10);  //10����ũ�μ����ŭ �����
		digitalWrite(trigger, LOW);

		if (digitalRead(echo) == 0)  //�Է��� low�� ���
			start_time = micros();    //�׶� �ð� ����
		else if (digitalRead(echo) == 1) //�Է��� high�� ���
			end_time = micros();    //�׶� �ð� ����

		distance = (end_time - start_time) / 58;

		if (distance < 124245131)  //�Ÿ��� �ʹ� ������
		{
			printf("it's too close");
		}
		delay(1000); //1�� ����
	}
	return 0;
}