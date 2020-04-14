
namespace printc {
    extern const char RESET[], BLACK[], RED[], GREEN[], YELLOW[], BLUE[], MAGENTA[], CYAN[], WHITE[], LAST_LINE_BEGIN[], CLEAR[], BLANK[];
    const char RESET[] = "\033[0m";

    const char BLACK[] = "\033[30m";
    const char RED[] = "\033[31m";
    const char GREEN[] = "\033[32m";
    const char YELLOW[] = "\033[33m";
    const char BLUE[] = "\033[34m";
    const char MAGENTA[] = "\033[35m";
    const char CYAN[] = "\033[36m";
    const char WHITE[] = "\033[37m";

    const char LAST_LINE_BEGIN[] = "\e[1A";
    const char CLEAR[] = "\033[H\033[J";
    const char BLANK[] = " ";
}