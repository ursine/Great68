#include "votrax.h"
#include <cstdio>

int main() {
    std::printf("Starting simulation\n");
    votrax_sc01_device votrax;
    votrax.device_start();
    votrax.device_reset();

    votrax.write(0x06);
    votrax.write(0x13);
    votrax.write(0x23);
    votrax.write(0x1A);

    return 0;
}