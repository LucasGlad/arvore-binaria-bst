# 🌳 Árvore Binária de Busca (BST)

Implementação de uma **Árvore Binária de Busca** (Binary Search Tree) em linguagem C, desenvolvida como trabalho acadêmico.

## 📋 Descrição

Uma Árvore Binária de Busca é uma estrutura de dados baseada em nós onde:
- Todos os nós da **subárvore esquerda** possuem valor **menor** que o nó raiz
- Todos os nós da **subárvore direita** possuem valor **maior** que o nó raiz

> Referência: FORBELLONE, A. L. V.; EBERSPACHER, H. F. *Lógica de Programação*. 2005.

## ⚙️ Funcionalidades

| Opção | Operação | Descrição |
|:-----:|----------|-----------|
| `1` | **Incluir nó** | Insere um valor na posição correta da árvore |
| `2` | **Remover nó** | Remove um valor tratando os 3 casos possíveis |
| `3` | **Buscar pré-ordem** | Raiz → Esquerda → Direita |
| `4` | **Buscar em ordem** | Esquerda → Raiz → Direita *(resultado ordenado)* |
| `5` | **Buscar pós-ordem** | Esquerda → Direita → Raiz |
| `0` | **Encerrar** | Libera a memória e encerra o programa |

## 🗂️ Estrutura do Projeto

```
arvore-binaria-bst/
└── arvore_binaria.c   # Código-fonte principal
```

## 🔧 Como Compilar e Executar

### Requisitos
- Compilador GCC instalado

### Compilar
```bash
gcc arvore_binaria.c -o arvore_binaria
```

### Executar
```bash
# Windows
.\arvore_binaria.exe

# Linux/Mac
./arvore_binaria
```

## 🖥️ Exemplo de Uso

```
=================================
  Arvore Binaria de Busca - 
=================================

+------------------------------+
|   * * * MENU DE OPCOES * * * |
+------------------------------+
|  1 - Incluir no              |
|  2 - Remover no              |
|  3 - Buscar pre-ordem        |
|  4 - Buscar em ordem         |
|  5 - Buscar pos-ordem        |
|  0 - Encerrar                |
+------------------------------+
Opcao: 1
Digite o valor a inserir: 50
Valor 50 inserido com sucesso!
```

Inserindo os valores `50, 30, 70, 20, 40, 60, 80`:

```
Pre-ordem  (Raiz -> Esq -> Dir): 50 30 20 40 70 60 80
Em-ordem   (Esq -> Raiz -> Dir): 20 30 40 50 60 70 80
Pos-ordem  (Esq -> Dir -> Raiz): 20 40 30 60 80 70 50
```

A árvore formada visualmente:

```
        50
       /  \
      30   70
     / \  / \
    20 40 60 80
```

## 🧠 Lógica de Remoção

A remoção trata **3 casos**:

1. **Nó folha** (sem filhos) → remove diretamente
2. **Um filho** → substitui o nó pelo filho sobrevivente
3. **Dois filhos** → substitui pelo **sucessor em-ordem** (menor nó da subárvore direita)

## 👨‍💻 Autor

Desenvolvido por **Lucas** — Trabalho Acadêmico de Estruturas de Dados
