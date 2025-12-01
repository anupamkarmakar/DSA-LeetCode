# 🔋 Maximum Running Time of N Computers - Dry Run & Visuals

## 📌 Problem Statement
Given `n` computers and an array of `batteries`, where each battery has a certain amount of power, find the maximum number of minutes you can run all `n` computers simultaneously.

**Key Rule**: You can swap batteries instantly at any time.

---

## 💡 Main Idea (Intuition)

### The Core Question:
> "Can we run all `n` computers for `T` minutes?"

### Battery Contribution Logic:
Each battery `b[i]` can contribute **at most**:
```
min(b[i], T) minutes
```

**Why?** 
- A battery can't be used on two computers simultaneously
- Giving more than `T` minutes to one computer is wasteful

### Feasibility Check:
```
total_power = Σ min(b[i], T)

If total_power ≥ n × T  →  We CAN run for T minutes ✅
Otherwise              →  We CANNOT ❌
```

### Binary Search Approach:
Since the condition is **monotonic** (if we can run for T, we can run for any time < T), we use binary search:

```
low = 0
high = total_battery_power / n
```

---

## 🎯 Example Setup

```
n = 2 (computers)
batteries = [3, 3, 3]
```

### Initial Calculations:
```
Total battery power = 3 + 3 + 3 = 9
Maximum possible time = 9 / 2 = 4 minutes
```

### Search Range:
```
low = 0
high = 4
ans = 0
```

---

## 🔍 Detailed Dry Run with Visuals

### 🔁 Iteration 1

```
low = 0, high = 4
mid = (0 + 4) / 2 = 2
```

**Question**: Can we run 2 computers for 2 minutes?

#### Visual Battery Distribution:
```
Time Target: T = 2 minutes

Battery 1: [■■■]     → min(3, 2) = 2 ✓
           Power: 3     Use: 2
           
Battery 2: [■■■]     → min(3, 2) = 2 ✓
           Power: 3     Use: 2
           
Battery 3: [■■■]     → min(3, 2) = 2 ✓
           Power: 3     Use: 2

Total Available: 2 + 2 + 2 = 6
Total Needed:    2 × 2 = 4

6 ≥ 4  ✅  POSSIBLE!
```

#### Computer Timeline:
```
Computer 1: [■■] (2 min)
Computer 2: [■■] (2 min)

Total power used: 4
Power remaining: 2 (can do better!)
```

**Result**: ✅ Possible → Update `ans = 2`, try higher → `low = 3`

---

### 🔁 Iteration 2

```
low = 3, high = 4
mid = (3 + 4) / 2 = 3
```

**Question**: Can we run 2 computers for 3 minutes?

#### Visual Battery Distribution:
```
Time Target: T = 3 minutes

Battery 1: [■■■]     → min(3, 3) = 3 ✓
           Power: 3     Use: 3
           
Battery 2: [■■■]     → min(3, 3) = 3 ✓
           Power: 3     Use: 3
           
Battery 3: [■■■]     → min(3, 3) = 3 ✓
           Power: 3     Use: 3

Total Available: 3 + 3 + 3 = 9
Total Needed:    2 × 3 = 6

9 ≥ 6  ✅  POSSIBLE!
```

#### Computer Timeline:
```
Computer 1: [■■■] (3 min)
Computer 2: [■■■] (3 min)

Total power used: 6
Power remaining: 3 (can we do better?)
```

**Result**: ✅ Possible → Update `ans = 3`, try higher → `low = 4`

---

### 🔁 Iteration 3

```
low = 4, high = 4
mid = (4 + 4) / 2 = 4
```

**Question**: Can we run 2 computers for 4 minutes?

#### Visual Battery Distribution:
```
Time Target: T = 4 minutes

Battery 1: [■■■ ]     → min(3, 4) = 3 ✓
           Power: 3      Use: 3
           
Battery 2: [■■■ ]     → min(3, 4) = 3 ✓
           Power: 3      Use: 3
           
Battery 3: [■■■ ]     → min(3, 4) = 3 ✓
           Power: 3      Use: 3

Total Available: 3 + 3 + 3 = 9
Total Needed:    2 × 4 = 8

9 ≥ 8  ✅  POSSIBLE!
```

#### Computer Timeline with Battery Swapping:
```
Minute:     1  2  3  4
Computer 1: [B1][B2][B3][?] 
Computer 2: [B1][B2][B3][?]

Strategy:
- Minutes 0-3: Each battery contributes 3 min total
- Minute 3-4: We need 2 more minutes (1 per computer)
- We have 9 - 6 = 3 spare minutes ✓

Distribution:
  Computer 1: Uses 4 min (1.5 + 1.5 + 1)
  Computer 2: Uses 4 min (1.5 + 1.5 + 1)
  Total: 8 min used, 1 min spare
```

**Result**: ✅ Possible → Update `ans = 4`, try higher → `low = 5`

---

### 🔁 Iteration 4 (Termination)

```
low = 5, high = 4
low > high  →  STOP
```

**Question**: Can we run 2 computers for 5 minutes?

#### Quick Check:
```
Total Available: 9
Total Needed:    2 × 5 = 10

9 < 10  ❌  IMPOSSIBLE!
```

Since `low > high`, binary search terminates.

---

## 🎉 Final Answer

```
Maximum Running Time = 4 minutes
```

---

## 📊 Visual Summary of Binary Search

```
Search Space: [0, 1, 2, 3, 4, 5, 6, ...]

Iteration 1:  [0 ─────── mid=2 ─────── 4]
              ✅ Possible → ans=2, search right

Iteration 2:  [3 ── mid=3 ── 4]
              ✅ Possible → ans=3, search right

Iteration 3:  [4 mid=4 4]
              ✅ Possible → ans=4, search right

Iteration 4:  [5 > 4]
              low > high → DONE!

Final: ans = 4
```

---

## 🧮 Complexity Analysis

### Time Complexity: **O(m × log(sum/n))**
- `m` = number of batteries
- Binary search iterations: `log(total_battery / n)`
- Each iteration: O(m) to check feasibility

### Space Complexity: **O(1)**
- Only using variables for binary search

---

## 🔑 Key Insights

1. **Binary Search on Answer**: The answer has a monotonic property
2. **Greedy Contribution**: Each battery contributes `min(battery, time)`
3. **Pooling Strategy**: Total power matters, not individual battery assignments
4. **Upper Bound**: Maximum time = `total_battery / n` (equal distribution)

---

## 🚀 Code Template

```python
def maxRunTime(n, batteries):
    low = 0
    high = sum(batteries) // n
    ans = 0
    
    while low <= high:
        mid = (low + high) // 2
        
        # Check if we can run n computers for mid minutes
        total_power = sum(min(b, mid) for b in batteries)
        
        if total_power >= n * mid:
            ans = mid
            low = mid + 1  # Try longer time
        else:
            high = mid - 1  # Try shorter time
    
    return ans
```

---

## 📝 Practice Tips

1. **Understand the pooling concept**: All batteries contribute to a shared pool
2. **Why min(b, T)?**: A battery can't give more than T to any single computer
3. **Binary search invariant**: If time T works, all times < T work too
4. **Edge cases**: 
   - Single computer (n=1)
   - Single battery
   - Very large batteries vs. many small ones

---

Happy Coding! 🎯
