grammar ExprCppTree;

options {
    language = C;
    output = AST;
    ASTLabelType=pANTLR3_BASE_TREE;
}

@header {
    #include <assert.h>
}

// The suffix '^' means make it a root.
// The suffix '!' means ignore it.

PLUS: '+';
MINUS: '-';
COMMA: ',';
ASSIGN: '=';
ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;
NEWLINE: '\r'? '\n' ;
WS : (' '|'\t')+ {$channel = HIDDEN;}; 

dot: expr ((COMMA^) expr)*
    ;

expr: multExpr ((PLUS^ | MINUS^) multExpr)*
    ;


multExpr
    : atom (TIMES^ atom)*
    ;

TIMES: '*';

atom: INT
    | ID
    | '('! dot ')'!
    ;

//stmt = statement语句解析规则
stmt: dot NEWLINE -> dot  // tree rewrite syntax
    | ID ASSIGN dot NEWLINE -> ^(ASSIGN ID dot) // tree notation
    | NEWLINE ->   // ignore
    ;


prog
    : (stmt {pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
             assert(s->chars);
             printf(" tree \%s\n", s->chars);
            }
        )+
    ;

