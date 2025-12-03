#include <iostream>

using namespace std;

/*
    Linkli siyahı (linked list) ardıcıl düyünlərdən ibarət olan xətti verilənlər strukturudur.
    Burada hər bir düyün həm veriləni (data), həm də növbəti düyünün ünvanını saxlayır.
    Nümunələr:
    https://media.geeksforgeeks.org/wp-content/uploads/20220712172013/Singlelinkedlist.png
    https://media.geeksforgeeks.org/wp-content/uploads/20220901153812/LLdrawio.png


    Linkli siyahı ilə massivlərin müqayisəsi:

    Linkli siyahının üstünlükləri:
        1. Dinamik ölçü: Linkli siyahılar dinamik ölçüyə malikdir,
        yəni elementlər əlavə və ya silindikcə böyüyüb-kiçilə bilər.
        2. Bu çeviklik yaddaşdan daha səmərəli istifadə etməyə imkan verir və yenidən ölçüləndirməyə ehtiyac qalmır.
        3. Effektiv əlavə və silmə: Siyahının əvvəlinə və ya ortasına əlavə/silmə
        O(1) vaxtda edilə bilər, sadəcə göstəriciləri dəyişməklə.
        Massivlərdə olduğu kimi elementləri sürüşdürməyə ehtiyac yoxdur.
        4. Yaddaş israfı yoxdur: Linkli siyahılar yalnız lazım olan qədər yaddaş tutur,
        əlavə boş sahə saxlamır.

    Linkli siyahının çatışmazlıqları:
        1. Ardıcıllıqla keçid: Massivlərdən fərqli olaraq, linkli siyahıda elementlərə birbaşa indekslə çıxış yoxdur.
        Hansısa elementi tapmaq üçün siyahını əvvəlindən keçmək lazımdır.
        2. Əlavə yaddaş xərci: Hər bir düyün növbəti düyünün ünvanını saxlamalıdır,
        bu isə massivlərlə müqayisədə daha çox yaddaş tələb edir.
        3. Sabit zamanda çıxış yoxdur: Elementi tapmaq üçün siyahını tam keçmək lazım gəlir,
        massivlərdəki kimi indekslə birbaşa çıxış mümkün deyil.

    Massivin üstünlükləri:
        1. Birbaşa çıxış: Massivlərdə elementlərə indekslə sabit zamanda çıxış mümkündür.
        2. Cache üstünlüyü: Massiv elementləri yaddaşda ardıcıl yerləşir,
        bu isə qonşu elementlərə daha sürətli çıxış imkanı verir.
        3. Yığcam yaddaş: Eyni sayda element üçün massiv linkli siyahıya nisbətən daha az yaddaş tutur.

    Massivin çatışmazlıqları:
        1. Sabit ölçü: Massivin ölçüsü əvvəlcədən müəyyən olunur,
        dəyişəndə isə ya ölçüləndirmə, ya da yeni massiv yaradılmalıdır.
        2. Bahalı əlavə/silmə: Əgər ortada və ya əvvəlində element əlavə/silmək lazım olsa,
        qalan elementlərin sürüşdürülməsi vaxt aparır.
        3. Yaddaş israfı: Massiv əvvəlcədən çox böyük seçilərsə, istifadə olunmayan yerlər yaddaş itkisinə səbəb olur.

    Nəticə: Əgər tez-tez əlavə və silmələr lazımdırsa, linkli siyahı daha uyğundur.
    Əgər indekslə sürətli çıxış vacibdirsə, massiv daha uyğundur.
    Seçim konkret tətbiqə görə dəyişir.


    Linkli siyahının istifadə sahələri:
        1. Stack və Queue quruluşları: Əlavə/silmə əməliyyatlarının effektiv olması səbəbindən
        linkli siyahılar çox vaxt stack və queue üçün istifadə olunur.

        2. Dinamik yaddaş idarəsi: Linkli siyahı contiguous (ardıcıl) yaddaş tələb etmir,
        buna görə yaddaşdan səmərəli istifadə edir.

        3. Fayl sistemləri: Fayl və qovluqların strukturu linkli siyahı ilə göstərilə bilər.

        4. Musiqi və video playlistlər: Hər bir düyün mahnı və ya videonu göstərir,
        playlistdə asanlıqla əlavə, silmə və sıralama mümkündür.

        5. Simvol cədvəlləri: Açar-dəyər cütləri ilə işləmək üçün linkli siyahıdan istifadə edilə bilər.

        6. Polinomların göstərilməsi: Hər bir düyün polinomun bir terminini (əmsal və dərəcə ilə) saxlayır.

        7. Qraf alqoritmləri: Qonşuluq siyahıları linkli siyahı ilə göstərilə bilər,
        bu da qraf üzərində keçidi asanlaşdırır.
*/

/*
    Tapşırıq:

    1. Node adlı struct yaradın. Bu struct bir dəyər (data) və
    növbəti düyünün göstəricisini saxlamalıdır.

    2. LinkedList adlı class yaradın. Bu class özündə
    baş (head) göstəricisini saxlamalıdır.

    3. Constructor yazın ki, head = nullptr olsun (boş siyahı).

    4. insert funksiyası yazın – verilmiş dəyəri siyahının əvvəlinə əlavə etsin.

    5. display funksiyası yazın – siyahını keçib bütün elementləri çap etsin.

    6. search funksiyası yazın – verilmiş dəyəri axtarsın, tapılsa true, tapılmasa false qaytarsın.

    7. remove funksiyası yazın – verilmiş dəyərin ilk rast gəldiyi düyünü silsin.

    8. append funksiyası yazın – dəyəri siyahının sonuna əlavə etsin.

    9. Destructor yazın – siyahını tam silsin.

    10. Test üçün LinkedList obyekt yaradın, elementlər əlavə edin,
    display, search, remove və append funksiyalarını yoxlayın.

    Qeyd: private və public access specifier-lərdən düzgün istifadə edin.
    Bu tapşırıq C++-da OOP prinsipləri ilə linkli siyahının necə qurulduğunu anlamağa kömək edəcək.
*/
//   1. Node adlı struct yaradın. Bu struct bir dəyər (data) və
//     növbəti düyünün göstəricisini saxlamalıdır.
// struct Node {
//     int data;
//     Node* next;

