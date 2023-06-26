#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# C++ Plus Include Language Formatter

# See 'language_format.txt'

import sys
import logging
import os

# Get logger and init
LOGFILE = "ilang.log"
logger = logging.getLogger()
logger.setLevel(logging.NOTSET)
log_handler = logging.FileHandler(LOGFILE, encoding="utf-8")
log_handler.setLevel(logging.NOTSET)
log_formatter = logging.Formatter("[%(asctime)s %(name)s %(levelname)s] %(message)s")
log_handler.setFormatter(log_formatter)
log_console = logging.StreamHandler(sys.stderr)
log_console.setLevel(logging.NOTSET)
log_console.setFormatter(log_formatter)
logger.addHandler(log_handler)
logger.addHandler(log_console)

class Unit:
    """
    
    Language format unit
    
    """
    
    def __init__(self, id:str, code:str):
        """
        
        Create a language format unit.

        Args:
            id (str): unit id
            code (str): unit code
        """
        self.id = id
        self.code = code
    
    def __eq__(self, value: object) -> bool:
        """
        
        Compare self and other Unit object

        Args:
            value (Unit): other Unit object
        """
        return self.id == value.id
    
    def __hash__(self) -> int:
        """
        
        Get Unit object hash

        Returns:
            int: hash data
        """
        return hash(self.id)

# Format unit list
format_units = set()

def read_format(path:str):
    """
    
    Read format units list from a ilang file.

    Args:
        path (str): file path
    """
    global format_units
    
    with open(path, encoding="utf-8") as source_file:
        _unit_flag = False
        _unit_id = ""
        _unit_code = ""
        for line in source_file:
            line = line.rstrip()
            
            if line:
                if line.startswith("#"):
                    # Ignore this line
                    continue
                elif line.startswith("```"):
                    if _unit_flag:
                        # Insert this unit to units list
                        logger.info("Add unit <%s>", _unit_id)
                        logger.debug(_unit_code)
                        unit = Unit(_unit_id, _unit_code.strip())
                        format_units.add(unit)
                        # End unit code reading and clean cache
                        _unit_flag = False
                        _unit_id = ""
                        _unit_code = ""
                    else:
                        # Format unit start
                        _unit_flag = True
                        # Read unit id
                        _unit_id = line[len("```"):]
                else:
                    # Unit code or unexpected junk
                    if _unit_flag:
                        _unit_code += line + "\n"
                    else:
                        logger.fatal("Unexpected junk")
                        raise ValueError("Read unit file error:", "Unexpected junk in '", line, "'")

def get_file_list(path:str):
    """
    
    Get file list.

    Args:
        path (str): directory path
    """
    def _recurse(path:str, cache:list):
        for file_path in os.listdir(path):
            file_path = os.path.join(path, file_path)
            if os.path.isdir(file_path):
                _recurse(file_path, cache)
            else:
                cache.append(file_path)
    cache = []
    _recurse(path, cache)
    return cache

def main(args:list[str]):
    """
    
    Program main.

    Args:
        args (list[str]): args
    """
    logger.info("C++ Plus Include Language Formatter started with args = %s", str(args))
    read_format("lang/en_us.ilang")

if __name__ == "__main__":
    main(sys.argv)
