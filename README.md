# Pointers training ground
Pointers' related  micro-projects and memory allocation knowledges

main.cpp contains basic and advanced examples of pointers' usages

## Syntax
Declare pointer of X type : X *ptr_targetedVar = NULL or &targetedVar

Access value of targetedVar through pointer : *ptr_targetedVar

Update value of targetVar through pointer : *ptr_targetedVar = newValue

Access mem address of var : &var

Declare arg of function as pointers : void fun(X *targetedVar) --> can be used with &targetedVar or ptr_targetedVar

Declare arg of function as references : void fun(X &targetedVar) --> can be used with targetedVar

Constant reference / pointer (prevent update of pointed data) : void fun(const X &targetedVar)

### Unique
auto uPtr = make_unique<X>(new X(...))
  
auto uPtr2 = move(uPtr) // uPtr est maintenant "vide"

## Notes
### Raw pointers, references and general infos
**RAW POINTERS SHOULD BE AVOIDED (rare cases)**

Badly managed raw pointers (likelihood) lead to memory leaks. A memory leak is a portion of **used** memory that can't be accessed anymore until the end of the process (dead memory).

**References (&) should be used in most cases (safer)**

Main use of pointers / references is to alter the value of a variable which lies outside the scope of a function.

Also, it is cheaper to point toward the original of a complex object than to copying it (default behavior) when calling it in function (C++ copy by default, JAVA / C# always use reference for complexe objects).

In cases where we do not want to modifiy original data but still take advantage of the "lightness" offered by pointers, we can prevent the modification of the referenced var --> use const reference (see Syntax)

Reference (&) is a syntactic sugar that hide explicits pointers mechanisms and prevent some misbehavior (pointer validity, leaks).

A reference is essentially a valid pointer. A pointer is not always valid.

Pointer are used to keep track of data allocated in heap --> Data *ptr_data = **new** Data() (**USE ADVANCED POINTERS else you have to make sure you destroy the data before you lose any pointer to said data** --- A.V.O.I.D heap allocation if not needed)

Heap allocation cases :
- Large object
- Object must live outside is init scope
- Unpredictable size of data (user input / string...)
- Returning address of obj can be faster than classic return (by copy) <-- OUTSIDE OF (N)RVO cases

### Smart pointers (unique_ptr & shared_ptr)
These avoid the hassle to manually manage the lifespan of heap data and so the likelihood of memory leaks

**UNIQUE :**
                                                                           
unique_ptr encapsulate a raw pointer and auto destroy the pointed data when itself goes out of scope (see code)

A raw pointer can be contained by only **ONE** unique_ptr at any given time (hence the name lol). if you need to access the data outside of the scope of the current unique_ptr, you need to **move** the raw ptr to another unique ptr (the old unique_ptr will lose the raw)

**SHARED :**

TO-DO
## Definitions
**de-reference** (*ptr) : ptr contain a X memory address, *ptr is what's at X's address (can read / write content at pointed location)

Memo :

**stack** = pile (plus rapide / moins de place / gestion allocation auto); **heap** = tas (grande taille / plus lent / gestion allocation manuelle)
