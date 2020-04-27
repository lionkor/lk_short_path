# lk_short_path

A simple tool to displaying the current directory as a "short path".

## Examples

`/home/lion/src/myproj` → `~/s/myproj`

`/etc/systemd/network` → `/e/s/network`

I personally use this for my shell's prompt (which is why I made it)! 
Example of usage in a simple bash prompt:

`~/s/d/src $ `

*See ".bashrc" section below for the code for this prompt!*

## Why

This helps with discerning between same named folders in different directories:
Say you have two shells open, one in `~/src/gameengine/include` and one in `~/src/website/include`, you can quickly see which one you are in without wasting screen space on the full path:

`~/s/g/include`

versus

`~/s/w/include`

The idea is to create a middleground between only showing the basename (in this example `include`) and the full path, which may get quite long!

## Boring Details
How it works

1. Use the env var `HOME` and replace that part of the path (if it exists) with `~`.
2. Shorten all parts of the path to their first letter, except the last one.
3. Append the last one in full. 

## .bashrc

You can use this in your bash prompt to make it look like this:

Example with path `~/src/game/Core/src`:

`~/s/g/C/src $ `

.bashrc:
```bash
export PS1="\[\033[32m\]\$(lk_short_path)\[\033[00m\] \$ "
```