//     Node(int val) : data(val), next(nullptr) {}
// };
//   2. LinkedList adlı class yaradın. Bu class özündə
//     baş (head) göstəricisini saxlamalıdır.
//     class linkedlist {
//         private:
//         struct Node {
//             int data;
//             Node* next;
//             Node(int val) : data(val), next(nullptr) {}
//         };
//         Node* head;
//         public:
//         linkedlist() {
//             head = nullptr;  // yeni yaradılan siyahı boş olur
//         }
// };

// 3. Constructor yazın ki, head = nullptr olsun (boş siyahı).

//        class linkedlist {
//         private:
//         struct Node {
//             int data;
//             Node* next;
//             Node(int val) : data(val), next(nullptr) {}
//         };
//         Node* head;
//         public:
//         linkedlist() {
//             head = nullptr;  // yeni yaradılan siyahı boş olur
//         }
// };
/* Həll */

//  4. insert funksiyası yazın – verilmiş dəyəri siyahının əvvəlinə əlavə etsin.

//                class linkedlist {
//         private:
//         struct Node {
//             int data;
//             Node* next;
//             Node(int val) : data(val), next(nullptr) {}
//         };
//         Node* head;
//         public:
//         void insert(int x){
//             Node* newnode = new Node(x);
//               newnode->next = head;        // yeni node köhnə başa bağlanır
//              head = newnode;
//         };
//         linkedlist() {
//             head = nullptr;  // yeni yaradılan siyahı boş olur
//         }
// };
//  5. display funksiyası yazın – siyahını keçib bütün elementləri çap etsin.
class linkedlist
{
    private:
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *head;

public:
//  9. Destructor yazın – siyahını tam silsin.
    ~linkedlist()
    {
        Node *current = head;
        Node *nextNode;

        while (current != nullptr)
        {
            nextNode = current->next; // növbəti düyünü yadda saxla
            cout << "Destructor: delete on " << current->data << endl;
            delete current; // cari düyünü sil
            current = nextNode; // növbəti düyünə keç
        }
        head = nullptr; // başı null et
    }
    void insert(int x)
    {
        Node *newnode = new Node(x);
        newnode->next = head; // yeni node köhnə başa bağlanır
        head = newnode;
    };
    linkedlist()
    {
        head = nullptr; // yeni yaradılan siyahı boş olur
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    //   6. search funksiyası yazın – verilmiş dəyəri axtarsın, tapılsa true, tapılmasa false qaytarsın.
    void search(int x)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                cout << " tapildi " << "daxil olunan: " << temp->data << endl;
                break;
            }
            else
            {
                cout << " tapilmadi heleki " << endl;
            }

            temp = temp->next;
        }
    }
    // 7. remove funksiyası yazın – verilmiş dəyərin ilk rast gəldiyi düyünü silsin.
    void remove(int x)
    {
        if (head == nullptr)
            return; // liste boşsa çık

        // baştaki node'u silme durumu
        if (head->data == x)
        {
            Node *temp = head;
            head = head->next; // başı bir sonraki node'a kaydır
            delete temp;       // eski head'i sil
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == x)
            {
                Node *temp = current->next;
                current->next = current->next->next; // node'u listeden çıkar
                delete temp;                         // hafızayı temizle
                return;
            }
            current = current->next;
        }

    }

    //  8. append funksiyası yazın – dəyəri siyahının sonuna əlavə etsin.
    void append(int x){
        Node* newnode = new Node(x);
         Node* temp = head;
     while (temp->next!=nullptr)
     {
        
        temp=temp->next;
     }
     temp->next=newnode;
  
      
        
    }
};
int main()
{
    linkedlist data; // linkedlist sınıfından bir nesne oluştur
    data.insert(3);  // listeye eleman ekle
    data.insert(1);
    data.insert(4);
    data.insert(6);
    data.append(1340);
    //    data.insert(10);
    data.display(); // nesne üzerinden display çağrısı
    // return 0;
    /*      İstifadə nümunəsi:     */
    // LinkedList list = LinkedList();

    // list.append(1).append(2).append(3).append(4);

    // list.display();

    // list.insert(5).display();

    // bool isFound = list.search(4);

    // cout << std::boolalpha << endl;
    // cout << isFound;
    // cout << endl << endl;

    // list.remove(3).display().remove(4).display().remove(5).display();

    // cout << endl;

    /*
        Çıxış nümunəsi:

        [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05c90] ---> [3 | 0x7f9092f05ca0] ---> [4 | 0x0]
        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05c90] ---> [3 | 0x7f9092f05ca0] ---> [4 | 0x0]

        true

        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x7f9092f05ca0] ---> [4 | 0x0]
        [5 | 0x7f9092f05c70] ---> [1 | 0x7f9092f05c80] ---> [2 | 0x0]
        [1 | 0x7f9092f05c80] ---> [2 | 0x0]

        Destructor:
            delete on 0
            delete on 1
            delete on 2
    */

    return 0;
}
//test queue