//John Maurer
//Stack - A special data structure that stores integers and retieves them in a first in, last out method (Like stacking plates)

#pragma once
#include <string> //Used to provide a nice printing format

class Stack
{
	//Initialize private fields
private:
	int capacity;
	int stackPointer;
	int* stack;

	//Initialize public members
public:
	//Constructor, requires a maximum size in order to instantiate the array 
	Stack(int capacity)
	{
		//Store maximum size into 'capacity'
		this->capacity = capacity;

		//Initialize the stack pointer to start at 0
		stackPointer = 0;

		//Instantiate the array
		stack = new int[capacity];
	}

	//Function, pushes data into the the stack and moves the pointer up one unit
	void push(int data)
	{
		//Determine if the stack pointer has reached the capacity of the array
		if (stackPointer < capacity)
		{
			//Store the data at the location of the pointer, then move the pointer to the next spot
			stack[stackPointer] = data;
			stackPointer++;
		}
		else
		{
			//Throw an exception
			throw "Stack overflow! The stack pointer has exceeded the size of the stack.";
		}
	}

	//Function, returns the data that was last inserted into the stack
	int pop()
	{
		//Determine if the stack pointer has reached the bottom of the stack
		if (stackPointer > 0)
		{
			//Move the pointer down, then return the data at that point in the stack
			stackPointer--;
			return stack[stackPointer];
		}
		else
		{
			//Throw an exception
			throw "Stack underflow! the stack pointer has fallen through the floor of the stack.";
		}
	}

	//Function, returns the size of the stack, which is the number of data currently within the stack, NOT its max capacity
	int getSize()
	{
		//Return stack pointer, which tells how many pieces of data are in the stack
		return stackPointer;
	}

	//Function, returns a C++ string that nicely formats the contents of stack in a printable manner
	std::string toString()
	{
		//Initialize the string
		std::string finalString = "Contents of the stack:\n";

		//Append the members of the stack to the string, from top to bottom
		for (int i = stackPointer - 1; i >= 0; i--)
		{
			finalString += std::to_string(stack[i]) + "\n";
		}

		//Return the final string
		return finalString;
	}
};
