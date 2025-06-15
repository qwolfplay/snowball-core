//
// Created by wolfplay on 6/13/25.
//

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <array>
#include <cstddef>

namespace Snowball::buffers
{
template<typename T, size_t Size>
class RingBuffer {
    static_assert(std::is_trivially_copyable<T>::value, "RingBuffer only supports trivially copyable types");

    std::array<T, Size> _dataArray;
    size_t _read;
    size_t _write;
    bool _full;

public:
    RingBuffer();
    inline T& operator[](size_t index);
    inline const T& operator[] (size_t index) const;
    inline void write(const T& data);
    [[nodiscard]] inline size_t size() const;
    [[nodiscard]] inline bool full() const;
    [[nodiscard]] inline bool empty() const;

};
}
#endif //RINGBUFFER_H
#include "../../../src/Buffers/RingBuffer.inl"