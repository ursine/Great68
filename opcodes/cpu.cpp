#include "cpu.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

SimpleRAM::SimpleRAM() : Memory() {}

void SimpleRAM::loadROM(const std::string& file, const uint16_t address)
{
  std::ifstream inf(file , std::ios::binary | std::ios::in );

  auto start = std::istreambuf_iterator<char>(inf);
  auto end   = std::istreambuf_iterator<char>();

  std::vector<char> val(start,end);

  std::copy(val.begin(), val.end(), ram.begin() + address);
}
