package main

import (
	"fmt"

	"./datastructures/sll"
)

func main() {

	list := sll.NewList()

	for i := 0; i < 10; i++ {
		list.InsertStart(i)
	}

	list.InsertStart("World")
	list.InsertStart("Hello")

	var values = []float64{98.1, 23.4, 55.0, 65.8}

	for _, e := range values {
		list.InsertEnd(e)
	}

	for list.Size() > 5 {
		list.Display()
		list.RemoveEnd()
	}

	err := list.Insert("Gipsy", list.Size())

	if err != nil {
		fmt.Println(err)
	}

	list.Display()

	err = list.Remove(3)

	if err != nil {

		fmt.Println(err)
	}

	list.Display()

	for !list.IsEmpty() {
		err = list.Remove(list.Size() - 1)

		if err != nil {

			fmt.Println(err)
		}

		list.Display()
	}

}
