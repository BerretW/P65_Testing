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

  /* YM2612 Test code */
ym_setreg(0x22, 0x00); // LFO off
ym_setreg(0x27, 0x00); // Note off (channel 0)
ym_setreg(0x28, 0x01); // Note off (channel 1)
ym_setreg(0x28, 0x02); // Note off (channel 2)
ym_setreg(0x28, 0x04); // Note off (channel 3)
ym_setreg(0x28, 0x05); // Note off (channel 4)
ym_setreg(0x28, 0x06); // Note off (channel 5)
ym_setreg(0x2B, 0x00); // DAC off
ym_setreg(0x30, 0x71); //
ym_setreg(0x34, 0x0D); //
ym_setreg(0x38, 0x33); //
ym_setreg(0x3C, 0x01); // DT1/MUL
ym_setreg(0x40, 0x23); //
ym_setreg(0x44, 0x2D); //
ym_setreg(0x48, 0x26); //
ym_setreg(0x4C, 0x00); // Total level
ym_setreg(0x50, 0x5F); //
ym_setreg(0x54, 0x99); //
ym_setreg(0x58, 0x5F); //
ym_setreg(0x5C, 0x94); // RS/AR
ym_setreg(0x60, 0x05); //
ym_setreg(0x64, 0x05); //
ym_setreg(0x68, 0x05); //
ym_setreg(0x6C, 0x07); // AM/D1R
ym_setreg(0x70, 0x02); //
ym_setreg(0x74, 0x02); //
ym_setreg(0x78, 0x02); //
ym_setreg(0x7C, 0x02); // D2R
ym_setreg(0x80, 0x11); //
ym_setreg(0x84, 0x11); //
ym_setreg(0x88, 0x11); //
ym_setreg(0x8C, 0xA6); // D1L/RR
ym_setreg(0x90, 0x00); //
ym_setreg(0x94, 0x00); //
ym_setreg(0x98, 0x00); //
ym_setreg(0x9C, 0x00); // Proprietary
ym_setreg(0xB0, 0x32); // Feedback/algorithm
ym_setreg(0xB4, 0xC0); // Both speakers on
ym_setreg(0x28, 0x00); // Key off
ym_setreg(0xA4, 0x22);	//
ym_setreg(0xA0, 0x69); // Set frequency

  while(1)
  {
    c = acia_getc();
    print_f("Volove");
    if (note == 0){
      ym_setreg(0x28,c); // Key on
      note = 1;
    } else {
      ym_setreg(0x28,0); // Key on
      note = 0;
    }

  }

}
