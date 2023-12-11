#include <iostream>
#include <conio.h>

#define RED "\033[31m"
#define LBLUE "\033[94m"
#define RESET "\033[0m"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define Enter 13

int Win(std::string matrix[][3])
{
    /*
    return 1 == x won
    return 2 == o won
    retrurn 0 == no one won
    */
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

// void moving(std::string matBackup[][3])
// {
// }

int main()
{

    system("cls");
    std::string temp = ".";
    int victory;
    std::string mat00[3][3]; // this is the matrix for the player
    // moving(mat00);
    // initialize the starter matrix to 0 for checking
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat00[i][j] = ".";
        }
    }

    // A loop to run through our matrix
    for (int k = 0; k < 9; k++)
    {
        system("cls");
        bool enter = true;
        // std::cout << 0 << " " << 0 << std::endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                if (mat00[i][j] == ".")
                {
                    drawBoard(mat00);
                    do
                    {
                        switch (getch())
                        {
                        case KEY_UP:

                            if (i > 0 && mat00[i - 1][j] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i - 1][j];
                                i--;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            else if (i > 0 && mat00[i - 2][j] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i - 2][j];
                                i -= 2;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            break;

                        case KEY_DOWN:
                            if (i < 2 && mat00[i + 1][j] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i + 1][j];
                                i++;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            else if (i < 2 && mat00[i + 2][j] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i + 2][j];
                                i += 2;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            break;

                        case KEY_LEFT:
                            if (j > 0 && mat00[i][j - 1] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i][j - 1];
                                j--;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            else if (j > 0 && mat00[i][j - 2] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i][j - 2];
                                j -= 2;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            break;

                        case KEY_RIGHT:
                            if (j < 2 && mat00[i][j + 1] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i][j + 1];
                                j++;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            else if (j < 2 && mat00[i][j + 2] == ".")
                            {
                                mat00[i][j] = temp;
                                temp = mat00[i][j + 2];
                                j += 2;
                                system("cls");
                                if (k % 2 == 0 && mat00[i][j] != "x")
                                    mat00[i][j] = "o";
                                else if (k % 2 == 1 && mat00[i][j] != "o")
                                    mat00[i][j] = "x";
                                drawBoard(mat00);
                            }
                            break;
                        case Enter:
                            enter = false;
                            break;
                        default:
                            system("cls");
                            std::cout << "goh nakhor" << std::endl;
                            break;
                        }

                    } while (enter);
                    break;
                }
                if (enter == false)
                {
                    break;
                }
            }
            if (enter == false)
            {
                break;
            }
        }

        system("cls");

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