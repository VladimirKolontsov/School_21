#include "data_stat.h"

double max(double *data, int n) {
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
  return max;
}

double min(double *data, int n) {
    double min = max(data, n);
    for (int i = 0; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

double mean(double *data, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    return mean / (double)n;
}

double variance(double *data, int n) {
    double tmp = 0;
    if (n == 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        tmp += (data[i] - mean(data, n)) * (data[i] - mean(data, n));
    }
    return tmp / (double)n;
}
