#include "votrax.h"
#include <cstdio>

int main() {
    std::printf("Starting simulation\n");
    votrax_sc01_device votrax;
    votrax.device_start();
    votrax.device_reset();

    votrax.write(0x06);
    for (int i = 0; i < 51200; i++) { votrax.chip_update(); }

    votrax.write(0x13);
    for (int i = 0; i < 51200; i++) { votrax.chip_update(); }

    votrax.write(0x23);
    for (int i = 0; i < 51200; i++) { votrax.chip_update(); }

    votrax.write(0x1A);
    for (int i = 0; i < 51200; i++) { votrax.chip_update(); }

    return 0;
}