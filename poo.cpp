// Inclui as bibliotecas de entrada/saída, strings e vetores
#include <iostream>
#include <string>
#include <vector>

// Utiliza o espaço de nomes padrão para evitar a necessidade de prefixar std::
using namespace std;

// Define uma classe base chamada Entidade
class Entidade {
public:
    string nome; // Variável para armazenar o nome da entidade

    // Construtor que inicializa o nome da entidade
    Entidade(string n) : nome(n) {}
    
    // Método para obter o nome da entidade
    string getNome() {
        return nome;
    }
    
    // Método para imprimir o nome da entidade
    void imprimir() { 
        cout << "Nome da Entidade: " << nome << endl;
    }
};

// Define uma classe Produto que herda da classe Entidade
class Produto : public Entidade {
public:
    string codigo; // Variável para armazenar o código do produto
    string descricao; // Variável para armazenar a descrição do produto
    float preco; // Variável para armazenar o preço do produto
    int quantidade_estoque; // Variável para armazenar a quantidade em estoque

    // Construtor que inicializa os atributos do produto e chama o construtor da classe base
    Produto(string n, string c, string d, float p, int q) : Entidade(n), codigo(c), descricao(d), preco(p), quantidade_estoque(q) {}

    // Método para imprimir as informações do produto
    void imprimir() {
        cout << "Produto: " << nome << " - Codigo: " << codigo << " - Descricao: " << descricao << " - Preco: R$" << preco << " - Quantidade em Estoque: " << quantidade_estoque << endl;
    }
};

// Define uma classe Fornecedor que herda da classe Entidade
class Fornecedor : public Entidade {
private:
    string contato; // Variável privada para armazenar o contato do fornecedor
    string endereco; // Variável privada para armazenar o endereço do fornecedor

public:
    // Construtor que inicializa os atributos do fornecedor e chama o construtor da classe base
    Fornecedor(string n, string c, string e) : Entidade(n), contato(c), endereco(e) {}

    // Método para imprimir as informações do fornecedor
    void imprimir() {
        cout << "Fornecedor: " << nome << " - Contato: " << contato << " - Endereco: " << endereco << endl;
    }

    // Método para editar as informações do fornecedor
    void editarInformacoes(string n, string c, string e) {
        nome = n;
        contato = c;
        endereco = e;
    }
};

// Define uma classe Estoque que herda da classe Entidade
class Estoque : public Entidade {
private:
    vector<Produto> produtos; // Vetor privado para armazenar os produtos

public:
    // Construtor que inicializa o nome do estoque e chama o construtor da classe base
    Estoque(string n) : Entidade(n) {}

    // Método para adicionar um produto ao vetor de produtos
    void adicionar_produto(Produto p) {
        produtos.push_back(p);
    }

    // Método para atualizar a quantidade em estoque de um produto, onde "i" vai percorrer o tamanho do vetor produtos, até encontrar o código buscado para prosseguir a atualização
    void atualizar_estoque(string c, int q) {
        for (int i = 0; i < (int) produtos.size(); ++i) {
            Produto& p = produtos[i];
            if (p.codigo == c) {
                p.quantidade_estoque += q;
                cout << "Estoque de " << p.nome << " atualizado para " << p.quantidade_estoque << endl;
                return;
            }
        }
        cout << "Produto nao encontrado" << endl;
    }

    // Método para remover um produto do vetor de produtos, onde novamente, "i" percorrerá o vetor produtos até achar o código buscado, e ".erase()" apaga o produto que tiver o código buscado
    void remover_produto(string codigo) {
        for (int i = 0; i < (int) produtos.size(); i++) {
            if (produtos[i].codigo == codigo) {
                produtos.erase(produtos.begin() + i);
                cout << "Produto " << codigo << " removido com sucesso!" << endl;
                return;
            }
        }
        cout << "Produto nao encontrado" << endl;
    }

    // Método para imprimir um relatório com todos os produtos em estoque
    void imprimir() {
        cout << "Relatorio de Estoque:" << endl;
        for (int i = 0; i < (int) produtos.size(); i++) {
			Produto p = produtos[i];
            p.imprimir();
        }
    }
};

// Função principal que demonstra o uso das classes
int main() {
    // Cria um objeto Estoque chamado 'estoque'
    Estoque estoque("Estoque Principal");
    // Cria um objeto Fornecedor chamado 'fornecedor'
    Fornecedor fornecedor("Fornecedor Padrao", "contato@fornecedor.com", "Endereço Padrão");

    // Loop infinito para simular um menu de opções
    while (true) {
        // Imprime as opções do menu
        cout << "\nOpcoes:" << endl;
        cout << "1. Adicionar produto" << endl;
        cout << "2. Atualizar estoque" << endl;
        cout << "3. Gerar relatorio" << endl;
        cout << "4. Editar fornecedor" << endl;
        cout << "5. Remover produto por codigo" << endl;
        cout << "0. Sair" << endl;

        // Lê a opção do usuário
        int opcao;
        cin >> opcao;
        cin.ignore();

        // Executa a ação correspondente à opção escolhida
        if (opcao == 1) {
            // Código para adicionar um novo produto
            string nome, codigo, descricao;
            float preco;
            int quantidade_estoque;
            cout << "Nome do produto: ";
            getline(cin, nome);
            cout << "Codigo do produto: ";
            getline(cin, codigo);
            cout << "Descricao do produto: ";
            getline(cin, descricao);
            cout << "Preco do produto (separado por '.'): ";
            cin >> preco;
            cout << "Quantidade em estoque: ";
            cin >> quantidade_estoque;
            cin.ignore();

            Produto novoProduto(nome, codigo, descricao, preco, quantidade_estoque);
            estoque.adicionar_produto(novoProduto);
            cout << "Produto adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            // Código para atualizar o estoque de um produto
            string codigo;
            int quantidade;
            cout << "Codigo do produto: ";
            getline(cin, codigo);
            cout << "Quantidade a adicionar/remover: ";
            cin >> quantidade;
            cin.ignore();

            estoque.atualizar_estoque(codigo, quantidade);
        } else if (opcao == 3) {
            // Código para imprimir o relatório de estoque
            estoque.imprimir();
        } else if (opcao == 4) {
            // Código para editar as informações do fornecedor
            string nome, contato, endereco;
            cout << "Nome do fornecedor: ";
            getline(cin, nome);
            cout << "Contato do fornecedor: ";
            getline(cin, contato);
            cout << "Endereco do fornecedor: ";
            getline(cin, endereco);
            fornecedor.editarInformacoes(nome, contato, endereco);
        } else if (opcao == 5) {
            // Código para remover um produto pelo código
            string codigo;
        	cout << "Codigo do produto a remover: ";
        	getline(cin, codigo);
        	estoque.remover_produto(codigo);
        } else if (opcao == 0) {
            // Sai do loop e termina o programa
            break;
        } else {
            // Informa ao usuário que a opção é inválida
            cout << "Opcao invalida. Por favor, tente novamente." << endl;
        }
    }

    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}
