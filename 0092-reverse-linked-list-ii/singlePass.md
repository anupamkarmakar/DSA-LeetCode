# 🔄 Reverse Linked List II - Head Insertion Method (Visual Dry Run)

## 📌 Problem Overview

**Given:** A linked list and two positions `left` and `right`  
**Task:** Reverse the nodes between positions `left` and `right` (1-indexed)

**Example:**
```
Input:  1 → 2 → 3 → 4 → 5,  left = 2, right = 4
Output: 1 → 4 → 3 → 2 → 5
```

**Target Segment:**
```
Original:  2 → 3 → 4
Reversed:  4 → 3 → 2
```

---

## 🎯 The Head Insertion Method Explained

### Core Concept
We repeatedly **extract** nodes from the sublist and **insert them at the head** (front) of the reversed section.

```
Think of it like this:
- You have a rope with beads (nodes)
- You pick beads one by one from the middle
- You place each bead at the FRONT of a growing reversed section
```

---

## 🚀 Initial Setup

### Step 1: Create Dummy Node

**Why?** Handles edge cases when `left = 1` (reversing from the head)

```
dummy → 1 → 2 → 3 → 4 → 5 → NULL
  ↓
  0
```

### Step 2: Position the `prev` Pointer

Move `prev` to the node **just before** position `left`:

```
Loop: for (int i = 1; i < left; i++)
      prev = prev->next

Result: prev stops at node 1 (position 1)
```

### Step 3: Set the `curr` Pointer

`curr` points to the **first node** to be reversed:

```
curr = prev->next  // Node at position 'left'
```

### Visual State After Setup:

```
        prev  curr
          ↓    ↓
dummy → 1 → 2 → 3 → 4 → 5 → NULL
  ↓
  0
```

| Pointer | Position | Points To | Role |
|---------|----------|-----------|------|
| `dummy` | 0 | Node 0 | Safety anchor |
| `prev` | 1 | Node 1 | Anchor before reversal |
| `curr` | 2 | Node 2 | **Stays fixed** during reversal |

---

## 🔁 Reversal Loop - Detailed Dry Run

**Loop Count:** `right - left = 4 - 2 = 2 iterations`

---

### 🔄 **ITERATION 1**

#### 📸 State Before:
```
        prev  curr
          ↓    ↓
dummy → 1 → 2 → 3 → 4 → 5 → NULL
  ↓
  0

Connections:
prev->next = node 2
curr->next = node 3
```

---

#### Step A: Capture the node to move
```cpp
temp = curr->next  // temp = node 3
```

```
        prev  curr  temp
          ↓    ↓    ↓
dummy → 1 → 2 → 3 → 4 → 5 → NULL
  ↓
  0

temp is the node we're about to EXTRACT and move to the front!
```

---

#### Step B: Bypass `temp` (unhook it)
```cpp
curr->next = temp->next  // Skip over node 3
```

**Before:**
```
curr (2) → temp (3) → node 4
```

**After:**
```
curr (2) ────────────→ node 4
         (bypassing 3)

        temp (3) is now floating!
```

**Visual:**
```
        prev  curr  temp
          ↓    ↓    ↓
dummy → 1 → 2 ⤵  3   4 → 5 → NULL
  ↓         └──────→
  0         
```

---

#### Step C: Point `temp` to the front of reversed section
```cpp
temp->next = prev->next  // Point node 3 to node 2
```

```
        prev  curr  temp
          ↓    ↓    ↓
dummy → 1 → 2    3 → 4 → 5 → NULL
  ↓         ↑    │
  0         └────┘
```

**What's happening?**  
Node 3 now points to node 2 (the current front of the reversed section)

---

#### Step D: Insert `temp` at the head
```cpp
prev->next = temp  // Make prev point to node 3
```

```
        prev       curr
          ↓         ↓
dummy → 1 → 3 → 2 → 4 → 5 → NULL
  ↓       ↑
  0 ──────┘
```

**Result:** Node 3 is now **in front of** node 2!

---

#### 📸 State After Iteration 1:

```
        prev       curr
          ↓         ↓
dummy → 1 → 3 → 2 → 4 → 5 → NULL
  ↓
  0

Reversed so far: [3 → 2]
                  └───┘
                  HEAD
```

**Key Observation:**  
- `curr` **NEVER MOVED** - still at node 2
- Node 3 was inserted **before** node 2
- `prev` still at node 1

---

### 🔄 **ITERATION 2**

#### 📸 State Before:
```
        prev       curr
          ↓         ↓
dummy → 1 → 3 → 2 → 4 → 5 → NULL
  ↓
  0

Connections:
prev->next = node 3
curr->next = node 4
```

---

#### Step A: Capture the node to move
```cpp
temp = curr->next  // temp = node 4
```

```
        prev       curr  temp
          ↓         ↓    ↓
dummy → 1 → 3 → 2 → 4 → 5 → NULL
  ↓
  0

Now we'll extract node 4 and move it to the front!
```

---

#### Step B: Bypass `temp`
```cpp
curr->next = temp->next  // Skip over node 4
```

```
        prev       curr  temp
          ↓         ↓    ↓
dummy → 1 → 3 → 2 ⤵  4   5 → NULL
  ↓             └──────→
  0
```

