//Função de calibração da bússola

void Calibrar(){

    while (contador != 101){
          compass.read();
          
          LSM303::vector<int16_t> running_min = {-32767, -32767, -32767}, running_max = {32767, 32767, 32767};
      
          running_min.x = min(running_min.x, compass.m.x);
          running_min.y = min(running_min.y, compass.m.y);
          running_min.z = min(running_min.z, compass.m.z);

          running_max.x = max(running_max.x, compass.m.x);
          running_max.y = max(running_max.y, compass.m.y);
          running_max.z = max(running_max.z, compass.m.z);
    
          lcd.clear();
          lcd.setCursor (0,0); 
          lcd.print("Calibrando ");
          lcd.print (percent); 
          lcd.print (F("%"));
    
          lcd.setCursor (0,1); 
          byte nb_columns = map(percent,0,100,0,LCD_NB_COLUMNS * 5 );
    
          for (byte i=0; i<LCD_NB_COLUMNS; ++i){
            if (nb_columns == 0){ // Case 
              lcd.write((byte)0); 
            }
            else if(nb_columns >= 5){ // Caixa cheia 
            lcd.write(5); 
            nb_columns -= 5; 
            }
            else{ //Última caixa não vazia 
            lcd.write(nb_columns); 
            nb_columns = 0 ; 
            } 
          }
          if (++percent == 101){
            percent = 0;
            delay(1000);
          }
          delay(100);
          contador++;
    
   }
   lcd.setCursor(0,0);
   lcd.print("Calibrada! ");
   delay(3000);
}
