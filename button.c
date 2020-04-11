/*
 * button.c
 *
 * Created: 2020-04-05 8:20:43 PM
 *  Author: l1598
 */ 
#include "button.h"

uint8_t START_GAME = 0;	// 0 or 1
uint8_t CONTINUE_GAME = 0; // 0 or 1
uint8_t CURRENT_CELL = 1; // 1 - 9

/* Return the next available cell, to the right and button, if there is one
	return the current cell, if there is none. */
uint8_t next_available_led(uint8_t current){
	int i, j;
	 
	for (i = 1; i <= 8; i++)
	{
		j = (current - 1 + i)%9 + 1;	// the position after i shifts from the current position
		if(led_state(j) == AVAILABLE_CELL){
			return j;
		}
	}
	return 0;
}
/**
 * \brief Process Buttons Events from button 1.
 */
static void ProcessButton1Evt()
{	
	CONTINUE_GAME = 0;
	if(START_GAME == 0){
		START_GAME = 1;
	}
	else{
		int current = next_available_led(CURRENT_CELL);
		CURRENT_CELL = current == 0? CURRENT_CELL : current;
	}
	
}

/**
 * \brief Process Buttons Events from button 2.
 */
static void ProcessButton2Evt()
{		
	CONTINUE_GAME = 0;
	if(START_GAME == 0){
		START_GAME = 1;
	}
	else{
		int current = next_available_led(CURRENT_CELL);
		CURRENT_CELL = current == 0? CURRENT_CELL : current;
	}
}

/**
 * \brief Process Buttons Events from button 3.
 */
static void ProcessButton3Evt()
{
	if(START_GAME == 0){
		START_GAME = 1;
	}
	else{
		CONTINUE_GAME = 1;	// Finish one round
	}  
}

/**
 * \brief Handler for Button 1 rising edge interrupt.
 * \param id The button ID.
 * \param mask The button mask.
 */
static void Button1_Handler(uint32_t id, uint32_t mask)
{
	if ((PIN_PUSHBUTTON_1_ID == id) && (PIN_PUSHBUTTON_1_MASK == mask))
		ProcessButton1Evt();
}

/**
 * \brief Handler for Button 2 rising edge interrupt.
 * \param id The button ID.
 * \param mask The button mask.
 */
static void Button2_Handler(uint32_t id, uint32_t mask)
{
	if ((PIN_PUSHBUTTON_2_ID == id) && (PIN_PUSHBUTTON_2_MASK == mask))
		ProcessButton2Evt();
}

/**
 * \brief Handler for Button 3 rising edge interrupt.
 * \param id The button ID.
 * \param mask The button mask.
 */
static void Button3_Handler(uint32_t id, uint32_t mask)
{
	if ((PIN_PUSHBUTTON_3_ID == id) && (PIN_PUSHBUTTON_3_MASK == mask))
		ProcessButton3Evt();
}



/**
 * \brief Configure the Pushbuttons.
 *
 * Configure the PIO as inputs and generate corresponding interrupt when
 * pressed or released.
 */
void configure_buttons(void)
{
	/* Configure Pushbutton 1. */
	pmc_enable_periph_clk(PIN_PUSHBUTTON_1_ID);
	pio_set_debounce_filter(PIN_PUSHBUTTON_1_PIO, PIN_PUSHBUTTON_1_MASK, 10);
	pio_handler_set(PIN_PUSHBUTTON_1_PIO, PIN_PUSHBUTTON_1_ID,
			PIN_PUSHBUTTON_1_MASK, PIN_PUSHBUTTON_1_ATTR, Button1_Handler);
	NVIC_EnableIRQ((IRQn_Type) PIN_PUSHBUTTON_1_ID);
	pio_handler_set_priority(PIN_PUSHBUTTON_1_PIO, (IRQn_Type) PIN_PUSHBUTTON_1_ID, IRQ_PRIOR_PIO1);//1 level priority
	pio_enable_interrupt(PIN_PUSHBUTTON_1_PIO, PIN_PUSHBUTTON_1_MASK);

	/* Configure Pushbutton 2. */
	pmc_enable_periph_clk(PIN_PUSHBUTTON_2_ID);
	pio_set_debounce_filter(PIN_PUSHBUTTON_2_PIO, PIN_PUSHBUTTON_2_MASK, 10);
	pio_handler_set(PIN_PUSHBUTTON_2_PIO, PIN_PUSHBUTTON_2_ID,
			PIN_PUSHBUTTON_2_MASK, PIN_PUSHBUTTON_2_ATTR, Button2_Handler);
	NVIC_EnableIRQ((IRQn_Type) PIN_PUSHBUTTON_2_ID);
	pio_handler_set_priority(PIN_PUSHBUTTON_2_PIO, (IRQn_Type) PIN_PUSHBUTTON_2_ID, IRQ_PRIOR_PIO1);//1 level priority
	pio_enable_interrupt(PIN_PUSHBUTTON_2_PIO, PIN_PUSHBUTTON_2_MASK);

	/* Configure Pushbutton 3. */
	pmc_enable_periph_clk(PIN_PUSHBUTTON_3_ID);
	pio_set_debounce_filter(PIN_PUSHBUTTON_3_PIO, PIN_PUSHBUTTON_3_MASK, 10);
	pio_handler_set(PIN_PUSHBUTTON_3_PIO, PIN_PUSHBUTTON_3_ID,
			PIN_PUSHBUTTON_3_MASK, PIN_PUSHBUTTON_3_ATTR, Button3_Handler);
	NVIC_EnableIRQ((IRQn_Type) PIN_PUSHBUTTON_3_ID);
	pio_handler_set_priority(PIN_PUSHBUTTON_3_PIO, (IRQn_Type) PIN_PUSHBUTTON_3_ID, IRQ_PRIOR_PIO);//0 level priority
	pio_enable_interrupt(PIN_PUSHBUTTON_3_PIO, PIN_PUSHBUTTON_3_MASK);
}