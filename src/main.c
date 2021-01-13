#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//#include "acia.h"
//#include "lcd.h"
//#include "ym2612.h"
#include "utils.h"
#include "kernel_c_lib.h"
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



void main(void) {
  PRNTLN("Ahoj zdravi Vas P65 a test klavesnice!!");
  PRNTLN("Ted muzes zacit psat");
  PRNL();
  while(1){
    CHROUT(KBINPUT());
  }

}
