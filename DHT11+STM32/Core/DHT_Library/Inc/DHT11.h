/*
 * DHT11.h
 *
 *  Created on: Feb 14, 2023
 *      Author: huyle
 */

#ifndef DHT_LIBRARY_INC_DHT11_H_
#define DHT_LIBRARY_INC_DHT11_H_
#include "main.h"
extern void delay_us(uint16_t time);
extern void delay_ms(uint16_t time);
/*******************************************************************************
                                 API
*******************************************************************************/

typedef struct
{
	float Temperature;  // 2 byte lưu nhiet
	float Humidity;  // 2 byte lưu nhiet
}DHT_DataTypedef;

/*API*/
void DHT_GetData (DHT_DataTypedef *DHT_Data);

#endif /* DHT_LIBRARY_INC_DHT11_H_ */
