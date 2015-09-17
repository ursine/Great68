#include "cpu.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

SimpleRAM::SimpleRAM() : Memory() {
  ram[0xFFFE] = 0xA0; // Start of BASIC
  ram[0xFFFF] = 0x27;
}

void SimpleRAM::loadROM(const std::string& file, const uint16_t address)
{
  std::ifstream inf(file , std::ios::binary | std::ios::in );

  auto start = std::istreambuf_iterator<char>(inf);
  auto end   = std::istreambuf_iterator<char>();

  std::vector<char> val(start,end);

  std::copy(val.begin(), val.end(), ram.begin() + address);
}

MC6809::MC6809(std::shared_ptr<TandyMemory> m) :
  memory(m)
{
}

void MC6809::reset()
{
  PC = memory->read16(0xFFFE);
  D=U=S=X=Y=0;
}

int MC6809::runFor(const int cycles)
{
  return 0;
}
