//Inicialização das constantes do led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;

// IInicializaçãos das constantes do botão 1 e 2
const int botao1 = 2;
const int botao2 = 3;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int botaoDelay = 100;

//Incicializacção do Setup
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

  Serial.begin(9600);

  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: ----> QUINTETO FANTÁSTICO  <-------");
}

//DETERMINANDO O LOOP

void loop()
{
  // REGRA DECISÃO DO BOTÃO 1
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
      Serial.println("Processo iniciado");
    ledVermelho(true);
      lastDebounceTime1 = millis();
 }

 //REGRA DECISÃO DO BOTÃO 2
  if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){
      Serial.println("Processo encerrado");
    ledVermelho(false);
      lastDebounceTime2 = millis();
  }
	
//REGRA DE DECISÃO DO LED AZUL
  if(getTemperatura() > 15){
    ledAzul(true);
    Serial.println("Temperatura acima do esperado");
  }else{
    ledAzul(false);
    Serial.println("Temperatura esperada");
  }
	
//REGRA DE DECISÃO DO LED VERDE
  if(getLuminosidade() > 5){
    ledVerde(true);
    Serial.println("Luminosidade acima do esperado");
  }else{
    ledVerde(false);
    Serial.println("Luminosidade esperada");
  }

  delay(10);
}

//DEFININDO ESTADOS DO LED
void ledVermelho(bool estado){
  digitalWrite(vermelho,estado);
}
void ledVerde(bool estado){
 digitalWrite(verde,estado);
}
void ledAzul(bool estado){
    digitalWrite(azul,estado);
}

// CÁLCULO DA TEMPERATURA EM GRAUS CÉLCIUS
int getTemperatura(){
      int temperaturaC; 
    temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
      return temperaturaC;
} 

// CÁLCULO DA LUMINOSIDADE
int getLuminosidade(){
      int luminosidade;
    luminosidade = map(analogRead(A1), 6, 619, -3, 10);
      return luminosidade;
}

