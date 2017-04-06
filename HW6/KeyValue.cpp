//
// Created by Justin Fairbourn on 4/5/2017.
//

#include "KeyValue.h"

template <class K, class V>
KeyValue<K,V>::KeyValue(K key, V value) {
    m_key = key;
    m_value = value;
}

template <class K, class V>
KeyValue<K,V>::KeyValue(KeyValue<K,V>* copy){
    m_key = copy->getKey();
    m_value = copy->getValue();
}