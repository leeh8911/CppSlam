/**
 * @file identifier.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SRC_IDENTIFIER_H_
#define SRC_IDENTIFIER_H_

#include <cstddef>
#include <unordered_map>

namespace ad {

class Identifier final {
public:
    Identifier() = default;
    ~Identifier() = default;
    
private:
    Identifier(std::size_t value); // 
    std::size_t identifier_;
};

} // namespace ad
#endif // SRC_IDENTIFIER_H_