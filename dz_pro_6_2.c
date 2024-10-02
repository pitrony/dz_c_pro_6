//Урок 6. Списки и двоичные деревья
//Задание 2. Сумма всех элементов
//Напишите программу, которая возвращает сумму всех элементов в дереве.
#include <stdio.h>
#include <stdlib.h>
    
typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

int sum (Tree *node) {
    if (node == 0) return 0;
    return node->value + sum (node->left) + sum (node->right);
}
static Tree *addNode (Tree *parent, char leftRight, int value) {
   struct Tree *node = calloc(1, sizeof(Tree));
    node->value = value;
    node->left = 0;
    node->right = 0;
    if (parent != 0) {
        if (leftRight == 'L') {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
    return node;
}

int main (void) {
    Tree *root = 0;
    printf("%d\n", sum(root));
    root = addNode (0, ' ', 10);
    addNode (root,'L',5);
    addNode (root,'R',15);
    addNode (root->left,'L',3);
    addNode (root->left->left,'L',1);
    addNode (root->left,'R',7);
    addNode (root->left->right,'L',6);
    addNode (root->right,'L',13);
    addNode (root->right,'R',18);
    printf("%d\n", sum (root));
    return 0;
}
