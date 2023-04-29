#include <iostream>
using namespace std;
#include <string>
// forward declaration of template class List

template<class T>
class List;

template<class T>
class Node
{
private:
	friend List<T>;
	T info;
	Node<T>* next;
public:
	// Methods…
	//Default Constructor:
	Node() 
	{
		info = 0;
		next = NULL;
	}
	//Parameterized Constructor:
	Node(T val) 
	{
		this->info = val;
		this->next = NULL;
	}
};

template<class T>
class List
{
private:
	Node<T>* head;
public:
	List()
	{
		head = NULL;
	}
	//~List()		//LOOP wala function chalaty waqat comment krna prta ha 
	//{
	//	Node<T>*toDelete = head;
	//	while (head) {
	//		//cout << "DELETING" << endl;
	//		toDelete = head;
	//		head = head->next;
	//		delete toDelete;

	//		//				OR
	//		//deleteAtHead();
	//	}
	//
	//}
	//Copy Constructor
	List(const List<T>& lhs) {		// rhs aana ha lhs ki jagah
		if (!lhs.head) {
			head = NULL;
			return;
		}
		else {
			Node<T>*temp = lhs.head;
			while (temp) {
				//Creating new node to hold data
				Node<T>*NewNode = new Node<T>(temp->info);
				if (this->head == NULL) {
					head = NewNode;
				}
				else {
					//inserting that node into newly created link list 
					this->insertAtTail(NewNode->info);
				}
				temp = temp->next;
			}
		}
	}



