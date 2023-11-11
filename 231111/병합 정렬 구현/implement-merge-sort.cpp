#include <iostream>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];
int merged_arr[MAX_N];

void Merge(int low, int mid, int high) {
    int i = low, j = mid + 1;            // 각 리스트 내의 원소 위치를 잡습니다.

    int k = low;                         // 병합 시 원소를 담을 위치를 유지합니다.
    while(i <= mid && j <= high) {       // 두 리스트 내의 원소가 아직 남아있다면
        if (arr[i] <= arr[j])            // 첫 번째 리스트 내의 원소가 더 작다면
            merged_arr[k++] = arr[i++];  // 해당 원소를 옮겨줍니다. 
        else
            merged_arr[k++] = arr[j++];  // 그렇지 않다면 두 번째 리스트 내의 원소를 옮겨줍니다.
    }

    while(i <= mid)                      // 아직 첫 번째 리스트 내 원소가 남아있다면
        merged_arr[k++] = arr[i++];      // 남은 원소들을 전부 옮겨줍니다.
    
    while(j <= high)                     // 아직 두 번째 리스트 내 원소가 남아있다면
        merged_arr[k++] = arr[j++];      // 남은 원소들을 전부 옮겨줍니다.
    
    for(int k = low; k <= high; k++)     // 병합된 리스트를 다시
        arr[k] = merged_arr[k];          // 원본 리스트에 옮겨줍니다.
}

void MergeSort(int low, int high) {
    if(low < high) {                   // 원소의 개수가 2개 이상인 경우에만 진행
        int mid = (low + high) / 2;    // 가운데 원소의 위치
        MergeSort(low, mid);           // 왼쪽 부분에 대해 병합정렬 진행
        MergeSort(mid + 1, high);      // 우측 부분에 대해 병합정렬 진행
        Merge(low, mid, high);         // 정렬된 두 리스트를 하나로 병합
    }
}

int main() {
    // 입력
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    MergeSort(0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}