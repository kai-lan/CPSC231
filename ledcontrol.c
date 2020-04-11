/*
 * ledcontrol.c
 *
 * Created: 2020-04-06 1:19:29 AM
 *  Author: l1598
 */ 

#include "ledcontrol.h"

uint8_t CELL1_state = AVAILABLE_CELL;
uint8_t CELL2_state = AVAILABLE_CELL;
uint8_t CELL3_state = AVAILABLE_CELL;
uint8_t CELL4_state = AVAILABLE_CELL;
uint8_t CELL5_state = AVAILABLE_CELL;
uint8_t CELL6_state = AVAILABLE_CELL;
uint8_t CELL7_state = AVAILABLE_CELL;
uint8_t CELL8_state = AVAILABLE_CELL;
uint8_t CELL9_state = AVAILABLE_CELL;

/* Flashing the LED of an available cell:
	- checks if the current cell is available, as leds that are 
	already on will not be flashed. */
void flash_led(uint8_t ledID, char color){
	
	int the_color = color;
	if (led_state(ledID) == AVAILABLE_CELL)
	{
		set_led_level(ledID, the_color, LEVEL_LOW);
		delay_ms(200);

		set_led_level(ledID, the_color, LEVEL_HIGH);
		delay_ms(200);
	}
}

/* Set the directions of the LEDs: output(0) or input(1) */
void set_led_dir(uint8_t ledID, char color, uint8_t dir){
	
	if (ledID == 1)
	{
		if(color == 'r' || color == 'R')
		pioa_dir_set(dir, CELL1_RED);
		else if(color == 'b' || color == 'B')
		pioa_dir_set(dir, CELL1_BLUE);
	}
	if (ledID == 2)
	{
		if(color == 'r' || color == 'R')
		pioa_dir_set(dir, CELL2_RED);
		else if(color == 'b' || color == 'B')
		pioa_dir_set(dir, CELL2_BLUE);
	}
	if (ledID == 3)
	{
		if(color == 'r' || color == 'R')
		pioa_dir_set(dir, CELL3_RED);
		else if(color == 'b' || color == 'B')
		pioa_dir_set(dir, CELL3_BLUE);
	}
	if (ledID == 4)
	{
		if(color == 'r' || color == 'R')
		pioa_dir_set(dir, CELL4_RED);
		else if(color == 'b' || color == 'B')
		piob_dir_set(dir, CELL4_BLUE);
	}
	if (ledID == 5)
	{
		if(color == 'r' || color == 'R')
		pioa_dir_set(dir, CELL5_RED);
		else if(color == 'b' || color == 'B')
		pioa_dir_set(dir, CELL5_BLUE);
	}
	if (ledID == 6)
	{
		if(color == 'r' || color == 'R')
		piob_dir_set(dir, CELL6_RED);
		else if(color == 'b' || color == 'B')
		pioa_dir_set(dir, CELL6_BLUE);
	}
	if (ledID == 7)
	{
		if(color == 'r' || color == 'R')
		pioc_dir_set(dir, CELL7_RED);
		else if(color == 'b' || color == 'B')
		pioc_dir_set(dir, CELL7_BLUE);
	}
	if (ledID == 8)
	{
		if(color == 'r' || color == 'R')
		pioc_dir_set(dir, CELL8_RED);
		else if(color == 'b' || color == 'B')
		pioa_dir_set(dir, CELL8_BLUE);
	}
	if (ledID == 9)
	{
		if(color == 'r' || color == 'R')
		pioc_dir_set(dir, CELL9_RED);
		else if(color == 'b' || color == 'B')
		pioc_dir_set(dir, CELL9_BLUE);
	}
		
}

/* Turn the red or blue of a specified LED by the cell number 1-9 
	@para LEDs that represent cell 1- 9
		  color	'r' or 'R" for red, and 'b' or 'B' for blue
		  level high for on, low for off						*/
