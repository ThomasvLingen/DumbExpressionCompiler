## DumbExpressionCompiler (dexc)
My attempt at making a simple expression compiler, in order to get the hang of
lexing, building an AST and (x86) code generation.

DumbExpressionCompiler supports the following operators with proper operator
precedence:
* +
* -
* *
* /

The result of the expression is always unsigned. We don't do decimals.

### Usage
This compiler generates x86 assembly. Usage of `dexc` is as follows:
```
dexc EXPRESSION
``` 

The generated x86 assembly stored in the `out.asm` file can be assembled into
an actual program on x86_64 machines with `gcc`:
```
gcc -m32 -x assembler -nostdlib out.asm -o out
```

When run, this program returns the result of the expression. The result can be
checked in `bash` like this:
```
./out
echo $?
```

