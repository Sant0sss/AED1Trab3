#include <stdio.h>
#include <stdbool.h>

// Definindo a estrutura para um nó da árvore binária
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para verificar se dois nós são primos (cousins) na árvore binária
bool isCousins(struct TreeNode* root, int x, int y) {
    // Inicializando variáveis para guardar informações sobre os nós x e y
    int x_depth = -1, y_depth = -1; 
    struct TreeNode* x_parent = NULL;
    struct TreeNode* y_parent = NULL;
    int depth = 0;
    struct TreeNode* current = root;
    
    // Percorrendo a árvore para encontrar os nós x e y e suas profundidades e pais
    while (current != NULL) {
        if (current->left != NULL && (current->left->val == x || current->left->val == y)) {
            x_depth = depth + 1;
            x_parent = current;
        }
        if (current->right != NULL && (current->right->val == x || current->right->val == y)) {
            y_depth = depth + 1;
            y_parent = current;
        }
        
        // Se ambos os nós forem encontrados, podemos parar a busca
        if (x_depth != -1 && y_depth != -1) {
            break;
        }
        
        depth++;
        
        // Movendo para o próximo nó na mesma profundidade
        if (current->left != NULL && (current->left->val == x || current->left->val == y)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // Verificando se os nós x e y são primos (cousins)
    return x_depth == y_depth && x_parent != y_parent;
}

int main() {
    // Criando a árvore binária de exemplo: [1,2,3,4]
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node4 = {4, NULL, NULL};

    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;

    int x = 4;
    int y = 5;

    // Chamando a função isCousins para testar se os nós x e y são primos
    bool result = isCousins(&node1, x, y);

    // Exibindo o resultado do teste
    if (result) {
        printf("Os nos %d e %d sao primos na arvore.\n", x, y);
    } else {
        printf("Os nos %d e %d nao sao primos na arvore.\n", x, y);
    }

    return 0;
}
