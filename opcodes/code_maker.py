#!/usr/bin/env python

import re

mc6809 = []
hc6309 = []

def main():

    print "switch(opcode) {"

    with file('6309Opcodes.txt', 'r') as the_file:
        for the_line in the_file:

            line_stripped = the_line.strip()

            if line_stripped.startswith('#'):
                continue

            if not line_stripped:
                continue

            hconly = line_stripped.startswith('*')
            if hconly:
                line_stripped = line_stripped[1:].strip()

            opnum = re.compile(r"([\d|A|B|C|D|E|F]+)\s+([\w|/]+)\s+")
            numm = opnum.search(line_stripped)

            opcode = int(numm.group(1),16)

            if opcode <= 0xFF:
                print "    case 0x%0.2X : break;" % opcode


    print "    case default: {"
    print "        break;"
    print "    }"
    print "}"

if __name__ == "__main__":
    main()
