#!/usr/bin/env python3.7

import logging
import sys
from enum import Enum, auto


logger = logging.getLogger('6809asm')


class Tokens(Enum):
    COMMENT = auto()
    LABEL = auto()
    RMB = auto()
    EQU = auto()
    ORG = auto()
    PAG = auto()

class Node:
    pass

token_map = {
    
}

if __name__=='__main__':
    logging.basicConfig(level=logging.DEBUG)

    file = sys.argv[1]

    logger.info(f'Starting 6809 assembler on "{file}"')

    with open(file, 'r') as fh:
        all_lines = [line.rstrip() for line in fh.readlines()]

    logger.info(f"Total lines: {len(all_lines)}")

    # Pass One, convert to ASL
    symbol_table = {}

    for line, text in enumerate(all_lines):
        lineno = 1+line

        parts = []

        if text.strip() == '':
            continue # This is a blank line

        if text[0] == '*':
            continue # This is a comment

        pieces = text.split(maxsplit=3)
        piece  = 0

        if text[0] != ' ' and text[0] != '\t':
            parts.append((Tokens.LABEL, pieces[piece]))
            piece+=1
        
        cmd = pieces[piece]
        if cmd == 'RMB':
            parts.append((Tokens.RMB, pieces[piece+1]))
        
        if cmd == 'EQU':
            parts.append((Tokens.EQU, pieces[piece+1]))
            
        if cmd == 'ORG':
            parts.append((Tokens.ORG, pieces[piece+1]))
            
        if cmd == 'PAG':
            parts.append(Tokens.PAG)
        
        print(lineno, '-', parts, ':', text)


        
