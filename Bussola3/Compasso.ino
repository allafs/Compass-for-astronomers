//Função bússola

void Compasso(){ 

  lcd.setCursor(0,0);
  lcd.print("< Bussola Magn >");
      
  if(!digitalRead(Bot1Enter))e_Bot1Enter = 0x01; //Botão Enter pressionado? Seta flag
  
  if(digitalRead(Bot1Enter) && e_Bot1Enter){     //Botão Enter solto e flag setada?
                                                 //Sim...
     e_Bot1Enter = 0x00;                         //Limpa flag
     set1++;                                     //Incrementa set1
     
     if(set1 > 2) set1 = 0x01;                   //Se maior que 2, volta a ser 1
     
     while (set1 == 0x01){
                                   
          compass.read();
          int heading = compass.heading();
          lcd.setCursor(0,1);
          lcd.print(heading);
          lcd.write(B11011111);

          if(heading >= 0 && heading <= 5 ){
            lcd.print(" Norte          ");
          }
          if(heading > 5 && heading < 85){
            lcd.print(" Nordeste       ");
          }
          if(heading >= 85 && heading <= 95){
            lcd.print(" Leste          ");
          }
          if(heading > 95 && heading < 175){
            lcd.print(" Sudeste        ");
          }
          if(heading >= 175 && heading <= 185){
            lcd.print(" Sul            ");
          }
          if(heading > 185 && heading < 265){
            lcd.print(" Sudoeste       ");
          }
          if(heading >= 265 && heading <= 275){
            lcd.print(" Oeste          ");
          }
          if(heading > 275 && heading < 355){
           lcd.print(" Noroeste       ");
          }
          if(heading >= 355 && heading <= 360){
            lcd.print(" Norte          ");
          }
                   
          if(!digitalRead(Bot1Enter))e_Bot1Enter = 0x01; //Botão Enter pressionado? Seta flag
          if(digitalRead(Bot1Enter) && e_Bot1Enter){     //Botão Enter solto e flag setada?
                                                         //Sim...
          e_Bot1Enter = 0x00;                         //Limpa flag
          set1++;                                 
          }
          delay(300); 
      }
    }
}
