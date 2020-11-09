#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "acia.h"
#include "lcd.h"
#include "ym2612.h"


#include "song.h"
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
int song_pos = 0x3F;
int i;
int i2;
int waitL;
int waitH;
char cmd;

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


//char getByte(){
//  ++song_pos;
  //acia_putc(song[song_pos]);
  //delay();
//  return song[song_pos];
//}


void main(void) {
  line = 0;
  note = 0;
  lcd_init();
  ym_init();



while(1){
    //delay();
    cmd = getByte();
    switch (cmd) {
      case 0x50:
        getByte();
        break;
      case 0x52:
        ym_setreg(getByte(),getByte());
        break;
      case 0x53:
        ym_setreg_A1(getByte(),getByte());
        break;
      case 0x61:
        waitL = getByte();
        waitH = getByte();
        for (i=0; i <= waitH; ++i){
          for (i2 = 0; i2 <= waitL; ++i2){
            delay();
          }
        }
        break;
      case 0x62:
        for (i = 0; i <= 735; ++i){
          delay();
        }
        break;
      case 0x63:
        for (i = 0; i <= 835; ++i){
          delay();
        }
          break;
      case 0x70:
        for (i=1; i <= 1; ++i){
          delay();
        }
        break;
      case 0x71:

          for (i=1; i <= 2; ++i){
            delay();
          }
          break;
      case 0x72:
          for (i=1; i <= 3; ++i){
            delay();
          }
          break;
      case 0x73:
          for (i=1; i <= 4; ++i){
            delay();
          }
          break;
      case 0x74:
          for (i=1; i <= 5; ++i){
            delay();
          }
          break;
      case 0x75:
          for (i=1; i <= 5; ++i){
            delay();
          }
          break;
    }
}


}
