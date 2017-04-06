//
// Created by Justin Fairbourn on 4/5/2017.
//

#ifndef HW6_DICTIONARY_H
#define HW6_DICTIONARY_H

#include "KeyValue.h"

template <class K, class V>
class Dictionary {
public:
    Dictionary<K,V>();
    Dictionary<K,V>(int size);
    Dictionary<K,V>(const Dictionary<K,V> &copy);
    void add(KeyValue<K,V>* newEntry);
    KeyValue<K,V>* getByKey(K key) const;
    KeyValue<K,V>* getByIndex(int i) const;
    int getSize() const {return m_size;}
    int getAllocated() const {return m_allocated;}
    void removeByKey(K key);
    void removeByIndex(int i);
private:
    int findInDictionary(K key) const;
    KeyValue<K,V>** m_dictionary = nullptr;
    int m_allocated = 0;
    int m_size = 0;
    void grow();

};


#endif //HW6_DICTIONARY_H
