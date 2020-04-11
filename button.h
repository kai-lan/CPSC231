/*
 * button.h
 * Button listeners that handle interrupt from users pushing buttons
 * when starting the game, selecting a different cell or confirming the current cell
 * Created: 2020-04-05 8:20:59 PM
 *  Author: l1598
 */ 
#include <asf.h>
#include "ledcontrol.h"

#ifndef BUTTON_H_
#define BUTTON_H_

/* IRQ priority for PIO (The lower the value, the greater the priority) */
#define IRQ_PRIOR_PIO    0	
#define IRQ_PRIOR_PIO1	 1

/* Press any button to start the game, 0 not started, 1 started. */
extern uint8_t START_GAME;
/* When user is choosing between the cells, the CONTINUE-GAME is set 0;
	once the user decides their cell, it is set to 1.			*/
extern uint8_t CONTINUE_GAME;
/* Report if an interrupt has happened inside the flash function */
extern uint8_t INTERRUPTED;
/* Record the current position, led flashing if the cell is available */
extern uint8_t CURRENT_CELL;

void configure_buttons(void);
uint8_t next_available_led(uint8_t current);

#endif /* BUTTON_H_ */