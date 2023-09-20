/* torre_hannoi.cpp */

#include <iostream>


void hanoi (int discos, char origem, char destino, char ajuda)
{
    if( discos == 1)
    {
        std::cout << "\t Mova o disco " << discos << " de "
                  << origem << " para " << destino << std::endl;
    }
    else
    {
        hanoi(discos-1,origem,ajuda,destino);
        std::cout << "\t Mova o disco " << discos << " de "
                  << origem << " para " << destino << std::endl;
        hanoi(discos-1,ajuda,destino,origem);
    }
    return;
}

int main (void)
{
    int total_discos;
    std::cout << "Informe o numero de discos:" ;
    std::cin >> total_discos;
    hanoi(total_discos,'A','B','C');
    return 0;
}
