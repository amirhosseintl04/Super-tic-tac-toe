#include <iostream>
#define RED "\033[31m"
#define LBLUE "\033[94m"
#define RESET "\033[0m"

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
        if (matrix[i][0] != "." && matrix[i][1] != "." && matrix[i][2] != ".")
        {
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

void drawBoard(std::string matrix[][3]) {
    std::cout << "+-----------+" << std::endl;
    
    for (int i = 0; i < 3; i++) {
       // std::cout << i + 1 << " ";
       std::cout<<"|";
        for (int j = 0; j < 3; j++) {
            std::cout <<" "<< matrix[i][j]<<" ";
            if (j < 2) std::cout << "|";
        }
        std::cout<<"|";
        std::cout << std::endl;
        if (i < 2) std::cout << "+-----------+" << std::endl;
    }
    std::cout << "+-----------+" << std::endl;
    std::cout << std::endl;
}
int main()
{
    system("cls");          
    int victory;             
    std::string mat00[3][3]; // this is the matrix for the player

    // initialize the starter matrix to 0 for checking
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat00[i][j] = ".";
        }
    }

    int i, j;

    // A loop to run through our matrix
    for (int k = 0; k < 9; k++)
    {
        drawBoard(mat00);
    
        if (k % 2 == 0)
        {

            do
            {
                std::cout << RED << "Player O : " << RESET;
                std::cin >> i >> j;

            } while ((i > 2 || i < 0 || j < 0 || j > 2) && mat00[i][j] != "." || mat00[i][j] == "o" || mat00[i][j] == "x");
            mat00[i][j] = "o";
        }
        else
        {

            do
            {

                std::cout << LBLUE << "Player X : " << RESET;
                std::cin >> i >> j;

            } while ((i > 2 || i < 0 || j < 0 || j > 2) && mat00[i][j] != "." || mat00[i][j] == "o" || mat00[i][j] == "x");

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
    std::cout << "DRAW";
    return 0;
}