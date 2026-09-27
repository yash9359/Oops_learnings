# Exception Handling in C++ — Complete Deep Dive (Basic to Advanced)

> Ye notes tumhare `Customer` (deposit/withdraw) aur `bad_alloc` wale code pe based hain. **try, catch, throw** basics se leke, **custom exception classes**, **standard exception hierarchy**, aur **catch order ka important rule** — sab depth mein cover kiya hai.

---

# PART 0: EXCEPTION HANDLING KYA HAI AUR KYU ZAROORI HAI

## 0.1 Definition

**Tumne khud likha:***"An exception is an unexpected problem that arises during the execution of a program & our program terminates suddenly with some issues/errors → exceptions hamesha run time pe hi aate hain."*

**Simple Words Mein:** Exception ek **aisi galti/situation hai jo program chalte waqt (run-time pe) achanak aa jaati hai** — jaise negative amount deposit karna, zero se divide karna, bahut zyada memory maangna. Agar isse handle na kiya jaaye, to **poora program crash** ho jaata hai.

## 0.2 Exception Handling Kyu Zaroori Hai? (Without vs With)

**Bina Exception Handling Ke:**

```cpp
void deposit(int amount) {
    if (amount <= 0) {
        cout << "Invalid amount!";
        return;    // bas return kar diya, lekin CALLER ko exact pata nahi chalega KYA galat hua
    }
    balance += amount;
}
```

Problem: Agar function **deep nested calls** mein hai (jaise `A() -> B() -> C() -> galti yahan hui`), to error ko **manually har level pe check karke upar pass karna** padta — bahut messy code ban jaata hai.

**Exception Handling Ke Saath:** Error ko **"throw"** kar do, jahan bhi ho — aur wo **automatically upar tak "jump" kar jaata hai** jab tak koi usse "catch" (pakड़) na le, chahe wo function calls ki kitni bhi layers door ho.

**Analogy:** Socho exception handling ek **fire alarm system** jaisा hai — agar building ke **kisi bhi floor pe aag lage (`throw`)**, to alarm poori building mein bajta hai aur **jo bhi floor pe fire-fighting equipment (`catch`) hai, wahan pahunch ke handle ho jaata hai** — tumhe manually har floor pe jaake check nahi karna padta ki "aag hai ya nahi."

---

# PART 1: `try`, `catch`, `throw` — BASIC SYNTAX

## 1.1 Teeno Keywords Ka Kaam


| Keyword | Kaam                                                                            |
| ------- | ------------------------------------------------------------------------------- |
| `try`   | Wo code block jaha**exception aane ka chance hai**— isse "monitor" karte hain  |
| `throw` | Jab actually galti ho jaaye, to ek**"exception object" bhej dete hain**(signal) |
| `catch` | `try`block ke baad, jo exception "pakड़ke" usse**handle**karta hai            |

## 1.2 Sabse Basic Example

```cpp
int main() {
    try {
        int amount = -5;
        if (amount < 0) {
            throw runtime_error("Amount cannot be negative!");   // exception THROW ki
        }
        cout << "Deposited: " << amount;   // ye line kabhi chalegi hi nahi (neeche dekho kyu)
    }
    catch (const runtime_error &e) {        // exception CATCH ki
        cout << "Error: " << e.what() << endl;
    }
}
```

**Flow:**

1. `try` block **shuru** hota hai — normal code chalta hai.
2. Jaise hi `throw` line hit hoti hai, **turant**`try` block ka **baaki saara code skip** ho jaata hai (chahe wo throw line se 100 lines door ho).
3. Control **seedha matching `catch` block** mein chala jaata hai.
4. `catch` block apna code chalata hai, fir program **normally aage badhta hai** (crash nahi hota).

**Analogy:**`throw` ek **emergency SOS signal** bhejne jaisा hai. Jaise hi SOS bheja, tumhara current kaam (baaki try block) **turant rok diya jaata hai**, aur seedha **rescue team (catch block)** tak pahuncha diya jaata hai.

