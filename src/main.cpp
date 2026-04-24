#include <Arduino.h>

char palavra[10] = "OLA MUNDO";
char palavra2[10] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};

 String nomeCompleto = "Thiago";

void setup() 
{
  Serial.begin(9600);
  Serial.println();
  
  Serial.println(palavra);
  Serial1.println(palavra2);

  strcpy(palavra, "SENAI");
  
  Serial.println(palavra);
  
  //função strcmp: analisa a ordem léxica das palavras
  if(strcmp(palavra, "SENAI") == 0)
  {
    Serial.println("São iguais");
  }

  else if(strcmp(palavra, "SENAI") > 0)
  {
    Serial.println("A Segunda palavra vem antes da primeira palavra em ordem lexica");
  }

  else // < 0
  {
    Serial.println("A Primeira palavra vem antes da segunda palavra em ordem lexica");
  }

  if(strncmp(palavra2, "OLA", 3) == 0)
  {
    Serial.println("As primeiras letras da palavra são iguais");
  }

  //strstr: procura uma string dentro da string/cadeia de caracteres dentro de outra
  if(strstr(palavra2, "MUNDO"))
  {
    Serial.println("Palavra MUNDO detectada");
  }

  Serial.print("A string tem ");
  Serial.print(strlen(palavra2));
  Serial.println("Letras");

  //strchr: pesquisa um caractere na string / retorna a posicao que se encontra a primeira ocorrencia do caractere 
  strchr(palavra2, 'M');

  Serial.println(strchr(palavra2, 'M')); // MUNDO\0

  strcpy(palavra, "45");

  int numeroRecebido = atoi(palavra); // ASCII TO INT
  Serial.println(numeroRecebido * 2); // 90

  char fraseComposta[30];
  strcpy(fraseComposta, palavra2);
  strcat(fraseComposta, palavra);
  Serial.println(fraseComposta); //OLA MUNDO45

  //!------------------String--------------------

  String palavra3 = "HOJE EH QUINTA!";

  Serial.println(palavra3.length());
  Serial.println(palavra3.charAt(8)); //"HOJE EH (Q)UINTA"
  
  Serial.println(palavra3.indexOf('Q')); //8
  Serial.println(palavra3.substring(8, 13)); //QUINTA
  
  Serial.println(palavra3.indexOf('E')); //3
  Serial.println(palavra3.lastIndexOf('E')); //5

  if(palavra3.equals("HOJE EH SEXTA!!!")) //compara duas strings
  {
    Serial.println("hoje é sexta!!!");
  }

  else
  {
    Serial.println("Errooooooooouuuuuu, hj n é sexta");
  }

  if(palavra3.equalsIgnoreCase("hoje eh quinta!"))
  {
    Serial.println("Sim, hoje ainda é quinta feira");
  }

  if(palavra3.startsWith("HOJE"))
  {
    Serial.println("a string começa com a palavra HOJE");
  }

  if(palavra3.endsWith("INTA!"))
  {
    Serial.println("a string termina com INTA!");
  }

  String valor = "peso 123kg";

  int valorNumerico = valor.toInt();
  Serial.println(valorNumerico * 10);

  palavra3.toLowerCase();
  Serial.println(palavra3);

  palavra3.toUpperCase();
  Serial.println(palavra3);

  String textoLed = "Led = ON";
  textoLed.replace("ON", "OFF");

  Serial.println(textoLed);

  String novaFrase = "texto      ";
  Serial.println(novaFrase);

  if(novaFrase.equals("texto"))
  {
    Serial.println("Sao iguais");
  }

  else
  {
    Serial.println("Nao sao iguais");
  }

  novaFrase.trim(); //remove espacos e o \n \r \t do fim do texto

  if(novaFrase.equals("texto"))
  {
    Serial.println("Sao iguais");
  }

  else
  {
    Serial.println("Não são iguais");
  }

  novaFrase.concat(" final");
  Serial.println(novaFrase);

  novaFrase = novaFrase + "do final";
  Serial.println(novaFrase);
  
  const char* vetorCaracteres = novaFrase.c_str();
  Serial.println(vetorCaracteres);

  //Formatação na exibição
  char buffer[60]; //defino o maximo de caracter

  int anoAtual = 2026;

 // Serial.printf("Prof: %s Ano Atual: %d", nomeCompleto.c_str(), anoAtual);

  //snprintf: guarda o formato desejado respeitando o buffer estipulado
  snprintf(buffer, sizeof(buffer), "O prof %s é muito legal\n\rAno Atual: %d\n\r100%%", nomeCompleto.c_str(), anoAtual); 

  Serial.println(buffer);

}

void loop() 
{

}