/*
 * Arvore Binaria de Busca (BST)
 * Operacoes: Insercao, Remocao e Busca (Pre-ordem, Em-ordem, Pos-ordem)
 * Linguagem: C
 */

#include <stdio.h>
#include <stdlib.h>

/* ======================================================
 * Estrutura do no da arvore
 * ====================================================== */
typedef struct sNo {
    int valor;
    struct sNo *esquerda;
    struct sNo *direita;
} No;

/* ======================================================
 * Funcoes auxiliares
 * ====================================================== */

/* Cria e retorna um novo no com o valor fornecido */
No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria!\n");
        exit(1);
    }
    novo->valor    = valor;
    novo->esquerda = NULL;
    novo->direita  = NULL;
    return novo;
}

/* ======================================================
 * 1. Insercao
 * ====================================================== */

/* Retorna 1 se inseriu, 0 se ja existia */
int inserir(No **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        return 1;
    }
    if (valor < (*raiz)->valor) {
        return inserir(&(*raiz)->esquerda, valor);
    } else if (valor > (*raiz)->valor) {
        return inserir(&(*raiz)->direita, valor);
    } else {
        return 0; /* valor duplicado */
    }
}

/* ======================================================
 * 2. Remocao
 * ====================================================== */

/* Encontra o menor no (mais a esquerda) de uma subarvore */
No *menorNo(No *no) {
    No *atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No *remover(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("Valor %d nao encontrado na arvore.\n", valor);
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        /* No encontrado - tres casos: */

        /* Caso 1: no folha (sem filhos) */
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        /* Caso 2: no com apenas um filho */
        else if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        /* Caso 3: no com dois filhos
           Substitui pelo sucessor em-ordem (menor da subarvore direita) */
        else {
            No *sucessor  = menorNo(raiz->direita);
            raiz->valor   = sucessor->valor;
            raiz->direita = remover(raiz->direita, sucessor->valor);
        }
    }
    return raiz;
}

/* ======================================================
 * 3. Travessias (busca em profundidade)
 * ====================================================== */

/* Pre-ordem: Raiz -> Esquerda -> Direita */
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

/* Em-ordem: Esquerda -> Raiz -> Direita (resultado ordenado) */
void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

/* Pos-ordem: Esquerda -> Direita -> Raiz */
void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

/* ======================================================
 * Libera toda a memoria da arvore
 * ====================================================== */
void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

/* ======================================================
 * Menu principal
 * ====================================================== */
void exibirMenu() {
    printf("\n+------------------------------+\n");
    printf("|   * * * MENU DE OPCOES * * * |\n");
    printf("+------------------------------+\n");
    printf("|  1 - Incluir no              |\n");
    printf("|  2 - Remover no              |\n");
    printf("|  3 - Buscar pre-ordem        |\n");
    printf("|  4 - Buscar em ordem         |\n");
    printf("|  5 - Buscar pos-ordem        |\n");
    printf("|  0 - Encerrar                |\n");
    printf("+------------------------------+\n");
    printf("Opcao: ");
}

int main() {
    No *raiz  = NULL;
    int opcao = -1;
    int valor = 0;

    printf("=========================================\n");
    printf("  Arvore Binaria de Busca - Renalf S/A   \n");
    printf("=========================================\n");

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (inserir(&raiz, valor)) {
                    printf("Valor %d inserido com sucesso!\n", valor);
                } else {
                    printf("Valor %d ja existe na arvore. Insercao ignorada.\n", valor);
                }
                break;

            case 2:
                if (raiz == NULL) {
                    printf("A arvore esta vazia. Nada a remover.\n");
                } else {
                    printf("Digite o valor a remover: ");
                    scanf("%d", &valor);
                    raiz = remover(raiz, valor);
                    printf("Operacao de remocao concluida.\n");
                }
                break;

            case 3:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    printf("Pre-ordem  (Raiz -> Esq -> Dir): ");
                    preOrdem(raiz);
                    printf("\n");
                }
                break;

            case 4:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    printf("Em-ordem   (Esq -> Raiz -> Dir): ");
                    emOrdem(raiz);
                    printf("\n");
                }
                break;

            case 5:
                if (raiz == NULL) {
                    printf("A arvore esta vazia.\n");
                } else {
                    printf("Pos-ordem  (Esq -> Dir -> Raiz): ");
                    posOrdem(raiz);
                    printf("\n");
                }
                break;

            case 0:
                printf("Encerrando o programa. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    liberarArvore(raiz);
    return 0;
}
