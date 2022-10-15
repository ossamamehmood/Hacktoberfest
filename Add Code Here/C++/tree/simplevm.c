// simple fetch-decode-execute 16 bit virtual machine
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    HALT,
    ADD,
    SUB,
    MUL,
    DIV,
    RETR,
    RETI,
    STR
} OpCode;

typedef enum {
    R0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    PC,
    RCOUNT
} Regs;

//Program memory 16 bits and holds a maximum of 65535 instructions
static uint16_t memory[UINT16_MAX]={0x70c8,0x71c8,0x1001,0x5000,0x0000};
//store value of 200 in register R0(0x70c8) and R1(0x71c8) then add them and store result in register R0(0x1001) then print value of R0(0x5000) and halt(0x0000)

static uint16_t regs[RCOUNT];
//instruction parameters
static uint16_t opcode,reg_1,reg_2,reg_3,imm;

uint16_t fetch() {
    return memory[(regs[PC]++)];
}

void decode(uint16_t instr) {
    opcode=(instr&0xf000)>>12;
    reg_1=(instr&0xf00)>>8;
    reg_2=(instr&0xf0)>>4;
    reg_3=(instr&0xf);
    //Imm(immediate) is an 8 bit unsigned integer
    imm=(instr&0xff);
}

void execute() {
    int running=1;
    while(running) {
        uint16_t instr=fetch();
        decode(instr);
        switch(opcode) {
            case 0x0: //HALT
                running=0;
                break;
            case 0x1: //ADD
                //adds values of reg_2 and reg_3 and stores in reg_1
                regs[reg_1]=regs[reg_2]+regs[reg_3];
                break;
            case 0x2: //SUB
                //subtract value of reg_3 from reg_2 and stores in reg_1
                regs[reg_1]=regs[reg_2]-regs[reg_3];
                break;
            case 0x3: //DIV
                //divide value of reg_3 from reg_2 and stores in reg_1
                regs[reg_1]=regs[reg_2]/regs[reg_3];
                break;
            case 0x4: //MUL
                //multiply values of reg_2 and reg_3 and stores in reg_1
                regs[reg_1]=regs[reg_2]*regs[reg_3];
                break;
            case 0x5: //RETR
            //prints value of reg_1
                printf("%d\n",regs[reg_1]);
                break;
            case 0x6: //RETI
            //prints value of immediate
                printf("%d\n",imm);
            case 0x7: //STR
            //store immediate in reg_1
                regs[reg_1]=imm;
                break;
        }
    }
}

// Program does not get any commandline arguments
int main(void) {
    execute();
}
