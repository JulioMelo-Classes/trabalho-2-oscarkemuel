#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include "mensagem.h"
#include "usuario.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

/*
CP2 ok
*/
class CanalTexto{
	private:
    string nome; //<! Uma string com o nome do canal, conforme o comando create-channel
    vector<Mensagem> mensagens; //<! Um vector com mensagens que foram enviadas neste canal

  public:
    /*! Constructor - Criação de Canal de texto.
        @param dataHora string com o nome do canal de texto
    */
    CanalTexto(string nome);

    /*! Retorna o nome do canal de texto.
				@return uma string com o nome do canal de texto."
		*/
    string getName();

    /*! Converte a time_t para string e adiciona a mensagem no vetor de mensagens.
        @param date time_t a hora e data atual
        @param id int com id de usuário criador da mensagem
        @param message string o conteúdo da mensagem
		*/
    void addMessage(time_t date, int id, string message);

    /*! Printa todas as mensagens no formato Nome<dia/mes/ano - hora:minuto:segundo>: mensagem.
        @param usuarios vetor de usuários do servidor
		*/
    void listMessages(vector<Usuario> usuarios);
};

#endif
