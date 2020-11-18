#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "acia.h"
#include "lcd.h"
#include "ym2612.h"
#include "utils.h"

//#include "song.h"
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

int i;
int i2;
int CharL;
int CharH;
int playing;
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
//  if (song_pos == 0x4000){
//    song_pos = 0;
//    switch_bank();
//  }
  //acia_putc(song[song_pos]);
  //delay();
//  return song[song_pos];
//}
void PlayFromBank(){
	while(playing == 1){
    //delay();
    cmd = getByte();
    switch (cmd) {
      case 0x50:
        CharL = getByte();
        delay();
        break;
      case 0x52:
        CharL = getByte();
        CharH = getByte();
        ym_setreg(CharL,CharH);
        //acia_puts("Wr_A0_");
        //acia_putc(CharL);
        //acia_putc(CharH);
        //acia_put_newline();
        break;
      case 0x53:
      CharL = getByte();
      CharH = getByte();
      ym_setreg_A1(CharL,CharH);
      //acia_puts("Wr_A1_");
      //acia_putc(CharL);
      //acia_putc(CharH);
      //acia_put_newline();
        break;
      case 0x61:
        CharL = getByte();
        CharH = getByte();
        //acia_puts("Wait ");
        //acia_putc(CharL);
        //acia_putc(CharH);
        //acia_puts("H ms");
        //acia_put_newline();
        for (i=0; i <= CharH; ++i){
          for (i2 = 0; i2 <= CharL; ++i2){
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
          for (i=1; i <= 6; ++i){
            delay();
          }
          break;
      case 0x76:
          for (i=1; i <= 7; ++i){
            delay();
          }
          break;
      case 0x77:
          for (i=1; i <= 8; ++i){
            delay();
          }
          break;
          case 0x78:
              for (i=1; i <= 9; ++i){
                delay();
              }
              break;
          case 0x79:
              for (i=1; i <= 10; ++i){
                delay();
              }
              break;
          case 0x7A:
              for (i=1; i <= 11; ++i){
                delay();
              }
              break;
          case 0x7B:
              for (i=1; i <= 12; ++i){
                delay();
              }
              break;
          case 0x7C:
              for (i=1; i <= 13; ++i){
                delay();
              }
              break;
          case 0x7D:
              for (i=1; i <= 14; ++i){
                delay();
              }
              break;
          case 0x7E:
              for (i=1; i <= 15; ++i){
                delay();
              }
              break;
          case 0x7F:
            for (i=1; i <= 16; ++i){
              delay();
            }
            break;
      case 0x66:
        playing = 0;
        set_song_pos(0x003F);
        acia_puts("Konec");
      break;

    }
}


}


void main(void) {
  print_f("Appartus VGM Player Vas vita");
  line = 0;
  note = 0;
  lcd_init();
  ym_init();
  while(1){
    c = acia_getc();
  switch (c){
    case 'W':
      print_f("Zacinam zapis.");
      write_to_BANK();
    break;

    case 'F':
      print_f("Formatuji Banky");
      format_bank();
    break;

    case 'P':
      print_f("Spoustim song");
      set_song_pos(0x003F);
      playing = 1;
      PlayFromBank();
    break;
  }
  }
}
