#include <iostream>
using namespace std;

struct No {
    int dado;
    No *proximo;
    No *anterior;
};

void inserirNaListaNoFinal(No *&head, int data) {
    No *novoNo = new No;
    novoNo->dado = data;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (head == NULL) {
        head = novoNo;
        return;
    }

    No *aux = head;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
    novoNo->anterior = aux;
}

void imprimirLista(No *head) {
    if (head == NULL) {
        cout << "Lista vazia." << endl;
        return;
    }
    No *aux = head;
    while (aux != NULL) {
        cout << "[" << aux->dado << "]";
        aux = aux->proximo;
    }
    cout << endl;
}

void removerPorValor(No *&head, int valor) {
    No *aux = head;

    while (aux != NULL && aux->dado != valor) {
        aux = aux->proximo;
    }

    if (aux == NULL) {
        cout << "Valor " << valor << " nao existe na lista." << endl;
        return;
    }

    if (aux->anterior == NULL) {          // remover o primeiro
        head = aux->proximo;
    } else {
        aux->anterior->proximo = aux->proximo;
    }

    if (aux->proximo != NULL) {           // se não for o último
        aux->proximo->anterior = aux->anterior;
    }

    delete aux;
    cout << "Valor " << valor << " removido com sucesso." << endl;
}

int main() {
    No *head = NULL;
    int opcao, valor;

    do {
        cout << "\n--- REMOVER POR VALOR ---" << endl;
        cout << "1 - Inserir numero" << endl;
        cout << "2 - Imprimir lista" << endl;
        cout << "3 - Remover valor" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Numero: ";
                cin >> valor;
                inserirNaListaNoFinal(head, valor);
                break;
            case 2:
                imprimirLista(head);
                break;
            case 3:
                cout << "Valor a remover: ";
                cin >> valor;
                removerPorValor(head, valor);
                break;
            case 0:
                cout << "Encerrando..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}