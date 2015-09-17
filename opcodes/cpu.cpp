#include "cpu.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <stdexcept>

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

using UnknownOpcode     = std::invalid_argument;
using UnsupportedOpcode = std::invalid_argument;

MC6809::MC6809(std::shared_ptr<TandyMemory> m) :
  memory(m)
{
}

void MC6809::reset()
{
  PC = memory->read16(0xFFFE);
  D=U=S=X=Y=0;
}

int MC6809::run()
{
  std::string opcode;

  int cycles = 0;

  uint8_t opc = memory->read8(PC++);
  
  switch(opc) {
    
    case 0x00 : { // NEG 
        opcode = "NEG";
        throw new UnsupportedOpcode("NEG 0x00");
        break;
    }

    case 0x01 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x01");
        break;
    }

    case 0x02 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x02");
        break;
    }

    case 0x03 : { // COM 
        opcode = "COM";
        throw new UnsupportedOpcode("COM 0x03");
        break;
    }

    case 0x04 : { // LSR 
        opcode = "LSR";
        throw new UnsupportedOpcode("LSR 0x04");
        break;
    }

    case 0x05 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x05");
        break;
    }

    case 0x06 : { // ROR 
        opcode = "ROR";
        throw new UnsupportedOpcode("ROR 0x06");
        break;
    }

    case 0x07 : { // ASR 
        opcode = "ASR";
        throw new UnsupportedOpcode("ASR 0x07");
        break;
    }

    case 0x08 : { // ASL/LSL 
        opcode = "ASL/LSL";
        throw new UnsupportedOpcode("ASL/LSL 0x08");
        break;
    }

    case 0x09 : { // ROL 
        opcode = "ROL";
        throw new UnsupportedOpcode("ROL 0x09");
        break;
    }

    case 0x0A : { // DEC 
        opcode = "DEC";
        throw new UnsupportedOpcode("DEC 0x0A");
        break;
    }

    case 0x0B : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x0B");
        break;
    }

    case 0x0C : { // INC 
        opcode = "INC";
        throw new UnsupportedOpcode("INC 0x0C");
        break;
    }

    case 0x0D : { // TST 
        opcode = "TST";
        throw new UnsupportedOpcode("TST 0x0D");
        break;
    }

    case 0x0E : { // JMP 
        opcode = "JMP";
        throw new UnsupportedOpcode("JMP 0x0E");
        break;
    }

    case 0x0F : { // CLR 
        opcode = "CLR";
        throw new UnsupportedOpcode("CLR 0x0F");
        break;
    }

    case 0x10 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x10");
        break;
    }

    case 0x11 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x11");
        break;
    }

    case 0x12 : { // NOP 
        opcode = "NOP";
        throw new UnsupportedOpcode("NOP 0x12");
        break;
    }

    case 0x13 : { // SYNC 
        opcode = "SYNC";
        throw new UnsupportedOpcode("SYNC 0x13");
        break;
    }

    case 0x14 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x14");
        break;
    }

    case 0x15 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x15");
        break;
    }

    case 0x16 : { // LBRA 
        opcode = "LBRA";
        throw new UnsupportedOpcode("LBRA 0x16");
        break;
    }

    case 0x17 : { // LBSR 
        opcode = "LBSR";
        throw new UnsupportedOpcode("LBSR 0x17");
        break;
    }

    case 0x18 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x18");
        break;
    }

    case 0x19 : { // DAA 
        opcode = "DAA";
        throw new UnsupportedOpcode("DAA 0x19");
        break;
    }

    case 0x1A : { // ORCC 
        opcode = "ORCC";
        throw new UnsupportedOpcode("ORCC 0x1A");
        break;
    }

    case 0x1B : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x1B");
        break;
    }

    case 0x1C : { // ANDCC 
        opcode = "ANDCC";
        throw new UnsupportedOpcode("ANDCC 0x1C");
        break;
    }

    case 0x1D : { // SEX 
        opcode = "SEX";
        throw new UnsupportedOpcode("SEX 0x1D");
        break;
    }

    case 0x1E : { // EXG 
        opcode = "EXG";
        throw new UnsupportedOpcode("EXG 0x1E");
        break;
    }

    case 0x1F : { // TFR 
        opcode = "TFR";
        throw new UnsupportedOpcode("TFR 0x1F");
        break;
    }

    case 0x20 : { // BRA 
        opcode = "BRA";
        throw new UnsupportedOpcode("BRA 0x20");
        break;
    }

    case 0x21 : { // BRN 
        opcode = "BRN";
        throw new UnsupportedOpcode("BRN 0x21");
        break;
    }

    case 0x22 : { // BHI 
        opcode = "BHI";
        throw new UnsupportedOpcode("BHI 0x22");
        break;
    }

    case 0x23 : { // BLS 
        opcode = "BLS";
        throw new UnsupportedOpcode("BLS 0x23");
        break;
    }

    case 0x24 : { // BHS/BCC 
        opcode = "BHS/BCC";
        throw new UnsupportedOpcode("BHS/BCC 0x24");
        break;
    }

    case 0x25 : { // BLO/BCS 
        opcode = "BLO/BCS";
        throw new UnsupportedOpcode("BLO/BCS 0x25");
        break;
    }

    case 0x26 : { // BNE 
        opcode = "BNE";
        throw new UnsupportedOpcode("BNE 0x26");
        break;
    }

    case 0x27 : { // BEQ 
        opcode = "BEQ";
        throw new UnsupportedOpcode("BEQ 0x27");
        break;
    }

    case 0x28 : { // BVC 
        opcode = "BVC";
        throw new UnsupportedOpcode("BVC 0x28");
        break;
    }

    case 0x29 : { // BVS 
        opcode = "BVS";
        throw new UnsupportedOpcode("BVS 0x29");
        break;
    }

    case 0x2A : { // BPL 
        opcode = "BPL";
        throw new UnsupportedOpcode("BPL 0x2A");
        break;
    }

    case 0x2B : { // BMI 
        opcode = "BMI";
        throw new UnsupportedOpcode("BMI 0x2B");
        break;
    }

    case 0x2C : { // BGE 
        opcode = "BGE";
        throw new UnsupportedOpcode("BGE 0x2C");
        break;
    }

    case 0x2D : { // BLT 
        opcode = "BLT";
        throw new UnsupportedOpcode("BLT 0x2D");
        break;
    }

    case 0x2E : { // BGT 
        opcode = "BGT";
        throw new UnsupportedOpcode("BGT 0x2E");
        break;
    }

    case 0x2F : { // BLE 
        opcode = "BLE";
        throw new UnsupportedOpcode("BLE 0x2F");
        break;
    }

    case 0x30 : { // LEAX 
        opcode = "LEAX";
        throw new UnsupportedOpcode("LEAX 0x30");
        break;
    }

    case 0x31 : { // LEAY 
        opcode = "LEAY";
        throw new UnsupportedOpcode("LEAY 0x31");
        break;
    }

    case 0x32 : { // LEAS 
        opcode = "LEAS";
        throw new UnsupportedOpcode("LEAS 0x32");
        break;
    }

    case 0x33 : { // LEAU 
        opcode = "LEAU";
        throw new UnsupportedOpcode("LEAU 0x33");
        break;
    }

    case 0x34 : { // PSHS 
        opcode = "PSHS";
        throw new UnsupportedOpcode("PSHS 0x34");
        break;
    }

    case 0x35 : { // PULS 
        opcode = "PULS";
        throw new UnsupportedOpcode("PULS 0x35");
        break;
    }

    case 0x36 : { // PSHU 
        opcode = "PSHU";
        throw new UnsupportedOpcode("PSHU 0x36");
        break;
    }

    case 0x37 : { // PULU 
        opcode = "PULU";
        throw new UnsupportedOpcode("PULU 0x37");
        break;
    }

    case 0x38 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x38");
        break;
    }

    case 0x39 : { // RTS 
        opcode = "RTS";
        throw new UnsupportedOpcode("RTS 0x39");
        break;
    }

    case 0x3A : { // ABX 
        opcode = "ABX";
        throw new UnsupportedOpcode("ABX 0x3A");
        break;
    }

    case 0x3B : { // RTI 
        opcode = "RTI";
        throw new UnsupportedOpcode("RTI 0x3B");
        break;
    }

    case 0x3C : { // CWAI 
        opcode = "CWAI";
        throw new UnsupportedOpcode("CWAI 0x3C");
        break;
    }

    case 0x3D : { // MUL 
        opcode = "MUL";
        throw new UnsupportedOpcode("MUL 0x3D");
        break;
    }

    case 0x3E : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x3E");
        break;
    }

    case 0x3F : { // SWI 
        opcode = "SWI";
        throw new UnsupportedOpcode("SWI 0x3F");
        break;
    }

    case 0x40 : { // NEGA 
        opcode = "NEGA";
        throw new UnsupportedOpcode("NEGA 0x40");
        break;
    }

    case 0x41 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x41");
        break;
    }

    case 0x42 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x42");
        break;
    }

    case 0x43 : { // COMA 
        opcode = "COMA";
        throw new UnsupportedOpcode("COMA 0x43");
        break;
    }

    case 0x44 : { // LSRA 
        opcode = "LSRA";
        throw new UnsupportedOpcode("LSRA 0x44");
        break;
    }

    case 0x45 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x45");
        break;
    }

    case 0x46 : { // RORA 
        opcode = "RORA";
        throw new UnsupportedOpcode("RORA 0x46");
        break;
    }

    case 0x47 : { // ASRA 
        opcode = "ASRA";
        throw new UnsupportedOpcode("ASRA 0x47");
        break;
    }

    case 0x48 : { // ASLA/LSLA 
        opcode = "ASLA/LSLA";
        throw new UnsupportedOpcode("ASLA/LSLA 0x48");
        break;
    }

    case 0x49 : { // ROLA 
        opcode = "ROLA";
        throw new UnsupportedOpcode("ROLA 0x49");
        break;
    }

    case 0x4A : { // DECA 
        opcode = "DECA";
        throw new UnsupportedOpcode("DECA 0x4A");
        break;
    }

    case 0x4B : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x4B");
        break;
    }

    case 0x4C : { // INCA 
        opcode = "INCA";
        throw new UnsupportedOpcode("INCA 0x4C");
        break;
    }

    case 0x4D : { // TSTA 
        opcode = "TSTA";
        throw new UnsupportedOpcode("TSTA 0x4D");
        break;
    }

    case 0x4E : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x4E");
        break;
    }

    case 0x4F : { // CLRA 
        opcode = "CLRA";
        throw new UnsupportedOpcode("CLRA 0x4F");
        break;
    }

    case 0x50 : { // NEGB 
        opcode = "NEGB";
        throw new UnsupportedOpcode("NEGB 0x50");
        break;
    }

    case 0x51 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x51");
        break;
    }

    case 0x52 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x52");
        break;
    }

    case 0x53 : { // COMB 
        opcode = "COMB";
        throw new UnsupportedOpcode("COMB 0x53");
        break;
    }

    case 0x54 : { // LSRB 
        opcode = "LSRB";
        throw new UnsupportedOpcode("LSRB 0x54");
        break;
    }

    case 0x55 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x55");
        break;
    }

    case 0x56 : { // RORB 
        opcode = "RORB";
        throw new UnsupportedOpcode("RORB 0x56");
        break;
    }

    case 0x57 : { // ASRB 
        opcode = "ASRB";
        throw new UnsupportedOpcode("ASRB 0x57");
        break;
    }

    case 0x58 : { // ASLB/LSLB 
        opcode = "ASLB/LSLB";
        throw new UnsupportedOpcode("ASLB/LSLB 0x58");
        break;
    }

    case 0x59 : { // ROLB 
        opcode = "ROLB";
        throw new UnsupportedOpcode("ROLB 0x59");
        break;
    }

    case 0x5A : { // DECB 
        opcode = "DECB";
        throw new UnsupportedOpcode("DECB 0x5A");
        break;
    }

    case 0x5B : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x5B");
        break;
    }

    case 0x5C : { // INCB 
        opcode = "INCB";
        throw new UnsupportedOpcode("INCB 0x5C");
        break;
    }

    case 0x5D : { // TSTB 
        opcode = "TSTB";
        throw new UnsupportedOpcode("TSTB 0x5D");
        break;
    }

    case 0x5E : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x5E");
        break;
    }

    case 0x5F : { // CLRB 
        opcode = "CLRB";
        throw new UnsupportedOpcode("CLRB 0x5F");
        break;
    }

    case 0x60 : { // NEG 
        opcode = "NEG";
        throw new UnsupportedOpcode("NEG 0x60");
        break;
    }

    case 0x61 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x61");
        break;
    }

    case 0x62 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x62");
        break;
    }

    case 0x63 : { // COM 
        opcode = "COM";
        throw new UnsupportedOpcode("COM 0x63");
        break;
    }

    case 0x64 : { // LSR 
        opcode = "LSR";
        throw new UnsupportedOpcode("LSR 0x64");
        break;
    }

    case 0x65 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x65");
        break;
    }

    case 0x66 : { // ROR 
        opcode = "ROR";
        throw new UnsupportedOpcode("ROR 0x66");
        break;
    }

    case 0x67 : { // ASR 
        opcode = "ASR";
        throw new UnsupportedOpcode("ASR 0x67");
        break;
    }

    case 0x68 : { // ASL/LSL 
        opcode = "ASL/LSL";
        throw new UnsupportedOpcode("ASL/LSL 0x68");
        break;
    }

    case 0x69 : { // ROL 
        opcode = "ROL";
        throw new UnsupportedOpcode("ROL 0x69");
        break;
    }

    case 0x6A : { // DEC 
        opcode = "DEC";
        throw new UnsupportedOpcode("DEC 0x6A");
        break;
    }

    case 0x6B : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x6B");
        break;
    }

    case 0x6C : { // INC 
        opcode = "INC";
        throw new UnsupportedOpcode("INC 0x6C");
        break;
    }

    case 0x6D : { // TST 
        opcode = "TST";
        throw new UnsupportedOpcode("TST 0x6D");
        break;
    }

    case 0x6E : { // JMP 
        opcode = "JMP";
        throw new UnsupportedOpcode("JMP 0x6E");
        break;
    }

    case 0x6F : { // CLR 
        opcode = "CLR";
        throw new UnsupportedOpcode("CLR 0x6F");
        break;
    }

    case 0x70 : { // NEG 
        opcode = "NEG";
        throw new UnsupportedOpcode("NEG 0x70");
        break;
    }

    case 0x71 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x71");
        break;
    }

    case 0x72 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x72");
        break;
    }

    case 0x73 : { // COM 
        opcode = "COM";
        throw new UnsupportedOpcode("COM 0x73");
        break;
    }

    case 0x74 : { // LSR 
        opcode = "LSR";
        throw new UnsupportedOpcode("LSR 0x74");
        break;
    }

    case 0x75 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x75");
        break;
    }

    case 0x76 : { // ROR 
        opcode = "ROR";
        throw new UnsupportedOpcode("ROR 0x76");
        break;
    }

    case 0x77 : { // ASR 
        opcode = "ASR";
        throw new UnsupportedOpcode("ASR 0x77");
        break;
    }

    case 0x78 : { // ASL/LSL 
        opcode = "ASL/LSL";
        throw new UnsupportedOpcode("ASL/LSL 0x78");
        break;
    }

    case 0x79 : { // ROL 
        opcode = "ROL";
        throw new UnsupportedOpcode("ROL 0x79");
        break;
    }

    case 0x7A : { // DEC 
        opcode = "DEC";
        throw new UnsupportedOpcode("DEC 0x7A");
        break;
    }

    case 0x7B : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x7B");
        break;
    }

    case 0x7C : { // INC 
        opcode = "INC";
        throw new UnsupportedOpcode("INC 0x7C");
        break;
    }

    case 0x7D : { // TST 
        opcode = "TST";
        throw new UnsupportedOpcode("TST 0x7D");
        break;
    }

    case 0x7E : { // JMP 
        opcode = "JMP";
        throw new UnsupportedOpcode("JMP 0x7E");
        break;
    }

    case 0x7F : { // CLR 
        opcode = "CLR";
        throw new UnsupportedOpcode("CLR 0x7F");
        break;
    }

    case 0x80 : { // SUBA 
        opcode = "SUBA";
        throw new UnsupportedOpcode("SUBA 0x80");
        break;
    }

    case 0x81 : { // CMPA 
        opcode = "CMPA";
        throw new UnsupportedOpcode("CMPA 0x81");
        break;
    }

    case 0x82 : { // SBCA 
        opcode = "SBCA";
        throw new UnsupportedOpcode("SBCA 0x82");
        break;
    }

    case 0x83 : { // SUBD 
        opcode = "SUBD";
        throw new UnsupportedOpcode("SUBD 0x83");
        break;
    }

    case 0x84 : { // ANDA 
        opcode = "ANDA";
        throw new UnsupportedOpcode("ANDA 0x84");
        break;
    }

    case 0x85 : { // BITA 
        opcode = "BITA";
        throw new UnsupportedOpcode("BITA 0x85");
        break;
    }

    case 0x86 : { // LDA 
        opcode = "LDA";
        throw new UnsupportedOpcode("LDA 0x86");
        break;
    }

    case 0x87 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x87");
        break;
    }

    case 0x88 : { // EORA 
        opcode = "EORA";
        throw new UnsupportedOpcode("EORA 0x88");
        break;
    }

    case 0x89 : { // ADCA 
        opcode = "ADCA";
        throw new UnsupportedOpcode("ADCA 0x89");
        break;
    }

    case 0x8A : { // ORA 
        opcode = "ORA";
        throw new UnsupportedOpcode("ORA 0x8A");
        break;
    }

    case 0x8B : { // ADDA 
        opcode = "ADDA";
        throw new UnsupportedOpcode("ADDA 0x8B");
        break;
    }

    case 0x8C : { // CMPX 
        opcode = "CMPX";
        throw new UnsupportedOpcode("CMPX 0x8C");
        break;
    }

    case 0x8D : { // BSR 
        opcode = "BSR";
        throw new UnsupportedOpcode("BSR 0x8D");
        break;
    }

    case 0x8E : { // LDX 
        opcode = "LDX";
        throw new UnsupportedOpcode("LDX 0x8E");
        break;
    }

    case 0x8F : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0x8F");
        break;
    }

    case 0x90 : { // SUBA 
        opcode = "SUBA";
        throw new UnsupportedOpcode("SUBA 0x90");
        break;
    }

    case 0x91 : { // CMPA 
        opcode = "CMPA";
        throw new UnsupportedOpcode("CMPA 0x91");
        break;
    }

    case 0x92 : { // SBCA 
        opcode = "SBCA";
        throw new UnsupportedOpcode("SBCA 0x92");
        break;
    }

    case 0x93 : { // SUBD 
        opcode = "SUBD";
        throw new UnsupportedOpcode("SUBD 0x93");
        break;
    }

    case 0x94 : { // ANDA 
        opcode = "ANDA";
        throw new UnsupportedOpcode("ANDA 0x94");
        break;
    }

    case 0x95 : { // BITA 
        opcode = "BITA";
        throw new UnsupportedOpcode("BITA 0x95");
        break;
    }

    case 0x96 : { // LDA 
        opcode = "LDA";
        throw new UnsupportedOpcode("LDA 0x96");
        break;
    }

    case 0x97 : { // STA 
        opcode = "STA";
        throw new UnsupportedOpcode("STA 0x97");
        break;
    }

    case 0x98 : { // EORA 
        opcode = "EORA";
        throw new UnsupportedOpcode("EORA 0x98");
        break;
    }

    case 0x99 : { // ADCA 
        opcode = "ADCA";
        throw new UnsupportedOpcode("ADCA 0x99");
        break;
    }

    case 0x9A : { // ORA 
        opcode = "ORA";
        throw new UnsupportedOpcode("ORA 0x9A");
        break;
    }

    case 0x9B : { // ADDA 
        opcode = "ADDA";
        throw new UnsupportedOpcode("ADDA 0x9B");
        break;
    }

    case 0x9C : { // CMPX 
        opcode = "CMPX";
        throw new UnsupportedOpcode("CMPX 0x9C");
        break;
    }

    case 0x9D : { // JSR 
        opcode = "JSR";
        throw new UnsupportedOpcode("JSR 0x9D");
        break;
    }

    case 0x9E : { // LDX 
        opcode = "LDX";
        throw new UnsupportedOpcode("LDX 0x9E");
        break;
    }

    case 0x9F : { // STX 
        opcode = "STX";
        throw new UnsupportedOpcode("STX 0x9F");
        break;
    }

    case 0xA0 : { // SUBA 
        opcode = "SUBA";
        throw new UnsupportedOpcode("SUBA 0xA0");
        break;
    }

    case 0xA1 : { // CMPA 
        opcode = "CMPA";
        throw new UnsupportedOpcode("CMPA 0xA1");
        break;
    }

    case 0xA2 : { // SBCA 
        opcode = "SBCA";
        throw new UnsupportedOpcode("SBCA 0xA2");
        break;
    }

    case 0xA3 : { // SUBD 
        opcode = "SUBD";
        throw new UnsupportedOpcode("SUBD 0xA3");
        break;
    }

    case 0xA4 : { // ANDA 
        opcode = "ANDA";
        throw new UnsupportedOpcode("ANDA 0xA4");
        break;
    }

    case 0xA5 : { // BITA 
        opcode = "BITA";
        throw new UnsupportedOpcode("BITA 0xA5");
        break;
    }

    case 0xA6 : { // LDA 
        opcode = "LDA";
        throw new UnsupportedOpcode("LDA 0xA6");
        break;
    }

    case 0xA7 : { // STA 
        opcode = "STA";
        throw new UnsupportedOpcode("STA 0xA7");
        break;
    }

    case 0xA8 : { // EORA 
        opcode = "EORA";
        throw new UnsupportedOpcode("EORA 0xA8");
        break;
    }

    case 0xA9 : { // ADCA 
        opcode = "ADCA";
        throw new UnsupportedOpcode("ADCA 0xA9");
        break;
    }

    case 0xAA : { // ORA 
        opcode = "ORA";
        throw new UnsupportedOpcode("ORA 0xAA");
        break;
    }

    case 0xAB : { // ADDA 
        opcode = "ADDA";
        throw new UnsupportedOpcode("ADDA 0xAB");
        break;
    }

    case 0xAC : { // CMPX 
        opcode = "CMPX";
        throw new UnsupportedOpcode("CMPX 0xAC");
        break;
    }

    case 0xAD : { // JSR 
        opcode = "JSR";
        throw new UnsupportedOpcode("JSR 0xAD");
        break;
    }

    case 0xAE : { // LDX 
        opcode = "LDX";
        throw new UnsupportedOpcode("LDX 0xAE");
        break;
    }

    case 0xAF : { // STX 
        opcode = "STX";
        throw new UnsupportedOpcode("STX 0xAF");
        break;
    }

    case 0xB0 : { // SUBA 
        opcode = "SUBA";
        throw new UnsupportedOpcode("SUBA 0xB0");
        break;
    }

    case 0xB1 : { // CMPA 
        opcode = "CMPA";
        throw new UnsupportedOpcode("CMPA 0xB1");
        break;
    }

    case 0xB2 : { // SBCA 
        opcode = "SBCA";
        throw new UnsupportedOpcode("SBCA 0xB2");
        break;
    }

    case 0xB3 : { // SUBD 
        opcode = "SUBD";
        throw new UnsupportedOpcode("SUBD 0xB3");
        break;
    }

    case 0xB4 : { // ANDA 
        opcode = "ANDA";
        throw new UnsupportedOpcode("ANDA 0xB4");
        break;
    }

    case 0xB5 : { // BITA 
        opcode = "BITA";
        throw new UnsupportedOpcode("BITA 0xB5");
        break;
    }

    case 0xB6 : { // LDA 
        opcode = "LDA";
        throw new UnsupportedOpcode("LDA 0xB6");
        break;
    }

    case 0xB7 : { // STA 
        opcode = "STA";
        throw new UnsupportedOpcode("STA 0xB7");
        break;
    }

    case 0xB8 : { // EORA 
        opcode = "EORA";
        throw new UnsupportedOpcode("EORA 0xB8");
        break;
    }

    case 0xB9 : { // ADCA 
        opcode = "ADCA";
        throw new UnsupportedOpcode("ADCA 0xB9");
        break;
    }

    case 0xBA : { // ORA 
        opcode = "ORA";
        throw new UnsupportedOpcode("ORA 0xBA");
        break;
    }

    case 0xBB : { // ADDA 
        opcode = "ADDA";
        throw new UnsupportedOpcode("ADDA 0xBB");
        break;
    }

    case 0xBC : { // CMPX 
        opcode = "CMPX";
        throw new UnsupportedOpcode("CMPX 0xBC");
        break;
    }

    case 0xBD : { // JSR 
        opcode = "JSR";
        throw new UnsupportedOpcode("JSR 0xBD");
        break;
    }

    case 0xBE : { // LDX 
        opcode = "LDX";
        throw new UnsupportedOpcode("LDX 0xBE");
        break;
    }

    case 0xBF : { // STX 
        opcode = "STX";
        throw new UnsupportedOpcode("STX 0xBF");
        break;
    }

    case 0xC0 : { // SUBB 
        opcode = "SUBB";
        throw new UnsupportedOpcode("SUBB 0xC0");
        break;
    }

    case 0xC1 : { // CMPB 
        opcode = "CMPB";
        throw new UnsupportedOpcode("CMPB 0xC1");
        break;
    }

    case 0xC2 : { // SBCB 
        opcode = "SBCB";
        throw new UnsupportedOpcode("SBCB 0xC2");
        break;
    }

    case 0xC3 : { // ADDD 
        opcode = "ADDD";
        throw new UnsupportedOpcode("ADDD 0xC3");
        break;
    }

    case 0xC4 : { // ANDB 
        opcode = "ANDB";
        throw new UnsupportedOpcode("ANDB 0xC4");
        break;
    }

    case 0xC5 : { // BITB 
        opcode = "BITB";
        throw new UnsupportedOpcode("BITB 0xC5");
        break;
    }

    case 0xC6 : { // LDB 
        opcode = "LDB";
        throw new UnsupportedOpcode("LDB 0xC6");
        break;
    }

    case 0xC7 : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0xC7");
        break;
    }

    case 0xC8 : { // EORB 
        opcode = "EORB";
        throw new UnsupportedOpcode("EORB 0xC8");
        break;
    }

    case 0xC9 : { // ADCB 
        opcode = "ADCB";
        throw new UnsupportedOpcode("ADCB 0xC9");
        break;
    }

    case 0xCA : { // ORB 
        opcode = "ORB";
        throw new UnsupportedOpcode("ORB 0xCA");
        break;
    }

    case 0xCB : { // ADDB 
        opcode = "ADDB";
        throw new UnsupportedOpcode("ADDB 0xCB");
        break;
    }

    case 0xCC : { // LDD 
        opcode = "LDD";
        throw new UnsupportedOpcode("LDD 0xCC");
        break;
    }

    case 0xCD : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0xCD");
        break;
    }

    case 0xCE : { // LDU 
        opcode = "LDU";
        throw new UnsupportedOpcode("LDU 0xCE");
        break;
    }

    case 0xCF : { // INVALID 
        opcode = "INVALID";
        throw new UnknownOpcode("INVALID 0xCF");
        break;
    }

    case 0xD0 : { // SUBB 
        opcode = "SUBB";
        throw new UnsupportedOpcode("SUBB 0xD0");
        break;
    }

    case 0xD1 : { // CMPB 
        opcode = "CMPB";
        throw new UnsupportedOpcode("CMPB 0xD1");
        break;
    }

    case 0xD2 : { // SBCB 
        opcode = "SBCB";
        throw new UnsupportedOpcode("SBCB 0xD2");
        break;
    }

    case 0xD3 : { // ADDD 
        opcode = "ADDD";
        throw new UnsupportedOpcode("ADDD 0xD3");
        break;
    }

    case 0xD4 : { // ANDB 
        opcode = "ANDB";
        throw new UnsupportedOpcode("ANDB 0xD4");
        break;
    }

    case 0xD5 : { // BITB 
        opcode = "BITB";
        throw new UnsupportedOpcode("BITB 0xD5");
        break;
    }

    case 0xD6 : { // LDB 
        opcode = "LDB";
        throw new UnsupportedOpcode("LDB 0xD6");
        break;
    }

    case 0xD7 : { // STB 
        opcode = "STB";
        throw new UnsupportedOpcode("STB 0xD7");
        break;
    }

    case 0xD8 : { // EORB 
        opcode = "EORB";
        throw new UnsupportedOpcode("EORB 0xD8");
        break;
    }

    case 0xD9 : { // ADCB 
        opcode = "ADCB";
        throw new UnsupportedOpcode("ADCB 0xD9");
        break;
    }

    case 0xDA : { // ORB 
        opcode = "ORB";
        throw new UnsupportedOpcode("ORB 0xDA");
        break;
    }

    case 0xDB : { // ADDB 
        opcode = "ADDB";
        throw new UnsupportedOpcode("ADDB 0xDB");
        break;
    }

    case 0xDC : { // LDD 
        opcode = "LDD";
        throw new UnsupportedOpcode("LDD 0xDC");
        break;
    }

    case 0xDD : { // STD 
        opcode = "STD";
        throw new UnsupportedOpcode("STD 0xDD");
        break;
    }

    case 0xDE : { // LDU 
        opcode = "LDU";
        throw new UnsupportedOpcode("LDU 0xDE");
        break;
    }

    case 0xDF : { // STU 
        opcode = "STU";
        throw new UnsupportedOpcode("STU 0xDF");
        break;
    }

    case 0xE0 : { // SUBB 
        opcode = "SUBB";
        throw new UnsupportedOpcode("SUBB 0xE0");
        break;
    }

    case 0xE1 : { // CMPB 
        opcode = "CMPB";
        throw new UnsupportedOpcode("CMPB 0xE1");
        break;
    }

    case 0xE2 : { // SBCB 
        opcode = "SBCB";
        throw new UnsupportedOpcode("SBCB 0xE2");
        break;
    }

    case 0xE3 : { // ADDD 
        opcode = "ADDD";
        throw new UnsupportedOpcode("ADDD 0xE3");
        break;
    }

    case 0xE4 : { // ANDB 
        opcode = "ANDB";
        throw new UnsupportedOpcode("ANDB 0xE4");
        break;
    }

    case 0xE5 : { // BITB 
        opcode = "BITB";
        throw new UnsupportedOpcode("BITB 0xE5");
        break;
    }

    case 0xE6 : { // LDB 
        opcode = "LDB";
        throw new UnsupportedOpcode("LDB 0xE6");
        break;
    }

    case 0xE7 : { // STB 
        opcode = "STB";
        throw new UnsupportedOpcode("STB 0xE7");
        break;
    }

    case 0xE8 : { // EORB 
        opcode = "EORB";
        throw new UnsupportedOpcode("EORB 0xE8");
        break;
    }

    case 0xE9 : { // ADCB 
        opcode = "ADCB";
        throw new UnsupportedOpcode("ADCB 0xE9");
        break;
    }

    case 0xEA : { // ORB 
        opcode = "ORB";
        throw new UnsupportedOpcode("ORB 0xEA");
        break;
    }

    case 0xEB : { // ADDB 
        opcode = "ADDB";
        throw new UnsupportedOpcode("ADDB 0xEB");
        break;
    }

    case 0xEC : { // LDD 
        opcode = "LDD";
        throw new UnsupportedOpcode("LDD 0xEC");
        break;
    }

    case 0xED : { // STD 
        opcode = "STD";
        throw new UnsupportedOpcode("STD 0xED");
        break;
    }

    case 0xEE : { // LDU 
        opcode = "LDU";
        throw new UnsupportedOpcode("LDU 0xEE");
        break;
    }

    case 0xEF : { // STU 
        opcode = "STU";
        throw new UnsupportedOpcode("STU 0xEF");
        break;
    }

    case 0xF0 : { // SUBB 
        opcode = "SUBB";
        throw new UnsupportedOpcode("SUBB 0xF0");
        break;
    }

    case 0xF1 : { // CMPB 
        opcode = "CMPB";
        throw new UnsupportedOpcode("CMPB 0xF1");
        break;
    }

    case 0xF2 : { // SBCB 
        opcode = "SBCB";
        throw new UnsupportedOpcode("SBCB 0xF2");
        break;
    }

    case 0xF3 : { // ADDD 
        opcode = "ADDD";
        throw new UnsupportedOpcode("ADDD 0xF3");
        break;
    }

    case 0xF4 : { // ANDB 
        opcode = "ANDB";
        throw new UnsupportedOpcode("ANDB 0xF4");
        break;
    }

    case 0xF5 : { // BITB 
        opcode = "BITB";
        throw new UnsupportedOpcode("BITB 0xF5");
        break;
    }

    case 0xF6 : { // LDB 
        opcode = "LDB";
        throw new UnsupportedOpcode("LDB 0xF6");
        break;
    }

    case 0xF7 : { // STB 
        opcode = "STB";
        throw new UnsupportedOpcode("STB 0xF7");
        break;
    }

    case 0xF8 : { // EORB 
        opcode = "EORB";
        throw new UnsupportedOpcode("EORB 0xF8");
        break;
    }

    case 0xF9 : { // ADCB 
        opcode = "ADCB";
        throw new UnsupportedOpcode("ADCB 0xF9");
        break;
    }

    case 0xFA : { // ORB 
        opcode = "ORB";
        throw new UnsupportedOpcode("ORB 0xFA");
        break;
    }

    case 0xFB : { // ADDB 
        opcode = "ADDB";
        throw new UnsupportedOpcode("ADDB 0xFB");
        break;
    }

    case 0xFC : { // LDD 
        opcode = "LDD";
        throw new UnsupportedOpcode("LDD 0xFC");
        break;
    }

    case 0xFD : { // STD 
        opcode = "STD";
        throw new UnsupportedOpcode("STD 0xFD");
        break;
    }

    case 0xFE : { // LDU 
        opcode = "LDU";
        throw new UnsupportedOpcode("LDU 0xFE");
        break;
    }

    default: {
        break;
    }
    }
    
    return cycles;
}
