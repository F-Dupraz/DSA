template <typename N>
void InsertionSort(N* arr, int n) {
  for(int i = 1; i < n; ++i) {
    N key = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = key;
  }

  return;
}

template <typename N>
void SelectionSort(N* arr, int n) {
  for(int i = 0; i < n; ++i) {
    int min = i;
    for(int j = i+1; j < n; ++j) {
      if(arr[j] < arr[min])
        min = j;
    }
    if(min != i) {
      N aux = arr[i];
      arr[i] = arr[min];
      arr[min] = aux;
    }
  }
}

template <typename N>
void BubbleSort(N* arr, int n) {
  for(int i = 0; i < n; ++i) {
    for(int j = n-1; j > i; --j) {
      if(arr[j] < arr[j-1]) {
        N aux = arr[j];
        arr[j]= arr[j-1];
        arr[j-1] = aux;
      }
    }
  }
}

template <typename N>
bool LinearSearch(N* arr, N value, int n) {
  for(int i = 0; i < n; ++i) {
    if(arr[i] == value)
      return 1;
  }
  return 0;
}

template <typename N>
bool BinarySearch(N* arr, N value, int n) {
  int min, max, mid, i = 0;
  min = 0;
  max = n-1;
  while(i < n && min <= max) {
    mid = min + (max - min) / 2;
    if(arr[mid] == value)
      return 1;
    else if(arr[mid] < value)
      min = mid + 1;
    else
      max = mid - 1;
    ++i;
  }
  return 0;
}

template <typename N>
bool BinarySearchRecImpl(N value, N* arr, int min, int max, int mid) {
  mid = min + (max - min) / 2;
  
  if(min > max) return false;

  if(arr[mid] == value)
    return true;
  else if(arr[mid] < value)
    min = mid + 1;
  else
    max = mid - 1;
  return BinarySearchRecImpl(value, arr, min, max, mid);
}

template <typename N>
bool BinarySearchRec(N value, N* arr, int n) {
  return BinarySearchRecImpl(value, arr, 0, n-1, (n-1)/2);
}
