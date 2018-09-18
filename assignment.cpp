#include <Rcpp.h>   //for running c plus plus code in R 
#include <numeric>  //for using numeric array 
using namespace Rcpp;  
// [[Rcpp::export]]   
int insertSort(NumericVector arr, int size) //Sorting function that implements Insertion Sort algorithm
{
  int i, k, temp, count=0;
  for(k=1; k<size; k++)
  {
    temp = arr[k];
    for(i=k; (i>0 && ++count && temp<arr[i-1]); i--) //increment count when ever there is a comparison
      arr[i] = arr[i-1];
    arr[i] = temp;
  }
  return (count);                       //returing the number of comparison taken by 
                                        //insetion sort algorithm for size = "size" 
}
// [[Rcpp::export]]
int partition(NumericVector arr, int p, int r, int &count)
{                                       //partition function for quicksort
  int x, i, j;
  int temp;
  x = arr[r];
  i = p-1;
  for(j=p; j<r; j++)
  {
    ++count;                //count incremented here 
    if(arr[j]<=x)
    {
      i++;
      temp = arr[i];        //swapping 
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i+1];
  arr[i+1] = arr[r];
  arr[r] = temp;
  
  return i+1;           
}
// [[Rcpp::export]]
int quickSort(NumericVector arr, int p, int r)
{
  int q, count=0;
  if(p<r)
  {
    q = partition(arr, p, r, count);
    count += quickSort(arr, p, q-1);   //  count incremented for both halves
    count += quickSort(arr, q+1, r);   //
  }
  return count;
}
// [[Rcpp::export]]
void merge(NumericVector arr, int first, int last, int &count)
{
  int i, i1, i2, mid;
  int *temp = new int [last-first+1];
  mid = (first+last)/2;
  i = 0;
  i1 = first;
  i2 = mid+1;
  
  while(i1<=mid && i2<=last)
  {
    ++count;
    if(arr[i1]<arr[i2]) 
      temp[i++] = arr[i1++];
    else 
      temp[i++] = arr[i2++];
  }
  
  while(i1<=mid)
    temp[i++] = arr[i1++];
    
  while(i2<=last)
    temp[i++] = arr[i2++];
  
  for(i=first; i<=last; i++) 
    arr[i] = temp[i-first];
}
// [[Rcpp::export]]
int mergeSort(NumericVector arr, int first, int last)
{
  int mid, count=0;
  if(first<last)
  {
    mid = (first+last)/2;
    count += mergeSort(arr, first, mid);
    count += mergeSort(arr, mid+1, last);
    merge(arr, first, last, count);
  }
  return count;
}

/***R

insert_sum = 0
merge_sum = 0   #algo_sum for storing sum of 20 iterations 
quick_sum = 0
x = c()
insert_y = c()   #
quick_y = c()    #   algo_y for storing y coordinate data 
merge_y = c()    #
for(size in seq(10, 1000, 10))
{
  insert_sum = 0          #
  merge_sum = 0           #    algo_sum for storing sum of 20 iterations 
  quick_sum = 0           #
  x<-append(x, size)      #    storing the size of the arrays in x varible 
  for(i in 1:20)          #    running 20 iteration with size of array to be 
                          #    stored in "size" variable 
  {
    data_insert <- sample(size)   #
    data_quick <- data_insert     #   Same data for all 3 algorithms 
    data_merge <- data_insert     #
    
    insert_sum = insert_sum + insertSort(data_insert, size)    #
    quick_sum = quick_sum + quickSort(data_quick, 0, size-1)   #   storing sum of all comparison 
    merge_sum = merge_sum + mergeSort(data_merge, 0, size-1)   #   taken in 20 iterations 
  }
  insert_y = append(insert_y, insert_sum / 20)  #storing the average of 20 iterations 
  quick_y = append(quick_y, quick_sum / 20)     #storing the average of 20 iterations
  merge_y = append(merge_y, merge_sum / 20)     #storing the average of 20 iterations
}

plot(x, insert_y, 
     type = "l", xlab = "Size", 
     ylab = "InsertionSort comparisons", 
     main="Size vs comparisons")
#plotting for insertion sort 

plot(x, quick_y,
     main="Size vs comparisons", 
     col = "green",type="l",xlab = "Size", 
     ylab = "QuickSort comparisons")
#plotting for quick sort

plot(x, merge_y,
     main="Size vs comparisons", 
     col = "red",type="l",xlab = "Size",      
     ylab = "MergeSort comparisons")
#plotting for merge sort 




trendline(x, quick_y,type="l", model="power3P", main = "Fitting for QuickSort"
          ,xlab = "Sizes", ylab = "Comparisons")
#model is => "power3P": y=a*x^b+c

trendline(x, insert_y, type="l", model="line3P",xlab = "Sizes"
          ,ylab = "Insertion Sort Comparisons", main = "Fitting for Insertions Sort")
#model is => "line3P": y=a*x^2+b*x+c

trendline(x, merge_y, type="l", model="power3P", 
          xlab = "Sizes", ylab = "Merge comparisons", 
          main = "Fitting for Merge sort\n Red is nlogn")
#model is => "power3P": y=a*x^b+c

lines(x, x*log2(x), col = "red")   #red is nlogn
#drawn for reference 


*/


