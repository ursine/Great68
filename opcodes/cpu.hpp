#pragma once

#include <array>
#include <cstdint>

constexpr size_t SIZE_64Kb = 1024*64;

class Memory
{
  virtual uint8_t   read8(const uint16_t address) const = 0;
  virtual uint16_t read16(const uint16_t address) const = 0;
  
  virtual void     write8(const uint16_t address, const uint8_t value)  = 0;
  virtual void    write16(const uint16_t address, const uint16_t value) = 0;
};

template<size_t T>
class SimpleRAM : public Memory
{
public:
  SimpleRAM() : Memory() {}

private:
  std::array<uint8_t,T> ram;
};

class CPU
{
public:
  virtual void reset()                  = 0;
  virtual int  runFor(const int cycles) = 0;
};
