/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    //store the node copies itself in hashmap
    curr := head
    copies := make(map[*Node]*Node)

    for curr != nil {
        copyNode := &Node{
            Val: curr.Val,
        }

        copies[curr] = copyNode
        curr = curr.Next
    }

    curr = head
    for curr != nil {
        copyNode := copies[curr]
        copyNode.Next = copies[curr.Next]
        copyNode.Random = copies[curr.Random]

        curr = curr.Next
    }

    return copies[head]
}
