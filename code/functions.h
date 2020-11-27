#include <I2C_LCD.c> //Biblioteca de controle do Display por I2C
#include <kbd.c>  //Biblioteca do KeyPad
//Fun��o para iniciar o display
void Start(){   
   //LCD_Goto(coluna, linha);        
   LCD_Goto(3, 2);                         
   LCD_Out("Carregando .");
   delay_ms(100);
   LCD_Goto(14, 2);
   LCD_Out(".");   
   delay_ms(100);
   LCD_Goto(15, 2);
   LCD_Out(".");
   delay_ms(100);
   LCD_Goto(16, 2);
   LCD_Out(".");
   delay_ms(100);
   LCD_Goto(1, 2);   
   LCD_Cmd(LCD_CLEAR);                             //Limpara o display   
   delay_ms(100);   
}


//Fun��o feedback para fechar a porta
void CloseDoor(){
   LCD_Cmd(LCD_CLEAR);                             //Limpara o display  
   delay_ms(100);
   LCD_Goto(4,2);
   LCD_Out("Fecha Porta !!");
}

// Fun��o de constrole do andar das l�mpadas ==========================================
void Lamps(){                                      
   unsigned int8 speed_ = 2000;                    //Velocidade dos motores   
   for(;;){                                        //Fun��o para mover as lampadas
      if(input(pin_B7)){                           //Teste para saber se est� no final. Se n�o estiver ela ir� para o ponto inicial         
         for(int i=0; i<3; i++){                   //ir� para o meio da pagina para come�ar a esteriliza��o                         
            output_f(0b00000101);
            delay_ms(speed_);
            output_f(0b00000110);
            delay_ms(speed_);
            output_f(0b00001010);
            delay_ms(speed_);
            output_f(0b00001001);
            delay_ms(speed_);        
         }
         delay_ms(2000);                         //Tempo de espera de 40 segundos para estereliza��o  
         for(;;){                                //Fun��o que retornar� as lampadas para o est�gio inicial             
            output_f(0b00000110);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_f(0b00000101);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_f(0b00001001);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_f(0b0001010);
            delay_ms(speed_);
            if(input(pin_B7)) break;
         }   
         break;
      }else{                                    //Caso n�o esteja na posi��o inicial essa fun��o ir� levar at� la               
         for(;;){                  
            output_f(0b00000110);
            delay_ms(speed_);
            if(input(pin_B7)) break;            //Teste se chegou na posi��o inicial
            output_f(0b00000101);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_f(0b00001001);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_f(0b00001010);
            delay_ms(speed_);
            if(input(pin_B7)) break;
         }
      }
   }   
   delay_ms(2000);                              //Tempo de aguardo at� passar as p�ginas
}

//Fun��o que ir� passar as p�ginas ===============================================================
void PassadorPag(){   
   unsigned int8 speed_ = 1000;           //Velocidade dos motores
      for(;;){                               //Haste principal ir� para a frente at� encostar no livro
      output_a(0b00000110);
      delay_ms(speed_);
      if(input(pin_B3)) break;            //Teste se encostou no livro
      output_a(0b00000101);
      delay_ms(speed_);
      if(input(pin_B3)) break;
      output_a(0b00001001);
      delay_ms(speed_);
      if(input(pin_B3)) break;
      output_a(0b00001010);
      delay_ms(speed_);
      if(input(pin_B3)) break;
   }
   delay_ms(500);
   output_high(pin_B2);                    //Liga o FAN para segurar a p�gina
   delay_ms(1000);                        //Depois que tiver encostador ir� parar e esperar at� sugar a p�gina
   for(;;){                               //Ir� passar a pagina at� encostar do outro lado
      output_a(0b00000101);
      delay_ms(speed_);
      if(input(pin_B4)) break;            //Teste se chegou do outro lado
      output_a(0b00000110);
      delay_ms(speed_);
      if(input(pin_B4)) break;
      output_a(0b00001010);
      delay_ms(speed_);
      if(input(pin_B4)) break;
      output_a(0b00001001);
      delay_ms(speed_);       
      if(input(pin_B4)) break;
   }
   delay_ms(1000);                        
   output_low(pin_B2);                    //Desliga a FAN do Passador
   delay_ms(1000);  
                                 //Faz a haste secund�ria sair da pagina
   output_f(0b00010000);
   delay_ms(speed_);
   output_f(0b00110000);
   delay_ms(speed_);
   output_f(0b00100000);
   delay_ms(2000);  
   //Faz a Haste primaria ficar na vertical
   output_a(0b00000110);
   delay_ms(speed_);   
   output_a(0b00000101);
   delay_ms(speed_);
   //Faz a haste secud�ria voltar para a posi��o original
   output_f(0b00110000);      
   delay_ms(speed_);
   output_f(0b00010000);
   delay_ms(speed_);              
}

