//
// Created by Justin Fairbourn on 4/21/2017.
//

#ifndef HW7_KEYVALUE_H
#define HW7_KEYVALUE_H

template<class K, class V>
class KeyValue {
public:
    KeyValue<K,V>(K key, V value){
        m_key = key;
        m_value = value;
    }
    KeyValue<K,V>(KeyValue<K,V>* copy){
        m_key = copy->getKey();
        m_value = copy->getValue();
    };
    K getKey(){return m_key;}
    V getValue(){return m_value;}
    void setValue(V value) {m_value = value;}
private:
    K m_key;
    V m_value;
};

#endif //HW7_KEYVALUE_H
