#include <iostream>
#include "automato.h"

int main()
{
    gerarAutomatos("entrada.txt", "saida.txt");

//    {
//        Automato automato("2 3 4 0 1\n0\n0 1 0\n0 1 1\n0 2 1\n1 2 0");

//        Cadeia cadeia1 = {1};
//        Cadeia cadeia2 = {1,1};
//        Cadeia cadeia3 = {1,1,1};
//        Cadeia cadeia4 = {1,2,2,1,1,1,2,2,1};
//        Cadeia cadeia5 = {2,2,2,1};
//        Cadeia cadeia6 = {2,1,2,2};

//        std::cout << "Automato 1:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//        std::cout << "Cadeia 5: " << automato.testarCadeia(cadeia5) << std::endl;
//        std::cout << "Cadeia 6: " << automato.testarCadeia(cadeia6) << std::endl;
//    }

//    {
//        Automato automato("3 3 6 0 1\n1\n0 0 1\n1 1 0\n0 1 2\n2 2 2\n2 1 1\n2 2 1");

//        Cadeia cadeia1 = {0};
//        Cadeia cadeia2 = {1};
//        Cadeia cadeia3 = {1,2,2,2,2,2,1};
//        Cadeia cadeia4 = {1,1,1,2,1,1,1};
//        Cadeia cadeia5 = {1,2,1,1};
//        Cadeia cadeia6 = {1,2,2,1,2,2};
//        Cadeia cadeia7 = {2};
//        Cadeia cadeia8 = {1,1,2,2,1,2};

//        std::cout << "Automato 2:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//        std::cout << "Cadeia 5: " << automato.testarCadeia(cadeia5) << std::endl;
//        std::cout << "Cadeia 6: " << automato.testarCadeia(cadeia6) << std::endl;
//        std::cout << "Cadeia 7: " << automato.testarCadeia(cadeia7) << std::endl;
//        std::cout << "Cadeia 8: " << automato.testarCadeia(cadeia8) << std::endl;
//    }

//    {
//        Automato automato("4 3 8 0 1\n3\n0 1 1\n1 1 0\n2 1 3\n3 1 2\n0 2 2\n2 2 0\n1 2 3\n3 2 1\n");

//        Cadeia cadeia1 = {1,2,1,2,1,2};
//        Cadeia cadeia2 = {1,1,1,1,1,1};
//        Cadeia cadeia3 = {1,1,1,2,1,1};
//        Cadeia cadeia4 = {1,1,1,2,2,2};
//        Cadeia cadeia5 = {1,2,1,2,1,1};
//        Cadeia cadeia6 = {1,1,2,2,2};
//        Cadeia cadeia7 = {1,1,1,2,2};
//        Cadeia cadeia8 = {1,1,2,1,1,1};

//        std::cout << "Automato 3:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//        std::cout << "Cadeia 5: " << automato.testarCadeia(cadeia5) << std::endl;
//        std::cout << "Cadeia 6: " << automato.testarCadeia(cadeia6) << std::endl;
//        std::cout << "Cadeia 7: " << automato.testarCadeia(cadeia7) << std::endl;
//        std::cout << "Cadeia 8: " << automato.testarCadeia(cadeia8) << std::endl;
//    }

//    {
//        Automato automato("5 3 8 0 1\n1\n0 1 0\n0 2 2\n2 0 1\n2 0 3\n3 1 3\n3 2 4\n4 2 4\n4 1 1\n");

//        Cadeia cadeia1 = {1,1,1,1,1};
//        Cadeia cadeia2 = {1,1,1,1,2};
//        Cadeia cadeia3 = {1,1,2,1,1,2,2};
//        Cadeia cadeia4 = {1,1,2,2,2};
//        Cadeia cadeia5 = {1,1,2};
//        Cadeia cadeia6 = {2,1,1,1};
//        Cadeia cadeia7 = {2,1,2,1};
//        Cadeia cadeia8 = {2,1,2,1,1};

//        std::cout << "Automato 4:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//        std::cout << "Cadeia 5: " << automato.testarCadeia(cadeia5) << std::endl;
//        std::cout << "Cadeia 6: " << automato.testarCadeia(cadeia6) << std::endl;
//        std::cout << "Cadeia 7: " << automato.testarCadeia(cadeia7) << std::endl;
//        std::cout << "Cadeia 8: " << automato.testarCadeia(cadeia8) << std::endl;
//    }

//    {
//        Automato automato("2 4 4 0 1\n1\n0 1 0\n0 2 0\n0 3 0\n0 1 1\n");

//        Cadeia cadeia1 = {0};
//        Cadeia cadeia2 = {1};
//        Cadeia cadeia3 = {1,1,2};
//        Cadeia cadeia4 = {1,2,3,1};

//        std::cout << "Automato 5:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//    }

//    {
//        Automato automato("7 4 9 0 1\n6\n0 1 1\n1 0 2\n2 0 4\n4 0 6\n4 2 4\n1 0 3\n3 0 5\n5 0 6\n5 3 5\n");

//        Cadeia cadeia1 = {0};
//        Cadeia cadeia2 = {1};
//        Cadeia cadeia3 = {1,2,2,2,2};
//        Cadeia cadeia4 = {1,3,3,3,3,3};
//        Cadeia cadeia5 = {1,2,2,2,3};
//        Cadeia cadeia6 = {1,3,3,3,2};
//        Cadeia cadeia7 = {2,1,1,1};

//        std::cout << "Automato 6:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//        std::cout << "Cadeia 5: " << automato.testarCadeia(cadeia5) << std::endl;
//        std::cout << "Cadeia 6: " << automato.testarCadeia(cadeia6) << std::endl;
//        std::cout << "Cadeia 7: " << automato.testarCadeia(cadeia7) << std::endl;
//    }

//    {
//        Automato automato("7 4 9 0 1\n6\n0 1 1\n1 0 2\n2 0 4\n4 0 6\n4 2 4\n1 0 3\n3 0 5\n5 0 6\n5 3 5\n");

//        Cadeia cadeia1 = {0};
//        Cadeia cadeia2 = {1};
//        Cadeia cadeia3 = {1,2,2,2,2};
//        Cadeia cadeia4 = {1,3,3,3,3,3};
//        Cadeia cadeia5 = {1,2,2,2,3};
//        Cadeia cadeia6 = {1,3,3,3,2};
//        Cadeia cadeia7 = {2,1,1,1};

//        std::cout << "Automato 6:"<< std::endl;
//        std::cout << "Cadeia 1: " << automato.testarCadeia(cadeia1) << std::endl;
//        std::cout << "Cadeia 2: " << automato.testarCadeia(cadeia2) << std::endl;
//        std::cout << "Cadeia 3: " << automato.testarCadeia(cadeia3) << std::endl;
//        std::cout << "Cadeia 4: " << automato.testarCadeia(cadeia4) << std::endl;
//        std::cout << "Cadeia 5: " << automato.testarCadeia(cadeia5) << std::endl;
//        std::cout << "Cadeia 6: " << automato.testarCadeia(cadeia6) << std::endl;
//        std::cout << "Cadeia 7: " << automato.testarCadeia(cadeia7) << std::endl;
//    }
}
