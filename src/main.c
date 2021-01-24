#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "duart.h"
#include "kernel_c_lib.h"


void main(void) {
  duart_init();
  duart_puts("Ahoj zdravi Vas P65 a test klavesnice!!");
  duart_put_newline();
  duart_puts("Ted muzes zacit psat.");
  //PRNL();


  while(1){
  //CHROUT(CHRIN());
  CHROUT(duart_getc());
  }
}
