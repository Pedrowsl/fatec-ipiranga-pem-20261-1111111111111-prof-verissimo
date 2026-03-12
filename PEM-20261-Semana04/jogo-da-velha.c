/*
Jogo da Velha
Disciplina: Programação Estruturada e Modular
Curso: Análise e Desenvolvimento de Sistemas
Professor: Carlos Veríssimo

Aluno: Pedro Wesley Pinto de Magalhães
*/

#include <stdio.h>

void mostrar(char velha[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %c ", velha[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        if(i<2){
        printf("---+---+---\n");
        }
    }
}

int main(){

    char velha[3][3];
    char jogador_atual='X', vazio=' ';
    int i, j, linha, coluna, espaco, vencedor=0;
    
    // Inicializa o tabuleiro 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            velha[i][j]=vazio;
        }
    }

    while(vencedor==0){
        // Mostra tabuleiro
        mostrar(velha);

        // Começo de jogo
        printf("* Jogador %c escolha a linha(0-2): ", jogador_atual);
        scanf("%d", &linha);
        printf("* Jogador %c escolha a coluna(0-2): ", jogador_atual);
        scanf("%d", &coluna);

        if(velha[linha][coluna]!=vazio){
            printf("* Posicao ocupada!\n");
            continue;
        }
        velha[linha][coluna]=jogador_atual;

        // Verificar linhas
        for(i=0; i<3; i++){
            if(velha[i][0]==jogador_atual && velha[i][1]==jogador_atual && velha[i][2]==jogador_atual){
                vencedor=1;
            }
        }
        // Verificar colunas
        for(i=0; i<3; i++){
            if(velha[0][i]==jogador_atual && velha[1][i]==jogador_atual && velha[2][i]==jogador_atual){
                vencedor=1;
            }
        }
        // Verificar diagonal principal
            if(velha[0][0]==jogador_atual && velha[1][1]==jogador_atual && velha[2][2]==jogador_atual){
                vencedor=1;
            }
        // verificar diagonal secundaria
            if(velha[0][2]==jogador_atual && velha[1][1]==jogador_atual && velha[2][0]==jogador_atual){
                vencedor=1;
            }

        // Verifica se acabou com vencedor
        if(vencedor==1){
            mostrar(velha);
            printf("* Jogador %c e o vencedor!", jogador_atual);
            break;
        }

        // Verifica se acabou com empate
        espaco=0;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(velha[i][j]==vazio){
                    espaco=1;
                }
            }
        }
        if(espaco==0){
            mostrar(velha);
            printf("* O jogo terminou em empate!");
        break;
        }

        // Troca de jogadores
        if(jogador_atual == 'X'){
            jogador_atual = 'O';
        }
        else {
            jogador_atual = 'X';
        }
    }

    return 0;
}