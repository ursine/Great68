#!/usr/bin/env python3.7

import logging
import sys

logger = logging.getLogger('6809asm')

if __name__=='__main__':
    logging.basicConfig(level=logging.DEBUG)

    file = sys.argv[1]

    logger.info(f'Starting 6809 assembler on "{file}"')

    with open(file, 'r') as fh:
        all_lines = [line.rstrip() for line in fh.readlines()]

    logger.info(f"Total lines: {len(all_lines)}")

    # Pass One, convert to ASL

    for line in all_lines:
        print(line)

