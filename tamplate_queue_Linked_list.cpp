//Template_Queue_LinkedList
#include <iostream>
#include "Template_Node_SLL.cpp"
using namespace std;
template <typename T>
class queue
{
	private:
		Node <T> * front;
		Node <T> * end;
		int size;
		
	public:
		queue()
		{
		  this->front = this->end = NULL;
			this->size = 0;
			}
		
		~queue() { delete front;
				   delete end;	}
	 int sizeOfQueue() { return this->size;		}
	 bool isEmpty() {return (front == NULL && end == NULL && size == 0);	 }
	 T peak() { return this->front->getData();	 }
	 void push(T x)	
	  { 
	  	if (front == NULL || end == NULL || size == 0)	 
	  	{
		  Node<T> * newNode  = new Node<T>();
		  newNode->setData(x);
		  newNode->setNext(NULL);
		  front = newNode;
		  end = newNode;
		  size++;
		  }
		  else
		  {
		  		Node<T> * newNode  = new Node<T>();
		  		newNode->setData(x);
		  		newNode->setNext(NULL);
		  		end->setNext(newNode);
		  		end = newNode;
		  		size++;
		  }
	 }
	 T pop()
	 {	
	 	T x;
	 	if (front == NULL || end == NULL || size == 0)
	 	{
	 	cout << "\nQueue is empty....\n"; 
		 return 0 ;
		  }
		  else
		  {	
		  	
		  	if (front == end && front != NULL && end !=NULL) // if queue has only one element and that need to be popped.
		  	   {
		  	   		  x = front->getData();
		  	   		  front = NULL;
		  	   		  end = NULL;
		  	   		  size--;
		  	   		  return x;
				 }
			 else
			 {
			  	 x = front->getData();
			  	 front = front->getNext();
			  	 size--;
			  	 return x;
			 	
			 }

			  }	
		  }
};


int main()
{
	
	queue<double> myQueue;
	for (int i =0; i<10; i++)
	myQueue.push(i*(i+1.123456789));
	cout <<"the size of the queue is : " << myQueue.sizeOfQueue() << endl;
	cout << "the element : "<< myQueue.pop() << endl;
	cout << "the element : "<< myQueue.pop() << endl;
	cout << "the element : "<< myQueue.pop() << endl;
	cout << "the element : "<< myQueue.pop() << endl;
	cout << "the element : "<< myQueue.pop() << endl;
	cout <<"the size of the queue is : " << myQueue.sizeOfQueue() << endl;
	cout << endl << "the front element is : " << myQueue.peak();
}
