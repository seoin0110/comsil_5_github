#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함
//LinkedList class를 상속받음
template <typename T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first==NULL)
				return false; //첫번째 node가 null이면 false반환
			Node<T> * t = this->first; //첫번째 노드를 t에 저장
			element = t->data; //t가 가리키는 data를 element에 저장
			this->first=this->first->link; //first에 first가 가리키는 link 저장
			delete t; //t 삭제
			this->current_size--; // 성공적으로 delete 했으므로 current_size 1감소
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제


			return true; //성공적으로 delete했으므로 true반환
		}
};
