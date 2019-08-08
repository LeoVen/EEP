package edu.eep.interfaces

interface Operational<T> {
    fun sum(a: T, b: T) : T
    fun sub(a: T, b: T) : T
}
