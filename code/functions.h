#include <I2C_LCD.c> //Biblioteca de controle do Display por I2C
//Fun��o para iniciar o display
void Start(){   
   //LCD_Goto(coluna, linha);        
   LCD_Goto(2, 2);                         
   LCD_Out("Carregando .");
   delay_ms(300);
   LCD_Goto(14, 2);
   LCD_Out(".");   
   delay_ms(300);
   LCD_Goto(15, 2);
   LCD_Out(".");
   delay_ms(300);
   LCD_Goto(16, 2);
   LCD_Out(".");
   delay_ms(300);
   LCD_Goto(1, 2);
   LCD_Out("                    ");                //Limpara o display   
   LCD_Goto(2, 2);                                // Go to column 2 row 3
   LCD_Out("Clique em iniciar"); 
}

void CloseDoor(){
   LCD_Goto(2,2);
   LCD_Out("                    ");                //Limpara o display   
   LCD_Goto(2,2);
   LCD_Out("Fecha Porta");
}

// Fun��o de constrole do andar das l�mpadas ==========================================
void Lamps(){                                      
   unsigned int8 speed_ = 2000;                    //Velocidade dos motores
   
   for(;;){                                        //Fun��o para mover as lampadas
      if(input(pin_B7)){                           //Teste para saber se est� no final. Se n�o estiver ela ir� para o ponto inicial         
         for(int i=0; i<3; i++){                   //ir� para o meio da pagina para come�ar a esteriliza��o            
            output_c(0b00000101);
            delay_ms(speed_);
            output_c(0b00000110);
            delay_ms(speed_);
            output_c(0b00010010);
            delay_ms(speed_);
            output_c(0b00010001);
            delay_ms(speed_);        
         }
         delay_ms(2000);                         //Tempo de espera de 40 segundos para estereliza��o  
         for(;;){                                //Fun��o que retornar� as lampadas para o est�gio inicial            
            output_c(0b00000110);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_c(0b00000101);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_c(0b00010001);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_c(0b00010010);
            delay_ms(speed_);
            if(input(pin_B7)) break;
         }   
         break;
      }else{                                    //Caso n�o esteja na posi��o inicial essa fun��o ir� levar at� la               
         for(;;){                  
            output_c(0b00000110);
            delay_ms(speed_);
            if(input(pin_B7)) break;            //Teste se chegou na posi��o inicial
            output_c(0b00000101);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_c(0b00010001);
            delay_ms(speed_);
            if(input(pin_B7)) break;
            output_c(0b00010010);
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
   LCD_Goto(2, 2);  
   LCD_Out("                    ");                //Limpara o display
   LCD_Goto(2, 2);  
   LCD_Out("Passando pagina"); 
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
   delay_ms(5000);   
}

