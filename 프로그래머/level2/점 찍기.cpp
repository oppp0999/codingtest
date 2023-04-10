#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(int k, int d)
{
    long long answer = 0;

    for (long long i = 0; i <= d; i += k) {
        answer += (int)(sqrt(pow(d, 2) - pow(i , 2))) / k + 1;
    }

    return answer;
}