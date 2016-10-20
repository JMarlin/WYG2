#include "calculator.h"
#include "textbox.h"
#include <inttypes.h>
#include "styleutils.h"

int power(int base, int power) {

    int i;
    int out = 1;
    char* calc_str;

    for(i = 0; i < power; i++)
        out *= base;

    return out;
}

char* int_to_str(int integer) {

    int len, i, result;
    char* out_str;
    result = integer;

    for(len = 1; result; len++)
        result /= 10;

    if(!(out_str = malloc(len * sizeof(char))))
        return out_str;

    out_str[len - 1] = 0;

    for(i = len - 2; i >= 0; i--) {

        out_str[i] = (integer % 10) + '0';
        integer /= 10;
    }

    return out_str;
}

int str_to_int(char* string) {

    int i, len;
    int output = 0;

    for(len = 0; string[len]; len++);

    for(i = len - 1; i >= 0; i--) {

        if(string[i] < '0' || string[i] > '9')
            return output;

        output += (int)(string[i] - '0') * power(10, (len - 1) - i);
    }

    return output;
}

void Calc_paint(Window* calc_window) {

    draw_panel(calc_window->context, 0, 0, calc_window->width,
               calc_window->height, WIN_BGCOLOR, 2, 0);
    Context_fill_rect(calc_window->context, 2, 2, calc_window->width - 4,
                      calc_window->height - 4, WIN_BGCOLOR); 
}

void Calculator_button_handler(Window* button_window, int x, int y) {

    char* calc_str;
    Button* button = (Button*)button_window;
    Calculator* calculator = (Calculator*)button->window.parent;

    if(calculator->stage == 2) {

        calculator->stage = 0;
        Window_set_title((Window*)calculator->text_box, "0");
    }

    if(button == calculator->button_0) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "0");
    }

    if(button == calculator->button_1) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "1");
        else
            Window_set_title((Window*)calculator->text_box, "1");
    }

    if(button == calculator->button_2) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "2");
        else
            Window_set_title((Window*)calculator->text_box, "2");
    }

    if(button == calculator->button_3) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "3");
        else
            Window_set_title((Window*)calculator->text_box, "3");
    }

    if(button == calculator->button_4) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "4");
        else
            Window_set_title((Window*)calculator->text_box, "4");
    }

    if(button == calculator->button_5) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "5");
        else
            Window_set_title((Window*)calculator->text_box, "5");
    }

    if(button == calculator->button_6) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "6");
        else
            Window_set_title((Window*)calculator->text_box, "6");
    }

    if(button == calculator->button_7) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "7");
        else
            Window_set_title((Window*)calculator->text_box, "7");
    }

    if(button == calculator->button_8) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "8");
        else
            Window_set_title((Window*)calculator->text_box, "8");
    }

    if(button == calculator->button_9) {

        if(!(calculator->text_box->window.title[0] == '0' &&
            calculator->text_box->window.title[1] == 0))
            Window_append_title((Window*)calculator->text_box, "9");
        else
            Window_set_title((Window*)calculator->text_box, "9");
    }

    if(button == calculator->button_c) {
        Window_set_title((Window*)calculator->text_box, "0");
    }

    if(button == calculator->button_add) {

        if(calculator->stage == 0) {
            
            calculator->op = '+';
            calculator->stage = 1;
            Window_set_title((Window*)calculator->text_box, "0");
        }
    }

    if(button == calculator->button_sub) {

        if(calculator->stage == 0) {
            
            calculator->op = '-';
            calculator->stage++;
            Window_set_title((Window*)calculator->text_box, "0");
        }
    }

    if(button == calculator->button_mul) {

        if(calculator->stage == 0) {
            
            calculator->op = '*';
            calculator->stage++;
            Window_set_title((Window*)calculator->text_box, "0");
        }
    }

    if(button == calculator->button_div) {

        if(calculator->stage == 0) {
            
            calculator->op = '/';
            calculator->stage++;
            Window_set_title((Window*)calculator->text_box, "0");
        }
    }

    if(button == calculator->button_ent) {

        if(calculator->stage == 1) {

            calc_str = (char*)0;
            calculator->stage++;

            if(calculator->op == '+')
                calc_str = int_to_str(calculator->value[0] + calculator->value[1]);

            if(calculator->op == '-')
                calc_str = int_to_str(calculator->value[0] - calculator->value[1]);

            if(calculator->op == '*')
                calc_str = int_to_str(calculator->value[0] * calculator->value[1]);

            if(calculator->op == '/')
                calc_str = int_to_str(calculator->value[0] / calculator->value[1]);

            if(calc_str) {

                Window_set_title((Window*)calculator->text_box, calc_str);
                free(calc_str);
            }
        }
    }

    calculator->value[calculator->stage] = str_to_int(calculator->text_box->window.title);
}