---

# PART 2: TUMHARE CODE KA FLOW — LINE BY LINE (VERY IMPORTANT SECTION)

Chalo tumhare `Customer` example ko **step-by-step trace** karte hain — ye sabse zyada samajh aayega:

```cpp
int main() {
    Customer C1("Yash", 5000, 1234);
    try {
        C1.deposit(100);        // Step 1
        C1.withdraw(-1);         // Step 2
        C1.deposit(500);         // Step 3
    }
    catch (const InvalidAmountError &e) { ... }
    catch (const char *error) { ... }
    catch (const runtime_error &e) { ... }
    catch (const my_runtime_error &e) { ... }
    catch (...) { ... }
}
```

**Step 1: `C1.deposit(100)`**

```cpp
void deposit(int amount) {
    if (amount <= 0) throw runtime_error("...");
    balance += amount;   // 100 > 0, isliye ye line chalti hai
    cout << "100rs is credited successfully\n";
}
```

Amount `100` valid hai, koi exception nahi aati — normal chalta hai. Output: `"100rs is credited successfully"`.

**Step 2: `C1.withdraw(-1)`**

```cpp
void withdraw(int amount) {
    if (amount > 0 && amount <= balance) { ... }
    else if (amount < 0) {
        throw InvalidAmountError("amount should greater than 0");   // <-- YE CHALTA HAI (amount = -1)
    }
    else { throw my_runtime_error("insufficient amount"); }
}
```

`amount = -1`, jo `< 0` hai — isliye **`InvalidAmountError` throw hoti hai.**

**Turant Kya Hota Hai:** Exception throw hote hi, `try` block **turant chhod diya jaata hai** — control **`Step 3` (`C1.deposit(500)`) tak pahunchta hi nahi!**

**Tumhara comment bilkul sahi tha:***"ye chalega hi nahi, upar wale mein error hai kyunki"* — **BILKUL CORRECT!** Ek baar exception throw ho gayi, to **try block ke baaki saare statements skip** ho jaate hain, chahe wo bilkul next line hi kyu na ho — control seedha matching `catch` mein chala jaata hai.

**Step 3: Matching `catch` Dhundhna**

Compiler **top se neeche, order mein** catch blocks check karta hai:

```cpp
catch (const InvalidAmountError &e) { ... }   // ✅ MATCH! Exception type bilkul same hai
```

Ye **pehla hi catch block match** kar jaata hai (kyunki thrown exception ka type `InvalidAmountError` hai, aur ye catch bhi wahi type pakड़ रहा hai). Baaki catch blocks (`const char*`, `runtime_error`, etc.) **check hi nahi hote** — jaise hi ek match milta hai, wahi use ho jaata hai.

**Output:**`"Exception Occured: amount should greater than 0"`

---

# PART 3: CATCH BLOCKS KA ORDER — VERY IMPORTANT RULE (Interview Favorite)

## 3.1 Rule: Zyada "Specific" Wale Pehle, "General" Wale Baad Mein

Tumhare code mein order aisा hai:

```cpp
catch (const InvalidAmountError &e) { ... }   // Specific — sirf ye exact type pakड़ता
catch (const char *error) { ... }              // C-string throw hui ho to
catch (const runtime_error &e) { ... }         // General std exception
catch (const my_runtime_error &e) { ... }      // Custom hierarchy wala
catch (...) { ... }                             // SABSE LAST — jo bhi bacha, sab pakड़ le
```

**Kyu Ye Order Important Hai:**`InvalidAmountError`**khud `runtime_error` se inherit karta hai** (`class InvalidAmountError : public runtime_error`). Agar `catch (const runtime_error &e)` ko **`InvalidAmountError` wale catch se PEHLE** likh dete:

```cpp
// GALAT ORDER:
catch (const runtime_error &e) { cout << "runtime_error: " << e.what(); }
catch (const InvalidAmountError &e) { cout << "Invalid Amount: " << e.what(); }   // <- YE KABHI CHALEGA HI NAHI!
```

