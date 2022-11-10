/*
Name - Akshit Sharma
SID - 21107018
BRANCH - Mechanical

*/

#include <iostream>
#include <sys/time.h>
using namespace std;


//time complexity of this code is - O(n^2).
pair<int,int> bubbleSort(int *input, int size)
{
    int count_swaps = 0;
    // this is created to maintain the count of number of swaps
    int count_comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                count_swaps++;
            }
            count_comparisons++;
        }
    }
    pair<int,int> ans;
    ans.first = count_swaps;
    //the first member would store the number of swaps.
    ans.second = count_comparisons;
    //the second member would store the umber of comparisons.
    
    return ans;
}


//time complexity of this code is - O(n^2).
pair<int,int> SelectionSort(int *input,int size)
{
    int min_index;
    int count_swaps = 0;
    int count_comparisons = 0;
    for(int i=0;i<size;i++)
    {
        min_index = i;
        for(int j=i+1;j<size;j++)
        {
            if(input[j]<input[min_index])
            {
                min_index = j;
                count_swaps++;
            }
            count_comparisons++;
        }
        int temp = input[i];
        input[i] = input[min_index];
        input[min_index] = temp;
    }
    pair<int,int> ans;
    ans.first = count_swaps;
    ans.second = count_comparisons;
    return ans;
}


// Time-run calculator
long getTimeinMicroseconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}



int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];

    cout<< "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<int,int> bubble = bubbleSort(arr,n);
    pair<int,int> selection = SelectionSort(arr,n);

    cout << "comparison between Bubble sort and Selection sort. " << endl;
    cout << endl;

    cout << "1. on the basis of number of comparisons :  " << " ";
    if(bubble.second > selection.second)
    {
        cout << "more comparisions are required for BUBBLE SORT." << endl; 
    }
    else if(bubble.second < selection.second)
    {
        cout << "more comparisions are required for SELECTION SORT." << endl;
    }
    else
    {
        cout << "both require equal number of comparisons." << endl;
    }
    cout << endl;

    //second comparison

    cout << "2. on the basis of number of swaps : " << " ";
    if(bubble.first > selection.first)
    {
        cout << "MORE SWAPS ARE REQUIRED FOR BUBBLE SORT." << endl;
    }
    else if(bubble.first < selection.first)
    {
        cout << "MORE SWAPS ARE REQUIRED FOR SELECTION SORT." << endl;
    }
    else
    {
        cout << "BOTH REQUIRE EQUAL NUMBER OF SWAPS." << endl;
    }
    cout << endl;

    cout << "3 . As both BubbleSort and SelectionSort are In-place algorithms, hence both of their Inplace Algorithms have been written above." << endl;

    cout<< "3 . ON THE BASIS OF RUN-TIME OF CODE. "<<endl;
    for (int n=10; n<=10000; n*=10){
        int *arr = new int[n];
        long start_time, end_time;
        for(int i=0; i<n; i++) {
            arr[i] = n-i;
        }
        //Bubble sort complexity
        start_time = getTimeinMicroseconds();
        bubble = bubbleSort(arr,n);
        end_time = getTimeinMicroseconds();
        cout<<"BubbleSort for n= "<<n<<" time = "<<end_time-start_time<<" nanoseconds."<<endl;

        //Selection sort complexity
        start_time = getTimeinMicroseconds();
        selection = SelectionSort(arr,n);
        end_time = getTimeinMicroseconds();
        cout<<"SelectionSort for n= "<<n<<" time = "<<end_time-start_time <<" nanoseconds." <<endl;
        cout<<endl;
        
    }   
    cout<<"CLEARLY SELECTION SORT IS FASTER THAN BUBBLE SORT FOR LARGE SIZE ARRAY."<<endl;

    return 0;
}



