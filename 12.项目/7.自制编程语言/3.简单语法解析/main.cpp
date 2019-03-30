#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
/*
class ExprTreeEvaluator {
    map<string,int> memory;
public:
    ExprTreeEvaluator(ExprTreeEvaluator *next) {
        this->next = next;
    }
    int find(string var) {
        if (this->memory.find(var) != this->memory.end()) {
            return this->memory[var];
        }
        if (this->next) return this->next->find(var);
        return 0;
    }
    int run(pANTLR3_BASE_TREE);
    ExprTreeEvaluator *next;
};
*/
class ExprTreeEvaluator {
public:
    ExprTreeEvaluator() : next(nullptr) {}
    ExprTreeEvaluator(ExprTreeEvaluator *next) {
        this->next = next;
    }
    int find(string var) {
        if (this->memory.find(var) != this->memory.end()) {
            return this->memory[var];
        }
        if (this->next) return this->next->find(var);
        return 0;
    }
    int run(pANTLR3_BASE_TREE);
    int getVal(string name);
    int setVal(string name, int val);
private:
    map<string,int> memory;
    ExprTreeEvaluator *next;
};


pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);

int main(int argc, char* argv[])
{
  pANTLR3_INPUT_STREAM input;
  pExprCppTreeLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  pExprCppTreeParser parser;

  assert(argc > 1);
  input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);
  lex = ExprCppTreeLexerNew(input);

  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
                                            TOKENSOURCE(lex));
  parser = ExprCppTreeParserNew(tokens);

    printf("get parser done!\n");
    fflush(stdout);

  ExprCppTreeParser_prog_return r = parser->prog(parser);
   
    printf("parser tree is done!\n");
    fflush(stdout);

  pANTLR3_BASE_TREE tree = r.tree;

  ExprTreeEvaluator eval(NULL);
  int rr = eval.run(tree);
  //cout << "Evaluator result: " << rr << '\n';

  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  input->close(input);

  return 0;
}

int ExprTreeEvaluator::getVal(string name) {
    printf("get memory : %s\n", name.c_str());
    ExprTreeEvaluator *p = this;
    while (p != nullptr) {
        if (p->memory.find(name) != p->memory.end()) {
            return p->memory[name];
        }
        p = p->next;
    }
    return -1;
}

int ExprTreeEvaluator::setVal(string name, int val) {
    printf("set %s = %d\n", name.c_str(), val);
    this->memory[name] = val;
    return 1;
}

int ExprTreeEvaluator::run(pANTLR3_BASE_TREE tree)
{
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);
    if(tok) {
        // 处理树
        switch(tok->type) {
            case DEF: {
                int k = tree->getChildCount(tree);
                for (int i = 0; i < k; i++) {
                    string var(getText(getChild(tree, i)));
                    this->setVal(var, 0);
                }
                return 0;
            }
            case BLOCK: {
                ExprTreeEvaluator new_obj(this);
                int k = tree->getChildCount(tree);
                int r = 0;
                for(int i = 0; i < k; i++) {
                    r = new_obj.run(getChild(tree, i));
                }
                printf("This Block result: %d\n", r);
                return r;
            }
            case IF: {
                int k = tree->getChildCount(tree);
                int judg = run(getChild(tree, 0));
                if (judg != 0) {
                    return run(getChild(tree, 1));
                } else {
                    if (k <= 2) {
                        return 0;
                    } else {
                        return run(getChild(tree, 2));
                    }
                }
            }
            case FOR: {
                run(getChild(tree, 0));
                int judg = run(getChild(tree, 1));
                int ans;
                while (judg) {
                    ans = run(getChild(tree, 3));
                    run(getChild(tree, 2));
                    judg = run(getChild(tree, 1));
                }
                return ans;
            }
            case INT: {
                const char* s = getText(tree);
                if(s[0] == '-') {
                    return -atoi(s+1);
                }
                else {
                    return atoi(s);
                }
            }
            case ID: {
                string var(getText(tree));
                return this->getVal(var);
            }
            case DOT: {
                int left = run(getChild(tree,0));
                int right = run(getChild(tree,1));
                return right;
            }
            case PLUS:
                return run(getChild(tree,0)) + run(getChild(tree,1));
            case MINUS:
                return run(getChild(tree,0)) - run(getChild(tree,1));
            case TIMES:
                return run(getChild(tree,0)) * run(getChild(tree,1));
            case DIV:
                return run(getChild(tree,0)) / run(getChild(tree,1));
            case MOD:
                return run(getChild(tree,0)) % run(getChild(tree,1));
            case ASSIGN: {
                string var(getText(getChild(tree,0)));
                int val = run(getChild(tree,1));
                memory[var] = val;
                this->setVal(var, val);
                return val;
            }
            case AND:
                return run(getChild(tree,0)) && run(getChild(tree,1));
            case OR:
                return run(getChild(tree,0)) || run(getChild(tree,1));
            case GT:
                return run(getChild(tree,0)) > run(getChild(tree,1));
            case LITTLE:
                return run(getChild(tree,0)) < run(getChild(tree,1));
            case GE:
                return run(getChild(tree,0)) >= run(getChild(tree,1));
            case LE:
                return run(getChild(tree,0)) <= run(getChild(tree,1));
            case EQ:
                return run(getChild(tree,0)) == run(getChild(tree,1));
            case NE:
                return run(getChild(tree,0)) != run(getChild(tree,1));
            default:
                cout << "Unhandled token: #" << tok->type << '\n';
                return -1;
        }
    }
    else {
        // 处理森林
        int k = tree->getChildCount(tree);
        int r = 0;
        for(int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
        }
        return r;
    }
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i)
{
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree)
{
    return (const char*) tree->getText(tree)->chars;
}