**Kya Hota:** Jab `InvalidAmountError` throw hoti, C++ **upar se neeche check karta** — pehla catch hi (`runtime_error`) match kar jaata (kyunki `InvalidAmountError`**IS-A `runtime_error`** bhi hai, inheritance ki wajah se) — aur **doosra catch (specific `InvalidAmountError` wala) kabhi reach hi nahi hota**, dead code ban jaata.

**Analogy:** Ye aisा hai jaise ek **security checkpoint** pe do gates hon — "Sabke liye General Gate" aur "VIP Gate" — agar tum **General Gate ko pehle** rakh do, to VIP log bhi **General Gate se hi nikal jaayenge** (kyunki wo bhi "General public" ki category mein aate hain), aur VIP Gate **kabhi use hi nahi hoga.** Isliye **VIP (specific) Gate hamesha pehle, General (broad) Gate baad mein** rakhna chahiye.

## 3.2 `catch(...)` — Catch-All, Hamesha SABSE LAST

```cpp
catch (...) {
    cout << "Exception occured" << endl;
}
```

**Definition:**`catch(...)` (teen dots — "ellipsis") **kisi bhi type ka exception pakड़ leta hai** — chahe wo `int`, `string`, koi custom class, kuch bhi ho. Ye ek **"safety net"** hai jo ensure karta hai ki **koi bhi exception bina handle hue na reh jaaye** (warna program crash ho jaata — `std::terminate` call ho jaata).

**Isse Hamesha LAST Kyu Rakhte Hain:** Kyunki ye **sabkuch pakड़ leta hai** — agar isse upar rakho, to ye **baaki saare specific catches ko "steal" kar lega** (jaise upar wale General Gate example), aur specific catch blocks kabhi chalenge hi nahi.

**Analogy:**`catch(...)` ek **"Lost & Found" counter** jaisा hai jo **kisi bhi cheez ko accept** kar leta hai jo kahin aur classify nahi ho paayi — isliye ye hamesha **sabse last "backup" option** hona chahiye, sabse pehle nahi.

---

# PART 4: EXCEPTION KO REFERENCE (`&`) SE CATCH KARNA — KYU ZAROORI HAI

```cpp
catch (const runtime_error &e) { ... }   // '&' (reference) use kiya, copy nahi
```

**Kyu Reference Use Karte Hain (Do Reasons):**

1. **Efficiency (Copy Constructor Notes Se Yaad Karo):** Exception object ki **copy banana expensive** ho sakta hai, reference se copy nahi banti — fast hai.
2. **Polymorphism Ke Liye ZAROORI (VERY IMPORTANT):** Agar tum **by-value** (`catch (runtime_error e)`) catch karte, to C++ **"Object Slicing"** kar deta — matlab agar actual thrown object `InvalidAmountError` (jo `runtime_error` se derived hai) tha, to by-value catch karne pe **uska sirf `runtime_error` wala hissa hi copy hota**, `InvalidAmountError` ki apni extra cheezein **"kaat (slice)" ho jaati** — jaisa humne **Virtual Functions** notes mein dekha tha, polymorphism sirf **reference/pointer** se hi sahi kaam karta hai, by-value se nahi.

**Analogy:** Ye bilkul waisा hai jaise humne pehle discuss kiya tha — **`const &` parameter pass karna** (Operator Overloading notes) — original object ka reference lena **fast bhi hai, aur uska poora (asli) roop bhi preserve karta hai**, jabki copy banane se kuch details "kट़" (slice) sakti hain.

---

# PART 5: CUSTOM EXCEPTION CLASSES — TUMHARE CODE KE DONO TAREEKE

Tumhare code mein **do alag tareeke** dikhaye gaye hain custom exceptions banane ke:

## 5.1 Tareeka 1 — Apni Khud Ki Independent Exception Hierarchy Banana

