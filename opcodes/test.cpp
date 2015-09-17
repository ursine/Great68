#include "cpu.hpp"
#include <iostream>

std::shared_ptr<SimpleRAM> tram(new SimpleRAM);

int main(int argc, char* argv[])
{
  tram->loadROM("roms/bas13.rom",0xA000);
  tram->loadROM("roms/extbas11.rom",0x8000);

  MC6809 cpu(tram);

  try
  {
      cpu.run();    
  }
  catch(const std::invalid_argument& ia)
  {
      std::cout << "INVALID: " << ia.what() << std::endl;
  }
}
