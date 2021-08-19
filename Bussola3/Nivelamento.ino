//Função nivelamento

void Nivelamento(){
    
    lcd.setCursor(0,0);
    lcd.print("<  Nivelamento >");
    
    if(!digitalRead(Bot1Enter))e_Bot1Enter = 0x01; //Botão Enter pressionado? Seta flag
    
    if(digitalRead(Bot1Enter) && e_Bot1Enter){     //Botão Enter solto e flag setada?
                                                 //Sim...
      e_Bot1Enter = 0x00;                         //Limpa flag
      set1++;                                     //Incrementa set1
     
      if(set1 > 2) set1 = 0x01;                   //Se maior que 2, volta a ser 1
     
      while (set1 == 0x01){                      
            
            byte setacima[8] = {0b00100,0b01110,0b10101,0b00100,0b00100,0b00100,0b00100,0b00100};
            lcd.createChar (1, setacima);
            byte setabaixo[8] = {0b00100,0b00100,0b00100,0b00100,0b00100,0b10101,0b01110,0b00100};
            lcd.createChar (2, setabaixo);
    
            int regis_X;
            int regis_Y;
        
            compass.readAcc();

            regis_X = (compass.a.x/1000);
            regis_Y = (compass.a.y/1000);

            lcd.setCursor(0,1);
            lcd.write(B01111110);
            lcd.print("+");
            lcd.write(B01111111);
            lcd.print("-:");
            lcd.print(regis_X);

            lcd.print("  ");        
            lcd.write(2);
            lcd.print("+");
            lcd.write(1);
            lcd.print("-:");
            lcd.print(regis_Y);
    
            lcd.print("  ");
    
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
  
