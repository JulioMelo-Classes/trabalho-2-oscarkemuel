#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "usuario.h"
#include "servidor.h"
#include "canaltexto.h"


// Sistema deve concentrar todas as operações do Concordo
class Sistema {
  private:
		std::vector<Servidor> servidores; //<! um vetor com todos os servidores
		std::vector<Usuario> usuarios; //<! um vetor com todos os usuários cadastrados
		std::map< int, std::pair<std::string, std::string> > usuariosLogados; //<! um vetor contendo os usuários que logaram no sistema
		

  public:

		/*! Encerra o funcionamento do Concordo, o programa termina ao executar este comando.
				@return uma string com a mensagem "Saindo.."
		*/
		std::string quit();

		/*! Cria um usuário e retorna uma string de erro/sucesso 
				@param email o email do usuário informado no comando create-user
				@param senha a senha passada ao comando create-ser
				@param nome o nome do usuário (com espaços) passado ao comando create user 
				@return uma string contendo uma mensagem de erro ou "Usuário Criado"
		*/
		std::string create_user (const std::string email, const std::string senha, const std::string nome);

		/*! Realiza o login do usuário com email e senha, retorna uma string de erro ou uma mensagem 
				login bem sucedido. Quando um usuário loga o sistema deve adicionar o usuário na tabela 
				Sistema::usuariosLogados.
				@param email o email do usuário, passado no comando login
				@param senha a senha correspondente àquele usuário
				@return uma string contendo uma mensagem de erro ou "Logado como <email>!"
		*/
		std::string login(const std::string email, const std::string senha);

		/*! Desconecta um usuário específico do sistema, removendo a informação daquele usuário da 
				tabela Sistema::usuariosLogados. A função retorna uma mensagem de sucesso ou de erro 
				caso o usuário não esteja logado.
				@param id um id válido de um usuário logado no sistema.
				@return "Usuário <email> desconectado!" ou uma mensagem de erro em caso de falha.
		*/
		std::string disconnect(int id);

		/*! Cria um novo servidor no sistema e o adiciona na lista de servidores. A função deve retornar
				uma string "Servidor <nome> criado" ou uma mensagem de erro caso o servidor não possa ser 
				criado por algum motivo.
				@param id um id válido de um usuário logado no sistema.
				@param nome o nome do servidor de acordo com o comando create-server.
				@return "Servidor <nome> criado" quando o servidor for criado ou uma mensagem de erro em
								caso de falha.
		*/
		std::string create_server(int id, const std::string nome);
		
		/*! Modifica a descrição do servidor passado no comando, para a descrição desejada. A função
				deve retornar "Descrição do servidor <nome> modificada!" ou uma mensagem de erro em caso
				de falha.
				@param id um id válido de um usuário logado no sistema.
				@param nome o nome do servidor que se deseja mudar.
				@param descricao nova descrição desejada.
				@return "Descrição do servidor <nome> modificada!" ou uma mensagem de erro em caso de falha.
		*/
		std::string set_server_desc(int id, const std::string nome, const std::string descricao);

		/*! Modifica o código de convite do servidor no sistema. Retorna uma mensagem de sucesso ou
				de erro em caso de falha.
				@param id um id válido de um usuário logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@param codigo um código de acordo com o comando set-server-invite-code.
				@return "Código de convite modificado com sucesso" ou uma mensagem de erro em caso de
								falha.
		*/ 
		std::string set_server_invite_code(int id, const std::string nome, const std::string codigo);

		/*! Lista os servidores cadastrados no sistema, retorna uma string contendo uma mensagem de
				erro ou uma string vazia no caso de não haver erros.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia ou a string de erro "Usuário não está logado".
		*/
		std::string list_servers(int id);
	
		/*! Remove um servidor da lista de servidores, retornando uma mensagem de sucesso ou de erro
				em caso de falha.
				@param id  um id válido de algum usuário cadastrado e logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@return "Servidor <nome> removido com sucesso" ou uma mensagem de erro em caso de falha.
		*/
		std::string remove_server(int id, const std::string nome);

