package main

// Code structure
//
// - Initial Values
// - Webserver functions
// -

import (
	"encoding/json"
	"log"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

// Mock data
var books []Book

// Webserver functions

// GET /api/books
// Gets all books
func getBooks(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	json.NewEncoder(w).Encode(books)
}

// GET /api/books/{id}
// Gets a single book by id
func getBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	params := mux.Vars(r) // Gets any parameters

	// find correct book
	for _, item := range books {
		if item.ID == params["id"] {
			json.NewEncoder(w).Encode(item)
			return
		}
	}

	json.NewEncoder(w).Encode(&Book{})
}

// POST /api/books
// Creates a book
func createBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	var book Book
	_ = json.NewDecoder(r.Body).Decode(&book)
	book.ID = strconv.Itoa(len(books) + 1)

	books = append(books, book)
}

// PUT /api/books/{id}
// Updates a single book by id
func updateBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	params := mux.Vars(r)

	for index, item := range books {
		if item.ID == params["id"] {
			books = append(books[:index], books[index+1:]...)
			var book Book
			_ = json.NewDecoder(r.Body).Decode(&book)
			book.ID = strconv.Itoa(len(books) + 1)
			books = append(books, book)
			return
		}
	}

	json.NewEncoder(w).Encode(books)
}

// DELETE /api/books/{id}
// Deletes a given book by id
func deleteBook(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	params := mux.Vars(r)

	for index, item := range books {
		if item.ID == params["id"] {
			books = append(books[:index], books[index+1:]...)
			break
		}
	}

	json.NewEncoder(w).Encode(books)
}

// Book model containing information about a book
type Book struct {
	ID     string  `json:"id"`
	Isbn   string  `json:"isbn"`
	Title  string  `json:"title"`
	Author *Author `json:"author"`
}

// Author model containing information about an author
// Used by Book
type Author struct {
	Firstname string `json:"firstname"`
	Lastname  string `json:"lastname"`
}

func main() {

	// Init mux router
	r := mux.NewRouter()

	// Mock data
	books = append(books, Book{
		ID:     "1",
		Isbn:   "9780618640157",
		Title:  "Lord of the Rings",
		Author: &Author{Firstname: "John", Lastname: "Tolkien"}})
	books = append(books, Book{
		ID:     "2",
		Isbn:   "9788578274887",
		Title:  "The Silmarillion",
		Author: &Author{Firstname: "John", Lastname: "Tolkien"}})

	// Route endpoints
	r.HandleFunc("/api/books", getBooks).Methods("GET")
	r.HandleFunc("/api/books/{id}", getBook).Methods("GET")
	r.HandleFunc("/api/books", createBook).Methods("POST")
	r.HandleFunc("/api/books/{id}", updateBook).Methods("PUT")
	r.HandleFunc("/api/books/{id}", deleteBook).Methods("DELETE")

	log.Fatal(http.ListenAndServe(":8000", r))
}
