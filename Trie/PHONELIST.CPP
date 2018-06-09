#include <stdio.h>
#define MAX_CHILD 10
#define MAX_WORD 255

struct node {
    struct node * parent;
    struct node * child[MAX_CHILD];
    int occur = 0;
};

node * addNode(node * parent) {
    node * temp = new node();
    temp->parent = parent;
    for (int i = 0; i < MAX_CHILD; i++) {
        temp->child[i] = NULL;
    }
    temp->occur = 0;
    return temp;
}

bool insertWord(node * trie, char word[]) {
    node * temp = trie;
    for (int i = 0; word[i] != '\0'; i++) {
        if (temp->occur != 0) {
            return false;
        }
        if (temp->child[word[i] - '0'] == NULL) {
            temp->child[word[i] - '0'] = addNode(temp);
        }
        temp = temp->child[word[i] - '0'];
    }
    temp->occur++;
    for (int i = 0; i < MAX_CHILD; i++) {
        if (temp->child[i] != NULL) {
            return false;
        }
    }
    return true;
}

int main() {
    int testcase, n;
    scanf("%d", &testcase);
    while (testcase-- > 0) {
        char word[MAX_WORD];
        scanf("%d", &n);
        node * trie = addNode(NULL);
        bool result = true;
        for (int i = 0; i < n; i++) {
            scanf("%s", &word);
            if (!insertWord(trie, word))
                result = false;
        }
        if (result)
            printf("YES\n");
        else
            printf("NO\n");
    }

}
