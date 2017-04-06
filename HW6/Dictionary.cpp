//
// Created by Justin Fairbourn on 4/5/2017.
//

#include "Dictionary.h"

template <class K, class V>
Dictionary<K,V>::Dictionary(){
    m_allocated = 10;
    m_size = 0;
    m_dictionary = new KeyValue<K,V>*[m_allocated];
}

template <class K, class V>
Dictionary<K,V>::Dictionary(int size){
    m_allocated = size;
    m_size = 0;
    m_dictionary = new KeyValue<K,V>*[m_allocated];
}

template <class K, class V>
Dictionary<K,V>::Dictionary(const Dictionary<K,V> &copy){
    m_allocated = copy.getAllocated();
    m_size = copy.getSize();
    m_dictionary = new KeyValue<K,V>*[m_allocated];
    for (int i = 0; i < m_size; i++) m_dictionary[i] = new KeyValue<K,V>(copy.getByIndex(i));
};

template <class K, class V>
void Dictionary<K,V>::grow(){
    m_allocated = m_allocated*2;
    KeyValue<K,V>** newDictionary = new KeyValue<K, V>*[m_allocated];
    for(int i = 0; i < m_size; i++) newDictionary[i] = m_dictionary[i];
    delete[] m_dictionary;
    m_dictionary = newDictionary;
}

template <class K, class V>
void Dictionary<K,V>::add(KeyValue<K,V>* newEntry){
    if(findInDictionary(newEntry->getKey())>=0) throw "KEY ALREADY IN DICTIONARY";
    if(m_size == m_allocated) grow();
    m_dictionary[m_size] = newEntry;
    m_size++;
}

template <class K, class V>
KeyValue<K,V>* Dictionary<K,V>::getByKey(K key) const{
    int found = findInDictionary(key);
    if(found<=0) return m_dictionary[found];
    else throw "KEY NOT FOUND";
}

template <class K, class V>
int Dictionary<K,V>::findInDictionary(K key) const{
    for(int i = 0; i < m_size; i++){
        if(m_dictionary[i]->getKey()==key) return i;
    }
    return -1;
};

template <class K, class V>
KeyValue<K,V>* Dictionary<K,V>::getByIndex(int i) const {
    if(i < 0 || i >= m_size) throw "INDEX OUT OF RANGE";
    else return m_dictionary[i];
}

template <class K, class V>
void Dictionary<K,V>::removeByKey(K key){
    int found = findInDictionary(key);
    if(found == -1) throw "KEY NOT FOUND";
    else removeByIndex(found);
}

template <class K, class V>
void Dictionary<K,V>::removeByIndex(int i){
    delete m_dictionary[i];
    for(int j = i; j < m_size - 1; j++){
        m_dictionary[j] = m_dictionary[j+1];
    }
    m_dictionary[m_size - 1] = nullptr;
    m_size--;
}