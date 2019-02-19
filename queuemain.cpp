#include<iostream>
#include"queuearray.h"
using namespace std;

int main()
{
	Queue <int> q;
	int elem, choice;
	
	do
	{
		
	system("cls");
	cout<<"1. Push"<<endl;
	cout<<"2. Size"<<endl;
	cout<<"3. Front"<<endl;
	cout<<"4. Pop"<<endl;
		
	cin>>choice;
	
	switch(choice)
	{
		case 1:  	cin>>elem;
					q.Push(elem);
				 	break;
		
		case 2: 	cout<<q.size();
					break;
					
		case 3: 	cout<<q.Front();
					break;
					
		case 4:		q.Pop();
					break;
					
	}
	
	cout<<"Again?";
	cin>>choice;
	
	}while(choice!=0);
	
}
