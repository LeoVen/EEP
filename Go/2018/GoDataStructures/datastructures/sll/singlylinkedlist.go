// @file singlylinkedlist.go
// @author Leonardo Vencovsky (https://github.com/LeoVen)
// @date 03/08/2018
//

// Package sll contains the Singly Linked List implementation
package sll

import (
	"errors"
	"fmt"
)

// Error strings
const (
	removeOnEmptyList = "<ERROR> Can not remove an element from an empty list"
	invalidPosition   = "<ERROR> Invalid position"
)

// SinglyLinkedList : This struct is a descriptor for the chained nodes. All
//                    operations should be made on top of this structure
type SinglyLinkedList struct {
	head *SinglyLinkedNode // The first element on the list
	tail *SinglyLinkedNode // The last element on the list
	size uint              // List size tracker
}

// SinglyLinkedNode : This struct defines a chained list or a forward list
//                    where each node points to either nil or a next node
type SinglyLinkedNode struct {
	element interface{}       // Element of that node
	next    *SinglyLinkedNode // Next element on the list
}

// newNode : This properly builds a SinglyLinkedNode
func newNode(value interface{}) *SinglyLinkedNode {

	return &SinglyLinkedNode{value, nil}
}

// NewList : This properly builds a SinglyLinkedList
func NewList() *SinglyLinkedList {

	return &SinglyLinkedList{nil, nil, 0}
}

// iterate : Used to iterate through the list and return the element that the given position
func (list *SinglyLinkedList) iterate(pos uint) *SinglyLinkedNode {

	scan := list.head

	var i uint
	for i = 0; i < pos; i++ {
		scan = scan.next
	}

	return scan
}

// IsEmpty : Returns true if list is empty, false otherwise
func (list *SinglyLinkedList) IsEmpty() bool {

	return list.size == 0
}

// Size : Returns list's size
func (list *SinglyLinkedList) Size() uint {

	return list.size
}

// InsertStart : This function inserts a new node at the start of the list
func (list *SinglyLinkedList) InsertStart(value interface{}) error {

	node := newNode(value)

	if list.IsEmpty() {
		list.head = node
		list.tail = node
	} else {
		node.next = list.head
		list.head = node
	}

	list.size++

	return nil
}

// Insert : This function inserts a given element at a given position
func (list *SinglyLinkedList) Insert(value interface{}, position uint) error {

	if position > list.size {

		return errors.New(invalidPosition)
	}

	if position == 0 {

		list.InsertStart(value)

	} else if position == list.size {

		list.InsertEnd(value)

	} else {

		prev := list.iterate(position - 1)

		node := newNode(value)

		node.next = prev.next
		prev.next = node

		list.size++
	}

	return nil
}

// InsertEnd : This function inserts a new node at the end of the list
func (list *SinglyLinkedList) InsertEnd(value interface{}) error {

	node := newNode(value)

	if list.IsEmpty() {

		list.head = node
		list.tail = node

	} else {

		list.tail.next = node
		list.tail = node
	}

	list.size++

	return nil
}

// RemoveStart : This function removes the first element of the list or raises
//               an error if the list is empty
func (list *SinglyLinkedList) RemoveStart() error {

	if !list.IsEmpty() {
		list.head = list.head.next

		list.size--

		if list.IsEmpty() {
			list.head = nil
			list.tail = nil
		}

		return nil
	}

	return errors.New(removeOnEmptyList)
}

// Remove : This function removes an element at a given position
func (list *SinglyLinkedList) Remove(position uint) error {

	if list.IsEmpty() {

		return errors.New(removeOnEmptyList)
	}

	if position >= list.size {

		return errors.New(invalidPosition)
	}

	if position == 0 {

		list.RemoveStart()

	} else if position == list.size-1 {

		list.RemoveEnd()

	} else {

		prev := list.iterate(position - 1)

		prev.next = prev.next.next

		list.size--
	}

	return nil
}

// RemoveEnd : This function removes the last element of the list or raises an
//             error if the list is empty
func (list *SinglyLinkedList) RemoveEnd() error {

	if !list.IsEmpty() {

		var prev *SinglyLinkedNode
		scan := list.head

		for scan.next != nil {
			prev = scan
			scan = scan.next
		}

		if prev != nil {

			prev.next = nil
			list.tail = prev
		}

		list.size--

		if list.IsEmpty() {
			list.head = nil
			list.tail = nil
		}

		return nil
	}

	return errors.New(removeOnEmptyList)

}

// Display : This function displays the list in the terminal using fmt
func (list *SinglyLinkedList) Display() {

	fmt.Println("SinglyLinkedList", list.size)

	var scan = list.head

	if list.IsEmpty() {

		fmt.Println("[ EMPTY ]")
	} else {

		for scan != nil {

			fmt.Print(scan.element, " -> ")
			scan = scan.next
		}

		fmt.Print("nil\n")
	}

}
