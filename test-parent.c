#include <stdio.h>
#include "rov-util.h"

int main(void)
{
    start_child("./test-child");
     start_child("./test-child second arg");
    return 0;
}
