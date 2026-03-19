class NStack {
    int *arr, *top, *next;
    int n, s;
    int freeSpot;

public:
    NStack(int N, int S) {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i = 0; i < n; i++)
            top[i] = -1;

        for(int i = 0; i < s-1; i++)
            next[i] = i+1;

        next[s-1] = -1;
        freeSpot = 0;
    }

    bool push(int x, int m) {

        if(freeSpot == -1)
            return false; // overflow

        int index = freeSpot;

        freeSpot = next[index];

        arr[index] = x;

        next[index] = top[m-1];

        top[m-1] = index;

        return true;
    }

    int pop(int m) {

        if(top[m-1] == -1)
            return -1; // underflow

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

time cpmplexity o(n)
space o(s+n)

// push


// 1. Take freeSpot index
// 2. Move freeSpot to next free
// 3. Insert element
// 4. Link to previous top
// 5. Update top

// arr   = values
// top   = index of top of each stack
// next  = links (like linked list)
// next = prev element is smothnig is there or next freespace
