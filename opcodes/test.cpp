#include "cpu.hpp"

SimpleRAM tram;

int main(int argc, char* argv[])
{
  tram.loadROM("roms/bas13.rom",0xA000);
  tram.loadROM("roms/extbas11.rom",0x8000);
}
