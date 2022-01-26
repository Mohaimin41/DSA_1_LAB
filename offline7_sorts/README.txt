Please use this command to compile:
g++ --std=c++14 -g -O3 -fdiagnostics-color=always "-Wl,--stack,16777216" .\main.cpp -o <exe file name>

We are setting stack size to 16 MiB here, otherwise sorting 100000 numbers won't be possible