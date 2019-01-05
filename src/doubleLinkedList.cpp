#include "doubleLinkedList.h";

template<typename T>
ListNode<T>::ListNode() {}
template<typename T>
ListNode<T>::~ListNode() {}

template<typename T>
ListNode<T>::ListNode(T Data)
{
}



template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {}
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {}

template<typename T>
void DoubleLinkedList<T>::addNode(const T Data) {
	ListNode* curr = nullptr;
	if (m_pHead.get() == nullptr) { //If list is empty.
		m_pHead = std::make_unique<ListNode>(Data);
	}
	else if (m_pHead.get()->next.get() == nullptr) { //If list has one element
		m_pHead.get()-> = std::make_unique<ListNode>(Data);
		curr = m_pHead.get()->next.get();
		curr->prev = m_pHead.get();
		tail = curr;
	}
	else {
		m_pTail-> = std::make_unique<ListNode>(Data);
		curr = m_pTail->next.get(); //Sets raw pointer to the last element.
		curr->prev = m_pTail;
		m_pTail = curr;
	}
}

template<typename T>
void DoubleLinkedList<T>::removeNode(const T Data) {

}

template<typename T>
void DoubleLinkedList<T>::display() {

}