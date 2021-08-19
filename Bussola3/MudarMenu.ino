//Função para mudar o menu

void MudarMenu(){

   if(!digitalRead(Bot2Esq)){e_Bot2Esq = 0x01;}          //Botão Esquerdo pressionado? Seta flag
   if(!digitalRead(Bot3Dir)){e_Bot3Dir = 0x01;}          //Botão Direito pressionado? Seta flag
      
   if(digitalRead(Bot2Esq) && e_Bot2Esq){          //Botão Esquedo solto e flag setada?
                                                   //Sim...
      e_Bot2Esq = 0x00;                            //Limpa flag
      
      lcd.clear();                                //Limpa display
      menu++;                                      //Incrementa menu
      
      if(menu > 0x03){ menu = 0x01;}                  //Se menu maior que 4, volta a ser 1
   } 
   
   if(digitalRead(Bot3Dir) && e_Bot3Dir){           //Botão Direito solto e flag setada?
                                                    //Sim...
      e_Bot3Dir = 0x00;                             //Limpa flag
      
      lcd.clear();                                 //Limpa display
      menu--;                                       //Decrementa menu
      
      if(menu < 0x01){ menu = 0x03;}                      //Se menu menor que 1, volta a ser 4
   }    
}
