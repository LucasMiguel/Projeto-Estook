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
   lcd_gotoxy(2, 2);                              // Go to column 2 row 1
   lcd_putc("Clique em iniciar"); 
}

void Lamps(){
   for(int i=0; i<3; i++){
      output_c(0b00010011);
      delay_ms(100);
      output_c(0b00010110);
      delay_ms(100);
      output_c(0b00011100);
      delay_ms(100);
      output_c(0b00011001);
      delay_ms(100);
   }   
   delay_ms(1000);
   /*for(int j=0; j<3; j++){      
      output_c(0b00001100);
      delay_ms(100);
      output_c(0b00000110);
      delay_ms(100);
      output_c(0b00000011);
      delay_ms(100);
      output_c(0b00001001);
      delay_ms(100);
   } */  
}

void PassadorPag(){
   


}

