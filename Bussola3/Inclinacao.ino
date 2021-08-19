//Função de mostrar o ângulo de inclinação horizontal ou Latitude

void Inclinacao(){

    lcd.setCursor(0,0);
    lcd.print("<  Inclinacao  >");

    if(!digitalRead(Bot1Enter))e_Bot1Enter = 0x01; //Botão Enter pressionado? Seta flag
  
    if(digitalRead(Bot1Enter) && e_Bot1Enter){     //Botão Enter solto e flag setada?
                                                  //Sim...
      e_Bot1Enter = 0x00;                         //Limpa flag
      set1++;                                     //Incrementa set1
     
      if(set1 > 2) set1 = 0x01;                   //Se maior que 2, volta a ser 1
     
      while (set1 == 0x01){
     
            int regis_Y;
            compass.readAcc();
            regis_Y = (compass.a.y/100)*90/175*-1;
   
            lcd.setCursor(0,1);
            lcd.print("<= ");
            lcd.print(regis_Y);
            lcd.write(B11011111);
            lcd.print(" Latitude       ");
        
            if(!digitalRead(Bot1Enter))e_Bot1Enter = 0x01; //Botão Enter pressionado? Seta flag
            if(digitalRead(Bot1Enter) && e_Bot1Enter){     //Botão Enter solto e flag setada?
                                                           //Sim...
            e_Bot1Enter = 0x00;                            //Limpa flag
            set1++;                                 
            }
            delay(300); 
      } 
   }
}
