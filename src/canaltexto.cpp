#include "canaltexto.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <ctime>

CanalTexto::CanalTexto(string nome){
  this->nome = nome;
}

string CanalTexto::getName(){
  return this->nome;
}

void CanalTexto::addMessage(time_t date, int id, string message){
  char mbstr[100];
  std::strftime(mbstr, 100, "%d/%m/%Y - %T", std::localtime(&date));
  std::string dateAjoutSysteme (mbstr);

  Mensagem menssagem(dateAjoutSysteme, id, message);

  this->mensagens.push_back(menssagem);
}

void CanalTexto::listMessages(vector<Usuario> usuarios){
  int size = this->mensagens.size();

  if(size == 0) {
    cout << "Sem mensagens para exibir" << endl;
  }else{
    for (int i = 0; i < size; i++){
      cout << usuarios[this->mensagens[i].enviadaPor].nome << "<" << this->mensagens[i].dataHora << ">: " << this->mensagens[i].conteudo << endl;
    }
  }
}
