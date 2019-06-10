package sort;

import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);
    int arr[], l, i, choice;
    while(true){
      System.out.print("Please input length: ");
      l = input.nextInt();
      arr = new int[l];
      System.out.print("Please input arr: ");
      for(i = 0; i < arr.length; ++i){
        arr[i] = input.nextInt();
      }
      System.out.println("Please choose sort method ");
      System.out.println("1: Binary Insertion Sort");
      System.out.println("2: Bubble Sort");
      System.out.println("3: Quick Sort");
      System.out.println("4: Simple Selection Sort");
      System.out.println("5: Merging Sort");
      System.out.println("6: Heap Sort");
      System.out.println("0: quit");
      choice = input.nextInt();
      if(choice == 0) break;
      switch(choice){
      case 1:
        binaryInsertionSort(arr);
        break;
      case 2:
        bubbleSort(arr);
        break;
      case 3:
        int low = 0, high = arr.length;
        quickSort(arr, low, high - 1);
        break;
      case 4:
        seclectSort(arr);
        break;
      case 5:
    	mergeSort(arr);
        break;
      case 6:
        heapSort(arr);
        break;
      default:
        System.out.println("input error!");
      }
      System.out.println(Arrays.toString(arr));
    }
    input.close();
  }

  static void binaryInsertionSort(int arr[]){
    int lookout, low, high, m;
    for(int i = 1; i < arr.length; ++i){
      lookout = arr[i];
      low = 0;
      high = i - 1;
      while(low <= high){
        m = (low + high) / 2;
        if(lookout < arr[m]) high = m - 1;
        else low = m + 1;
      }
      for(int j = i - 1; j >= high + 1; --j) arr[j+1] = arr[j];
      arr[high+1] = lookout;
    }
  }

  static void bubbleSort(int arr[]){
    for(int i = 0; i < arr.length - 1; ++i){
      for(int j = 0; j < arr.length - 1 - i; ++j){
        if(arr[j] > arr[j+1]) swap(arr, j, j+1);
      }
    }
  }

  static int Partition(int arr[], int low, int high){
    int lookout, pivotkey;
    lookout = arr[low];
    pivotkey = arr[low];
    while(low < high){
      while(low < high && arr[high] >= pivotkey) --high;
      arr[low] = arr[high];
      while(low < high && arr[low] <= pivotkey) ++low;
      arr[high] = arr[low];
    }
    arr[low] = lookout;
    return low;
  }

  static void quickSort(int arr[], int low, int high){
    if(low < high){
      int pivotloc = Partition(arr, low, high);
      quickSort(arr, low, pivotloc - 1);
      quickSort(arr, pivotloc + 1, high);
    }
  }

  static void seclectSort(int arr[]){
    int min, flag;
    for(int i = 0; i < arr.length; ++i){
      min = arr[arr.length - 1];
      flag = arr.length - 1;
      for(int j = i; j < arr.length; ++j){
        if(arr[j] <= min){
          min = arr[j];
          flag = j;
        }
      }
      if(i != flag) swap(arr, i, flag);
    }
  }

  static void merge(int arr[], int tarr[], int i, int m, int n){
	int j, k;
    for(j = m + 1, k = i; i <= m && j <= n; ++k){
      if(arr[i] <= arr[j]) tarr[k] = arr[i++];
      else tarr[k] = arr[j++];
    }
    if(i <= m)
    	for(int t = 0; t <= n - k; ++t) tarr[k+t] = arr[i+t];
    if(j <= m)
    	for(int t = 0; t <= n - k; ++t) tarr[k+t] = arr[j+t];
  }

  static void mSort(int arr[], int arr1[], int s, int t){
    if(s == t) arr1[s] = arr[s];
    else{
      int m = (s + t) / 2;
      int arr2[] = new int[arr.length];
      mSort(arr, arr2, s, m);
      mSort(arr, arr2, m+1, t);
      merge(arr2, arr1, s, m, t);
    }
  }

  static void mergeSort(int arr[]){
    mSort(arr, arr, 0, arr.length - 1);
  }

  static void heapAdjust(int arr[], int s, int m){
    int rc = arr[s];
    for(int j = 2 * s; j <= m; j *= 2){
      if(j < m && arr[j] < arr[j+1]) ++j;
      if(rc >= arr[j]) break;
      arr[s] = arr[j];
      s = j;
    }
    arr[s] = rc;
  }

  static void heapSort(int arr[]){
    int i;
    for(i = arr.length / 2; i >= 0; --i)
      heapAdjust(arr, i, arr.length - 1);
    for(i = arr.length - 1; i > 0; --i){
      swap(arr, 0, i);
      heapAdjust(arr, 0, i - 1);
    }
  }

  static void swap(int arr[], int i, int j){
    int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
  }
}