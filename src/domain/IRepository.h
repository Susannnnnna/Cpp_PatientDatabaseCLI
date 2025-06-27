#pragma once
#include <vector>
#include <string>

template<typename T>
class IRepository {
    public:
        virtual std::vector<T> load() = 0;
        virtual void save(const std::vector<T>& items) = 0;
        virtual ~IRepository() = default;
};