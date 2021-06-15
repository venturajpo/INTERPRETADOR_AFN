#include "automato.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

std::vector<std::string> dividirString(const std::string& str, char divisor, bool empty = false)
{
    std::vector<std::string> strings;
    std::istringstream stream (str);
    std::string ret;
    while(std::getline(stream,ret,divisor))
    {
        strings.push_back(ret);
    }

    if(!empty)
    {
        auto i = std::find(strings.begin(), strings.end(), "");
        while(i != strings.end()) {
            std::find(strings.begin(), strings.end(), "");
            strings.erase(i);
        }
    }

    return strings;
}

std::string juntarListaString(std::vector<std::string>::iterator first, std::vector<std::string>::iterator last,  char separador = 0, bool empty = false)
{
    std::string saida;
    int i = 0;
    for(std::vector<std::string>::iterator it = first; it != last; ++it)
    {
        if(it->empty() && empty == true)
            continue;
        if(i != 0 && separador != 0)
            saida.push_back(separador);
        saida.append(*it);
        ++i;
    }
    return saida;
}

Automato::Automato(std::string especificacoesTexto)
{
    std::vector<std::string> linhas = dividirString(especificacoesTexto, '\n');

    int q_QtdEstadosAutomato = -1;
    int s_QtdSimbolosAlfabetoExtendido  = -1;
    int t_QtdTransicoesAFN = -1;
    IndiceEstado q0_IndiceEstadoInicial = -1;
    int a_QtdEstadosAceitacao = -1;

    {   //Infos Básicas
        std::vector<std::string> linhaBasica = dividirString(linhas[0], ' ');

        q_QtdEstadosAutomato = std::stoi(linhaBasica[0]);
        s_QtdSimbolosAlfabetoExtendido  = std::stoi(linhaBasica[1]);
        t_QtdTransicoesAFN = std::stoi(linhaBasica[2]);
        q0_IndiceEstadoInicial = std::stoi(linhaBasica[3]);
        a_QtdEstadosAceitacao = std::stoi(linhaBasica[4]);

        especificacoesAutomato.estadoInicial = q0_IndiceEstadoInicial;
        especificacoesAutomato.quantidadeEstados = q_QtdEstadosAutomato;
        especificacoesAutomato.quantidadeSimbolos = s_QtdSimbolosAlfabetoExtendido;

    }

    {   //Estados de aceitação
        std::vector<IndiceEstado> estadosAceitacao;
        std::vector<std::string> linhaAceitacao = dividirString(linhas[1], ' ');

        for(const auto& estado : linhaAceitacao)
            estadosAceitacao.push_back(std::stoi(estado));

        if(estadosAceitacao.size() != (unsigned int)a_QtdEstadosAceitacao)
            std::cerr << "Quantidade de estados de aceitação explicitado na entrada não corresponde ao encontrado.";

        especificacoesAutomato.estadosAceitacao = estadosAceitacao;
    }

    {   //Funão de Transição
        FuncaoTransicao func;
        func.inicializar(q_QtdEstadosAutomato, s_QtdSimbolosAlfabetoExtendido);

        for(int i = 2; i < t_QtdTransicoesAFN + 2; ++i)
        {
            std::vector<std::string> strTransicao = dividirString(linhas[i],' ');
            IndiceEstado estadoOrigem = std::stoi(strTransicao[0]);
            Simbolo simbolo = std::stoi(strTransicao[1]);
            IndiceEstado estadoDestino = std::stoi(strTransicao[2]);

            func.inserirTransicao(estadoOrigem, simbolo, estadoDestino);
        }

        especificacoesAutomato.funcao = func;
    }
}

bool Automato::testarCadeia(const Cadeia &cadeia)
{
    return visitarCadeia(cadeia, especificacoesAutomato.estadoInicial, 0);
}

