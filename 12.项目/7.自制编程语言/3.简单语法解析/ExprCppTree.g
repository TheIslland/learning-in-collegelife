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
defid_expr
    : DEF! defid (','! defid)* 
    ;
defid
    : ID^ (ASSIGN! expr)?
    ;
*/

expr: assignExpr (DOT^ assignExpr)*
    ;

assignExpr: addexpr
    | ID ASSIGN addexpr -> ^(ASSIGN ID addexpr)
	;

addexpr: multExpr ((PLUS^ | MINUS^) multExpr)*
    ;

multExpr: atom ((TIMES^ | DIV^ | MOD^) atom)*
    ;

atom: INT
    | ID
    | '('! expr ')'!
    ;

if_expr: IF^ '('! condition_expr ')'! stmt ( (ELSE) => ELSE! stmt )?
    ;

for_expr: FOR^ '('! assignExpr ';'! condition_expr ';'! assignExpr ')'! stmt
    ;
/*
for_expr: FOR^ '('! init_expr ';'! condition_expr ';'! for_do_expr ')'! stmt
    ;
*/
/*
init_expr: ID ASSIGN expr -> ^(ASSIGN ID expr)
    ;

for_do_expr: ID ASSIGN expr -> ^(ASSIGN ID expr)
    ;
*/

defid: DEF! ID (','! ID)* ';'!
    ;

condition_expr: andExpr (OR^ andExpr)*
    ;
andExpr: cmp_atom (AND^ cmp_atom)*
    ;
cmp_atom: cond_atom ((GT^ | LITTLE^ | EQ^ | GE^ | LE^ | NE^) cond_atom)?
    ;
cond_atom: expr
    ;

block: '{'! (stmt)* '}'!
    ;

stmt: expr ';' -> expr  // tree rewrite syntax
    | defid ';' -> ^(DEF defid)
    | ';' -> 
    | block -> ^(BLOCK block)
    | if_expr
    | for_expr
    ;

prog: (stmt {
            pANTLR3_STRING s = $stmt.tree->toStringTree($stmt.tree);
            assert(s->chars);
            printf("tree \%s\n", s->chars);
        })+
    ;

DOT: ',';
MOD: '%';
DIV: '/';
DO: 'do';
DOWHILE: 'dowhile';
WHILE: 'while';
FOR: 'for';
PRINT: 'print';
IF: 'if';
ELSE: 'else';
OR: '||';
AND: '&&';
GE: '>=' | '=>';
NE: '!=';
LITTLE: '<';
LE: '<=' | '=<';
GT: '>';
EQ: '==';
PLUS: '+';
MINUS: '-';
TIMES: '*';
ASSIGN: '=';
BLOCK: '{}';
DEF: 'def';

INT :	'-'? '0'..'9' + 
    ;
ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    ;

FLOAT
    :   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
    |   '.' ('0'..'9')+ EXPONENT?
    |   ('0'..'9')+ EXPONENT
    ;

COMMENT
    :   '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    |   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

STRING
    :  '"' ( ESC_SEQ | ~('\\'|'"') )* '"'
    ;

fragment
EXPONENT : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
ESC_SEQ
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UNICODE_ESC
    |   OCTAL_ESC
    ;

fragment
OCTAL_ESC
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UNICODE_ESC
    :   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;
