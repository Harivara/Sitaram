# INTERVAL DP / PARTITION DP — NOTES

## 1. First identify the DP state

There are TWO common ways to define intervals.

### A. INCLUSIVE INTERVAL

`dp[i][j]` represents elements from index `i` to `j` (both included).

Examples:
- Burst Balloons
- Merge Elements / Merge Stones
- Stone Game V

**Length and loop structure:**

```cpp
for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {

        int j = i + len - 1;

        // Calculate dp[i][j]

    }
}
```

**Partition loop depends on the problem:**

1. Choose `k` as the LAST element/operation:

```cpp
for (int k = i; k <= j; k++)
```

2. Split into two nonempty parts `[i...k]` and `[k+1...j]`:

```cpp
for (int k = i; k < j; k++)
```

### B. BOUNDARY INTERVAL

`dp[i][j]` represents the segment BETWEEN positions `i` and `j`.

The actual elements/cuts being processed lie strictly between these boundaries.

Example:
- Minimum Cost to Cut a Stick

**Length and loop structure:**

```cpp
for (int len = 2; len < n; len++) {
    for (int i = 0; i + len < n; i++) {

        int j = i + len;

        // Calculate dp[i][j]

    }
}
```

**Partition loop:**

```cpp
for (int k = i + 1; k < j; k++)
```

Here `k` is an internal boundary/cut.

---

## 2. Problem-wise templates

### 1. Burst Balloons — Inclusive

State: `dp[i][j]` = maximum coins from bursting balloons `[i...j]`.

Choose `k` as the LAST balloon to burst.

```cpp
for (int len = 1; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;

        for (int k = i; k <= j; k++) {
            dp[i][j] = max(dp[i][j],
                dp[i][k-1] + dp[k+1][j]
                + a[i-1] * a[k] * a[j+1]);
        }
    }
}
```

### 2. Merge Elements — Inclusive

State: `dp[i][j]` = minimum cost to merge elements `[i...j]`.

Split into `[i...k]` and `[k+1...j]`.

```cpp
for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        for (int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j],
                dp[i][k] + dp[k+1][j] + sum(i, j));
        }
    }
}
```

### 3. Minimum Cost to Cut a Stick — Boundary

State: `dp[i][j]` = minimum cost to cut the stick segment between `cuts[i]` and `cuts[j]`.

Choose `k` as the FIRST cut.

```cpp
for (int len = 2; len < m; len++) {
    for (int i = 0; i + len < m; i++) {
        int j = i + len;

        for (int k = i + 1; k < j; k++) {
            dp[i][j] = min(dp[i][j],
                dp[i][k] + dp[k][j]
                + cuts[j] - cuts[i]);
        }
    }
}
```

### 4. Stone Game V — Inclusive

State: `dp[i][j]` = maximum score from subarray `[i...j]`.

Split into `[i...k]` and `[k+1...j]`.

```cpp
for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        for (int k = i; k < j; k++) {
            // Calculate leftSum and rightSum

            // If leftSum < rightSum:
            // take leftSum + dp[i][k]

            // If leftSum > rightSum:
            // take rightSum + dp[k+1][j]

            // If equal:
            // take max of both possibilities
        }
    }
}
```

---

## 3. How to decide loop values in an interview

Ask these questions:

**Q1. What does `dp[i][j]` represent?**

- Elements `[i...j]` → Inclusive interval.
- Segment between `i` and `j` → Boundary interval.

**Q2. What is the smallest valid interval?**

- One element → `len = 1`.
- At least two elements to split → `len = 2`.
- Boundary interval needs an internal cut → `len = 2` (minimum distance between boundaries that allows a cut).

**Q3. What does `k` represent?**

- Last balloon/element selected → `k = i` to `j`.
- Split between two nonempty groups → `k = i` to `j-1`.
- Internal cut/boundary → `k = i+1` to `j-1`.

## 4. Remember these formulas

**Inclusive interval:**

```cpp
j = i + len - 1;
```

**Boundary interval:**

```cpp
j = i + len;
```

**Most important rule:**

Do not memorize `len`, `i`, and `k` values separately for every problem.

First define `dp[i][j]`. Then derive:
1. Valid starting index `i`.
2. Ending index `j`.
3. Smallest valid interval length.
4. Valid partition choices `k`.
5. Dependencies and their calculation order.

The DP state determines the loops — not the problem's name.