void set_led_level(uint8_t ledID, char color, uint8_t level){
	
	if (ledID == 1)
	{
		if(color == 'r' || color == 'R')
			pioa_level_set(level, CELL1_RED);
		else if(color == 'b' || color == 'B')
			pioa_level_set(level, CELL1_BLUE);
	}
	if (ledID == 2)
	{
		if(color == 'r' || color == 'R')
			pioa_level_set(level, CELL2_RED);
		else if(color == 'b' || color == 'B')
			pioa_level_set(level, CELL2_BLUE);
	}
	if (ledID == 3)
	{
		if(color == 'r' || color == 'R')
			pioa_level_set(level, CELL3_RED);
		else if(color == 'b' || color == 'B')
			pioa_level_set(level, CELL3_BLUE);
	}
	if (ledID == 4)
	{
		if(color == 'r' || color == 'R')
			pioa_level_set(level, CELL4_RED);
		else if(color == 'b' || color == 'B')
			piob_level_set(level, CELL4_BLUE);
	}
	if (ledID == 5)
	{
		if(color == 'r' || color == 'R')
			pioa_level_set(level, CELL5_RED);
		else if(color == 'b' || color == 'B')
			pioa_level_set(level, CELL5_BLUE);
	}
	if (ledID == 6)
	{
		if(color == 'r' || color == 'R')
			piob_level_set(level, CELL6_RED);
		else if(color == 'b' || color == 'B')
			pioa_level_set(level, CELL6_BLUE);
	}
	if (ledID == 7)
	{
		if(color == 'r' || color == 'R')
			pioc_level_set(level, CELL7_RED);
		else if(color == 'b' || color == 'B')
			pioc_level_set(level, CELL7_BLUE);
	}
	if (ledID == 8)
	{
		if(color == 'r' || color == 'R')
			pioc_level_set(level, CELL8_RED);
		else if(color == 'b' || color == 'B')
			pioa_level_set(level, CELL8_BLUE);
	}
	if (ledID == 9)
	{
		if(color == 'r' || color == 'R')
			pioc_level_set(level, CELL9_RED);
		else if(color == 'b' || color == 'B')
			pioc_level_set(level, CELL9_BLUE);
	}
}

/***********************************************************************************/
/* Return the state of a given LED, available or red (player1's) or blue (player2's)                                                                     */
/***********************************************************************************/
uint8_t led_state(uint8_t ledID){
	if(ledID == 1)
		return CELL1_state;
	if(ledID == 2)
		return CELL2_state;
	if(ledID == 3)
		return CELL3_state;
	if(ledID == 4)
		return CELL4_state;
	if(ledID == 5)
		return CELL5_state;
	if(ledID == 6)
		return CELL6_state;
	if(ledID == 7)
		return CELL7_state;
	if(ledID == 8)
		return CELL8_state;
	if(ledID == 9)
		return CELL9_state;
	
	return 0;
}

/************************************************************************/
/* Update the state of a LED to red for player1 or blue for player2                                                                     */
/************************************************************************/
void set_led_state(uint8_t ledID, char color){
	
	if(ledID == 1)
		CELL1_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 2)
		CELL2_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 3)
		CELL3_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 4)
		CELL4_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 5)
		CELL5_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 6)
		CELL6_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 7)
		CELL7_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 8)
		CELL8_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
	if(ledID == 9)
		CELL9_state = (color == 'r' || color == 'R') ? PLAYER1_CELL : PLAYER2_CELL;
}
/* Call assembly subroutine to initialize the pins that will be used for the LEDs.
	Set the LEDs low, and output direction. 
	Set the state of 9 cells as available. */
void led_init(void){
	uint8_t counter;
	
	for (counter = 1; counter <= 9; counter ++)
	{
		set_led_level(counter, 'r', LEVEL_HIGH);
		set_led_dir(counter, 'r', OUTPUT_DIR);
		set_led_level(counter, 'b', LEVEL_HIGH);
		set_led_dir(counter, 'b', OUTPUT_DIR);
	}
	
}
