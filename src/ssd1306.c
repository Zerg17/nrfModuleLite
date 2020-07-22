#include "ssd1306.h"
#ifdef SSD1306_MODULE

uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xC0, 0xF0, 0x3C, 0x0E, 0x86, 0xE3, 0x73, 0x31, 
	0x19, 0x99, 0x99, 0x19, 0x31, 0x73, 0xE3, 0x86, 0x0E, 0x3C, 
	0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0x70, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 
	0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 
	0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 
	0xF0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0xF0, 0xF0, 0xF0, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x39, 0xF1, 0xF0, 0xC0, 0x03, 0x07, 
	0x07, 0x03, 0x00, 0x00, 0xF9, 0xF9, 0xF8, 0x18, 0x18, 0x18, 
	0x18, 0xF8, 0xF8, 0xF0, 0x40, 0x00, 0x00, 0x00, 0x18, 0x18, 
	0x18, 0xFF, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x1F, 0x7F, 
	0xFE, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xC0, 
	0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
	0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 
	0x0F, 0x3F, 0xFF, 0xFC, 0xF0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x03, 0x07, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 
	0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00
};

static void ssd1306_SendToDisplay(SSD1306_DATA_TYPE type, uint8_t *data, uint8_t length);

static SSD1306_t SSD1306;

void ssd1306_Init(uint8_t address){	
	SSD1306.Address = address;
	// Waiting for SEG/COM ON after reset
	//for(volatile uint32_t i=0; i<100000; i++);
	// Initialize LCD
	uint8_t init_data[] = {0xAE, 0xA6, 0x20, 0x00, 0x21, 0x00, 0x7F, 0x22, 0x00, 0x07, 0xA1, 0xC8, 0xA8, 0x3F, 0x81, 0x20, 0x8D, 0x14, 0xAF};
	// 0xAE - display off
	// 0xA6 - normal (not inversed)
	// 0x20, 0x00 - page horizontal adressing mode
	// 0x21, 0x00, 0x7F - column address from 0 to 127
	// 0x22, 0x00, 0x07 - page address from 0 to 7
	// 0xA1 - segment re-map (vertical mirroring)
	// 0xC8 - COM scan direction (horizontal mirroring)
	// 0xA8, 0x3F - multiplex ratio
	// 0x81, 0x7F - contrast ratio 127 
	// 0x8D, 0x14 - enable charge pump
	// 0xAF - display on (only just after enabling charge pump)
	ssd1306_SendToDisplay(Commands, init_data, sizeof(init_data));
	ssd1306_UpdateScreen();
	SSD1306.CurrentX = 0;
  	SSD1306.CurrentY = 0;
}

void ssd1306_Fill(SSD1306_COLOR color) {
	uint8_t toBuffer = color == White?0xFF:0x00;
	for(uint32_t i = 0; i < sizeof(SSD1306_Buffer); i++)
		SSD1306_Buffer[i] = toBuffer;
}

void ssd1306_UpdateScreen(void) {
  uint8_t update_region_data[6] = {0x21, 0x00, 0x7F, 0x22, 0x00, 0x07};
  //0x21, 0x00, 0x7F - column address from 0 to 127
  //0x22, 0x00, 0x07 - page address from 0 to 7
  ssd1306_SendToDisplay(Commands, update_region_data, 6);
  for(uint32_t page = 0; page < 8; page++) 
    ssd1306_SendToDisplay(Datas, &SSD1306_Buffer[SSD1306_WIDTH * page], SSD1306_WIDTH);
}

void ssd1306_DrawPixel(uint32_t x, uint32_t y, SSD1306_COLOR color){
  if((x < SSD1306_WIDTH) && (y < SSD1306_HEIGHT)){
    if (color == White) SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
    else SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
	}
}

