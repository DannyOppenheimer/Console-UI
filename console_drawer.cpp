#include "console_ui.hpp"

#include <cstdlib>
#include <thread>
#include <chrono>

uiconsole::console_drawer::console_drawer(int width, int height) {
    this->width = width;
    this->height = height;

    for(int i = 0; i < this->height; ++i) {
        this->window.push_back(std::vector<std::string>(width));
    }

    for(int i = 0; i < this->height; ++i) {
        for(int j = 0; j < this->width; ++j) {
            this->window[i].at(j) = printc::BLANK;
        }
    }
        
}
void uiconsole::console_drawer::create_frame(const char color[], std::string vertical, std::string corner, std::string horizontal) {
    std::strcpy(this->frame_color, color);
    for(int i = 0; i < this->height; ++i) {
        this->window[0].at(i) = horizontal;
        this->window[this->height - 1].at(i) = horizontal;
        
    }
    for(int i = 0; i < this->width; ++i) {
        this->window[i].at(0) = vertical;
        this->window[i].at(this->width - 1) = vertical;
    }
    this->window[0].at(0) = corner;
    this->window[this->height - 1].at(0) = corner;
    this->window[0].at(this->width - 1) = corner;
    this->window[this->height - 1].at(this->width - 1) = corner;
}

void uiconsole::console_drawer::draw(int delay, bool threaded) {
    /*if(threaded) {}
    std::thread t( [this, &delay]() {
        bool exit_flag = true;
        while(exit_flag) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            // this->printframe(&this->width, &this->height, this->frame_color);


            for(int i = 0; i < this->components.size(); ++i) {
                this->components[i].draw();
                std::cout << "bruh";
            }
            for(int i = 0; i < this->height + 3; ++i) {
                std::cout << printc::LAST_LINE_BEGIN;
            }
        }
    });

    t.join();*/
    std::cout << this->frame_color;
    for(int i = 0; i < this->height; ++i) {
        for(int j = 0; j < this->width; ++j) {
            std::cout << this->window[i].at(j);
        }
        std::cout << std::endl;
    }
    std::cout << printc::RESET;

}
void uiconsole::console_drawer::add(component to_add) {
    this->components.push_back(to_add);
}

int uiconsole::console_drawer::getWidth() {
    return this->height;
}
int uiconsole::console_drawer::getHeight() {
    return this->height;
}

namespace uiconsole {
    std::ostream& operator<<(std::ostream& os, const console_drawer& cd) {
        os << "<console_drawer object at " << &cd << " with w" << cd.width << ", h" << cd.height << ">";
        return os;
    }
}
