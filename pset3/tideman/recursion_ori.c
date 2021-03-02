#include <stdio.h>

// This function will use merge sort to practice recursion.

// Prototype
void rec(int n, int s);

// Array of numbers.
int a[10] = {5, 1, 6, 2, 7, 3, 8, 4, 9, 0};
int a_c = 10;
// int a[5] = {4, 3, 3, 2, 4};
// int a_c = 5;

int main(void)
{
    int start = 0;
    rec(10, start);

    for (int i = 0; i < 10; i++)
    {
        printf("Rank %d has the value %d.\n", i + 1, a[i]);
    }
    
}

void rec(int n, int s)
{
    // This is the main recursion function. var.int n = how many numbers to sort, var.int s = starting index in the array.

    // If n < 2, meaning theres only 1 or 0 numbers to sort, then return.
    if (n < 2)
    {
        return;
    }

    // Working out the new variables needed for left and right merge sort.
    int leftn, rightn, lefts, rights = 0; // variables for left half and right half.

    if (n % 2 == 1) // If odd.
    {
        leftn = (n + 1) / 2;
        rightn = (n - 1 ) / 2;
        lefts = s;
        rights = s + (n + 1) / 2;
    }
    else // If even.
    {
        leftn = n / 2;
        rightn = n / 2;
        lefts = s;
        rights = s + (n / 2);
    }

    // Merge sort left half and right half.
    rec(leftn, lefts);
    rec(rightn, rights);

    // Now to sort the actual left and right arrays.
    // We need use the leftn and right n value;
    // as well as new variables here to manage the locations as well as to store the values in the array.

    // current left count and right count.
    int leftc = 0;
    int rightc = 0;
    int b[n]; // temporary array to store the sorted array.


    for (int i = 0; i < n ; i++)
    {
        int loc = s + i; // location in the new array where we will place the sorted value.
        int leftloc = lefts + leftc;
        int rightloc = rights + rightc;
        int leftv = a[lefts + leftc];
        int rightv = a[rights + rightc];

        // If there are no more numbers in the left half of the array, the popular new array using right half.
        if (leftc >= leftn)
        {
            b[i] =  rightv;
            rightc++;
        }
        // If there are no more numbers in the right half of the array, the popular new array using left half.
        else if (rightc >= rightn)
        {
            b[i] = leftv;
            leftc++;
        }
        // If left value is greater than right.
        else if (leftv > rightv)
        {
            b[i] = leftv;
            leftc++;
        }
        // If right value is greater than left.
        else if (rightv > leftv)
        {
            b[i] = rightv;
            rightc++;
        }
        else if (leftv == rightv)
        {
            b[i] = leftv;
            leftc++;
        }
        else
        {
            printf("Sorting error.\n");
            return;
        }
    }
    // Updating original array with sorted array.
    for (int i = 0; i < n; i++)
    {
        a[s + i] = b[i];
    }
}



