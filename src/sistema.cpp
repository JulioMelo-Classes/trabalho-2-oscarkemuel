#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool Sistema::userNotLogged(int id) {
  std::map< int, std::pair<std::string, std::string> >::iterator iteratorUser;
  iteratorUser = usuariosLogados.find(id);

  // if(iteratorUser == usuariosLogados.end()) cout << "user: " << usuariosLogados[id].first << endl;
  // for (auto it:usuariosLogados){
  //   cout << it.first << endl;
  // }

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


/*
A1.2 ok
*/
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

  // cout << "ID: " << id << " USUARIO: " << email << endl;

  this->usuarios.push_back({id, nome, email, senha});

  return "Usuário criado";
}

/*
A1.3 ok
*/
string Sistema::login(const string email, const string senha) {
  for (int i = 0; i < this->usuarios.size(); i++){
    if(this->usuarios[i].email == email && this->usuarios[i].senha == senha){
      usuariosLogados.insert(pair<int, pair<string, string>>(usuarios[i].id, make_pair("", "")));
      return "Logado com " + email;
    }
  }
  return "Senha ou usuário inválidos!";
}

/*
A2.1 ok
*/
string Sistema::disconnect(int id) {
  if(userNotLogged(id)) return "Não está conectado";

  this->usuariosLogados.erase(id);

  return "Usuário '" + usuarios[id].email + "' desconectado!";
}

/*
A2.2 ok
*/
string Sistema::create_server(int id, const string nome) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(!serverNotExist(nome)) return "Servidor com esse nome já existe";

  Servidor server(id, nome);

  server.addParticipant(id);

  servidores.push_back(server);

  return "Servidor '" + nome + "' criado";
}

/*
A2.3 ok
*/
string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não existe";

  int serverIndex = serverIndexByName(nome);
  if(servidores[serverIndex].getUsuarioDonoId() != id) return "Você não pode alterar a descrição de um servidor que não foi criado por você";

  servidores[serverIndex].setDescricao(descricao);

  return "Descrição do servidor '" + nome + "' modificada!";
}

/*
A2.4 ok
*/
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

/*
A2.5 ok
*/
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

/*
A2.6 ok
*/
string Sistema::remove_server(int id, const string nome) {
  if(userNotLogged(id)) return "Usuário não está logado";
  else if(serverNotExist(nome)) return "Servidor '" + nome +"' não encontrado";

  int serverIndex = serverIndexByName(nome);
  if(servidores[serverIndex].getUsuarioDonoId() != id) return "Você não é o dono do servidor " + nome;

  // Change Pair<Server, Channel> to Pair<"", "">
  for (int i = 0; i < usuariosLogados.size(); i++){
    std::map< int, std::pair<std::string, std::string> >::iterator iteratorUser = usuariosLogados.find(i);
    if(iteratorUser->second.first == nome){
        iteratorUser->second.first = "";
        iteratorUser->second.second = "";
      }
  }

  // for (int i = 0; i < usuariosLogados.size(); i++){
  //   cout << (*usuariosLogados.find(i)).first << " - " << (*usuariosLogados.find(i)).second.first << endl;
  // }

  // cout << "USUARIOS NO SERVIDOR ANTES DE DELETAR: " << usuariosLogados.size() << endl;

  // remove server
  for(auto it = servidores.begin(); it != servidores.end();){
    if((*it).getNome() == nome)
      it = this->servidores.erase(it);
    else
      it++;
  }

  return "Servidor '" + nome + "' removido com sucesso";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
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
