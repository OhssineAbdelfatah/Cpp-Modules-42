#include <iostream>
#include <ctype.h>
using namespace std;
int main(int ac, char **av)
{
    int i = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else if (ac > 1)
    {
        i = 1;
        while(i < ac)
        {
            int j = 0;
            while(av[i][j] != '\0')
            {
                char c = (char)toupper(av[i][j]);
                std::cout.put(c);
                j++;
            }
            i++;
        }
        std::cout << "\n";
    }
    return 0;
}