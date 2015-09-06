#pragma once

#include <array>
#include <cstdint>

constexpr size_t SIZE_64K = 1024*64;

template<typename T>
class Memory
{
  virtual uint8_t   read8(const T address) const = 0;
  virtual uint16_t read16(const T address) const = 0;

  virtual void     write8(const T address, const uint8_t value)  = 0;
  virtual void    write16(const T address, const uint16_t value) = 0;
};

class SimpleRAM : public Memory<uint16_t>
{
public:
  SimpleRAM() : Memory()
  {
    ram.fill(0);
  }

  uint8_t  read8(const uint16_t address)  const override { return ram.at(address); }
  uint16_t read16(const uint16_t address) const override { return ram.at(address) << 8 | ram.at(address+1); }

  void write8(const uint16_t address, const uint8_t value) override { ram.at(address) = value; }
  void write16(const uint16_t address, const uint16_t value) override {
    ram.at(address)   = (value>>8) & 0xFF;
    ram.at(address+1) = value & 0xFF;
  }

private:
  std::array<uint8_t,SIZE_64K> ram;
};

class CPU
{
public:
  virtual void reset()                  = 0;
  virtual int  runFor(const int cycles) = 0;
};
