#include "Partida.hpp"
#include "Jogador.hpp"



Partida::Partida(int num_jogadores)  {

    this->_num_jogadores = num_jogadores;

    this->_jogadores = new Jogador[this->_num_jogadores];
}


Partida::~Partida()  {

    this->_num_jogadores = 0;

    delete[](this->_jogadores);
}



void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe)  {

}
	

int Partida::getNumJogadores()  {

}
	
    
int Partida::getNumAtualJogadores()  {

}
	

void Partida::setJogadores(Jogador* jogadores)  {

}
	

Jogador* Partida::getJogadores()  {

}


Jogador Partida::getCampeao()  {

}
	

Jogador* Partida::getJogadoresOrdenados()  {

}
	

void Partida::imprimeJogadoresOrdenados()  {

}



