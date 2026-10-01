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

void buscarValor(No *head, int valor) {
    No *aux = head;
    int posicao = 1;

    while (aux != NULL) {
        if (aux->dado == valor) {
            cout << "Valor " << valor << " encontrado na posicao " << posicao << "." << endl;
            return;
        }
        aux = aux->proximo;
        posicao++;
    }
    cout << "Valor " << valor << " nao foi encontrado na lista." << endl;
}

int main() {
    No *head = NULL;
    int opcao, valor;

    do {
        cout << "\n--- BUSCA NA LISTA ---" << endl;
        cout << "1 - Inserir numero" << endl;
        cout << "2 - Imprimir lista" << endl;
        cout << "3 - Buscar valor" << endl;
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
                cout << "Valor a buscar: ";
                cin >> valor;
                buscarValor(head, valor);
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