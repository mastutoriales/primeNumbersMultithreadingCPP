#include "Bloqueador.h"
#include <thread>

void Bloqueador::lock() {
    while (locked.test_and_set(std::memory_order_acquire)) {
             std::this_thread::yield(); //<- this is not in the source but might improve performance.
    }
}
void Bloqueador::unlock() {
    locked.clear(std::memory_order_release);
}
