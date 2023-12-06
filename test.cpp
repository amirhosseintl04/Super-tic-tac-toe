#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define Enter 13

void drawBoard(std::string matrix[][3])
{
    std::cout << "+-----------+" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        // std::cout << i + 1 << " ";
        std::cout << "|";
        for (int j = 0; j < 3; j++)
        {
            std::cout << " " << matrix[i][j] << " ";
            if (j < 2)
                std::cout << "|";
        }
        std::cout << "|";
        std::cout << std::endl;
        if (i < 2)
            std::cout << "+-----------+" << std::endl;
    }
    std::cout << "+-----------+" << std::endl;
    std::cout << std::endl;
}

int main()
{
    int i = 0, j = 0;
    std::string mat00[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat00[i][j] = ".";
        }
    }

    for (int k = 0; k < 9; k++)
    {
        i = j = 0;
        bool enter = true;
        system("cls");
        std::cout << i << " " << j << std::endl;

        if (k % 2 == 0){
            mat00[i][j] = "o";
        }
        else{
            mat00[i][j] = "x";
        }

        drawBoard(mat00);

        do
        {
            switch ((getch()))
            {
            case KEY_UP:
                system("cls");
                mat00[i][j] = ".";
                if ( i > 0)i--;
                
                std::cout << i << " " << j << "\n";

                if (k % 2 == 0)
                {
                    mat00[i][j] = "o";
                }
                else
                {
                    mat00[i][j] = "x";
                }
                drawBoard(mat00);
                break;
            case KEY_DOWN:
                system("cls");
                mat00[i][j] = ".";
                if ( i < 2)i++;
            
                std::cout << i << " " << j << "\n";
                if (k % 2 == 0)
                {
                    mat00[i][j] = "o";
                }
                else
            {
                    mat00[i][j] = "x";
                }
                drawBoard(mat00);
                break;
            case KEY_LEFT:
                system("cls");
                mat00[i][j] = ".";
                if ( j > 0)j--;
                
                std::cout << i << " " << j << "\n";
                if (k % 2 == 0)
                {
                    mat00[i][j] = "o";
                }
                else
                {
                    mat00[i][j] = "x";
                }
                drawBoard(mat00);
                break;
            case KEY_RIGHT:
                system("cls");
                mat00[i][j] = ".";
                if ( j < 2) j++ ;
                std::cout << i << " " << j << "\n";
                if (k % 2 == 0)
                {
                    mat00[i][j] = "o";
                }
                else
                {
                    mat00[i][j] = "x";
                }
                drawBoard(mat00);
                break;
            case Enter :
                enter = false ;    
            default:
                cout << endl
                     << "goh nakhor" << endl; 
                break;
            }

        } while (enter);
    }
    return 0;
}
