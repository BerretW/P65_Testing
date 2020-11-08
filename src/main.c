#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "acia.h"
#include "lcd.h"
#include "ym2612.h"

//#include "vdp_low.h"
//#include "test.h"
//#include "bank.h"
//#include "wait.h"
//
//#include "utils.h"
//#include "wood_char.h"
//#include "sprite.h"
//#include "copyshort.h"

//#include "spi.h"
char c;
int line;
int note;

void lcd_put_text(char * s){
  char y = 0x80;

  switch (line) {
         case 0: y = 0x80; break;
         case 1: y = 0xc0; break;
         case 2: y = 0x90; break;
         case 3: y = 0xd0; break;
     }
  ++line;
  if (line > 3) line = 0;
  lcd_w_reg(y);
  lcd_puts(s);
}


void print_f(char * s){
  acia_put_newline();
  acia_puts(s);
  lcd_put_text(s);
}






void main(void) {
  line = 0;
  note = 0;
  lcd_init();
  ym_init();

  ym_setreg(0x00,0x22); // LFO off
  ym_setreg(0x00,0x27); // Note off (channel 0)
  ym_setreg(0x01,0x28); // Note off (channel 1)
  ym_setreg(0x02,0x28); // Note off (channel 2)
  ym_setreg(0x04,0x28); // Note off (channel 3)
  ym_setreg(0x05,0x28); // Note off (channel 4)
  ym_setreg(0x06,0x28); // Note off (channel 5)
  ym_setreg(0x00,0x2B); // DAC off
  ym_setreg(0x71,0x30); //
  ym_setreg(0x0D,0x34); //
  ym_setreg(0x33,0x38); //
  ym_setreg(0x01,0x3C); // DT1/MUL
  ym_setreg(0x23,0x40); //
  ym_setreg(0x2D,0x44); //
  ym_setreg(0x26,0x48); //
  ym_setreg(0x00,0x4C); // Total level
  ym_setreg(0x5F,0x50); //
  ym_setreg(0x99,0x54); //
  ym_setreg(0x5F,0x58); //
  ym_setreg(0x94,0x5C); // RS/AR
  ym_setreg(0x05,0x60); //
  ym_setreg(0x05,0x64); //
  ym_setreg(0x05,0x68); //
  ym_setreg(0x07,0x6C); // AM/D1R
  ym_setreg(0x02,0x70); //
  ym_setreg(0x02,0x74); //
  ym_setreg(0x02,0x78); //
  ym_setreg(0x02,0x7C); // D2R
  ym_setreg(0x11,0x80); //
  ym_setreg(0x11,0x84); //
  ym_setreg(0x11,0x88); //
  ym_setreg(0xA6,0x8C); // D1L/RR
  ym_setreg(0x00,0x90); //
  ym_setreg(0x00,0x94); //
  ym_setreg(0x00,0x98); //
  ym_setreg(0x00,0x9C); // Proprietary
  ym_setreg(0x32,0xB0); // Feedback/algorithm
  ym_setreg(0xC0,0xB4); // Both speakers on
  ym_setreg(0x00,0x28); // Key off
  ym_setreg(0x22,0xA4);//
  ym_setreg(0x69,0xA0); // Set frequency
  //print_f("No nazdar");

  while(1)
  {
    c = acia_getc();
    print_f("Volove");
    if (note == 0){
      ym_setreg(c,0x28); // Key on
      note = 1;
    } else {
      ym_setreg(0x00,0x28); // Key on
      note = 0;
    }

  }

}
