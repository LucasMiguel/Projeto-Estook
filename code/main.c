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
#use fast_io(C)
#use I2C(master, sda=PIN_b0, scl=PIN_b1, ADDRESS = 0X01, FAST = 100000, STREAM = I2C_LCD)
#include <stdio.h>
#include <functions.h> //Biblioteca auxiliar com todas as fun��es de comando


void main()
{
   output_b(0);    
   output_d(0); 
   output_c(0); 
   set_tris_b(0b1111000); //setando as portas como 1=input || 0=output
   set_tris_c(0); 
   LCD_Begin(0x4E); 
   Start();
   while(TRUE){
      if(input(pin_B5)){         
         if(input(pin_B6)){                 
               LCD_Goto(2,2);
               LCD_Out("                    ");                //Limpara o display   
               LCD_Goto(2,2);
               LCD_Out("Iniciado");
               //Lamps();
               PassadorPag();
         }else{                                               //Teste para as portas fechadas 
                                          
         }
      }
      delay_ms(200);
   }
}


