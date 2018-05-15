#include <immintrin.h>
#include <stdio.h>

int main()
{
    float a[] = { 10.0f, 20.0f, 30.0f, 40.0f, 1.0f, 1.0f, 1.0f, 1.0f };
    float b[] = { 40.0f, 30.0f, 20.0f, 10.0f, 2.0f, 2.0f, 2.0f, 2.0f };
    float c[] = { 2.5f,  1.2f,  1.3f,  4.3f,  0.5f, 0.5f, 0.5f, 0.5f };
    float d[] = { 0.0f,  0.0f,  0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f };

    __asm__ __volatile__ (
        // TODO: Multiply a and b and sum the result with c into d, BUT
        // starting from the index 4 in all the arrays above.
        //"movq $3, %%rcx\n\t"
//      "kmovw $0x80, %%eax\n\t"

        "movq $4,%%rax\n\t"
        "vmovapd 0x10(%0), %%xmm0\n\t"
        "vmovaps 0x10(%1), %%xmm1\n\t"
        "mulps %%xmm1, %%xmm0\n\t"
        "vmovaps 0x10(%2), %%xmm2\n\t"
        "addps %%xmm2, %%xmm0\n\t"
        "vmovaps %%xmm0, (%3)\n\t"

        ::
        "S"(a), "D"(b), "d"(c), "c"(d)
        :
        "%rax","xmm0", "xmm1", "xmm2"

    );

    printf("%f %f %f %f\n", d[4], d[5], d[6], d[7]);

    return 0;
}
