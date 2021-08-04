#include "servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Servidor::Servidor(int usuarioDonoId, string nome){
  this->usuarioDonoId = usuarioDonoId;
  this->nome = nome;
}

void Servidor::addParticipant(int id){
  this->participantesIDs.push_back(id);
}

void Servidor::setDescricao(string descricao){
  this->descricao = descricao;
}

void Servidor::setCodigoConvite(string codigo){
  this->codigoConvite = codigo;
}

string Servidor::getNome(){
  return this->nome;
}

int Servidor::getUsuarioDonoId(){
  return this->usuarioDonoId;
}

string Servidor::getCodigoConvite(){
  return this->codigoConvite;
}
