#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6_1();
void Ex6_2();
void Ex7();
int main() {
    //Ex1();
    //Ex2();
    //Ex3();
    //Ex4();
    //Ex5();
    //Ex6_1();
    //Ex6_2();
    Ex7();
    return 0;
}

void Ex1() {
    // 1)
    /*int a = 19;
    int* b = &a;
    (*b)++;
    cout << a;*/

    // 2)
    //int arr[] = {1, 1, 2, 3, 5, 8, 13};
    //int* q = arr;
    //int** p = &q; // *p = arr
    //(*p)[4] += *((*p) + 1); // arr[4] += arr[1]
    //cout << arr[4] << endl;
    

    // 3)
    /* int *p;
    *p = 9;
    cout << *p;*/ 

    // 4)
    int nums[2][3] = { { 16, 18 ,20}, { 25, 26 ,27} };
   // arr[i][j] = *(*(arr + i) +j)
    cout << *(*nums) << endl; // i = 0, j = 0 => nums[0][0] = 16
    cout << *(*nums+2) << endl; // i = 0, j = 2 => nums[0][2] = 20
    cout << *(*(nums+1)) << endl;// i = 1, j =  => nums[1][0] = 25
    cout << *(*(nums + 1)+2) << endl; // i = 1, j = 2 => nums[1][2] = 27
}
void delete2DArray(int m, float**& arr) {
    for (int i = 0; i < m; i++)
        delete[] arr[i];
    delete[] arr;
}
float** CreateMatrix(int M, int N) {
    // Cấp phát bộ nhớ
    // Tạo một ma trận có m hàng 
    float** a = new float*[M];

    //Mỗi hàng có n cột
    for (int i = 0; i < M; i++)
        a[i] = new float[N];

    //Nhập
    for (int i = 0; i < M; i++)
        for (int y = 0; y < N; y++)
            cin >> a[i][y];

    //Trả về địa chỉ của a
    return a;
}
void PrintMatrix(float** a, int M, int N) {
    //Dùng vòng lập để xuất ra màn hình từ a[0][0] đến a[M-1][N-1]
    for (int i = 0; i < M; i++) {
        for (int y = 0; y < N; y++)
            cout << a[i][y] << " ";
        cout << endl;
    }
}
float** Addition(float** a, int M1, int N1, float** b, int M2, int N2) {
    //Để tính tổng ma trận, số hàng và cột của hai ma trận phải bằng nhau
    //Đoạn code phía dưới sẽ trả về kết quả là NULL nếu số hàng hoặc cột không bằng nhau
    if (M1 != M2 || N1 != N2)
        return NULL;

    //Tạo bộ nhớ cho ma trận kết quả dạng mảng hai chiều kiểu float
    //Tạo một ma trận có M1 hàng
    float** c = new float*[M1];

    //Mỗi hang có N1 cột
    for (int i = 0; i < M1; i++)
        c[i] = new float[N1];

    //Thực hiện phép toán công ma trận
    for (int i = 0; i < M1; i++)
        for (int y = 0; y < N1; y++)
            c[i][y] = a[i][y] + b[i][y];
    //Trả về địa chỉ của c
    return c;
}
float** Multiply(float** a, int M1, int N1, float** b, int M2, int N2) {
    //Để nhân hai ma trận, số cột của ma trận 1 phải bằng số hàng của ma trận 2
    //Đoạn code phía dưới sẽ trả về kết quả là NULL nếu số cột của ma trận 1 khác số hàng của                                   ma trận 2
    if (N1 != M2)
        return NULL;

    //Tạo bộ nhớ cho ma trận kết quả dạng mảng hai chiều kiểu float
    //Tạo một ma trận có M1 hàng
    float** c = new float*[M1];

    //mỗi hàng có N2 cột
    for (int i = 0; i < M1; i++)
        c[i] = new float[N2];

    //Thực hiện phép toán nhân ma trận
    for (int i = 0; i < M1; i++)
        for (int y = 0; y < N2; y++) {
            c[i][y] = 0;
            for (int z = 0; z < N1; z++)
                c[i][y] += (a[i][z] * b[z][y]);
        }
    //Trả về địa chỉ của c
    return c;
}
void Ex2() {
    cout << "\nNhap ma tran A:\n";
    float** a = CreateMatrix(2, 2);
    cout << "\nNhap ma tran B:\n";
    float** b = CreateMatrix(2, 2);
    cout << "\nMa tran A+B:\n";
    float** c = Addition(a, 2, 2, b, 2, 2);
    PrintMatrix(c, 2, 2);
    cout << "\nMa tran A*B:\n";
    float** d = Multiply(a, 2, 2, b, 2, 2);
    PrintMatrix(d, 2, 2);

    delete2DArray(2, a);
    delete2DArray(2, b);
    delete2DArray(2, c);
    delete2DArray(2, d);
}
struct Fraction {
    //kiểu dữ liệu cấu trúc phân số gồm tử và mẫu
    int num, den;
};
Fraction* Input(int n) {
    Fraction* arr = new Fraction[n];
    Fraction temp;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap phan so thu " << i + 1 << endl;
        cout << "tu so: "; cin >> temp.num;
        cout << "mau so: "; cin >> temp.den;
        arr[i] = temp;
    }
    return arr;
}
void write_data(char* filename, Fraction* data, int total) {
    //Khai báo
    FILE* file;

    //mở file nhị phân ở chế dộ viết 
    file = fopen(filename, "wb");

    //Kiểm tra xem file có mở được không, nếu không thì dừng hàm
    if (!file)
        return;

    //ghi tổng cộng có bao nhiêu phân số vào file
    fwrite(&total, sizeof(int), 1, file);

    //ghi total phân số vào file nhị phân
    fwrite(data, sizeof(Fraction), total, file);

    //đóng file
    fclose(file);
}