		/*! Faz com que o usuário logado com o id dado entre no servidor de nome com a senha fornecida
				(se necessário). Retorna uma mensagem de erro em caso de falha ou uma mensagem de sucesso
				caso contrário. Esse método atualiza a tabela Sistema::usuariosLogados com a informação do
				servidor que o usuário com o id está conectado.
				@param id  um id válido de algum usuário cadastrado e logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@param codigo um código de convite para o servidor se necessário ou uma string vazia, caso
							 o comando tenha vindo sem código. Veja o comando enter-server para mais detalhes.
				@return "Entrou no servidor <nome>" em caso de sucesso ou uma mensagem de erro caso contrário.
		*/
		std::string enter_server(int id, const std::string nome, const std::string codigo);

		/*! Faz com oque o usuário conectado em algum servidor saia do mesmo. Deve retornar uma string
				com uma mensagem de sucesso ou uma mensagem de erro caso contrário. No caso que o servidor
				passado como agumento para este método é o mesmo que o servidor em que o usuário está 
				visualizando atualmente (usando o valor guardado em Sistema::usuariosLogados) este método
				deve atualizar a tabela Sistema::usuariosLogados, sinalizando que o usuário não está mais
				visualizando aquele servidor.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@param nome um nome válido de um servidor cadastrado no sistema.
				@return "Saiu do servidor <nome>" ou uma mensagem de erro em caso de falha.
		*/
		std::string leave_server(int id, const std::string nome);

		/*! Lista os participantes presentes no servidor que o usuário com o id passado está visualizando.
				Retorna uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return Uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
		std::string list_participants(int id);

		/*!	Lista os canais do servidor que o usuário com o id passado está vizualizando. Retorna uma
				string vazia em caso de sucesso o uma mensagem de erro no caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
		std::string list_channels(int id);

		/*! Cria um canal em um servidor com o nome passado. O canal criado é do tipo dado (voz ou texto)
				de acordo com o comando create-channel. Retorna uma mensa
				@param id um id válido de algum usuário cadastrado e logado no sistema. 
				@param o nome do novo canal, de acordo com o comando create-channel
				@return "Canal <nome> criado!" ou uma mensagem de erro em caso de falha.
		*/
		std::string create_channel(int id, const std::string nome);
		
		/*! Faz com que o usuário com id dado entre em um canal específico(com seu nome e tipo) ao entrar
				em um canal o sistema deve atualizar a tabela Sistema::usuariosLogados com a informação de
				que o usuário está vizualizando o canal em que entrou. Retorna uma mensagem de sucesso ou de
				erro em caso de falha.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@param o nome do canal que deseja entrar,
				@return "Usuário <email.do.usuario> entrou no canal <nome>" ou uma mensagem de
								erro em caso de falha.
		*/
		std::string enter_channel(int id, const std::string nome);

		/*! Faz com que o usuário com id dado saia do canal que está visualizando atualmente. 
				Ao sair de um canal o sistema deve atualizar o attributo Sistema::usuariosLogados de 
				forma que o usuário não esteja mais vizualizando qualquer canal. A função deve retornar 
				mensagem de sucesso ou de erro em caso de falha
				@param id um id válido de algum usuário cadastrado e logado no sistema.
							 que o usuário está visualizando, de acordo com o atributo Sistema::usuariosLogados.
				@return "Usuário <email.do.usuario> saiu no canal <nome>" ou uma mensagem de erro em caso de
								falha.
		*/
		std::string leave_channel(int id);
		
		/*! Envia uma mensagem no canal em que o usuáiro com id passado está visualizando.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@param mensagem a mensagem que deve ser enviada.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
		std::string send_message(int id, const std::string mensagem);
		
		/*! Lista as mensagem no canal que o usuário com id passado está visualizando.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
		std::string list_messages(int id);
};

#endif
