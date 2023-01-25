// A1_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "Alberto.h"

#include <iostream>
#include "queue.h"

void Wrapper()
{
    // Creating a new queue
    Queue<int> queueInt = Queue<int>();

    // First queue
    cout << "\n\nInt Queue: \n";
    // Pushing values to the queue
    queueInt.Push(3);
    queueInt.Push(5);
    queueInt.Push(-12);
    queueInt.Push(2);
    queueInt.Push(0);

    // Printing the queue
    cout << endl;
    queueInt.Print();
    cout << endl;

    // Popping values off the queue
    queueInt.Pop();
    queueInt.Pop();

    // Printing the queue
    cout << endl;
    queueInt.Print();
    cout << endl;

   
    



    // New Copied Queue
    cout << "Copied Queue: \n";
    Queue<int> newQueue = queueInt;

    // Printing the queue
    cout << endl;
    newQueue.Print();
    cout << endl;

    // Popping values off the queue
    newQueue.Pop();
    newQueue.Pop();

    // Printing the queue
    cout << endl;
    newQueue.Print();
    cout << endl;

    // New Copy Assignment Queue
    cout << "Assigned Queue: \n";
    /*newStack = queueInt;

    // Printing the queue
    cout << endl;
    newQueue.Print();
    cout << endl;*/
}

int main()
{
    Wrapper();
    _CrtDumpMemoryLeaks();
    return 0;
}

