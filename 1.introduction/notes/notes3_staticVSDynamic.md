# Pointers & Memory Allocation (Static vs Dynamic) — Revision Notes 

> Ye notes tumhare `Student` pointer wale code pe based hain — pointer, `new`, `->` operator, aur static vs dynamic memory allocation sab cover hai.

---

## 1. Pointer kya hota hai?

**Definition:** Pointer ek **special variable** hota hai jo kisi doosre variable/object ka **memory address store** karta hai — value khud store nahi karta, sirf ye batata hai ki wo value **kahan (address pe) rakhi hai**.

**Analogy:** Socho ek variable ek **ghar** hai jisme koi cheez (data) rakhi hai. Pointer us ghar ka **address likha hua kaagaz** hai. Tumhare paas agar address hai to tum us ghar tak pahunch sakte ho, andar ja sakte ho, cheez dekh sakte ho ya badal sakte ho — bina khud us ghar ko carry kiye.

```cpp
int x = 10;
int *p = &x;     // p mein x ka address store ho gaya

cout << x;       // 10  -> direct value
cout << p;       // 0x7ffee... -> x ka memory address
cout << *p;      // 10  -> address pe jaake value nikal li (dereference)
```

* `&x` → x ka **address** nikalta hai ("address-of" operator)
* `*p` → pointer ke andar jo address hai, **wahan jaake value** nikalta hai ("dereference" operator)

---

## 2. Tumhare Code Mein Pointer Kaise Use Hua

```cpp
Student *s = new Student;
```

* `Student *s` → `s` ek pointer hai jo **`Student` type ke object ka address** store karega.
* `new Student` → memory mein **ek naya `Student` object banata hai (heap pe)** aur uska address return karta hai, jo `s` mein store ho jaata hai.

```cpp
s->name = "yash";
```

* `->` (arrow operator) **pointer ke through object ke member ko access** karne ke liye use hota hai.
* `s->name` asal mein `(*s).name` ka **shortcut** hai.

```cpp
(*s).name = "yash";   // long/manual way — pehle dereference, fir member access
s->name = "yash";     // short way — zyada use hota hai, easy to read
```

**Analogy:** Agar `s` ek address hai (jaise "House No. 5, XYZ Street"), to `->` bolta hai — "us address pe jaake, jo cheez andar rakhi hai (jaise `name` waala drawer) usse nikal do ya usme kuch daal do."

---

## 3. Static Memory Allocation

**Definition:** Static allocation matlab memory **compile-time pe hi fix ho jaati hai** — variable declare karte hi uske liye jagah reserve ho jaati hai, aur ye memory **Stack** pe hoti hai.

```cpp
Student s1;          // Static allocation
s1.name = "Honey";
```

**Characteristics:**

* Memory **automatically allocate** hoti hai jab variable declare hota hai.
* Memory **automatically free (deallocate)** ho jaati hai jab wo scope (jaise function) khatam hota hai — tumhe manually kuch delete nahi karna padta.
* **Fast** hoti hai (stack access CPU ke liye bahut quick hota hai).
* **Size fix** honi chahiye — compile time pe hi pata hona chahiye kitni memory chahiye.
* Scope se bahar jaate hi khatam ho jaati hai — agar function return kar de to us function ke andar bana object automatically destroy ho jaata hai.

**Analogy:** Static allocation aisi hai jaise tum kisi **hotel room** book karte ho fixed check-in/check-out time ke saath — jaise hi checkout time (scope end) aata hai, room automatically khaali ho jaata hai, tumhe khud checkout call karne ki zaroorat nahi.

---

## 4. Dynamic Memory Allocation

**Definition:** Dynamic allocation matlab memory **run-time pe (jab program chal raha ho tab)** manually allocate ki jaati hai `new` keyword se, aur ye memory **Heap** pe hoti hai.

```cpp
Student *s = new Student;   // Dynamic allocation
s->name = "yash";

delete s;    // IMPORTANT: manually free karna padta hai!
```

**Characteristics:**

* Memory **manually allocate** karni padti hai (`new` keyword se).
* Memory **manually free** bhi karni padti hai (`delete` keyword se) — agar nahi ki to **memory leak** ho jaata hai (memory waste hoti rehti hai, wapas nahi milti).
* Thoda **slower** hoti hai static ke comparison mein (heap management overhead hota hai).
* Object function/scope khatam hone ke baad bhi **zinda reh sakta hai** — jab tak `delete` na karo ya program hi khatam na ho jaaye.
* Size **run-time pe decide** ho sakta hai (jaise user input ke hisaab se array size).

**Analogy:** Dynamic allocation aisi hai jaise tum khud kisi **PG/flat ko rent pe lete ho** — jab tak tum khud "chhod raha hoon" (`delete`) nahi bologe, wo tumhare naam pe hi rahega, chahe tum uska use kar rahe ho ya bhool hi gaye ho (memory leak!). Isliye rent khatam karna (memory free karna) tumhari responsibility hai.

