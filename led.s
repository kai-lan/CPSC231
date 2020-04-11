
/*
 * led.s
 *
 * Created: 2020-04-06 1:02:27 AM
 *  Author: l1598
 */ 

 .syntax unified

/* PMC see pg 520 documentation */
.equ PMC,	0x400E0400 /* PMC Base Address */
.equ PCER0, 0x10	/* Peripheral Clock Enable Register 0*/

/* PIOC see pg 575 documentation */
.equ PIOA,			0x400E0E00 /* PIOC Base Address */
.equ PIOB,			0x400E1000 /* PIOC Base Address */
.equ PIOC,			0x400E1200 /* PIOC Base Address */
.equ OER_OFFSET,	0x10	/* Output Enable Register */
.equ ODR_OFFSET,	0x14	/* Output Disable Register */
.equ SODR_OFFSET,	0x30	/* Set Output Data Register */
.equ CODR_OFFSET,	0x34	/* Clear Output Data Register */
.equ OWER_OFFSET,	0xA0	/* Output Write Enable Register*/

/* PIOC PID pg. 48*/
.equ PID13, 13	

.equ INPUT_DIR,  1 
.equ OUTPUT_DIR, 0
.equ LEVEL_HIGH, 1
.equ LEVEL_LOW,  0


.section .text

/* 
	enable peripheral clock line to PIOC 
*/
.thumb_func

pioc_init:		
	ldr r0, =(PMC + PCER0)
	mov r1, #1
	lsl r1, r1, PID13
	str r1, [r0] /* PCER0.bit13 = 1 */

	bx lr

/*	
	PIOA:
	Set PIO Line Direction  
	r0 = direction (1=input, 0=output)
	r1 = IO line (PC1 = 1, PC2 = 2, so forth)
*/
.thumb_func
.global pioa_dir_set
pioa_dir_set:	
	cmp r0, OUTPUT_DIR
	bne pioa_else_d
	ldr r0, =(PIOA + OER_OFFSET) 
	b pioa_end_d
pioa_else_d:
	ldr r0, =(PIOA + ODR_OFFSET) 
pioa_end_d:
	mov r2, #1
	lsl r2, r2, r1			
	str r2, [r0]	/* OxR.bitx = 1 */
pioa_enable_writing:
	ldr r0, =(PIOA + OWER_OFFSET) 
	mov r2, #1
	lsl r2, r2, r1
	str r2, [r0]	/* OWER.bitx = 1 */

	bx lr

/* 
	PIOA:
	Set PIO Line Level  
	r0 = level (1=high, 0=low)
	r1 = IO line (PC1 = 1, PC2 = 2, so forth)
*/
.thumb_func
.global pioa_level_set
pioa_level_set:
	cmp r0, LEVEL_HIGH
	bne pioa_else_l
	ldr r0, =(PIOA + SODR_OFFSET) 
	b pioa_end_l
pioa_else_l:
	ldr r0, =(PIOA + CODR_OFFSET) 
pioa_end_l:
	mov r2, #1
	lsl r2, r2, r1  
	str r2, [r0]	/* xODR.bitx = 1 */

	bx lr

/*	
	PIOB:
	Set PIO Line Direction  
	r0 = direction (1=input, 0=output)
	r1 = IO line (PC1 = 1, PC2 = 2, so forth)
*/
.thumb_func
.global piob_dir_set
piob_dir_set:	
	cmp r0, OUTPUT_DIR
	bne piob_else_d
	ldr r0, =(PIOB + OER_OFFSET) 
	b piob_end_d
piob_else_d:
	ldr r0, =(PIOB + ODR_OFFSET) 
piob_end_d:
	mov r2, #1
	lsl r2, r2, r1			
	str r2, [r0]	/* OxR.bitx = 1 */
piob_enable_writing:
	ldr r0, =(PIOB + OWER_OFFSET) 
	mov r2, #1
	lsl r2, r2, r1
	str r2, [r0]	/* OWER.bitx = 1 */

	bx lr

/* 
	PIOB:
	Set PIO Line Level  
	r0 = level (1=high, 0=low)
	r1 = IO line (PC1 = 1, PC2 = 2, so forth)
*/
.thumb_func
.global piob_level_set
piob_level_set:
	cmp r0, LEVEL_HIGH
	bne piob_else_l
	ldr r0, =(PIOB + SODR_OFFSET) 
	b piob_end_l
piob_else_l:
	ldr r0, =(PIOB + CODR_OFFSET) 
piob_end_l:
	mov r2, #1
	lsl r2, r2, r1  
	str r2, [r0]	/* xODR.bitx = 1 */

	bx lr

/*	
	PIOC:
	Set PIO Line Direction  
	r0 = direction (1=input, 0=output)
	r1 = IO line (PC1 = 1, PC2 = 2, so forth)
*/
.thumb_func
.global pioc_dir_set
pioc_dir_set:	
	cmp r0, OUTPUT_DIR
	bne pioc_else_d
	ldr r0, =(PIOC + OER_OFFSET) 
	b pioc_end_d
pioc_else_d:
	ldr r0, =(PIOC + ODR_OFFSET) 
pioc_end_d:
	mov r2, #1
	lsl r2, r2, r1			
	str r2, [r0]	/* OxR.bitx = 1 */
pioc_enable_writing:
	ldr r0, =(PIOC + OWER_OFFSET) 
	mov r2, #1
	lsl r2, r2, r1
	str r2, [r0]	/* OWER.bitx = 1 */

	bx lr

/* 
	PIOC:
	Set PIO Line Level  
	r0 = level (1=high, 0=low)
	r1 = IO line (PC1 = 1, PC2 = 2, so forth)
*/
.thumb_func
.global pioc_level_set
pioc_level_set:
	cmp r0, LEVEL_HIGH
	bne pioc_else_l
	ldr r0, =(PIOC + SODR_OFFSET) 
	b pioc_end_l
pioc_else_l:
	ldr r0, =(PIOC + CODR_OFFSET) 
pioc_end_l:
	mov r2, #1
	lsl r2, r2, r1  
	str r2, [r0]	/* xODR.bitx = 1 */

	bx lr

.end