// Incluir a biblioteca SoftwareSerial - já vem instalada na prórpia IDE
#include "SoftwareSerial.h"

// Crie uma nova série de software
SoftwareSerial bluetooth(2, 3); // pinos utilizados pelo TX e RX do módulo Bluetooth

const int ledPin = 11;// pino utilizado pelo LED
int Dados_Bluetooth;     // variável para ler os dados seriais recebidos

void setup() {
//Inicializa a série do software
bluetooth.begin(9600);
pinMode(ledPin, OUTPUT);  // indica o pino do LED como uma saída:
}

void loop() {
if (bluetooth.available()>0){ //se o valor recebido for maior que zero faz
Dados_Bluetooth = bluetooth.read(); // ler e salvar os dados
switch(Dados_Bluetooth)
{
case 'L': digitalWrite(ledPin, HIGH);break;  // caso seja L acende o led
case 'D': digitalWrite(ledPin, LOW);break;   // caso seja D apaga o led
default: break;
}
}
}