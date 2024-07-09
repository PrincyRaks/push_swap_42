# include <unistd.h>

void    print_error()
{
    write(1, "Error\n", 6);
}