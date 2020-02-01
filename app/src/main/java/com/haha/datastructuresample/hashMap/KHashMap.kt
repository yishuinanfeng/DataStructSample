package com.haha.datastructuresample.hashMap

import android.util.Log
import com.haha.datastructuresample.HASHMAP_TAG

/**
 * kotlin版HashMap
 */

private val DEFAULT_LOAD_FACTOR = 0.75f
/**
 * 16
 */
private var DEFAULT_INITIAL_CAPACITY = 1 shl 4

private val MAXIMUM_CAPACITY = 1 shl 30

class KHashMap<K, V>(
    initialCapacity: Int = DEFAULT_INITIAL_CAPACITY,
    /**
     * The load factor for the hash table.
     *
     * @serial
     */
    var loadFactor: Float = DEFAULT_LOAD_FACTOR
) {

    private var threshold: Int = 0

    @Transient
    internal var size: Int = 0

    private lateinit var table: Array<Node<K, V>?>

    init {
        require(initialCapacity >= 0) { "Illegal initial capacity: $initialCapacity" }
        var capacity = initialCapacity
        if (capacity > MAXIMUM_CAPACITY) {
            capacity = MAXIMUM_CAPACITY
        }
        val tableSize = tableSizeFor(capacity)
        Log.d(HASHMAP_TAG, "tableSize：$tableSize")
        table = arrayOfNulls(tableSize)
        this.threshold = (tableSize * loadFactor).toInt()
    }

    /**
     * 添加键值对节点，返回之前key对应的旧值如果有
     */
    fun put(key: K, value: V): V? {
        if (key == null) {
            //todo 可以参考HashMap对key为null处理
            return null
        }

        val hash = hash(key.hashCode())
        val index = getIndex(hash)

        var e = table[index]
        while (e != null) {
            if ((e.hash == hash) && ((e.key === key) || (e.key == key))) {
                //找到对应key的Node,将Node的value
                val oldValue = e.value
                e.value = value
                return oldValue
            }
            e = e.next
        }

        //找不到对应key的Node
        addNewNode(key, value, index, hash)
        return null
    }

    /**
     * table数组添加一个新的节点
     */
    private fun addNewNode(key: K, value: V, index: Int, hash: Int) {
        var realIndex = index
        if (size >= threshold && table[index] != null) {
            resize()
            realIndex = getIndex(hash)
        }

        addNodeToArray(key, value, realIndex, hash)
        size++
    }

    private fun addNodeToArray(key: K, value: V, index: Int, hash: Int) {
        val node = Node(hash, key, value, null)
        table[index] = node
    }

    /**
     * 数组扩容
     */
    private fun resize() {

    }

    private fun getIndex(hashCode: Int): Int {
        return hashCode.and(table.size - 1)
    }

    /**
     * 再次哈希，使得哈希码更加均匀
     */
    private fun hash(key: Int?): Int {
        val h = key.hashCode()
        return if (key == null) {
            0
        } else {
            h xor h.ushr(16)
        }
    }

    /**
     * 查询键为key的value
     * null表示查找找不到
     */
    fun get(key: K): V? {
        val hash = hash(key.hashCode())
        val index = getIndex(hash)

        var e = table[index]
        while (e != null) {
            if ((e.hash == hash) && ((e.key === key) || (e.key == key))) {
                return e.value
            }
            e = e.next
        }

        return null
    }


    /**
     * 获取第一个大于当前数字的2次幂的数
     */
    private fun tableSizeFor(cap: Int): Int {
        var n = cap - 1
        n = n or n.ushr(1)
        n = n or n.ushr(2)
        n = n or n.ushr(4)
        n = n or n.ushr(8)
        n = n or n.ushr(16)
        return if (n < 0) 1 else if (n >= MAXIMUM_CAPACITY) MAXIMUM_CAPACITY else n + 1
    }

    /**
     * 一个键值对节点
     */
    class Node<K, V>(val hash: Int, val key: K, var value: V, var next: Node<K, V>?)
}