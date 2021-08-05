#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool Sistema::userNotLogged(int id) {
  auto iteratorUser = usuariosLogados.find(id);

  return iteratorUser == usuariosLogados.end();
}

bool Sistema::serverNotExist(string nome){
  for (int i = 0; i < this->servidores.size(); i++){
    if(servidores[i].getNome() == nome){
      return false;
    }
  }

  return true;
}

int Sistema::serverIndexByName(string nome){
  for (int i = 0; i < this->servidores.size(); i++){
    if(servidores[i].getNome() == nome){
      return i;
    }
  }

  return 0;
}

string Sistema::quit() {
  return "Saindo..";
  exit(0);
}

string Sistema::create_user (const string email, const string senha, const string nome) {
  cout << "Criando usuário " << nome << " (" << email << ")" << endl;
  for (int i = 0; i < this->usuarios.size(); i++){
    if(this->usuarios[i].email == email) return "Usuário já existe!";
  }

  int sizeUsers = this->usuarios.size();

  int id;
  if(sizeUsers < 1){
    id = 0;
  }else {
    id = sizeUsers;
  }

  this->usuarios.push_back({id, nome, email, senha});

  return "Usuário criado";
}

string Sistema::login(const string email, const string senha) {
  for (int i = 0; i < this->usuarios.size(); i++){
    if(this->usuarios[i].email == email && this->usuarios[i].senha == senha){
      usuariosLogados.insert(pair<int, pair<string, string>>(usuarios[i].id, make_pair("", "")));
      return "Logado com " + email;
    }
  }
  return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
  if(userNotLogged(id)) return "Não está conectado";

  this->usuariosLogados.erase(id);

  return "Usuário '" + usuarios[id].email + "' desconectado!";
}

string Sistema::create_server(int id, const string nome) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(!serverNotExist(nome)) return "Servidor com esse nome já existe";

  Servidor server(id, nome);

  servidores.push_back(server);

  return "Servidor '" + nome + "' criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não existe";

  int serverIndex = serverIndexByName(nome);
  if(servidores[serverIndex].getUsuarioDonoId() != id) return "Você não pode alterar a descrição de um servidor que não foi criado por você";

  servidores[serverIndex].setDescricao(descricao);

  return "Descrição do servidor '" + nome + "' modificada!";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não existe";

  int serverIndex = serverIndexByName(nome);
  if(servidores[serverIndex].getUsuarioDonoId() != id) return "Você não pode alterar o código de convite de um servidor que não foi criado por você";

  servidores[serverIndex].setCodigoConvite(codigo);

  if(codigo.length() > 0){
    return "Código de convite do servidor '" + nome + "' modificado!";
  }else {
    return "Código de convite do servidor '" + nome + "' removido!";
  }
}

string Sistema::list_servers(int id) {
  if(userNotLogged(id)) return "Usuário não está logado";

  for (int i = 0; i < this->servidores.size(); i++){
    if(i == servidores.size()-1)
      cout << servidores[i].getNome();
    else
      cout << servidores[i].getNome() << endl;
  }

  return "";
}

string Sistema::remove_server(int id, const string nome) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não encontrado";

  int serverIndex = serverIndexByName(nome);
  if(servidores[serverIndex].getUsuarioDonoId() != id) return "Você não é o dono do servidor " + nome;

  // Change Pair<Server, Channel> to Pair<"", "">
  for (int i = 0; i < usuariosLogados.size(); i++){
    auto iteratorUser = usuariosLogados.find(i);
    if(iteratorUser->second.first == nome){
        iteratorUser->second.first = "";
        iteratorUser->second.second = "";
    }
  }

  // remove server
  for(auto it = servidores.begin(); it != servidores.end();){
    if((*it).getNome() == nome){
      it = this->servidores.erase(it);
      break;
    }
  }

  return "Servidor '" + nome + "' removido com sucesso";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não encontrado";

  for (int i = 0; i < this->servidores.size(); i++){
    if(servidores[i].getNome() == nome){

      string code = servidores[i].getCodigoConvite();
      int owner = servidores[i].getUsuarioDonoId();
      float isOwner = false;
      float isEnabled = false;

      if(owner == id) isOwner = true;

      if(code.size() > 0 && codigo.size() == 0 && !isOwner) return "Servidor requer código de convite";
      else if(servidores[i].participantIsConected(id)) return "Você já está nesse servidor";
      else if(code == codigo) isEnabled = true;
      else return "Código inválido";

      if(code.size() == 0 || isOwner || isEnabled){
        servidores[i].addParticipant(id);

        auto iteratorUser = usuariosLogados.find(id);
        iteratorUser->second.first = nome;
        iteratorUser->second.second = "";
      };

      break;
    }
  }

  return "Entrou no servidor '" + nome + "' com sucesso";
}

string Sistema::leave_server(int id, const string nome) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não encontrado";

  for (int i = 0; i < this->servidores.size(); i++){
    if(servidores[i].getNome() == nome){
      auto iteratorUser = usuariosLogados.find(id);

      // verifica se o usuário está em algum servidor
      if(iteratorUser->second.first.size() == 0) return "Você não está em qualquer servidor";
      // verifica se o usuário está listado nos participantsIDs
      if(!servidores[i].participantIsConected(id)) return "Você não está nesse servidor";

      servidores[i].removeParticipant(id);
      iteratorUser->second.first = "";
      iteratorUser->second.second = "";
      break;
    }
  }

  return "Saindo do servidor" + nome;
}

string Sistema::list_participants(int id) {
  if(userNotLogged(id)) return "Usuário não está logado";

  auto iteratorUser = usuariosLogados.find(id);
  string nome = iteratorUser->second.first;

  for (int i = 0; i < this->servidores.size(); i++){
    if(servidores[i].getNome() == nome){
      servidores[i].listParticipants(usuarios);

      break;
    }
  }

  return "";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
