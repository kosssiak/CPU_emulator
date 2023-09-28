#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <assert.h>

#define SIGN "AS"

#define STR_EQ(str1, str2)   (strcmp (str1, str2) == 0) 

#define ASSERT_OKAY(smth, code)    if (smth) code                                     

enum TYPEOFREGISTER {
    #define DEF_REG_(name, number) R_##name = number,

    #include "../lib/regs_def.h"

    #undef DEF_REG_
};

enum COMMANDS_NUMBERS {
    
    #define DEF_CMD_(name, numbOfCmd, argNumber, code)  CMD_##name = numbOfCmd,                                           \

    #include "../lib/commands_def.h"

    #undef DEF_CMD_
};

enum TYPEOFWRITE {
    NTHG,
    IMM,
    REG,
    MEM,
    MEMREG,
    MEMREGIMM
};

enum ERRORS {
    UNKNOWN_COMMAND = -10,
    UNKNOWN_REGISTER = -9,
    INCORRECT_INPUT = -8,
    OK = -7,
    ZERO_DIV = -6,
    WRONG_ADDRESS = -5,
    FIRST,
    SECOND,
    NULLPTR,
    UNABLETOREADFROMFILE,
    UNABLETOWRITETOFILE,
    WRONGFILETYPE,
    UNABLETOOPENFILE
};

int GetFileSize (FILE *asmProgram);

void PrintErrors (const int typeOfError);

#endif