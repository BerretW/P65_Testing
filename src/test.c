#include "acia.h"
#include "lcd.h"

void udp_wr_reg(char red, char data){
  lcd_putc(red);
  acia_putc(data);
}
void vdp_wr_reg(char red, char data){
  lcd_putc(red);
  acia_putc(data);
}
