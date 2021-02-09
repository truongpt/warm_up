from linked_list import LinkedList

llist = LinkedList()
llist.append("a")
llist.append("b")
llist.append("c")
llist.append("d")
print("Initialize linked list")
llist.print()

llist.insert_after_node(llist.head.next, "e")
print("Updated linked list")
llist.print()
