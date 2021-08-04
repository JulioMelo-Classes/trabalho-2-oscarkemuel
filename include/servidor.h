#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "canaltexto.h"

using namespace std;
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
