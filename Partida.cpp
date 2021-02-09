#include "Partida.hpp"
#include "Jogador.hpp"



Partida::Partida(int num_jogadores)  {

    this->_num_jogadores = num_jogadores;
    this->_jogadores = new Jogador[this->_num_jogadores];
    this->indiceJogadores = new int[this->_num_jogadores];
}


Partida::~Partida()  {

    this->_num_jogadores = 0;
    delete[](this->_jogadores);
    delete[](this->indiceJogadores);
}



void Partida::addJogadorCarta(string nomeJogador, int numero_pontos_carta, string naipe)  {

    Carta c(numero_pontos_carta, naipe);
 
    // Se ainda nao ha jogadores na partida, seta o primeiro e da a primeira carta para ele
    if (this->_atualSize == 0) {
        
        this->_jogadores[ this->_atualSize ].setNomeJogador( nomeJogador );  
        this->_jogadores[ this->_atualSize ].adicionaCarta( c );
        ++(this->_atualSize);
        return; 
    }


    // Verifica se a proxima carta não é para o jogador atual. Se não for, seta o próximo jogador
    if( this->_jogadores[ this->_atualSize - 1 ].getNomeJogador() != nomeJogador )  {
        
        this->_jogadores[ this->_atualSize ].setNomeJogador( nomeJogador );        
        ++(this->_atualSize);
    }

    // Da a carta ao jogador        
    this->_jogadores[ this->_atualSize - 1 ].adicionaCarta( c ); 
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
	


Jogador* Partida::getJogadoresOrdenados()  {

    Jogador* jogadores = new Jogador[this->_num_jogadores];

    quicksort();

    for( int i = 0;  i < this->_atualSize;  ++i ) { 

        jogadores[i] = this->_jogadores[ this->indiceJogadores[i] ];
    }

    return jogadores;
}
	


void Partida::imprimeJogadoresOrdenados()  {

    quicksort();

    for( int i = 0;  i < this->_atualSize;  ++i )  {
        cout << this->_jogadores[ this->indiceJogadores[i] ].getNomeJogador() << " " 
             << this->_jogadores[ this->indiceJogadores[i] ].calcularPontuacao() << endl;        
    }
}






// Definicao de funcoes auxiliares para ordenacao do array de jogadores
// O algoritmo quicksort é utilizado para ordenar o array de indices dos
// jogadores, em funcao da pontuação total dos jogadores

// Ordenacao por quicksort
void Partida::quicksort() {

    int* pontuacao = new int[ this->_atualSize ];

    for( int i = 0;  i < this->_atualSize;  ++i )  {

        this->indiceJogadores[i] = i;
        pontuacao[i] = (this->_jogadores[i]).calcularPontuacao();       
    }

    this->ordena( this->indiceJogadores, pontuacao, 0, this->_atualSize-1 );

    delete[](pontuacao);
}



// Prototipo do procedimento ordena, do metodo quicksort                 
void Partida::ordena( int* indiceJogadores, 
                      int* pontuacao,
                      int esquerda,
                      int direita )  {

    int i;
    int j;
				 
    particao( indiceJogadores, pontuacao, esquerda, direita, &i, &j );
    if( esquerda < j )  ordena( indiceJogadores, pontuacao, esquerda, j );
    if( i < direita )   ordena( indiceJogadores, pontuacao, i, direita  );
}



// Prototipo do procedimento particao, do metodo quicksort            
void Partida::particao( int* indiceJogadores, 
                        int* pontuacao,
                        int esquerda,
                        int direita,
                        int* i,
                        int* j )  {

    int pivo;
    int aux;
    
    *i = esquerda;
    *j = direita;
    pivo = pontuacao[ ((*i)+(*j))/2 ];				   
				   
	do {
		
		while(pontuacao[*i] < pivo)  ++(*i);
		while(pontuacao[*j] > pivo)  --(*j);
		
		if( *i <= *j )   {
			
			aux = pontuacao[*i];
			pontuacao[*i] = pontuacao[*j];
			pontuacao[*j] = aux;
			
			aux = indiceJogadores[*i];
			indiceJogadores[*i] = indiceJogadores[*j];
			indiceJogadores[*j] = aux;
	
			++(*i);
			--(*j);
		}
		
	} while( *i <= *j );

}



