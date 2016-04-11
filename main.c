#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/user.h>
#include <string.h>


int main() {
    FILE *fp = freopen(NULL, "rb", stdin);
    if (fseek(fp, 0, SEEK_END) == -1) {
        printf("stdin is not seekable\n");
        return 1;
    }

    long len = ftell(fp);
    rewind(fp);

    unsigned char *buffer = (unsigned char *) malloc((len + 1) * sizeof(unsigned char));

    fread(buffer, (size_t) len, 1, fp);
    fclose(fp);

    unsigned  char *mem = mmap(NULL, PAGE_SIZE, PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

    memcpy(mem, buffer, sizeof(buffer));

    int (*func)() = (int (*)()) mem;

    printf("%d\n", func());

    munmap(mem, PAGE_SIZE);
    free(buffer);

    return 0;
}