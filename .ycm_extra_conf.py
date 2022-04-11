import os
import os.path
import fnmatch
import logging
import ycm_core
import re

CFLAGS = ["-Wall", "-Wextra", "-Werror", "-std=c++98", "-I./ex**"]
SRCS_EXT = [".cpp"]
HEADER_EXT = [".hpp"]

def Settings(**kwargs):
    return {
            "flags": CFLAGS
            }