```cpp
class exeception {          // (tumhara khud ka banaya hua base, std::exception NAHI hai)
protected:
    string msg;
public:
    exeception(string msg) { this->msg = msg; }
    string what() const { return msg; }   // apna khud ka 'what()' function
};

class my_runtime_error : public exeception {
public:
    my_runtime_error(const string &msg) : exeception(msg) {}   // Initializer List se base ko msg diya
};
```

**Isme Kya Ho Raha Hai:** Tumne **poori apni khud ki chhoti si exception system** bana li hai, jo **C++ ki standard `std::exception` se bilkul unrelated** hai — bas isi structure/pattern ko copy kiya hai (`msg` store karna, `what()` se return karna) taaki familiar/consistent lage.

**Kab Use Karte Hain Ye Approach:** Jab tumhe **bilkul apni khud ki, chhoti, custom exception system** chahiye ho, bina standard library ki cheezon pe depend kiye — rare use case hai, usually learning/practice ke liye achha hai.

## 5.2 Tareeka 2 — Standard Library Ki Exception Se Inherit Karna (BEHTAR/COMMON PRACTICE)

```cpp
class InvalidAmountError : public runtime_error {   // std::runtime_error se inherit
public:
    InvalidAmountError(const string &msg) : runtime_error(msg) {}
};
```

**Isme Kya Ho Raha Hai:**`InvalidAmountError`**C++ ki standard `std::runtime_error` class se inherit** kar raha hai — jo khud **`std::exception` se inherit** karti hai. `runtime_error(msg)` constructor already `what()` function ko **automatically implement** kar deta hai (tumhe khud se `what()` likhne ki zaroorat nahi padi, jaisa Tareeka 1 mein padi thi).

**Ye Behtar Kyu Hai:**

1. **Standard `what()` already milta hai** — khud implement nahi karna padta.
2. **Interoperability** — Agar tumhara code doosri libraries/functions ke saath kaam kare jo `catch (const exception &e)` use karti hain (generic standard exception catch), to tumhari custom exception bhi **automatically usme catch ho jaayegi** (kyunki wo `std::exception` ka hi part hai) — Tareeka 1 wali custom exception **generic `std::exception` catch mein nahi aayegi**, kyunki wo bilkul alag/unrelated hierarchy hai.

**Analogy:** Tareeka 2 aisा hai jaise tum **existing "recognized ID card system" (std::exception)** mein register ho rahe ho — koi bhi jagah jo "recognized ID" maangti hai, tumhara card kaam karega. Tareeka 1 aisा hai jaise tumne apna **khud ka, private, "sirf tumhare gharwalo ke liye valid" ID card** bana liya — dikhta similar hai, lekin **kahin aur officially recognize nahi hoga.**

---

# PART 6: STANDARD EXCEPTION HIERARCHY (C++ Ki Built-in Exceptions)

C++ mein saari standard exceptions ek **hierarchy (tree)** mein organized hain, sabki jaड़ (root) hai **`std::exception`**:

```
                    std::exception
                   /       |        \
          logic_error  runtime_error   bad_alloc, bad_cast, bad_typeid...
             /    \         /    |    \
   invalid_       out_    overflow_ underflow_ range_error
   argument      of_range   error     error
```


| Exception Class         | Kab Use Hoti Hai                                                                           |
| ----------------------- | ------------------------------------------------------------------------------------------ |
| `std::exception`        | Sabse**base/root**class — sabki common ancestor                                           |
| `std::runtime_error`    | Errors jo**run-time pe predict nahi kiye jaa sakte**(jaise invalid user input)             |
| `std::logic_error`      | Errors jo**programming logic ki galti**se hote hain (jo pehle hi avoid kiye jaa sakte the) |
| `std::bad_alloc`        | Jab`new`se**memory allocate nahi ho paati**(heap full/exhausted)                           |
| `std::out_of_range`     | Jaise`vector.at(100)`jab vector ka size 100 se kam ho                                      |
| `std::invalid_argument` | Function ko galat type/value ka argument diya gaya ho                                      |