Calculator* Calculator_new(void) {

    Calculator* calculator;
 
    //Attempt to allocate and initialize the window
    if(!(calculator = (Calculator*)malloc(sizeof(Calculator))))
        return calculator;

    if(!Window_init((Window*)calculator, 0, 0,
                    (2 * WIN_BORDERWIDTH) + 145,
                    WIN_TITLEHEIGHT + WIN_BORDERWIDTH + 170,
                    WIN_BODYDRAG | WIN_NODECORATION , (Context*)0)) {

        free(calculator);
        return (Calculator*)0;
    }

    calculator->value[0] = 0;
    calculator->value[1] = 0;
    calculator->value[2] = 0;
    calculator->stage = 0;

    calculator->window.paint_function = Calc_paint;

    //Set a default title 
    Window_set_title((Window*)calculator, "Calculator");

    //Create the buttons
    calculator->button_7 = Button_new(WIN_BORDERWIDTH + 5, WIN_TITLEHEIGHT + 30, 30, 30);
    Window_set_title((Window*)calculator->button_7, "7");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_7);

    calculator->button_8 = Button_new(WIN_BORDERWIDTH + 40, WIN_TITLEHEIGHT + 30, 30, 30);
    Window_set_title((Window*)calculator->button_8, "8");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_8);

    calculator->button_9 = Button_new(WIN_BORDERWIDTH + 75, WIN_TITLEHEIGHT + 30, 30, 30);
    Window_set_title((Window*)calculator->button_9, "9");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_9);

    calculator->button_add = Button_new(WIN_BORDERWIDTH + 110, WIN_TITLEHEIGHT + 30, 30, 30);
    Window_set_title((Window*)calculator->button_add, "+");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_add);

    calculator->button_4 = Button_new(WIN_BORDERWIDTH + 5, WIN_TITLEHEIGHT + 65, 30, 30);
    Window_set_title((Window*)calculator->button_4, "4");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_4);

    calculator->button_5 = Button_new(WIN_BORDERWIDTH + 40, WIN_TITLEHEIGHT + 65, 30, 30);
    Window_set_title((Window*)calculator->button_5, "5");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_5);

    calculator->button_6 = Button_new(WIN_BORDERWIDTH + 75, WIN_TITLEHEIGHT + 65, 30, 30);
    Window_set_title((Window*)calculator->button_6, "6");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_6);

    calculator->button_sub = Button_new(WIN_BORDERWIDTH + 110, WIN_TITLEHEIGHT + 65, 30, 30);
    Window_set_title((Window*)calculator->button_sub, "-");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_sub);

    calculator->button_1 = Button_new(WIN_BORDERWIDTH + 5, WIN_TITLEHEIGHT + 100, 30, 30);
    Window_set_title((Window*)calculator->button_1, "1");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_1);

    calculator->button_2 = Button_new(WIN_BORDERWIDTH + 40, WIN_TITLEHEIGHT + 100, 30, 30);
    Window_set_title((Window*)calculator->button_2, "2");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_2);

    calculator->button_3 = Button_new(WIN_BORDERWIDTH + 75, WIN_TITLEHEIGHT + 100, 30, 30);
    Window_set_title((Window*)calculator->button_3, "3");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_3);

    calculator->button_mul = Button_new(WIN_BORDERWIDTH + 110, WIN_TITLEHEIGHT + 100, 30, 30);
    Window_set_title((Window*)calculator->button_mul, "*");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_mul);

    calculator->button_c = Button_new(WIN_BORDERWIDTH + 5, WIN_TITLEHEIGHT + 135, 30, 30);
    Window_set_title((Window*)calculator->button_c, "C");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_c);

    calculator->button_0 = Button_new(WIN_BORDERWIDTH + 40, WIN_TITLEHEIGHT + 135, 30, 30);
    Window_set_title((Window*)calculator->button_0, "0");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_0);

    calculator->button_ent = Button_new(WIN_BORDERWIDTH + 75, WIN_TITLEHEIGHT + 135, 30, 30);
    Window_set_title((Window*)calculator->button_ent, "=");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_ent);

    calculator->button_div = Button_new(WIN_BORDERWIDTH + 110, WIN_TITLEHEIGHT + 135, 30, 30);
    Window_set_title((Window*)calculator->button_div, "/");
    Window_insert_child((Window*)calculator, (Window*)calculator->button_div);

    //We'll use the same handler to handle all of the buttons
    calculator->button_1->window.mouseclick_function = calculator->button_2->window.mouseclick_function = 
        calculator->button_3->window.mouseclick_function = calculator->button_4->window.mouseclick_function =
        calculator->button_5->window.mouseclick_function = calculator->button_6->window.mouseclick_function =
        calculator->button_7->window.mouseclick_function = calculator->button_8->window.mouseclick_function =
        calculator->button_9->window.mouseclick_function = calculator->button_0->window.mouseclick_function =
        calculator->button_add->window.mouseclick_function = calculator->button_sub->window.mouseclick_function = 
        calculator->button_mul->window.mouseclick_function = calculator->button_div->window.mouseclick_function =
        calculator->button_ent->window.mouseclick_function = calculator->button_c->window.mouseclick_function =
        Calculator_button_handler;          

    //Create the textbox
    calculator->text_box = TextBox_new(WIN_BORDERWIDTH + 5, WIN_TITLEHEIGHT + 5, 135, 20);
    Window_set_title((Window*)calculator->text_box, "0");
    Window_insert_child((Window*)calculator, (Window*)calculator->text_box);

    //Return the finished calculator
    return calculator;
}