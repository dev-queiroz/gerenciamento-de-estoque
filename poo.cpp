#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe base Entidade
class Entidade {
public:
    string nome;

    Entidade(string n) : nome(n) {}
    
    string getNome() {
        return nome;
    }
    
    void imprimir() { 
        cout << "Nome da Entidade: " << nome << endl;
    }
};

// Classe Produto herda de Entidade
class Produto : public Entidade {
public:
    string codigo;
    string descricao;
    float preco;
    int quantidade_estoque;

    Produto(string n, string c, string d, float p, int q) : Entidade(n), codigo(c), descricao(d), preco(p), quantidade_estoque(q) {}

    void imprimir() {
        cout << "Produto: " << nome << " - Código: " << codigo << " - Descrição: " << descricao << " - Preço: R$" << preco << " - Quantidade em Estoque: " << quantidade_estoque << endl;
    }
};

// Classe Fornecedor herda de Entidade
class Fornecedor : public Entidade {
private:
    string contato;
    string endereco;

public:
    Fornecedor(string n, string c, string e) : Entidade(n), contato(c), endereco(e) {}

    void imprimir() {
        cout << "Fornecedor: " << nome << " - Contato: " << contato << " - Endereço: " << endereco << endl;
    }

    void editarInformacoes(string n, string c, string e) {
        nome = n;
        contato = c;
        endereco = e;
    }
};

// Classe Estoque herda de Entidade
class Estoque : public Entidade {
private:
    vector<Produto> produtos;

public:
    Estoque(string n) : Entidade(n) {}

    void adicionar_produto(Produto p) {
        produtos.push_back(p);
    }

    void atualizar_estoque(string c, int q) {
        for (int i = 0; i < produtos.size(); ++i) {
    		Produto& p = produtos[i];
            if (p.codigo == c) {
                p.quantidade_estoque += q;
                cout << "Estoque de " << p.nome << " atualizado para " << p.quantidade_estoque << endl;
                return;
            }
        }
        cout << "Produto não encontrado" << endl;
    }

    void remover_produto(string codigo) {
        for (int i = 0; i < produtos.size(); i++) {
            if (produtos[i].codigo == codigo) {
                produtos.erase(produtos.begin() + i);
                cout << "Produto " << codigo << " removido com sucesso!" << endl;
                return;
            }
        }
        cout << "Produto não encontrado" << endl;
    }

    void imprimir() {
        cout << "Relatório de Estoque:" << endl;
        for (Produto& p : produtos) {
            p.imprimir();
        }
    }
};

// Exemplo de uso
int main() {
    Estoque estoque("Estoque Principal");
    Fornecedor fornecedor("Fornecedor Padrão", "contato@fornecedor.com", "Endereço Padrão");

    while (true) {
        cout << "\nOpções:" << endl;
        cout << "1. Adicionar produto" << endl;
        cout << "2. Atualizar estoque" << endl;
        cout << "3. Gerar relatório" << endl;
        cout << "4. Editar fornecedor" << endl;
        cout << "5. Remover produto por código" << endl;
        cout << "0. Sair" << endl;

        int opcao;
        cin >> opcao;
        cin.ignore();

        if (opcao == 1) {
            string nome, codigo, descricao;
            float preco;
            int quantidade_estoque;
            cout << "Nome do produto: ";
            getline(cin, nome);
            cout << "Código do produto: ";
            getline(cin, codigo);
            cout << "Descrição do produto: ";
            getline(cin, descricao);
            cout << "Preço do produto (separado por '.'): ";
            cin >> preco;
            cout << "Quantidade em estoque: ";
            cin >> quantidade_estoque;
            cin.ignore();

            Produto novoProduto(nome, codigo, descricao, preco, quantidade_estoque);
            estoque.adicionar_produto(novoProduto);
            cout << "Produto adicionado com sucesso!" << endl;
        } else if (opcao == 2) {
            string codigo;
            int quantidade;
            cout << "Código do produto: ";
            getline(cin, codigo);
            cout << "Quantidade a adicionar/remover: ";
            cin >> quantidade;
            cin.ignore();

            estoque.atualizar_estoque(codigo, quantidade);
        } else if (opcao == 3) {
            estoque.imprimir();
        } else if (opcao == 4) {
            string nome, contato, endereco;
            cout << "Nome do fornecedor: ";
            getline(cin, nome);
            cout << "Contato do fornecedor: ";
            getline(cin, contato);
            cout << "Endereço do fornecedor: ";
            getline(cin, endereco);
            fornecedor.editarInformacoes(nome, contato, endereco);
        } else if (opcao == 5) {
        	string codigo;
        	cout << "Código do produto a remover: ";
        	getline(cin, codigo);
        	estoque.remover_produto(codigo);
        } else if (opcao == 0) {
            break;
        } else {
            cout << "Opção inválida. Por favor, tente novamente." << endl;
        }
    }

    return 0;
}