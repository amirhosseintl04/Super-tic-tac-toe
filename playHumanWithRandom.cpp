#include <iostream>
#include <conio.h>
#include <ctime>
#include <unistd.h>

#define RED "\033[31m"
#define LBLUE "\033[94m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define DGRAY "\033[90m"

int Win(char matrix[][3])
{
    for (int i = 0; i < 3; i++){
        if (matrix[i][0] != '.' && matrix[i][1] != '.' && matrix[i][2] != '.'){
            if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]){

                if (matrix[i][0] == 'x'){
                    return 1;
                }else if (matrix[i][0] == 'o'){
                    return 2;
                }
            }
        }
        if (matrix[0][i] != '.' && matrix[1][i] != '.' && matrix[2][i] != '.'){
            if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]){
                
                if (matrix[0][i] == 'x'){
                    return 1;
                }else if (matrix[0][i] == 'o'){
                    return 2;
                }
            }
        }
    }
    if (matrix[0][0] != '.' && matrix[1][1] != '.' && matrix[2][2] != '.'){
        if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
            if (matrix[0][0] == 'x'){
                return 1;
            }
            else if (matrix[0][0] == 'o'){
                return 2;
            }
        }
    }
    if (matrix[2][0] != '.' && matrix[1][1] != '.' && matrix[0][2] != '.'){
        if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2]){

            if (matrix[1][1] == 'x'){
                return 1;
            }else if (matrix[1][1] == 'o'){
                return 2;
            }
        }
    }

    return 0;
}

void drawBoard(char matrix[][3], const char* color){
    std::cout <<color<< "+---+---+---+"<<RESET<< std::endl;
    for (int i = 0; i < 3; i++){
        std::cout <<color<< "|"<<RESET;
        for (int j = 0; j < 3; j++){
            if (matrix[i][j]=='x')
                {std::cout << " " <<RED<< matrix[i][j] <<RESET<< " ";}
            else if (matrix[i][j]=='o')
                {std::cout << " " <<LBLUE<< matrix[i][j] <<RESET<< " ";}
            else
                {std::cout << " " <<DGRAY<< matrix[i][j] <<RESET<< " ";}
            
            if (j < 2) std::cout <<color<< "|"<<RESET;
        }
        std::cout <<color<< "|"<<RESET;
        std::cout << std::endl;
        if (i < 2)
            std::cout <<color<< "+---+---+---+"<<RESET<< std::endl;
    }
    std::cout <<color<< "+---+---+---+"<<RESET<< std::endl;
}

void initialize(char mat[3][3]){
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            mat[i][j] = '.';
        }
    }
}

void turn(char mat[3][3], int& k,int& randX,int& randY){
    if (k % 2 == 0){
        std::srand(static_cast<unsigned int>(std::time(0)));
        do{
            randX = 0 + std::rand() % 3;
            randY = 0 + std::rand() % 3;
        }while(mat[randX][randY] != '.');
        mat[randX][randY] = 'o'; 
    }else{
        int i,j;
        switch (getch()){
            case '1': i = 2; j = 0;  mat[i][j] = 'x'; break;
            case '2': i = 2; j = 1;  mat[i][j] = 'x'; break;
            case '3': i = 2; j = 2;  mat[i][j] = 'x'; break;
            case '4': i = 1; j = 0;  mat[i][j] = 'x'; break;
            case '5': i = 1; j = 1;  mat[i][j] = 'x'; break;
            case '6': i = 1; j = 2;  mat[i][j] = 'x'; break;
            case '7': i = 0; j = 0;  mat[i][j] = 'x'; break;
            case '8': i = 0; j = 1;  mat[i][j] = 'x'; break;
            case '9': i = 0; j = 2;  mat[i][j] = 'x'; break;
        }
    }
    system("cls");
    std::cout << "Play board" << std::endl ;
    drawBoard(mat,MAGENTA);
}

    void game(char gameMat[3][3] , int& randX,int& randY){

    while(true){
        initialize(gameMat);
        for (int k = 0; k < 9; k++)
        {
            system("cls");
            std::cout << "Play board" << std::endl ;
            drawBoard(gameMat,MAGENTA);
            turn(gameMat, k,randX,randY);

            if (Win(gameMat) == 1){
                std::cout<<"X won!\n";
                return;
            }else if (Win(gameMat) == 2){
                std::cout<<"O won!\n";
                return;
            }
        }
    }
}

int main()
{
    int randX,randY;
    char gameMat[3][3];

    std::srand(static_cast<unsigned int>(std::time(0)));
    game( gameMat , randX,randY);
    system("pause") ;
    return 0;
}