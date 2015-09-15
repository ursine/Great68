#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <memory>

constexpr size_t SIZE_64K = 1024*64;

template<typename T>
class Memory
{
public:
  virtual uint8_t   read8(const T address) const = 0;
  virtual uint16_t read16(const T address) const = 0;

  virtual void     write8(const T address, const uint8_t value)  = 0;
  virtual void    write16(const T address, const uint16_t value) = 0;
};

using TandyMemory = Memory<uint16_t>;

class SimpleRAM : public Memory<uint16_t>
{
public:
  SimpleRAM();

  uint8_t  read8(const uint16_t address)  const override { return ram.at(address); }
  uint16_t read16(const uint16_t address) const override { return ram.at(address) << 8 | ram.at(address+1); }

  void write8(const uint16_t address, const uint8_t value) override { ram.at(address) = value; }
  void write16(const uint16_t address, const uint16_t value) override {
    ram.at(address)   = (value>>8) & 0xFF;
    ram.at(address+1) = value & 0xFF;
  }

  void loadROM(const std::string& file, const uint16_t startAddress);

private:
  std::array<uint8_t,SIZE_64K> ram;
};

class Opcode {
};


class CPU
{
public:
  virtual void reset()                  = 0;
  virtual int  runFor(const int cycles) = 0;
};

class MC6809 : public CPU
{
public:
  void reset() override;
  int  runFor(const int cycles) override;

private:
  struct {
    uint16_t D;
    union {
      uint8_t A;
      uint8_t B;
    };
  };

  uint16_t X;
  uint16_t Y;
  uint16_t S;
  uint16_t U;
  uint16_t PC;
  uint8_t  CC;

  std::shared_ptr<TandyMemory> memory;
};
