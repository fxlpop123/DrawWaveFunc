
//在使用该函数前，需要将ucWaveBuff内全部元素赋值为ucRangeDown,然后将函数OLED_Draw_Wave放在while里周期调用

uint8_t ucWaveBuff[128] = {0};
uint8_t ucKeyCode = 0;

void OLED_Draw_Wave(void)
{
	uint8_t ucRangeUp = 50;
	uint8_t ucRangeDown = 10;
	
	for(uint8_t i = 127; i > 0 i--)
	{
		ucWaveBuff[i] = ucWaveBuff[i-1];
	}
	
	if(ucKeyCode != 0)
		ucWaveBuff[0] = ucRangeUp;
	else
		ucWaveBuff[0] = ucRangeDown;
	
	OLED_Clear();
	
	for(uint8_t i = 0; i < 127)
		OLED_Draw_Line(i, 63 - ucWaveBuff[i], i, 63 - ucWaveBuff[i + 1], 1);
	
	OLED_Refresh();

	Delay_Ms(30);
}