bool Automato::visitarCadeia(const Cadeia &cadeia, const IndiceEstado estadoAtual, const int indice)
{
    const int qtdItensCadeia = cadeia.size();
    ConjuntoDestino vazio = especificacoesAutomato.funcao.estados(estadoAtual, 0);

    for(const auto& estado : vazio)                                 //Testar todas os branchs com simbolo vazio sem mudar o simbolo atual
        if(visitarCadeia(cadeia, estado, indice) == true)
            return true;

    if(indice == qtdItensCadeia)
    {
        for(const auto& estadoAceitacao: especificacoesAutomato.estadosAceitacao)
        {
            if(estadoAceitacao == estadoAtual)
                return true;
        }
        return false;
    }

    Simbolo simbolo = cadeia[indice];
    ConjuntoDestino transicao = especificacoesAutomato.funcao.estados(estadoAtual, simbolo);

    for(const auto& estado : transicao)                               //Testar
        if(visitarCadeia(cadeia, estado, indice + 1) == true)
            return true;

    return false;
}

void FuncaoTransicao::inicializar(const int quantidadeEstados, const int quantidadeSimbolos)
{
    transicao.resize(quantidadeEstados);
    for(auto& i: transicao)
    {
        i.resize(quantidadeSimbolos);
        for(auto& j: i)
            j.reserve(quantidadeEstados);
    }
}

std::vector<IndiceEstado> FuncaoTransicao::estados(const IndiceEstado &estadoAtual, const Simbolo &simbolo) const
{
    return transicao[estadoAtual][simbolo];
}

void FuncaoTransicao::inserirTransicao(const IndiceEstado &estadoAtual, const Simbolo &simbolo, const IndiceEstado &estadoDestino)
{
    ConjuntoDestino& destinos = transicao[estadoAtual][simbolo];
    if(std::find(destinos.begin(), destinos.end(), estadoDestino) != destinos.end())
        return; //Já existe
    destinos.push_back(estadoDestino);
    std::sort(destinos.begin(), destinos.end());
}

void gerarAutomatos(const char *entrada, const char *saida)
{
    std::ifstream input;
    std::ofstream output;
    input.open(entrada);
    output.open(saida);

    if(!input)
    {
        std::cerr << "Erro ao abrir o arquivo de entrada: ";
        return;
    }

    if(!output)
    {
        std::cerr << "Erro ao abrir o arquivo de saída: ";
        return;
    }

    std::string arquivoEntrada ((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    arquivoEntrada.erase(std::remove(arquivoEntrada.begin(), arquivoEntrada.end(), '\r'), arquivoEntrada.end());
    std::vector<std::string> linhas = dividirString(arquivoEntrada, '\n');

    int quantidadeAutomatos = std::stoi(linhas[0]);

    std::vector<Automato> automatos;
    std::vector<std::vector<Cadeia>> cadeias;
    automatos.reserve(quantidadeAutomatos);
    cadeias.reserve(quantidadeAutomatos);

    size_t posAutomatoInicial = 1;
    size_t posAutomatoFinal = -1;
    size_t posCadeiasInicial = 1;
    size_t posCadeiasFinal = -1;

    for(int i = 0; i < quantidadeAutomatos; ++i)
    {
        std::vector<std::string> specs = dividirString(linhas[posAutomatoInicial], ' ');
        int t = std::stoi(specs[2]);
        posAutomatoFinal = t + posAutomatoInicial + 2;

        std::string strAutomato = juntarListaString(linhas.begin() + posAutomatoInicial, linhas.begin() + posAutomatoFinal, '\n');

        automatos.push_back(Automato(strAutomato));

        int qtdTestes = std::stoi(linhas[posAutomatoFinal]);

        posCadeiasInicial = posAutomatoFinal + 1;
        posCadeiasFinal = posCadeiasInicial + qtdTestes;

        std::vector<Cadeia> listaCadeia;
        for(auto j = posCadeiasInicial; j < posCadeiasFinal; ++j)
        {
            std::string strCadeia = linhas[j];
            std::vector<std::string> listaCadeias = dividirString(strCadeia, ' ');
            Cadeia cadeia;
            for(const std::string& simb : listaCadeias)
                cadeia.push_back(std::stoi(simb));
            listaCadeia.push_back(cadeia);
        }
        cadeias.push_back(listaCadeia);

        posAutomatoInicial = posCadeiasFinal;
    }

    for(int i = 0; i < quantidadeAutomatos; ++i)
    {
        int count = 0;
        for(const auto& cadeia : cadeias[i])
        {
            if(count)
                output << " ";
            output << automatos[i].testarCadeia(cadeia);
            ++count;
        }
        output << std::endl;
    }


}