	void insertAtHead(T value) 
	{

		Node<T>*NewNode = new Node<T>(value);
		if (head == NULL) {
			head = NewNode;
			return;
		}
		else {

			NewNode->next = head;
			head = NewNode;
			return;
		}

		/*
		else {
			Node<T>*temp = head;
			while (temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
		}*/

	}
	void insertAtHead(Node<T>* newNode) 
	{
		if (head == NULL) {
			head = newNode;
			return;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}

	void insertAtTail(T value) 
	{
		Node<T>*NewNode = new Node<T>(value);
		if (head == NULL) {
			head = NewNode;
			return;
		}
		else  if (head != NULL) {
			Node<T>*temp = head;
			//traverse till end
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = NewNode;
		}
	}
	void insertAtTail(Node<T>* newNode) 
	{
		if (head == NULL) {
			head = newNode;
			return;
		}
		else  if (head != NULL) {
			Node<T>*temp = head;
			//traverse till end
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			//newNode->next = nullptr;
		}
	}
	bool deleteAtHead() 
	{
		if (head == NULL) {
			return false;
		}
		Node<T>*toDelete = head;
		head = head->next;
		delete toDelete;
		return true;
	}
	bool deleteAtTail() 
	{
		if (head==NULL)
		{
			return false;
		}
		else if (head != NULL) {
			if (head->next == NULL) {
				delete head;
				head = NULL;
				return true;
			}
			Node<T>*prev = nullptr;
			Node<T>*toDelete = head;
			while (toDelete->next)
			{
				prev = toDelete;
				toDelete = toDelete->next;
			}
			prev->next = nullptr;
			delete toDelete;
			return true;
		}
	}

	void printList() 
	{
		if (head == NULL) {
			cout << "List is Empty!" << endl;
		}
		//else if (head != NULL) 
		else{
			Node<T>*temp = head;
			cout << "Elements in List are: " << endl;
			while (temp) {

				cout << temp->info << " ";
				temp = temp->next;
			}

		}
	}
	Node<T>* search(T x) 
	{
		if (head = NULL) {
			return nullptr;
		}
		else if (head != NULL) {
			Node<T>*temp = head;
			while (temp)
			{
				if (temp->info==x) {
					Node<T>*pointer = temp;
					return pointer;
				}
				temp = temp->next;
			}
		}
		return nullptr;
	}

	bool insertAfter(T key, T value) 
	{
		if (head == NULL) {
			Node<T>*NewNode = new Node<T>(value);
			head = NewNode;
			return true;
		}
		else if (head != NULL) {
			Node<T>*temp = head;
			while (temp) {
				if (temp->info == key)
				{
					Node<T>*NewNode = new Node<T>(value);
					NewNode->next = temp->next;
					temp->next = NewNode;
					return true;
				}
				temp = temp->next;
			}
		}
	}

	bool insertBefore(T key, T value) 
	{
		if (head == NULL) {
			Node<T>*NewNode = new Node<T>(value);
			head = NewNode;
			return true;
		}
		else if (head != NULL) {
			Node<T>*prev = nullptr;
			Node<T>*temp = head;
			/*if (temp->next==NULL) {
				if (temp->info == key) {
				Node<T>*NewNode = new Node<T>(value);
				NewNode->next = temp;
				temp = NewNode;
				return true;
				}
			}*/
			while (temp->next) {
				//IF key is found at first node
				if (temp->info == key && temp == head) {
					Node<T>*NewNode = new Node<T>(value);
					NewNode->next = temp;
					head = NewNode;
					return true;
				}
				if (temp->info == key)
				{
					Node<T>*NewNode = new Node<T>(value);
					NewNode->next = prev->next;
					prev->next = NewNode;
					return true;
				}
				prev = temp;
				temp = temp->next;
			}
		}

	}

	int getLength() 
	{
		if (head == NULL) {
			return 0;
		}
		else if (head != NULL) {
			int count = 0;
			Node<T>*temp = head;
			while (temp)
			{
				count++;
				temp = temp->next;
			}
			return count;
		}
	}

	bool deleteBefore(T key) 
	{
		if (head==NULL)
		{
			return false;
		}
		else if (head != NULL) {
			Node<T>*prev = nullptr;
			Node<T>*toDelete = head;
			while (toDelete->next)
			{
				if (toDelete->info == key) {
					prev->next = toDelete->next;
					delete toDelete;
					return true;
				}
				prev = toDelete;
				toDelete = toDelete->next;
			}
		}
		return false;
	}

	bool deleteAfter(T key) 
	{
		if (head == NULL)
		{
			return false;
		}
		else if (head != NULL) {
		/*	Node<T>*prev = nullptr;*/
			Node<T>*temp = head;
			while (temp->next)
			{
				if (temp->info == key) {
					Node<T>*toDelete = temp->next;
					temp->next = toDelete->next;
					delete toDelete;
					return true;
				}
				temp = temp->next;
			}
		}
		return false;
	}

	bool deleteSeconLast()
	{
		if (head == NULL)
		{
			return false;
		}
		if (head != NULL && head->next==NULL)
		{
			return false;
		}
		if (head != NULL && head->next->next == NULL)
		{
			Node<T>*temp = head;
			head = head->next;
			delete temp;
			return true;
		}

		else if (head != NULL) {
			Node<T>*prev = nullptr;
			Node<T>*toDelete = head;
			while (toDelete->next)
			{
				if (toDelete->next->next == NULL) {
					prev->next = toDelete->next;
					delete toDelete;
					return true;
				}
				prev = toDelete;
				toDelete = toDelete->next;
			}
		}
		return false;
	}

	void compress() {
		if (!head) {
			cout << "LIST IS EMPTY!" << endl;
			return;
		}
		else {
			cout << "LIST 2 After Compressing: " << endl;
			Node<T>*temp = head;
			Node<T>*next;
			while (temp->next) 
			{	//Chekcing data of next node if same or not
				if (temp->info==temp->next->info) 
				{	//If data is same then skipping the pointer(next) to next pointer after same data node is found then deleting it
					next = temp->next->next;
					delete temp->next;
					temp->next = next;
				}
				else {//if data of Nodes isn't same then just skipping to next node 
					temp = temp->next;
				}

			}

		}


	}

	bool swap(int v1,int v2)
	{
		if (head == NULL)
		{
			return false;
		}
		if (v1 == v2) {
			return false;
		}
		if (head != NULL && head->next == NULL)
		{
			Node<T>*t1 = head;
			Node<T>*t2 = head->next;
			t1->next = nullptr;
			t2->next = t1;
			return true;
		}

		if (head != NULL && head->next->next == NULL)
		{
			Node<T>*t1 = head;
			Node<T>*t2 = head->next;
			Node<T>*tempX = t2->next;
			t2->next = t1;
			t1->next = tempX;
			head = t2;
			return true;
		}

		else{
			if (v1 == 1 || v2 == 1) {
				Node<T>*t1 = nullptr;
				Node<T>*t2 = nullptr;
				Node<T>*t3 = nullptr;
				Node<T>*t4 = nullptr;

				Node<T>* temp = head;
				int i = 1;
				if (v1 == 1) {
					t1 = nullptr;
					t2 = head;
					while (i != v2 - 1)
					{
						temp = temp->next;
						i++;
					}
					t3 = temp;
					t4 = temp->next;
				}
				i = 1;
				if (v2 == 1) {
					t1 = nullptr;
					t2 = head;
					while (i != v1 - 1)
					{
						temp = temp->next;
						i++;
					}
					t3 = temp;
					t4 = temp->next;
				}

				Node<T>*tempX = t4->next;
				head = t4;
				t4->next = t2->next;
				t3->next = t2;

				t2->next = tempX;

				return true;

			}

			Node<T>* temp = head;
			int i = 1;
			while (i != v1 - 1)
			{
				temp = temp->next;
				i++;
			}
			Node<T>*t1 = temp;
			Node<T>*t2 = temp->next;
			i = 1;
			temp = head;
			while (i != v2 - 1)
			{
				temp = temp->next;
				i++;
			}
			Node<T>*t3 = temp;
			Node<T>*t4 = temp->next;
			t1->next = t4;

			t3->next = t2;

			Node<T>* tempX = t4->next;
			t4->next = t2->next;
			t2->next = tempX;

			return true;
		}
		return false;
	}

	Node<T>* middleNode() {
		if (!head) {
			return NULL;
		}
		//if (head->next = nullptr) {
		//	return head;
		//}

		Node<T>* ptr1 = head;
		Node<T>* ptr2 = head->next;
		while (ptr2 && ptr2->next) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
		}
		cout << "MIDDLE NODE IS:" << ptr1->info;
		return ptr1;
	}

