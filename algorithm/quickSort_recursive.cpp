#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <time.h>

using namespace std;

void insertSort(vector<int>& data,int left,int right) {
  int temp = 0;
  for (int i=left+1; i<=right; ++i) {
    temp = data[i];
    int j=i;
    for ( ;j>left && temp<data[j-1]; --j)
      data[j] = data[j-1];
    data[j] = temp;
  }
}
int median3(vector<int>& data,int left,int right) {
  int center = (right+left)/2;
  if (data[right] < data[left])
    swap(data[right],data[left]);
  if (data[center] < data[left])
    swap(data[center],data[left]);
  if ( data[right] < data[center])
    swap(data[center],data[right]);

  swap(data[center],data[right-1]);
  return data[right-1];
}
void quickSort(vector<int>& data,int left,int right) {
  if (right-left >= 10) {
    int pivot = median3(data,left,right);
    int i = left;
    int j = right-1;
    for (;;) {
      while (data[++i] < pivot) {}
      while (pivot < data[--j]) {}

      if (i < j)
        swap(data[i],data[j]);
      else
        break;
    }
    swap(data[right-1],data[i]);
    quickSort(data,left,i-1);
    quickSort(data,i+1,right);
  } else {
    insertSort(data,left,right);
  }
}
int gen() {
  return rand()%100;
}
int main(int argc,char** argv) {
  vector<int> data;
  srand(time(0));
  generate_n(back_inserter(data),30,gen);
  copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
  cout << endl;
  quickSort(data,0,data.size()-1);
  copy(data.begin(),data.end(),ostream_iterator<int>(cout," "));
  cout << endl;
  return 0;
}
