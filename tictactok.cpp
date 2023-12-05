#include <iostream>
#define RED "\033[31m"
#define LBLUE "\033[94m"
#define RESET "\033[0m"
int main()
{
    system("cls");
    std::string mat00[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat00[i][j] = "0";
        }
    }
    int i, j;

    for (int k = 0; k < 9 ; k++)
    {
        if (k % 2 == 0){
            do
            {
                std::cout <<RED<< "ij" << k+1 <<RESET<< std::endl;
                std::cin >> i >> j;
            } while ((i>2 || i<0|| j<0|| j>2)&&mat00[i][j] != "0");
        }
        else{
            do
            {
                std::cout <<LBLUE<< "ij" << k+1 <<RESET<< std::endl;
                std::cin >> i >> j;
            } while ((i>2 || i<0|| j<0|| j>2)&&mat00[i][j] != "0");
        }
        if(k%2==0){
            do{
                std::cout<<"xORo";
                std::cin >> mat00[i][j];
            } while (mat00[i][j]!="o"); 
        }else{
            do{
                std::cout<<"xORo";
                std::cin >> mat00[i][j];
            } while (mat00[i][j]!="x");
        }
        system("cls");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << mat00[i][j]<<"  ";
        }
        std::cout << "\n";
    }
    return 0;
}

/*از k بزرگ تر 5 شروع کن شرط ویکتوری را چک کردن*/
