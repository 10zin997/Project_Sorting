//l = low,m = middle, h = high
#include<iostream>

using namespace std;

int COMPARISONS = 0;
int SWAPS = 0;

// Function: bubbleSort
int bubbleSort(int arrSize[],int numRange,int& compCount,int& swapCount);
void swap(int* arrSize,int* b); 
int part(int arrSize[], int l, int h);
//quickSort
void quickSort(int arrSize[],int l,int h);
//merge
void merge(int arrSize[],int l,int m,int h);
//mergeSort
int mergeSort(int arrSize[],int l,int h);

int main(){
    int arrSize[1000], numRange, choice1, choice2,
    compCount = 0, swapCount = 0,swapped;
    char cont;
do{
    cout << "Enter range to sort the elements: "<<endl;
    cin >> numRange;
    cout<< "Enter a choice among  1. almost sorted 2.random or 3.reverse sorted"<<endl;
    cout<< "Enter your choice: ";
    cin >> choice1;
    if (choice1 == 1){
        cout<<"Numbers are almost sorted order"<<endl;
    }
    else if(choice1 == 2){
        cout<<"Numbers are random order"<<endl;
    }
    else if(choice1 == 3){
        cout<<"Numbers are reverse sorted order"<<endl;
    }
  switch (choice1)
  {
    case 1: 
        for(int i = 0; i < numRange; i++){
            arrSize[i] = rand() %5 + i;
        }
        cout<< "The numbers are: "<<endl;
        for(int i = 0; i < numRange; i++){
            cout<<arrSize[i]<<" ";
        }
        cout<<endl;
        break;
    case 2: 
        for(int i = 0; i < numRange; i++){
            arrSize[i] = rand() % 100 + i;
        }
        cout<< "The numbers are: "<<endl;
        for(int i = 0; i < numRange; i++){
            cout<<arrSize[i]<<" ";
        }
        cout<<endl;
        break;
 //reverse order
    case 3: 
        for(int i = 0; i < numRange; i++){
            arrSize[i] = numRange - i;
        }
        cout<< "The numbers are: "<<endl;
        for(int i = 0; i < numRange; i++){
            cout<<arrSize[i]<<" ";
        }
        cout<<endl;
        break;
    default:
        cout<<"Invalid choice"<<endl;
        return 0;

  }  
  cout<< "Enter choice of Sort: 1. Bubble Sort 2. Quick Sort 3. Merge Sort"<<endl;
    cout<< "Enter your choice: ";
    cin >> choice2;
    switch (choice2)
    {
        case 1:
            cout<<"Sorting using Bubble Sort"<<endl;
            bubbleSort(arrSize,numRange,compCount,swapCount);
            break;
        case 2:
            cout<<"Sorting using Quick Sort"<<endl;
            quickSort(arrSize,0,numRange-1);
            break;  
        case 3:
            cout<<"Sorting using Merge Sort"<<endl;
            mergeSort(arrSize,0,numRange-1);
            break;
        default:
            cout<<"Invalid choice"<<endl;
            return 0;
    }
    cout<<"Sorted array is: "<<endl;
    for(int i = 0; i < numRange; i++){
        cout<<arrSize[i]<<" ";
    }
    cout<<endl;
    swapped = bubbleSort(arrSize,numRange,compCount,swapCount);
    if(swapped){
        cout<<" this is total number of comaprisons: "<<compCount<<endl;
        compCount = 0;
        cout<<" this is total number of swaps: "<<swapCount<<endl;
        SWAPS = 0;
    }else{
        cout<<" this is total number of comaprisons: "<<COMPARISONS<<endl;
        COMPARISONS = 0;
        cout<<" this is total number of swaps: "<<SWAPS<<endl;
        SWAPS = 0;
    }
    cout<<"==================================================="<<endl;
    cout<<"Do you want to continue? (y/n)"<<endl;
    cout<<"==================================================="<<endl;
    cin>>cont;
}while(cont == 'y' || cont == 'Y');
return 0;
}

//bubbble sort check
int bubbleSort(int arrSize[],int numRange,int& compCount,int& swapCount){
    int swapped = 0;
    for(int i = 0; i < numRange; i++){
        for(int j = 0; j < numRange-1; j++){
            compCount++;
            if(arrSize[i] < arrSize[j]){
                compCount++;
                 swapped = arrSize[i];
                arrSize[i] = arrSize[j];
                arrSize[j] = swapped;
               
            }
        }
    }
    return swapped;
}

//swap
void swap(int* arrSize,int* b){
    int temp = *arrSize;
    *arrSize = *b;
    *b = temp;
    SWAPS++;
}
//part
int part(int arrSize[], int l, int h){
    int pivot = arrSize[h];
    int index = l-1;
    for(int j = l; j <= h-1; j++){
        if(arrSize[j] <= pivot){
            index++;
            swap(&arrSize[index],&arrSize[j]);
        }
    }
    swap(&arrSize[index+1],&arrSize[h]);
    return (index+1);
}

//quick sort

void quickSort(int arrSize[],int l,int h){
    int index;
    if(l < h){
        COMPARISONS++;
        index = part(arrSize,l,h);
        quickSort(arrSize,l,index-1);
        quickSort(arrSize,index+1,h);
    }
}
//merge sort

int mergeSort (int arrSize[],int l,int h){
    int m;
    if(l < h){
        SWAPS++;
        m = (l+h)/2;
        mergeSort(arrSize,l,m);
        mergeSort(arrSize,m+1,h);
        merge(arrSize,l,m,h);
    }
    return SWAPS;
}

//merge

void merge(int arrSize[],int l,int m,int h){
    int val1,val2,val3,b[200];
    val1 = l;
    val2 = m+1;
    val3 = l;

    while(val1 <= m && val2 <= h){
        if(arrSize[val1] <= arrSize[val2]){
            b[val3] = arrSize[val1];
            val1++;
        }else{
            b[val3] = arrSize[val2];
            val2++;
        }
        val3++;
    }
    if(val1 > m){
        COMPARISONS++;
        for(int i = val2; i <= h; i++){
            b[val3] = arrSize[i];
            val3++;
        }
    }
    else{
        COMPARISONS++;
        for(int i = val1; i <= m; i++){
            b[val3] = arrSize[i];
            val3++;
        }
    }
    for(int i = l; i <= h; i++){
        arrSize[i] = b[i];
    }
}

   
    