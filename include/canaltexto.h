#ifndef CANALTEXTO_H
#define CANALTEXTO_H

class Mensagem{
  public:
    string dataHora; //<! Uma string com texto representando um timestamp com a data e hora em que a mensagem foi enviada no formato <DD/MM/AAAA - HH:MM>, exemplo: <08/03/2021 - 11:53>
    int enviadaPor; //<! Um inteiro com Id do usuário que enviou a mensagem
    string conteudo; //<! Uma string o conteúdo da mensagem
};

class CanalTexto{
	private:
    string nome; //<! Uma string com o nome do canal, conforme o comando create-channel
    vector<Mensagem> mensagens; //<! Um vector com mensagens que foram enviadas neste canal
};

#endif
