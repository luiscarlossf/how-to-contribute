fun <T : Comparable<T>> bubbleSort(array: Array<T>) {
    var swap = true
    while (swap) {
        swap = false
        array.forEachIndexed { i, t ->
            if (i < array.indices.last && t > array[i + 1]) {
                array[i] = array[i + 1]
                array[i + 1] = t
                swap = true
            }
        }
    }
}

fun main(args: Array<String>) {
    val array = arrayOf(6, 5, 3, 9, 2)
    bubbleSort(array)
    array.forEach { println(it) }
}
