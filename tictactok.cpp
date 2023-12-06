#include <iostream>
#define RED "\033[31m"
#define LBLUE "\033[94m"
#define RESET "\033[0m"
/*
return 1 == x won ;
return 2 == o won ;
retrurn 0 == no one won  ;
 */
int Win(std::string matrix[][3])
{

    for (int i = 0; i < 3; i++)
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

        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
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

    return 0;
}
void drawBoard(std::string matrix[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
}
int main()
{
    system("cls"); // for convinience
    int victory; //checks for the wo
    std::string mat00[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat00[i][j] = "0";
        }
    }
    int i, j;

    for (int k = 0; k < 9; k++)
    {
        drawBoard(mat00);
        if (k % 2 == 0)
        {

            do
            {
                std::cout << RED << "ij" << k + 1 << RESET << " ";
                std::cin >> i >> j;

            } while ((i > 2 || i < 0 || j < 0 || j > 2) && mat00[i][j] != "0" || mat00[i][j] == "o" || mat00[i][j] == "x");
            mat00[i][j] = "o";
        }
        else
        {

            do
            {

                std::cout << LBLUE << "ij" << k + 1 << RESET << " ";
                std::cin >> i >> j;

            } while ((i > 2 || i < 0 || j < 0 || j > 2) && mat00[i][j] != "0" || mat00[i][j] == "o" || mat00[i][j] == "x");

            mat00[i][j] = "x";
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
    std::cout<<"DRAW";
    return 0;
}

/*از k بزرگ تر 5 شروع کن شرط ویکتوری را چک کردن*/
// O RED zooj ... X LBLUE fard
// ایکس میتونه جای او را بگیره BUG

// شرط برنده شدن مساوی بودن این خونه پایینیا
// player mitone X ya O bashe
//[i][0]== player && [i][1] == player && [i][2] == player
//[0][i]== player && [1][i] == player && [2][i] == player
//[0][0]== player && [1][1] == player && [2][2] == player
//[0][2]== player && [1][1] == player && [2][0] == player