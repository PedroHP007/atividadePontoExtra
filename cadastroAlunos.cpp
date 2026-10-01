#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int idade;
    No *proximo;
    No *anterior;
};

void inserirAluno(No *&head, string nome, int idade) {
    No *novoNo = new No;
    novoNo->nome = nome;
    novoNo->idade = idade;
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
        cout << "Nenhum aluno cadastrado." << endl;
        return;
    }
    No *aux = head;
    int i = 1;
    while (aux != NULL) {
        cout << i << ") " << aux->nome << " - " << aux->idade << " anos" << endl;
        aux = aux->proximo;
        i++;
    }
}

int quantidadeAlunos(No *head) {
    int cont = 0;
    No *aux = head;
    while (aux != NULL) {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

void buscarAluno(No *head, string nome) {
    No *aux = head;
    int posicao = 1;
    while (aux != NULL) {
        if (aux->nome == nome) {
            cout << "Aluno encontrado na posicao " << posicao << ": "
                 << aux->nome << " - " << aux->idade << " anos" << endl;
            return;
        }
        aux = aux->proximo;
        posicao++;
    }
    cout << "Aluno nao encontrado." << endl;
}

void removerAluno(No *&head, string nome) {
    No *aux = head;

    while (aux != NULL && aux->nome != nome) {
        aux = aux->proximo;
    }

    if (aux == NULL) {
        cout << "Aluno nao encontrado." << endl;
        return;
    }

    if (aux->anterior == NULL) {          // é o primeiro
        head = aux->proximo;
    } else {
        aux->anterior->proximo = aux->proximo;
    }

    if (aux->proximo != NULL) {           // não é o último
        aux->proximo->anterior = aux->anterior;
    }

    delete aux;
    cout << "Aluno removido com sucesso." << endl;
}

int main() {
    No *head = NULL;
    int opcao;
    string nome;
    int idade;

    do {
        cout << "\n--- CADASTRO DE ALUNOS ---" << endl;
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Imprimir lista" << endl;
        cout << "3 - Quantidade de alunos" << endl;
        cout << "4 - Buscar aluno pelo nome" << endl;
        cout << "5 - Remover aluno" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(1000, '\n');

        switch (opcao) {
            case 1:
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Idade: ";
                cin >> idade;
                inserirAluno(head, nome, idade);
                break;
            case 2:
                imprimirLista(head);
                break;
            case 3:
                cout << "Total de alunos: " << quantidadeAlunos(head) << endl;
                break;
            case 4:
                cout << "Nome para buscar: ";
                getline(cin, nome);
                buscarAluno(head, nome);
                break;
            case 5:
                cout << "Nome para remover: ";
                getline(cin, nome);
                removerAluno(head, nome);
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