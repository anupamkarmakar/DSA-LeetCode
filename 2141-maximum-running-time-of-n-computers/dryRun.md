Main Idea (Intuition)

Suppose we want to check if all n computers can run for T minutes.

Each battery b[i] can contribute at most:

min
(
𝑏
[
𝑖
]
,
𝑇
)
 minutes
min(b[i],T) minutes

(because a single battery can’t be used on two computers at the same time, and it’s useless to give more than T minutes to any computer).

If we sum this for all batteries:

total
=
∑
min
(
𝑏
[
𝑖
]
,
𝑇
)
total=∑min(b[i],T)

To run n computers for T minutes, we need:

total
≥
𝑛
×
𝑇
total≥n×T

So we can binary search on T (the answer):

low = 0

high = totalBattery / n (maximum possible time if all power is evenly distributed)

Check mid = (low + high) / 2:

If we can run n computers for mid minutes → try bigger time

Else → try smaller time

This works because if we can run for T minutes, we can definitely run for any time < T ⇒ monotonic condition ⇒ perfect for binary search.



🔍 Dry Run (Step by Step)

Let’s take an example:

n = 2
batteries = [3, 3, 3]


Total battery = 3 + 3 + 3 = 9
Max possible equal time = 9 / 2 = 4 (integer division)

So:

low = 0

high = 4

ans = 0

🔁 Iteration 1

mid = (0 + 4) / 2 = 2

Check if we can run both computers for 2 minutes:

canRun(2):

batteries = [3, 3, 3]

For b = 3: min(3, 2) = 2 → total = 2

For b = 3: min(3, 2) = 2 → total = 4

For b = 3: min(3, 2) = 2 → total = 6

We need n * time = 2 * 2 = 4.
Here total = 6 ≥ 4 → Possible ✅

So:

ans = 2

Try more: low = mid + 1 = 3

🔁 Iteration 2

low = 3, high = 4

mid = (3 + 4) / 2 = 3

Check canRun(3):

For b = 3: min(3, 3) = 3 → total = 3

For b = 3: min(3, 3) = 3 → total = 6

For b = 3: min(3, 3) = 3 → total = 9

Need n * time = 2 * 3 = 6
total = 9 ≥ 6 → Possible ✅

So:

ans = 3

Try more: low = mid + 1 = 4

🔁 Iteration 3

low = 4, high = 4

mid = (4 + 4) / 2 = 4

Check canRun(4):

For b = 3: min(3, 4) = 3 → total = 3

For b = 3: min(3, 4) = 3 → total = 6

For b = 3: min(3, 4) = 3 → total = 9

Need n * time = 2 * 4 = 8
total = 9 ≥ 8 → Possible ✅

So:

ans = 4

Try more: low = mid + 1 = 5

🔁 Iteration 4 (End)

Now low = 5, high = 4 → low > high → stop

Final ans = 4

So the maximum running time of 2 computers = 4 minutes.