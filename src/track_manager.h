/**
 * @file track_manager.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_TRACK_MANAGER_H_
#define SRC_TRACK_MANAGER_H_

#include <unordered_map>
#include <utility>

#include "src/identifier.h"
#include "src/trackable.h"

namespace ad {
template<class T>
class TrackManager {
    using Track = Trackable<T>;
    using TrackPtr = std::unique_ptr<Track>;

    public:
    explicit TrackManager(const size_t max_size=64);
    ~TrackManager() = default;
    
    size_t Create(const T& meas);
    size_t Create();
    
    TrackPtr operator[](const size_t id) const ;
    private:
    size_t kMaxSize;
    std::unordered_map<size_t, TrackPtr> container_;
};

template<class T>
TrackManager<T>::TrackManager(const size_t max_size) : kMaxSize(max_size) {
    for (size_t idx=0; idx < kMaxSize; idx++) {
        container_.emplace(std::make_pair<size_t, TrackPtr>(idx+1, nullptr));
    }
}

template<class T>
size_t TrackManager<T>::Create(const T& meas) {
    size_t id = Create();
    container_[id]->SetMeas(meas);
    return id;
}

template<class T>
size_t TrackManager<T>::Create() {
    TrackPtr track;
    size_t id = 0;
    for (auto it = container_.begin(); it != container_.end(); it++) {
        if (!it->second) {
            id = it->first;
            track.Id(id);
            it->second = std::move(track);
        }
    }
    return id;
}

template<class T>
std::unique_ptr<Trackable<T>> TrackManager<T>::operator[](const size_t id) const {
    auto res = container_.find(id);
    return std::move(res->second);
}
} // namespace ad
#endif // SRC_TRACK_MANAGER_H_