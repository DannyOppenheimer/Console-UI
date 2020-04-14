#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

#include "console_ui.hpp"

int main() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    uiconsole::console_drawer drawer = uiconsole::console_drawer(25, 20);
    drawer.create_frame(printc::RED);
    drawer.draw(1);
    return 0;
}
