//Função para desenhar a barra de progresso com a porcentagem a ser exibida. 

void Bar_progresso(){//Exibe o novo valor em formato numérico na primeira linha * / 
  
  lcd.clear();
  lcd.setCursor (0,0); 
  lcd.print (percent); 
  lcd.print (F("%"));
  
  // NB Os dois espaços no final da linha permitem apagar os números da porcentagem anterior // quando você passa de um valor com dois ou três dígitos para um valor com dois ou um dígitos. / * Mova o cursor para a segunda linha * / 
  lcd.setCursor (0,1); 
  
  //Mapeie o intervalo (0 ~ 100) para o intervalo (0 ~ LCD_NB_COLUMNS * 5) 
  byte nb_columns = map(percent,0,100,0,LCD_NB_COLUMNS * 5 );
  
  //Desenhe cada caractere da linha
  for (byte i=0; i<LCD_NB_COLUMNS; ++i){ 
  
  //Dependendo do número de colunas restantes a serem exibidas
    if (nb_columns == 0){ // Case 
        lcd.write((byte)0); 
    }else if(nb_columns >= 5){ // Caixa cheia 
      lcd.write(5); 
      nb_columns -= 5; 
     }else { //Última caixa não vazia 
       lcd.write(nb_columns); 
       nb_columns = 0 ; 
       } 
   //Incrementa a porcentagem
    percent ++;
    // Retorna a zero se a porcentagem exceder 100% 
   
  }
 delay(500);
}
