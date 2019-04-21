// 4.4
// Doubly Linked List
// malloc
// アロー演算子

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
    int key;
    Node *prev, *next;
};

Node *nil;

Node *listSearch(int key)
{
    Node *cur = nil->next;
    while (cur != nil && cur->key != key)
    {
        cur = cur->next;
    };
    return cur;
}

void init()
{
    // mallocで動的確保
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void printList()
{
    Node *cur = nil->next;
    int isf = 0;
    while (1)
    {
        if (cur == nil)
            break;
        if (isf++ > 0)
            printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node *t)
{
    if (t == nil)
        return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    // メモリの解放
    free(t);
}

void deleteFirst()
{
    // nilで最初に初期化したのが活きる
    deleteNode(nil->next);
}

void deleteLast()
{
    // nilで最初に初期化したのが活きる
    deleteNode(nil->prev);
}

void deleteKey(int key)
{
    deleteNode(listSearch(key));
}

void insert(int key)
{
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    x->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main()
{
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;

    scanf("%d", &n);
    init();

    for (i = 0; i < n; i++)
    {
        // コマンドとデータ(key)の読み取り
        scanf("%s %d", com, &key);
        if (com[0] == 'i')
        {
            insert(key);
            np++;
            size++;
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                    deleteFirst();
                else if (com[6] == 'L')
                    deleteLast();
            }
            else
            {
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }

    printList();

    return 0;
}