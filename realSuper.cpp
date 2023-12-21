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
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

struct mat
{
    char matrix[3][3]={{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
};

void drawArzBoard(char matrix1[][3],char matrix2[][3],char matrix3[][3]){
    const char* color=RED;
    for (int i = 0; i < 3; i++){
        // std::cout << i + 1 << " ";
        std::cout <<RED<< "|"<<RESET;
        for (int j = 0; j < 3; j++){
            std::cout << " " <<WHITE<< matrix1[i][j] <<RESET<< " ";
            if (j < 2) std::cout <<RED<< "|"<<RESET;
        }
        std::cout <<RED<< "|"<<RESET;
        for (int j = 0; j < 3; j++){
            std::cout << " " <<WHITE<< matrix2[i][j] <<RESET<< " ";
            if (j < 2) std::cout <<BLUE<< "|"<<RESET;
        }
        std::cout <<LBLUE<< "|"<<RESET;
        for (int j = 0; j < 3; j++){
            std::cout << " " <<WHITE<< matrix3[i][j] <<RESET<< " ";
            if (j < 2) std::cout <<GREEN<< "|"<<RESET;
        }
        
        std::cout <<GREEN<< "|"<<RESET;
        std::cout << std::endl;
        if (i < 2)
            std::cout<<MAGENTA<< "+---+---+---+"<<RESET<<YELLOW<<"---+---+---"<<RESET<<CYAN<<"+---+---+---+"<<RESET<< std::endl;
    }
}

void drawBoard(mat boards[]){
    const char* color=RED;
    std::cout<<MAGENTA<< "+---+---+---+"<<RESET<<YELLOW<<"---+---+---"<<RESET<<CYAN<<"+---+---+---+"<<RESET<< std::endl;
    drawArzBoard(boards[0].matrix,boards[1].matrix,boards[2].matrix);
    std::cout<<MAGENTA<< "+---+---+---+"<<RESET<<YELLOW<<"---+---+---"<<RESET<<CYAN<<"+---+---+---+"<<RESET<< std::endl;
    drawArzBoard(boards[3].matrix,boards[4].matrix,boards[5].matrix);
    std::cout<<MAGENTA<< "+---+---+---+"<<RESET<<YELLOW<<"---+---+---"<<RESET<<CYAN<<"+---+---+---+"<<RESET<< std::endl;
    drawArzBoard(boards[6].matrix,boards[7].matrix,boards[8].matrix);
    std::cout<<MAGENTA<< "+---+---+---+"<<RESET<<YELLOW<<"---+---+---"<<RESET<<CYAN<<"+---+---+---+"<<RESET<< std::endl;
}

void WdrawBoard(char matrix[][3]){
    const char* color=RED;
    std::cout <<color<< "+---+---+---+"<<RESET<< std::endl;
    for (int i = 0; i < 3; i++){
        // std::cout << i + 1 << " ";
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

void turn(mat boards[],char mat[3][3], int& i, int& j,int& k){
    std::srand(static_cast<unsigned int>(std::time(0)));
    if (k % 2 == 0){
        do{
            i = 0 + std::rand() % 3;
            j = 0 + std::rand() % 3;
        }while(mat[i][j] != '.');
        mat[i][j] = 'o';
    }else{
        do{
            i = 0 + std::rand() % 3;
            j = 0 + std::rand() % 3;
        }while(mat[i][j] != '.');
        mat[i][j] = 'x';
    }
    system("cls");
    drawBoard(boards);
    WdrawBoard(boards[9].matrix);
    //sleep(1);
}

void game( mat boards[9] ,int& boardNUm, int& i ,int& j,int& k ){
    
    turn( boards,boards[boardNUm].matrix,i,j,k);
    int r,t;
    if (boardNUm==0){r=0; t=0;}
    if (boardNUm==1){r=0; t=1;}
    if (boardNUm==2){r=0; t=2;}
    if (boardNUm==3){r=1; t=0;}
    if (boardNUm==4){r=1; t=1;}
    if (boardNUm==5){r=1; t=2;}
    if (boardNUm==6){r=2; t=0;}
    if (boardNUm==7){r=2; t=1;}
    if (boardNUm==8){r=2; t=2;}
    if (Win(boards[boardNUm].matrix) == 1){
        for (int p = 0; p < 3; p++){
            for (int u = 0; u < 3; u++){
                boards[boardNUm].matrix[p][u] = 'x';
            }
        }
        boards[9].matrix[r][t] = 'x';
    }else if (Win(boards[boardNUm].matrix) == 2){
        for (int p = 0; p < 3; p++){
            for (int u = 0; u < 3; u++){
                boards[boardNUm].matrix[p][u] = 'o';
            }
        }
        boards[9].matrix[r][t] ='o';
    }    
    return;    
}
int main()
{
    mat boards[10];
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    //std::cout<<"Orginal\n";
    system("cls");
    drawBoard(boards);
    WdrawBoard(boards[9].matrix);
    int boardNUm,i=0,j=0;
    for(int k = 0 ; k < 81 ;k++){
        
            if(boards[9].matrix[i][j]!='.'){
                std::srand(static_cast<unsigned int>(std::time(0)));
                while(boards[9].matrix[i][j] != '.'){
                    i = 0 + std::rand() % 3;
                    j = 0 + std::rand() % 3;
                }
            }
            if (i==0 && j==0){boardNUm=0;}
            if (i==0 && j==1){boardNUm=1;}
            if (i==0 && j==2){boardNUm=2;}
            if (i==1 && j==0){boardNUm=3;}
            if (i==1 && j==1){boardNUm=4;}
            if (i==1 && j==2){boardNUm=5;}
            if (i==2 && j==0){boardNUm=6;}
            if (i==2 && j==1){boardNUm=7;}
            if (i==2 && j==2){boardNUm=8;}
            game(boards,boardNUm,i,j,k);

            

        if (Win(boards[9].matrix) == 1){
            system("cls");
            drawBoard(boards);
            WdrawBoard(boards[9].matrix);
            std::cout <<RED<< "X won\n";return 0;
        }else if (Win(boards[9].matrix) == 2){
            system("cls");
            drawBoard(boards);
            WdrawBoard(boards[9].matrix);
            std::cout <<LBLUE<< "O won\n";return 0;
        }
    }
    std::cout << "DRAW";
    
    system("pause") ;
    return 0;
}