Fraction* read_data(char* filename) {
    //Khai báo
    FILE* file;
    int total;

    //mở file dùng để đọc
    file = fopen(filename, "rb");

    //Nếu file không mở được thì gán data bằng con trỏ NULL
    if (file == NULL)
        return NULL;

    //Đọc total trong file để xem có bao nhiêu phân số
    fread(&total, sizeof(int), 1, file);

    //Khởi động bộ nhớ cho data kiểu Fraction gồm total phần tử
    Fraction* data = new Fraction[total];

    //Đọc dữ liệu từ file, sau đó lưu vào lưu vào data 
    fread(data, sizeof(Fraction), total, file);

    //đóng file
    fclose(file);

    //trở về địa chỉ của data
    return data;
}


// Hàm chuyển từ tập tin văn bản sang tập tin nhị phân (mã hóa để máy hiểu được)
// Đầu vào chúng ta sẽ nhận 1 tập tin văn bản (ĐỌC FILE) và đầu ra chúng ta sẽ có 1 tập tin nhị phân (GHI FILE)
void convertTextToBinary(char* text, char* binary)
{
    //Khai báo
    FILE* FileIn_Text = fopen(text, "r"); // r: read
    FILE* FileOut_Binary = fopen(binary, "wb"); // w: write

    //Kiểm tra xem file có mở được không
    if (!FileIn_Text)
        return; // kết thúc hàm không làm nữa

    int N;
    fscanf(FileIn_Text, "%d", &N);

    // sau khi đọc dữ liệu N từ tập tin văn bản vào biến N trong chương trình thì đồng thời ghi vào tập tin nhị phân luôn
    fwrite(&N, sizeof(int), 1, FileOut_Binary);

    for (int i = 0; i < N; ++i)
    {
        int tu, mau; // mỗi lần đọc dữ liệu từ tập tin văn bản vào 2 biến mau, tu thì đồng thời chúng ta ghi mau, tu ra tập tin nhị phân
        fscanf(FileIn_Text, "%d/%d", &tu, &mau);
        fwrite(&tu, sizeof(int), 1, FileOut_Binary);
        fwrite(&mau, sizeof(int), 1, FileOut_Binary);
    }

    fclose(FileIn_Text);
    fclose(FileOut_Binary);
}

// Hàm chuyển từ tập tin nhị phân (máy đọc được) sang tập tin văn bản (người đọc được)
// Đầu vào chúng ta sẽ nhận vào 1 tập tin nhị phân (ĐỌC FILE) và đầu ra chúng ta sẽ có được 1 tập tin văn bản với dữ liệu đọc ra được từ tập tin nhị phân trước đó (GHI FILE)
void convertBinaryToText(char* binary, char* text)
{
    //Khai báo
    FILE* FileOut_Text = fopen(text, "w"); // w: write
    FILE* FileIn_Binary = fopen(binary, "rb"); // r: read

    //Nếu mở file không được
    if (!FileIn_Binary)
        return; // kết thúc hàm không làm nữa

    //Đọc N từ file nhị phân và ghi vào file văn bản
    int N;
    fread(&N, sizeof(int), 1, FileIn_Binary);
    fprintf(FileOut_Text, "%d", N);

    // sau khi đọc dữ liệu N trong chương trình thì đồng thời ghi N biến đó vào tập tin văn bản luôn
    for (int i = 0; i < N; ++i)
    {
        int tu, mau;
        //xuống hàng
        fprintf(FileOut_Text, "\n");
        // mỗi lần đọc dữ liệu từ tập tin nhị phân vào biến tu, mau thì đồng thời chúng ta ghi 2 biến ra tập tin văn bản
        fread(&tu, sizeof(int), 1, FileIn_Binary);
        fread(&mau, sizeof(int), 1, FileIn_Binary);
        fprintf(FileOut_Text, "%d/%d", tu, mau);
    }

    fclose(FileOut_Text);
    fclose(FileIn_Binary);
}

