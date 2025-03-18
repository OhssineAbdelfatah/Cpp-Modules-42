#include <iostream>
#include <ctype.h>

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
            if (i < ac - 1)
				std::cout << ' ';
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}