const tamanhoMaximo = 50;

class PriorityQueue {
  constructor() {
    this.dados = [];
  }

  inserir(valor) {
    if (this.dados.length === tamanhoMaximo) {
      console.log("Fila cheia!");
      return;
    }

    this.dados.push(valor);
    let i = this.dados.length - 1;

    // Heapify para cima
    while (i > 0 && this.dados[i] < this.dados[Math.floor((i - 1) / 2)]) {
      [this.dados[i], this.dados[Math.floor((i - 1) / 2)]] =
        [this.dados[Math.floor((i - 1) / 2)], this.dados[i]];
      i = Math.floor((i - 1) / 2);
    }
  }

  remover() {
    if (this.dados.length === 0) {
      alert("Fila vazia!");
      return -1;
    }

    const raiz = this.dados[0];
    this.dados[0] = this.dados.pop();

    // Heapify para baixo
    let i = 0;
    while (true) {
      let menor = i;
      let esq = 2 * i + 1;
      let dir = 2 * i + 2;

      if (esq < this.dados.length && this.dados[esq] < this.dados[menor]) menor = esq;
      if (dir < this.dados.length && this.dados[dir] < this.dados[menor]) menor = dir;

      if (menor === i) break;

      [this.dados[i], this.dados[menor]] = [this.dados[menor], this.dados[i]];
      i = menor;
    }

    return raiz;
  }

  exibirFila() {
    alert(`Fila:\n ${this.dados.join(" ")}`);
  }
}

let op;

// main 
const fila = new PriorityQueue();

  do{
    op = prompt("\nSelecione uma opção:\n1 - Inserir elemento na fila\n2 - Exibir fila\n3 - Remover um elemento da fila\n0 - Sair do programa");
    switch (op) {
      case '1':
        const valor = prompt("Digite o valor que deseja inserir: ")
        fila.inserir(parseInt(valor));
        break;
      case '2':
        fila.exibirFila();
        break;
      case '3':
        const removido = fila.remover();
        if (removido !== -1) {
          alert("Removido:", removido);
        }
        break;
      case '0':
        alert("Saindo!")
        break;
      default:
        console.log("Opção inválida!");
    }
  } while (op != 0);
