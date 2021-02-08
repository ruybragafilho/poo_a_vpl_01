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

    Carta c(numero_pontos_carta, naipe);
    bool achou = false;
    int i;

    for( i=0;  i < this->_atualSize;  ++i )  {

        if( this->_jogadores[i].getNomeJogador() == nomeJogador )  {
            achou = true;
            break;
        }
    }
 
    if( !achou )  {
        ++(this->_atualSize);
        this->_jogadores[i].setNomeJogador( nomeJogador );
    }
            
    this->_jogadores[i].adicionaCarta( c );

}
	

int Partida::getNumJogadores()  {
    return( this->_num_jogadores );
}
	
    
int Partida::getNumAtualJogadores()  {
    return( this->_atualSize );
}
	

void Partida::setJogadores(Jogador* jogadores)  {
    this->_jogadores = jogadores;
}
	

Jogador* Partida::getJogadores()  {
    return( this->_jogadores );
}


Jogador Partida::getCampeao()  {

    int campeao = 0;
    int maiorPontuacao = 0;
    int pontuacaoJogadorAtual;
    
    for( int i=0;  i < this->_atualSize;  ++i )  {

        pontuacaoJogadorAtual = this->_jogadores[i].calcularPontuacao();
        if( pontuacaoJogadorAtual > maiorPontuacao )  {
         
            campeao = i;
            maiorPontuacao = pontuacaoJogadorAtual;
        }   
    }

    return ( this->_jogadores[campeao] );
}
	

//Jogador* Partida::getJogadoresOrdenados()  {

//}
	

void Partida::imprimeJogadoresOrdenados()  {

    for( int i = 0;  i < this->_atualSize;  ++i )  {
        cout << this->_jogadores[i].getNomeJogador() << " " << this->_jogadores[i].calcularPontuacao() << endl;
    }
}



