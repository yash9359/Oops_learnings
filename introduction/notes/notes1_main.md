# C++ Classes & Objects — Revision Notes 

## 1. Class kya hoti hai?

**Definition:** Class ek **blueprint / design** hoti hai jisse objects banaye jaate hain. Class khud koi memory nahi leti (jab tak object nahi banta), bas ye define karti hai ki object ke andar **kya data (attributes)** hoga aur **kya kaam (methods)** wo kar sakega.

**Analogy:** Class ek "naksha" (blueprint) hai ghar banane ka. Ek architect ek hi naksha se 100 ghar bana sakta hai — har ghar (object) alag hoga (alag address, alag rang, alag furniture) lekin structure same hoga.

```cpp
class Student
{
private:
    string name;
    int age, roll_number;
    string grade;
public:
    void setName(string studentName) { ... }
    string getName() { ... }
};
```

Yahan `Student` class hai jisme:

* **Attributes (data members):**`name`, `age`, `roll_number`, `grade`
* **Methods (member functions):**`setName()`, `getName()`, etc.

---

## 2. Object kya hota hai?

**Definition:** Object class ka ek **real instance** hota hai jise memory milti hai aur jiske paas apna alag data hota hai.

**Analogy:** Agar `Student` class naksha hai, to `s1` aur `s2` do alag ghar hain jo usi naksha se bane hain — dono ka apna address, apna data hai.

```cpp
Student s1;
s1.setName("Yash");
s1.setAge(21);

Student s2;
s2.setName("Honey");
s2.setAge(22);
```

Yahan `s1` aur `s2` dono `Student` class ke objects hain, lekin dono ka data independent hai. `s1.name` change karne se `s2.name` pe koi effect nahi padta.

---

## 3. Encapsulation (Data Hiding / Privacy)

**Definition:** Encapsulation ek OOP principle hai jisme hum **data (attributes)** ko `private` rakhte hain aur unhe access karne ke liye **public methods** (getters/setters) provide karte hain. Isse data **directly bahar se change nahi ho sakta** — sirf controlled tareeke se hi access milta hai.

**Analogy:** Socho tumhara ATM card hai. Tum apna balance directly bank ke server mein jaake edit nahi kar sakte (private data). Tumhe ATM machine (public method/interface) use karni padti hai jo validation karke hi paisa deti/leti hai.

```cpp
class Student
{
private:            // yahan data HIDDEN hai
    string name;
    int age;

public:             // yahan controlled ACCESS hai
    void setAge(int studentAge)
    {
        if (studentAge < 18 || studentAge > 100)   // validation!
        {
            cout << "Invalid age: " << endl;
            return;
        }
        age = studentAge;
    }
};
```

**Kyu zaroori hai?** Agar `age` public hota, to koi bhi likh sakta tha `s1.age = -500;` — jo galat hai. Private banake aur `setAge()` ke through validation lagake hum galat data set hone se bachate hain.

---

## 4. Getter aur Setter Methods

**Definition:**

* **Setter** — private data ko **set (assign)** karne ke liye public function. Usually validation bhi karta hai.
* **Getter** — private data ko **read (return)** karne ke liye public function.

**Analogy:** Ek locker (private data) hota hai jiski chaabi sirf bank manager (class ke methods) ke paas hoti hai. Tumhe paisa daalna hai to manager se bologe "isse deposit kar do" (setter), aur nikalna hai to bologe "ye nikaal do" (getter) — tum khud locker nahi khol sakte.

```cpp
// SETTER — validation ke saath data set karta hai
void setName(string studentName)
{
    if (studentName.empty())
    {
        cout << "invalid name: ";
        return;
    }
    name = studentName;
}

// GETTER — sirf data return karta hai
string getName()
{
    return name;
}
```

### Special case: Password-protected Getter

Tumhare code mein ek interesting example hai — `getGrade()` sirf tab grade return karta hai jab sahi `pin` diya jaaye:

```cpp
string getGrade(int pin)
{
    if (pin == 123)
    {
        return grade;
    }
    return "Enter valid password to get grades";
}
```

Ye dikhata hai ki getters bhi **conditional / restricted access** de sakte hain — sirf blind data return karna zaroori nahi.

Call karte waqt:

```cpp
cout << s1.getGrade(123) << endl;   // sahi pin -> grade milega
cout << s1.getGrade(111) << endl;   // galat pin -> error message
```

---

## 5. `private` vs `public` — Quick Table


| Keyword   | Kahan se access ho sakta hai              | Kab use karein                                  |
| --------- | ----------------------------------------- | ----------------------------------------------- |
| `private` | Sirf class ke andar (member functions se) | Data members (attributes) ke liye               |
| `public`  | Class ke bahar se bhi (object.method())   | Getters, setters, aur interface methods ke liye |

**Rule of thumb:** Data ko `private` rakho, functions ko `public` rakho. Isse encapsulation maintain hoti hai.

---

## 6. Empty Class ka Size — `sizeof(emptyClass)`

Tumhare code mein:

```cpp
class a
{
    // koi data member ya function nahi
};

a obj;
cout << sizeof(obj);   // Output: 1
```

**Explanation:** C++ mein har object ka **unique memory address** hona chahiye. Agar empty class ka size `0` hota, to do alag objects same address share kar lete (jo galat hota, kyuki dono independent objects hain).

Isliye compiler empty class ko bhi **1 byte** ka size deta hai — sirf isliye taaki har object ko apna unique address mil sake.

**Analogy:** Socho ek khaali dabba (empty box) hai jisme kuch nahi hai. Fir bhi us dabbe ko ek jagah (address) chahiye rack pe rakhne ke liye — chahe andar kuch ho ya na ho.

---

## 7. Padding Concept (Next Topic — Preview)

Tumhare code mein ye class already di hui hai padding samjhane ke liye:

```cpp
class b
{
    char d;   // 1 byte
    int c;    // 4 bytes
    char e;   // 1 byte
};
```

**Chhota sa hint (agla topic):** Agar sirf sizes jod di jaayen (1 + 4 + 1 = 6 bytes), to actual `sizeof(b)` usse **zyada** aayega (generally 12 bytes on most systems). Isका reason hai **memory alignment / padding** — compiler performance ke liye data members ke beech extra khaali bytes daal deta hai taaki CPU fast access kar sake.

> Padding ka detailed explanation agle notes mein cover karenge jab tum agla code doge.

---

## 8. Poora Flow — Ek Nazar Mein

```
Class (blueprint)
   │
   ├── private data members  → directly access nahi
   │
   ├── public setter methods → validation ke saath data set
   │
   └── public getter methods → controlled tareeke se data read
        │
        ▼
   Object (real instance, apna memory address, apna data)
```

---

## 9. Interview-style Quick Recap

* **Class** = blueprint, **Object** = real instance with memory.
* **Encapsulation** = data hide karo (`private`), access control karo (`public` methods).
* **Getter/Setter** = controlled read/write, validation setter mein daal sakte ho.
* **Empty class size = 1 byte** — unique address guarantee ke liye.
* **Padding** = compiler memory alignment ke liye extra bytes add karta hai (agla topic).

---

*Notes prepared for personal GitHub revision — Hinglish style, code + analogy + definition combo.*
