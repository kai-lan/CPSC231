/************************************************************************/
/* This is the Tic-Tac-Toe game for CPSC 231 project					*/
/* Team: Weixian Lan, Son Chou											*/
/* Please contact wlan@unbc.ca or schau@unbc.ca for further information */
/************************************************************************/

#include <asf.h>
#include "button.h"
#include "ledcontrol.h"

/* Record 3 LEDs with the same color in a row. */
uint8_t row1, row2, row3; // 1- 9
uint8_t winner; // 0 (no winner), 1 (winner player 1) or 2 (winner player 2)



/* Return 1 if player 1 or 2 wins, 0 otherwise:
	- Check if there are 3 LEDS in a row with the same color,
		and if so flash them. */
uint8_t win(uint8_t current, uint8_t player){
	
	if (current == 1)
	{
		if (led_state(2) == player && led_state(3) == player)
		{
			row1 = current, row2 = 2, row3 = 3;
			return player;
		}
		if (led_state(4) == player && led_state(7) == player)
		{
			row1 = current, row2 = 4, row3 = 7;
			return player;
		}
		if (led_state(5) == player && led_state(9) == player)
		{
			row1 = current, row2 = 5, row3 = 9;
			return player;
		}
	}
	if (current == 2)
	{
		if (led_state(1) == player && led_state(3) == player)
		{
			row1 = current, row2 = 1, row3 = 3;
			return player;
		}
		if (led_state(5) == player && led_state(8) == player)
		{
			row1 = current, row2 = 5, row3 = 8;
			return player;
		}
	}
	if (current == 3)
	{
		if (led_state(2) == player && led_state(1) == player)
		{
			row1 = current, row2 = 2, row3 = 1;
			return player;
		}
		if (led_state(5) == player && led_state(7) == player)
		{
			row1 = current, row2 = 5, row3 = 7;
			return player;
		}
		if (led_state(6) == player && led_state(9) == player)
		{
			row1 = current, row2 = 6, row3 = 9;
			return player;
		}
	}
	if (current == 4)
	{
		if (led_state(1) == player && led_state(7) == player)
		{
			row1 = current, row2 = 1, row3 = 7;
			return player;
		}
		if (led_state(5) == player && led_state(6) == player)
		{
			row1 = current, row2 = 5, row3 = 6;
			return player;
		}
	}
	if (current == 5)
	{
		if (led_state(4) == player && led_state(6) == player)
		{
			row1 = current, row2 = 4, row3 = 6;
			return player;
		}
		if (led_state(2) == player && led_state(8) == player)
		{
			row1 = current, row2 = 2, row3 = 8;
			return player;
		}
		if (led_state(1) == player && led_state(9) == player)
		{
			row1 = current, row2 = 1, row3 = 9;
			return player;
		}
		if (led_state(3) == player && led_state(7) == player)
		{
			row1 = current, row2 = 3, row3 = 7;
			return player;
		}
	}
	if (current == 6)
	{
		if (led_state(3) == player && led_state(9) == player)
		{
			row1 = current, row2 = 3, row3 = 9;
			return player;
		}
		if (led_state(5) == player && led_state(4) == player)
		{
			row1 = current, row2 = 5, row3 = 4;
			return player;
		}
	}
	if (current == 7)
	{
		if (led_state(4) == player && led_state(1) == player)
		{
			row1 = current, row2 = 4, row3 = 1;
			return player;
		}
		if (led_state(5) == player && led_state(3) == player)
		{
			row1 = current, row2 = 5, row3 = 3;
			return player;
		}
		if (led_state(8) == player && led_state(9) == player)
		{
			row1 = current, row2 = 8, row3 = 9;
			return player;
		}
	}
	if (current == 8)
	{
		if (led_state(7) == player && led_state(9) == player)
		{
			row1 = current, row2 = 7, row3 = 9;
			return player;
		}
		if (led_state(5) == player && led_state(2) == player)
		{
			row1 = current, row2 = 5, row3 = 2;
			return player;
		}
	}
	if (current == 9)
	{
		if (led_state(5) == player && led_state(1) == player)
		{
			row1 = current, row2 = 5, row3 = 1;
			return player;
		}
		if (led_state(6) == player && led_state(3) == player)
		{
			row1 = current, row2 = 6, row3 = 3;
			return player;
		}
		if (led_state(8) == player && led_state(7) == player)
		{
			row1 = current, row2 = 8, row3 = 7;
			return player;
		}
	}
	return 0;
}

