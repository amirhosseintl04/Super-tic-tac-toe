#include <iostream>
#include <conio.h>

#define RED "\033[31m"
#define LBLUE "\033[94m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define DGRAY "\033[90m"

#define Enter 13
#define Back 8
#define Space 32

    /**
    * return 1 == x won
    * return 2 == o won
    * retrurn 0 == no one won
    * @param matrix lkgfgdlkgdl 
    * @return if 1 then x win, if 2 o win, otherdftd tie
    */
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

void initialize(char mat[3][3]){
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            mat[i][j] = '.';
        }
    }
}

void turn(char (&ogMat)[3][3],char mat[3][3], int& k, bool& move, int i, int j){

    if (mat[i][j] == '.'){
        system("cls");
        if (k % 2 == 0){
            mat[i][j] = 'o';
        }else{
            mat[i][j] = 'x';
        }
        std::cout << "Play board" << std::endl ;
        drawBoard(mat,MAGENTA);
        std::cout << "\nOriginal" << std::endl ;
        drawBoard(ogMat,GREEN);
        move = true;
    }
}
void Switch(char (&ogMat)[3][3],int& k, bool& move, char mat[3][3], bool& enter,int& i,int j){
    
    do{
        int keyPressed = getch();
        if (keyPressed >= '1' && keyPressed <= '9') {
            if (move) {
                system("cls");
                std::cout << "Play board" << std::endl ;
                std::cout << "You can't move to a different position after making a move." << std::endl;
                drawBoard(mat,MAGENTA);
                std::cout << "\nOriginal" << std::endl;
                drawBoard(ogMat,GREEN);
                continue;
            }
        }
        switch (keyPressed){
            case '1': i = 2; j = 0; turn(ogMat,mat, k, move, i, j); break;
            case '2': i = 2; j = 1; turn(ogMat,mat, k, move, i, j); break;
            case '3': i = 2; j = 2; turn(ogMat,mat, k, move, i, j); break;
            case '4': i = 1; j = 0; turn(ogMat,mat, k, move, i, j); break;
            case '5': i = 1; j = 1; turn(ogMat,mat, k, move, i, j); break;
            case '6': i = 1; j = 2; turn(ogMat,mat, k, move, i, j); break;
            case '7': i = 0; j = 0; turn(ogMat,mat, k, move, i, j); break;
            case '8': i = 0; j = 1; turn(ogMat,mat, k, move, i, j); break;
            case '9': i = 0; j = 2; turn(ogMat,mat, k, move, i, j); break;
            
            case Back:
                system("cls"); mat[i][j] = '.'; 
                std::cout << "Play board" << std::endl ;
                drawBoard(mat,MAGENTA);
                std::cout << "\nOriginal" << std::endl ;
                drawBoard(ogMat,GREEN); move = false;
                break;
    
            case Enter:
                if (move){
                    enter = false;
                }else{
                     std::cout << "enteret nashod ";
                }
                break;
                
            default:
                system("cls");
                std::cout << "kossher vared nakon" << std::endl;
                break;
        }
    } while (enter);
}
void game(char (&ogMat)[3][3],char mat[3][3] , bool move , int& i ,int& j ,int x,int y){
    initialize(mat);
    int victory ;
    for (int k = 0; k < 9; k++)
    {
        system("cls");
        bool enter = true;
        std::cout << "Play board" << std::endl ;
        drawBoard(mat,MAGENTA);
        std::cout << "\nOriginal" << std::endl ;
        drawBoard(ogMat,GREEN);
        
        Switch(ogMat,k, move, mat, enter,i,j);

        victory = Win(mat);
        if (victory == 1){
            //std::cout << "X won";
            ogMat[x][y]='x';
            return;
        }else if (victory == 2){
            ogMat[x][y]='o';
            return;
        }
    }
    ogMat[x][y]='d';
    //std::cout << "DRAW";
}
int main()
{
    char ogMat[3][3];
    char gameMat[3][3];
    int i,j,x,y;
    int vicivici;
    bool move = false;

    system("cls");
    initialize(ogMat);
    std::cout<<"Orginal\n";
    drawBoard(ogMat,GREEN);
    for(int e=0; e<9;e++){
    switch (getch()){

        case '1': x = 2; y = 0;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '2': x = 2; y = 1;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '3': x = 2; y = 2;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '4': x = 1; y = 0;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '5': x = 1; y = 1;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '6': x = 1; y = 2;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '7': x = 0; y = 0;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '8': x = 0; y = 1;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        case '9': x = 0; y = 2;game(ogMat ,gameMat , move , i , j , x , y); system("cls");std::cout<<"Orginal\n"; drawBoard(ogMat,GREEN);if (Win(ogMat) == 1){std::cout <<RED<< "X won\n";return 0;}else if (Win(ogMat) == 2){std::cout <<LBLUE<< "O won\n";return 0;} break;
        
        }
    }
    std::cout << "DRAW";
    
    system("pause") ;
    return 0;
}

/*
        
    // for (int k = 0; k < 9; k++)
    // {
    //     system("cls");
    //     bool enter = true;
    //     drawBoard(mat00);
    //     Switch(k, move, mat00, enter,i,j);

    
    //     victory = Win(mat00);
    //     if (victory == 1){

    //         std::cout << "X won";
    //         return 0;

    //     }else if (victory == 2){

    //         std::cout << "O won";
    //         return 0;
    //     }
    // }
    
*/