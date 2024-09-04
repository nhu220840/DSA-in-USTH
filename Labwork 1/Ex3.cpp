#include <stdio.h>

typedef struct complexNumber{
    int real, img;

    void enter(){
        scanf("%d %d", &real, &img);
    }

    void print(){
        printf("%d + %di\n", real, img);
    }
} complexNumber;

//Addition:
//a = x1 + y1i
//b = x2 + y2i
//a + b = (x1 + x2) + (y1 + y2)i
complexNumber addition(complexNumber a, complexNumber b){
    complexNumber res;
    res.real = a.real + b.real;
    res.img = a.img + b.img;
    return res;
}

//Multiplication:
//a = x1 + y1i
//b = x2 + y2i
//a * b = (x1.x2) + x1y2i + x2y1i - y1y2
//      = (x1.x2 - y1.y2) + (x1y2 + x2y1)i
complexNumber multiplication(complexNumber a, complexNumber b){
    complexNumber res;
    res.real = a.real * b.real - a.img * b.img;
    res.img = (a.real * b.img + a.img * b.real);
    return res;
}

int main(){
    printf("Please enter components (real and virtual) of 2 complex numbers:\n");
    complexNumber a, b;
    a.enter();
    b.enter();

    printf("The result of addition of 2 complex numbers is: ");
    addition(a, b).print();
    printf("The result of multiplication of 2 complex numbers is: ");
    multiplication(a, b).print();
}