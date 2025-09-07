import sys

# Tamanho máximo da fila
TAMANHO_MAXIMO = 50

class PriorityQueue:
    def __init__(self):
        self.dados = [0] * TAMANHO_MAXIMO  # Vetor fixo
        self.tamanho = 0

    # Inserir elemento mantendo a propriedade de min-heap
    def inserir(self, valor):
        if self.tamanho == TAMANHO_MAXIMO:
            print("Fila cheia!")
            return

        i = self.tamanho
        self.dados[i] = valor
        self.tamanho += 1

        # Ajusta o heap para cima
        while i > 0 and self.dados[i] < self.dados[(i - 1) // 2]:
            self.dados[i], self.dados[(i - 1) // 2] = self.dados[(i - 1) // 2], self.dados[i]
            i = (i - 1) // 2

    # Remove o menor elemento (topo do heap)
    def remover(self):
        if self.tamanho == 0:
            print("Fila vazia!")
            return -1

        raiz = self.dados[0]
        self.tamanho -= 1
        self.dados[0] = self.dados[self.tamanho]

        # Ajusta o heap para baixo
        i = 0
        while True:
            menor = i
            esq = 2 * i + 1
            dir = 2 * i + 2

            if esq < self.tamanho and self.dados[esq] < self.dados[menor]:
                menor = esq
            if dir < self.tamanho and self.dados[dir] < self.dados[menor]:
                menor = dir

            if menor == i:
                break

            self.dados[i], self.dados[menor] = self.dados[menor], self.dados[i]
            i = menor

        return raiz

    # Exibe a fila
    def exibir(self):
        print("Fila:", end=" ")
        for i in range(self.tamanho):
            print(self.dados[i], end=" ")
        print()


# Programa principal
def main():
    fila = PriorityQueue()

    while True:
        print("\nSelecione uma opcao:")
        print("1 - Inserir elemento na fila")
        print("2 - Exibir fila")
        print("3 - Remover um elemento da fila")
        print("0 - Sair do programa")

        try:
            op = int(input("Opção: "))
        except ValueError:
            print("Opção inválida.")
            continue

        if op == 1:
            try:
                valor = int(input("Digite o valor que deseja inserir: "))
                fila.inserir(valor)
            except ValueError:
                print("Valor inválido.")
        elif op == 2:
            fila.exibir()
        elif op == 3:
            removido = fila.remover()
            if removido != -1:
                print(f"Removido: {removido}")
        elif op == 0:
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()
