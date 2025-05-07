/*
 * LCD_4_Bits.c
 *
 *  Created on: Feb 14, 2023
 *      Author: huyle
 */
#include "LCD_4_Bits.h"
#include "stm32f1xx_hal_def.h"
#include "main.h"
/*******************************************************************************
                              DEFINITIONS
*******************************************************************************/
#define LCD_RS GPIO_PIN_9
#define LCD_RW GPIO_PIN_8
#define LCD_EN GPIO_PIN_7
#define LCD_D4 GPIO_PIN_6
#define LCD_D5 GPIO_PIN_5
#define LCD_D6 GPIO_PIN_4
#define LCD_D7 GPIO_PIN_3
#define LCD_PORT GPIOB

/*******************************************************************************
                                 FUNCTION
*******************************************************************************/

void GPIO_LCD_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  HAL_GPIO_WritePin(LCD_PORT, LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4 | LCD_EN | LCD_RW | LCD_RS, 0);

  GPIO_InitStruct.Pin = LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4 | LCD_EN | LCD_RW | LCD_RS;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);
}

void GPIO_OUTPUT(uint16_t Pin, uint8_t state)
{
  HAL_GPIO_WritePin(LCD_PORT, Pin, state);
}

#if 1
/*Chuong trình giao tiep LCD 16x2 4bit*/

void LCD_Enable(void)   /* dau tien cau hinh ở chế độ ghi */
{
  // LCD_EN = 1;
  GPIO_OUTPUT(LCD_EN, 1);
  delay_us(50);
  GPIO_OUTPUT(LCD_EN, 0); // LCD_EN=0;
  delay_us(50);
}

void LCD_Send4Bit(unsigned char Data)  /*viet ham gui data */
{
  // LCD_D4=Data & 0x01;
  if (Data & 0x01)
  {
    GPIO_OUTPUT(LCD_D4, 1);
  }
  else
    GPIO_OUTPUT(LCD_D4, 0);

  // LCD_D5=(Data>>1)&1;
  if ((Data >> 1) & 1)
  {
    GPIO_OUTPUT(LCD_D5, 1);
  }
  else
    GPIO_OUTPUT(LCD_D5, 0);
  // LCD_D6=(Data>>2)&1;
  if ((Data >> 2) & 1)
  {
    GPIO_OUTPUT(LCD_D6, 1);
  }
  else
    GPIO_OUTPUT(LCD_D6, 0);
  // LCD_D7=(Data>>3)&1;
  if ((Data >> 3) & 1)
  {
    GPIO_OUTPUT(LCD_D7, 1);
  }
  else
    GPIO_OUTPUT(LCD_D7, 0);
}
void LCD_SendCommand(unsigned char command)   /*viet ham gui lenh*/
{
  LCD_Send4Bit(command >> 4);
  LCD_Enable();
  LCD_Send4Bit(command);
  LCD_Enable();
}
void LCD_Clear(void)
{
  LCD_SendCommand(0x01);
  delay_ms(2);
}
void LCD_Init(void)
{
  GPIO_LCD_Init();
  LCD_Send4Bit(0x00);
  delay_ms(20);
  // LCD_RS=0;
  GPIO_OUTPUT(LCD_RS, 0);
  // LCD_RW=0;
  GPIO_OUTPUT(LCD_RW, 0);
  LCD_Send4Bit(0x03);
  LCD_Enable();
  delay_ms(5);
  LCD_Enable();
  delay_us(100);
  LCD_Enable();
  LCD_Send4Bit(0x02);
  LCD_Enable();
  LCD_SendCommand(0x28);
  LCD_SendCommand(0x0C);
  LCD_SendCommand(0x06);
  LCD_SendCommand(0x01);
  LCD_SendCommand(0x02);
  delay_ms(2);
}
void LCD_Gotoxy(int x, int y)
{
  unsigned char address;
  if (!y)
    address = (0x80 + x);
  else
    address = (0xc0 + x);
  delay_ms(1);
  LCD_SendCommand(address);
  delay_us(50);
}
void LCD_PutChar(unsigned char Data)
{
  // LCD_RS=1;
  GPIO_OUTPUT(LCD_RS, 1);
  LCD_SendCommand(Data);
  GPIO_OUTPUT(LCD_RS, 0); // LCD_RS=0 ;
}
void LCD_Puts(char *s)
{
  while (*s)
  {
    LCD_PutChar(*s);
    s++;
  }
}

#endif /*0*/
