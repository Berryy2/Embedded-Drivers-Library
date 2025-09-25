/*************************************************
 * Module: LCD
 *
 * File Name: LCD.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mohamed ElBerry
 ************************************************/

#include "LCD.h"
#include "gpio.h"
#include <util/delay.h>

/*****************************************************************
 * Description :
 * Initialize the LCD:
 *  - Configure control pins (RS, E) as output
 *  - Configure data port as output
 *  - Send initialization commands
 *****************************************************************/
void LCD_init(void)
{
	// RS pin
	GPIO_setupPinDirection(PORTD_ID, PIN4_ID, PIN_OUTPUT);
	// E pin
	GPIO_setupPinDirection(PORTD_ID, PIN5_ID, PIN_OUTPUT);
	// Data bus
	GPIO_setupPortDirection(PORTC_ID, PORT_OUTPUT);
	// Wait for LCD power-up
	_delay_ms(20);
	// 2 lines, 8-bit mode
	LCD_sendCommand(0x38);
	// Display ON, cursor OFF
	LCD_sendCommand(0x0C);
	// Clear screen
	LCD_sendCommand(0x01);
}

/****************************************************
 * Description :
 * Send a command to the LCD
 ****************************************************/
void LCD_sendCommand(uint8 command)
{
	// RS = 0 (command mode)
	GPIO_writePin(PORTD_ID, PIN4_ID, LOGIC_LOW);
	_delay_ms(1);
	// Enable = 1
	GPIO_writePin(PORTD_ID, PIN5_ID, LOGIC_HIGH);
	_delay_ms(1);
	// Send command on data bus
	GPIO_writePort(PORTC_ID, command);
	_delay_ms(1);
	// Enable = 0
	GPIO_writePin(PORTD_ID, PIN5_ID, LOGIC_LOW);
	_delay_ms(1);
}

/***************************************************
 * Description :
 * Display a single character on the LCD
 ***************************************************/
void LCD_displayCharacter(uint8 data)
{
	// RS = 1 (data mode)
	GPIO_writePin(PORTD_ID, PIN4_ID, LOGIC_HIGH);
	_delay_ms(1);
	// Enable = 1
	GPIO_writePin(PORTD_ID, PIN5_ID, LOGIC_HIGH);
	_delay_ms(1);
	// Send data on data bus
	GPIO_writePort(PORTC_ID, data);
	_delay_ms(1);
	// Enable = 0
	GPIO_writePin(PORTD_ID, PIN5_ID, LOGIC_LOW);
	_delay_ms(1);
}

/******************************************
 * Description :
 * Display a string on the LCD
 *****************************************/
void LCD_displayString(const char *str)
{
	uint8 i;
	for (i = 0; str[i] != NULL_PTR; i++)
	{
		LCD_displayCharacter(str[i]);
	}
}

/********************************************
 * Description :
 * Move cursor to a specific row and column
 *******************************************/
void LCD_moveCursor(uint8 row, uint8 col)
{
	uint8 lcd_memory_address;

	switch (row)
	{
	case 0:
		lcd_memory_address = col;
		break;
	case 1:
		lcd_memory_address = col + 0x40;
		break;
	case 2:
		lcd_memory_address = col + 0x10;
		break;
	case 3:
		lcd_memory_address = col + 0x50;
		break;
	}
	// Set DDRAM address
	LCD_sendCommand(lcd_memory_address | 0x80);
}

/**********************************************************
 * Description :
 * Display a string starting from a specific row and column
 **********************************************************/
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str)
{
	LCD_moveCursor(row, col);
	LCD_displayString(Str);
}

/*********************************
 * Description :
 * Display an integer on the LCD
 *********************************/
void LCD_intgerToString(int data)
{
	char buff[16];
	// Convert integer to string
	itoa(data, buff, 10);
	LCD_displayString(buff);
}

/*********************************
 * Description :
 * Clear the LCD screen
 *********************************/
void LCD_clearScreen(void)
{
	// Clear screen command
	LCD_sendCommand(0x01);
}
