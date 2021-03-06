#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "button.h"
#include "textbox.h"

//Another special case of Window
typedef struct Calculator_struct {
    Window window; //'inherit' Window
    int value[3];
    int stage;
    char op;
    TextBox* text_box;
    Button* button_1;
    Button* button_2;
    Button* button_3;
    Button* button_4;
    Button* button_5;
    Button* button_6;
    Button* button_7;
    Button* button_8;
    Button* button_9;
    Button* button_0;
    Button* button_add;
    Button* button_sub;
    Button* button_div;
    Button* button_mul;
    Button* button_ent;
    Button* button_c;
} Calculator;

Calculator* Calculator_new(void);
void Calculator_delete_handler(void* calculator_object);

#endif //CALCULATOR_H