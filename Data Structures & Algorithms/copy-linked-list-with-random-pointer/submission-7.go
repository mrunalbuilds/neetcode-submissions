/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    //we can store the copied node next to original node
    if head == nil {
        return nil
    }
    curr := head
    for curr != nil {
        newNode := &Node{
            Val: curr.Val,
        }

        newNode.Next = curr.Next
        curr.Next = newNode

        curr = newNode.Next
    }

    curr = head
    for curr != nil {
        if curr.Random != nil{
            curr.Next.Random = curr.Random.Next
        }else{
            curr.Next.Random = nil
        }
        curr = curr.Next.Next
    }

    //now seperate the list
    curr = head;
    clonedHead := head.Next;
    for curr != nil {
        temp := curr.Next
        curr.Next = temp.Next

        if temp.Next != nil {
            temp.Next = temp.Next.Next
        }

        curr = curr.Next
    }

    return clonedHead
}
