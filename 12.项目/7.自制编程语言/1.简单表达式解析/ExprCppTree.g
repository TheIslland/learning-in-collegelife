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
/*
OR : '||';  
AND : '&&';  
EQ : '==';  
NEQ : '!=';  
GT : '>';  
LT : '<';  
GTEQ : '>=';  
LTEQ : '<=';  
PLUS : '+';  
MINUS : '-';  
MULT : '*';  
DIV : '/';  
MOD : '%';  
POW : '^';  
NOT : '!';  
  
SCOL : ';';  
ASSIGN : '=';  
OPAR : '(';  
CPAR : ')';  
OBRACE : '{';  
CBRACE : '}';  
  
TRUE : 'true';  
FALSE : 'false';  
NIL : 'nil';  
IF : 'if';  
ELSE : 'else';  
WHILE : 'while';  
LOG : 'log';  
*/

ID: ('a'..'z'|'A'..'Z')+ ;
INT: '~'? '0'..'9'+ ;
NEWLINE: '\r'? '\n' ;
WS : (' '|'\t')+ {$channel = HIDDEN;}; 
COMMA: ',';
ASSIGN: '=';
PLUS: '+';
MINUS: '-';
TIMES: '*';
DIV: '/';
BLOCK: '.';

expr: assignExpr ((COMMA^) assignExpr)* 
    ;
    
assignExpr: addexpr
    | ID ASSIGN addexpr -> ^(ASSIGN ID addexpr)
    ;

addexpr: multExpr ((PLUS^ | MINUS^) multExpr)*
    ;

multExpr: atom ((TIMES^ | DIV^) atom)*
    ;

atom: INT
    | ID
    | '('! expr ')'!
    ;

//stmt = statement语句解析规则

stmt: expr NEWLINE -> expr  // tree rewrite syntax
    | NEWLINE ->   // ignore
    | block
    ;

block: '{' block_body '}' NEWLINE -> ^(BLOCK block_body)
    ;

block_body: (stmt)*
    ;

prog
    : (stmt {pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
             assert(s->chars);
             printf(" tree is :\%s\n", s->chars);
            }
        )+
    ;
