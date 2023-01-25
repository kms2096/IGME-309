#pragma once
#include <iostream>
using namespace std;
template <class T>

class Queue
{
private:
	int count;				// How many items the array has in it
	T* array;				// A pointer to the items in the invetory

public:
	Queue()
	{
		// Put your constructor code here
		count = 0;
		array = new T[2];
		array[1] = NULL;

		cout << "Queue created" << endl;
	}

	// Copy constructor
	Queue(const Queue& newArray)
	{
		count = newArray.count;
		array = new T[count];

		// Copying all of the elements of the new array into the current one
		for (int i = 0; i < count; i++)
		{
			array[i] = newArray.array[i];
		}

		cout << "Queue copied" << endl;
	}

	// Copy Assignment Operator
	Queue& operator=(const Queue& newArray)
	{
		// Returns the array if it is this array
		if (this == &newArray)
		{
			return *this;
		}

		// Deleting the array if it already exists
		if (array != nullptr)
		{
			delete array;
			array = nullptr;
		}

		count = newArray.count;
		array = new T[count];

		copy(newArray.array, newArray.array + newArray.count, array);

		return *this;
	}

	// Destructor
	~Queue()
	{
		delete array;
		array = nullptr;

		cout << "Queue deleted" << endl;
	}

	// Sorting 
	void SortQueue()
	{
		if (IsEmpty())
		{
			return;
		}

		for (int i = count - 1; i > -1; i--)
		{
			for (int j = count - 1; j > -1; j--)
			{
				if (array[i] > array[j])
				{
					swap(array[j], array[i]);
				}
			}
		}
	}

	// Method that can add information to your queue
	void Push(T value)
	{
		// Resizes the array if it is not long enough
		if (array[count] == 0)
		{
			// Creating a new array
			T* tempArray = array;
			array = new T[(count + 1) * 2];
			array[(count * 2) + 1] = 0;

			// Copy the entire temporary array to the new one
			for (int i = 0; i < count; i++)
			{
				array[i] = tempArray[i];
			}

			// Deleting the temp array
			delete tempArray;
			tempArray = nullptr;
		}

		// Assigning the new value to the first spot in the array
		array[count] = value;

		count++;

		SortQueue();

		cout << "Enqueue: " << value << endl;
	}

	// This method returns the last element that was added to the queue
	T Pop()
	{
		// Returns nothing if the stack is empty
		if (IsEmpty())
		{
			cout << "The queue is empty\n";
			return NULL;
		}

		// Temp variable to store the value before it is deleted
		T temp = array[0];
		cout << "Dequeue: " << temp << endl;

		for (int i = 0; i <= count; i++)
		{
			if (i == count)
			{
				array[count] = NULL;
			}

			array[i] = array[i + 1];
		}

		count--;

		return temp;
	}

	// This method will print all of the elements of your queue to the console.
	void Print()
	{
		// Returns early if the queue is empty
		if (count == 0)
		{
			cout << "The queue is empty\n";
			return;
		}

		// Prints out all of the items in the queue
		for (int i = 0; i <= count - 1; i++)
		{
			cout << array[i] << " \n";
		}
	}

	// This method returns the number of elements currently stored in the underlying array
	int GetSize()
	{
		return count;
	}

	// This method should return true or false depending on if any data is currently stored in the queue.
	bool IsEmpty()
	{
		if (count <= 0)
		{
			return true;
		}

		return false;
	}
};
