#include <stdio.h>

typedef struct {
    int a;
    int b;
} Test;

typedef int (*AddFunc)(int, int);

int add(int a, int b) {
    return a + b;
}

void main(int argc, char *argv[]) {
    
    const float f = .01;
    double d = .01;

    printf("%f\n", f);
    printf("%f\n", d);

    Test t;
    t.a = 1;
    t.b = 2;
    printf("t.a = %d, t.b = %d\n", t.a, t.b);

    AddFunc addFunc = add;
    printf("addFunc(1, 2) = %d\n", addFunc(1, 2));

}