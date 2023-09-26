/*****************************< LIB *****************************/
#include <stdint.h>
#include "stm32f103x8.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*****************************< MCAL *****************************/
#include "GPIO.h"
#include "RCC_interface.h"
#include "STK_interface.h"

/*****************************< HAL *****************************/
#include "LED.h"
#include "PushButton.h"
#include "Seg-5161BS.h"

/*****************************< MACROS *****************************/
#define Car_Red      LED_PIN_0
#define Car_Yellow   LED_PIN_1
#define Car_Green    LED_PIN_2
#define Ped_Red      LED_PIN_5
#define Ped_Yellow   LED_PIN_6
#define Ped_Green    LED_PIN_7
#define Ped_Button   PB_PIN0
#define StopState    0
#define ClearState   1
#define ReadyState   2
#define RedToGreen   0
#define GreenToRed   1

/*****************************< GLobal Variables *****************************/
u8 Current_State;
u8 Next_State = 2;
u8 SinglePressFlag = 1;

/*****************************< Prototypes  *********************************/
void LEDS_init();
void BUTTONS_init();
void Clear();
void Stop();
void Ready();

/*****************************< Main  *********************************/

int main(void)
{
    /********< Initialize Peripherals and Clock *************************/
	STK_Init(1000);

	MCAL_RCC_InitSysClock();
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPBEN);

	LEDS_init();
	BUTTONS_init();
	HAL_SEG_init();

	Stop();
	while(1)
	{
		if(Next_State == RedToGreen)
		{
			Ready();
			Stop();
		}
		if(Next_State == GreenToRed)
		{
			Ready();
			Clear();
		}


	}

}

/*****************************< End of Main  *********************************/


void LEDS_init()
{
	/************< Car Traffic Lights***********/
	HAL_LED_Init(LED_PORTA, LED_PIN_0);
	//yellow
	HAL_LED_Init(LED_PORTA, LED_PIN_1);
	//green
	HAL_LED_Init(LED_PORTA, LED_PIN_2);
	/********< Pedestrian Traffic Lights********/
	//red
	HAL_LED_Init(LED_PORTA, LED_PIN_5);
	//yellow
	HAL_LED_Init(LED_PORTA, LED_PIN_6);
	//green
	HAL_LED_Init(LED_PORTA, LED_PIN_7);
}

void BUTTONS_init()
{
	HAL_PushButton_Init(PB_PORTB, PB_PIN0, FLOATING);
}


void Clear()
{
	Current_State = ClearState;
	u8 i;
	for(i = 5; i>=1; i--)
	{
		HAL_SEG_DisplayNumber(i);
		HAL_LED_On(LED_PORTA, Car_Red);
		HAL_LED_Off(LED_PORTA, Car_Green);
		HAL_LED_Off(LED_PORTA, Car_Yellow);

		HAL_LED_Off(LED_PORTA, Ped_Red);
		HAL_LED_Off(LED_PORTA, Ped_Yellow);
		HAL_LED_On(LED_PORTA, Ped_Green);

		STK_SetDelay_ms(1000);
	}

	Next_State = RedToGreen;
}


void Stop()
{
	SinglePressFlag = 1;
	Current_State = StopState;
	if(Next_State == GreenToRed)
	{
		return;
	}
	u8 i;
	u16 j;
	for (i = 5; i>=1; i--)
	{
		HAL_SEG_DisplayNumber(i);
		for(j = 1; j<= 1000; j++)
		{
			if((HAL_PushButton_Read(PB_PORTB, PB_PIN0, 10) == GPIO_PIN_SET) && SinglePressFlag)
			{
				SinglePressFlag = 0;
				STK_SetDelay_ms(200);
				if(MCAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == GPIO_PIN_RESET)
				{
					Next_State = GreenToRed;
					return;
				}
			}
			HAL_LED_Off(LED_PORTA, Car_Red);
			HAL_LED_On(LED_PORTA, Car_Green);
			HAL_LED_Off(LED_PORTA, Car_Yellow);

			HAL_LED_On(LED_PORTA, Ped_Red);
			HAL_LED_Off(LED_PORTA, Ped_Yellow);
			HAL_LED_Off(LED_PORTA, Ped_Green);
			STK_SetDelay_ms(1);
		}

	}
	SinglePressFlag = 1;
	Next_State = GreenToRed;
}

void Ready()
{
	HAL_LED_Off(LED_PORTA, Car_Red);
	HAL_LED_Off(LED_PORTA, Car_Green);
	HAL_LED_Off(LED_PORTA, Car_Yellow);

	HAL_LED_Off(LED_PORTA, Ped_Red);
	HAL_LED_Off(LED_PORTA, Ped_Yellow);
	HAL_LED_Off(LED_PORTA, Ped_Green);

	u8 i;
	for (i = 5; i>=1; i--)
	{
		HAL_SEG_DisplayNumber(i);
		HAL_LED_Toggle(LED_PORTA, Car_Yellow);
		HAL_LED_Toggle(LED_PORTA, Ped_Yellow);
		STK_SetDelay_ms(1000);
	}

}


