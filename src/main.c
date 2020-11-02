#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "acia.h"
#include "lcd.h"
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


void print_f(const char * s){
  acia_put_newline();
  acia_puts(s);
  lcd_put_text(s);
}





void main(void) {
  line = 0;
  lcd_init();


  //print_f("No nazdar");

  while(1)
  {
    c = acia_getc();
    print_f("Volove");
  }

}
