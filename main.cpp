#include <stdio.h>
#include "Stack.h"

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
		cin>>mode;
						    
		if(mode == 1)
			p = new Stack<int>();    // 정수를 저장하는 스택
			
		else
			p = new LinkedList<int>(); //정수를 저장하는 LinkedList


		do{
			prnMenu();
			cin>>selectNumber; //수행할 번호 입력받음
			
			switch(selectNumber){ 
				case 1:
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem); //tmpItem 입력받고 insert함수를 이용해 삽입
					cout<<tmpItem<<"가 삽입되었습니다."<<endl; //삽입 성공 메시지 출력
					break;
					
				case 2:
					if(p->Delete(tmpItem)==true) //성공적으로 삭제 되었는지 여부 체크
						cout<<tmpItem<<"가 삭제되었습니다."<<endl; //삭제된 원소 출력
						
					else cout<<"비어있습니다. 삭제 실패"<<endl; //노드가 비어있으면(false 반환) 삭제 실패
					break;
					
				case 3:
					cout<<"크기: "<<p->GetSize()<<endl; //노드 개수 출력
					p->Print(); //첫번째 원소부터 마지막 원소까지 출력
					break;
					
				case 4:
					flag = true;     break; //flag에 true 저장
					
				default:
					cout<<"잘못 입력하셨습니다."<<endl; //1,2,3,4가 아닌 다른 값 입력시 오류 메시지 출력
					break;
			
			}
			
			if(flag) break; //flag == true 이면 종료
			
		} while(1);
		
		return 0;
}

