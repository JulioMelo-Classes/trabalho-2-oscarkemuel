#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Mensagem{
  public:
    string dataHora; //<! Uma string com texto representando um timestamp com a data e hora em que a mensagem foi enviada no formato <DD/MM/AAAA - HH:MM>, exemplo: <08/03/2021 - 11:53>
    int enviadaPor; //<! Um inteiro com Id do usuário que enviou a mensagem
    string conteudo; //<! Uma string o conteúdo da mensagem

    /*! Constructor - Criação de mensagem
        @param dataHora string com data e hora que a mensagem foi enviada
        @param enviadoPor um inteiro com o id de quem enviou a mensagem
        @param conteudo string com conteúdo da mensagem
    */
    Mensagem(string dataHora, int enviadoPor, string conteudo);
};

#endif
