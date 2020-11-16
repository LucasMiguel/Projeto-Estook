//LCD module connections
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6
//End LCD module connections

#include <18F4550.h>
#fuses NOMCLR NOBROWNOUT NOLVP INTRC_IO
#device ADC = 10
#use delay(clock = 8000000)
#use fast_io(B)
#use fast_io(D)
#include <lcd.c>
#include <stdio.h>
#include <functions.h>

void main()
{
   output_b(0);    
   output_d(0); 
   output_c(0);    
   set_tris_c(0); 
   Start();
   while(TRUE){
      if(input(pin_B5)){
         lcd_gotoxy(4, 2);
         if(input(pin_B6)){            
               lcd_putc('\f');                                // Clear LCD
               lcd_putc("Iniciado");    
               output_high(pin_C5);                
               Lamps();                                       // Fun��o para mover as lampadas
              //PassadorPag();
         }else{            
               lcd_putc('\f');                                // Clear LCD
               lcd_putc("Fecha Porta");                           
         }
      }
      delay_ms(200);
   }
}


