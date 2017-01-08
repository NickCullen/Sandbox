#include <stdio.h>
#include "Core/Engine.h"

int main()
{
    printf("Hello, world from c++\n");

    Engine e;

    e.Initialize();
    
    e.DoTests();

    return 0;
}