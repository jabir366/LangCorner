#include <stdio.h>
#include <utmpx.h>

int main() {
    // Print the size of ut_session field in utmpx structure
    printf("Size of ut_session: %lu bytes\n", sizeof(((struct utmpx *)0)->ut_session));

    return 0;
}