void Ex3() {
    int n = 3;
    Fraction* arr = Input(n);
    char filename_bin[] = "OUTPUT.BIN";
    char filename_txt[] = "OUTPUT.TXT";
    write_data(filename_bin, arr, n);
    convertBinaryToText(filename_bin, filename_txt);

    delete[] arr;
}
//Hàm đệ quy
int Recursive_Find(int decimal_number)
{
    //Khử đệ quy khi decimal_number tiến tới 0
    if (decimal_number == 0)
        return 0;

    //Nếu decimal_number chia hết cho 2 thì hàm trả kết quả là 0, ngược lại là 1. Sau đó cộng cho
    //hàm đệ quy của decimal_number chia hai và lập lại liên tục cho đến khi decimal_number = 0
    else
       return decimal_number % 2 + 10 * Recursive_Find(decimal_number / 2);
}
void Ex4() {
    //Khai báo
    int decimal_number;

    //Nhận giá trị từ người dùng và lưu vào decimal_number
    cin >> decimal_number;

    // Xuất ra dãy số dạng nhị phân của decimal_number0
    cout << Recursive_Find(decimal_number);
}
struct Node {
    int data;
    struct Node* next;
};

void RemoveList(Node*& pHead)
{
    while (pHead != NULL)
    {
        Node* p = pHead;
        pHead = p->next;
        delete p;
    }
}
// Hàm dùng để tạo một Node mới
Node* newNode(int data)
{
    //Khởi tạo bộ nhớ cho biến temp kiểu Node*
    Node* temp = new Node;

    //gán giá trị data của tmp bằng với data, và temp trỏ đến Null
    temp->data = data;
    temp->next = NULL;

    //Trả về giá trị temp
    return temp;
}

//Hàm dùng để xóa các Node có data trùng nhau
void RemoveRightDuplicates(Node*& head)
{
    //Khởi tạo
    Node* ptr1, * prev, * tmp;
    ptr1 = head;

    //Chọn từng Node để giám định
    while (ptr1 != NULL && ptr1->next != NULL) {
        prev = ptr1;

        //So sánh data của Node được chọn với các data của các Node còn lại phía sau của nó
        while (prev->next != NULL) {
            //Nếu data của Node đang giám định bằng với data của Node đang chọn thì xóa nó đi
            if (ptr1->data == prev->next->data) {
                //Phần quan trọng của vấn đề
                //Cô lập dup, để khi xóa không làm mất các liên kết
                tmp = prev->next;
                prev->next = tmp->next;
                //Xóa dup
                delete (tmp);
            }
            //Nếu phần tử đang giám định khác với phần tử đang chọn thì di chuyển prt2 đến Node tiếp theo
            else
                prev = prev->next;
        }
        //Sau khi so sánh hết các Node phía sau prt1, thì prt1 di chuyển đến Node tiếp theo
        ptr1 = ptr1->next;
    }
}

//Hàm dùng để xuất ra màn hình data của Node trong một danh sách
void PrintList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
void AddNode(Node* &head, int value) {
    Node* p = newNode(value);
    p->next = head;
    head = p;
}
void Ex5() {
    Node* head = nullptr;
    AddNode(head, 43);
    AddNode(head, 24);
    AddNode(head, 5);
    AddNode(head, 5);
    AddNode(head, 24);
    AddNode(head, 65);
    AddNode(head, 43);
    AddNode(head, 6);

    RemoveRightDuplicates(head);
    PrintList(head);
    RemoveList(head);
}
//struct Stack
struct Stack {

    int top;
    unsigned int capacity;
    char* arr;
};

//Hàm để tạo stack dựa theo capacity
Stack* createStack(unsigned int capacity)
{
    //Khởi tạo bộ nhớ cho biến stack kiểu Stack*
    Stack* stack = new Stack();
    //Gán giá trị
    stack->capacity = capacity;
    stack->top = -1;
    //Khởi tạo bộ nhớ cho chuối có capacity kí tự
    stack->arr = new char[(stack->capacity * sizeof(char))];

    return stack;
}

// Kiểm tra xem stack có full chưa
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

//Kiểm tra xem stack có trống hay không
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Hàm dùng để thêm item vào stack.
// Khi thêm, hàm sẽ tăng top thêm 1 đơn vị
void push(Stack* stack, char item)
{
    //Nếu đã đủ rồi thì dừng hàm
    if (isFull(stack))
        return;
    //Nếu chưa thì thêm item vào đầu stack
    stack->arr[++stack->top] = item;
}

