
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;

	// Verifica se o valor já existe na lista
    if (posicaoElemento(novo->valor) != NULL) {
        cout << "Elemento já existe na lista. Inserção ignorada.\n";
        free(novo); // Libera a memória do novo nó, pois não será inserido
        return;
    }

    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo; // Lista vazia, novo nó se torna o primeiro
    } else {
        // Procura o final da lista
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo; // Insere o novo nó no final da lista
    }
}

void excluirElemento()

{
	int numero;
cout << "Digite o numero a ser buscado e deletado: ";
cin >> numero;

// Verifica se a lista está vazia
if (primeiro == NULL) {
    cout << "A lista está vazia!\n";
    return;
}

// Usa posicaoElemento para encontrar o nó a ser deletado
NO* aux = posicaoElemento(numero);

// Se o nó não for encontrado
if (aux == NULL) {
    cout << "Elemento não encontrado.\n";
    return;
}

// Caso especial: Se o nó a ser deletado for o primeiro nó
if (aux == primeiro) {
    primeiro = primeiro->prox; // Atualiza o primeiro nó
} else {
    // Encontra o nó anterior
    NO* anterior = primeiro;
    while (anterior->prox != aux) {
        anterior = anterior->prox;
    }
    anterior->prox = aux->prox; // Ignora o nó a ser deletado
}

free(aux); // Libera a memória do nó deletado
cout << "Elemento excluído.\n";
}

void buscarElemento()
{
    int numero;
    cout << "Digite o numero a ser buscado: ";
    cin >> numero;

    // Usa a função posicaoElemento para encontrar o nó
    NO* resultado = posicaoElemento(numero);

    // Checa se o nó foi encontrado
    if (resultado != NULL) {
        cout << "Encontrado\n";
    } else {
        cout << "Elemento nao encontrado\n";
    }
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}