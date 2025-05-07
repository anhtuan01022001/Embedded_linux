/*
 * LCD_4_Bits.h
 *
 *  Created on: Feb 14, 2023
 *      Author: huyle
 */

#ifndef LIB_INC_LCD_4_BITS_H_
#define LIB_INC_LCD_4_BITS_H_
#include "main.h"
/*******************************************************************************
                                 API
*******************************************************************************/
extern void delay_us(uint16_t time);
extern void delay_ms(uint16_t time);
void GPIO_LCD_Init(void);
void GPIO_OUTPUT(uint16_t Pin, uint8_t state);
void LCD_Init(void);
void LCD_Enable(void);
void LCD_Send4Bit(unsigned char Data);
void LCD_SendCommand(unsigned char command);
void LCD_Clear(void);
void LCD_Gotoxy(int x, int y);
void LCD_PutChar(unsigned char Data);
void LCD_Puts(char *s);
#endif /* LIB_INC_LCD_4_BITS_H_ */