// Hàm dùng để bỏ một item ra khỏi stack
// Khi bỏ, hàm sẽ giảm top đi 1 đơn vị
char pop(Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->arr[stack->top--];
}

// hàm dùng để đảo lộn lại chuỗi
void reverse(char str[])
{
    //lưu độ dài của chuỗi vào n
    int n = strlen(str);
    //Sau đó tạo một stack gồm n kí tự
    Stack* stack = createStack(n);

    // Đẩy tất cả các kí tự vào stack
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);

    // Lấy ra từng kí tự trong stack
    // Thêm vào str
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}
void Ex6_1() {
    char str[50];
    cin.getline(str, 50);

    reverse(str);
    cout << "Reversed string is " << str;
}
struct Queue
{
    Node* head;
    Node* tail;
};
void CreateQueue(Queue &q) {
    q.head = q.tail = nullptr;
}
int IsEmpty(Queue q)
{
    if (q.head == NULL)
        return 1;
    return 0;
}
void EnQueue(Queue& q, Node* node) {
    if (IsEmpty(q)) {
        q.head = node;
        q.tail = node;
    }
    else {
        q.tail->next = node;
        q.tail = node;
    }
}
int DeQueue(Queue& q) {
    if (IsEmpty(q))
        return 0;
    Node* node = q.head;
    int data = node->data;
    q.head = node->next;
    delete node;
    if (q.head == NULL)
        q.tail = NULL;
    return data;
}
int Front(Queue q) {
    if (IsEmpty(q))
        return 0;
    return q.head->data;
}
Node* CreateNode(int init)
{
    Node* node = new Node;
    node->data = init;
    node->next = NULL;
    return node;
}
void Ex6_2() {
    int n, k;
    cin >> n;
    //Khởi tạo một container queue tên là queue
    Queue queue;
    CreateQueue(queue);
    Node* node;
    for (int i = 0; i < n; i++)
    {
        node = CreateNode(i + 1);
        EnQueue(queue, node);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        //Trả về một tham chiếu đến phần tử đầu tiên của q và lưu vào x
        int x = Front(queue);
        //sao đó loại bỏ phần tử đầu queue, và thêm x vào cuối queue
        DeQueue(queue);
        Node* node = CreateNode(x);
        EnQueue(queue, node);
    }
    //Xuất các phần tử trong queue từ đầu đến cuối
    while (!IsEmpty(queue)) {
        cout << Front(queue) << " ";
        DeQueue(queue);
    }
    RemoveList(queue.head);
}
struct PlantPot {
    int index;
    int height;
};

void Merge(PlantPot a[], int l, int mid, int r) {
    int sizeSubArray1 = mid - l + 1;
    int sizeSubArray2 = r - mid;
    PlantPot* subArray1 = (PlantPot*)malloc(sizeof(PlantPot) * sizeSubArray1);
    PlantPot* subArray2 = (PlantPot*)malloc(sizeof(PlantPot) * sizeSubArray2);
    for (int i = l; i <= mid; ++i)
        subArray1[i - l] = a[i];
    for (int i = mid + 1; i <= r; ++i)
        subArray2[i - mid - 1] = a[i];

    int indexSubArray1 = 0; 
    int indexSubArray2 = 0;
    int indexMergeArray = l;
    while (indexSubArray1 < sizeSubArray1 || indexSubArray2 < sizeSubArray2)
    {
        if (indexSubArray1 >= sizeSubArray1)
            a[indexMergeArray++] = subArray2[indexSubArray2++];
        else if (indexSubArray2 >= sizeSubArray2)
            a[indexMergeArray++] = subArray1[indexSubArray1++];
        else
        {
            if (subArray1[indexSubArray1].height <= subArray2[indexSubArray2].height)
                a[indexMergeArray++] = subArray1[indexSubArray1++];
            else
                a[indexMergeArray++] = subArray2[indexSubArray2++];
        }
    }
    free(subArray1);
    free(subArray2);
}


void Merge_sort(PlantPot a[], int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    Merge_sort(a, l, mid);
    Merge_sort(a, mid + 1, r);
    Merge(a, l, mid, r);
}

void Ex7() {
    int N;
    PlantPot* arr;
    cout << "Nhap N:";
    cin >> N;

    arr = new PlantPot[N];

    for (int i = 0; i < N; i++) {
        cout << "Nhap chieu cao cay thu " << (i + 1) << ": ";
        cin >> arr[i].height;
        arr[i].index = i + 1;
    }

    Merge_sort(arr, 0, N - 1);

    cout << "Thu tu cac cay sau khi sap xep:" << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i].index << "\t";
}

