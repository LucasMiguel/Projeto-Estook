//Fun��o para iniciar o display
void Start(){
   lcd_init();  // Initialize LCD module
   lcd_putc('\f');                                // Clear LCD
   lcd_gotoxy(4, 2);                              // Go to column 2 row 1
   lcd_putc("Carregando .");
   delay_ms(300);
   lcd_gotoxy(14, 2);
   lcd_putc(".");   
   delay_ms(300);
   lcd_gotoxy(15, 2);
   lcd_putc(".");
   delay_ms(300);
   lcd_gotoxy(16, 2);
   lcd_putc(".");
   delay_ms(300);
   lcd_putc('\f');   
   lcd_gotoxy(2, 2);                              // Go to column 2 row 3
   lcd_putc("Clique em iniciar"); 
}

void Lamps(){
   unsigned int8 speed_;
   lcd_putc('\f');   
   lcd_gotoxy(2, 2);    
   for(;;){
      if(input(pin_B7)){
         lcd_putc("Para Frente");
         for(int i=0; i<3; i++){
            speed_ = 1000;
            output_c(0b00000101);
            delay_ms(speed_);
            output_c(0b00000110);
            delay_ms(speed_);
            output_c(0b00010010);
            delay_ms(speed_);
            output_c(0b00010001);
            delay_ms(speed_);        
         }
         delay_ms(2000);
         for(;;){      
            speed_ = 1000;
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
      }else{
         lcd_putc("Para Tras");
         for(;;){      
            speed_ = 1000;
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
      }
   }   
   delay_ms(2000);
}

void PassadorPag(){
   unsigned int8 speed_;
   lcd_putc('\f');   
   lcd_gotoxy(2, 2);  
   lcd_putc("Passando pagina"); 
   for(;;){      
      speed_ = 1000;
      output_a(0b00000110);
      delay_ms(speed_);
      if(input(pin_B3)) break;
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
   delay_ms(2000);
}

