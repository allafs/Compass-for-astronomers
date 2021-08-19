//Armazena caracteres personalizados na memória da tela LCD para a
//barra de progresso.

void Config_barprogresso() {
  lcd.createChar ( 0 , DIV_0_OF_5);
  lcd.createChar ( 1 , DIV_1_OF_5);
  lcd.createChar ( 2 , DIV_2_OF_5);
  lcd.createChar ( 3 , DIV_3_OF_5);
  lcd.createChar ( 4 , DIV_4_OF_5);
  lcd.createChar ( 5 , DIV_5_OF_5);
}
