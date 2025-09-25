/*************************************************
 * Module: LCD
 *
 * File Name: LCD.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Mohamed ElBerry
 ************************************************/
#ifndef LCD_H_
#define LCD_H_
#include  "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Description :
 * Initialize the LCD:
 *  - Setup control pins and data bus as output
 *  - Send initialization commands
 *******************************************************************************/

void LCD_init(void);

/*******************************************************************************
 * Description :
 * Send a command to the LCD
 *******************************************************************************/

void LCD_sendCommand(uint8 command);

/*******************************************************************************
 * Description :
 * Display a single character on the LCD
 *******************************************************************************/

void LCD_displayCharacter(uint8 data);

/*******************************************************************************
 * Description :
 * Display a string on the LCD
 *******************************************************************************/

void LCD_displayString(const char *str);

/*******************************************************************************
 * Description :
 * Move cursor to a specific row and column
 *******************************************************************************/

void LCD_moveCursor(uint8 row, uint8 col);

/*******************************************************************************
 * Description :
 * Display a string starting from a specific row and column
 *******************************************************************************/

void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str);

/*******************************************************************************
 * Description :
 * Display an integer on the LCD
 *******************************************************************************/

void LCD_intgerToString(int data);

/*******************************************************************************
 * Description :
 * Clear the LCD screen
 *******************************************************************************/

void LCD_clearScreen(void);

#endif /* LCD_H_ */
