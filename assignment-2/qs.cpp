#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

int partition(int * arr, int l, int r)
{
  int random = (rand() % (r - l + 1)) + l;


  int tempElement = arr[r];
  arr[r] = arr[random];
  arr[random] = tempElement;


  int x = arr[r];
  int i = l - 1;
  for(int j = l; j < r; j++)
  {
    if(arr[j] <= x)
    {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i+1];
  arr[i+1] = arr[r];
  arr[r] = temp;

  return i + 1;
}

void InsertionSort(int* arr, int l, int r)
{
  for (int j = l + 1; j < r; j++)
  {
    int temp = arr[j];
    int i = j - 1;
    while(i >= 0 && arr[i] > temp)
    {
      arr[i+1] = arr[i];
      i--;
    }
    arr[i+1] = temp;
  }
}

void RandomizedQuicksortLecture(int* arr, int l, int r)
{
  if(l >= r)
    return;

      int part = partition(arr, l, r);
      RandomizedQuicksortLecture(arr, l, part - 1);
      RandomizedQuicksortLecture(arr, part + 1, r);

}

void RandomizedQuicksort(int* arr, int k, int l, int r)
{
  if(l >= r)
    return;
  if(r - l > k)
  {
      int part = partition(arr, l, r);
      RandomizedQuicksortLecture(arr, l, part - 1);
      RandomizedQuicksortLecture(arr, part + 1, r);
  }
  else
  {
    InsertionSort(arr, l, r + 1);
  }
}



int main()
{
srand(time(NULL));
int n_values[] = {0,1,2,3,4,5};

for(int i =0 ; i< 6 ; i++)
{
int size = pow(2,n_values[i]) * 1000;
int* arr1 = new int[size];
int* arr2 = new int[size];

for (int j =0; j<size; j++)
{
int temp =  rand()%200 + (-100);
arr1[j] = temp;
arr2[j] = temp;
}

cout<<"FOR N = "<<size<<" : "<<endl;

clock_t random_quick = clock();
RandomizedQuicksortLecture(arr1,0,size-1);
random_quick = clock() - random_quick;
cout<<"TIME FOR RANDOMIZED QUICK SORT = "<<(float) random_quick / CLOCKS_PER_SEC<<" seconds"<<endl;

int k = 8;

clock_t quick_insertion = clock();
RandomizedQuicksort(arr2,k,0,size-1);
quick_insertion = clock() - quick_insertion;
cout<<"TIME FOR RANDOMIZED QUICK SORT-INSERTION SORT = "<<(float) quick_insertion / CLOCKS_PER_SEC<<" seconds"<<endl;

cout<<endl;
}


return 0;
}
