#include <iostream>
#include <mysingletonlazy.h>
#include <mysingletonmeyers.h>

int main() {
    // yyang::MySingletonLazy::instance().log("Test in main");

    yyang::MySingletonMeyers::instance().log("Test in main");

    yyang::MySingletonMeyers::instance().log("Test in main2");

    return 0;
}