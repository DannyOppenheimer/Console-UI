#include "console_ui.hpp"

uiconsole::input::input(int x, int y, std::string leading_title) : component(&x, &y) {
    this->leading_title = leading_title;
}

std::string uiconsole::input::getLeadingTitle() {
    return this->leading_title;
}
void uiconsole::input::draw() {
    std::cout << this->leading_title << "~ ";
}