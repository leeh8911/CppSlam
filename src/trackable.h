/**
 * @file trackable.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_TRACKABLE_H_
#define SRC_TRACKABLE_H_

#include <memory>
#include <set>

#include "src/identifier.h"

namespace ad {

template<class T>
class Trackable {
public:
    Trackable();
    virtual ~Trackable() = default;
    virtual size_t Id() const;
    virtual void Id(size_t id);
    virtual void SetMeas(const T& meas);
    virtual void Update();
private:
    T meas_;
    size_t id_;
};

template<class T>
Trackable<T>::Trackable() : id_(0), meas_(0) {}

template<class T>
size_t Trackable<T>::Id() const {
    return id_;
}

template<class T>
void Trackable<T>::Id(size_t id) {
    id_ = id;
}

template<class T>
void Trackable<T>::SetMeas(const T& meas) {
    meas_ = meas;
}

template<class T>
void Trackable<T>::Update() {
    
}

} // namespace ad

#endif // SRC_TRACKABLE_H_