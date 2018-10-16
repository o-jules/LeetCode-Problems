# Parser

EBNF:
```
digit postive = "1" | ... | "9" ;
digit = "0" | digit postive;
letter = "a" | .... | "z";

number = digit postive, { digit } ;
count statement = number, '[', { string | count statement }, ']' ;

statement = string | count statment ;
```
