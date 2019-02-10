#ifndef HHKB_AVR_H
#define HHKB_AVR_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


// Timer resolution check
#if (1000000/TIMER_RAW_FREQ > 20)
#   error "Timer resolution(>20us) is not enough for HHKB matrix scan tweak on V-USB."
#endif


/*
 * HHKB Matrix I/O
 *
 * row:     HC4051[A,B,C]  selects scan row0-7
 * row-ext: [En0,En1] row extention for JP
 * col:     LS145[A,B,C,D] selects scan col0-7 and enable(D)
 * key:     on: 0/off: 1
 * prev:    hysteresis control: assert(1) when previous key state is on
 */


#if defined(__AVR_ATmega32U4__)
/*
 * For TMK HHKB alt controller(ATMega32U4)
 *
 * row:     PB0-2
 * col:     PB3-5,6
 * key:     PD7(pull-uped)
 * prev:    PB7
 * power:   PD4(L:off/H:on)
 * row-ext: PC6,7 for HHKB JP(active low)
 */

/*
 * Control BCD chip
 */
static inline void KEY_ENABLE(void) { (PORTB &= ~(1<<6)); }
static inline void KEY_UNABLE(void) { (PORTB |=  (1<<6)); }

/* 
 * Check input from Capacitive sensor.
 * Is low for pressed key.
 */
static inline bool KEY_STATE(void) { return !(PIND & (1<<7)); }

/*
 * Capacitive sensor wants to know the previos value
 */
//static inline void KEY_PREV_ON(void) { (PORTB |=  (1<<7)); }
//static inline void KEY_PREV_OFF(void) { (PORTB &= ~(1<<7)); }
static inline void KEY_PREV_ON(void) { (PORTD |=  (1<<1)); }
static inline void KEY_PREV_OFF(void) { (PORTD &= ~(1<<1)); }

/*
 * Dummy functions.
 * Board could be powered down by mosfet here.
 */
static inline void KEY_POWER_ON(void) {}
static inline void KEY_POWER_OFF(void) {}
static inline bool KEY_POWER_STATE(void) { return true; }

static inline void KEY_INIT(void)
{
  /* row,col,prev: output */
  //DDRB  = 0xFF;
  //PORTB = 0x40;   // unable
  //[> key: input with pull-up <]
  //DDRD  &= ~0x80;
  //PORTD |=  0x80;


  /* 
   * PB7 is not used.
   * All others are output.
   */
  DDRB  = 0x7F;
  PORTB = 0x00;

  KEY_UNABLE();
  KEY_PREV_OFF();

  // PD0 and PD1 are both used as output
  // PD7 is used as input, with pullup
  DDRD = 0x03;
  PORTD = 0x80;


  KEY_POWER_OFF();
}
static inline void KEY_SELECT(uint8_t ROW, uint8_t COL)
{
  PORTB = (PORTB & 0x40) | ((COL & 0x07)<<3) | (ROW & 0x06);
  PORTD = (PORTD & 0xFE) | (ROW & 0x01);
}


#else
#   error "define code for matrix scan"
#endif

#endif
