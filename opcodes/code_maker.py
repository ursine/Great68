#!/usr/bin/env python

import re

mc6809 = {}
hc6309 = {}

mc6809_10 = {}
hc6309_10 = {}

mc6809_11 = {}
hc6309_11 = {}

def main():

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
            opname = numm.group(2)

            if opcode <= 0xFF:
                if not hconly:
                    mc6809[opcode] = (opcode, opname)
                hc6309[opcode] = (opcode, opname)

    print "switch(opcode) {"
    print

    for opcode in xrange(0,0xFF):
        opstr = "0x%0.2X" % opcode

        support = "Unknown"
        opname = "INVALID"
        if (opcode in mc6809):
            support = "Unsupported"
            opname = mc6809[opcode][1]

        print
        print "    case %s : { // %s " % (opstr,opname)
        print "        abort(\"%s opcode %s\");" % (support,opstr)
        print "        break;"
        print "    }"



    print "    case default: {"
    print "        break;"
    print "    }"
    print "}"

if __name__ == "__main__":
    main()
