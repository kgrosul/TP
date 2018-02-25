#!/bin/bash
g++ -std=c++11 main.cpp run.cpp makepizza.cpp otherfood.cpp pizza.cpp -lgtest -pthread -lgtest_main -L/usr/lib/
