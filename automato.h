#ifndef AUTOMATO_H
#define AUTOMATO_H
#include <vector>
#include <string>
typedef int IndiceEstado;
typedef int Simbolo ;
typedef std::vector<Simbolo> Cadeia;
typedef std::vector<IndiceEstado> ConjuntoDestino;
typedef std::vector<ConjuntoDestino> SimboloParaDestinos;
typedef std::vector<SimboloParaDestinos> TransicoesDeEstado;
class FuncaoTransicao {
    TransicoesDeEstado transicao;
public:
    void inicializar(const int quantidadeEstados, const int quantidadeSimbolos);
    std::vector<IndiceEstado> estados(const IndiceEstado& estadoAtual, const Simbolo& simbolo) const;
    void inserirTransicao(const IndiceEstado& estadoAtual, const Simbolo& simbolo, const IndiceEstado& estadoDestino);
};

struct EspecificacoesAutomato {
    int quantidadeEstados = -1;
    int estadoInicial = -1;
    int quantidadeSimbolos = -1;
    FuncaoTransicao funcao;
    std::vector<IndiceEstado> estadosAceitacao;
};

class Automato {
    EspecificacoesAutomato especificacoesAutomato;
    bool visitarCadeia(const Cadeia& cadeia, const IndiceEstado estadoAtual, const int indice);
public:
    explicit Automato(std::string especificacoesTexto);
    bool testarCadeia(const Cadeia& cadeia);
};

void gerarAutomatos(const char* entrada = "entrada.txt", const char* saida = "saida.txt");
#endif // AUTOMATO_H
