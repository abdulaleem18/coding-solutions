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
