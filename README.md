# Sorting-visualization-in-R-and-C-
Objective : Size vs Swaps visualization in R and C++



# READ ME FOR ASSIGNMENT.CPP FILE 


The code is written in R and C++,
Visualization part is done in R 
Sorting algorithms are done  in C++ 
(using Rcpp library)

C++ code consists of 5 function 
-------------------------------

1)  int insertSort(NumericVector arr, int size)
    
    this function sorts the <NumericVector> 1D array 
    of size = "size", and returns the number of 
    comparison done while sorting arr array.

2)  int quickSort(NumericVector arr, int p, int r)
    
    this function sorts the <NumericVector> array using 
    partition function(divide and conquer approach)
    where arr is the 1D array and p and r the lower 
    and upper bounds of the arr array. And returns the 
    number of comparisons in while sorting.
    
3)  int mergeSort(NumericVector arr, int first, int last)
    
    this function sorts the array using merge function 
    and return the number of comparison while sorting array.
    
    

Code written under /***R ..somecode.. */ is the R code 
which is used for visualization purposes and curve fitting

R functions and library used 
----------------------------

1)  plot, and lines function of base R 
    
    plot() : for plotting points in 2D space(size vs comparisons)
    lines() : for plotting different curves in the same plot.

2)  trendline function of library "basicTrendline" 
    
    trendline() : for curve fitting and giving summary of plots(R^2 etc)
    
# How to run
                        
Connect R the directory that contains assignment.cpp file

just write this line in the console : 

1. Rcpp::sourceCpp('assigment.cpp') or 
2. Rcpp::sourceCpp(file.choose())   //to manually pick the file.

Then, program will plot 6 plots, automatically. 
# incase the program is ubable to run properly then check if necessary libraries are installed on the system or not 
* try :  install.packages(Rcpp)
  install.packages(basictrendline) 
    
