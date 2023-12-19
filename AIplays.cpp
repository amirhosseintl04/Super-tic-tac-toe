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

void turn(char (&ogMat)[3][3] ,char mat[3][3], int& k){

    std::srand(static_cast<unsigned int>(std::time(0)));
    int randX,randY;
    do{
        randX = 0 + std::rand() % 3;
        randY = 0 + std::rand() % 3;
    }while(mat[randX][randY] != '.');
        system("cls");
        if (k % 2 == 0){
            mat[randX][randY] = 'o';
        }else{
            mat[randX][randY] = 'x';
        }
        std::cout << "Play board" << std::endl ;
        drawBoard(mat,MAGENTA);
        std::cout << "\nOriginal" << std::endl ;
        drawBoard(ogMat,GREEN);
        sleep(1);
    }

void game( char (&ogMat)[3][3],char mat[3][3] , bool move , int& i ,int& j ,int x,int y){

    while(true){
        initialize(mat);
        for (int k = 0; k < 9; k++)
        {
            system("cls");
            std::cout << "Play board" << std::endl ;
            drawBoard(mat,MAGENTA);
            std::cout << "\nOriginal" << std::endl ;
            drawBoard(ogMat,GREEN);

            turn(ogMat, mat, k);

            if (Win(mat) == 1){
                ogMat[x][y]='x';
                return;
            }else if (Win(mat) == 2){
                ogMat[x][y]='o';
                return;
            }
        }
    }
}
int main()
{
    char ogMat[3][3];
    char gameMat[3][3];
    int i,j,x,y;
    int vicivici;
    bool move = false;
    std::srand(static_cast<unsigned int>(std::time(0)));
    system("cls");
    initialize(ogMat);
    std::cout<<"Orginal\n";
    drawBoard(ogMat,GREEN);

    for(int e=0; e<9;e++){
        int x,y;
        std::cout<<"Orginal\n"; 
        do{
        x = 0 + std::rand() % 3;
        y = 0 + std::rand() % 3;
        }while(ogMat[x][y] != '.');
        game(ogMat ,gameMat , move , i , j , x , y);
        system("cls");
        drawBoard(ogMat,GREEN);
        if (Win(ogMat) == 1){
            std::cout <<RED<< "X won\n";return 0;
        }else if (Win(ogMat) == 2){
            std::cout <<LBLUE<< "O won\n";return 0;
        }
        sleep(1);      
    }
    std::cout << "DRAW";
    
    system("pause") ;
    return 0;
}