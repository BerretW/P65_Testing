#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//#include "utils.h"
#include "kernel_c_lib.h"


void main(void) {
  PRNTLN("Ahoj zdravi Vas P65 a test klavesnice!!");
  PRNTLN("Ted muzes zacit psat");
  PRNL();
  while(1){
    CHROUT(KBINPUT());
  }
}