**Result:** `curr (2)` now points directly to `node 5`

---

#### Step C: Point `temp` to front
```cpp
temp->next = prev->next  // Point node 4 to node 3
```

```
        prev       curr  temp
          ↓         ↓    ↓
dummy → 1 → 3 → 2    4 → 5 → NULL
  ↓         ↑         │
  0         └─────────┘
```

**What's happening?**  
Node 4 now points to node 3 (the current front)

---

#### Step D: Insert `temp` at the head
```cpp
prev->next = temp  // Make prev point to node 4
```

```
        prev            curr
          ↓              ↓
dummy → 1 → 4 → 3 → 2 → 5 → NULL
  ↓       ↑
  0 ──────┘
```

**Result:** Node 4 is now **in front of** node 3!

---

#### 📸 State After Iteration 2:

```
        prev            curr
          ↓              ↓
dummy → 1 → 4 → 3 → 2 → 5 → NULL
  ↓
  0

Fully reversed: [4 → 3 → 2]
                 └─────────┘
                    HEAD
```

---

## 🎉 Final Result

```
Original List:
1 → 2 → 3 → 4 → 5

After Reversal (left=2, right=4):
1 → 4 → 3 → 2 → 5
    └─────────┘
    Reversed!

Return: dummy->next (node 1)
```

---

## 🔑 The "Head Insertion" Pattern Visualized

### Animation-Style Breakdown:

```
BEFORE:
prev → [reversed part] → curr → temp → rest...

STEP 1 (Unhook):
prev → [reversed part] → curr ───────→ rest...
                              temp ⤴

STEP 2 (Point to front):
prev → [reversed part] → curr → rest...
       ↑                      
       └──────────── temp ────┘

STEP 3 (Insert at head):
prev → temp → [reversed part] → curr → rest...
       └──┘
       NEW HEAD!

AFTER:
prev → [temp + reversed part] → curr → rest...
```

---

## 💡 Key Insights

### Why This Works

1. **`prev` never moves** → Stable anchor point before the reversal
2. **`curr` never moves** → Stable anchor point at the "end" of the reversal
3. **`temp` is extracted and inserted** → Builds reversed section backwards

### The Pattern

| Iteration | Node Extracted | Where Inserted | Result |
|-----------|---------------|----------------|---------|
| 1 | Node 3 | Before node 2 | `1 → 3 → 2 → 4 → 5` |
| 2 | Node 4 | Before node 3 | `1 → 4 → 3 → 2 → 5` |

### Mental Model

```
Think of it as building a stack:
- Start with: [2]
- Push 3: [3, 2]
- Push 4: [4, 3, 2]

Each new node goes to the HEAD (front)!
```

---

## 📊 Complexity Analysis

| Metric | Value | Explanation |
|--------|-------|-------------|
| **Time Complexity** | O(n) | Single pass: O(left-1) setup + O(right-left) reversals |
| **Space Complexity** | O(1) | Only 3 pointers used (prev, curr, temp) |

---

## 🎓 Step-by-Step Algorithm Summary

```
1. Create dummy node (handles edge cases)
2. Move prev to position (left - 1)
3. Set curr = prev->next
4. For (right - left) iterations:
   a. temp = curr->next           // Capture node to move
   b. curr->next = temp->next     // Unhook temp
   c. temp->next = prev->next     // Point temp to current head
   d. prev->next = temp           // Insert temp as new head
5. Return dummy->next
```

---

## 🐛 Common Mistakes & Fixes

| ❌ Mistake | ✅ Fix |
|-----------|-------|
| Moving `curr` forward | Keep `curr` **fixed** at position `left` |
| Wrong loop count (`right - left + 1`) | Use `right - left` iterations |
| Forgetting dummy node | Always use dummy for edge cases |
| Losing track of `temp` | Extract → Point → Insert (3 steps!) |

---

## 📝 Complete Code

```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    // Step 1: Create dummy node
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    // Step 2: Move prev to position (left - 1)
    ListNode* prev = dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }
    
    // Step 3: Set curr to start of reversal
    ListNode* curr = prev->next;
    
    // Step 4: Head insertion loop
    for (int i = 0; i < right - left; i++) {
        ListNode* temp = curr->next;      // a. Capture
        curr->next = temp->next;          // b. Unhook
        temp->next = prev->next;          // c. Point to head
        prev->next = temp;                // d. Insert at head
    }
    
    // Step 5: Return result
    return dummy->next;
}
```

---

## 🎯 Practice Examples

### Example 1: Reverse First 3 Nodes
```
Input:  1 → 2 → 3 → 4 → 5, left = 1, right = 3
Output: 3 → 2 → 1 → 4 → 5
```

### Example 2: Reverse Last 2 Nodes
```
Input:  1 → 2 → 3 → 4 → 5, left = 4, right = 5
Output: 1 → 2 → 3 → 5 → 4
```

### Example 3: Reverse Entire List
```
Input:  1 → 2 → 3 → 4 → 5, left = 1, right = 5
Output: 5 → 4 → 3 → 2 → 1
```

---

## 🧠 Remember

> **"Extract from the middle, Insert at the head"**

This is the essence of the head insertion method! Each node is pulled out and placed at the front of the growing reversed section, one by one. 🎯

---

**Happy Coding! 🚀**
