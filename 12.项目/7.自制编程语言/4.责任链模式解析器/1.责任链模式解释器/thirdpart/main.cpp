#include "hlLexer.h"
#include "hlParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::endl;
using std::map;
using std::string;
using std::cout;
using std::runtime_error;

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE );

class Paramters {
public :
    Paramters(Paramters *father) : father(father) {}
    int getVal(string name) {
        if (memory.find(name) == memory.end()) {
            if (father == nullptr) throw runtime_error("unknown paramters!");
            return father->getVal(name);
        }
        return memory[name];
    }
    int setVal(string name, int val) {
        if (memory.find(name) == memory.end()) {
            if (father == nullptr) throw runtime_error("unknown paramters!");
            return father->setVal(name, val);
        }
        return (memory[name] = val);
    }
    int setVal(string name) {
        return (memory[name] = 0);
    }

private:
    map<string, int> memory;
    Paramters *father;
};

class IMaster {
public :
    virtual bool Test(pANTLR3_BASE_TREE ) = 0;
    virtual int run(pANTLR3_BASE_TREE, Paramters *) = 0;
    static int MasterRun(pANTLR3_BASE_TREE, Paramters *);

    friend IMaster *getMasterLink();
private:
    IMaster *next;
    static IMaster *head;
};

class RelationMaster : public IMaster {
public:
    bool Test(pANTLR3_BASE_TREE tree) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        if(tok) {
            switch(tok->type) {
                case AND:
                case OR:
                case GT: 
                case LITTLE: 
                case GE:
                case LE:
                case EQ:
                case NE: return true;
            }
        }
        return false;
    }
    int run(pANTLR3_BASE_TREE tree, Paramters *param) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        switch (tok->type) {
            case AND: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a && b;
            }
            case OR: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a || b;
            }
            case GT: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a > b;
            }
            case LITTLE: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a < b;
            }
            case GE: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a >= b;
            }
            case LE: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a <= b;
            }
            case EQ: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a == b;
            }
            case NE: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a != b;
            }
            default : {
                cout << tok->type << endl;
                throw runtime_error("unknown token type!");
            }
        }
        return -1;
    } 

};

class BinaryMaster : public IMaster {
public :
    bool Test(pANTLR3_BASE_TREE tree) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        if(tok) {
            switch(tok->type) {
                case PLUS:
                case MINUS:
                case MOD:
                case ASSIGN: 
                case TIMES: return true;
            }
        }
        return false;
    }
    int run(pANTLR3_BASE_TREE tree, Paramters *param) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        switch (tok->type) { 
            case PLUS: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a + b;
            }
            case MINUS: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a - b;
            }
            case MOD: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a % b;
            }
            case TIMES: {
                int a = IMaster::MasterRun(getChild(tree, 0), param);
                int b = IMaster::MasterRun(getChild(tree, 1), param);
                return a * b;
            }
            case ASSIGN: {
                string var(getText(getChild(tree,0)));
                int val = IMaster::MasterRun(getChild(tree, 1), param);
                param->setVal(var, val);
                return val;
            }
            default : throw runtime_error("unknown token type!");
        }
        return -1;
    }
};

