// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).

#include "Dictionary.h"
#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <cctype>
#include <algorithm>  // for swap
using namespace std;


void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

// This class does the real work of the implementation.
//interface of the hash_table class




struct Node
{
    Node(string words, int key[26])
    {
        m_words = words;
        for (int i = 0; i<26; i++)
        {
            m_key[i] = key[i];
        }
        m_length = words.length();
    }
    
    Node()
    {
        m_words = "";
        m_length = 0;
    }
    Node& operator = (Node& rhs);
    bool operator > (Node& rhs);
    
    string m_words;
    int m_key[26];
    int m_length;
};

bool Node:: operator>(Node& rhs)
{
    return (m_length>rhs.m_length);
}

Node& Node:: operator=(Node & rhs)
{
    m_words = rhs.m_words;
    m_length = rhs.m_length;
    for (int i = 0; i<26; i++)
    {
        m_key[i] = rhs.m_key[i];
    }
    return *this;
}


class simple_list
{
public:
    simple_list() { head = nullptr; }
    void insert_by_value(Node new_node);
    
    
    struct dush
    {
        Node m_node;
        dush* next;
        
    };
    dush* head;
};

void simple_list::insert_by_value(Node new_node)
{
    dush* newPtr = new dush;
    newPtr->m_node = new_node;
    newPtr->next = nullptr;
    
    
    if (head == nullptr)
        head = newPtr;
    else if (head->next == nullptr)
    {
        if (new_node>head->m_node)
        {
            head->next = newPtr;
            
        }
        else
        {
            newPtr->next = head;
            head = newPtr;
        }
    }
    
    else
    {
        dush* cur = nullptr;
        for (cur = head; cur != nullptr&&cur->next != nullptr; cur = cur->next)
        {
            if (cur->next->m_node > new_node)
            {
                newPtr->next = cur->next;
                cur->next = newPtr;
                return;
            }
            
        }
        
        cur->next = newPtr;
        
        
        
    }
    
    
    
    
    
}

class DictionaryImpl
{
public:
    DictionaryImpl()
    {
        for (int i = 0; i<50000; i++)
            Hash_bucket[i] = nullptr;
    }
    ~DictionaryImpl(){}
    void insert(string word);
    void lookup(string letters, void callback(string)) const;
    
private:
    simple_list* Hash_bucket[50000];
    
    //generate a structure Node, consitis of the original string, and the string key.
    
    void generate_key(string words, int key[26])const;
    //generate a 5 digits bucket number
    int generate_5_digits_bucket_number(int code[26])const;
    
    
    
    
    //return the sum of each char int the string word.
    int Sum_of_char(string word) const;
    bool is_same_keys(const int key_1[26], const int key_2[26]) const;
    
};

//===============implementation of the hash table goes here=======================

void DictionaryImpl::generate_key(string words, int key[26])const
{
    int a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), n(0), o(0), p(0), q(0), r(0), s(0), t(0), u(0), v(0), w(0), x(0), y(0), z(0);
    for (int i1 = 0; i1<words.length(); i1++)
    {
        switch (words[i1])
        {
            case 'a':
                a++;
                break;
            case 'b':
                b++;
                break;
            case 'c':
                c++;
                break;
            case 'd':
                d++;
                break;
            case 'e':
                e++;
                break;
            case 'f':
                f++;
                break;
            case 'g':
                g++;
                break;
            case 'h':
                h++;
                break;
            case 'i':
                i++;
                break;
            case 'j':
                j++;
                break;
            case 'k':
                k++;
                break;
            case 'l':
                l++;
                break;
            case 'm':
                m++;
                break;
            case 'n':
                n++;
                break;
            case 'o':
                o++;
                break;
            case 'p':
                p++;
                break;
            case 'q':
                q++;
                break;
            case 'r':
                r++;
                break;
            case 's':
                s++;
                break;
            case 't':
                t++;
                break;
            case 'u':
                u++;
                break;
            case 'v':
                v++;
                break;
            case 'w':
                w++;
                break;
            case 'x':
                x++;
                break;
            case 'y':
                y++;
                break;
            case 'z':
                z++;
                break;
                
                
                
                
        }
    }
    
    key[0] = e;
    key[1] = t;
    key[2] = a;
    key[3] = o;
    key[4] = i;
    
    key[5] = n;
    
    key[6] = s;
    key[7] = h;
    key[8] = r;
    
    key[9] = d;
    
    key[10] = l;
    key[11] = c;
    key[12] = u;
    key[13] = m;
    key[14] = w;
    
    key[15] = f;
    key[16] = g;
    key[17] = y;
    key[18] = p;
    key[19] = b;
    
    key[20] = v;
    key[21] = k;
    key[22] = j;
    key[23] = x;
    key[24] = q;
    key[25] = z;
    
    
    
    
    
    
}

