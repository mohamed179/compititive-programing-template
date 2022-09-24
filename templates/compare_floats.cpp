#include <cstdio>
#include <cmath>

#define GREATER_THAN(X, Y) (((X) - (Y)) > 0.099f)
#define LESS_THAN(X, Y) (((Y) - (X)) > 0.099f)
#define GREATER_THAN_OR_EQUALS(X, Y) ((((X) - (Y)) > 0.099f) || (fabs(((X) - (Y))) < 0.00001f))
#define LESS_THAN_OR_EQUALS(X, Y) ((((Y) - (X)) > 0.099f) || (fabs(((Y) - (X))) < 0.00001f))
#define EQUALS(X, Y) (fabs(((X) - (Y))) < 0.00001f)

int main() {
    // your code here...
    return 0;
}