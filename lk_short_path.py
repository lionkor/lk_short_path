#!/bin/python3.8

import os

path = os.getcwd()
_HOME = os.getenv("HOME")

if path.startswith(_HOME):
    path = path.replace(_HOME, "~")

result = ""
if not path.startswith("~"):
    result += "/" # prefix path with root
for part in path.split('/'):
    if not path.endswith(part):
        result += part[0:1]
        result += '/'
    else:
        result += part

print(result, end='')
