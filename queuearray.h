#include<iostream>
using namespace std;

/*Implementation of Queue as Array.
Code by Utkarsh Agrawal.
Please suggest edits wherever possible. */

template <typename T>
class Queue{
	
	T *arr;				//pointer to a dynamically allocated array
	int capacity;		// max capacity of queue
	int tail;			
	int head;
	
  public:
  	
  	Queue(): arr(new T[100]), capacity(100), tail(-1), head(-1)		//initialisation list, constructor
  	{}
  	
  	void Push(T elem)			//pushes new element in Queue
  	{
  		if(tail == -1)			//empty queue
  		{
  			tail= head = 0;
  			arr[0]= elem;
			return;	
		}
		
  		if(tail==capacity-1 && head==0 || head - tail == 1)		//full queue
		{
		  	capacity*=2;
		  	T *ptr =new T[capacity];
		  	int k=0;
		  	
		  	for(int i=head; i<=tail; i++)
		  		ptr[k++]=arr[i];
		  	
		  	ptr[k]=elem;
		  	tail=k;
		  	
		  	delete [] arr;
		  	arr=ptr;
		  	return;
		}	
		  
		if( tail == capacity-1 && head!=0)		//space optimization
		{
			tail=0;
			arr[tail]=elem;
			return;	
		} 
		
		
		  arr[++tail]=elem;			
		  
	}
	
	
	void Pop()				//removes element from queue
	{
		if(head==-1)			//empty queue
			return;
			
		if(head == tail)			//only 1 element in queue
		{
			head=tail=-1;
			return;
		}
		
		head++;
	}
	
	
	T Front()		//returns front element of queue
	{
		if(tail == -1)			//empty queue
			return -9999;
			
		return arr[head];		
	}
	
	int size()				//return size of queue
	{
		if(tail==-1)		//empty queue
			return 0;
		
		if(tail>=head)
		return (tail-head+1);
		
		return tail+ capacity-head +1;
	}
	
	~Queue()				//destructor
	{
		cout<<"Deleting Queue";
		delete [] arr;
	}
		
};

