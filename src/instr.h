#ifndef __INSTR_H
#define __INSTR_H

#define FOREACH_INSTR(F) \
    F(ADD) F(AND) F(LDA) F(STA) F(BUN) F(BSA) F(ISZ) F(CLA) \
    F(CLE) F(CMA) F(CME) F(CIR) F(CIL) F(INC) F(SPA) F(SNA) \
    F(SZA) F(SZE) F(HLT) F(INP) F(OUT) F(SKI) F(SKO) F(ION) \
    F(IOF) F(ORG) F(HEX) F(DEC) F(CHR)
    
#define __GEN_ENUM(instr) instr,

enum { 
    FOREACH_INSTR(__GEN_ENUM)
};

int get_instr_id(char *);

#endif