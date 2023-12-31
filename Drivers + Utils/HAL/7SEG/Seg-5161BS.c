/*
 * 7Seg-5161BS.c
 *
 *  Created on: Sep 25, 2023
 *      Author: mw296
 */

#include "STD_TYPES.h"

#include "GPIO.h"
#include "Seg-5161BS.h"


void HAL_SEG_init()
{
	GPIO_PinConfig_t cfg;
	cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	cfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	cfg.GPIO_PinNumber = SEG_A;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
	cfg.GPIO_PinNumber = SEG_B;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
	cfg.GPIO_PinNumber = SEG_C;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
	cfg.GPIO_PinNumber = SEG_D;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
	cfg.GPIO_PinNumber = SEG_E;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
	cfg.GPIO_PinNumber = SEG_F;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
	cfg.GPIO_PinNumber = SEG_G;
	MCAL_GPIO_Init(SEG_PORT, &cfg);
}

void HAL_SEG_DisplayNumber(u8 num)
{
	if (num > 9)
	{
		return;
	}
	else
	{
		switch(num)
		{
		case 0:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
			break;
		case 1:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
			break;
		case 2:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;

		case 3:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;
		case 4:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;
		case 5:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;
		case 6:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;
		case 7:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
			break;
		case 8:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;
		case 9:
			MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
			break;
		default:
			break;
		}
	}
}

void HAL_SEG_DisplayLED(u16 num)
{
	switch(num)
	{
	case SEG_A:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
		break;
	case SEG_B:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
		break;
	case SEG_C:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
		break;

	case SEG_D:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
		break;
	case SEG_E:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
		break;
	case SEG_F:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_SET);
		break;
	case SEG_G:
		MCAL_GPIO_WritePin(SEG_PORT, SEG_A, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_B, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_C, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_D, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_E, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_F, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(SEG_PORT, SEG_G, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}
