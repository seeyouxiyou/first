//有序数组插入元素，返回下标
//二分查找到元素直接返回，查找不到返回left
package main

import "fmt"

func main() {
	var len, goal, index int
	fmt.Printf("pls input arr length:\n")
	fmt.Scanf("%d", &len)

	arr := make([]int, len)

	fmt.Printf("pls input a sorted arr:\n")
	for i := 0; i < len; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	fmt.Printf("sorted arr: ")
	for i := 0; i < len; i++ {
		fmt.Printf("%d ", arr[i])
	}
	fmt.Printf("\n")

	fmt.Printf("pls input goal to insert:\n")
	fmt.Scanf("%d", &goal)

	index = binaryInsert(arr, len, goal)

	fmt.Printf("insert index is %d:\n", index)

}

func binaryInsert(arr []int, len, goal int) (ret int) {
	left := 0
	right := len - 1

	for left < right {
		mid := left + ((right - left) >> 1)

		if arr[mid] == goal {
			return mid
		} else if arr[mid] < goal {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return left
}
