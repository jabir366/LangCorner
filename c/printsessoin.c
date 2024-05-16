#include <stdio.h>
#include <unistd.h>

int main() {
    // Get the session ID of the current user
    pid_t session_id = getsid(0);
    
    if(session_id == -1) {
        perror("getsid");
        return 1;
    }

    printf("Session ID: %d\n", session_id);
    printf("Size of session ID: %lu bytes\n", sizeof(session_id));

    return 0;
}

