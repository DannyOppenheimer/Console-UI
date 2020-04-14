#include "console_ui.hpp"

uiconsole::component::component(int* x, int* y) {
    this->x = x;
    this->y = y;
}
void uiconsole::component::draw() {}
