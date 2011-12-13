manoasm: ./src/asm.c ./src/codegen.c ./src/instr.c ./src/symtab.c
	gcc ./src/asm.c ./src/codegen.c ./src/instr.c ./src/symtab.c -o manoasm
