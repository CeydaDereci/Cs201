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
    int key;
    int output;

    //create four random arrays with size N
    int test1[n], test2[n], test3[n], test4[n];
    for (int i = 0; i < n; ++i){
        test1[i] = 0 + (rand() % static_cast<int>(n*10 - 0 + 1));
        test2[i] = 0 + (rand() % static_cast<int>(n*10 - 0 + 1));
        test3[i] = 0 + (rand() % static_cast<int>(n*10 - 0 + 1));
        test4[i] = 0 + (rand() % static_cast<int>(n*10 - 0 + 1));
    }

    //sort arrays
    sort(test1, test1+n);
    sort(test2, test2+n);
    sort(test3, test3+n);
    sort(test4, test4+n);

    //print arrays
    cout <<"Test 1: [";
    for (const auto& e : test1) {
        cout << e << ",";
    }
    cout<< "]" << endl;
    cout <<"Test 2: [";
    for (const auto& e : test2) {
        cout << e << ",";
    }
    cout<< "]" << endl;
    cout <<"Test 3: [";
    for (const auto& e : test3) {
        cout << e << ",";
    }
    cout<< "]" << endl;
    cout <<"Test 4: [";
    for (const auto& e : test4) {
        cout << e << ",";
    }

    cout<< "]" << endl << "Enter key: ";
    cin>> key;
    cout << endl;

    cout << "---------------Linear Search---------------" << endl;
    cout << "---Test 1---\n";
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    output = linearSearch(test1, n, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 2---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = linearSearch(test2, n, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 3---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = linearSearch(test3, n, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 4---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = linearSearch(test4, n, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "----------Recursive Linear Search----------" << endl;
    cout << "---Test 1---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = recursiveLinearSearch(test1,0, n-1, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 2---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = recursiveLinearSearch(test2,0, n-1, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 3---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = recursiveLinearSearch(test3,0, n-1, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 4---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = recursiveLinearSearch(test4,0, n-1, key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;



    cout << "---------------Binary Search---------------" << endl;
    cout << "---Test 1---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = binarySearch(test1,0,n-1,key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 2---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = binarySearch(test2,0,n-1,key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 3---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = binarySearch(test3,0,n-1,key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 4---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = binarySearch(test4,0,n - 1,key);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "----------------Jump Search----------------" << endl;
    cout << "---Test 1---\n";
    //Store the starting time
    startTime = clock();
    //Code block
    output = jumpSearch(test1, key, n);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 2---\n";
    startTime = clock();
    //Code block
    output = jumpSearch(test2, key, n);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 3---\n";
    startTime = clock();
    //Code block
    output = jumpSearch(test3, key, n);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;

    cout << "---Test 4---\n";
    startTime = clock();
    //Code block
    output = jumpSearch(test4, key, n);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime) / CLOCKS_PER_SEC;
    cout << key << " is at index: " << output << endl;
    cout << "Execution took " << duration << " milliseconds." << endl;


}
