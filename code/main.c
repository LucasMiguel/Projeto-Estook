#include <18F6490.h>
#fuses NOMCLR NOBROWNOUT INTRC_IO 
#device ADC = 10
#use delay(clock = 8000000)
#use fast_io(A)
#use fast_io(B)
#use fast_io(C)
#use fast_io(D)
#use fast_io(E)
#use fast_io(F)
#use I2C(master, sda=PIN_C4, scl=PIN_C3, ADDRESS = 0X01, FAST =100000, STREAM = I2C_LCD)
#use rs232(baud=9600, xmit= PIN_C6, rcv= PIN_C7, bits=8)
#include <stdio.h>
#include <stdlib.h>
#include <functions.h> //Biblioteca auxiliar com todas as fun��es de comando


//Variaveis para guardar valores do teclados
char k = 0;
char valuePagesChar[4];
int cont=0;
int valuePages = 0; //Quantidade de paginas que tem o livro
//===========================================

void main()
{
   output_b(0);    
   output_d(0); 
   output_c(0); 
   //set_tris_b(0b1111000); //setando as portas como 1=input || 0=output
   set_tris_a(0b11000000);
   set_tris_f(0b00000000);
   LCD_Begin(0x4E);
   kbd_init();
   Start();        
   LCD_Goto(2,2);
   LCD_Out("Qts paginas:");
   LCD_Goto(14,2);
   while(TRUE){  
      while(valuePages == 0){                                     //Loop para pegar valor do teclado         
         k = kbd_getc();                                          // read keypad input (if exists) 
         if(k!=0 && k!='*' && k !="#" && cont<4){                 // se a tecla for captaurada e n�o for "*" ou "#" ou for menor que 4 digitos      
            LCD_Out(k);                                           // print captured key to lcd
            valuePagesChar[cont] = k;
            k=0;                                                  // reset k for another loop round
            cont++;
            delay_ms(250);                                        // delay between key presses
         } 
         delay_ms(1);
         if(input(pin_B5)){
            valuePages= atoi(valuePagesChar); 
            if(valuePages != 0){
               break;
            }
         }    
      }      
      if(input(pin_B6)){                   //Teste para ver se as portas est�o fechadas
         LCD_Cmd(LCD_CLEAR);                             //Limpara o display
         delay_ms(100);
         LCD_Goto(7,2);
         LCD_Out("Iniciado!!");
         LCD_Goto(1,3);
         LCD_Out("Pag. restantes:");
         for(int i=0; i<valuePages;i++){  
            LCD_Goto(17,3);               
            printf(lcd_out, "%d", valuePages-i);   
            Lamps();
            PassadorPag();
         }
         Finish();         
      }else{                                               //Teste para as portas fechadas 
            CloseDoor();                                
      }      
   }   
}




