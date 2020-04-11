/*
 * led.h
 * Control over the cells (LEDs): set LEDs on/off, flash an LED, set or get the state of an LED.
 * Created: 2020-04-05 11:21:09 PM
 *  Author: l1598
 */ 
#include <asf.h>

#ifndef LED_H_
#define LED_H_

/* Indicate the state of each led: available, occupied 
	by player 1 or player 2. */
#define AVAILABLE_CELL	0
#define PLAYER1_CELL	1
#define PLAYER2_CELL	2

/*	pin level high (1) and low (0).
	Note that the LEDs are true low. */
#define LEVEL_HIGH	1
#define LEVEL_LOW	0

/* Pin output (0) and input (1) direction */
#define OUTPUT_DIR	0
#define INPUT_DIR	1

/* Each cell is numbered from 1 to 9 from top left
	to top right to bottom left and to bottom right;
	each cell (LED) is connected to two pins, one for
	red color and one for blue color. */
#define CELL1_RED	17		//EXT1_PIN_3, PA17
#define CELL1_BLUE	19		//EXT1_PIN_8, PA19
#define CELL2_RED	24		//EXT1_PIN_5, PA24
#define CELL2_BLUE	25		//EXT1_PIN_6, PA25
#define CELL3_RED	23		//EXT1_PIN_7, PA23
#define CELL3_BLUE	18		//EXT1_PIN_4, PA18
#define CELL4_RED	1		//EXT1_PIN_9, PA1
#define CELL4_BLUE	1		//EXT2_PIN_4, PB1
#define CELL5_RED	3		//EXT1_PIN_11, PA3
#define CELL5_BLUE	4		//EXT1_PIN_12, PA4
#define CELL6_RED	0		//EXT2_PIN_3, PB0
#define CELL6_BLUE	6		//EXT1_PIN_10, PA6
#define CELL7_RED	24		//EXT2_PIN_5,PC24
#define CELL7_BLUE	27		//EXT2_PIN_10, PC27
#define CELL8_RED	19		//EXT2_PIN_7, PC19
#define CELL8_BLUE	20		//EXT2_PIN_8, PA20
#define CELL9_RED	26		//EXT2_PIN_9, PC26
#define CELL9_BLUE	25		//EXT2_PIN_6, PC25


/* The state of each cell: available, occupied
	by player 1 or occupied by player 2. */
extern uint8_t CELL1_state;
extern uint8_t CELL2_state;
extern uint8_t CELL3_state;
extern uint8_t CELL4_state;
extern uint8_t CELL5_state;
extern uint8_t CELL6_state;
extern uint8_t CELL7_state;
extern uint8_t CELL8_state;
extern uint8_t CELL9_state;

/* Assembly subroutine to set the direction in specified pin.
	@para	direction (input = 1, output = 0)
			PA Id	  (for example, 23 for PA23)			*/
extern void pioa_dir_set(uint8_t, uint8_t);

/* Assembly subroutine to set the level in specified pin.
	@para	level (high = 1, low = 0)
			PA Id	  (for example, 23 for PA23)			*/
extern void pioa_level_set(uint8_t, uint8_t);

/* Assembly subroutine to set the direction in specified pin.
	@para	direction (input = 1, output = 0)
			PB Id	  (for example, 23 for PB23)			*/
extern void piob_dir_set(uint8_t, uint8_t);

/* Assembly subroutine to set the level in specified pin.
	@para	level (high = 1, low = 0)
			PB Id	  (for example, 23 for PB23)			*/
extern void piob_level_set(uint8_t, uint8_t);

/* Assembly subroutine to set the direction in specified pin.
	@para	direction (input = 1, output = 0)
			PC Id	  (for example, 23 for PC23)			*/
extern void pioc_dir_set(uint8_t, uint8_t);

/* Assembly subroutine to set the level in specified pin.
	@para	level (high = 1, low = 0)
			PC Id	  (for example, 23 for PC23)			*/
extern void pioc_level_set(uint8_t, uint8_t);

/* Call assembly subroutine to initialize the pins that will be used for the LEDs.
	Set the LEDs low, and output direction. */
void led_init(void);
void flash_led(uint8_t ledID, char color);
uint8_t led_state(uint8_t ledID);
void set_led_state(uint8_t ledID, char color);
void set_led_level(uint8_t ledID, char color, uint8_t level);
void set_led_dir(uint8_t ledID, char color, uint8_t dir);

#endif /* LED_H_ */