	bool reverse() {
		if (!head) {
			return false;
		}

		if (head->next==NULL) {
			Node<T>*t1 = head;
			Node<T>*t2 = head->next;
			Node<T>*tempX = t2->next;
			t2->next = t1;
			t1->next = tempX;
			return true;
		}
		if (head->next != NULL) {
			Node<T>*prev = head;
			Node<T>*curr = nullptr;
			Node<T>*lastToBe = head;

			head = head->next;


			while (head->next)
			{
			
				curr = head;

				head = head->next;
				Node<T>*temp = curr;
				curr->next = prev;
				prev = temp;
			}

			curr = head;
			Node<T>*temp = curr;
			curr->next = prev;
			prev = temp;


			lastToBe->next = NULL;
			return true;


		}
		return false;
	}
	void printReverse() {

		recursiveFunction(head);
		//cout << head->info;
	}

	void recursiveFunction(Node<T>*head) {
		//Node<T>*temp = head;
		//T val1 = head->info;
		if (!head) {
			return;
		}

		recursiveFunction(head->next);
		if (head) {
			cout << head->info << " ";
		}
	}

	bool isPalindrome() {
		string str1 = "";
		string str2 = "";
		recursivePalindromeFunction(head, str1, str2);
		if (str1 == str2)
		{
			return true;
		}
		else {
			return false;
		}
	}
	void recursivePalindromeFunction(Node<T>*head, string& s1, string& s2) {
		if (!head) {
			return;
		}
		s1 += to_string(head->info);
		recursivePalindromeFunction(head->next, s1, s2);
		if (head) {
			s2 += to_string(head->info);
		}

	}

