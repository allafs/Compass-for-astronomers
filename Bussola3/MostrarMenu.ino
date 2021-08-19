//Função para mostrar o menu

void MostrarMenu(){
  
  switch(menu){                                       //Controle da variável menu
    
       case 0x01:                                       //Caso 1
             Compasso();                               //Chama a Bussola
             
             break;                                     //break
       case 0x02:                                       //Caso 2
             Nivelamento();                             //Chama Nivelamento
             
             break;                                     //break
       case 0x03:                                       //Caso 3
             Inclinacao();                              //Chama Inclinação
            
             break;                                     //break
       
  }
}
