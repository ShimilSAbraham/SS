#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    FILE *symtab = fopen("symtab.txt","w");

    char label[10],opcode[10],operand[10];
    int start,locctr;

    //reads first line
    fscanf(input,"%s %s %s",label,opcode,operand);

    if(strcmp(opcode,"START")==0){
    // writes into the file
    fprintf(output,"- %s %s %s\n",label,opcode,operand);
    // convert string to int(hexadecimal)
    start = (int)strtol(operand,NULL,16);
    //locctr keeps track of the location of each line
    locctr = start;
    }

    // works till the file reaches END line 
    while(strcmp(opcode,"END")!=0){
        fscanf(input,"%s %s %s",label,opcode,operand);
        fprintf(output,"%x %s %s %s\n",locctr,label,opcode,operand);

        //checking if there is a label
        if(strcmp("-",label)!=0){
            //store it into symtab
            fprintf(symtab,"%s\t%x\n",label,locctr);
        }

        //incrementing the location counter based on the assembler directives
        if(strcmp(opcode,"RESW")==0)
            locctr+=(3*(int)strtol(operand,NULL,16));
        else if(strcmp(opcode,"RESB")==0)
            locctr+=(int)strtol(operand,NULL,16);
        else if(strcmp(opcode,"BYTE")==0)
            locctr+=strlen(operand);
        else
            locctr+=3;

    }

    fclose(input);
    fclose(output);
    fclose(symtab);
}

//for byte declaration c'String' format won't work. It will give errors. So just type the string in the input file.
