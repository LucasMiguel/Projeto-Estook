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

