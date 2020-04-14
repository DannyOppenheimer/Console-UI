#ifndef CONSOLE_COMPONENTS_H
#define CONSOLE_COMPONENTS_H
#pragma once

#include <string>

namespace uiconsole {
    class component {
        int* x; 
        int* y;
    public:
        component(int* x, int* y);
        virtual void draw();
    };

    class input : public component {
    public:
        input(int x, int y, std::string leading_title);
        std::string getLeadingTitle();
        void draw();
    private:
        std::string leading_title;
    };
}

#endif