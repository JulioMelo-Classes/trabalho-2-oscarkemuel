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

void Servidor::removeParticipant(int id){
  for(auto it = this->participantesIDs.begin(); it != this->participantesIDs.end();){
    if((*it) == id){
      it = this->participantesIDs.erase(it);
      break;
    }
  }
}

bool Servidor::participantIsConected(int id){
  bool isConected = false;

  for (int i = 0; i < this->participantesIDs.size(); i++){
    if(participantesIDs[i] == id){
      isConected = true;
      break;
    }
  }

  return isConected;
};

void Servidor::listParticipants(std::vector<Usuario> usuarios){
  for (int i = 0; i < this->participantesIDs.size(); i++){
    cout << usuarios[participantesIDs[i]].nome << endl;
  }
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
