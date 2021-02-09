#ifndef PARTIDA
#define PARTIDA

#include <string>
#include <iostream>
#include "Jogador.hpp"

using namespace std;

class Partida {
	
private:
	Jogador *_jogadores;
	int _num_jogadores = 0;
	int _atualSize = 0;

    // Atributo utilizado para armazenar os indices do jogadores no array
	// É utilizado para fazer uma oredenação indireta dos jogadores, em função
	// da pontuação dos jogadores
    int *indiceJogadores;


    // Ordenacao por quicksort - O algoritmo quicksort é utilizado para
	// ordenar o array de indice dos jogadores, em funcao da pontuação
    void  quicksort();


    // Prototipo do procedimento ordena, do metodo quicksort                 
    void ordena( int* indiceJogadores, 
                 int* pontuacao,
                 int esquerda,
                 int direita );


    // Prototipo do procedimento particao, do metodo quicksort            
    void particao(  int* indiceJogadores, 
                    int* pontuacao,
                    int esquerda,
                    int direita,
                    int* i,
                    int* j  );


public:

	Partida(int num_jogadores);
	~Partida();
	void addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe);
	
	int getNumJogadores();
	int getNumAtualJogadores();
	void setJogadores(Jogador* jogadores);
	Jogador* getJogadores();
	Jogador getCampeao();
	Jogador* getJogadoresOrdenados();
	void imprimeJogadoresOrdenados();
};

#endif