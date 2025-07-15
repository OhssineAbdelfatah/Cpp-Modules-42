#include <fstream>
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "Error : bad arguments";
        std::cout << std::endl;
    }
    else
    {
        std::cout << "hna\n";
        std::string fileName(av[1]);
        std::string baseStr(av[2]);
        std::string newStr(av[3]);
        std::string line;
        std::string res;

        std::ifstream in(av[1], std::ios::in);
        if (!in.is_open())
        {
            std::cout << "Error while opening file" << std::endl;
            return (1);
        }
        in.seekg(0, std::ios::end);
        if (in.tellg() == 0)
        {
            std::cout << "Error empty file" << std::endl;
            return (1);
        }
        in.seekg(0, std::ios::beg);

        while (1)
        {
            if(!getline(in, line))
                break;
            size_t pos = line.find(baseStr, 0);
            while (pos != std::string::npos && !baseStr.empty())
            {
                line.erase(pos, baseStr.size());
                line.insert(pos, newStr);
                pos = line.find(baseStr, 0);
            }

            if (!in.eof())
                res.append(line + "\n");
            else
                res.append(line);
        }
        std::ofstream out(fileName + ".replace");
        out << res;
        std::cout << res;
        out.close();
    }
}