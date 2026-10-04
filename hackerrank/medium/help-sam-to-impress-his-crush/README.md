# Help Sam to impress his CRUSH

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Sam's CRUSH wants to pass  **n**  diagnostic tests and get the chance to attend placement drives. She will be eligible to attend placement drives if the average score for all the tests is atleast  **AVG**. Each test score cannot exceed  **R**. She got score Ai for the i-th test.

- if she is eligible to attend placement drives, print 0.
- else she will be given a second chance to increase tests score based on below conditions:
- To increase the score for the i-th test by 1. She needs to prepare Bi programming questions for the upcomming contest in their college.
- She can raise the test score multiple times.

Sam wants to help his CRUSH in preparing programming questions. They don't know how many questions they need to prepare. Sam asks your help to find minimum number of questions required to prepare so that his CRUSH will be eligible for placement drives.

 **Input Format** 

- First line contains t, Number of testcases.
- Next line contains 3 integers i.e., n (number of tests), R(Maximum score), AVG(Required average score).
- Next line contains n integers separated spaces i.e., Ai (0 <= i <= n).
- Next line contains n integers separated spaces i.e., Bi (0 <= i <= n).

 **Constraints** 

- 1 <= t <= 100
- 1 ≤  n ≤  103
- 1 ≤  R ≤  103
- 1 ≤  AVG ≤  min(R, 103)
- 1 <= Ai <= R
- 1 <= Bi <= 103

 **Output Format** 

For each testcase, print minimum number of questions in separate line.

 **Sample Input 0** 

```
2
5 5 4
5 4 3 3 2
2 7 1 2 5
2 5 4
5 5
2 2

```

 **Sample Output 0** 

```
4
0

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T19:46:35.354Z  

```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int score;
    int cost;
} Test;

int compare(const void *a, const void *b) {
    Test *x = (Test *)a;
    Test *y = (Test *)b;

    return x->cost - y->cost;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, R, AVG;
        scanf("%d %d %d", &n, &R, &AVG);

        int A[n], B[n];
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        long long required = (long long)n * AVG;

        if (sum >= required) {
            printf("0\n");
            continue;
        }

        Test tests[n];

        for (int i = 0; i < n; i++) {
            tests[i].score = A[i];
            tests[i].cost = B[i];
        }

        qsort(tests, n, sizeof(Test), compare);

        long long answer = 0;
        long long need = required - sum;

        for (int i = 0; i < n && need > 0; i++) {
            int canIncrease = R - tests[i].score;

            long long increase = canIncrease;

            if (increase > need)
                increase = need;

            answer += increase * tests[i].cost;
            need -= increase;
        }

        printf("%lld\n", answer);
    }

    return 0;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/help-sam-to-impress-his-crush/problem)