---

## 5. Static vs Dynamic — Side by Side Comparison


| Feature              | Static Allocation                      | Dynamic Allocation                         |
| -------------------- | -------------------------------------- | ------------------------------------------ |
| Kab hoti hai         | Compile-time                           | Run-time                                   |
| Kahan store hoti hai | **Stack**                              | **Heap**                                   |
| Keyword              | Koi nahi (direct declare)              | `new`(allocate),`delete`(free)             |
| Memory free          | Automatic (scope khatam hote hi)       | **Manual**(`delete`karna padta hai)        |
| Speed                | Fast                                   | Thoda slow                                 |
| Size                 | Fix, compile-time pe pata hona chahiye | Flexible, run-time pe decide ho sakta hai  |
| Lifetime             | Sirf scope ke andar                    | Jab tak`delete`na ho, tab tak              |
| Risk                 | Kam (auto-managed)                     | Memory leak ka risk agar`delete`bhool gaye |
| Example              | `Student s1;`                          | `Student *s = new Student;`                |

---

## 6. Kab Kya Use Karna Chahiye?

### ✅ Static allocation use karo jab:

* Object/variable ka size **pehle se pata** hai.
* Object sirf us **function/scope ke andar hi chahiye** (temporary use).
* Tumhe **speed** chahiye aur manual memory management se bachna hai.

```cpp
void printStudent() {
    Student s1;               // static — function khatam hote hi auto-delete
    s1.name = "Yash";
    cout << s1.name;
}   // yahan s1 automatically destroy ho gaya
```

### ✅ Dynamic allocation use karo jab:

* Object ko **function ke bahar bhi zinda rakhna** ho (jaise return karna ho ya globally use karna ho).
* Run-time pe pata chale ki **kitni memory chahiye** (jaise user input se array size).
* Bahut **bada data** ho jo stack pe fit nahi hoga (stack ka size limited hota hai, heap ka bahut bada).

```cpp
Student* createStudent() {
    Student *s = new Student;   // dynamic — function khatam hone ke baad bhi zinda rahega
    s->name = "Yash";
    return s;                   // agar static hota to ye return karte hi destroy ho jaata (dangling)!
}
```

---

## 7. Full Working Example (Tumhare Code Ke Saath)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int age, roll_number;
    string grade;
};

int main() {

    // ---- STATIC allocation example ----
    Student s1;                 // stack pe bana, auto-managed
    s1.name = "Honey";
    s1.age = 20;
    cout << "Static Student: " << s1.name << endl;

    // ---- DYNAMIC allocation example ----
    Student *s = new Student;   // heap pe bana, manually manage karna hoga
    s->name = "yash";
    s->age = 10;
    s->grade = "A+";
    s->roll_number = 22;

    cout << "Dynamic Student: " << s->name << endl;

    delete s;                   // IMPORTANT: heap memory free karo, warna memory leak!

    return 0;
}
```

**Output:**

```
Static Student: Honey
Dynamic Student: yash
```

---

## 8. Common Mistake — Memory Leak

```cpp
void badFunction() {
    Student *s = new Student;   // memory allocate hui
    s->name = "Test";
    // delete s;  <-- ye line bhool gaye!
}   // function khatam ho gaya, lekin heap memory abhi bhi allocated hai
    // ab us memory ka address kahin store nahi hai -> memory hamesha ke liye "leak" ho gayi
```

**Analogy:** Ye aisa hai jaise tumne ek PG le liya, kabhi jaake use kiya bhi nahi, aur "chhodta hoon" bhi kabhi nahi bola — rent (memory) waste hoti rahegi hamesha ke liye, jab tak koi manually cancel na kare.

**Fix:** Jab bhi `new` use karo, uske corresponding `delete` ka dhyan zaroor rakho (ya smart pointers use karo jaise `unique_ptr`, `shared_ptr` — advanced topic, baad mein).

---

## 9. Quick Recap (Interview-Ready)

* **Pointer** = kisi variable/object ka **memory address** store karne wala variable. `&` se address milta hai, `*` se dereference (value nikalna) hota hai.
* **`->` operator** = pointer ke through object ke members access karne ka shortcut (`(*s).name` == `s->name`).
* **Static allocation** = compile-time, **Stack** pe, **auto-managed**, fast, fixed size.
* **Dynamic allocation** = run-time (`new`), **Heap** pe, **manually managed** (`delete` zaroori), flexible size, object function ke bahar bhi zinda reh sakta hai.
* Dynamic memory bhool ke free na karna → **memory leak**.

---

*Notes prepared for personal GitHub revision — Hinglish style with analogy + code examples + comparison table.*
