#include <iostream>
#include <ctime>
using namespace std;


int linearSearch(int arr[], int n, int key){
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int recursiveLinearSearch(int arr[], int l, int r, int x){
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    return recursiveLinearSearch(arr, l + 1,r - 1, x);
}

int binarySearch( int* arr, int low, int high, int key) {
    if ( low > high )
        return -1;
    int mid = (low + high) / 2;
    if ( arr[mid] == key )
        return mid;
    if ( arr[mid] > key )
        return binarySearch( arr, low, mid - 1, key );
    return binarySearch( arr, mid + 1, high, key );
}

int jumpSearch(int arr[], int key, int n){
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n)-1] < key){
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < key){
        prev++;
        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == key)
        return prev;
    return -1;
}


int main() {
    int n = 10;
    int key = 19;
    int output;

    //create random array with size n
    int test[n];
    for (int i = 0; i < n; ++i){
        test[i] = 0 + (rand() % static_cast<int>(n*10 - 0 + 1));
    }

    //sort array
    sort(test, test+n);

    //print array
    cout <<"Test 1: [";
    for (const auto& e : test) {
        cout << e << ",";
    }
    cout<< "]" << endl;

    cout << "---------------Linear Search---------------" << endl;
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    output = linearSearch(test, n, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "-------------------------------------------" << endl;

    cout << "----------Recursive Linear Search----------" << endl;
    //Store the starting time
    startTime = clock();
    //Code block
    output = recursiveLinearSearch(test,0, n-1, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "-------------------------------------------" << endl;

    cout << "---------------Binary Search---------------" << endl;
    //Store the starting time
    startTime = clock();
    //Code block
    output = binarySearch(test,0,n-1,key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "-------------------------------------------" << endl;


    cout << "----------------Jump Search----------------" << endl;
    //Store the starting time
    startTime = clock();
    //Code block
    output = jumpSearch(test, key, n);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "-------------------------------------------" << endl;


}
