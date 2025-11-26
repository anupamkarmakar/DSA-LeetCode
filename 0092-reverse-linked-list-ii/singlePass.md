We want to reverse between left = 2 and right = 4.

So we must reverse the part:
2 → 3 → 4 into 4 → 3 → 2

#Initial Setup
We create a dummy node and move prev to the node just before left:

Pointer	Points To
dummy	0 → 1 → 2 → 3 → 4 → 5
prev	node 1
curr	node 2 (start of reverse part)


dummy
  ↓
0 → 1 → 2 → 3 → 4 → 5
      ↑
     prev
      ↑
     curr




🔁 Reversal Loop Execution
We run the loop right - left = 4 - 2 = 2 times.

Iteration 1
temp = curr->next = node 3


Then we adjust pointers:

Step A:
curr->next = temp->next   (2->next = 4)

Step B:
temp->next = prev->next   (3->next = 2)

Step C:
prev->next = temp         (1->next = 3)

List After Iteration 1
1 → 3 → 2 → 4 → 5
     ↑    ↑
    prev curr




Visualization:

dummy
  ↓
0 → 1 → 3 → 2 → 4 → 5
          ↑    ↑
        temp  curr

Iteration 2
temp = curr->next = node 4

Step A:
curr->next = temp->next   (2->next = 5)

Step B:
temp->next = prev->next   (4->next = 3)

Step C:
prev->next = temp         (1->next = 4)


List After Iteration 2
Final reversed segment:
1 → 4 → 3 → 2 → 5
     ↑        ↑
    prev     curr




🎉 Final Linked List
1 → 4 → 3 → 2 → 5

🔑 Core Idea Summary
We keep moving the node after curr to just after prev, turning the segment backwards one-by-one.