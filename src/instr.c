#include "instr.h"

#define GEN_INSTRCHK(a) \
    if(!strcmp(instr, #a)) \
        return a;

int
get_instr_id(char *instr)
{
    /* Magic! - See instr.h */
    FOREACH_INSTR(GEN_INSTRCHK);
}