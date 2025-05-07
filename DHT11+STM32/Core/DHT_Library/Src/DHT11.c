/*
 * DHT11.c
 *
 *  Created on: Feb 14, 2023
 *      Author: huyle
 */
#include "stm32f1xx_hal.h"

#define TYPE_DHT11
// #define TYPE_DHT22

#define DHT_PORT GPIOA
#define DHT_PIN GPIO_PIN_2

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM;
uint8_t Presence = 0;

#include "DHT11.h"

void Set_Pin_Output(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void DHT_Start(void)
{
  Set_Pin_Output(DHT_PORT, DHT_PIN);                    // set the pin as output
  HAL_GPIO_WritePin(DHT_PORT, DHT_PIN, GPIO_PIN_RESET); // pull the pin low  // keo ve muc 0
  delay_ms(18); // wait for 18ms
  HAL_GPIO_WritePin(DHT_PORT, DHT_PIN, GPIO_PIN_SET); // pull the pin high
  delay_us(30);                                       // wait for 30us
  Set_Pin_Input(DHT_PORT, DHT_PIN);                   // set as input
}

uint8_t DHT_Check_Response(void)
{
  uint8_t Response = 0;
  delay_us(50);
  if (!(HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))) // neu muc 0
  {
    delay_us(80);                 // doi 100 ús
    if ((HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN)))  // doc tip neu la muc 1
    {
      Response = 1;           // check xem có phản hồi về 0
    }
    else
    {
      Response = -1;
    }
  }
  while ((HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN)))   // doi khi het muc 1
    ; // wait for the pin to go low
  // day tin hieu ơ muc 0
  return Response;
}

uint8_t DHT_Read(void)
{
  uint8_t i, j;
  /*bat dau truyen*/
  for (j = 0; j < 8; j++)
  {
    while (!(HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN)))
      ;                                         // wait for the pin to go high
    delay_us(50);                               // wait for 50 us
    if (!(HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN))) // if the pin is low
    {
    	i = (i << 1);// write 0
    }
    /* bit 7 0: i = 0;
     * bit 6 1: i = 0 << 1 | 0x01 = 0x01;
     * bit 5 1: i = 0x01 << 1 | 0x01 = 0x010 | 0x01 = 0x011;
     * bit 4 0: i = 0x011 << 1 = 0x0110;
     *
     *
     * */
    else  	i = (i << 1) | 0x01; // if the pin is high, write 1
    while ((HAL_GPIO_ReadPin(DHT_PORT, DHT_PIN)))
      ; // wait for the pin to go low
  }
  return i;
}

void DHT_GetData(DHT_DataTypedef *DHT_Data)  // trả về 2 giá
{
  DHT_Start();
  Presence = DHT_Check_Response();  // check = 1;
  /*doc 5 lan */
  Rh_byte1 = DHT_Read(); /*8 bit */
  Rh_byte2 = DHT_Read();
  Temp_byte1 = DHT_Read();
  Temp_byte2 = DHT_Read();

  SUM = DHT_Read();
  if (SUM == (Rh_byte1 + Rh_byte2 + Temp_byte1 + Temp_byte2))
  {
#if defined(TYPE_DHT11)
    DHT_Data->Temperature = Temp_byte1;
    DHT_Data->Humidity = Rh_byte1;
#endif

#if defined(TYPE_DHT22)
    DHT_Data->Temperature = ((Temp_byte1 << 8) | Temp_byte2);
    DHT_Data->Humidity = ((Rh_byte1 << 8) | Rh_byte2);
#endif
  }
}
