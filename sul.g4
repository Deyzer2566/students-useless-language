grammar sul;

@header {
/*
 * Студенческий бесполезный язык 2025
 * Student's useless language 2025
 */
}

program
    : block EOF;

block
    : '{' (stmt '.')* '}'
    | stmt '.'?
    ;

stmt
    : if
    | expr
    | loop
    | print
    ;
    

expr
    : '(' expr ')'          # parenthesis
    | '(' type ')' expr     # cast
    | expr operation=('*' | '/') expr   # mul_div
    | expr operation=('+' | '-') expr   # sum_sub
    | '-' expr              # negation
    | '!' expr              # logical_inversion
    | expr operation=('=='|'>'|'<') expr# compare
    | IDENT                 # ident
    | INTEGER               # integer_val
    | REAL                  # real_val
    | STRING                # string_val
    | assignment123         # assignment
    ;

assignment123: IDENT '=' expr ;

if: 'дабы' expr block ('иначе' block)? ;

IDENT: [a-zA-Z_а-яА-ЯЁё] [a-zA-Z_0-9а-яА-ЯЁё]* ;

INTEGER : [0-9]+ ;

REAL: INTEGER ',' INTEGER ;

STRING : '"' .*? '"' ;

SPACE: [ \t\n\r]+ -> channel(HIDDEN);

type
    : 'int'     # int
    | 'real'    # real
    | 'str'     # str
    ;

loop
    : while
    ;

while: 'доколе' expr block ;

print: 'воспевай' expr ;

MULTI_LINE_COMMENT: '/*' .*? '*/' -> channel(HIDDEN) ;

SINGLE_LINE_COMMENT: '//' .*? '\n' -> channel(HIDDEN);
