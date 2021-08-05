Trabalho 2
# Trabalho-2
Repositório contendo as especificações do Trabalho 2 da disciplina de LP1

## Clonar, Compilar e Executar

### Clonar
Para clonar o trabalho, rode os seguintes comandos:
```
git clone https://github.com/JulioMelo-Classes/trabalho-2-oscarkemuel.git
cd trabalho-2-oscarkemuel
```

### Compilação
Para compilar o trabalho, rode os seguintes comandos:
```
mkdir build && cd build
cmake ../
make
```

### Execução
Para executar comandos já criados, rode o seguinte comando:
```
./concordo < ../script_comandos.txt
```
ou rode isso para ter acesso ao programa sem scripts:
```
./concordo
```

## Testando erros
### Teste 1 - Testes de Criação de usuário, login e desconnect;
```
./concordo < ../data/test_1.txt
```
### Teste 2 - Criação, remoção, descrição, listagem e convite de servidores;
```
./concordo < ../data/test_2.txt
```
### Teste 3 - Entrar, sair e listagem de participantes do servidor;
```
./concordo < ../data/test_3.txt
```
### Teste 4 - Criar, entrar e sair de canais;
```
./concordo < ../data/test_4.txt
```
### Teste 5 - Envio e listagem de mensagens;
```
./concordo < ../data/test_5.txt
```
