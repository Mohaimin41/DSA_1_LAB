Stack.h         : Holds generic stack ADT as a virtual base class
ArrStack.h      : Implements generic stack ADT by inheriting stack using array
LinkedStack.h   : Implements generic stack ADT by inheriting stack using linked list
main.cpp        : Uses ArrStack/LinkedStack to demonstrate stack operations
dishwasher.cpp  : Uses ArrStack/LinkedStack to simulate a dishwasher system

Please compile with this command: g++ -fpermissive ./main.cpp -o ./main.exe
                                g++ -fpermissive ./dishwasher.cpp -o ./dishwasher.exe