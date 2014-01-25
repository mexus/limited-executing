limited-executing
=================

A little framework to execute tasks in a multiple threads with restriction
on a "server" limits (e.g. each server can handle only certain
ammount of connections).


Requirements
============

1. CMake to build tests.
2. Some C++11 functionality used (shared pointers, variadic templates, c++11 initializations), so C++11 compliant compiler required.

Tested with gcc 4.8.2, linux kernel 3.12.6-1-ARCH (x86_64), cmake 2.8.12.1.


Building
========

To build a test project go to "build" folder and execute

% cmake ..

% make


Using
=====

See usage at test/ folder

