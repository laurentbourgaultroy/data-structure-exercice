Data Structure Exercise
=======================

I coded this program as a refresher on C data-structure. You can use it as an example if you need a refresh yourself -it's easy to get spoiled by higher level languages. This code may contains nasty bugs, copy-paste at your own peril. 

The project use modern practices of software development: a fully automated build, unit tests, static code analysis, and leak detection using valgrind. Poke in the Makefile if you are curious how those have been applied to a C program.

# What's in it

Right now, a resizable vector and a bunch of tests.

Future plan -not in it right now- include an old-fashion linked list, a hash map, a heap, and maybe some more exotic data structures like a rope.

# How to build

You will need the standard GNU C toolchain: make, gcc and the like. [Valgrind](http://valgrind.org) is required for the leak detection part. The project require a Unix-like environment. Building it on Windows may be very hard.

Check the OS specific detail below to install the prerequisite. Then run good-ol `make` in the source directory to build.

## On Mac OS X, 

Install the XCode Command-Line tools. You can also install them from XCode directly, but an easier way to get them is to install the [homebrew](http://brew.sh) package manager. The homebrew installer will install them itself. Using that later option will let you install the other tools easily. 

Install [Valgrind](http://valgrind.org). You can compile it from source, or use homebrew: `brew install valgrind`

*Note* The homebrew version of valgrind sometime trail with support for the latest version of Mac OS X. If you get error messages about an unsupported version of OS X, use `brew install --HEAD valgrind` to install the latest dev version of valgrind. Be careful, that version may be instable.

##Linux 

This program was not tested on Linux, but should compile and run without problems. The required tools are usually in a "build-essential" package or equivalent. Install them with your package manager. On Ubuntu: `apt-get install build-essential`. 

You will need valgrind, available on most package manager. On Ubuntu: `apt-get install valgrind`. You can also compile it from source.

# Licence 

This is public domain, use that project however you want. Full text below for the lawyers.

> This is free and unencumbered software released into the public domain.
>
> Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.
>
> In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
>
> For more information, please refer to [http://unlicense.org/](http://unlicense.org/)