class ProgramMaster : public IMaster {
public:
    bool Test(pANTLR3_BASE_TREE tree) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        if(tok) {
            switch(tok->type) {
                case BLOCK:
                case DEF:
                case IF:
                case FOR:
                case WHILE:
                case DOWHILE:
                case PRINT: return true;
            }
        }
        return false;
    }
    int run(pANTLR3_BASE_TREE tree, Paramters *param) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        switch (tok->type) { 
            case BLOCK: {
                Paramters new_param(param);
                int k = tree->getChildCount(tree);
                int r = 0;
                for (int i = 0; i < k; i++) {
                    r = IMaster::MasterRun(getChild(tree, i), &new_param);
                }
                return r;
            }
            case IF: {
                int k = tree->getChildCount(tree);
                int cond_value = IMaster::MasterRun(getChild(tree, 0), param);
                if (cond_value) {
                    Paramters new_param(param);
                    return IMaster::MasterRun(getChild(tree, 1), &new_param);
                } else {
                    if (k <= 2) {
                        return 0;
                    } else {
                        Paramters new_param(param);
                        return IMaster::MasterRun(getChild(tree, 2), &new_param);
                    }
                }
            }
            case FOR: {
                Paramters new_param(param);
                IMaster::MasterRun(getChild(tree, 0), &new_param);
                int judg = IMaster::MasterRun(getChild(tree, 1), &new_param);
                int ans;
                while (judg) {
                    ans = IMaster::MasterRun(getChild(tree, 3), &new_param);
                    IMaster::MasterRun(getChild(tree, 2), &new_param);
                    judg = IMaster::MasterRun(getChild(tree, 1), &new_param);
                }
                return ans;
            }
            case WHILE: {
                
            }
            case DEF: {
                int k = tree->getChildCount(tree);
                for (int i = 0; i < k; i++) {
                    string var(getText(getChild(tree, i)));
                    param->setVal(var);
                    pANTLR3_BASE_TREE p = getChild(tree, i);
                    int cnt = p->getChildCount(p);
                    if (cnt != 0) {
                        int temp = IMaster::MasterRun(getChild(p, 0), param);
                        param->setVal(var, temp);
                    }
                }
                return 0;
            }
            case PRINT: {
                int k = tree->getChildCount(tree);
                int r = 0;
                for (int i = 0; i < k; i++) {
                    cout << IMaster::MasterRun(getChild(tree, i), param) << " ";
                }
                cout << endl;
                return 0;
            }
            default : throw runtime_error("unknown token type!");
        }
       return 0; 
    }
};

class ValueMaster : public IMaster {
public :
    bool Test(pANTLR3_BASE_TREE tree) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        if(tok) {
            switch(tok->type) {
                case INT:
                case ID: return true;
            }
        }
        return false;
    }
    int run(pANTLR3_BASE_TREE tree, Paramters *param) {
        pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
        switch (tok->type) { 
            case INT: {
                const char* s = getText(tree);
                if(s[0] == '~') {
                    return -atoi(s+1);
                }
                else {
                    return atoi(s);
                }
            }
            case ID: {
                string var(getText(tree));
                return param->getVal(var);
            }
            default : throw runtime_error("unknown token type!");
        }
        return 0;
    }
};


IMaster *IMaster::head = nullptr;

IMaster *getMasterLink() {
    if (IMaster::head == nullptr) {
        IMaster::head = new BinaryMaster();
        IMaster::head->next = new ProgramMaster();
        IMaster::head->next->next = new RelationMaster();
        IMaster::head->next->next->next = new ValueMaster();
    }
    return IMaster::head;
}

int IMaster::MasterRun(pANTLR3_BASE_TREE tree, Paramters *param) {
    IMaster *p = getMasterLink();
    while (p && p->Test(tree) == false) {
        p = p->next;
    }
    if (p == nullptr) throw runtime_error("No Master Handle!");
    return p->run(tree, param);
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);

int main(int argc, char* argv[]) {
    pANTLR3_INPUT_STREAM input;
    phlLexer lex;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    phlParser parser;

    assert(argc > 1);
    input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
    lex = hlLexerNew(input);
    
    tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    parser = hlParserNew(tokens);
    printf("get parser done!\n");
    fflush(stdout);
    hlParser_prog_return r = parser->prog(parser);
    printf("parser tree is done!\n");
    fflush(stdout);
    pANTLR3_BASE_TREE tree = r.tree;
    
    Paramters param(nullptr);
    int rr = IMaster::MasterRun(tree, &param);
    cout << "Evaluator result:" << rr << '\n' ;
    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);
    
    return 0;
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i) {
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree) {
    return (const char*) tree->getText(tree)->chars;
}