**Har ek exception class mein `what()` (virtual function) hota hai** jo error ka message return karta hai — isiliye tum **generic `catch (const exception &e)`** likh ke, `e.what()` call karke, **kisi bhi standard exception ka message** nikal sakte ho, chahe wo `runtime_error` ho ya `bad_alloc`.

---

# PART 7: TUMHARA `bad_alloc` WALA EXAMPLE — DEEP EXPLANATION

```cpp
try {
    int *p = new int[1000000000000LL];   // 1 trillion ints maang rahe ho — bahut zyada memory!
    cout << "Memory allocation is successful\n";
    delete[] p;
}
catch (const bad_alloc &e) {
    cout << "Exception occurred due to line 97: " << e.what() << endl;
}
```

**Kya Ho Raha Hai:** Tum `new int[1000000000000LL]` se **1 trillion integers** ke liye memory maang rahe ho — ye **kisi bhi normal computer ki RAM se bahut zyada** hai (roughly 4 TB!). Jab `new` itni memory allocate **nahi kar paata**, to wo **khud automatically `std::bad_alloc` exception throw** kar deta hai.

**VERY IMPORTANT INSIGHT:** Is example mein **tumne khud `throw` nahi likha** — `new` operator **khud, apne aap** exception throw kar raha hai jab wo apna kaam nahi kar paata. **Ye dikhata hai ki exceptions sirf tumhare khud ke `throw` statements se hi nahi aatin — C++ ki standard library ke functions (jaise `new`, `vector::at()`, etc.) bhi khud apni exceptions throw karte hain** jab kuch galat ho.

**Analogy:** Ye aisा hai jaise tum ek **movers/packers company** ko bolo "meri 4 TB saaman utha ke le jao" — company (`new` operator) khud check karti hai ki uske paas itni capacity hai ya nahi, aur agar nahi hai, to wo **khud "Sorry, hum ye nahi kar sakte" (`bad_alloc` throw)** bol deti hai — tumhe khud manually check karke bolne ki zaroorat nahi padi "agar capacity kam ho to error do."

---

# PART 8: FULL RECAP — SAB KUCH EK JAGAH (Interview-Ready)

## 8.1 Basic Flow

* `try` = risky code ka block.
* `throw` = exception object bhejna (jab galti ho).
* `catch` = exception ko pakड़ke handle karna.
* Exception throw hote hi, **try block ka baaki code turant skip** ho jaata hai.

## 8.2 Catch Order Rule

* **Specific (derived) exceptions PEHLE, general (base) exceptions BAAD mein.**
* `catch(...)` hamesha **sabse LAST** — sabkuch pakड़ leta hai, safety net ke liye.
* Galat order mein likhne se **specific catch kabhi reach nahi hota** (dead code).

## 8.3 Reference Se Catch Karo

* `catch (const Type &e)` — copy nahi, fast + **object slicing avoid** karta hai (polymorphism sahi se kaam karta hai).

## 8.4 Custom Exceptions Banane Ke Do Tareeke

* **Apni khud ki independent hierarchy** (jaisa `exeception`/`my_runtime_error`) — rare, learning ke liye.
* **`std::exception`/`runtime_error` se inherit karna** (jaisa `InvalidAmountError`) — **BEHTAR practice**, standard `what()` milta hai, generic catches mein bhi pakड़ा jaata hai.

## 8.5 Standard Exception Hierarchy

* Sab kuch **`std::exception`** se derive hota hai.
* `runtime_error` (unpredictable runtime issues), `logic_error` (avoidable programming mistakes), `bad_alloc` (memory allocation fail), etc.

## 8.6 Exceptions Sirf User Ke `throw` Se Nahi Aatin

* Standard library functions (`new`, `vector::at()`) **khud bhi exceptions throw karte hain** jab unka kaam fail ho jaaye.

---
