//
// Created by wolfplay on 6/13/25.
//

#include "Snowball/Buffers/RingBuffer.h"

namespace Snowball::buffers
{
template<typename T, size_t Size>
RingBuffer<T, Size>::RingBuffer(): _dataArray(std::array<T, Size>()), _read(0), _write(0), _full(false) {};

template<typename T, size_t Size>
T& RingBuffer<T, Size>::operator[](size_t index) {
    // NOTE: `% Size` can be replaced with this:
    //  if (actualIndex >= Capacity) {
    //  actualIndex -= Capacity;
    //  }
    // for a bit faster execution if the compiler doesn't optimize modulo for small constants
    // (but most likely when using -O3 the compiler will optimize it anyway)
    size_t realIndex = index + _read % Size;

    return _dataArray[realIndex];
}

template<typename T, size_t Size>
const T& RingBuffer<T, Size>::operator[](size_t index) const {
    // NOTE: @ Line 14
    size_t realIndex = index + _read % Size;

    return _dataArray[realIndex];
}

template<typename T, size_t Size>
void RingBuffer<T, Size>::write(const T& data) {
    _dataArray[_write] = data;
    _write = (_write + 1) % Size; // NOTE: @ Line 14

    if (_full) {
        _read = (_read + 1) % Size;
    } else if (_write == _read) {
        _full = true;
    }
}

template<typename T, size_t Size>
size_t RingBuffer<T, Size>::size() const {
    if (_full) { return Size; }
    if (_write >= _read ) { return _write - _read; }
    return Size - _read + _write;
}

template<typename T, size_t Size>
bool RingBuffer<T, Size>::full() const {
    return _full;
}

template<typename T, size_t Size>
bool RingBuffer<T, Size>::empty() const {
    return (!_full && _write == _read);
}
}