	//List<T>& mergeLists(List<T>* l2) {
	//	if (!this->head && l2->head)
	//	{
	//		return l2->head;
	//	}
	//	if (this->head && !l2->head)
	//	{
	//		return this->head;
	//	}
	//	Node<T>*temp1 = this->head;
	//	Node<T>*temp2 = l2->head;
	//	List<T> list;
	//	while (temp1 && temp2)
	//	{
	//		if (temp1 != NULL) {
	//			list.insertAtTail(temp1->info);
	//		}
	//		if (temp2 != NULL) {
	//			list.insertAtTail(temp2->info);
	//		}

	//	}
	//	Node<T>*NewHead = list;
	//	return NewHead;


	//}

	void combine(List<T>& l1, List<T>& l2) {
		if (!l1.head && l2.head) {
			head = l2.head;
			l2.head = NULL;
		}
		else if (!l2.head && l1.head) {
			head = l1.head;
			l1.head = NULL;
		}
		else if (l1.head && l2.head) {
			head = l1.head;
			Node<T>* curr = head;
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = l2.head;
			l1.head = l2.head = NULL;
		}
	}

	void sortedMerge(List<T>& l1, List<T>& l2) {
		Node<T>* temp = nullptr;
		if (!l1.head && l2.head) {
			head = l2.head;
			l2.head = NULL;
		}
		else if (!l2.head && l1.head) {
			head = l1.head;
			l1.head = NULL;
		}
		else if (l1.head && l2.head) {

			Node<T>* curr1 = NULL;
			Node<T>* curr2 = NULL;

			if (l1.head->info < l2.head->info)
			{
				//Node<T>* NewHead = new Node<T>(l1.head->info);
				/*head = NewHead;*/
				head = l1.head;
				curr1 = l1.head->next;
				curr2 = l2.head;
				//NewHead = l1.head;
				//curr1 = l1.head;
				//curr2 = l2.head;
			}
			if(l2.head->info < l1.head->info){
				head = l2.head;
				curr1 = l2.head->next;
				curr2 = l1.head;
				/*curr1 = l1.head;*/
				//curr1 = l2.head;
				//curr2 = l1.head;
			}
			temp = head;

			while (curr1 && curr2 )
			{
				if (curr1->info < curr2->info) {
					temp->next = curr1;
					temp = temp->next;
					curr1 = curr1->next;
					if (curr1==nullptr)
					{
						temp->next = curr2;

					}

				}
				else if (curr2->info < curr1->info) {
					temp->next = curr2;
					temp = temp->next;
					curr2 = curr2->next;
					if (curr2 == nullptr)
					{
						temp->next = curr1;

					}


				}

			}

			l1.head = l2.head = NULL;
		}
	}

	//void createLoop() {
	//	Node<T>*temp = head;
	//	Node<T>*tempX = head;
	//	while (temp->info != 10)
	//	{
	//		temp = temp->next;
	//	}
	//	while (tempX->info != 4) {
	//		tempX = tempX->next;
	//	}
	//	temp->next = tempX;
	//}

	bool loopExistsOrNot() {
		if (!head)
		{
			return false;
		}
		if (head && head->next == nullptr) {
			return false;
		}
		if (head && head->next->next != nullptr) {
			if (head->next->next == head)
			{
				return true;
			}
		}

		Node<T>* ptr1 = head;
		Node<T>* ptr2 = head;
		while (ptr1 != nullptr && ptr1->next != nullptr && ptr2 != nullptr && ptr2->next != nullptr && ptr2->next->next != nullptr)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
			if (ptr1 == ptr2)
			{
				return true;
			}

		}
		return false;

	}
};



