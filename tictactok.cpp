#include <iostream>
#include <conio.h>

#define RED "\033[31m"
#define LBLUE "\033[94m"
#define RESET "\033[0m"

// #define KEY_UP 72
// #define KEY_DOWN 80
// #define KEY_LEFT 75
// #define KEY_RIGHT 77
#define Enter 13
#define Back 8
#define Space 32


// struct Student {
//     int age;
//     std::string name;

//     void tellName() {
//         std::cout << name;
//     }
// };

    /**
    * return 1 == x won
    * return 2 == o won
    * retrurn 0 == no one won
    * @param matrix lkgfgdlkgdl 
    * @return if 1 then x win, if 2 o win, otherdftd tie
    */
int Win(std::string matrix[][3])
{
    // Student haas(20, "MOhsen");
    // haas.tellName();

    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] != "." && matrix[i][1] != "." && matrix[i][2] != ".")
        {
            if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            {

                if (matrix[i][0] == "x")
                {
                    return 1;
                }
                else if (matrix[i][0] == "o")
                {
                    return 2;
                }
            }
        }
        if (matrix[0][i] != "." && matrix[1][i] != "." && matrix[2][i] != ".")
        {
            if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            {
                if (matrix[0][i] == "x")
                {
                    return 1;
                }
                else if (matrix[0][i] == "o")
                {
                    return 2;
                }
            }
        }
    }
    if (matrix[0][0] != "." && matrix[1][1] != "." && matrix[2][2] != ".")
    {
        if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        {
            if (matrix[0][0] == "x")
            {
                return 1;
            }
            else if (matrix[0][0] == "o")
            {
                return 2;
            }
        }
    }
    if (matrix[2][0] != "." && matrix[1][1] != "." && matrix[0][2] != ".")
    {
        if (matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2])
        {
            if (matrix[1][1] == "x")
            {
                return 1;
            }
            else if (matrix[1][1] == "o")
            {
                return 2;
            }
        }
    }

    return 0;
}

void drawBoard(std::string matrix[][3])
{
    std::cout << "+---+---+---+" << std::endl;

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
            std::cout << "+---+---+---+" << std::endl;
    }
    std::cout << "+---+---+---+" << std::endl;
    std::cout << std::endl;
}

void initialize(std::string mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = ".";
        }
    }
}

void turn(std::string mat[3][3], int k, bool move, int i, int j)
{
    if (mat[i][j] == ".")
    {
        system("cls");
        if (k % 2 == 0)
        {
            mat[i][j] = "o";
        }
        else
        {
            mat[i][j] = "x";
        }
        drawBoard(mat);
        move = true;
    }
}
void Switch(int k, bool move, std::string mat[3][3], bool enter,int i,int j)
{
    //bool moved=move;
    do
    {
        switch (getch())
        {
        case '1':
            i = 2; j = 0;
            turn(mat, k, move, i, j);
            break;

        case '2':
            i = 2; j = 1;
            turn(mat, k, move, i, j);
            break;

        case '3':
            i = 2; j = 2;
            turn(mat, k, move, i, j);
            break;

        case '4':
            i = 1; j = 0;
            turn(mat, k, move, i, j);
            break;

        case '5':
            i = 1; j = 1;
            turn(mat, k, move, i, j);
            break;
        case '6':
            i = 1; j = 2;
            turn(mat, k, move, i, j);
            break;

        case '7':
            i = 0; j = 0;
            turn(mat, k, move, i, j);
            break;

        case '8':
            i = 0; j = 1;
            turn(mat, k, move, i, j);
            break;
        case '9':
            i = 0; j = 2;
            turn(mat, k, move, i, j);
            break;

        case Space:
            system("cls");
            mat[i][j] = ".";
            drawBoard(mat);
            move = false;
            break;

        case Enter:
            if (move)
             {
                enter = false;
            }
             else
             {
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

int main()
{
    int i,j;
    system("cls");
    bool move = false;
    int victory;
    std::string mat00[3][3];
    initialize(mat00);
    for (int k = 0; k < 9; k++)
    {

        system("cls");
        bool enter = true;
        drawBoard(mat00);
        Switch(k, move, mat00, enter,i,j);
        victory = Win(mat00);

        if (victory == 1)
        {
            std::cout << "X won";
            return 0;
        }
        else if (victory == 2)
        {
            std::cout << "O won";
            return 0;
        }
    }
    std::cout << "DRAW";
    return 0;
}

/*
bugs:
if press any null key turn will expire;
and big dick bug in changing elements;
*/