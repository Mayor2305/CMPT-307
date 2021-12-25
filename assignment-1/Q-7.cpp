#include <iostream>
#include <ctime>
#include <cmath>
#include <limits>
using namespace std;

int* Find_Maximum_Crossing(int* array,int LeftIndex,int mid,int RightIndex)
{
  int sum_left = -1.0 * (numeric_limits <int> :: max());
  int sum = 0;
  int* return_array = new int [3];
  for (int i = mid; i >= LeftIndex; i--)
  {
    sum = sum + array[i];
    if(sum > sum_left)
    {
      sum_left = sum;
      return_array[0] = i;
    }
  }
  int sum_right = -1.0 * (numeric_limits <int> :: max());
  sum = 0;
  for (int i = mid+1; i <= RightIndex; i++)
  {
    sum = sum + array[i];
    if(sum > sum_right)
    {
      sum_right = sum;
      return_array[2] = i;
    }
  }
  return_array[1] = sum_left + sum_right;
  return return_array;

}


int* Find_Maximum_Subarray(int* array, int LeftIndex, int RightIndex)
{
  int* AL;
  int* AR;
  int* AC;

  if(LeftIndex != RightIndex)
  {
    int mid = (LeftIndex + RightIndex) / 2;

    AL = Find_Maximum_Subarray(array, LeftIndex, mid);
    AR = Find_Maximum_Subarray(array, mid + 1, RightIndex);
    AC = Find_Maximum_Crossing(array, LeftIndex, mid, RightIndex);

    if(AL[1] >= AR[1] && AL[1] >= AC[1])
    {
      delete[] AR;
      delete[] AC;
      return AL;
    }
    else if(AR[1] >= AL[1] && AR[1] >= AC[1])
    {
      delete[] AL;
      delete[] AC;
      return AR;
    }
    else
    {
      delete[] AL;
      delete[] AR;
      return AC;
    }

  }
  else
  {
    int* temp_arr = new int[3];
    temp_arr[0] = LeftIndex;
    temp_arr[1] = array[LeftIndex];
    temp_arr[2] = RightIndex;
    return temp_arr;
  }
}


int BruteForce (int* array, int* LeftIndex, int* RightIndex, int size)
{
  int sum = -1.0 * (numeric_limits <int> :: max());
  int i, j, k = 0;
  for (i = 0; i < size; )
  {
      int temp_sum = 0;
      k = k + 1;

      if(k >= size)
      {
        i ++;
        if(i == size)
         break;
        k = i + 1;
      }
      for(j = i; j < k ; j++)
      {
        temp_sum = temp_sum + array[j];
      }
      if(sum < temp_sum)
      {
        sum = temp_sum;
        *RightIndex = j-1;
        *LeftIndex = i;
      }
  }
  return sum;
}

int main()
{
  srand(time(NULL));
  // sizes
  int array_size1 = 100;
  int array_size2 = 20;
  int array_size3 = 50;
  int array_size4 =100;
  int array_size5 = 200;
  int array_size6 = 500;
  int array_size7 = 1000;

  // arrays
  int array1[array_size1];
  int array2[array_size2];
  int array3[array_size3];
  int array4[array_size4];
  int array5[array_size5];
  int array6[array_size6];
  int array7[array_size7];


  int left = 0;
  int right;
  for (int i = 0; i < array_size7; i++)
  {
    if(i < array_size1)
      array1[i] = pow(-1,i) * (rand() % 512);

    if(i < array_size2)
        array2[i] = pow(-1,i) * (rand() % 512);

    if(i < array_size3)
      array3[i] = pow(-1,i) * (rand() % 512);

    if(i < array_size4)
      array4[i] = pow(-1,i) * (rand() % 512);

    if(i < array_size5)
      array5[i] = pow(-1,i) * (rand() % 512);

    if(i < array_size6)
      array6[i] = pow(-1,i) * (rand() % 512);

    array7[i] = pow(-1,i) * (rand() % 512);
  }

  // time taken by brute force
  right = array_size1;
  clock_t BF_time = clock();
  int sum = BruteForce(array1, &left, &right, array_size1);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size1 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size1;
  clock_t DC_time = clock();
  int* result = Find_Maximum_Subarray (array1, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size1 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

  cout<<endl;

  // time taken by brute force
  right = array_size2;
  BF_time = clock();
  sum = BruteForce(array2, &left, &right, array_size2);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size2 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size2;
  DC_time = clock();
  result = Find_Maximum_Subarray (array2, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size2 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

  cout<<endl;

  // time taken by brute force
  right = array_size3;
  BF_time = clock();
  sum = BruteForce(array3, &left, &right, array_size3);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size3 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size3;
  DC_time = clock();
  result = Find_Maximum_Subarray (array3, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size3 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

  cout<<endl;

  // time taken by brute force
  right = array_size4;
  BF_time = clock();
  sum = BruteForce(array4, &left, &right, array_size4);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size4 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size4;
  DC_time = clock();
  result = Find_Maximum_Subarray (array4, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size4 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

  cout<<endl;

  // time taken by brute force
  right = array_size5;
  BF_time = clock();
  sum = BruteForce(array5, &left, &right, array_size5);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size5 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size5;
  DC_time = clock();
  result = Find_Maximum_Subarray (array5, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size5 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

  cout<<endl;

  // time taken by brute force
  right = array_size6;
  BF_time = clock();
  sum = BruteForce(array6, &left, &right, array_size6);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size6 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size6;
  DC_time = clock();
  result = Find_Maximum_Subarray (array6, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size6 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

  cout<<endl;

  // time taken by brute force
  right = array_size7;
  BF_time = clock();
  sum = BruteForce(array7, &left, &right, array_size7);
  BF_time = clock() - BF_time;

  cout<<"BruteForce time for array size = "<< array_size7 <<" is "<< (1.0 * BF_time) / CLOCKS_PER_SEC << " sec "<< endl;

  // time taken by Divide and conquer
  left = 0;
  right = array_size7;
  DC_time = clock();
  result = Find_Maximum_Subarray (array7, left, right);
  DC_time = clock() - DC_time;
  cout<<"Divide and Conquer time for array size = "<< array_size7 <<" is "<< (1.0 * DC_time) / CLOCKS_PER_SEC << " sec " << endl;
  delete[] result;

}
