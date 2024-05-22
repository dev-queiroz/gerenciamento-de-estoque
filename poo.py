class Entidade:
    def __init__(self, nome):
        self.nome = nome

    def get_nome(self):
        return self.nome

    def imprimir(self):
        print(f"Nome da Entidade: {self.nome}")


class Produto(Entidade):
    def __init__(self, nome, codigo, descricao, preco, quantidade_estoque):
        super().__init__(nome)
        self.codigo = codigo
        self.descricao = descricao
        self.preco = preco
        self.quantidade_estoque = quantidade_estoque

    def imprimir(self):
        print(f"Produto: {self.nome} - Código: {self.codigo} - Descrição: {self.descricao} - Preço: R${self.preco:.2f} - Quantidade em Estoque: {self.quantidade_estoque}")


class Fornecedor(Entidade):
    def __init__(self, nome, contato, endereco):
        super().__init__(nome)
        self.contato = contato
        self.endereco = endereco

    def imprimir(self):
        print(f"Fornecedor: {self.nome} - Contato: {self.contato} - Endereço: {self.endereco}")

    def editar_informacoes(self, nome, contato, endereco):
        self.nome = nome
        self.contato = contato
        self.endereco = endereco


class Estoque(Entidade):
    def __init__(self, nome):
        super().__init__(nome)
        self.produtos = []

    def adicionar_produto(self, produto):
        self.produtos.append(produto)

    def atualizar_estoque(self, codigo, quantidade):
        for produto in self.produtos:
            if produto.codigo == codigo:
                produto.quantidade_estoque += quantidade
                print(f"Estoque de {produto.nome} atualizado para {produto.quantidade_estoque}")
                return
        print("Produto não encontrado")

    def imprimir(self):
        print("Relatório de Estoque:")
        for produto in self.produtos:
            produto.imprimir()


# Exemplo de uso
estoque = Estoque("Estoque Principal")
fornecedor = Fornecedor("Fornecedor Padrão", "contato@fornecedor.com", "Endereço Padrão")

while True:
    print("\nOpções:")
    print("1. Adicionar produto")
    print("2. Atualizar estoque")
    print("3. Gerar relatório")
    print("4. Editar fornecedor")
    print("5. Sair")

    opcao = int(input("Opção: "))

    if opcao == 1:
        nome = input("Nome do produto: ")
        codigo = input("Código do produto: ")
        descricao = input("Descrição do produto: ")
        preco = float(input("Preço do produto (separado por '.'): "))
        quantidade_estoque = int(input("Quantidade em estoque: "))

        novo_produto = Produto(nome, codigo, descricao, preco, quantidade_estoque)
        estoque.adicionar_produto(novo_produto)
        print("Produto adicionado com sucesso!")

    elif opcao == 2:
        codigo = input("Código do produto: ")
        quantidade = int(input("Quantidade a adicionar/remover: "))

        estoque.atualizar_estoque(codigo, quantidade)

    elif opcao == 3:
        estoque.imprimir()

    elif opcao == 4:
        nome = input("Nome do fornecedor: ")
        contato = input("Contato do fornecedor: ")
        endereco = input("Endereço do fornecedor: ")
        fornecedor.editar_informacoes(nome, contato, endereco)

    elif opcao == 5:
        break

    else:
        print("Opção inválida. Por favor, tente novamente.")
