package edu.eep

fun <T, C : Iterable<T>>iterPrinter(col: C) {
    for (item in col) {
        print("$item ")
    }
}

fun <T, M : Iterable<Iterable<T>>>iterMatrix(matrix: M) {
    for ( row in matrix) {
        println()
        for ( item in row) {
            print("$item ")
        }
    }
}

fun <T, M : Iterable<Iterable<T>>>iterRowMatrix(matrix: M) {
    for ( (i, row) in matrix.withIndex()) {
        for ( (j, item) in row.withIndex()) {
            println("[$i, $j] = $item")
        }
    }
}

fun main() {
    val list = ArrayList<Int>(100)

    for (i in 0..20) {
        list.add(i)
    }

    iterPrinter(list)
    println("\n")

    val matrix = ArrayList<ArrayList<Char>>(100)
    val width = 11
    val high = 'X'
    val low = ' '

    for (i in 0 until width) {
        matrix.add(ArrayList(100))
        for (j in 0 until width) {
            if (i == j || i + j == width - 1) {
                matrix[i].add(high)
            } else {
                matrix[i].add(low)
            }
        }
    }

    for (i in 1..10) {
        iterMatrix(matrix)
    }
}
