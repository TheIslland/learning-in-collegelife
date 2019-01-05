/*************************************************************************
	> File Name: LeetCode_14_最长公共前缀.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 18时31分32秒
 ************************************************************************/
#define BASE 'a'
typedef struct Trie {
    int flag;
    struct Trie **childs;
}TrieNode, *Trie;

Trie new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode*) * 26);
    for (int i = 0; i < 26; i++) {
        p->childs[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int insert (Trie trie, char *pattern) {
    int cnt = 0;
    TrieNode *p = trie;
    for (int i = 0; i < strlen(pattern); i++) {
        if (p->childs[pattern[i] - BASE] == NULL) {
            p->childs[pattern[i] - BASE] = new_node();
        } else {
            cnt++;
        }
        p = p->childs[pattern[i] - BASE];
    }
    p->flag = 1;
    return cnt;
}

char* longestCommonPrefix(char** strs, int strsSize) {       
    TrieNode *trie = new_node();
    int len = 100000;
    insert(trie, strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int temp = insert(trie, strs[i]);
        if (temp < len) len = temp;
    }
    printf("%d\n", len);
    char *ans = (char *)malloc(sizeof(char) * (len + 1));
    ans[len] = '\0';
    strncpy(ans, strs[0], len);
    return ans;
}
