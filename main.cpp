#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){

    if(argc != 3){
        printf("Usage: ./add-nbo <File1> <File2>\n");
        return -1; // Error Case by argc
    }
    
    //file validation 확인

    FILE *f1, *f2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    if(f1 == NULL || f2 == NULL) return 1; // Error Case by Invalid File

    uint32_t net_order_1, net_order_2;
    fread(&net_order_1, sizeof(uint32_t), 1, f1); // 정말 4 byte를 읽었나?
    fread(&net_order_2, sizeof(uint32_t), 1, f2);

    uint32_t host_order_1 = htonl(net_order_1);
    uint32_t host_order_2 = htonl(net_order_2);
    uint32_t sum = host_order_1 + host_order_2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", host_order_1, host_order_1, host_order_2, host_order_2, sum, sum);

    fclose(f2);
    fclose(f1);
}
