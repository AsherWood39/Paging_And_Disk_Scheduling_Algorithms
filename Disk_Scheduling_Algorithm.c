#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REQUESTS 100

int requests[MAX_REQUESTS], n, direction, disk_size;

// FCFS Disk Scheduling
void FCFS(int head) 
{
    printf("\nFCFS Disk Scheduling :\nRequest sequence : ");
    printf("%d ", head);
    for (int i = 0; i < n; i++) 
    {
        printf("-> %d ", requests[i]);
    }

    int movement = 0;
    for (int i = 0; i < n; i++) 
    {
        movement += abs(requests[i] - head);
        head = requests[i];
    }
    printf("\nTotal head movement : %d\n", movement);
}

// SCAN Disk Scheduling with full sequence printing
void SCAN(int head) 
{
    int movement = 0;

    printf("\nSCAN Disk Scheduling :\nRequest sequence : ");

    if (direction == 1) 
    { // Moving right
        int start = 0;
        while (start < n && requests[start] < head) start++;

        // Print movement to first request
        if (start < n) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move right through remaining requests
        for (int i = start + 1; i < n; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Move to end if needed
        if (head != disk_size - 1) 
        {
            printf("-> %d ", disk_size - 1);
            movement += abs(disk_size - 1 - head);
            head = disk_size - 1;
        }

        // Move left through remaining requests
        for (int i = start - 1; i >= 0; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    } 

    else 
    { // Moving left
        int start = n - 1;
        while (start >= 0 && requests[start] > head) start--;

        // Print movement to first request
        if (start >= 0) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move left through remaining requests
        for (int i = start - 1; i >= 0; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Move to start if needed
        if (head != 0) 
        {
            printf("-> 0 ");
            movement += abs(0 - head);
            head = 0;
        }

        // Move right through remaining requests
        for (int i = start + 1; i < n; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("\nTotal head movement: %d\n", movement);
}

// C-SCAN Disk Scheduling with full sequence printing
void C_SCAN(int head) 
{
    int movement = 0;

    printf("\nC-SCAN Disk Scheduling :\nRequest sequence : ");

    if (direction == 1) 
    { // Moving right
        int start = 0;
        while (start < n && requests[start] < head) start++;

        // Print movement to first request
        if (start < n) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move right through remaining requests
        for (int i = start + 1; i < n; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Jump to start if needed
        if (head != disk_size - 1) 
        {
            printf("-> %d -> 0 ", disk_size - 1);
            movement += abs(disk_size - 1 - head) + (disk_size - 1);
            head = 0;
        } 

        else 
        {
            printf("-> 0 ");
            movement += (disk_size - 1);
            head = 0;
        }

        // Move right through remaining requests
        for (int i = 0; i < start; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    } 

    else 
    { // Moving left
        int start = n - 1;
        while (start >= 0 && requests[start] > head) start--;

        // Print movement to first request
        if (start >= 0) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move left through remaining requests
        for (int i = start - 1; i >= 0; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Jump to end if needed
        if (head != 0) 
        {
            printf("-> 0 -> %d ", disk_size - 1);
            movement += abs(0 - head) + (disk_size - 1);
            head = disk_size - 1;
        } 
        else 
        {
            printf("-> %d ", disk_size - 1);
            movement += (disk_size - 1);
            head = disk_size - 1;
        }

        // Move left through remaining requests
        for (int i = n - 1; i > start; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("\nTotal head movement: %d\n", movement);
}

// LOOK Disk Scheduling with full sequence printing
void LOOK(int head) 
{
    int movement = 0;

    printf("\nLOOK Disk Scheduling :\nRequest sequence : ");

    if (direction == 1) 
    {   // Moving right
        int start = 0;
        while (start < n && requests[start] < head) start++;

        // Print movement to first request
        if (start < n) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move right through remaining requests
        for (int i = start + 1; i < n; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Move left through remaining requests
        for (int i = start - 1; i >= 0; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    } 

    else 
    {   // Moving left
        int start = n - 1;
        while (start >= 0 && requests[start] > head) start--;

        // Print movement to first request
        if (start >= 0) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move left through remaining requests
        for (int i = start - 1; i >= 0; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
        
        // Move right through remaining requests
        for (int i = start + 1; i < n; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("\nTotal head movement: %d\n", movement);
}

// C-LOOK Disk Scheduling with full sequence printing
void C_LOOK(int head) 
{
    int movement = 0;

    printf("\nC-LOOK Disk Scheduling :\nRequest sequence : ");

    if (direction == 1) 
    { // Moving right
        int start = 0;
        while (start < n && requests[start] < head) start++;

        // Print movement to first request
        if (start < n) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move right through remaining requests
        for (int i = start + 1; i < n; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Move right through remaining requests
        for (int i = 0; i < start; i++) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    } 

    else 
    { // Moving left
        int start = n - 1;
        while (start >= 0 && requests[start] > head) start--;

        // Print movement to first request
        if (start >= 0) 
        {
            printf("%d -> %d ", head, requests[start]);
            movement += abs(head - requests[start]);
            head = requests[start];
        }

        // Move left through remaining requests
        for (int i = start - 1; i >= 0; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }

        // Move left through remaining requests
        for (int i = n - 1; i > start; i--) 
        {
            printf("-> %d ", requests[i]);
            movement += abs(head - requests[i]);
            head = requests[i];
        }
    }

    printf("\nTotal head movement: %d\n", movement);
}
int main() 
{
    int head;
    printf("Enter the number of disk requests : ");
    scanf("%d", &n);

    printf("Enter the disk size (number of cylinders) : ");
    scanf("%d", &disk_size);

    printf("Enter the initial head position : ");
    scanf("%d", &head);

    printf("Enter the direction (1 for right, 0 for left) : ");
    scanf("%d", &direction);

    printf("Enter the disk requests : ");
    for (int i = 0; i < n; i++) {   scanf("%d", &requests[i]);    }

    for (int i = 0; i < n; i++) 
    {
        if (requests[i] < 0 || requests[i] >= disk_size) 
        {
            printf("Invalid request : %d\n", requests[i]);
            return 0;
        }
    }

    // FCFS
    FCFS(head);

    for (int i = 0; i < n; i++) 
    {
        for (int j=i + 1; j < n; j++) 
        {
            if (requests[i] > requests[j]) 
            {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // SCAN
    SCAN(head);

    // C-SCAN
    C_SCAN(head);

    // LOOK
    LOOK(head);

    // C-LOOK
    C_LOOK(head);

    return 0;
}
