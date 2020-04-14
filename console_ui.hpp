#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H
#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "console_components.hpp"
#include "color_print.hpp"

namespace uiconsole {

    class console_drawer {
        int width, height, tickspeed;
        std::vector<component> components;

    public:
        console_drawer(int width, int height);
        void create_frame(const char color[], std::string vertical="|", std::string corner="+", std::string horizontal="-");

        /// <summary>Redraw console ui on a set tick rate.</summary>
        /// <param name="delay">Milliseconds to wait before refresh</param>  
        /// <param name="threaded">Whether or not to run the code in a thread. Defaults to true</param>
        void draw(int delay, bool threaded=true);
        void add(component to_add);
        int getWidth();
        int getHeight();
        friend std::ostream& operator<<(std::ostream& os, const console_drawer& dt);
        
    private:
        std::vector< std::vector<std::string> > window;
        char frame_color[];
    };
    std::ostream& operator<<(std::ostream& os, const uiconsole::console_drawer& dt);
}

#endif
