#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define program_buffer_flip 65503
#define A 65500
#define B 65501
#define C 65502
#define HALT 65499
bool read(unsigned short address, unsigned short* memory){
unsigned short* x = memory + address/16;
if ((1 << (0xF^(address%16))) & *x){
return 1;
}
return 0;
}
void write(unsigned short address, unsigned short* memory, bool value){
unsigned short* x = memory + address/16;
if (value){
*x |= (value << (0XF-(address % 16)));}
else{
*x &= ~(~value << (0XF-(address % 16)));}
}
int main()
{
unsigned short* memory = malloc(8164);
unsigned short* program_counter = memory+4095;
unsigned short* program_counter_buffer = program_counter - 1;
unsigned short* program = memory;
*program = A;
*(program + 1) = B;
*(program + 2) = C;
*(program + 3) = A;
*(program + 4) = C;
*(program + 5) = HALT;
for (*program_counter = 0; read(HALT, memory) == 0; *program_counter += 2){
unsigned short address1 = *(memory + *program_counter);
unsigned short address2 = *(memory + *program_counter + 1);
write(C, memory, 1^(read(A, memory) & read(B, memory)));
write(address2, memory ,read(address1, memory));
if (read(program_buffer_flip, memory)){*program_counter = *program_counter_buffer; write(program_buffer_flip, memory, 0);}}
printf("A %d, B %d, C %d, HALT %d, program counter %b, program counter buffer %b\n", read(A,memory), read(B,memory), read(C,memory), read(HALT,memory), *program_counter, *program_counter_buffer);
return 0; 
}