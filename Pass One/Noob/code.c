#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");

    char label[10],opcode[10],operand[10];
    int start,locctr;

    //reads first line
    fscanf(input,"%s %s %s",label,opcode,operand);

    // writes into the file
    fprintf(output,"- %s %s %s\n",label,opcode,operand);

    // convert string to int(hexadecimal)
    start = (int)strtol(operand,NULL,16);
    //locctr keeps track of the location of each line
    locctr = start;

    //
    if(strcmp(opcode,"START")==0){
        while(strcmp(opcode,"END")!=0){
            fscanf(input,"%s %s %s",label,opcode,operand);
            fprintf(output,"%x %s %s %s\n",locctr,label,opcode,operand);

            // since every line is of three bytes for this file
            locctr+=3;

        }
    }

    fclose(input);
    fclose(output);
}
