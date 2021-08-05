#include "mensagem.h"
#include <iostream>
#include <sstream>
#include <algorithm>

Mensagem::Mensagem(string data, int id, string menssagem){
  this->dataHora = data;
  this->enviadaPor = id;
  this->conteudo = menssagem;
}