int DictionaryImpl::generate_5_digits_bucket_number(int code[26])const
{
    //double key (0);
    unsigned int rand_seed_1(0), rand_seed_2(0), rand_seed_3(0), rand_seed_4(0), rand_seed_5(0);
    int index_1(0), index_2(0), index_3(0), index_4(0), index_5(0);
    
    rand_seed_1 = code[21] * 10000 + code[6] * 1000 + code[7] * 100 + code[8] * 10 + code[9];
    rand_seed_2 = code[23] * 10000 + code[5] * 1000 + code[12] * 100 + code[13] * 10 + code[11];
    rand_seed_3 = code[22] * 10000 + code[1] * 1000 + code[2] * 100 + code[3] * 10 + code[4];
    rand_seed_4 = code[14] * 10000 + code[0] * 1000 + code[17] * 100 + code[18] * 10 + code[19];
    rand_seed_5 = code[20] * 10000 + code[10] * 1000 + code[15] * 100 + code[24] * 10 + code[16];
    
    index_1 = rand_r(&rand_seed_1) % 5;
    index_2 = rand_r(&rand_seed_2) % 10;
    index_3 = rand_r(&rand_seed_3) % 10;
    index_4 = rand_r(&rand_seed_4) % 10;
    index_5 = rand_r(&rand_seed_5) % 10;
    
    return index_1 * 10000 + index_2 * 1000 + index_3 * 100 + index_4 * 10 + index_5;
    
    
    
}


void DictionaryImpl::insert(string word)
{
    
    removeNonLetters(word);
    int key[26];
    generate_key(word, key);
    
    int index_of_bucket = generate_5_digits_bucket_number(key);
    
    
    if (Hash_bucket[index_of_bucket] == nullptr)
        Hash_bucket[index_of_bucket] = new simple_list();
    
    Hash_bucket[index_of_bucket]->insert_by_value(Node(word, key));
}

bool DictionaryImpl::is_same_keys(const int key_1[26], const int key_2[26]) const
{
    for (int i = 0; i<26; i++)
    {
        if (key_1[i] != key_2[i])
            return false;
    }
    return true;
    
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    if (callback == nullptr)
        return;
    if (letters.empty())
        return;
    int key[26];
    removeNonLetters(letters);
    generate_key(letters, key);
    int index_of_bucket = generate_5_digits_bucket_number(key);
    
    if (Hash_bucket[index_of_bucket] == nullptr)
        return;
    
    for (simple_list::dush* cur = Hash_bucket[index_of_bucket]->head; cur != nullptr; cur = cur->next)
    {
        if (cur->m_node.m_length == letters.length() && is_same_keys(key, cur->m_node.m_key))
            
            
            callback((cur)->m_node.m_words);
    }
}


//===============================end of definition====================================
/*
 class DictionaryImpl
 {
 public:
 DictionaryImpl() {}
 ~DictionaryImpl() {}
 void insert(string word);
 void lookup(string letters, void callback(string)) const;
 private:
 list<string> m_words;
 };
 */

//===========================================need to change

/*
 void DictionaryImpl::insert(string word)
 {
 removeNonLetters(word);
 if ( ! word.empty())
 m_words.push_back(word);
 }
 
 void DictionaryImpl::lookup(string letters, void callback(string)) const
 {
 if (callback == nullptr)
 return;
 
 removeNonLetters(letters);
 if (letters.empty())
 return;
 
 string permutation = letters;
 
 do
 {
 for (list<string>::const_iterator wordp = m_words.begin();
 wordp != m_words.end(); wordp++)
 {
 if (permutation == *wordp)
 callback(*wordp);
 }
 generateNextPermutation(permutation);
 } while (permutation != letters);
 }
 
 */

//=====================================================================================
void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop off everything from "to" to end.
}

// Each successive call to this function generates the next permutation of the
// characters in the parameter.  For example,
//    string s = "eel";
//    generateNextPermutation(s);  // now s == "ele"
//    generateNextPermutation(s);  // now s == "lee"
//    generateNextPermutation(s);  // now s == "eel"
// You don't have to understand this function's implementation.

//========================================================need to change or avoid ===============================

/*
 void generateNextPermutation(string& permutation)
 {
 string::iterator last = permutation.end() - 1;
 string::iterator p;
 
 for (p = last; p != permutation.begin()  &&  *p <= *(p-1); p--)
 ;
 if (p != permutation.begin())
 {
 string::iterator q;
 for (q = p+1; q <= last  &&  *q > *(p-1); q++)
 ;
 swap(*(p-1), *(q-1));
 }
 for ( ; p < last; p++, last--)
 swap(*p, *last);
 }
 
 */
//compare if two strings are exactly the same
/*
 bool is_same (const string& s1, const string& s2)
 {
 for (int i =0; i<s1.size(); i++)
 {
 if (s1[i]!=s2[i])
 return false;
 }
 return true;
 }
 */

//******************** Dictionary functions **********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code.

Dictionary::Dictionary()
{
    m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters, callback);
}