#define abs(x) ((x)>0?(x):-(x))
void ssd1306_DrawLine(int16_t  x0, int16_t  y0, int16_t  x1, int16_t  y1, SSD1306_COLOR color) {
	uint32_t tmp;
  uint8_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
		tmp=x0;
		x0=y0;
		y0=tmp;
		tmp=x1;
		x1=y1;
		y1=tmp;
  }
  if (x0 > x1) {
		tmp=x0;
		x0=x1;
		x1=tmp;
		tmp=y0;
		y0=y1;
		y1=tmp;
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0 <= x1; x0++) {
    if (steep) {
      ssd1306_DrawPixel(y0, x0, color);
    } else {
      ssd1306_DrawPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

void ssd1306_DrawRect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, SSD1306_COLOR color) {
  ssd1306_DrawLine(x0, y0, x1, y0, color);
	ssd1306_DrawLine(x0, y1, x1, y1, color);
	ssd1306_DrawLine(x0, y0, x0, y1, color);
	ssd1306_DrawLine(x1, y0, x1, y1, color);
}

void ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color){
  uint32_t pixel, x;

	if(ch=='\r'){
	  SSD1306.CurrentX=INDENT;
	  return;
  	}
  	if(ch=='\n'){
	  	SSD1306.CurrentX=INDENT;
	  	SSD1306.CurrentY+=Font.FontHeight;
	  	return;
  	}

  	if((SSD1306.CurrentX + Font.FontWidth) > SSD1306_WIDTH){
	  	SSD1306.CurrentX=INDENT;
	  	SSD1306.CurrentY+=Font.FontHeight;
  	}

  	if (((SSD1306.CurrentY + Font.FontHeight) < SSD1306_HEIGHT)){
    	for (uint32_t y = 0; y < Font.FontHeight; y++){
      		if(ch < 127) pixel = Font.fontEn[(ch - 32) * Font.FontHeight + y];
      		else pixel = Font.fontRu[(ch - 192) * Font.FontHeight + y]; 
      		x = Font.FontWidth;
      		while(x--){
        		if (pixel & 0x0001) ssd1306_DrawPixel(SSD1306.CurrentX + x, (SSD1306.CurrentY + y), color);
        		else ssd1306_DrawPixel(SSD1306.CurrentX + x, (SSD1306.CurrentY + y), !color);
        		pixel >>= 1;
      		}
    	}
  	}
  	SSD1306.CurrentX += Font.FontWidth;
}

void ssd1306_Char(unsigned char ch){
	if(ch!=0)
		ssd1306_WriteChar(ch, Font_7x9, White);
}

void ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color){
  while (*str) 
    ssd1306_WriteChar(*str++, Font, color);
}

void ssd1306_SetCursor(uint32_t x, uint32_t y) {
	SSD1306.CurrentX = x;
	SSD1306.CurrentY = y;
}

void ssd1306_SetContrast(uint8_t contrast){
  uint8_t contrast_data[2] = {0x81};
  contrast_data[1] = contrast;
  ssd1306_SendToDisplay(Commands, contrast_data, 2);
}

void ssd1306_DisplayOn(){
  uint8_t contrast_data[1] = {0xAF};
  ssd1306_SendToDisplay(Commands, contrast_data, 1);
}

void ssd1306_DisplayOff(){
  uint8_t contrast_data[1] = {0xAE};
  ssd1306_SendToDisplay(Commands, contrast_data, 1);
}

static void ssd1306_SendToDisplay(SSD1306_DATA_TYPE type, uint8_t *data, uint8_t length){
  	I2C1->CR2 = (SSD1306.Address<<1)|(((length+1))<<16);
	I2C1->CR2 |= I2C_CR2_START | I2C_CR2_AUTOEND | I2C_CR2_PECBYTE;

	I2C1->TXDR = type;
    while(!(I2C1->ISR & I2C_ISR_STOPF)){
        if((I2C1->ISR & I2C_ISR_TXIS))
            I2C1->TXDR = *data++;
    }
    I2C1->ICR |= I2C_ICR_STOPCF;
}

#endif