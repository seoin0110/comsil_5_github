#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template<typename T>
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){
		  data = element; //data에 element 대입
		  link = 0; //link는 NULL
		}
	};

//LinkedList Class
template<typename T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size; //LinkedList의 크기
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0; //첫번째 원소 주소 초기화
			current_size = 0; //LinkedList 크기 초기화
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size; //LinkedList의 크기 즉, 노드 개수 리턴
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element); //맨 앞 원소 삽입 
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element); //맨 뒤 원소 삭제 (QUEUE와 같은 구조)

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template<typename T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first; //새노드가 가르키는게 first
	first = newnode; //첫번째 노드의 주소에 newnode 포인터를 대입
	current_size++; //하나의 노드를 추가함으로써 size 1증가
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template<typename T>
bool LinkedList<T>::Delete(T &element){

	if (first == 0) //첫번째 노드가 없으면 false반환
		return false;
	
	Node<T> *current = first; //첫번째 노드의 주소를 저장함
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link; 
	}
	element = current -> data; //마지막 노드의 데이터
	delete current; //마지막 노드 제거
	current_size--; //제거했으므로 size하나 감소

	return true; //제거에 성공했으므로 true반환
}

//리스트를 출력하는 Print 함수
template<typename T>
void LinkedList<T>::Print(){
	Node<T> *i; 
	int index = 1; //인덱스에 1대입

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){ //첫번째 노드부터 마지막 노드까지 반복
			if (index == current_size){ //마지막 노드일 때
				cout << "[" << index << "|";
				cout << i -> data <<"]"; //대괄호 닫음
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->"; //계속 이어짐 "->"로 연결
				index++;
			}
		}
		cout << endl;
	}

}


#endif
