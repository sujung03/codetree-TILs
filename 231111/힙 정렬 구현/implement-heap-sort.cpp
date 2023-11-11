#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int arr[MAX_N + 1];

void Heapify(int n, int i) {
    int largest = i;                    // 최대 노드가 i번이라고 가정합니다.
    int l = i * 2;                      // 왼쪽 자식 노드 번호입니다.
    int r = i * 2 + 1;                  // 오른쪽 자식 노드 번호입니다.

    if(l <= n && arr[l] > arr[largest]) // 왼쪽 자식이 크다면, 최대 번호를 수정합니다.
        largest = l;
    
    if(r <= n && arr[r] > arr[largest]) // 오른쪽 자식이 크다면, 최대 번호를 수정합니다.
        largest = r;
    
    if(largest != i) {                  // 최대 노드가 자식 노드라면
        swap(arr[i], arr[largest]);     // 해당 자식과 현재 노드를 교환해준 뒤
        Heapify(n, largest);            // 내려간 위치에서 다시 heapify를 진행합니다.
    }
}

void HeapSort() {
    // 1. max-heap을 만들어 줍니다.
    for(int i = n / 2; i >= 1; i--)    // n / 2번째 원소부터 1번째 원소까지 돌며
        Heapify(n, i);                 // heapify 과정을 진행하여 max-heap을 만들어줍니다.

    // 2. 정렬을 진행합니다.
    for(int i = n; i > 1; i--) {       // n을 하나씩 줄여나가며
        swap(arr[1], arr[i]);          // 현재 최댓값과 가장 끝에 있는 노드를 교환해주고
        Heapify(i - 1, 1);             // 1번 노드를 기준으로 heapify를 진행하여
    }                                  // max-heap 상태를 계속 유지해줍니다. 
}

int main() {
    // 입력
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    HeapSort();

    for(int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    return 0;
}