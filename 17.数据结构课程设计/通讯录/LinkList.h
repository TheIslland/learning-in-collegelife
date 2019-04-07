/*************************************************************************
	> File Name: LinkList.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月25日 星期二 22时39分13秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H


class Link {
public:
typedef struct H_Node {
    char *name;
    char *num;
    struct H_Node *next;
    }H_Node;
typedef struct Hashtable {
    H_Node **data;
    int size;
} Hashtable;
private:
    Hashtable *h;
public:
    H_Node *init_H_Node (char *str, char *num, H_Node *head);
    Link(int n) ;
    int Hashtable_insert (char *name, char *num);
    int Hashtable_find (char *name);
    int Hashtable_put (char *name);
    int Hashtable_del (char *name);
    //void clear_hashtable();
};

Link::H_Node * Link::init_H_Node (char *str, char *num, Link::H_Node *head) {
    Link::H_Node *node = (H_Node *)malloc(sizeof(H_Node));
    node->name = strdup(str);
    node->num = strdup(num);
    node->next = head;
    return node;
}

Link::Link (int n) {
    h = (Hashtable *)malloc(sizeof(Hashtable));
    h->size = n << 1;
    h->data = (H_Node **)calloc(sizeof(H_Node *), h->size);
}

unsigned int APHash(char *str) {
    unsigned int hash = 0;
    int i;  
    for(i = 0; *str; i++) {
        if((i & 1) == 0) {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }      
    return hash;
}

int Link::Hashtable_insert (char *name, char *num) {
    unsigned int hash = APHash(name);
    unsigned int ind = hash % h->size;
    Link::H_Node *p = h->data[ind];
    while (p && strcmp(p->name, name)) p = p->next;
    if (p == NULL) {
        h->data[ind] = init_H_Node(name, num, h->data[ind]);
        return 1;
    } else {
        return 0;
    }
}

int Link::Hashtable_find (char *name) {
    unsigned int hash = APHash(name);
    unsigned int ind = hash % h->size;
    Link::H_Node *p = h->data[ind];
    while (p && strcmp(p->name, name)) p = p->next;
    if (p == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int Link::Hashtable_put (char *name) {
    unsigned int hash = APHash(name);
    unsigned int ind = hash % h->size;
    Link::H_Node *p = h->data[ind];
    while (p && strcmp(p->name, name)) p = p->next;
    if (p == NULL) {
        return 1;
    } else {
        printf("%s电话为%s\n", name, p->num);
        return 0;
    }
}

int Link::Hashtable_del (char *name) {
    unsigned int hash = APHash(name);
    unsigned int ind = hash % h->size;
    Link::H_Node *p = h->data[ind];
    while (p && strcmp(p->name, name)) p = p->next;
    if (p == NULL) {
        return 1;
    } else {
        p->name = "00000";
        return 0;
    }
}
/*
void clear_node(H_Node *node) {
    if (!node) return ;
    H_Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->name);
        free(p->num);
        free(p);
        p = q;
    }
    return ;
}

void Link::clear_hashtable() {
    if (!h) return ;
    for (int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}*/

#endif
