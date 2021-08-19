
/*
 * Sketch feito com base:
 * 1)https://www.carnetdumaker.net/articles/faire-une-barre-de-progression-avec-arduino-et-liquidcrystal/ em 05/2020
 * 2)http://mikrokontroler.pl/2017/07/05/akcelerometr-i-magnetometr-kamodlms303-arduino/
 * 3)https://www.youtube.com/watch?v=Swr2Q1IFiBM
 */

//Bibliotecas
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <LSM303.h>

//bussola/acelerometro. define pinos A4(SDA) e A5(SCL)
LSM303 compass;

//Constantes: LCD/Menus
LiquidCrystal_I2C lcd(0x27, 20, 3);
#define menu_max 3

//Botoes
#define Bot1Enter 11 //Enter
#define Bot2Esq 12 //Esquerda
#define Bot3Dir 10 //Direita

//Funções
void MudarMenu();
void MostrarMenu();
void Compasso();
void Config_barprogresso();
void Calibrar();
void Bar_progresso();
void Nivelamento();
void Inclinacao();

//Variaveis globais
float acc_x,
      acc_y,
      ax_offset = 0,
      ay_offset = 0;

const int LCD_NB_ROWS = 2;
const int LCD_NB_COLUMNS = 16;

byte DIV_0_OF_5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // 0/5
byte DIV_1_OF_5[8] = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000}; // 1/5
byte DIV_2_OF_5[8] = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // 2/5
byte DIV_3_OF_5[8] = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11100}; // 3/5
byte DIV_4_OF_5[8] = {B11110,B11110,B11110,B11110,B11110,B11110,B11110,B11110}; // 4/5
byte DIV_5_OF_5[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111}; // 5/5

static byte percent = 0; //Valor percentual da barra de progresso

int contador = 0; //Contador do calibrador

char menu = 0x01, //Ao ligar aparece o menu1
     set1 = 0x00, //Variáveis de acionamento
     set2 = 0x00;

boolean e_Bot1Enter = 0x00, //variaveis de estado dos botões
        e_Bot2Esq = 0x00,
        e_Bot3Dir = 0x00;

////////////////////////////////////
void setup(){
  
  //saída LCD
  lcd.init();
  lcd.backlight();

  //configuração da barra de progresso
  Config_barprogresso();
   
  //Botoes
  pinMode(Bot1Enter, INPUT_PULLUP); //definição de entradas dos botões
  pinMode(Bot2Esq, INPUT_PULLUP);
  pinMode(Bot3Dir, INPUT_PULLUP);

  e_Bot1Enter = 0x00; //limpar o estado dos botões
  e_Bot2Esq = 0x00;
  e_Bot3Dir = 0x00;

  //Inicializacao da bussola
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  compass.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};

  //Calibração automática da bússola 
  Calibrar();
  percent = 0;
  lcd.clear();
}

//////////////////////
void loop(){

     MudarMenu();
     MostrarMenu();
}
