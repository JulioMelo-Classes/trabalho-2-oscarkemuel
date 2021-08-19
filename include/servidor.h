#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "canaltexto.h"
#include "usuario.h"

using namespace std;
/*
CP2 ok
*/
class Servidor{
	private:
    int usuarioDonoId; //<! ID do criador do servidor
    string nome; //<! Nome do servidor
    string descricao; //<! Descrição do servidor
    string codigoConvite; //<! Código de convite do servidor
    vector<int> participantesIDs; //<! Vetor de IDs dos Participantes do servidor
    vector<CanalTexto> canalTexto; //<! Vetor de canais de texto do servidor

  public:
    /*! Constructor - Criação de servidor
        @param usuarioDonoId um inteiro com o id de quem está criando
        @param nome nome do servidor
    */
    Servidor(int usuarioDonoId, string nome);

    /*! Adiciona um participante no vetor de participantesIDs.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
		*/
    void addParticipant(int id);

    /*! Remove um participante no vetor de participantesIDs.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
		*/
    void removeParticipant(int id);

    /*! Printa os participantes que estão conectados ao servidor.
				@param usuarios o vetor de usuários do sistema.
		*/
    void listParticipants(std::vector<Usuario> usuarios);

    /*! Verifica se o usuário está conectado no servidor.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
		*/
    bool participantIsConected(int id);

    /*! Printa a lista de canais de texto do servidor.*/
    void listChannels();

    /*! Verifica se existe um canal com o nome desejado.
				@param nome string com o nome do canal a ser verificado.
		*/
    bool haveChannel(string nome);

    /*! Adiciona um novo canal no vetor de canais de texto.
				@param canal CanalTexto a ser adicionado no vetor.
		*/
    void addChannel(CanalTexto canal);

    /*! Seleciona o canal pelo nome e chama o método de adicionar mensagem.
				@param channelName string com o nome do canal que a mensagem deve ser adicionada.
				@param id int com o ID do usuário que está enviando a mensagem.
				@param menssage string com o conteúdo da mensagem.
		*/
    void addMessageByNameChannel(string channelName, int id, string menssage);

    /*! Seleciona o canal pelo nome e chama o método de printar mensagens do canal.
				@param channelName string com o nome do canal que deseja listar mensagem.
				@param usuarios vetor de usuário do servidor.
		*/
    void listMessagesByName(string channelName, vector<Usuario> usuarios);

    /*! Seta a descrição do servidor.
				@param descricao uma string com a descrição do servidor.
		*/
    void setDescricao(string descricao);

    /*! Adiciona ou remove o código de convite do servidor.
				@param codigo uma string com um codigo ou vazia.
		*/
    void setCodigoConvite(string codigo);

    /*! Retorna o nome do servidor.
				@return uma string com o nome do servidor."
		*/
    string getNome();

    /*! Retorna a identificação do dono do servidor.
				@return um int com o id do dono do servidor."
		*/
    int getUsuarioDonoId();

    /*! Retorna o código de convite do servidor.
				@return uma string com o código de convite."
		*/
    string getCodigoConvite();
};

#endif