int main()
{
	List<int> list;

	// Inserting nodes
	//list.insertAtHead(4);
	//list.insertAtHead(3);
	//list.insertAtHead(2);
	//list.insertAtHead(1);
	
	//List<int> listS;

	// //Inserting nodes
	//listS.insertAtHead(4);
	//listS.insertAtHead(3);
	//listS.insertAtHead(2);
	//listS.insertAtHead(1);
	//
	
	//list.insertAtHead(1);
	//list.insertAtHead(2);
	//list.insertAtHead(3);
	//list.insertAtHead(4);
	//list.insertAtHead(5);
	//list.insertAtHead(6);
	//list.insertAtHead(7);
	//list.insertAtHead(8);
	//list.insertAtHead(9);
	//list.insertAtHead(10);
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.insertAtTail(6);
	list.insertAtTail(7);
	list.insertAtTail(8);
	list.insertAtTail(9);
	list.insertAtTail(10);
	/*list.printList();*/
	cout << endl;
	bool isLoop = list.loopExistsOrNot();
	if (isLoop)
	{
		cout << "Loop Exists!" << endl;
	}
	else {
		cout << "Loop Does Not Exist!" << endl;
	}

	//list.insertAtHead(6);
	//list.insertAtHead(7);
	//list.insertAtHead(8);
	//list.insertAtHead(9);
	//list.insertAtHead(10);


	//list.insertAtTail(5);
	//list.insertAtTail(6);
	//list.insertAtTail(7);
	//list.insertAtTail(8);
	//list.insertAtTail(9);
	//list.insertAtTail(10);


	
	//list.printList();
	//cout << endl;

	//Node<int>*ptr = list.middleNode();
	//
	//cout << endl;

	//bool isReversed=list.reverse();
	//if (isReversed) {
	//	cout << "Reversed List is:" << endl;
	//	list.printList();
	//}
	//else {
	//	cout << "Can't be reversed" << endl;
	//}

	//cout << endl;

	//list.printReverse();

	cout << endl;

	List<char> list2;
	list2.insertAtTail('h');
	list2.insertAtTail('a');
	list2.insertAtTail('n');
	list2.insertAtTail('n');
	list2.insertAtTail('a');
	list2.insertAtTail('h');

	bool check = list2.isPalindrome();
	if (check) {
		cout << "List is Palindrome" << endl;
	}
	else {
		cout << "List is Not Palindrome" << endl;
	}

	//cout << endl;
	//List<int> list3;
	//list3.insertAtTail('1');
	//list3.insertAtTail('0');
	//list3.insertAtTail('3');
	//list3.insertAtTail('2');
	//list3.insertAtTail('1');
	//bool checkX = list3.isPalindrome();
	//if (checkX) {
	//	cout << "List is Palindrome" << endl;
	//}
	//else {
	//	cout << "List is Not Palindrome" << endl;
	//}

	cout << endl;
	List<int> listX;
	List<int> listY;
	listX.insertAtTail(2);
	listX.insertAtTail(4);
	listX.insertAtTail(6);
	listX.insertAtTail(8);
	listX.insertAtTail(10);

	listY.insertAtTail(1);
	listY.insertAtTail(3);
	listY.insertAtTail(5);
	listY.insertAtTail(7);
	listY.insertAtTail(9);

	//------------------------------------

	//listX.insertAtTail(4);
	//listX.insertAtTail(7);
	//listX.insertAtTail(10);
	//listX.insertAtTail(12);
	//listX.insertAtTail(14);

	//listY.insertAtTail(1);
	//listY.insertAtTail(3);
	//listY.insertAtTail(6);
	//listY.insertAtTail(8);
	//listY.insertAtTail(9);
	//listY.insertAtTail(15);

	//------------------------------------
	/*List<int> listZ = listX.mergeLists(&listY);
	cout << endl;
	listZ.printList();
	*/
	List<int> listZ;
	//listZ.combine(listX, listY);
	cout << endl;
	//cout << "After Combining:" << endl;
	//listZ.printList();
	//cout << endl;
	cout << "--------------------" << endl;
	List<int> listM;
	listM.sortedMerge(listX, listY);
	cout << endl;
	cout << "After Merging:" << endl;
	listM.printList();


	/*cout << "Address of middle node of link list is:" << endl;*/


	//List<int> list;
	//// Inserting nodes
	//list.insertAtHead(4);
	//list.insertAtHead(3);
	//list.insertAtHead(2);
	//list.insertAtHead(1);
	//list.insertAtTail(5);
	//list.insertAtTail(6);
	//list.insertAtTail(7);
	//list.insertAtTail(8);

	//list.printList();
	//
	//bool status=list.deleteSeconLast();
	//if (status)
	//{
	//	cout << "After Deleting Second Last List is:" << endl;
	//	list.printList();
	//}
	//else {
	//	cout << "Second Last cannot be deleted!" << endl;
	//}

	//--------------------------------- SWAP ----------------------------------


	//List<char> charlist;
	//// Inserting nodes
	//charlist.insertAtTail('a');
	//charlist.insertAtTail('b');
	//charlist.insertAtTail('c');
	//charlist.insertAtTail('d');
	//charlist.insertAtTail('e');
	//charlist.insertAtTail('f');
	////charlist.insertAtTail('f');
	////charlist.insertAtTail('g');
	////charlist.insertAtTail('h');
	//
	//charlist.printList();

	//bool status1 = charlist.swap(4,1);
	//if (status1)
	//{
	//	cout << "After Swap List is:" << endl;
	//	charlist.printList();
	//}
	//else {
	//	cout << "Not Swapped!" << endl;
	//}
	/*list.printList();*/

	/*Node<int>*NewNode = new Node<int>(0);
	list.insertAtHead(NewNode);
	cout << endl;
	list.printList();

	Node<int>*NewNode1 = new Node<int>(9);
	list.insertAtTail(NewNode1);
	cout << endl;
	list.printList();

	bool isDeleted = list.deleteAtHead();
	if (isDeleted) {
		cout << "After Deleting Head, LinkList is: " << endl;
		list.printList();
	}
	if (!isDeleted) {
		cout << "List is Empty!" << endl;
	}
	

	cout << endl;
	bool isDeleted1 = list.deleteAtTail();
	if (isDeleted1) {
		cout << "After Deleting Head, LinkList is: " << endl;
		list.printList();
	}
	if (!isDeleted1) {
		cout << "List is Empty!" << endl;
	}
	
	list.insertAfter(5, 15);
	cout << endl;
	list.printList();

	list.insertAfter(9, 10);
	cout << endl;
	list.printList();


	list.insertBefore(5, 51);
	cout << endl;
	list.printList();

	list.insertBefore(9, 91);
	cout << endl;
	list.printList();


	list.insertBefore(0, -1);
	cout << endl;
	list.printList();

	
	list.deleteAtTail();
	cout << endl;
	list.printList();

	list.deleteAtHead();
	cout << endl;
	list.printList();
*/

	/*
	List<int> list2;
	// Inserting nodes
	list2.insertAtTail(1);
	
	list2.insertAtTail(2);
	list2.insertAtTail(2);
	list2.insertAtTail(3);
	list2.insertAtTail(3);
	list2.insertAtTail(4);
	list2.insertAtTail(4);
	list2.insertAtTail(4);
	list2.insertAtTail(5);
	list2.insertAtTail(5);
	list2.insertAtTail(5);
	list2.insertAtTail(6);
	//Compressing List
	list2.compress();
	
	list2.printList();

	List<int> list3(list);
	cout << "LIST CREATED FROm COPY CONSTRUCTOR:-" << endl;
	list3.printList();
	*/

	return 0;

}