int main (void)
{
	//clock configuration and initialization
	sysclk_init();
	
	/*Disable the watchdog timer and configure/initialize
	port pins connected to various components incorporated 
	into the SAM4S Xplained development platform, e.g., the 
	NAND flash, the OLED interface, the LEDs, the SW0 pushbutton.*/  
	board_init();
	
	// Configure IO1 buttons.
	configure_buttons();
	
	// Configure the LEDs
	led_init();

	//initialize SPI and the OLED controller
	ssd1306_init();
	ssd1306_clear();
	
	//**********************************************************************
	// Press any button to start the game, waiting for user to push a button
	//**********************************************************************
	ssd1306_write_text("Press any button to start.");
	do{delay_ms(50);}
	while (START_GAME == 0);
	
	
	//*******************************************************************
	// Two Players take turn to play, as led color switches between
	// red (player 1) and blue (player 2) each round.
	// They keep playing until 3 in a row with the same color 
	// or after 9 rounds.
	//*************************************************************
	uint8_t counter;
	char color = 'r';
	winner = 0;
	for (counter = 0; counter < 9; counter ++) {
		
		ssd1306_clear();
		ssd1306_set_page_address(0);
		ssd1306_set_column_address(0);
		if (color == 'r'||color == 'R')
		{
			ssd1306_write_text("Player 1");
		} else{
			ssd1306_write_text("Player 2");
		}
		
		CONTINUE_GAME = 0;	// Turn 1 if the user pushes button 3
		
		delay_ms(200); // Allow some user reaction time in the new round
		do
		{
			// Stop flashing when button 3 is pushed, or flash
			// another LED when button 1 or 2 is pushed
			flash_led(CURRENT_CELL, color);
		}
		while(CONTINUE_GAME == 0); 
		
		set_led_level(CURRENT_CELL, color, LEVEL_LOW);
		set_led_state(CURRENT_CELL, color);
		
		// Check if the current player wins, if no that is the end of the game;
		// if not, the game continues.
		winner = win(CURRENT_CELL, color == 'r'||color == 'R'? PLAYER1_CELL : PLAYER2_CELL);
		if (winner == PLAYER1_CELL || winner == PLAYER2_CELL)
		{
			break;
		}
		
		// Move the current position to the next available cell
		CURRENT_CELL = next_available_led(CURRENT_CELL);
		// switch players in the next round
		color = color == 'r'? 'b':'r';
	}
	
	//************************************************
	// End of the game:
	// - flash the 3 LEDS with the same color in a row
	// - Display 'game over'
	//************************************************
	ssd1306_clear();
	ssd1306_set_page_address(0);
	ssd1306_set_column_address(0);
	
	// Player 1 wins
	if (winner == PLAYER1_CELL)
	{
		ssd1306_write_text("Game over. Player 1 wins!");
		while(1){
			set_led_level(row1, 'r', LEVEL_LOW);
			set_led_level(row2, 'r', LEVEL_LOW);
			set_led_level(row3, 'r', LEVEL_LOW);
			delay_ms(500);
			set_led_level(row1, 'r', LEVEL_HIGH);
			set_led_level(row2, 'r', LEVEL_HIGH);
			set_led_level(row3, 'r', LEVEL_HIGH);
			delay_ms(500);
		}
	}
	else if (winner == PLAYER2_CELL)
	{
		ssd1306_write_text("Game over. Player 2 wins!");
		while(1){
			set_led_level(row1, 'b', LEVEL_LOW);
			set_led_level(row2, 'b', LEVEL_LOW);
			set_led_level(row3, 'b', LEVEL_LOW);
			delay_ms(500);
			set_led_level(row1, 'b', LEVEL_HIGH);
			set_led_level(row2, 'b', LEVEL_HIGH);
			set_led_level(row3, 'b', LEVEL_HIGH);
			delay_ms(500);
		}
	}
	else{
		
		ssd1306_write_text("Game over. No winner.");
		delay_ms(500);
	}
	
}
